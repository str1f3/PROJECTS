#!/usr/bin/env python3

def main() -> None:

    errorMsg1 = "Incorrect PIN. Try again...\nHINT: System PIN has four digits\n";
    errorMsg2 = "Invalid entry. Try again...\n";
    accessGranted = False;

    print("PIN NUMBER GUESSING GAME\n");

    while(not(accessGranted)):
        try:
            enteredPIN = int(input("Enter access PIN to unlock the system: "));
        except Exception:
            print(errorMsg2);
            continue;

        if(enteredPIN < 0 or enteredPIN > 9999):
            print(errorMsg2);
        elif(enteredPIN != 1337):
            print(errorMsg1);
        else:
            print("Access granted!\n");
            accessGranted = True;

if __name__ == "__main__":
    main();
