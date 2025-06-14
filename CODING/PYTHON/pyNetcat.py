#!/usr/bin/env python3

"""required modules"""
import argparse
import os
import socket
import time

# Constants

MAX_FILENAME_LENGTH = 255
WORK_DIR = os.path.join(os.getcwd(), 'server_files')
SERVER_LOGS = os.path.join(os.getcwd(), 'server_logs')
SERVER_LOG_FILE = os.path.join(SERVER_LOGS, 'server.log')
MAX_FILENAME_MSG = f"Error: Max filename length is {MAX_FILENAME_LENGTH} characters.".encode()

# Make sure working dirs exist
os.makedirs(WORK_DIR, exist_ok=True)
os.makedirs(SERVER_LOGS, exist_ok=True)


class ServerMode:
    """ServerMode"""

    def __init__(self, host_ip: str = "0.0.0.0", host_port: int = 1337):
        """Initialization"""
        self.host_ip = host_ip
        self.host_port = host_port
        self.server_socket = None

    def server_log(self, log: str) -> None:
        """Place for server logs"""
        with open(SERVER_LOG_FILE, 'a', encoding="utf-8") as log_file:

            log_file.write(f"{time.time()} - {log}\n")

    def server_configuration(self) -> None:
        """Server socket configuration"""
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((self.host_ip, self.host_port))
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.listen(5)
        print(f"Server is listening on {self.host_ip}:{self.host_port}")

    def client_handler(self, client_socket: socket.socket) -> None:
        """Handle client commands"""
        try:
            while True:
 
                client_command = client_socket.recv(1024).decode()
                if client_command == "LIST":
                    self.listing_handler(client_socket)
                elif client_command == "DOWNLOAD":
                    self.download_handler(client_socket)
                elif client_command == "UPLOAD":
                    self.upload_handler(client_socket)
                elif client_command == "DELETE":
                    self.delete_handler(client_socket)
                elif client_command == "QUIT":
                    self.server_log("QUIT command executed")
                    client_socket.send(b"QUIT")
                    break
                else:
                    client_socket.send("Invalid command...try again.".encode())
        except ConnectionResetError:
            print("Connection closed unexpectedly")
        finally:
            client_socket.close()
            print("Connection terminated")

    def listing_handler(self, client_socket: socket.socket) -> None:
        """Directory listing"""
        directory_path = client_socket.recv(1024).decode()
        if not directory_path:
            directory_path = WORK_DIR
        try:
            if not os.path.exists(directory_path):
                raise FileNotFoundError(f"Directory {directory_path} does not exist.")
            if not os.path.isdir(directory_path):
                raise NotADirectoryError(f"{directory_path} is not a directory.")

            contents = os.listdir(directory_path)
            response = "\n".join(contents)
        except (PermissionError, FileNotFoundError, NotADirectoryError) as error:
            response = str(error)
            self.server_log(f"{error}")
        client_socket.send(response.encode())

    def download_handler(self, client_socket: socket.socket) -> None:
        """File download"""
        file_name = client_socket.recv(1024).decode()
        if len(file_name) > MAX_FILENAME_LENGTH:
            client_socket.send(MAX_FILENAME_MSG)
            return
        file_path = os.path.join(WORK_DIR, file_name)
 
        try:
            with open(file_path, 'rb') as file:
                while True:
                    data = file.read(4096)
                    if not data:
                        break
                    client_socket.sendall(data)
            # Ensure the last chunk is sent before EOF
            time.sleep(1)
            client_socket.send(b"<EOF>")
            self.server_log(f"Downloading...{file_name}")
        except FileNotFoundError:
            response = f"File {file_name} not found."
            self.server_log(f"Download error: {response}")
            client_socket.send(response.encode())
        except PermissionError as error:
            response = str(error)
            self.server_log(f"Download error: {error}")
            client_socket.send(response.encode())

    def upload_handler(self, client_socket: socket.socket) -> None:
        """File upload"""
        file_name = client_socket.recv(1024).decode()
        if len(file_name) > MAX_FILENAME_LENGTH:
            client_socket.send(MAX_FILENAME_MSG)
            return
        file_path = os.path.join(WORK_DIR, file_name)
        try:
            with open(file_path, 'wb') as file:
                while True:
                    data = client_socket.recv(4096)
                    if b"<EOF>" in data:
                        data = data.replace(b"<EOF>", b"")
                        file.write(data)
                        break
                    file.write(data)
            response = f"{file_name} successfully uploaded"
            self.server_log(f"Uploading file...{file_name}")
        except socket.error as error:
            response = str(error)
            self.server_log(f"Upload error: {error}")
        client_socket.send(response.encode())

    def delete_handler(self, client_socket: socket.socket) -> None:
        """Delete file"""
        file_name = client_socket.recv(1024).decode()
        if len(file_name) > MAX_FILENAME_LENGTH:
            client_socket.send(MAX_FILENAME_MSG)
            return
        file_path = os.path.join(WORK_DIR, file_name)
        try:
            os.remove(file_path)
            response = f"{file_name} successfully deleted"
            self.server_log(f"Deleting file...{file_name}")
        except PermissionError as error:
            response = str(error)
            self.server_log(f"Deletion error: {error}")
        except FileNotFoundError as error:
            response = str(error)
            self.server_log(f"Deletion error: {error}")
        client_socket.send(response.encode())

    def server_start(self) -> None:
        """Start the server & accept incoming connections"""

        self.server_configuration()
        try:
            while True:
                client_socket, client_address = self.server_socket.accept()
                print(f"Connection established with {client_address}")
                self.server_log(f"Connection established with {client_address}")
                self.client_handler(client_socket)
        except KeyboardInterrupt:
            print("\nServer is terminated by the user...shutting down")
            self.server_log("Server shutdown by user")
        finally:
            self.server_socket.close()


class ClientMode:
    """ClientMode"""

    def __init__(self, host_ip: str = "127.0.0.1", host_port: int = 1337):
        """Initialization"""
        self.host_ip = host_ip
        self.host_port = host_port
        self.client_socket = None

    def client_configuration(self) -> None:
        """Configure client socket and connect to the server"""
        try:
            self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client_socket.connect((self.host_ip, self.host_port))
            print(f"Connected to the server @ {self.host_ip}:{self.host_port}")
        except ConnectionRefusedError:
            print("Connection Error: Server unavailable")
            self.client_socket = None

    def send_command(self, cmd: str, argument="") -> None:
        """Client is sending commands to the server from here"""
        if self.client_socket:
            try:
                self.client_socket.send(cmd.encode())
                time.sleep(1)
                if argument:
                    self.client_socket.send(argument.encode())
                response = self.client_socket.recv(4096).decode()
                print(response)
            except OSError as error:
                print(f"{error}")

    def download_file(self, file_name: str) -> None:
        """Download server file(s)"""
        if self.client_socket:
            if len(file_name) > MAX_FILENAME_LENGTH:
                self.client_socket.send(MAX_FILENAME_MSG)
                return
            if os.path.exists(file_name):
                overwrite_file = input(
                    f"{file_name} exists. Overwrite file? (y/n): "
                ).strip().lower()
                if overwrite_file != 'y':
                    print("Canceling download...")
                    return
            try:
                self.client_socket.send("DOWNLOAD".encode())
                time.sleep(1)
                self.client_socket.send(file_name.encode())
                with open(file_name, 'wb') as file:
                    while True:
                        data = self.client_socket.recv(4096)
                        if b"<EOF>" in data:
                            data = data.replace(b"<EOF>", b"")
                            file.write(data)
                            break
                        file.write(data)
                print(f"{file_name} successfully downloaded")
            except FileNotFoundError as error:
                print(f"{error}...File not found")
            except ConnectionError as error:
                print(f"{error}...Connection error")

    def upload_file(self, file_name: str) -> None:
        """Upload file to server"""
        if self.client_socket:
            if len(file_name) > MAX_FILENAME_LENGTH:
                self.client_socket.send(MAX_FILENAME_MSG)
                return
            #https://docs.python.org/3/library/os.html#module-os
            if not os.path.exists(file_name):
                print(f"Error: File {file_name} does not exist.")
                return
            try:
                self.client_socket.send("UPLOAD".encode())
                time.sleep(1)
                self.client_socket.send(file_name.encode())
                with open(file_name, 'rb') as file:
                    while True:
                        data = file.read(4096)
                        if not data:
                            break
                        self.client_socket.sendall(data)
                # Ensure the last chunk is sent before EOF
                time.sleep(1)
                self.client_socket.send(b"<EOF>")
                response = self.client_socket.recv(4096).decode()
                print(response)
            except FileNotFoundError as error:
                print(f"{error}...File not found")
            except ConnectionError as error:
                print(f"{error}...Connection error")
            except OSError as error:
                print(f"{error}...OS error")

    def delete_file(self, file_name: str) -> None:
        """Delete server file(s)"""
        if self.client_socket:
            if len(file_name) > MAX_FILENAME_LENGTH:
                self.client_socket.send(MAX_FILENAME_MSG)
                return
            try:
                self.client_socket.send("DELETE".encode())
                time.sleep(1)
                self.client_socket.send(file_name.encode())
                response = self.client_socket.recv(4096).decode()
                print(response)
            except FileNotFoundError as error:
                print(f"{error}...File not found")
            except ConnectionError as error:
                print(f"{error}...Connection error")
            except OSError as error:
                print(f"{error}...OS error")

    def close_connection(self) -> None:
        """Terminate connection"""
        if self.client_socket:
            self.client_socket.send("QUIT".encode())
            response = self.client_socket.recv(1024).decode()
            if response == "QUIT":
                self.client_socket.close()
                print("Connection Terminated!")

    def client_start(self) -> bool:
        """Start client mode and connect to the server"""
        self.client_configuration()
        return self.client_socket is not None

class ClientActions:
    """Handler for client actions"""

    def __init__(self, client: ClientMode):
        self.client = client

    def get_directory(self) -> None:
        """Display directory contents"""
        directory_path = input("Enter a directory path to display: ")
        self.client.send_command("LIST", directory_path)

    def download_file(self) -> None:
        """Download server file(s)"""
        file_name = input("Enter file name to download: ")
        self.client.download_file(file_name)

    def upload_file(self) -> None:
        """Upload file to server"""
        file_name = input("Enter filename to upload: ")
        self.client.upload_file(file_name)

    def delete_file(self) -> None:
        """Delete server file(s)"""
        file_name = input("Enter filename to delete: ")
        self.client.delete_file(file_name)

    def quit(self) -> None:
        """Terminate connection"""
        self.client.close_connection()

class ParsingArguments:
    """Parse cmdline arguments"""

    def __init__(self):
        parser = argparse.ArgumentParser(description="Client/Server Project")
        parser.add_argument("host_ip", type=str, help="Server IP Address")
        parser.add_argument("host_port", type=int, help="Server Port Number")
        parser.add_argument("-m", "--mode", choices=["server", "client"],
                            required=True, help="Mode Selector")
        self.args = parser.parse_args()


def main() -> None:
    """Program execution entry point"""
    parser = ParsingArguments()
    host_ip, host_port = parser.args.host_ip, parser.args.host_port
    mode = parser.args.mode

    #trying to implement a script where mode selection similar Netcat
    try:
        if mode == "server":
            server = ServerMode(host_ip, host_port)
            server.server_start()
        elif mode == "client":
            client = ClientMode(host_ip, host_port)

            if client.client_start():
                client_action = ClientActions(client)
                functions = {'0': client_action.get_directory,
                             '1': client_action.download_file,
                             '2': client_action.upload_file,
                             '3': client_action.delete_file,
                             '4': client_action.quit}
                while True:
                    function = input(
                        "Message From Server\n\n"
                        "No:\t CMD\n"
                        "===========================\n"
                        "'0'\t Directory Listing\n"
                        "'1'\t Download File\n"
                        "'2'\t Upload File\n"
                        "'3'\t Delete File\n"
                        "'4'\t Quit\n"
                        "===========================\n\n"
                        "Enter the number of the command to execute: ").strip()
                    if function in functions:
                        functions[function]()
                    else:
                        print(
                        f"{function} is not part of the selection. Enter a number between 0 and 4."
                        )
        else:
            print("Invalid mode: choose between 'server' or 'client'")
    except ValueError:
        print("Invalid mode: Choose either 'server' or 'client'\n")


if __name__ == "__main__":
    main()
