#ifndef _SPRITE_H					// If we haven't included this file
#define _SPRITE_H					// Set a flag saying we included it

#include "main.h"					// Here we include main.h because that holds all the #include info.
									// This way we don't have to #include everything in every .h file
									// like iostream and the namespace stuff.
									
									// These are are the states of the sprite
									// This order is the order of the frames in the bitmap
#define NORTH 0						// This is the NORTH state of the sprite
#define EAST  1						// This is the EAST state of the sprite
#define SOUTH 2						// This is the SOUTH state of the sprite
#define WEST  3						// This is the WEST state of the sprite
#define NONE  4						// This is the WEST state of the sprite
#define NORTHEAST  5	
#define SOUTHEAST  6	
#define NORTHWEST  7	
#define SOUTHWEST  8
#define ANIMATION1 9	
#define ANIMATION2 10

struct SPRITE {		
	int oldSIZEwidth;
	int oldSIZEheight;
	int SIZEwidth;
	int SIZEheight;			// This is our SPRITE structure for animation
	HBITMAP hBitmap;				// This is the bitmap we will draw our frames from
	HBITMAP hBitmapNormal;
	HBITMAP hBitmapNightVision;
	HBITMAP hBitmapThermalVision;
	int cloaked;
	POINT position;					// This the position of the sprite on the screen
	POINT speed;					// The x and y speed of the sprite
	int currentFrame;				// This is the current frame of animation we are on (starts at 0)
	int lastFrame;					// This is the amount of bitmaps that the sprite animates
	int state;						// The state of the sprite (0 = LEFT, 1 = RIGHT, 2 = NORTH, 3 = SOUTH)
	int width;						// The width in pixels of one of the frames of animation
	int height;						// The height in pixels of one of the frames of animation
	int condition;
	int life; //FLAMES LENGTH
	double maxhealth;
	double health; //OBJECTS HEALTH
	double damage; 
	int particles;
	int max_momentumY;
	int max_momentumX;
	int momentum_climb;
	int heat_speed;
	int upgrade;
	int closeness;
	int control_of_allys;
	int formation_range;
	int formation_type;
	int defend_formation_hold;
	int sequence;
	int script;
	int scriptpos;
	int yhold;
	int xhold;
	int randomdirectionpicked;
	int toleft;
	int toright;
	int boss;
	int randomfire;
	int moved;
	int laserstartypos;
	int special;
	int mission;
	int startpoints;
	int begin_upgrade;
	int points;
	int type;
	int startupgrade;
	int change;
	int shiptype;
	int shothold;
	int camefrom;
	int boss_condition;
	int shotcount;
	int missioncomplete;
	int momentumx;
	int momentumy;
	int target;
	int nuke;
	int charge;
	int difficulty;
	int play_or_quit;
	int ship;
	int loaded;
	int SelectionsComplete;
	int screen;
	int cursor_position;
	int cruel;
	int exemplar;
	int pariah;
	int renegade;
	int init;
	int nightvision;
	int thermalvision;
	int vision;
	int battery;
	int maxbattery;
	int darkmission;
	int headlight;
	int time_left;
	int rescue_mission_loop_count;
	int temp_formation;
	int formationtime;
};

// This loads a sprite and reads in the bitmap associate with it
void LoadSprite(SPRITE *pSprite, LPSTR szFileName, int width, int height, int lastFrame);

// This returns if we should animate the next frame depending on the frame rate
BOOL AnimateNextFrame(int desiredFrameRate);

// Sets a sprites X and Y position
void SetSpritePosition(SPRITE *pSprite, int x, int y);

// This sets the state of the animation (WEST, EAST, etc..)
void SetSpriteState(SPRITE *pSprite, int whichState);

// This sets the sprites x and y speed in pixels
void SetSpriteSpeed(SPRITE *pSprite, int xSpeed, int ySpeed);

// Animates and displays the current bitmap
void AnimateSprite(BUFFER *pBuffer, SPRITE *pSprite);

// This calculates the frames per second and display it in the window title bar
void CalculateFrameRate(HWND hWnd);

// This moves the sprite depending on its state and speed
void MoveSprite(SPRITE *pSprite);

// This erases the sprite with a portion of the background
void EraseSprite(BUFFER *pBuffer, SPRITE *pSprite, HBITMAP hBackground);

// This frees a sprite that is passed in
void FreeSprite(SPRITE *pSprite);

void FreeSpriteALL(SPRITE *pSprite);

#endif

////////////////////////////////////////////////////////////
//
// *Quick Notes*
//
// If you include sprite.cpp with your programs, include this file too
// You probably won't want to change this file, unless you make
// NORTH-EAST , etc... directions.
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//