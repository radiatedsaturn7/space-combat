#ifndef _MAIN_H								
#define _MAIN_H			

#include <iostream>		//yes we need this
#include <windows.h>	
#include "bitmap.h"		//like i said, game tutorials files
#include "sprite.h"			

using namespace std;		// Include the standard namespace																		

// The function prototype for our WndProc (The function that handles all the windows messages)																																																																									
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);		

// Loads the bitmaps and creates the double buffer
void Init(HWND hwnd);

// This frees memory and quits the program
void DeInit();

#endif

