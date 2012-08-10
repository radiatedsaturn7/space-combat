//***********************************************************************//
//																		 //
//		- "Talk to me like a 3 year old!" Programming Lessons -			 //
//                                                                       //
//		$Author:		DigiBen		digiben@gametutorials.com			 //
//																		 //
//		$Program:		Full Screen Apps								 //
//																		 //
//		$Description:	This gives the user the option to go full screen //
//																		 //
//		$Date:			6/18/01											 //
//																		 //
//***********************************************************************//

#include <windows.h>										// We need to include windows.h
#include <stdio.h>											// Include stdio.h for the basics

BOOL bFullScreen = FALSE;									// Create a boolean and set it to false.  If we choose full screen, set it to TRUE


///////////////////////////////// CHANGE TO FULL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This changes the screen to FULL SCREEN
/////
///////////////////////////////// CHANGE TO FULL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void ChangeToFullScreen(int width, int height)
{
	DEVMODE dmSettings;									// Device Mode variable - Needed to change modes

	memset(&dmSettings,0,sizeof(dmSettings));			// Makes Sure Memory's Cleared

	// Get current settings -- This function fills our the settings
	// This makes sure NT and Win98 machines change correctly
	if(!EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dmSettings))
	{
		// Display error message if we couldn't get display settings
		MessageBox(NULL, "Could Not Enum Display Settings", "Error", MB_OK);
		return;
	}

	dmSettings.dmPelsWidth	= width;					// Set the desired Screen Width
	dmSettings.dmPelsHeight	= height;					// Set the desired Screen Height
	dmSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;	// Set the flags saying we're changing the Screen Width and Height
	
	// This function actually changes the screen to full screen
	// CDS_FULLSCREEN Gets Rid Of Start Bar.
	// We always want to get a result from this function to check if we failed
	int result = ChangeDisplaySettings(&dmSettings,CDS_FULLSCREEN);	

	// Check if we didn't recieved a good return message From the function
	if(result != DISP_CHANGE_SUCCESSFUL)
	{
		// Display the error message and quit the program
		MessageBox(NULL, "Display Mode Not Compatible", "Error", MB_OK);
		PostQuitMessage(0);
	}
}

// * QUICK NOTES * 
//
// This shows you how to go to full screen in a window app.  Before we create our
// window you will notice that we have to change the style, depending on if we
// chose full screen or not.  If we didn't change the style it would be full screen,
// but it would look like a window.  We usually want to get rid of the window look,
// and that is why we change the style of it.
//
// We use a message box to get the choice from the user.  This is a very good idea.
// The function MessageBox() returns the button ID that was clicked.  In our case,
// we checked on IDNO.  If we clicked the NO button, then don't go to full screen.
// If we didn't click NO, it will return IDYES, and then sets our flag/boolean to TRUE.
// This is important because when we close the program we need to restore the settings.
// To do this, we call the ChangeDisplaySettings() again, but pass in NULL and 0 for
// the parameters.  It restores the old settings before we changed it, which is nice
// that we don't need to keep track of the old settings.  The ChangeToFullScreen()
// function should be modular enough to plug into any project.  It's simple to use
// and easy to cleanup.
//
// In the ChangeToFullScreen() function, what we do is Enumerate the current display
// settings. This means, that we fill in our DEVMODE structure with our current screen
// settings.  If you debug you will find it will hold your current screen resolution,
// along with other information after the function is called.  But, before we pass that
// information into ChangeDisplaySettings(), we want to change the resolution to our
// desired resolution that was passed in.  In my fire tutorial I go to 320 240 resolution.
//
// Just remember to call ChangeDisplaySettings() again before you close the program or
// else you will be stuck in the changed mode until you manually change it in your
// display settings from control panels.
//
// If you haven't seen the WM_KEYDOWN message yet, you can kinda see what it does.
// The wParam holds the key that was pressed down, so we can query it like we did above.
// Each key has a virtual key code, hence the VK_.  Look in MSDN for the rest of them.
// In this program, we check if the user hit the escape key.  If so, restore the settings
// and quit the program.
//
// © 2000-2003 GameTutorials

