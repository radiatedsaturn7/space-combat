//FM#pragma comment(lib, "fmodvc.lib")

//FM#include "CFmod.h"	

// PERSONAL NOTE : i cried with joy when i completed this game ;)										
#include "main.h"	
#include "randgen.cpp"
#include "randgen.h"
#include "defines.h"
#include "stdlib.h"

/*the reason why i made most of the stuff global was because i figure
  "well, im going to be passing most of this crap through the parameters
  list anyways, so why bother making it local?"

  i dont know if its great reasoning, but i havent had any problems with it yet.*/

//IF YOU ADD A SPRITE IN : TYPE "/" INTO FIND AND IT WILL BRING YOU TO WHERE YOU MUST
//ADD CODE IN TO MAKE IT /!SPRITE
BUFFER g_Buffer;
//!SPRITE	
SPRITE g_WEAPONHUD;
SPRITE g_WEAPONHUD2;
SPRITE g_HUNTER;
SPRITE g_SCORE[max_digits];
SPRITE g_EXPLOSION[max_explosions];
SPRITE g_PARTICLE[max_particles];
SPRITE g_ESCORT;
SPRITE g_switcher;
SPRITE g_temp;
SPRITE g_MO;

SPRITE g_ENDING[4];
	
SPRITE g_HEADLIGHT;
SPRITE g_SCREEN[max_levels];							
SPRITE g_PLAYER;//the player
SPRITE g_ALLY[maxally]; //players allies (get one after each completeion of level...can get 4)
SPRITE g_ENEMY[max_level_tiles]; //UH OH! WATCH OUT THE BADDIES!!!
SPRITE g_SMOKE[max_level_tiles];
SPRITE g_SPARK[max_level_tiles];

SPRITE g_HUD;//head up display bar at bottom..need to be bigger, and maybe redone
SPRITE g_HEALTHBAR;//undernath player
SPRITE g_CHARGEBAR;
SPRITE g_NUKEBAR;
SPRITE g_BATTERY;
SPRITE g_ALLYBAR[maxally];//underneath allies
SPRITE g_AMMOBAR; //when you can shoot again...i may remove this
SPRITE g_HEAD[1 + maxally]; //head at bottom of screen...shows allies too
SPRITE g_HEADBAR[1 + maxally];//health for head
SPRITE g_LOADER;//Loading Bar for the Music I think.

//various weapons FIRE WITH SPACE
SPRITE g_LASER[lasermax];//blue shot
SPRITE g_MGUN[lasermax];//grey/orange shot
SPRITE g_PULSE[lasermax];//green shot
SPRITE g_FLAME[lasermax];//red/yellow/orange shot
SPRITE g_DLASER[lasermax];//shoots diagonally
SPRITE g_SLASER[lasermax];//shoots left/right
SPRITE g_MISSILE[lasermax];//homes in on enemies

SPRITE g_NUKE; //KABOOOM! use with alt, start with 1
SPRITE g_CHARGE[lasermax]; //hold ctrl to charge it, release. no sound or HUD, so you dont know how charged it is yet
SPRITE g_ALLYSHOT[lasermax]; //allies shots (same as laser)

SPRITE g_POWERUP[lasermax];//powerups you can get

SPRITE g_ELASER[max_level_tiles];//enemy shots

SPRITE g_BACKROUND[max_levels];//the planets
SPRITE g_LEVEL[max_level_tiles];//all the particles and starss

SPRITE g_RADAR;//radar at bottom right
SPRITE g_RADARTARGET[max_level_tiles + 1 + maxally];//the little dots on radar

HBITMAP enemyBMPnorm = (HBITMAP)LoadImage(NULL, "enemy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
HBITMAP enemyBMPnv = (HBITMAP)LoadImage(NULL, "enemyNV.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
HBITMAP enemyBMPth = (HBITMAP)LoadImage(NULL, "enemyTH.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

int TALKING = 0;
int MUSIC_PLAYING = 0;

int PAUSE = no;//did player pause? (the function sucks, and needs to be fixed, but thats for later)
int WAIT = 0; //when can player shoot primary again?
int WAIT2 = 0; //when can player shoot secondary again?
int NVWAIT = 0;//when can player press nighvision agian?
int weapon = weapon_laser; //set current laser to weapon_laser
int weapon2 = -1; //set to -1. player doesnt start with secondary, and well have it auto switch to one when he get one

int space_hold_time = 0;
int overheat = 0;

int READY = no;
int screen = titlesel;

int g_MOMX1 = 0;
int g_MOMX2 = 0;
int g_MOMX3 = 0;
int g_MOMX4 = 0;
int g_MOMX5 = 0;

int g_MOMY1 = 0;
int g_MOMY2 = 0;
int g_MOMY3 = 0;
int g_MOMY4 = 0;
int g_MOMY5 = 0;

HBITMAP g_bmpTiles[BOARD_WIDTH][BOARD_HEIGHT];
int g_BoardArray[] =  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int random;
RandGen rand1;

//there was world map stuff here, but i removed all the stuff before you joined in. the project was too big for myself,
//and if things start picking up, well add the world map back in

//FMCFmod music;//music for game. unfortunately, with FMOD we cant sell this :(

long int g_time = 0;//global time (how many times the program has gone through...if g_time == 1, then it means
//weve been completely through the game loop

#include "loader.h"//all the loader functions
void display_loading();
void update_loader();

#include "nightvision.h"//night vision functions..just incase we dont want to use it later.
void animate_NV_fog();
void set_vision_type();
void use_battery();

#include "power_up.h"//powerup file, this one is okay. -2 for random generated powerups
//(thats commented out in game loop), -1 if youve killed an important enemy, >= 0 if you want
//the powerup to be a specific type (better to use "addlaser", "addmgun" ect...see them in defines .h
//set g_POWERUP[x].change to "no" if you want the powerup to stay the same
void power_up(int type);

#include "addpoints.h"
void addpoints(int f);

#include "create_particle.h"
void create_particle(int x, int y, int momy, int momx);

#include "create_explosion.h"
void create_explosion(int x, int y, int momy, int momx);

#include "enemy.h"
void check_for_enemy_shot();//check to see if enemy can shoot
void kill_laser_if_dead(int x);
void kill_enemy_if_dead(int x);
void check_for_kill_or_load_enemy(int x);
void update_enemy_laser(int x);
void set_enemy_type();
void create_enemy(int time_to_create,
				  int ship_number_ONE_TO_THIRTEEN,
				  int script_number_NEGATIVEONE_TO_TEN,
				  int sway_YES_OR_NO,
				  int sway_right_ZERO_TO_FIVE,
				  int sway_left_ZERO_TO_FIVE,
				  int special_YES_OR_NO);

/* right....it said this already had a body...you got me, but comment it out makes the bitch stop complaining
#include "script_sequence.h"//UGLY!!! dont look at this. i imported it from my old space combat,
// so it will need to be redone
void script_sequence(int& z, int P);
*/


#include "findclosest.h"//closest enemy...used in update allys for breakformation
int findclosest(int z, int x);

#include "update_allys.h"//update the allys position
void update_allys();


#include "fire_nuke.h"
void fire_nuke();

#include "mission.h"//UGLY FILE! i also imported this from my first game.
//holds when all the enemys and powerups should appear
void mission();

#include "init_game.h"//the compiler is like a bitchy girlfriend...if you declare stuff in the wrong
//place, it bitches about it, so i made Primary_or_Secondary to state whether you doing the 1st half or second.
//NOTE : i just tried combining them, so im not making myself look like a moron, the if you add the 2ndhalf to the
//top half, the sprites are out of order, if you ad the first half to the second half, the game crashes. UGH!
void init_game(int Primary_or_Secondary);

#include "player_shot.h"
void player_shot();

#include "fire_charge.h"
void fire_charge();

#include "player_controls.h"
void player_controls();

#include "radar.h"
void update_radar(int x);

#include "sprite_collisions.h"
void sprite_collisions();

#include "saveandload.h"
void save_game();
void load_game();

//bool LockFrameRate(int frame_rate);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)			// Here is our "main()" for windows.  Must Have this for a windows app.
{		
	init_game(1);//do top half (mainly initializing upgrades an player health)

		/*CRAP I DONT UNDERSTAND, BUT DONT NEED TO*/
		/*this is where the program bitches about my init_game function*/
	// Create the handle to the window.  
    HWND        hwnd;										
	// Create the variable to hold the window messages
    MSG         msg;	
	
	// Create the structure that holds the attributes of the window.
	// I just crammed them in like this to save space because we know what they do.
    WNDCLASSEX  wndclass = {sizeof (wndclass), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance,
						  LoadIcon (NULL, IDI_WINLOGO), LoadCursor (NULL, IDC_ARROW), (HBRUSH) GetStockObject (BLACK_BRUSH),
						  NULL, "Window Class", LoadIcon (NULL, IDI_WINLOGO)};
	

	// Register the window class with the operating system
	RegisterClassEx (&wndclass);	
	
	// Now, we actually create the window
    hwnd = CreateWindow ("Window Class",					// window class name 
						 "Space Combat",			  			// window's Title    
						 NULL,				// window style	- This style won't allow the window to resize
						 100,								// initial x position
						 100,								// initial y position
						 WIDTH,								// Here we pass in our desired width (800)	 
						 HEIGHT,						    // Here we pass in our desired height (600)	 
						 NULL,								// This is the parent window handle.  
						 NULL,								// This is the window menu handle
						 hInstance,						    // This is the programs instance handle.
						 NULL);								// We don't want to pass any extra data in, so NULL

	// This shows our window. 
    ShowWindow (hwnd, iCmdShow);	

	// This pretty much paints our window to the screen.
    UpdateWindow (hwnd);	

	init_game(2); //init second half (mainly allys and enemies, allyshot and enemy shot)

	int init = 0;
	g_MO.position.y = 459;
	g_MO.position.x = 100;

	// Here is our main loop. 
	while (1)					
	{

		// *We use PeekMessage() instead of GetMessage() to see if there is a message
		// from windows, if not, then we want to animate when nothing is going on.*

		// Check if there is a window message and remove it from the queue
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// If the message was to quit, break out of the while loop
				if(msg.message == WM_QUIT) break;

				// This Translates messages so windows understands them.
				TranslateMessage (&msg);					
			
				// This sends the messages to the WndProc().
				DispatchMessage (&msg);		
				
			}

					for(int y = 0; y < BOARD_HEIGHT; y++)
					{
						for(int x = 0; x < BOARD_WIDTH; x++)
						{
							// Display each title according to their index.
							// We take the x and y index and times it by the width and height
							// in pixels to get the tile position. This makes the nice tile effect we see on screen  
							DisplayBitmap(&g_Buffer, g_bmpTiles[x][y], TILE_WIDTH * x, TILE_WIDTH * y);  
						}
					}

					//Auto response from (NAME OMITTED): God sees all, but can he see why kids love Cinnamon Toast Crunch?

					//sprite shit...need this to get sprites working
					//!SPRITE

						for (int x = 0; x < 10; x++)
						{
							AnimateSprite(&g_Buffer, &g_LEVEL[x]);
						}

						for (int bg = 0; bg < max_levels; bg++)
						{
							if (g_BACKROUND[bg].condition == alive && g_BACKROUND[bg].SIZEwidth > 1 && g_BACKROUND[bg].SIZEheight >  1)
							{
								AnimateSprite(&g_Buffer, &g_BACKROUND[bg]);
							}
						}
						for (x = 0; x < 10; x++)
						{
							if (g_ENDING[x].condition == alive && g_ENDING[x].SIZEwidth > 1 && g_ENDING[x].SIZEheight >  1)
							{
								AnimateSprite(&g_Buffer, &g_ENDING[x]);
							}
						}

						for (x = 10; x < 15; x++)
						{
							AnimateSprite(&g_Buffer, &g_LEVEL[x]);
						}
						for (x = 15; x < 20; x++)
						{
							AnimateSprite(&g_Buffer, &g_LEVEL[x]);
						}
						for (x = 20; x < max_level_tiles; x++)
						{
							AnimateSprite(&g_Buffer, &g_LEVEL[x]);
						}
						if (g_HEADLIGHT.condition == alive)
						{
							AnimateSprite(&g_Buffer, &g_HEADLIGHT);
						}
						for (x = max_level_tiles-1; x >= 0; x--)
						{
							if (g_ENEMY[x].condition != dead && x >= 0)
							{
								AnimateSprite(&g_Buffer, &g_ENEMY[x]);
							}
						}
						for (x = 0; x < max_explosions; x++)
						{
							if (g_EXPLOSION[x].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_EXPLOSION[x]);
							}
						}
						for (x = 0; x < max_particles; x++)
						{
							if (g_PARTICLE[x].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_PARTICLE[x]);
							}
						}
						for (x = 0; x < max_level_tiles; x++)
						{
							if (g_ELASER[x].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_ELASER[x]);
							}
						}

						for (int z = 0; z < lasermax; z++)
						{
							if (g_LASER[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_LASER[z]);
							}
							if (g_MGUN[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_MGUN[z]);
							}
							if (g_PULSE[z].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_PULSE[z]);
							}
							if (g_FLAME[z].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_FLAME[z]);
							}
							if (g_DLASER[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_DLASER[z]);
							}
							if (g_SLASER[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_SLASER[z]);
							}
							if (g_MISSILE[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_MISSILE[z]);
							}
							if (g_ALLYSHOT[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_ALLYSHOT[z]);
							}
							if (g_CHARGE[z].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_CHARGE[z]);
							}
						}

						for (x = 0; x < lasermax; x++)
						{
							if (g_POWERUP[x].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_POWERUP[x]);
							}
						}

						AnimateSprite(&g_Buffer, &g_NUKE);

						AnimateSprite(&g_Buffer, &g_ESCORT);

						for (x = 0; x < maxally; x++)
						{
							if (g_ALLY[x].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_ALLY[x]);
								AnimateSprite(&g_Buffer, &g_ALLYBAR[x]);
							}
						}

						AnimateSprite(&g_Buffer, &g_AMMOBAR);
						AnimateSprite(&g_Buffer, &g_HEALTHBAR);
						AnimateSprite(&g_Buffer, &g_PLAYER);
						if (g_HUNTER.condition == alive)
						{
							AnimateSprite(&g_Buffer, &g_HUNTER);
						}

						for (x = 0; x < max_level_tiles + 1 + maxally; x++)
						{
							if (g_SMOKE[x].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_SMOKE[x]);
							}
							if (g_SPARK[x].condition != dead)
							{
								AnimateSprite(&g_Buffer, &g_SPARK[x]);
							}
						}
						for (int dig = 0; dig < max_digits; dig++)
						{
							SetSpriteState(&g_SCORE[dig], g_SCORE[dig].condition);
							AnimateSprite(&g_Buffer, &g_SCORE[dig]);
						}

						AnimateSprite(&g_Buffer, &g_HEAD[0]);
						SetSpriteState(&g_MO, g_PLAYER.mission);
						SetSpriteState(&g_WEAPONHUD,weapon);
						SetSpriteState(&g_WEAPONHUD2,weapon2);

						if (g_HUD.condition == 0)
						{
							AnimateSprite(&g_Buffer, &g_WEAPONHUD);
							AnimateSprite(&g_Buffer, &g_WEAPONHUD2);
							SetSpriteState(&g_RADAR, 0);
							SetSpriteState(&g_HUD, 0);
							AnimateSprite(&g_Buffer, &g_RADAR);
							AnimateSprite(&g_Buffer, &g_HUD);
							AnimateSprite(&g_Buffer, &g_MO);
							AnimateSprite(&g_Buffer, &g_BATTERY);
							AnimateSprite(&g_Buffer, &g_CHARGEBAR);
							AnimateSprite(&g_Buffer, &g_NUKEBAR);
							g_HUD.condition = alive;
							g_HUD.condition--;
						}
						else if (g_HUD.condition >= 0)
						{
							g_HUD.condition--;
						}
						for (x = 0; x < maxally + 1; x++)
						{
							AnimateSprite(&g_Buffer, &g_HEADBAR[x]);
						}
						for (x = 0; x < max_level_tiles + 1 + maxally; x++)
						{
							AnimateSprite(&g_Buffer, &g_RADARTARGET[x]);
						}

						for (x = 0; x < max_levels; x++)
						{
							if (g_SCREEN[x].condition == alive)
							{
								AnimateSprite(&g_Buffer, &g_SCREEN[x]);
							}
						}
						

						if (g_LOADER.condition == alive)
						{
							AnimateSprite(&g_Buffer, &g_LOADER);
						}

						
		if (READY == no)
		{
			if (g_time == 0)
			{
				g_time = -450;
			}
						if (screen == titlesel)
						{
							if (g_SCREEN[0].condition == dead)
							{
								g_SCREEN[0].condition = alive;
								g_SCREEN[0].position.x = 0;
								g_SCREEN[0].position.y = 0;
							}
							if (g_SCREEN[4].condition == dead)
							{
								g_SCREEN[4].position.x = 119;
								g_SCREEN[4].position.y = 134;//moves 17
								g_SCREEN[4].condition = alive;
							}

							if (GetAsyncKeyState(VK_UP))
							{
								g_SCREEN[4].position.y = 134;
							}
							if (GetAsyncKeyState(VK_DOWN))
							{
								g_SCREEN[4].position.y = 151;
							}
							if (GetAsyncKeyState(VK_SPACE))
							{
								if (g_SCREEN[4].position.y == 151)
								{
									return 0;
								}
								else
								{
									screen = difficultysel;
									
									g_SCREEN[0].position.x = offscreen;
									g_SCREEN[0].position.y = offscreen;
									g_SCREEN[4].condition = dead;
									g_SCREEN[4].position.x = offscreen;
									g_SCREEN[4].position.y = offscreen;
									display_loading();
									WAIT = 0;
								}
							}
						}
						else if (screen == difficultysel)
						{
							if (g_SCREEN[2].condition == dead)
							{
								g_SCREEN[0].condition = dead;
								g_SCREEN[2].condition = alive;
								g_SCREEN[2].position.x = 0;
								g_SCREEN[2].position.y = 0;
							}
							if (g_SCREEN[4].condition == dead)
							{
								g_SCREEN[4].position.x = 150;//moves 35
								g_SCREEN[4].position.y = 201;
								g_SCREEN[4].condition = alive;
							}
							if (GetAsyncKeyState(VK_DOWN) && WAIT >= SCREENWAIT && g_SCREEN[4].position.y != 278 && g_PLAYER.difficulty != 4)
							{
								if (g_PLAYER.difficulty <= 3 || g_PLAYER.cruel == unlocked)
								{
									g_SCREEN[4].position.y += 29;
									g_PLAYER.difficulty++;
								}
							}
							if (GetAsyncKeyState(VK_UP) && WAIT >= SCREENWAIT && g_SCREEN[4].position.y != 173 && g_PLAYER.difficulty != 0)
							{
								g_SCREEN[4].position.y -= 29;
								g_PLAYER.difficulty--;
							}
							if (GetAsyncKeyState(VK_SPACE) && WAIT >= SCREENWAIT)
							{
								screen = vesselsel;
								g_SCREEN[2].condition = dead;
								g_SCREEN[2].position.x = -g_SCREEN[2].SIZEwidth;
								g_SCREEN[2].position.y = -g_SCREEN[2].SIZEheight;
								g_SCREEN[4].condition = dead;
								g_SCREEN[4].position.x = -g_SCREEN[4].SIZEwidth;
								g_SCREEN[4].position.y = -g_SCREEN[4].SIZEheight;
								display_loading();
								WAIT = 0;
								if (g_PLAYER.difficulty == 0)
								{
									screen = none;
									load_game();
									g_PLAYER.condition = alive;
									display_loading();
									g_PLAYER.position.x = 208;//center middle of screen
									g_PLAYER.position.y = 480;
									READY = yes;
									WAIT = 0;
									g_time = -450;
								}
							}
						}
						else if (screen == vesselsel)
						{
							if (g_SCREEN[1].condition == dead)
							{
								g_SCREEN[2].condition = dead;
								g_SCREEN[1].condition = alive;
								g_SCREEN[1].position.x = 0;
								g_SCREEN[1].position.y = 0;
							}
							if (g_SCREEN[4].condition == dead)
							{
								g_SCREEN[4].position.x = 109;//moves 35
								g_SCREEN[4].position.y = 138;
								g_SCREEN[4].condition = alive;
							}
							if (GetAsyncKeyState(VK_UP) && WAIT >= SCREENWAIT && g_PLAYER.ship >= 1)
							{
								g_SCREEN[4].position.y -= 35;
								g_PLAYER.ship--;
								if (g_PLAYER.ship == 5 && g_PLAYER.renegade == locked)
								{
									g_PLAYER.ship = 4;
								}
								if (g_PLAYER.ship == 4 && g_PLAYER.pariah == locked)
								{
									g_PLAYER.ship = 3;
								}
								if (g_PLAYER.ship == 3 && g_PLAYER.exemplar== locked)
								{
									g_PLAYER.ship = 2;
								}
							}
							if (GetAsyncKeyState(VK_DOWN) && WAIT >= SCREENWAIT && g_PLAYER.ship <= 4)
							{
								g_SCREEN[4].position.y += 35;
								g_PLAYER.ship++;
								if (g_PLAYER.ship == 3 && g_PLAYER.exemplar == locked)
								{
									g_SCREEN[4].position.y += 35;
									g_PLAYER.ship = 4;
								}
								if (g_PLAYER.ship == 4 && g_PLAYER.pariah == locked)
								{
									g_SCREEN[4].position.y += 35;
									g_PLAYER.ship = 5;
								}
								if (g_PLAYER.ship == 5 && g_PLAYER.renegade == locked)
								{
									g_SCREEN[4].position.y = 138 + (35 * 2);
									g_PLAYER.ship = 2;
								}
							}
							if (GetAsyncKeyState(VK_SPACE) && WAIT >= SCREENWAIT)
							{
								if (g_PLAYER.ship == 0)
								{
									LoadSprite(&g_PLAYER, "PPaladin.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PPaladin.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PPaladinNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PPaladinTH.bmp");

									g_PLAYER.maxhealth = 9;//3 digits must add up to 288
									g_PLAYER.max_momentumY = (int) (144 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (108 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (36 / g_PLAYER.maxhealth);
								}
								if (g_PLAYER.ship == 1)
								{
									//12 //9
									//   //16
									LoadSprite(&g_PLAYER, "PCalumniator.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PCalumniator.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PCalumniatorNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PCalumniatorTH.bmp");
									g_PLAYER.maxhealth = 12;
									g_PLAYER.max_momentumY = (int) (144 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (120 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (24 / g_PLAYER.maxhealth);
								}							
								if (g_PLAYER.ship == 2)
								{
									LoadSprite(&g_PLAYER, "PSentinel.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PSentinel.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PSentinelNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PSentinelTH.bmp");
									g_PLAYER.maxhealth = 15;
									g_PLAYER.max_momentumY = (int) (126 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (126 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (36 / g_PLAYER.maxhealth);
								}
								if (g_PLAYER.ship == 3)
								{
									LoadSprite(&g_PLAYER, "PExemplar.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PExemplar.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PExemplarNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PExemplarTH.bmp");
									g_PLAYER.maxhealth = 13;
									g_PLAYER.max_momentumY = (int) (120 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (152 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (16 / g_PLAYER.maxhealth);
								}
								if (g_PLAYER.ship == 4)
								{
									LoadSprite(&g_PLAYER, "PPariah.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PPariah.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PPariahNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PPariahTH.bmp");
									g_PLAYER.maxhealth = 10;
									g_PLAYER.max_momentumY = (int) (108 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (144 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (36 / g_PLAYER.maxhealth);
								}
								if (g_PLAYER.ship == 5)
								{
									LoadSprite(&g_PLAYER, "PRenegade.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
									g_PLAYER.hBitmapNormal = LoadABitmap("PRenegade.bmp");
									g_PLAYER.hBitmapNightVision = LoadABitmap("PRenegadeNV.bmp");
									g_PLAYER.hBitmapThermalVision = LoadABitmap("PRenegadeTH.bmp");
									g_PLAYER.maxhealth = 8;
									g_PLAYER.max_momentumY = (int) (108 / g_PLAYER.maxhealth);
									g_PLAYER.max_momentumX = (int) (156 / g_PLAYER.maxhealth);
									g_PLAYER.momentum_climb = (int) (24 / g_PLAYER.maxhealth);
								}
								g_PLAYER.health = g_PLAYER.maxhealth;
								screen = weaponssel;
								g_SCREEN[1].condition = dead;
								g_SCREEN[1].position.x = -g_SCREEN[1].SIZEwidth;
								g_SCREEN[1].position.y = -g_SCREEN[1].SIZEheight;
								g_SCREEN[4].condition = dead;
								display_loading();
								WAIT = 0;
							}
						}
						else if (screen == weaponssel)
						{
							if (g_SCREEN[3].condition == dead)
							{
								g_SCREEN[1].condition = dead;
								g_SCREEN[3].condition = alive;
								g_SCREEN[3].position.x = 0;
								g_SCREEN[3].position.y = 0;
							}
							if (g_SCREEN[4].condition == dead)
							{
								g_SCREEN[4].position.x = 143;//moves 29
								g_SCREEN[4].position.y = 160;
								g_SCREEN[4].condition = alive;
							}
							if (GetAsyncKeyState(VK_DOWN) && WAIT >= SCREENWAIT && g_SCREEN[4].position.y != 278 && weapon != addpulse)
							{
								g_SCREEN[4].position.y += 29;
								weapon++;
							}
							if (GetAsyncKeyState(VK_UP) && WAIT >= SCREENWAIT && g_SCREEN[4].position.y != 173 && weapon != addlaser)
							{
								g_SCREEN[4].position.y -= 29;
								weapon--;
							}
							if (GetAsyncKeyState(VK_SPACE) && WAIT >= SCREENWAIT)
							{
								if (weapon == addlaser)
								{
									g_LASER[0].upgrade = 1;
								}
								if (weapon == addmgun)
								{
									g_MGUN[0].upgrade = 4;
								}
								if (weapon == addflame)
								{
									g_FLAME[0].upgrade = 2;
								}
								if (weapon == addpulse)
								{
									g_PULSE[0].upgrade = 1;
								}
								screen = cutscene;
								g_SCREEN[3].condition = dead;
								g_SCREEN[3].position.x = -g_SCREEN[3].SIZEwidth;
								g_SCREEN[3].position.y = -g_SCREEN[3].SIZEheight;
								g_SCREEN[4].condition = dead;
								g_SCREEN[4].position.x = -g_SCREEN[4].SIZEwidth;
								g_SCREEN[4].position.y = -g_SCREEN[4].SIZEheight;
								g_BACKROUND[3].condition = dyingone;
								
								g_time = 0;
								g_PLAYER.battery = g_PLAYER.maxbattery;
								g_PLAYER.startupgrade = weapon;
								for (int h = 0; h < max_level_tiles; h++)
								{
									if (h < 10)
									{
										g_SCREEN[h].hBitmap = g_switcher.hBitmap;
										g_SCREEN[h].SIZEwidth = 1;
										g_SCREEN[h].SIZEheight = 1;
									}
									if (g_ENEMY[h].condition == alive)//kill enemys on backroudns creen
									{
										g_ENEMY[h].condition = dead;
									}
								}
							}
						}
						else if (screen == cutscene)
						{
							if (g_BACKROUND[5].condition != alive)
							{
								CreateDoubleBuffering(&g_Buffer, hwnd);
								g_BACKROUND[5].SIZEwidth = 480;
								g_BACKROUND[5].SIZEheight = 472;
								LoadSprite(&g_BACKROUND[5], "BOpeningA.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
							
								g_BACKROUND[5].hBitmapNormal = LoadABitmap("BOpeningA.bmp");
								g_BACKROUND[5].hBitmapNightVision = LoadABitmap("BOpeningA.bmp");
								g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("BOpeningA.bmp");
							
								SetSpriteState(&g_BACKROUND[5], NORTH);
								if (g_BACKROUND[5].condition == dyingone)
								{
									g_BACKROUND[5].position.y = 300;
									g_BACKROUND[5].position.x = 0;
								}
								g_BACKROUND[5].closeness = 20;
								g_BACKROUND[5].loaded = yes;
								g_BACKROUND[5].moved = no;
								g_BACKROUND[5].condition = alive;
							}
							if (g_BACKROUND[1].condition != alive)
							{
								CreateDoubleBuffering(&g_Buffer, hwnd);
								g_BACKROUND[1].SIZEwidth = 692;
								g_BACKROUND[1].SIZEheight = 428;
								LoadSprite(&g_BACKROUND[1], "BOpeningB1.bmp", g_BACKROUND[1].SIZEwidth, g_BACKROUND[1].SIZEheight, PLAYER_FRAMES);
							
								g_BACKROUND[1].hBitmapNormal = LoadABitmap("BOpeningB1.bmp");
								g_BACKROUND[1].hBitmapNightVision = LoadABitmap("BOpeningB1.bmp");
								g_BACKROUND[1].hBitmapThermalVision = LoadABitmap("BOpeningB1.bmp");
							
								SetSpriteState(&g_BACKROUND[1], NORTH);
								if (g_BACKROUND[1].condition == dyingone)
								{
									g_BACKROUND[1].position.y = 0;
									g_BACKROUND[1].position.x = 470;
									g_BACKROUND[2].position.x = 470;
								}
								g_BACKROUND[1].closeness = 20;
								g_BACKROUND[1].loaded = yes;
								g_BACKROUND[1].moved = no;
								g_BACKROUND[1].condition = alive;
							}
							if (g_BACKROUND[2].condition != alive && g_BACKROUND[1].position.x < -320)
							{
								CreateDoubleBuffering(&g_Buffer, hwnd);
								g_BACKROUND[2].SIZEwidth = 667;
								g_BACKROUND[2].SIZEheight = 409;
								LoadSprite(&g_BACKROUND[2], "BOpeningB2.bmp", g_BACKROUND[2].SIZEwidth, g_BACKROUND[2].SIZEheight, PLAYER_FRAMES);
								
								g_BACKROUND[2].hBitmapNormal = LoadABitmap("BOpeningB2.bmp");
								g_BACKROUND[2].hBitmapNightVision = LoadABitmap("BOpeningB2.bmp");
								g_BACKROUND[2].hBitmapThermalVision = LoadABitmap("BOpeningB2.bmp");

								SetSpriteState(&g_BACKROUND[2], NORTH);
								if (g_BACKROUND[2].condition == dyingone)
								{
									g_BACKROUND[2].position.y = 0;
									g_BACKROUND[2].position.x = 470;
								}
								g_BACKROUND[2].closeness = 20;
								g_BACKROUND[2].loaded = yes;
								g_BACKROUND[2].moved = no;
								g_BACKROUND[2].condition = alive;
							}
							if (g_BACKROUND[3].condition != alive && g_BACKROUND[2].position.x < -320)
							{
								CreateDoubleBuffering(&g_Buffer, hwnd);
								g_BACKROUND[3].SIZEwidth = 709;
								g_BACKROUND[3].SIZEheight = 446;
								LoadSprite(&g_BACKROUND[3], "BOpeningB3.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
								
								g_BACKROUND[3].hBitmapNormal = LoadABitmap("BOpeningB3.bmp");
								g_BACKROUND[3].hBitmapNightVision = LoadABitmap("BOpeningB3.bmp");
								g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("BOpeningB3.bmp");

								SetSpriteState(&g_BACKROUND[3], NORTH);
								if (g_BACKROUND[3].condition == dyingone)
								{
									g_BACKROUND[3].position.y = 0;
									g_BACKROUND[3].position.x = 470;
								}
								g_BACKROUND[3].closeness = 20;
								g_BACKROUND[3].loaded = yes;
								g_BACKROUND[3].moved = no;
								g_BACKROUND[3].condition = alive;
							}
							if (g_BACKROUND[5].condition == alive && (g_time % 2 == 0))
							{
								//Sleep(2);
								g_BACKROUND[5].moved = yes;
								g_BACKROUND[5].position.y -= 1;
							}
							if (g_BACKROUND[3].position.x < -650)
							{
								//Sleep(2);
								g_BACKROUND[5].moved = yes;
								g_BACKROUND[5].position.y -= 4;
							}
							if (g_BACKROUND[1].condition == alive)
							{
								//Sleep(2);
								g_BACKROUND[1].moved = yes;
								g_BACKROUND[1].position.x -= 3;
							}
							if (g_BACKROUND[2].condition == alive)
							{
								//Sleep(2);
								g_BACKROUND[2].moved = yes;
								g_BACKROUND[2].position.x -= 3;
							}
							if (g_BACKROUND[3].condition == alive)
							{
								//Sleep(2);
								g_BACKROUND[3].moved = yes;
								g_BACKROUND[3].position.x -= 3;
							}

							if (g_BACKROUND[5].position.y < -472 || GetAsyncKeyState(VK_SPACE))
							{
								g_BACKROUND[5].condition = dyingone;
								g_BACKROUND[1].condition = dyingone;
								g_BACKROUND[2].condition = dyingone;
								g_BACKROUND[3].condition = dyingone;
								g_BACKROUND[5].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[5].SIZEwidth = 1;
								g_BACKROUND[5].SIZEheight = 1;
								g_BACKROUND[5].position.y = -500;
								g_BACKROUND[5].position.x = -500;
								g_BACKROUND[5].loaded = no;
								g_BACKROUND[1].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[1].SIZEwidth = 1;
								g_BACKROUND[1].SIZEheight = 1;
								g_BACKROUND[1].position.y = -500;
								g_BACKROUND[1].position.x = -500;
								g_BACKROUND[1].loaded = no;
								g_BACKROUND[2].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[2].SIZEwidth = 1;
								g_BACKROUND[2].SIZEheight = 1;
								g_BACKROUND[2].position.y = -500;
								g_BACKROUND[2].position.x = -500;
								g_BACKROUND[2].loaded = no;
								g_BACKROUND[3].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[3].SIZEwidth = 1;
								g_BACKROUND[3].SIZEheight = 1;
								g_BACKROUND[3].position.y = -500;
								g_BACKROUND[3].position.x = -500;
								g_BACKROUND[3].loaded = no;


								g_PLAYER.condition = alive;
								display_loading();
								if (g_PLAYER.difficulty == easydif)
								{
									g_PLAYER.maxhealth *=2.5;
									g_PLAYER.health *=2.5;
								}
								if (g_PLAYER.difficulty == normaldif)
								{
									g_PLAYER.maxhealth *=2;
									g_PLAYER.health *=2;
								}
								if (g_PLAYER.difficulty == harddif)
								{
									g_PLAYER.maxhealth *=1.5;
									g_PLAYER.health *=1.5;
								}
								g_PLAYER.position.x = 208;//center middle of screen
								g_PLAYER.position.y = 480;
								g_PLAYER.mission = 0;//!mission
								READY = yes;
								WAIT = 0;
								g_time = -2350;//-2350
							}
							if (g_BACKROUND[1].position.x <= -800)
							{
								g_BACKROUND[1].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[1].SIZEwidth = 1;
								g_BACKROUND[1].SIZEheight = 1;
								g_BACKROUND[1].position.y = -500;
								g_BACKROUND[1].position.x = -500;
								g_BACKROUND[1].loaded = no;
							}
							if (g_BACKROUND[2].position.x <= -800)
							{
								g_BACKROUND[2].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[2].SIZEwidth = 1;
								g_BACKROUND[2].SIZEheight = 1;
								g_BACKROUND[2].position.y = -500;
								g_BACKROUND[2].position.x = -500;
								g_BACKROUND[2].loaded = no;
							}
							if (g_BACKROUND[3].position.x <= -800)
							{
								g_BACKROUND[3].hBitmap = g_switcher.hBitmap;
								g_BACKROUND[3].SIZEwidth = 1;
								g_BACKROUND[3].SIZEheight = 1;
								g_BACKROUND[3].position.y = -800;
								g_BACKROUND[3].position.x = -800;
								g_BACKROUND[3].loaded = no;
							}
						}

						for (int x = 0; x < max_levels;x++)
						{
							if (g_SCREEN[x].condition == alive)
							{
								SetSpriteState(&g_SCREEN[x], 0);
							}
						}
		}

		for (x = 0; x < max_explosions; x++)
		{
			if (g_EXPLOSION[x].condition==alive)
			{
				g_EXPLOSION[x].position.y += g_EXPLOSION[x].momentumy;
				g_EXPLOSION[x].position.x += g_EXPLOSION[x].momentumx;

				SetSpriteState(&g_EXPLOSION[x], g_EXPLOSION[x].life);

				if (g_EXPLOSION[x].life < 9)
				{
					g_EXPLOSION[x].life++;
				}
				else
				{
					g_EXPLOSION[x].condition = dead;
					g_EXPLOSION[x].position.x = offscreen;
					g_EXPLOSION[x].position.y = offscreen;
				}
			}
		}
		int signalpart = 0;
		for (x = 0; x < max_particles; x++)
		{
			if (g_PARTICLE[x].condition==alive)
			{
				signalpart = 1;
				g_PARTICLE[x].position.y += g_PARTICLE[x].momentumy;
				g_PARTICLE[x].position.x += g_PARTICLE[x].momentumx;

				SetSpriteState(&g_PARTICLE[x], g_PARTICLE[x].life);

				if (g_PARTICLE[x].life < 9)
				{
					g_PARTICLE[x].life++;
				}
				else
				{
					g_PARTICLE[x].condition = dead;
					g_PARTICLE[x].position.x = offscreen;
					g_PARTICLE[x].position.y = offscreen;
				}
			}
		}
		if (signalpart == 1)
		{
			if (g_MOMX1 > 0)
			{
				g_MOMX1 -=1;
			}
			else if (g_MOMX1 < 0)
			{
				g_MOMX1 +=1;
			}
			if (g_MOMX2 > 0)
			{
				g_MOMX2 -=1;
			}
			else if (g_MOMX2 < 0)
			{
				g_MOMX2 +=1;
			}
			if (g_MOMX3 > 0)
			{
				g_MOMX3 -=1;
			}
			else if (g_MOMX3 < 0)
			{
				g_MOMX3 +=1;
			}
			if (g_MOMX4 > 0)
			{
				g_MOMX4 -=1;
			}
			else if (g_MOMX4 < 0)
			{
				g_MOMX4 +=1;
			}
			if (g_MOMX5 > 0)
			{
				g_MOMX5 -=1;
			}
			else if (g_MOMX5 < 0)
			{
				g_MOMX5 +=1;
			}

			if (g_MOMY1 > 0)
			{
				g_MOMY1 -=1;
			}
			else if (g_MOMY1 < 0)
			{
				g_MOMY1 +=1;
			}
			if (g_MOMY2 > 0)
			{
				g_MOMY2 -=1;
			}
			else if (g_MOMY2 < 0)
			{
				g_MOMY2 +=1;
			}
			if (g_MOMY3 > 0)
			{
				g_MOMY3 -=1;
			}
			else if (g_MOMY3 < 0)
			{
				g_MOMY3 +=1;
			}
			if (g_MOMY4 > 0)
			{
				g_MOMY4 -=1;
			}
			else if (g_MOMY4 < 0)
			{
				g_MOMY4 +=1;
			}
			if (g_MOMY5 > 0)
			{
				g_MOMY5 -=1;
			}
			else if (g_MOMY5 < 0)
			{
				g_MOMY5 +=1;
			}
		}
		if (READY == yes)
		{
			for (int z = 0; z < 10; z++)
			{
				FreeSpriteALL(&g_SCREEN[z]);
			}	
		}
		if (g_time == 0 && READY == yes)
		{
			save_game();
		}

		if (g_PLAYER.position.y >= gridalignment * 15 - g_PLAYER.SIZEheight)
		{
			g_PLAYER.position.y-=4;
		}
		//ANIMATE DEATH

		if (g_PLAYER.health <= 0 && g_PLAYER.condition == alive)
		{
			PlaySound("playerdie.wav", NULL, SND_FILENAME | SND_ASYNC);
			g_PLAYER.condition = dyingone;
			if (g_PLAYER.toleft == yes)
			{
				g_PLAYER.life = 23;
			}
			else
			{
				g_PLAYER.life = 8;
			}
			g_HEAD[0].condition = unspawning;
		}

		if (g_PLAYER.condition == dyingone)
		{
			if (g_PLAYER.toleft == yes)
			{
				g_PLAYER.position.x+=3;
				g_PLAYER.position.y-=3;
			}
			else
			{
				g_PLAYER.position.x-=3;
				g_PLAYER.position.y-=3;
			}

			SetSpriteState(&g_PLAYER, g_PLAYER.life);

			if (g_time % 2 == 1)
			{
				g_PLAYER.life++;
			}
			if (g_PLAYER.life >= 22 && g_PLAYER.toleft == no)
			{
				g_PLAYER.condition = dead;
				g_PLAYER.position.y = offscreen;
				g_PLAYER.position.x = offscreen;
				WAIT = 0;
			}
			if (g_PLAYER.life >= 38 && g_PLAYER.toleft == yes)
			{
				g_PLAYER.condition = dead;
				g_PLAYER.position.y = offscreen;
				g_PLAYER.position.x = offscreen;
				WAIT = 0;
			}
		}

		if (g_PLAYER.condition == dead && WAIT >= 50 && READY == yes)
		{
			return 0;
		}

		if (g_ESCORT.condition == alive)
		{
			if (g_time % 2 == 0)
					{
						SetSpriteState(&g_ESCORT, 0);
					}
					if (g_time % 2 == 1)
					{
						SetSpriteState(&g_ESCORT, 6);
					}
					if (g_time % 2 == 2)
					{
						SetSpriteState(&g_ESCORT, 7);
					}
		}

		//ANIMATE SMOKE
		for (x = 0; x < max_level_tiles; x++)
		{
			if (g_SMOKE[x].condition != dead && g_SMOKE[x].life < 17)
			{
				if (g_SMOKE[x].life < 17)
				{
					g_SMOKE[x].condition = dyingone;
				}

				SetSpriteState(&g_SMOKE[x], g_SMOKE[x].life);

				g_SMOKE[x].life++;
				g_SMOKE[x].position.y += g_SMOKE[x].yhold;
				g_SMOKE[x].position.x += g_SMOKE[x].xhold;
			}
			else
			{
				g_SMOKE[x].life = 0;
				g_SMOKE[x].position.y = -92;
				g_SMOKE[x].position.y = -92;
				g_SMOKE[x].condition = dead;
			}
		}

		//ANIMATE SPARK
		for (x = 0; x < max_level_tiles; x++)
		{
			if (g_SPARK[x].condition != dead && g_SPARK[x].life < 12)
			{
				if (g_SPARK[x].life < 12)
				{
					g_SPARK[x].condition = dyingone;
				}

				SetSpriteState(&g_SPARK[x], g_SPARK[x].life);

				g_SPARK[x].life++;
				g_SPARK[x].position.y += g_SPARK[x].yhold;
				g_SPARK[x].position.x += g_SPARK[x].xhold;
			}
			else
			{
				g_SPARK[x].life = 0;
				g_SPARK[x].position.y = -92;
				g_SPARK[x].position.y = -92;
				g_SPARK[x].condition = dead;
			}
		}

		if (g_PLAYER.health != dead)
		{
			if (g_PLAYER.nuke >= 3)
			{
				SetSpriteState(&g_NUKEBAR, 0);
			}
			else if (g_PLAYER.nuke >= 2)
			{
				SetSpriteState(&g_NUKEBAR, 1);
			}
			else if (g_PLAYER.nuke >= 1)
			{
				SetSpriteState(&g_NUKEBAR, 2);
			}
			else
			{
				SetSpriteState(&g_NUKEBAR, 3);
			}

			double cp = g_PLAYER.charge;
			int cbp = g_CHARGE[0].upgrade * 100;
			cp /= cbp;
			cp *= 10;

			if (cp >= 10)
			{
				SetSpriteState(&g_CHARGEBAR, 0);
			}
			else if (cp >= 9)
			{
				SetSpriteState(&g_CHARGEBAR, 1);
			}
			else if (cp >= 8)
			{
				SetSpriteState(&g_CHARGEBAR, 2);
			}
			else if (cp >= 7)
			{
				SetSpriteState(&g_CHARGEBAR, 3);
			}
			else if (cp >= 6)
			{
				SetSpriteState(&g_CHARGEBAR, 4);
			}
			else if (cp >= 5)
			{
				SetSpriteState(&g_CHARGEBAR, 5);
			}
			else if (cp >= 4)
			{
				SetSpriteState(&g_CHARGEBAR, 6);
			}
			else if (cp >= 3)
			{
				SetSpriteState(&g_CHARGEBAR, 7);
			}
			else if (cp >=  2)
			{
				SetSpriteState(&g_CHARGEBAR, 8);
			}
			else if (cp >=  1)
			{
				SetSpriteState(&g_CHARGEBAR, 9);
			}
			else
			{
				SetSpriteState(&g_CHARGEBAR, 10);
			}

			double bp = g_PLAYER.battery;
			int mbp = g_PLAYER.maxbattery;
			bp /= mbp;
			bp *= 10;

			if (bp >= 10)
			{
				SetSpriteState(&g_BATTERY, 0);
			}
			else if (bp >= 9)
			{
				SetSpriteState(&g_BATTERY, 1);
			}
			else if (bp >= 8)
			{
				SetSpriteState(&g_BATTERY, 2);
			}
			else if (bp >= 7)
			{
				SetSpriteState(&g_BATTERY, 3);
			}
			else if (bp >= 6)
			{
				SetSpriteState(&g_BATTERY, 4);
			}
			else if (bp >= 5)
			{
				SetSpriteState(&g_BATTERY, 5);
			}
			else if (bp >= 4)
			{
				SetSpriteState(&g_BATTERY, 6);
			}
			else if (bp >= 3)
			{
				SetSpriteState(&g_BATTERY, 7);
			}
			else if (bp >=  2)
			{
				SetSpriteState(&g_BATTERY, 8);
			}
			else
			{
				SetSpriteState(&g_BATTERY, 9);
			}

			g_HEADBAR[0].position.y = ((gridalignment) * 15) + 12;
			g_HEADBAR[0].position.x = ((gridalignment) * 0) + 0;
			double hp = g_PLAYER.health;
			int mhp = g_PLAYER.maxhealth;
			hp /= mhp;
			hp *= 15;

			if (hp >= 15)
			{
				SetSpriteState(&g_HEADBAR[0], 0);
			}
			else if (hp >= 14)
			{
				SetSpriteState(&g_HEADBAR[0], 1);
			}
			else if (hp >= 13 )
			{
				SetSpriteState(&g_HEADBAR[0], 2);
			}
			else if (hp >= 12)
			{
				SetSpriteState(&g_HEADBAR[0], 3);
			}
			else if (hp >= 11)
			{
				SetSpriteState(&g_HEADBAR[0], 4);
			}
			else if (hp >= 10)
			{
				SetSpriteState(&g_HEADBAR[0], 5);
			}
			else if (hp >= 9)
			{
				SetSpriteState(&g_HEADBAR[0], 6);
			}
			else if (hp >= 8)
			{
				SetSpriteState(&g_HEADBAR[0], 7);
			}
			else if (hp >= 7)
			{
				SetSpriteState(&g_HEADBAR[0], 8);
			}
			else if (hp >= 6)
			{
				SetSpriteState(&g_HEADBAR[0], 9);
			}
			else if (hp >= 5)
			{
				SetSpriteState(&g_HEADBAR[0], 10);
			}
			else if (hp >= 4)
			{
				SetSpriteState(&g_HEADBAR[0], 11);
			}
			else if (hp >= 3)
			{
				SetSpriteState(&g_HEADBAR[0], 12);
			}
			else if (hp >=  2)
			{
				SetSpriteState(&g_HEADBAR[0], 13);
			}
			else if (hp >= 1)
			{
				SetSpriteState(&g_HEADBAR[0], 14);
			}
			else
			{
				SetSpriteState(&g_HEADBAR[0], 15);
			}

			hp = g_PLAYER.health;
			mhp = g_PLAYER.maxhealth;
			hp /= mhp;
			hp *= 10;

			if (hp >= 10)
			{
				SetSpriteState(&g_HEALTHBAR, 0);
			}
			else if (hp >= 9)
			{
				SetSpriteState(&g_HEALTHBAR, 1);
			}
			else if (hp >= 8)
			{
				SetSpriteState(&g_HEALTHBAR, 2);
			}
			else if (hp >= 7)
			{
				SetSpriteState(&g_HEALTHBAR, 3);
			}
			else if (hp >= 6)
			{
				SetSpriteState(&g_HEALTHBAR, 4);
			}
			else if (hp >= 5)
			{
				SetSpriteState(&g_HEALTHBAR, 5);
			}
			else if (hp >= 4)
			{
				SetSpriteState(&g_HEALTHBAR, 6);
			}
			else if (hp >= 3)
			{
				SetSpriteState(&g_HEALTHBAR, 7);
			}
			else if (hp >=  2)
			{
				SetSpriteState(&g_HEALTHBAR, 8);
			}
			else if (hp >= 1)
			{
				SetSpriteState(&g_HEALTHBAR, 9);
			}
			else
			{
				SetSpriteState(&g_HEALTHBAR, 10);
			}


			if (hp <= 4)
			{
				for (int x = 0; x < 4; x++)
				{
					if (g_SMOKE[0].condition == dead)
					{
						g_SMOKE[0].life = 0;
						g_SMOKE[0].position.y = g_PLAYER.position.y;
						g_SMOKE[0].position.x = g_PLAYER.position.x;
						g_SMOKE[0].type = rand1.RandInt(1,3);
						g_SMOKE[0].condition = alive;
						g_SMOKE[0].yhold = smokespeed;
						g_SMOKE[0].xhold = rand1.RandInt(-2,2);
						break;
					}
					else if (g_SMOKE[x-1].life >= 14
						&& g_SMOKE[x].condition == dead)
					{
						g_SMOKE[x].life = 0;
						g_SMOKE[x].position.y = g_PLAYER.position.y + rand1.RandInt(4,12);
						g_SMOKE[x].position.x = g_PLAYER.position.x;
						g_SMOKE[x].condition = alive;
						g_SMOKE[x].type = rand1.RandInt(1,3);
						g_SMOKE[x].yhold = smokespeed;
						g_SMOKE[x].xhold = rand1.RandInt(-2,2);
						break;
					}
				}
			}
			if (hp <= 4)
			{ 
				for (int x = 0; x < max_level_tiles; x++)
				{
					if (g_SPARK[0].condition == dead)
					{
						g_SPARK[0].life = 0;
						g_SPARK[0].position.y = (g_PLAYER.position.y + g_PLAYER.SIZEheight / 2) + rand1.RandInt(0,2);
						g_SPARK[0].position.x = g_PLAYER.position.x + g_PLAYER.SIZEwidth / 2;
						g_SPARK[0].condition = alive;
						g_SPARK[0].yhold = sparkspeed;
						g_SPARK[0].xhold = 0;
						break;
					}
					else if (g_SPARK[x-1].life >= 11
						&& g_SPARK[x].condition == dead)
					{
						g_SPARK[x].life = 0;
						g_SPARK[x].position.y = (g_PLAYER.position.y + g_PLAYER.SIZEheight / 2) + rand1.RandInt(0,2);
						g_SPARK[x].position.x = g_PLAYER.position.x + g_PLAYER.SIZEwidth / 2;
						g_SPARK[x].condition = alive;
						g_SPARK[x].yhold = sparkspeed;
						g_SPARK[x].xhold = 0;
						break;
					}
				}
			}
		}

		//ABOUT 1 in 10 PEOPLE THINK IN BINARY!

		for (int a = 0; a < maxally; a++) //allies alive, set sprite for head and underneath ship
		{
			if (g_ALLY[a].condition != dead)
			{
				double hp = g_ALLY[a].health;
				int mhp = g_ALLY[a].maxhealth;
				hp /= mhp;
				hp *= 10;
				if (hp >= 10)
				{
					SetSpriteState(&g_ALLYBAR[a], NORTH);
				}
				else if (hp >= 9)
				{
					SetSpriteState(&g_ALLYBAR[a], EAST);
				}
				else if (hp >= 8)
				{
					SetSpriteState(&g_ALLYBAR[a], SOUTH);
				}
				else if (hp >= 7)
				{
					SetSpriteState(&g_ALLYBAR[a], WEST);
				}
				else if (hp >= 6)
				{
					SetSpriteState(&g_ALLYBAR[a], NONE);
				}
				else if (hp >= 5)
				{
					SetSpriteState(&g_ALLYBAR[a], NORTHEAST);
				}
				else if (hp >= 4)
				{
					SetSpriteState(&g_ALLYBAR[a], SOUTHEAST);
				}
				else if (hp >= 3)
				{
					SetSpriteState(&g_ALLYBAR[a], NORTHWEST);
				}
				else if (hp >= 2)
				{
					SetSpriteState(&g_ALLYBAR[a], SOUTHWEST);
				}
				else if (hp >= 1)
				{
					SetSpriteState(&g_ALLYBAR[a], ANIMATION1);
				}
			}
			else 
			{
				g_ALLYBAR[a].position.y = -32;
				g_ALLYBAR[a].position.x = -32;
			}
		}


		//AMMO BAR
		if (g_PLAYER.health != dead)//AMMO BAR...underneath player..may or maynot remove..
			//tells you when you can shoot again (when your shots are "dead"
		{
				if (space_hold_time >= 700)
				{
					SetSpriteState(&g_AMMOBAR, NORTH);
				}
				else if (space_hold_time  >= 630)
				{
					SetSpriteState(&g_AMMOBAR, EAST);
				}
				else if (space_hold_time  >= 560)
				{
					SetSpriteState(&g_AMMOBAR, SOUTH);
				}
				else if (space_hold_time  >= 490)
				{
					SetSpriteState(&g_AMMOBAR, WEST);
				}
				else if (space_hold_time  >= 420)
				{
					SetSpriteState(&g_AMMOBAR, NONE);
				}
				else if (space_hold_time  >= 350)
				{
					SetSpriteState(&g_AMMOBAR, NORTHEAST);
				}
				else if (space_hold_time  >= 280)
				{
					SetSpriteState(&g_AMMOBAR, SOUTHEAST);
				}
				else if (space_hold_time  >= 210)
				{
					SetSpriteState(&g_AMMOBAR, NORTHWEST);
				}
				else if (space_hold_time  >= 140)
				{
					SetSpriteState(&g_AMMOBAR, SOUTHWEST);
				}
				else if (space_hold_time >= 70)
				{
					SetSpriteState(&g_AMMOBAR, ANIMATION1);
				}
				else
				{
					SetSpriteState(&g_AMMOBAR, ANIMATION2);
				}
		}

		/*GENERATE RANDOM POWERUPS WHILE PLAYING*/
//powerup stuff
		//power_up(-2);
		

	//RANDOM SHOTS FOR ENEMIES
	if (g_PLAYER.condition == alive)
	{
		check_for_enemy_shot();
	}

	for (x = 0; x < max_level_tiles; x++) 
	{
		//if enemy off screen or dead, set to dead and move to -32 -32
		kill_laser_if_dead(x); //in enemy.h
		kill_enemy_if_dead(x);
	}

		//animate the heads on HUD
		for (x = 0; x < maxally+1; x++)
		{
			if (g_HEAD[x].condition >= spawning && g_HEAD[x].condition < unspawning)
			{
				if (g_HEAD[x].condition == spawning + 1)
				{
					g_HEAD[x].position.y = ((gridalignment) * 15) + 10;
					g_HEAD[x].position.x = ((gridalignment+18) * x) + 8;
					g_HEAD[x].condition++;
				}
				if (g_HEAD[x].condition >= spawned)
				{
					g_HEAD[x].condition = alive;
					SetSpriteState(&g_HEAD[x], 0);
				}
				else
				{
					SetSpriteState(&g_HEAD[x], g_HEAD[x].condition);
					g_HEAD[x].condition++;
				}
			}
			else if (g_HEAD[x].condition >= unspawning)
			{
				SetSpriteState(&g_HEAD[x], g_HEAD[x].condition);
				if (g_HEAD[x].condition == unspawning + 1)
				{
					g_HEAD[x].position.y = (gridalignment) * 15;
					g_HEAD[x].position.x = (gridalignment+18) * x;
					g_HEAD[x].condition++;
				}
				if (g_HEAD[x].condition >= unspawned)
				{
					g_HEAD[x].condition = dead;
					g_HEAD[x].position.y = (gridalignment) -400;
					g_HEAD[x].position.y = (gridalignment) -400;
					SetSpriteState(&g_HEAD[x], 0);
				}
				else
				{
					SetSpriteState(&g_HEAD[x], g_HEAD[x].condition);
					g_HEAD[x].condition++;
				}
			}
			else if (g_PLAYER.condition == alive && g_HEAD[0].condition == dead)
			{
				g_HEAD[0].condition = alive;
				g_HEAD[0].position.y = (gridalignment) * 15;
				g_HEAD[0].position.x = (gridalignment+18) * 0;
			}
			else if (g_HEAD[x].condition == dead)
			{
				g_HEAD[x].position.y = -400;
				g_HEAD[x].position.x = -400;
			}
			else if (g_HEAD[x].condition > alive && g_HEAD[x].condition < spawning)
			{
				g_HEAD[x].condition++;
				if(g_HEAD[x].condition >= dyingfive)
				{
					if (g_PLAYER.health > 2 && x == 0)
					{
						g_HEAD[x].condition = alive;
						SetSpriteState(&g_HEAD[x], 0);
						if (g_PLAYER.health <= 0 && x == 0)
						{
							g_HEAD[x].condition = unspawning;
							SetSpriteState(&g_HEAD[x], 0);
						}
					}
					else if (g_ALLY[x-1].health > 2 && x > 0)
					{
						g_HEAD[x].condition = alive;
						SetSpriteState(&g_HEAD[x], 0);
						if (g_ALLY[x-1].health <= 0 && x > 0 && g_HEAD[x].condition != dead)
						{
							g_HEAD[x].condition = unspawning;
							SetSpriteState(&g_HEAD[x], 0);
						}
					}
					else
					{
						g_HEAD[x].condition = dyingone;
					}
				}
				if (g_HEAD[x].condition != alive)
				{
					SetSpriteState(&g_HEAD[x], g_HEAD[x].condition - 2);
				}
			}
		}

		//check to see if a backround has been killed
		for (x = 0; x < 10; x++)
		{
			if (g_BACKROUND[x].position.y >= gridalignment * 15)
			{
				g_BACKROUND[x].hBitmap = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapNormal = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapNightVision = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapThermalVision = g_switcher.hBitmap;
				g_BACKROUND[x].condition = dead;
				g_BACKROUND[x].width = 1;
				g_BACKROUND[x].height = 1;
				g_BACKROUND[x].position.y = -500;
				g_BACKROUND[x].position.x = -500;
				g_BACKROUND[x].loaded = no;
			}
			if (g_time >= 1999)
			{
				g_BACKROUND[x].hBitmap = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapNormal = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapNightVision = g_switcher.hBitmap;
				g_BACKROUND[x].hBitmapThermalVision = g_switcher.hBitmap;
				g_BACKROUND[x].condition = dyingone;
				g_BACKROUND[x].width = 1;
				g_BACKROUND[x].height = 1;
				g_BACKROUND[x].position.y = -500;
				g_BACKROUND[x].position.x = -500;
				g_BACKROUND[x].loaded = no;
			}
			SetSpriteState(&g_BACKROUND[x], 0);
		}

		check_for_kill_or_load_enemy(x);

		//update powerups & mission backrounds
		if (READY == yes)
		{
			for (x = 0; x < max_level_tiles; x++)
			{
				if (x < 5)
				{
					if (g_POWERUP[x].condition == alive)
					{
						g_POWERUP[x].yhold++;
						if (g_time % 20 == 0)
						{
							g_POWERUP[x].yhold = 0;
							if (g_POWERUP[x].change == yes)
							{
								g_POWERUP[x].type++;
							}
							if (g_POWERUP[x].type > 10)
							{
								g_POWERUP[x].type = 0;
							}
							SetSpriteState(&g_POWERUP[x], g_POWERUP[x].type);
						}
						script_sequence(x, yes);
					}
					if (g_POWERUP[x].condition == alive && g_POWERUP[x].position.y >= 480)
					{
						g_POWERUP[x].condition = dead;
						g_POWERUP[x].position.y = -32;
						g_POWERUP[x].position.x = -32;
					}
				}
				if (g_time == -449)
				{
					for (int reset = 0; reset < 10;reset++)
					{
						FreeSprite(&g_BACKROUND[reset]);
						g_BACKROUND[reset].condition = dyingone;
						g_BACKROUND[reset].hBitmap = g_switcher.hBitmap;
						g_BACKROUND[reset].SIZEwidth = 1;
						g_BACKROUND[reset].SIZEheight = 1;
						g_BACKROUND[reset].position.y = -500;
						g_BACKROUND[reset].position.x = -500;
						g_BACKROUND[reset].loaded = no;
					}
				}
				//!ending
				//ENDING
				
				if (g_PLAYER.mission == -5 && g_BACKROUND[3].condition != dead && x == 3 && g_time == -2347)
				{
					g_BACKROUND[3].SIZEwidth = 480;
					g_BACKROUND[3].SIZEheight = 800;
					LoadSprite(&g_BACKROUND[3], "BBACKROUNDA.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
					
					if (g_BACKROUND[3].condition == dyingone)
					{
						g_BACKROUND[3].position.y = 300;
						g_BACKROUND[3].position.x = -10;
					}
					g_BACKROUND[3].condition = alive;
					SetSpriteState(&g_BACKROUND[3], NORTH);
					g_BACKROUND[3].loaded = yes;
					g_BACKROUND[3].moved = no;
					g_BACKROUND[3].closeness = 15;
				}
				if (g_PLAYER.mission == -5 && g_BACKROUND[3].condition == alive && x == 1)
				{
					g_BACKROUND[3].moved = yes;
					g_BACKROUND[3].position.y -= 1;
				}
				if (g_PLAYER.mission == -5 && ((g_BACKROUND[3].position.y <= -g_BACKROUND[3].SIZEheight && (g_time >= -2320 && g_time <= 0)) || (g_time >= -2320 && g_time <= 0 && GetAsyncKeyState(VK_SPACE))))
				{
					return 0;
				}
				
				
				if (g_PLAYER.mission == -5 && g_ENDING[1].condition != dead && x == 1 && g_time == -2349)
				{
					g_ENDING[1].SIZEwidth = 519;
					g_ENDING[1].SIZEheight = 321;
					LoadSprite(&g_ENDING[1], "BENDINGB1.bmp", g_ENDING[1].SIZEwidth, g_ENDING[1].SIZEheight, PLAYER_FRAMES);
					
					if (g_ENDING[1].condition == dyingone)
					{
						g_ENDING[1].position.y = 0;
						g_ENDING[1].position.x = 479;
					}
					g_ENDING[1].condition = alive;
					SetSpriteState(&g_ENDING[1], NORTH);
					g_ENDING[1].loaded = yes;
					g_ENDING[1].moved = no;
					g_ENDING[1].closeness = 15;
				}
				if (g_PLAYER.mission == -5 && g_ENDING[1].condition == alive && x == 1)
				{
					g_ENDING[1].moved = yes;
					g_ENDING[1].position.x -= 5;
				}
				
				
			if (g_PLAYER.mission == -5 && x == 2 && g_time == -2100)
				{
					FreeSprite(&g_ENDING[1]);
					g_ENDING[2].SIZEwidth = 523;
					g_ENDING[2].SIZEheight = 294;
					LoadSprite(&g_ENDING[2], "BENDINGB2.bmp", g_ENDING[2].SIZEwidth, g_ENDING[2].SIZEheight, PLAYER_FRAMES);
					
					if (g_ENDING[2].condition == dyingone)
					{
						g_ENDING[2].position.y = 0;
						g_ENDING[2].position.x = 479;
					}
					g_ENDING[2].condition = alive;
					SetSpriteState(&g_ENDING[2], NORTH);
					g_ENDING[2].loaded = yes;
					g_ENDING[2].moved = no;
					g_ENDING[2].closeness = 15;
				}
				if (g_PLAYER.mission == -5&& g_ENDING[2].condition == alive && x == 2)
				{
					g_ENDING[2].moved = yes;
					g_ENDING[2].position.x -= 5;
				}
				if (g_PLAYER.mission == -5 && x == 3 && g_time == -1950)
				{
					FreeSprite(&g_ENDING[2]);
					g_ENDING[0].SIZEwidth = 566;
					g_ENDING[0].SIZEheight = 382;
					LoadSprite(&g_ENDING[0], "BENDINGB3.bmp", g_ENDING[0].SIZEwidth, g_ENDING[0].SIZEheight, PLAYER_FRAMES);
					
					if (g_ENDING[0].condition == dyingone)
					{
						g_ENDING[0].position.y = 0;
						g_ENDING[0].position.x = 479;
					}
					g_ENDING[0].condition = alive;
					SetSpriteState(&g_ENDING[0], NORTH);
					g_ENDING[0].loaded = yes;
					g_ENDING[0].moved = no;
					g_ENDING[0].closeness = 15;
				}
				if (g_PLAYER.mission == -5&& g_ENDING[0].condition == alive && x == 3)
				{
					g_ENDING[0].moved = yes;
					g_ENDING[0].position.x -= 5;
				}/*
				if (g_PLAYER.mission != -5 g_BACKROUND[x].condition == alive && x == 2)
				{
					g_BACKROUND[2].moved = yes;
					g_BACKROUND[2].position.x += 1;
				}
				*/
				/*
				//LARGECRYSTALINBEGINING
				if (g_PLAYER.mission == 0 && g_BACKROUND[2].condition != dead && x == 2 && g_time == -449)
				{
					
					g_BACKROUND[2].SIZEwidth = 480;
					g_BACKROUND[2].SIZEheight = 480;
					LoadSprite(&g_BACKROUND[2], "BDOODAD6.bmp", g_BACKROUND[2].SIZEwidth, g_BACKROUND[2].SIZEheight, PLAYER_FRAMES);
				
					g_BACKROUND[2].hBitmapNormal = LoadABitmap("BDOODAD6.bmp");
					g_BACKROUND[2].hBitmapNightVision = LoadABitmap("BDOODAD6NV.bmp");
					g_BACKROUND[2].hBitmapThermalVision = LoadABitmap("BDOODAD6TH.bmp");
					
					if (g_BACKROUND[2].condition == dyingone)
					{
						g_BACKROUND[2].position.y = 0;
						g_BACKROUND[2].position.x = 0;
					}
					g_BACKROUND[2].condition = alive;
					SetSpriteState(&g_BACKROUND[2], NORTH);
					g_BACKROUND[2].loaded = yes;
					g_BACKROUND[2].moved = no;
					g_BACKROUND[2].closeness = 15;
				}
				if (g_PLAYER.mission == 0 && g_BACKROUND[2].condition == alive && x == 2 && (g_time % 3 == 1 || g_time % 3 == -1))
				{
					g_BACKROUND[2].moved = yes;
					g_BACKROUND[2].position.x += 2;
				}
				//PLANET
				if (g_PLAYER.mission == 0 && g_BACKROUND[0].condition != dead && x == 0 && g_time == 125)
				{
					
					g_BACKROUND[0].SIZEwidth = 365;
					g_BACKROUND[0].SIZEheight = 292;
					LoadSprite(&g_BACKROUND[0], "BLvl1.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
				
					g_BACKROUND[0].hBitmapNormal = LoadABitmap("BLvl1.bmp");
					g_BACKROUND[0].hBitmapNightVision = LoadABitmap("BLvl1NV.bmp");
					g_BACKROUND[0].hBitmapThermalVision = LoadABitmap("BLvl1TH.bmp");
										
					SetSpriteState(&g_BACKROUND[0], NORTH);
					if (g_BACKROUND[0].condition == dyingone)
					{
						g_BACKROUND[0].position.y = -364;
						g_BACKROUND[0].position.x = 200;
					}
					g_BACKROUND[0].closeness = 20;
					g_BACKROUND[0].loaded = yes;
					g_BACKROUND[0].moved = no;
					g_BACKROUND[0].condition = alive;
				}
				if (g_PLAYER.mission == 0 && g_BACKROUND[0].condition == alive && x == 0)
				{
					g_BACKROUND[0].moved = yes;
					g_BACKROUND[0].position.y += 1;
				}
				//ASTEROID
				if (g_PLAYER.mission == 0 && g_BACKROUND[1].condition != dead && x == 0 && g_time == 1000)
				{
					
					g_BACKROUND[1].SIZEwidth = 160;
					g_BACKROUND[1].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[1], "BLargeasteroidL.bmp", g_BACKROUND[1].SIZEwidth, g_BACKROUND[1].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[1].hBitmapNormal = LoadABitmap("BLargeasteroidL.bmp");
					g_BACKROUND[1].hBitmapNightVision = LoadABitmap("BLargeasteroidLNV.bmp");
					g_BACKROUND[1].hBitmapThermalVision = LoadABitmap("BLargeasteroidLTH.bmp");
						
					SetSpriteState(&g_BACKROUND[1], NORTH);
					if (g_BACKROUND[1].condition == dyingone)
					{
						g_BACKROUND[1].position.y = -200;
						g_BACKROUND[1].position.x = 0;
					}
					g_BACKROUND[1].closeness = 20;
					g_BACKROUND[1].loaded = yes;
					g_BACKROUND[1].moved = no;
					g_BACKROUND[1].condition = alive;
				}
				if (g_PLAYER.mission == 0 && g_BACKROUND[1].condition == alive && x == 0)
				{
					g_BACKROUND[1].moved = yes;
					g_BACKROUND[1].position.y += 2;
				}
				//MOON1
				if (g_PLAYER.mission == 1 && g_BACKROUND[3].condition != dead && x == 3 && g_time == -200)
				{
					
					g_BACKROUND[3].SIZEwidth = 480;
					g_BACKROUND[3].SIZEheight = 128;
					LoadSprite(&g_BACKROUND[3], "Blvl2a.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[3].hBitmapNormal = LoadABitmap("Blvl2a.bmp");
					g_BACKROUND[3].hBitmapNightVision = LoadABitmap("Blvl2aNV.bmp");
					g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("Blvl2aTH.bmp");
						
					SetSpriteState(&g_BACKROUND[3], NORTH);
					if (g_BACKROUND[3].condition == dyingone)
					{
						g_BACKROUND[3].position.y = -128;
						g_BACKROUND[3].position.x = 0;
					}
					g_BACKROUND[3].closeness = 20;
					g_BACKROUND[3].loaded = yes;
					g_BACKROUND[3].moved = no;
					g_BACKROUND[3].condition = alive;
				}
				if (g_PLAYER.mission == 1 && g_BACKROUND[3].condition == alive && x == 3)
				{
					g_BACKROUND[3].moved = yes;
					g_BACKROUND[3].position.y += 1;
				}
				//MOON2
				if (g_PLAYER.mission == 2 && g_BACKROUND[4].condition != dead && x == 4 && g_time == -449)
				{
					
					g_BACKROUND[4].SIZEwidth = 480;
					g_BACKROUND[4].SIZEheight = 128;
					LoadSprite(&g_BACKROUND[4], "Blvl2b.bmp", g_BACKROUND[4].SIZEwidth, g_BACKROUND[4].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[4].hBitmapNormal = LoadABitmap("Blvl2b.bmp");
					g_BACKROUND[4].hBitmapNightVision = LoadABitmap("Blvl2bNV.bmp");
					g_BACKROUND[4].hBitmapThermalVision = LoadABitmap("Blvl2bTH.bmp");
						
					SetSpriteState(&g_BACKROUND[4], NORTH);
					if (g_BACKROUND[4].condition == dyingone)
					{
						g_BACKROUND[4].position.y = -128;
						g_BACKROUND[4].position.x = 0;
					}
					g_BACKROUND[4].closeness = 20;
					g_BACKROUND[4].loaded = yes;
					g_BACKROUND[4].moved = no;
					g_BACKROUND[4].condition = alive;
				}
				if (g_PLAYER.mission == 2 && g_BACKROUND[4].condition == alive && x == 4)
				{
					g_BACKROUND[4].moved = yes;
					g_BACKROUND[4].position.y += 1;
				}
				//BROKEN
				if (g_PLAYER.mission == 2 && g_BACKROUND[5].condition != dead && x == 0 && g_time == 125)
				{
					
					g_BACKROUND[5].SIZEwidth = 365;
					g_BACKROUND[5].SIZEheight = 292;
					LoadSprite(&g_BACKROUND[5], "Blvl3.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[5].hBitmapNormal = LoadABitmap("Blvl3.bmp");
					g_BACKROUND[5].hBitmapNightVision = LoadABitmap("Blvl3NV.bmp");
					g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("Blvl3TH.bmp");
						
					SetSpriteState(&g_BACKROUND[5], NORTH);
					if (g_BACKROUND[5].condition == dyingone)
					{
						g_BACKROUND[5].position.y = -292;
						g_BACKROUND[5].position.x = 0;
					}
					g_BACKROUND[5].closeness = 20;
					g_BACKROUND[5].loaded = yes;
					g_BACKROUND[5].moved = no;
					g_BACKROUND[5].condition = alive;
				}
				if (g_PLAYER.mission == 2 && g_BACKROUND[5].condition == alive && x == 0)
				{
					g_BACKROUND[5].moved = yes;
					g_BACKROUND[5].position.y += 1;
				}
				//WHIRL
				if (g_PLAYER.mission == 2 && g_BACKROUND[6].condition != dead && x == 0 && g_time == 1000)
				{
					g_BACKROUND[6].SIZEwidth = 160;
					g_BACKROUND[6].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[6], "BDOODAD1.bmp", g_BACKROUND[6].SIZEwidth, g_BACKROUND[6].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[6].hBitmapNormal = LoadABitmap("BDOODAD1.bmp");
					g_BACKROUND[6].hBitmapNightVision = LoadABitmap("BDOODAD1NV.bmp");
					g_BACKROUND[6].hBitmapThermalVision = LoadABitmap("BDOODAD1TH.bmp");
						
					SetSpriteState(&g_BACKROUND[6], NORTH);
					if (g_BACKROUND[6].condition == dyingone)
					{
						g_BACKROUND[6].position.y = -299;
						g_BACKROUND[6].position.x = 480-170;
					}
					g_BACKROUND[6].closeness = 20;
					g_BACKROUND[6].loaded = yes;
					g_BACKROUND[6].moved = no;
					g_BACKROUND[6].condition = alive;
				}
				if (g_PLAYER.mission == 2 && g_BACKROUND[6].condition == alive && x == 0)
				{
					g_BACKROUND[6].moved = yes;
					g_BACKROUND[6].position.y += 1;
				}
				//XTHING
				if (g_PLAYER.mission == 3 && g_BACKROUND[7].condition != dead && x == 0 && g_time == -450)
				{
					
					g_BACKROUND[7].SIZEwidth = 200;
					g_BACKROUND[7].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[7], "BDOODAD2.bmp", g_BACKROUND[7].SIZEwidth, g_BACKROUND[7].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[7].hBitmapNormal = LoadABitmap("BDOODAD2.bmp");
					g_BACKROUND[7].hBitmapNightVision = LoadABitmap("BDOODAD2NV.bmp");
					g_BACKROUND[7].hBitmapThermalVision = LoadABitmap("BDOODAD2TH.bmp");
						
					SetSpriteState(&g_BACKROUND[7], NORTH);
					if (g_BACKROUND[7].condition == dyingone)
					{
						g_BACKROUND[7].position.y = -200;
						g_BACKROUND[7].position.x = 200;
					}
					g_BACKROUND[7].closeness = 20;
					g_BACKROUND[7].loaded = yes;
					g_BACKROUND[7].moved = no;
					g_BACKROUND[7].condition = alive;
				}
				if (g_PLAYER.mission == 3 && g_BACKROUND[7].condition == alive && x == 0)
				{
					g_BACKROUND[7].moved = yes;
					g_BACKROUND[7].position.y += 1;
				}
				//WHIRL
				if (g_PLAYER.mission == 3 && g_BACKROUND[8].condition != dead && x == 0 && g_time == 125)
				{
					
					g_BACKROUND[8].SIZEwidth = 300;
					g_BACKROUND[8].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[8], "BDOODAD3.bmp", g_BACKROUND[8].SIZEwidth, g_BACKROUND[8].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[8].hBitmapNormal = LoadABitmap("BDOODAD3.bmp");
					g_BACKROUND[8].hBitmapNightVision = LoadABitmap("BDOODAD3NV.bmp");
					g_BACKROUND[8].hBitmapThermalVision = LoadABitmap("BDOODAD3TH.bmp");
						
					SetSpriteState(&g_BACKROUND[8], NORTH);
					if (g_BACKROUND[8].condition == dyingone)
					{
						g_BACKROUND[8].position.y = -300;
						g_BACKROUND[8].position.x = 480-280;
					}
					g_BACKROUND[8].closeness = 20;
					g_BACKROUND[8].loaded = yes;
					g_BACKROUND[8].moved = no;
					g_BACKROUND[8].condition = alive;
				}
				if (g_PLAYER.mission == 3 && g_BACKROUND[8].condition == alive && x == 0)
				{
					g_BACKROUND[8].moved = yes;
					g_BACKROUND[8].position.y += 1;
				}
				//CRYS
				if (g_PLAYER.mission == 3 && g_BACKROUND[9].condition != dead && x == 0 && g_time == 1000)
				{
					
					g_BACKROUND[9].SIZEwidth = 409;
					g_BACKROUND[9].SIZEheight = 424;
					LoadSprite(&g_BACKROUND[9], "BDOODAD4.bmp", g_BACKROUND[9].SIZEwidth, g_BACKROUND[9].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[9].hBitmapNormal = LoadABitmap("BDOODAD4.bmp");
					g_BACKROUND[9].hBitmapNightVision = LoadABitmap("BDOODAD4NV.bmp");
					g_BACKROUND[9].hBitmapThermalVision = LoadABitmap("BDOODAD4TH.bmp");
						
					SetSpriteState(&g_BACKROUND[9], NORTH);
					if (g_BACKROUND[9].condition == dyingone)
					{
						g_BACKROUND[9].position.y = -409;
						g_BACKROUND[9].position.x = -30;
					}
					g_BACKROUND[9].closeness = 20;
					g_BACKROUND[9].loaded = yes;
					g_BACKROUND[9].moved = no;
					g_BACKROUND[9].condition = alive;
				}
				if (g_PLAYER.mission == 3 && g_BACKROUND[9].condition == alive && x == 0)
				{
					g_BACKROUND[9].moved = yes;
					g_BACKROUND[9].position.y += 1;
				}
				//CRYS
				if (g_PLAYER.mission == 4 && g_BACKROUND[0].condition != dead && x == 0 && g_time == -449)
				{
					
					g_BACKROUND[0].SIZEwidth = 278;
					g_BACKROUND[0].SIZEheight = 286;
					LoadSprite(&g_BACKROUND[0], "BDOODAD5.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[0].hBitmapNormal = LoadABitmap("BDOODAD5.bmp");
					g_BACKROUND[0].hBitmapNightVision = LoadABitmap("BDOODAD5NV.bmp");
					g_BACKROUND[0].hBitmapThermalVision = LoadABitmap("BDOODAD5TH.bmp");
						
					SetSpriteState(&g_BACKROUND[0], NORTH);
					if (g_BACKROUND[0].condition == dyingone)
					{
						g_BACKROUND[0].position.y = -286;
						g_BACKROUND[0].position.x = 300;
					}
					g_BACKROUND[0].closeness = 20;
					g_BACKROUND[0].loaded = yes;
					g_BACKROUND[0].moved = no;
					g_BACKROUND[0].condition = alive;
				}
				if (g_PLAYER.mission == 4 && g_BACKROUND[0].condition == alive && x == 0)
				{
					g_BACKROUND[0].moved = yes;
					g_BACKROUND[0].position.y += 1;
				}
				//planetw/hole
				if (g_PLAYER.mission == 4 && g_BACKROUND[0].condition != dead && x == 0 && g_time == 125)
				{
					
					g_BACKROUND[0].SIZEwidth = 278;
					g_BACKROUND[0].SIZEheight = 286;
					LoadSprite(&g_BACKROUND[0], "Blvl4.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[0].hBitmapNormal = LoadABitmap("Blvl4.bmp");
					g_BACKROUND[0].hBitmapNightVision = LoadABitmap("Blvl4NV.bmp");
					g_BACKROUND[0].hBitmapThermalVision = LoadABitmap("Blvl4TH.bmp");
						
					SetSpriteState(&g_BACKROUND[0], NORTH);
					if (g_BACKROUND[0].condition == dyingone)
					{
						g_BACKROUND[0].position.y = -286;
						g_BACKROUND[0].position.x = 300;
					}
					g_BACKROUND[0].closeness = 20;
					g_BACKROUND[0].loaded = yes;
					g_BACKROUND[0].moved = no;
					g_BACKROUND[0].condition = alive;
				}
				if (g_PLAYER.mission == 4 && g_BACKROUND[0].condition == alive && x == 0)
				{
					g_BACKROUND[0].moved = yes;
					g_BACKROUND[0].position.y += 1;
				}
				//star
				if (g_PLAYER.mission == 4 && g_BACKROUND[2].condition != dead && x == 0 && g_time == 1000)
				{
					
					g_BACKROUND[2].SIZEwidth = 300;
					g_BACKROUND[2].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[2], "BDOODAD10.bmp", g_BACKROUND[2].SIZEwidth, g_BACKROUND[2].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[2].hBitmapNormal = LoadABitmap("BDOODAD10.bmp");
					g_BACKROUND[2].hBitmapNightVision = LoadABitmap("BDOODAD10NV.bmp");
					g_BACKROUND[2].hBitmapThermalVision = LoadABitmap("BDOODAD10TH.bmp");
						
					SetSpriteState(&g_BACKROUND[2], NORTH);
					if (g_BACKROUND[2].condition == dyingone)
					{
						g_BACKROUND[2].position.y = -300;
						g_BACKROUND[2].position.x = 200;
					}
					g_BACKROUND[2].closeness = 20;
					g_BACKROUND[2].loaded = yes;
					g_BACKROUND[2].moved = no;
					g_BACKROUND[2].condition = alive;
				}
				if (g_PLAYER.mission == 4 && g_BACKROUND[2].condition == alive && x == 0)
				{
					g_BACKROUND[2].moved = yes;
					g_BACKROUND[2].position.y += 1;
				}
				//METEOR1
				if (g_PLAYER.mission == 5 && g_BACKROUND[3].condition != dead && x == 3 && g_time % 240 == 0 && g_time < 2000 - 500)
				{
					
					g_BACKROUND[3].SIZEwidth = 100;
					g_BACKROUND[3].SIZEheight = 100;
					int randmet = rand1.RandInt(0,3);
					if (randmet == 1)
					{
						LoadSprite(&g_BACKROUND[3], "BDOODAD7.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[3].hBitmapNormal = LoadABitmap("BDOODAD7.bmp");
					g_BACKROUND[3].hBitmapNightVision = LoadABitmap("BDOODAD7NV.bmp");
					g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("BDOODAD7TH.bmp");
					
					}
					if (randmet == 2)
					{
						LoadSprite(&g_BACKROUND[3], "BDOODAD8.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[3].hBitmapNormal = LoadABitmap("BDOODAD8.bmp");
					g_BACKROUND[3].hBitmapNightVision = LoadABitmap("BDOODAD8NV.bmp");
					g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("BDOODAD8TH.bmp");
					
					}
					if (randmet == 3)
					{
						LoadSprite(&g_BACKROUND[3], "BDOODAD9.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[3].hBitmapNormal = LoadABitmap("BDOODAD9.bmp");
					g_BACKROUND[3].hBitmapNightVision = LoadABitmap("BDOODAD9NV.bmp");
					g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("BDOODAD9TH.bmp");
					
					}
					
					SetSpriteState(&g_BACKROUND[3], NORTH);
					if (g_BACKROUND[3].condition == dyingone)
					{
						g_BACKROUND[3].position.y = -100;
						g_BACKROUND[3].position.x = rand1.RandInt(0,380);
					}
					g_BACKROUND[3].closeness = 20;
					g_BACKROUND[3].loaded = yes;
					g_BACKROUND[3].moved = no;
					g_BACKROUND[3].condition = alive;
				}
				if (g_PLAYER.mission == 5 && g_BACKROUND[3].condition == alive && x == 3)
				{
					g_BACKROUND[3].moved = yes;
					g_BACKROUND[3].position.y += 3;
				}

				//METEOR2
				if (g_PLAYER.mission == 5 && g_BACKROUND[4].condition != dead && x == 4 && g_time % 240 == 0 && g_time < 2000 - 500)
				{
					
					g_BACKROUND[4].SIZEwidth = 100;
					g_BACKROUND[4].SIZEheight = 100;
					int randmet = rand1.RandInt(0,3);
					if (randmet == 1)
					{
						LoadSprite(&g_BACKROUND[4], "BDOODAD7.bmp", g_BACKROUND[4].SIZEwidth, g_BACKROUND[4].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[4].hBitmapNormal = LoadABitmap("BDOODAD7.bmp");
					g_BACKROUND[4].hBitmapNightVision = LoadABitmap("BDOODAD7NV.bmp");
					g_BACKROUND[4].hBitmapThermalVision = LoadABitmap("BDOODAD7TH.bmp");
					
					}
					if (randmet == 2)
					{
						LoadSprite(&g_BACKROUND[4], "BDOODAD8.bmp", g_BACKROUND[4].SIZEwidth, g_BACKROUND[4].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[4].hBitmapNormal = LoadABitmap("BDOODAD8.bmp");
					g_BACKROUND[4].hBitmapNightVision = LoadABitmap("BDOODAD8NV.bmp");
					g_BACKROUND[4].hBitmapThermalVision = LoadABitmap("BDOODAD8TH.bmp");
					
					}
					if (randmet == 3)
					{
						LoadSprite(&g_BACKROUND[4], "BDOODAD9.bmp", g_BACKROUND[4].SIZEwidth, g_BACKROUND[4].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[4].hBitmapNormal = LoadABitmap("BDOODAD9.bmp");
					g_BACKROUND[4].hBitmapNightVision = LoadABitmap("BDOODAD9NV.bmp");
					g_BACKROUND[4].hBitmapThermalVision = LoadABitmap("BDOODAD9TH.bmp");
					
					}
					SetSpriteState(&g_BACKROUND[4], NORTH);
					if (g_BACKROUND[4].condition == dyingone)
					{
						g_BACKROUND[4].position.y = -100;
						g_BACKROUND[4].position.x = rand1.RandInt(0,380);
					}
					g_BACKROUND[4].closeness = 20;
					g_BACKROUND[4].loaded = yes;
					g_BACKROUND[4].moved = no;
					g_BACKROUND[4].condition = alive;
				}
				if (g_PLAYER.mission == 5 && g_BACKROUND[4].condition == alive && x == 4)
				{
					g_BACKROUND[4].moved = yes;
					g_BACKROUND[4].position.y += 3;
				}

				//METEOR3
				if (g_PLAYER.mission == 5 && g_BACKROUND[5].condition != dead && x == 5 && g_time % 240 == 0 && g_time < 2000 - 500)
				{
					
					g_BACKROUND[5].SIZEwidth = 100;
					g_BACKROUND[5].SIZEheight = 100;
					int randmet = rand1.RandInt(0,3);
					if (randmet == 1)
					{
						LoadSprite(&g_BACKROUND[5], "BDOODAD7.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[5].hBitmapNormal = LoadABitmap("BDOODAD7.bmp");
					g_BACKROUND[5].hBitmapNightVision = LoadABitmap("BDOODAD7NV.bmp");
					g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("BDOODAD7TH.bmp");
					
					}
					if (randmet == 2)
					{
						LoadSprite(&g_BACKROUND[5], "BDOODAD8.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[5].hBitmapNormal = LoadABitmap("BDOODAD8.bmp");
					g_BACKROUND[5].hBitmapNightVision = LoadABitmap("BDOODAD8NV.bmp");
					g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("BDOODAD8TH.bmp");
					
					}
					if (randmet == 3)
					{
						LoadSprite(&g_BACKROUND[5], "BDOODAD9.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[5].hBitmapNormal = LoadABitmap("BDOODAD9.bmp");
					g_BACKROUND[5].hBitmapNightVision = LoadABitmap("BDOODAD9NV.bmp");
					g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("BDOODAD9TH.bmp");
					
					}
					SetSpriteState(&g_BACKROUND[5], NORTH);
					if (g_BACKROUND[5].condition == dyingone)
					{
						g_BACKROUND[5].position.y = -100;
						g_BACKROUND[5].position.x = rand1.RandInt(0,380);
					}
					g_BACKROUND[5].closeness = 20;
					g_BACKROUND[5].loaded = yes;
					g_BACKROUND[5].moved = no;
					g_BACKROUND[5].condition = alive;
				}
				if (g_PLAYER.mission == 5 && g_BACKROUND[5].condition == alive && x == 5)
				{
					g_BACKROUND[5].moved = yes;
					g_BACKROUND[5].position.y += 3;
				}

				//reset meteors
				if (g_PLAYER.mission == 5 && x == 3 && g_time % 240 == 239)
				{
					g_BACKROUND[3].hBitmap = g_switcher.hBitmap;
					g_BACKROUND[3].condition = dyingone;
					g_BACKROUND[3].SIZEwidth = 1;
					g_BACKROUND[3].SIZEheight = 1;
					g_BACKROUND[3].position.y = -500;
					g_BACKROUND[3].position.x = -500;
					g_BACKROUND[3].loaded = no;
				}
				if (g_PLAYER.mission == 5 && x == 4 && g_time % 290 == 239)
				{
					g_BACKROUND[4].hBitmap = g_switcher.hBitmap;
					g_BACKROUND[4].condition = dyingone;
					g_BACKROUND[4].SIZEwidth = 1;
					g_BACKROUND[4].SIZEheight = 1;
					g_BACKROUND[4].position.y = -500;
					g_BACKROUND[4].position.x = -500;
					g_BACKROUND[4].loaded = no;
				}
				if (g_PLAYER.mission == 5 && x == 5 && g_time % 340 == 239)
				{
					g_BACKROUND[5].hBitmap = g_switcher.hBitmap;
					g_BACKROUND[5].condition = dyingone;
					g_BACKROUND[5].SIZEwidth = 1;
					g_BACKROUND[5].SIZEheight = 1;
					g_BACKROUND[5].position.y = -500;
					g_BACKROUND[5].position.x = -500;
					g_BACKROUND[5].loaded = no;
				}
				//blue planet
				if (g_PLAYER.mission == 6 && g_BACKROUND[6].condition != dead && x == 6 && g_time == 0)
				{
					
					g_BACKROUND[6].SIZEwidth = 400;
					g_BACKROUND[6].SIZEheight = 400;
					LoadSprite(&g_BACKROUND[6], "Blvl5.bmp", g_BACKROUND[6].SIZEwidth, g_BACKROUND[6].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[6].hBitmapNormal = LoadABitmap("Blvl5.bmp");
					g_BACKROUND[6].hBitmapNightVision = LoadABitmap("Blvl5NV.bmp");
					g_BACKROUND[6].hBitmapThermalVision = LoadABitmap("Blvl5TH.bmp");
						
					SetSpriteState(&g_BACKROUND[6], NORTH);
					if (g_BACKROUND[6].condition == dyingone)
					{
						g_BACKROUND[6].position.y = -479;
						g_BACKROUND[6].position.x = 180;
					}
					g_BACKROUND[6].closeness = 20;
					g_BACKROUND[6].loaded = yes;
					g_BACKROUND[6].moved = no;
					g_BACKROUND[6].condition = alive;
				}
				if (g_PLAYER.mission == 6 && g_BACKROUND[6].condition == alive && x == 0)
				{
					g_BACKROUND[6].moved = yes;
					g_BACKROUND[6].position.y += 1;
				}
				//metoer planet
				if (g_PLAYER.mission == 6 && g_BACKROUND[7].condition != dead && x == 6 && g_time == 1000)
				{
					
					g_BACKROUND[7].SIZEwidth = 480;
					g_BACKROUND[7].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[7], "Blvl6.bmp", g_BACKROUND[7].SIZEwidth, g_BACKROUND[7].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[7].hBitmapNormal = LoadABitmap("Blvl6.bmp");
					g_BACKROUND[7].hBitmapNightVision = LoadABitmap("Blvl6NV.bmp");
					g_BACKROUND[7].hBitmapThermalVision = LoadABitmap("Blvl6TH.bmp");
						
					SetSpriteState(&g_BACKROUND[7], NORTH);
					if (g_BACKROUND[7].condition == dyingone)
					{
						g_BACKROUND[7].position.y = -479;
						g_BACKROUND[7].position.x = -50;
					}
					g_BACKROUND[7].closeness = 20;
					g_BACKROUND[7].loaded = yes;
					g_BACKROUND[7].moved = no;
					g_BACKROUND[7].condition = alive;
				}
				if (g_PLAYER.mission == 6 && g_BACKROUND[7].condition == alive && x == 0)
				{
					g_BACKROUND[7].moved = yes;
					g_BACKROUND[7].position.y += 1;
				}
				///nv
				if (g_PLAYER.mission == 7 && g_BACKROUND[8].condition != dead && x == 8 && g_time == -200)
				{
					
					g_BACKROUND[8].SIZEwidth = 480;
					g_BACKROUND[8].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[8], "BNV1.bmp", g_BACKROUND[8].SIZEwidth, g_BACKROUND[8].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[8].hBitmapNormal = LoadABitmap("BNV1.bmp");
					g_BACKROUND[8].hBitmapNightVision = LoadABitmap("BNV1NV.bmp");
					g_BACKROUND[8].hBitmapThermalVision = LoadABitmap("BNV1TH.bmp");
						
					SetSpriteState(&g_BACKROUND[8], NORTH);
					if (g_BACKROUND[8].condition == dyingone)
					{
						g_BACKROUND[8].position.y = -200;
						g_BACKROUND[8].position.x = 0;
					}
					g_BACKROUND[8].closeness = 20;
					g_BACKROUND[8].loaded = yes;
					g_BACKROUND[8].moved = no;
					g_BACKROUND[8].condition = alive;
				}
				if (g_PLAYER.mission == 7 && g_BACKROUND[8].condition == alive && x == 0)
				{
					g_BACKROUND[8].moved = yes;
					g_BACKROUND[8].position.y += 1;
				}
				if (g_PLAYER.mission == 8 && g_BACKROUND[1].condition != dead && x == 1 && g_time == -449)
				{
					
					g_BACKROUND[1].SIZEwidth = 480;
					g_BACKROUND[1].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[1], "BNV2.bmp", g_BACKROUND[1].SIZEwidth, g_BACKROUND[1].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[1].hBitmapNormal = LoadABitmap("BNV2.bmp");
					g_BACKROUND[1].hBitmapNightVision = LoadABitmap("BNV2NV.bmp");
					g_BACKROUND[1].hBitmapThermalVision = LoadABitmap("BNV2TH.bmp");
						
					SetSpriteState(&g_BACKROUND[1], NORTH);
					if (g_BACKROUND[1].condition == dyingone)
					{
						g_BACKROUND[1].position.y = -200;
						g_BACKROUND[1].position.x = 0;
					}
					g_BACKROUND[1].closeness = 20;
					g_BACKROUND[1].loaded = yes;
					g_BACKROUND[1].moved = no;
					g_BACKROUND[1].condition = alive;
				}
				if (g_PLAYER.mission == 8 && g_BACKROUND[1].condition == alive && x == 0)
				{
					g_BACKROUND[1].moved = yes;
					g_BACKROUND[1].position.y += 1;
				}
				//blue planet
				if (g_PLAYER.mission == 8 && g_BACKROUND[9].condition != dead && x == 9 && g_time == 425)
				{
					
					g_BACKROUND[9].SIZEwidth = 237;
					g_BACKROUND[9].SIZEheight = 237;
					LoadSprite(&g_BACKROUND[9], "Blvl7a.bmp", g_BACKROUND[9].SIZEwidth, g_BACKROUND[9].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[9].hBitmapNormal = LoadABitmap("Blvl7a.bmp");
					g_BACKROUND[9].hBitmapNightVision = LoadABitmap("Blvl7aNV.bmp");
					g_BACKROUND[9].hBitmapThermalVision = LoadABitmap("Blvl7aTH.bmp");
						
					SetSpriteState(&g_BACKROUND[9], NORTH);
					if (g_BACKROUND[9].condition == dyingone)
					{
						g_BACKROUND[9].position.y = -237;
						g_BACKROUND[9].position.x = 480-237+20;
					}
					g_BACKROUND[9].closeness = 20;
					g_BACKROUND[9].loaded = yes;
					g_BACKROUND[9].moved = no;
					g_BACKROUND[9].condition = alive;
				}
				if (g_PLAYER.mission == 8 && g_BACKROUND[9].condition == alive && x == 0)
				{
					g_BACKROUND[9].moved = yes;
					g_BACKROUND[9].position.y += 1;
				}
				//pink nebula
				if (g_PLAYER.mission == 8 && g_BACKROUND[0].condition != dead && x == 0 && g_time == 1025)
				{
					
					g_BACKROUND[0].SIZEwidth = 292;
					g_BACKROUND[0].SIZEheight = 210
						;
					LoadSprite(&g_BACKROUND[0], "Blvl7b.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[0].hBitmapNormal = LoadABitmap("Blvl7b.bmp");
					g_BACKROUND[0].hBitmapNightVision = LoadABitmap("Blvl7bNV.bmp");
					g_BACKROUND[0].hBitmapThermalVision = LoadABitmap("Blvl7bTH.bmp");
						
					SetSpriteState(&g_BACKROUND[0], NORTH);
					if (g_BACKROUND[0].condition == dyingone)
					{
						g_BACKROUND[0].position.y = -210;
						g_BACKROUND[0].position.x = -20;
					}
					g_BACKROUND[0].closeness = 20;
					g_BACKROUND[0].loaded = yes;
					g_BACKROUND[0].moved = no;
					g_BACKROUND[0].condition = alive;
				}
				if (g_PLAYER.mission == 8 && g_BACKROUND[0].condition == alive && x == 0)
				{
					g_BACKROUND[0].moved = yes;
					g_BACKROUND[0].position.y += 1;
				}
				//you just realized lvl 7 was nv, so u can use lvl 7, 8,9 for lvl 9, need a warp thingy for black hole in lvl 11
				//metal planet
				if (g_PLAYER.mission == 9 && g_BACKROUND[1].condition != dead && x == 1 && g_time == -449)
				{
					
					g_BACKROUND[1].SIZEwidth = 313;
					g_BACKROUND[1].SIZEheight = 301
						;
					LoadSprite(&g_BACKROUND[1], "Blvl7.bmp", g_BACKROUND[1].SIZEwidth, g_BACKROUND[1].SIZEheight, PLAYER_FRAMES);
									
					g_BACKROUND[1].hBitmapNormal = LoadABitmap("Blvl7.bmp");
					g_BACKROUND[1].hBitmapNightVision = LoadABitmap("Blvl7NV.bmp");
					g_BACKROUND[1].hBitmapThermalVision = LoadABitmap("Blvl7TH.bmp");
					
					SetSpriteState(&g_BACKROUND[1], NORTH);
					if (g_BACKROUND[1].condition == dyingone)
					{
						g_BACKROUND[1].position.y = -g_BACKROUND[1].SIZEheight;
						g_BACKROUND[1].position.x = 480-300;
					}
					g_BACKROUND[1].closeness = 20;
					g_BACKROUND[1].loaded = yes;
					g_BACKROUND[1].moved = no;
					g_BACKROUND[1].condition = alive;
				}
				if (g_PLAYER.mission == 9 && g_BACKROUND[1].condition == alive && x == 0)
				{
					g_BACKROUND[1].moved = yes;
					g_BACKROUND[1].position.y += 1;
				}
				//orange planet
				if (g_PLAYER.mission == 9 && g_BACKROUND[2].condition != dead && x == 2 && g_time == 125)
				{
					
					g_BACKROUND[2].SIZEwidth = 300;
					g_BACKROUND[2].SIZEheight = 300
						;
					LoadSprite(&g_BACKROUND[2], "Blvl8.bmp", g_BACKROUND[2].SIZEwidth, g_BACKROUND[2].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[2].hBitmapNormal = LoadABitmap("Blvl8.bmp");
					g_BACKROUND[2].hBitmapNightVision = LoadABitmap("Blvl8NV.bmp");
					g_BACKROUND[2].hBitmapThermalVision = LoadABitmap("Blvl8TH.bmp");
							
					SetSpriteState(&g_BACKROUND[2], NORTH);
					if (g_BACKROUND[2].condition == dyingone)
					{
						g_BACKROUND[2].position.y = -g_BACKROUND[2].SIZEheight;
						g_BACKROUND[2].position.x = 50;
					}
					g_BACKROUND[2].closeness = 20;
					g_BACKROUND[2].loaded = yes;
					g_BACKROUND[2].moved = no;
					g_BACKROUND[2].condition = alive;
				}
				if (g_PLAYER.mission == 9 && g_BACKROUND[2].condition == alive && x == 0)
				{
					g_BACKROUND[2].moved = yes;
					g_BACKROUND[2].position.y += 1;
				}
				//green w/ blue rings
				if (g_PLAYER.mission == 9 && g_BACKROUND[3].condition != dead && x == 3 && g_time == 1000)
				{
					
					g_BACKROUND[3].SIZEwidth = 234;
					g_BACKROUND[3].SIZEheight = 220
						;
					LoadSprite(&g_BACKROUND[3], "Blvl9.bmp", g_BACKROUND[3].SIZEwidth, g_BACKROUND[3].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[3].hBitmapNormal = LoadABitmap("Blvl9.bmp");
					g_BACKROUND[3].hBitmapNightVision = LoadABitmap("Blvl9NV.bmp");
					g_BACKROUND[3].hBitmapThermalVision = LoadABitmap("Blvl9TH.bmp");
							
					SetSpriteState(&g_BACKROUND[3], NORTH);
					if (g_BACKROUND[3].condition == dyingone)
					{
						g_BACKROUND[3].position.y = -g_BACKROUND[3].SIZEheight;
						g_BACKROUND[3].position.x = -20;
					}
					g_BACKROUND[3].closeness = 20;
					g_BACKROUND[3].loaded = yes;
					g_BACKROUND[3].moved = no;
					g_BACKROUND[3].condition = alive;
				}
				if (g_PLAYER.mission == 9 && g_BACKROUND[3].condition == alive && x == 0)
				{
					g_BACKROUND[3].moved = yes;
					g_BACKROUND[3].position.y += 1;
				}
				//stars
				if (g_PLAYER.mission == 10 && g_BACKROUND[4].condition != dead && x == 4 && g_time == -449)
				{
					
					g_BACKROUND[4].SIZEwidth = 300;
					g_BACKROUND[4].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[4], "Blvl10.bmp", g_BACKROUND[4].SIZEwidth, g_BACKROUND[4].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[4].hBitmapNormal = LoadABitmap("Blvl10.bmp");
					g_BACKROUND[4].hBitmapNightVision = LoadABitmap("Blvl10NV.bmp");
					g_BACKROUND[4].hBitmapThermalVision = LoadABitmap("Blvl10TH.bmp");
							
					SetSpriteState(&g_BACKROUND[4], NORTH);
					if (g_BACKROUND[4].condition == dyingone)
					{
						g_BACKROUND[4].position.y = -g_BACKROUND[4].SIZEheight;
						g_BACKROUND[4].position.x = 480-340;
					}
					g_BACKROUND[4].closeness = 20;
					g_BACKROUND[4].loaded = yes;
					g_BACKROUND[4].moved = no;
					g_BACKROUND[4].condition = alive;
				}
				if (g_PLAYER.mission == 10 && g_BACKROUND[4].condition == alive && x == 0)
				{
					g_BACKROUND[4].moved = yes;
					g_BACKROUND[4].position.y += 1;
				}
				//blue rings
				if (g_PLAYER.mission == 10 && g_BACKROUND[5].condition != dead && x == 4 && g_time == 200)
				{
					
					g_BACKROUND[5].SIZEwidth = 194;
					g_BACKROUND[5].SIZEheight = 187;
					LoadSprite(&g_BACKROUND[5], "BDOODAD11.bmp", g_BACKROUND[5].SIZEwidth, g_BACKROUND[5].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[5].hBitmapNormal = LoadABitmap("BDOODAD11.bmp");
					g_BACKROUND[5].hBitmapNightVision = LoadABitmap("BDOODAD11NV.bmp");
					g_BACKROUND[5].hBitmapThermalVision = LoadABitmap("BDOODAD11TH.bmp");
							
					SetSpriteState(&g_BACKROUND[5], NORTH);
					if (g_BACKROUND[5].condition == dyingone)
					{
						g_BACKROUND[5].position.y = -g_BACKROUND[5].SIZEheight;
						g_BACKROUND[5].position.x = 100;
					}
					g_BACKROUND[5].closeness = 20;
					g_BACKROUND[5].loaded = yes;
					g_BACKROUND[5].moved = no;
					g_BACKROUND[5].condition = alive;
				}
				if (g_PLAYER.mission == 10 && g_BACKROUND[5].condition == alive && x == 0)
				{
					g_BACKROUND[5].moved = yes;
					g_BACKROUND[5].position.y += 1;
				}
				//grren and purp
				if (g_PLAYER.mission == 10 && g_BACKROUND[6].condition != dead && x == 5 && g_time == 1000)
				{
					
					g_BACKROUND[6].SIZEwidth = 200;
					g_BACKROUND[6].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[6], "BDOODAD12.bmp", g_BACKROUND[6].SIZEwidth, g_BACKROUND[6].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[6].hBitmapNormal = LoadABitmap("BDOODAD12.bmp");
					g_BACKROUND[6].hBitmapNightVision = LoadABitmap("BDOODAD12NV.bmp");
					g_BACKROUND[6].hBitmapThermalVision = LoadABitmap("BDOODAD12TH.bmp");
							
					SetSpriteState(&g_BACKROUND[6], NORTH);
					if (g_BACKROUND[6].condition == dyingone)
					{
						g_BACKROUND[6].position.y = -g_BACKROUND[6].SIZEheight;
						g_BACKROUND[6].position.x = -40;
					}
					g_BACKROUND[6].closeness = 20;
					g_BACKROUND[6].loaded = yes;
					g_BACKROUND[6].moved = no;
					g_BACKROUND[6].condition = alive;
				}
				if (g_PLAYER.mission == 10 && g_BACKROUND[6].condition == alive && x == 0)
				{
					g_BACKROUND[6].moved = yes;
					g_BACKROUND[6].position.y += 1;
				}
				
				//blood cloud
				if (g_PLAYER.mission == 11 && g_BACKROUND[7].condition != dead && x == 7 && g_time == -400)
				{
					
					g_BACKROUND[7].SIZEwidth = 385;
					g_BACKROUND[7].SIZEheight = 355;
					LoadSprite(&g_BACKROUND[7], "Blvl11.bmp", g_BACKROUND[7].SIZEwidth, g_BACKROUND[7].SIZEheight, PLAYER_FRAMES);
							
					g_BACKROUND[7].hBitmapNormal = LoadABitmap("Blvl11.bmp");
					g_BACKROUND[7].hBitmapNightVision = LoadABitmap("Blvl11NV.bmp");
					g_BACKROUND[7].hBitmapThermalVision = LoadABitmap("Blvl11TH.bmp");
							
					SetSpriteState(&g_BACKROUND[7], NORTH);
					if (g_BACKROUND[7].condition == dyingone)
					{
						g_BACKROUND[7].position.y = -g_BACKROUND[7].SIZEheight;
						g_BACKROUND[7].position.x = 480-200;
					}
					g_BACKROUND[7].closeness = 20;
					g_BACKROUND[7].loaded = yes;
					g_BACKROUND[7].moved = no;
					g_BACKROUND[7].condition = alive;
				}
				if (g_PLAYER.mission == 11 && g_BACKROUND[7].condition == alive && x == 0)
				{
					g_BACKROUND[7].moved = yes;
					g_BACKROUND[7].position.y += 1;
				}
				//blackhole
				if (g_PLAYER.mission == 11 && g_BACKROUND[8].condition != dead && x == 8 && g_time == 125)
				{
					
					g_BACKROUND[8].SIZEwidth = 305;
					g_BACKROUND[8].SIZEheight = 295;
					LoadSprite(&g_BACKROUND[8], "BLACKHOLE.bmp", g_BACKROUND[8].SIZEwidth, g_BACKROUND[8].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[8].hBitmapNormal = LoadABitmap("BLACKHOLE.bmp");
					g_BACKROUND[8].hBitmapNightVision = LoadABitmap("BLACKHOLENV.bmp");
					g_BACKROUND[8].hBitmapThermalVision = LoadABitmap("BLACKHOLETH.bmp");
						
					SetSpriteState(&g_BACKROUND[8], NORTH);
					if (g_BACKROUND[8].condition == dyingone)
					{
						g_BACKROUND[8].position.y = -g_BACKROUND[8].SIZEheight;
						g_BACKROUND[8].position.x = 100;
					}
					g_BACKROUND[8].closeness = 20;
					g_BACKROUND[8].loaded = yes;
					g_BACKROUND[8].moved = no;
					g_BACKROUND[8].condition = alive;
				}
				if (g_PLAYER.mission == 11 && g_BACKROUND[8].condition == alive && x == 0)
				{
					g_BACKROUND[8].moved = yes;
					g_BACKROUND[8].position.y += 1;
				}
				//warp
				if (g_PLAYER.mission == 11 && g_BACKROUND[9].condition != dead && x == 9 && g_time == 1000)
				{
					
					g_BACKROUND[9].SIZEwidth = 480;
					g_BACKROUND[9].SIZEheight = 200;
					LoadSprite(&g_BACKROUND[9], "WARP.bmp", g_BACKROUND[9].SIZEwidth, g_BACKROUND[9].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[9].hBitmapNormal = LoadABitmap("WARP.bmp");
					g_BACKROUND[9].hBitmapNightVision = LoadABitmap("WARPNV.bmp");
					g_BACKROUND[9].hBitmapThermalVision = LoadABitmap("WARPTH.bmp");
						
					SetSpriteState(&g_BACKROUND[9], NORTH);
					if (g_BACKROUND[9].condition == dyingone)
					{
						g_BACKROUND[9].position.y = -g_BACKROUND[9].SIZEheight;
						g_BACKROUND[9].position.x = 0;
					}
					g_BACKROUND[9].closeness = 20;
					g_BACKROUND[9].loaded = yes;
					g_BACKROUND[9].moved = no;
					g_BACKROUND[9].condition = alive;
				}
				if (g_PLAYER.mission == 11 && g_BACKROUND[9].condition == alive && x == 0)
				{
					g_BACKROUND[9].moved = yes;
					g_BACKROUND[9].position.y += 10;
				}
				//moon
				if (g_PLAYER.mission == 12 && g_BACKROUND[0].condition != dead && x == 9 && g_time == 125)
				{
					
					g_BACKROUND[0].SIZEwidth = 300;
					g_BACKROUND[0].SIZEheight = 300;
					LoadSprite(&g_BACKROUND[0], "blvl12b.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[0].hBitmapNormal = LoadABitmap("blvl12b.bmp");
					g_BACKROUND[0].hBitmapNightVision = LoadABitmap("blvl12bNV.bmp");
					g_BACKROUND[0].hBitmapThermalVision = LoadABitmap("blvl12bTH.bmp");
						
					SetSpriteState(&g_BACKROUND[0], NORTH);
					if (g_BACKROUND[0].condition == dyingone)
					{
						g_BACKROUND[0].position.y = -g_BACKROUND[0].SIZEheight;
						g_BACKROUND[0].position.x = 480-250;
					}
					g_BACKROUND[0].closeness = 20;
					g_BACKROUND[0].loaded = yes;
					g_BACKROUND[0].moved = no;
					g_BACKROUND[0].condition = alive;
				}
				if (g_PLAYER.mission == 12 && g_BACKROUND[0].condition == alive && x == 0)
				{
					g_BACKROUND[0].moved = yes;
					g_BACKROUND[0].position.y += 1;
				}
				//earth
				if (g_PLAYER.mission == 12 && g_BACKROUND[1].condition != dead && x == 9 && g_time == 1000)
				{
					
					g_BACKROUND[1].SIZEwidth = 220;
					g_BACKROUND[1].SIZEheight = 220;
					LoadSprite(&g_BACKROUND[1], "blvl12.bmp", g_BACKROUND[1].SIZEwidth, g_BACKROUND[1].SIZEheight, PLAYER_FRAMES);
								
					g_BACKROUND[1].hBitmapNormal = LoadABitmap("blvl12.bmp");
					g_BACKROUND[1].hBitmapNightVision = LoadABitmap("blvl12NV.bmp");
					g_BACKROUND[1].hBitmapThermalVision = LoadABitmap("blvl12TH.bmp");
						
					SetSpriteState(&g_BACKROUND[1], NORTH);
					if (g_BACKROUND[1].condition == dyingone)
					{
						g_BACKROUND[1].position.y = -g_BACKROUND[1].SIZEheight;
						g_BACKROUND[1].position.x = 100;
					}
					g_BACKROUND[1].closeness = 20;
					g_BACKROUND[1].loaded = yes;
					g_BACKROUND[1].moved = no;
					g_BACKROUND[1].condition = alive;
				}
				if (g_PLAYER.mission == 12 && g_BACKROUND[1].condition == alive && x == 0)
				{
					g_BACKROUND[1].moved = yes;
					g_BACKROUND[1].position.y += 1;
				}
				*/

			}
		}

			SwapBackBuffer(&g_Buffer, FALSE);

  
			//particle & start movement
			for (x = 0; x < max_level_tiles; x++)
			{
				g_LEVEL[x].position.y += levelspeed / g_LEVEL[x].closeness;

				update_enemy_laser(x); //in enemy.h
				update_radar(x);

				//if particle or start is off screen random place about where player can see, so it can come again
				//will make "scrolling" effect
				if (g_LEVEL[x].position.y > 480)
				{
					g_LEVEL[x].position.y = rand1.RandInt(-16,-512);
					g_LEVEL[x].position.x = rand1.RandInt(0,480);
				}

				//make sure all level states are in the first 32 pixels

				SetSpriteState(&g_LEVEL[x], 0);

				//INIT FOR LASERS! dont ask why i put this here, but i did...it really shouldnt be here, but it
				//works nonetheless
				if (init == 0 && x < lasermax)
				{
					//set damages and speed, sprite state is the first
					g_LASER[x].damage = 4;
					g_LASER[x].condition = dead;
					g_LASER[x].position.x = offscreen;
					g_LASER[x].position.y = offscreen;
					SetSpriteState(&g_LASER[x], 0);

					g_MGUN[x].damage = 1.5;
					g_MGUN[x].condition = dead;
					g_MGUN[x].position.x = offscreen;
					g_MGUN[x].position.y = offscreen;
					SetSpriteState(&g_MGUN[x], 0);

					g_PULSE[x].damage = 2;
					g_PULSE[x].condition = dead;
					g_PULSE[x].position.x = offscreen;
					g_PULSE[x].position.y = offscreen;
					SetSpriteState(&g_PULSE[x], 0);


					g_FLAME[x].damage = 4;
					g_FLAME[x].condition = dead;
					g_FLAME[x].position.x = offscreen;
					g_FLAME[x].position.y = offscreen;
					SetSpriteState(&g_FLAME[x], 0);

					g_DLASER[x].damage = 4;
					g_DLASER[x].condition = dead;
					g_DLASER[x].position.x = offscreen;
					g_DLASER[x].position.y = offscreen;
					SetSpriteState(&g_DLASER[x], 0);

					g_SLASER[x].damage = 4;
					g_SLASER[x].condition = dead;
					g_SLASER[x].position.x = offscreen;
					g_SLASER[x].position.y = offscreen;
					SetSpriteState(&g_SLASER[x], 0);

					g_MISSILE[x].damage = 1;
					g_MISSILE[x].condition = dead;
					g_MISSILE[x].position.x = offscreen;
					g_MISSILE[x].position.y = offscreen;
					SetSpriteState(&g_MISSILE[x], 0);

					g_CHARGE[x].damage = 16;
					g_CHARGE[x].condition = dead;
					g_CHARGE[x].position.x = offscreen;
					g_CHARGE[x].position.y = offscreen;
					SetSpriteState(&g_CHARGE[x], 0);

					g_ALLYSHOT[x].damage = 2;
					g_ALLYSHOT[x].condition = dead;
					g_ALLYSHOT[x].position.x = offscreen;
					g_ALLYSHOT[x].position.y = offscreen;
					SetSpriteState(&g_ALLYSHOT[x], 0);

					g_POWERUP[x].condition = dead;
					g_POWERUP[x].position.x = offscreen;
					g_POWERUP[x].position.y = offscreen;
				}
			}

			update_allys();//update ally health bar

			for (x = 0; x < maxally; x++)
			{
				g_ALLYBAR[x].position.y = g_ALLY[x].position.y + 34;
				g_ALLYBAR[x].position.x = g_ALLY[x].position.x;

				//you got me with what this does
				if (g_ALLY[x].formation_type == breakformation)
				{
					g_ALLY[x].defend_formation_hold++;
				}
			}
		init = 1;

		sprite_collisions();

			//animate nuke

		if (g_NUKE.condition == dyingone)
		{
			SetSpriteState(&g_NUKE, 1);
			g_NUKE.condition = alive;
		}
		else if (g_NUKE.condition == alive)
		{
			SetSpriteState(&g_NUKE, 2);
			g_NUKE.condition = dyingtwo;
		}
		else if (g_NUKE.condition == dyingtwo)
		{
			g_NUKE.position.y = -900;
			g_NUKE.position.x = -900;
			g_NUKE.condition = dead;
		}
		
		//@HEY@ STUFF NEEDS TO BE DELETED IN HERE!!!//!//fix
		if (g_PLAYER.condition == alive)
		{
			player_controls();
		}

		for (z = 0; z < lasermax; z++)
		{
			for (x = 0; x < max_level_tiles; x++)
			{
		 		if ( g_PULSE[z].condition != dead && g_ENEMY[x].condition == alive &&
					g_PULSE[z].position.y +32>= g_ENEMY[x].position.y 
					&& g_PULSE[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight 
					&& g_PULSE[z].position.x +32>= g_ENEMY[x].position.x 
					&& g_PULSE[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
				{
					for (int gh = z + 1; gh < lasermax; gh++)
					{
						g_PULSE[gh].condition = dead;
						g_PULSE[gh].position.x = -1000;
						g_PULSE[gh].position.y = -1000;
					}
				}
			}
		}

		
			
			//set healthbar and ammo bar positions
			g_HEALTHBAR.position.y = g_PLAYER.position.y + 32;
			g_HEALTHBAR.position.x = g_PLAYER.position.x;
			g_AMMOBAR.position.y = g_PLAYER.position.y + 34;
			g_AMMOBAR.position.x = g_PLAYER.position.x;
			if (g_PLAYER.headlight == yes)
			{
				g_HEADLIGHT.position.y = g_PLAYER.position.y - 150;
				g_HEADLIGHT.position.x = g_PLAYER.position.x;
			}
			//update screen w/ new enemies and powerups
			mission();

			//set music
			
				
			update_loader();
//FM			if (g_PLAYER.mission == 2 && g_time <= 3 && MUSIC_PLAYING != 1)
//FM			{		
//FM				display_loading();
//FM				if(!music.Init("level1.mp3"))			
//FM				exit(1);
///FM/FM				music.PlaySong();
//FM				MUSIC_PLAYING = 1;
				
//FM			}
//FM			if (g_PLAYER.mission == 5 && g_time <= 3 && MUSIC_PLAYING != 1)
//FM			{					
//FM				display_loading();
//FM				if(!music.Init("level2.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
//FM				MUSIC_PLAYING = 1;
//FM			}
//FM			if (g_PLAYER.mission == 8 && g_time <= 3 && MUSIC_PLAYING != 1)
//FM			{		
//FM				display_loading();
//FM				if(!music.Init("level3.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
//FM				MUSIC_PLAYING = 1;
//FM			}

//FM			if (g_PLAYER.mission == 10 && g_time <= 3 && MUSIC_PLAYING != 1)
//FM			{			
//FM				display_loading();
//FM				if(!music.Init("level4.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
//FM				MUSIC_PLAYING = 1;
//FM			}
//FM			if (g_PLAYER.mission == 12 && g_time <= 3 && MUSIC_PLAYING != 1)
//FM			{	
//FM				display_loading();		
//FM				if(!music.Init("level5.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
//FM				MUSIC_PLAYING = 1;
//FM			}

			//set enemy types to correct sprite

			set_enemy_type();
			set_vision_type();
			use_battery();

			//add to time...this is ugly
			WAIT++;
			WAIT2++;
			if (NVWAIT <= 20)
			{
				NVWAIT++;
			}
			if (g_PLAYER.points >= 0)
			{
				int tmp = 0;
				int tmp2 = g_PLAYER.points;
				if (g_PLAYER.points >= 100000)
				{
					while (tmp2 >= 100000)
					{
						tmp2 -= 100000;
						tmp++;
					}
					g_SCORE[0].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 10;
				}
				tmp = 0;
				if (g_PLAYER.points >= 10000)
				{
					while (tmp2 >= 10000)
					{
						tmp2 -= 10000;
						tmp++;
					}
					g_SCORE[1].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 10;
				}
				tmp = 0;
				if (g_PLAYER.points >= 1000)
				{
					while (tmp2 >= 1000)
					{
						tmp2 -= 1000;
						tmp++;
					}
					g_SCORE[2].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 10;
				}
				tmp = 0;
				if (g_PLAYER.points >= 100)
				{
					while (tmp2 >= 100)
					{
						tmp2 -= 100;
						tmp++;
					}
					g_SCORE[3].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 10;
				}
				tmp = 0;
				if (g_PLAYER.points >= 10)
				{
					while (tmp2 >= 10)
					{
						tmp2 -= 10;
						tmp++;
					}
					g_SCORE[4].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 10;
				}
				tmp = 0;
				if (g_PLAYER.points >= 1)
				{
					while (tmp2 >= 1)
					{
						tmp2 -= 1;
						tmp++;
					}
					g_SCORE[5].condition = tmp;
				}
				else
				{
					g_SCORE[0].condition = 0;
				}
			}
			g_time++;
    }


	// Free all the data and set everything back to normal
	DeInit();

	// Unregister t            he window class with the operating system
	UnregisterClass("Window Class",hInstance);
    
	// Quit the program
	return msg.wParam ;										
}

// Here is the WndProc that handles all the messages		
													
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//i somewhat understand this
		if (iMsg == WM_CREATE)
		{	
			Init(hwnd);										
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{	
			PostQuitMessage(0);
		}

		if(iMsg == WM_DESTROY)
		{
			PostQuitMessage(0);									
		}
										

	// Process/handle the default messages

	return DefWindowProc (hwnd, iMsg, wParam, lParam);													
}

void Init(HWND hwnd)
{	
			//im pretty sure i got this...must add these 4 lines to add in a sprite.
			//!SPRITE
			g_WEAPONHUD.SIZEheight = 13;
			g_WEAPONHUD.SIZEwidth = 101;
			g_WEAPONHUD.SIZEwidth = 101;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_WEAPONHUD, "weaponHUD.bmp", g_WEAPONHUD.SIZEwidth, g_WEAPONHUD.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_WEAPONHUD, 0, 0);
			SetSpriteSpeed(&g_WEAPONHUD, TILE_WIDTH, TILE_HEIGHT);

			g_WEAPONHUD2.SIZEheight = 13;
			g_WEAPONHUD2.SIZEwidth = 76;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_WEAPONHUD2, "weapon2HUD.bmp", g_WEAPONHUD2.SIZEwidth, g_WEAPONHUD2.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_WEAPONHUD2, 0, 0);
			SetSpriteSpeed(&g_WEAPONHUD2, TILE_WIDTH, TILE_HEIGHT);




			g_HUNTER.SIZEheight = 32;
			g_HUNTER.SIZEwidth = 32;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HUNTER, "Rplayer.bmp", g_HUNTER.SIZEwidth, g_HUNTER.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_HUNTER, 0, 0);
			SetSpriteSpeed(&g_HUNTER, TILE_WIDTH, TILE_HEIGHT);

			g_PLAYER.SIZEheight = 32;
			g_PLAYER.SIZEwidth = 32;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_PLAYER, "Rplayer.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_PLAYER, 0, 0);
			SetSpriteSpeed(&g_PLAYER, TILE_WIDTH, TILE_HEIGHT);

			g_NUKEBAR.SIZEheight = 47;
			g_NUKEBAR.SIZEwidth = 18;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_NUKEBAR, "nukebar.bmp", g_NUKEBAR.SIZEwidth, g_NUKEBAR.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_NUKEBAR, 403, 464);
			SetSpriteSpeed(&g_NUKEBAR, TILE_WIDTH, TILE_HEIGHT);

			g_CHARGEBAR.SIZEheight = 52;
			g_CHARGEBAR.SIZEwidth = 26;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_CHARGEBAR, "chargebar.bmp", g_CHARGEBAR.SIZEwidth, g_CHARGEBAR.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_CHARGEBAR, 72, 460);
			SetSpriteSpeed(&g_CHARGEBAR, TILE_WIDTH, TILE_HEIGHT);

			g_BATTERY.SIZEheight = 20;
			g_BATTERY.SIZEwidth = 10;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_BATTERY, "Battery.bmp", g_BATTERY.SIZEwidth, g_BATTERY.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_BATTERY, 0, 0);
			SetSpriteSpeed(&g_BATTERY, TILE_WIDTH, TILE_HEIGHT);

			g_ESCORT.SIZEheight = 300;
			g_ESCORT.SIZEwidth = 64;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_ESCORT, "escort.bmp", g_ESCORT.SIZEwidth , g_ESCORT.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_ESCORT, 0, 0);
			SetSpriteSpeed(&g_ESCORT, TILE_WIDTH, TILE_HEIGHT);

			g_MO.SIZEheight = 54;
			g_MO.SIZEwidth = 299;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_MO, "HUDMO.bmp", g_MO.SIZEwidth , g_MO.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_MO, 0, 0);
			SetSpriteSpeed(&g_MO, TILE_WIDTH, TILE_HEIGHT);

			g_HEADLIGHT.SIZEheight = 160;
			g_HEADLIGHT.SIZEwidth = 34;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HEADLIGHT, "headlight.bmp", g_HEADLIGHT.SIZEwidth , g_HEADLIGHT.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_HEADLIGHT, 0, 0);
			SetSpriteSpeed(&g_HEADLIGHT, TILE_WIDTH, TILE_HEIGHT);

			g_switcher.SIZEheight = 32;
			g_switcher.SIZEwidth = 32;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_switcher, "None.bmp", g_switcher.SIZEwidth, g_switcher.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_switcher, 0, 0);
			SetSpriteSpeed(&g_switcher, TILE_WIDTH, TILE_HEIGHT);

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_NUKE, "nukeexplosion.bmp", 480, 600, PLAYER_FRAMES);
			SetSpritePosition(&g_NUKE, 0, 0);
			SetSpriteSpeed(&g_NUKE, TILE_WIDTH, TILE_HEIGHT);

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HEALTHBAR, "healthbar.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_HEALTHBAR, 0, 0);
			SetSpriteSpeed(&g_HEALTHBAR, TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[0].SIZEwidth = 480;
			g_SCREEN[0].SIZEheight = 544;
			LoadSprite(&g_SCREEN[0], "ScreenTitle.bmp", g_SCREEN[0].SIZEwidth, g_SCREEN[0].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[0], 0, 0);
			SetSpriteSpeed(&g_SCREEN[0], TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[1].SIZEwidth = 480;
			g_SCREEN[1].SIZEheight  = 544;
			LoadSprite(&g_SCREEN[1], "ScreenVesselSelection.bmp", g_SCREEN[1].SIZEwidth, g_SCREEN[1].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[1], 0, 0);
			SetSpriteSpeed(&g_SCREEN[1], TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[2].SIZEwidth = 480;
			g_SCREEN[2].SIZEheight  = 544;
			LoadSprite(&g_SCREEN[2], "ScreenDifficultySelection.bmp", g_SCREEN[2].SIZEwidth, g_SCREEN[2].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[2], 0, 0);
			SetSpriteSpeed(&g_SCREEN[2], TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[3].SIZEwidth = 480;
			g_SCREEN[3].SIZEheight  = 544;
			LoadSprite(&g_SCREEN[3], "ScreenWeaponSelection.bmp", g_SCREEN[3].SIZEwidth, g_SCREEN[3].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[3], 0, 0);
			SetSpriteSpeed(&g_SCREEN[3], TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[4].SIZEwidth = 32;
			g_SCREEN[4].SIZEheight  = 32;
			LoadSprite(&g_SCREEN[4], "ScreenCursor.bmp", g_SCREEN[4].SIZEwidth, g_SCREEN[4].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[4], 0, 0);
			SetSpriteSpeed(&g_SCREEN[4], TILE_WIDTH, TILE_HEIGHT);

			g_SCREEN[5].SIZEwidth = 960;
			g_SCREEN[5].SIZEheight  = 1088;
			LoadSprite(&g_SCREEN[5], "None.bmp", g_SCREEN[5].SIZEwidth, g_SCREEN[5].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_SCREEN[5], 0, 0);
			SetSpriteSpeed(&g_SCREEN[5], TILE_WIDTH, TILE_HEIGHT);
			for (int x = 0; x < 4; x++)
			{
				g_ENDING[x].SIZEwidth = 1;
				g_ENDING[x].SIZEheight  = 1;
				LoadSprite(&g_ENDING[x], "Rplayer.bmp", g_ENDING[x].SIZEwidth, g_ENDING[x].SIZEheight, PLAYER_FRAMES);
				SetSpritePosition(&g_ENDING[x], 0, 0);
				SetSpriteSpeed(&g_ENDING[x], TILE_WIDTH, TILE_HEIGHT);
			}
			for (x = 6; x < max_levels; x++)
			{
				g_SCREEN[x].SIZEwidth = 32;
				g_SCREEN[x].SIZEheight  = 32;
				LoadSprite(&g_SCREEN[x], "ScreenLocked.bmp", g_SCREEN[x].SIZEwidth, g_SCREEN[x].SIZEheight, PLAYER_FRAMES);
				SetSpritePosition(&g_SCREEN[x], 0, 0);
				SetSpriteSpeed(&g_SCREEN[x], TILE_WIDTH, TILE_HEIGHT);
			}
			for (x = 0; x < max_digits; x++)
			{
				g_SCORE[x].SIZEheight = 19;
				g_SCORE[x].SIZEwidth = 8;
				CreateDoubleBuffering(&g_Buffer, hwnd);
				LoadSprite(&g_SCORE[x], "numbers.bmp", g_SCORE[x].SIZEwidth, g_SCORE[x].SIZEheight, PLAYER_FRAMES);
				SetSpritePosition(&g_SCORE[x], 0, 0);
				SetSpriteSpeed(&g_SCORE[x], TILE_WIDTH, TILE_HEIGHT);
			}
			for (x = 0; x < max_particles; x++)
			{
				g_PARTICLE[x].SIZEwidth = 3;
				g_PARTICLE[x].SIZEheight  = 3;
				LoadSprite(&g_PARTICLE[x], "particle.bmp", g_PARTICLE[x].SIZEwidth, g_PARTICLE[x].SIZEheight, PLAYER_FRAMES);
				SetSpritePosition(&g_PARTICLE[x], 0, 0);
				SetSpriteSpeed(&g_PARTICLE[x], TILE_WIDTH, TILE_HEIGHT);
			}

			for (x = 0; x < max_explosions; x++)
			{
				if (x % 3 == 0)
				{
					g_EXPLOSION[x].SIZEwidth = 47;
					g_EXPLOSION[x].SIZEheight  = 42;
					LoadSprite(&g_EXPLOSION[x], "Exp1.bmp", g_EXPLOSION[x].SIZEwidth, g_EXPLOSION[x].SIZEheight, PLAYER_FRAMES);
					g_EXPLOSION[x].hBitmapNormal = LoadABitmap("Exp1.bmp");
					g_EXPLOSION[x].hBitmapNightVision = LoadABitmap("Exp1NV.bmp");
					g_EXPLOSION[x].hBitmapThermalVision = LoadABitmap("Exp1TH.bmp");
				}
				if (x % 3 == 1)
				{
					g_EXPLOSION[x].SIZEwidth = 49;
					g_EXPLOSION[x].SIZEheight  = 46;
					LoadSprite(&g_EXPLOSION[x], "Exp2.bmp", g_EXPLOSION[x].SIZEwidth, g_EXPLOSION[x].SIZEheight, PLAYER_FRAMES);
					g_EXPLOSION[x].hBitmapNormal = LoadABitmap("Exp2.bmp");
					g_EXPLOSION[x].hBitmapNightVision = LoadABitmap("Exp2NV.bmp");
					g_EXPLOSION[x].hBitmapThermalVision = LoadABitmap("Exp2TH.bmp");
				}
				if (x % 3 == 2)
				{
					g_EXPLOSION[x].SIZEwidth = 39;
					g_EXPLOSION[x].SIZEheight  = 42;
					LoadSprite(&g_EXPLOSION[x], "Exp3.bmp", g_EXPLOSION[x].SIZEwidth, g_EXPLOSION[x].SIZEheight, PLAYER_FRAMES);
					g_EXPLOSION[x].hBitmapNormal = LoadABitmap("Exp3.bmp");
					g_EXPLOSION[x].hBitmapNightVision = LoadABitmap("Exp3NV.bmp");
					g_EXPLOSION[x].hBitmapThermalVision = LoadABitmap("Exp3TH.bmp");
				}
				SetSpritePosition(&g_EXPLOSION[x], 0, 0);
				SetSpriteSpeed(&g_EXPLOSION[x], TILE_WIDTH, TILE_HEIGHT);
			}

			//shaun you stupid asshole stop coding your damn comments in ;)
			//btw, i gotta fix your damg code, so take this...HAHA!
			////////////////Rob////
			g_LOADER.SIZEheight = 20;
			g_LOADER.SIZEwidth = 124;
			////////////////Rob////
			////////////////Shaun////
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_LOADER, "loader.bmp", g_LOADER.SIZEwidth, g_LOADER.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_LOADER, 0, 0);
			SetSpriteSpeed(&g_LOADER, TILE_WIDTH, TILE_HEIGHT);
			////////////////Shaun////

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_AMMOBAR, "ammobar.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_AMMOBAR, 0, 0);
			SetSpriteSpeed(&g_AMMOBAR, TILE_WIDTH, TILE_HEIGHT);

			g_RADAR.SIZEheight = 48;
			g_RADAR.SIZEwidth = 48;

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_RADAR, "radar.bmp", g_RADAR.SIZEwidth, g_RADAR.SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_RADAR, 0, 0);
			SetSpriteSpeed(&g_RADAR, TILE_WIDTH, TILE_HEIGHT);

			g_HUD.SIZEheight = 64;//for custom sized sprites...default is 32 by 32
			g_HUD.SIZEwidth = 480;

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HUD, "HUD.bmp", g_HUD.SIZEwidth, g_HUD.SIZEheight = 64, PLAYER_FRAMES);
			SetSpritePosition(&g_HUD, 0, 0);
			SetSpriteSpeed(&g_HUD, TILE_WIDTH, TILE_HEIGHT);

	for (x = 0; x < max_level_tiles + 1; x++)
	{
		if (x < maxally)
		{
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_ALLY[x], "PPaladin.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_ALLY[x], 0, 0);
			SetSpriteSpeed(&g_ALLY[x], TILE_WIDTH, TILE_HEIGHT);

			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_ALLYBAR[x], "healthbar.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_ALLYBAR[x], 0, 0);
			SetSpriteSpeed(&g_ALLYBAR[x], TILE_WIDTH, TILE_HEIGHT);
		}
		if (x < maxally + 1)
		{
			g_HEAD[x].SIZEheight = 48;
			g_HEAD[x].SIZEwidth = 48;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HEAD[x], "playerHEAD.bmp", g_HEAD[x].SIZEwidth, g_HEAD[x].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_HEAD[x], 0, 0);
			SetSpriteSpeed(&g_HEAD[x], TILE_WIDTH, TILE_HEIGHT);

			g_HEADBAR[x].SIZEheight = 44;
			g_HEADBAR[x].SIZEwidth = 12;
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_HEADBAR[x], "HEADBAR.bmp", g_HEADBAR[x].SIZEwidth, g_HEADBAR[x].SIZEheight, PLAYER_FRAMES);
			SetSpritePosition(&g_HEADBAR[x], 0, 0);
			SetSpriteSpeed(&g_HEADBAR[x], TILE_WIDTH, TILE_HEIGHT);
		}

		if (x < lasermax)
		{
				CreateDoubleBuffering(&g_Buffer, hwnd);
				LoadSprite(&g_LASER[x], "Hlaser.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_LASER[x], 0, 0);
				SetSpriteSpeed(&g_LASER[x], TILE_WIDTH, TILE_HEIGHT);

				g_LASER[x].hBitmapNormal = LoadABitmap("Hlaser.bmp");
				g_LASER[x].hBitmapNightVision = LoadABitmap("HlaserNV.bmp");
				g_LASER[x].hBitmapThermalVision = LoadABitmap("HlaserTH.bmp");

				LoadSprite(&g_MGUN[x], "Hmgun.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_MGUN[x], 0, 0);
				SetSpriteSpeed(&g_MGUN[x], TILE_WIDTH, TILE_HEIGHT);

				g_MGUN[x].hBitmapNormal = LoadABitmap("Hmgun.bmp");
				g_MGUN[x].hBitmapNightVision = LoadABitmap("HmgunNV.bmp");
				g_MGUN[x].hBitmapThermalVision = LoadABitmap("HmgunTH.bmp");

				LoadSprite(&g_PULSE[x], "Hpulse.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_PULSE[x], 0, 0);
				SetSpriteSpeed(&g_PULSE[x], TILE_WIDTH, TILE_HEIGHT);

				g_PULSE[x].hBitmapNormal = LoadABitmap("Hpulse.bmp");
				g_PULSE[x].hBitmapNightVision = LoadABitmap("HpulseNV.bmp");
				g_PULSE[x].hBitmapThermalVision = LoadABitmap("HpulseTH.bmp");

				LoadSprite(&g_FLAME[x], "Hflame.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_FLAME[x], 0, 0);
				SetSpriteSpeed(&g_FLAME[x], TILE_WIDTH, TILE_HEIGHT);

				g_FLAME[x].hBitmapNormal = LoadABitmap("Hflame.bmp");
				g_FLAME[x].hBitmapNightVision = LoadABitmap("HflameNV.bmp");
				g_FLAME[x].hBitmapThermalVision = LoadABitmap("HflameTH.bmp");

				LoadSprite(&g_DLASER[x], "Hdiagonalshot.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_DLASER[x], 0, 0);
				SetSpriteSpeed(&g_DLASER[x], TILE_WIDTH, TILE_HEIGHT);

				g_DLASER[x].hBitmapNormal = LoadABitmap("Hdiagonalshot.bmp");
				g_DLASER[x].hBitmapNightVision = LoadABitmap("HdiagonalshotNV.bmp");
				g_DLASER[x].hBitmapThermalVision = LoadABitmap("HdiagonalshotTH.bmp");

				LoadSprite(&g_SLASER[x], "Hsideshot.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_SLASER[x], 0, 0);
				SetSpriteSpeed(&g_SLASER[x], TILE_WIDTH, TILE_HEIGHT);

				g_SLASER[x].hBitmapNormal = LoadABitmap("Hsideshot.bmp");
				g_SLASER[x].hBitmapNightVision = LoadABitmap("HsideshotNV.bmp");
				g_SLASER[x].hBitmapThermalVision = LoadABitmap("HsideshotTH.bmp");

				LoadSprite(&g_MISSILE[x], "Hmissile.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_MISSILE[x], 0, 0);
				SetSpriteSpeed(&g_MISSILE[x], TILE_WIDTH, TILE_HEIGHT);

				g_MISSILE[x].hBitmapNormal = LoadABitmap("Hmissile.bmp");
				g_MISSILE[x].hBitmapNightVision = LoadABitmap("HmissileNV.bmp");
				g_MISSILE[x].hBitmapThermalVision = LoadABitmap("HmissileTH.bmp");

				LoadSprite(&g_ALLYSHOT[x], "Hlaser.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_ALLYSHOT[x], 0, 0);
				SetSpriteSpeed(&g_ALLYSHOT[x], TILE_WIDTH, TILE_HEIGHT);

				g_ALLYSHOT[x].hBitmapNormal = LoadABitmap("Hlaser.bmp");
				g_ALLYSHOT[x].hBitmapNightVision = LoadABitmap("HlaserNV.bmp");
				g_ALLYSHOT[x].hBitmapThermalVision = LoadABitmap("HlaserTH.bmp");

				LoadSprite(&g_POWERUP[x], "powerup.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_POWERUP[x], 0, 0);
				SetSpriteSpeed(&g_POWERUP[x], TILE_WIDTH, TILE_HEIGHT);

				g_POWERUP[x].hBitmapNormal = LoadABitmap("powerup.bmp");
				g_POWERUP[x].hBitmapNightVision = LoadABitmap("powerupNV.bmp");
				g_POWERUP[x].hBitmapThermalVision = LoadABitmap("powerupTH.bmp");

				LoadSprite(&g_CHARGE[x], "Hcharge.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
				SetSpritePosition(&g_CHARGE[x], 0, 0);
				SetSpriteSpeed(&g_CHARGE[x], TILE_WIDTH, TILE_HEIGHT);

				g_CHARGE[x].hBitmapNormal = LoadABitmap("Hcharge.bmp");
				g_CHARGE[x].hBitmapNightVision = LoadABitmap("HchargeNV.bmp");
				g_CHARGE[x].hBitmapThermalVision = LoadABitmap("HchargeTH.bmp");
				
		}

		if (x < max_level_tiles)
		{
			LoadSprite(&g_SMOKE[x], "Smoke.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			g_SMOKE[x].hBitmapNormal = LoadABitmap("Smoke.bmp");
			g_SMOKE[x].hBitmapNightVision = LoadABitmap("SmokeNV.bmp");
			g_SMOKE[x].hBitmapThermalVision = LoadABitmap("SmokeTH.bmp");

			g_SPARK[x].SIZEwidth = 3;
			g_SPARK[x].SIZEheight = 3;
			LoadSprite(&g_SPARK[x], "spark.bmp", g_SPARK[x].SIZEwidth, g_SPARK[x].SIZEheight, PLAYER_FRAMES);

			g_SPARK[x].hBitmapNormal = LoadABitmap("spark.bmp");
			g_SPARK[x].hBitmapNightVision = LoadABitmap("sparkNV.bmp");
			g_SPARK[x].hBitmapThermalVision = LoadABitmap("sparkTH.bmp");

			LoadSprite(&g_ELASER[x], "Helaser.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			g_ELASER[x].SIZEheight = 32;
			g_ELASER[x].SIZEwidth = 32;
			g_ELASER[x].hBitmapNormal = LoadABitmap("Helaser.bmp");
			g_ELASER[x].hBitmapNightVision = LoadABitmap("HelaserNV.bmp");
			g_ELASER[x].hBitmapThermalVision = LoadABitmap("HelaserTH.bmp");

			g_LEVEL[x].closeness = 5;
			if (x >= 0 && x < 5)
			{
				g_LEVEL[x].SIZEheight = 5;
				g_LEVEL[x].SIZEwidth = 5;
				LoadSprite(&g_LEVEL[x], "star2.bmp", g_LEVEL[x].SIZEwidth, g_LEVEL[x].SIZEheight, PLAYER_FRAMES);
				g_LEVEL[x].closeness = 5;

				g_LEVEL[x].hBitmapNormal = LoadABitmap("star2.bmp");
				g_LEVEL[x].hBitmapNightVision = LoadABitmap("star2NV.bmp");
				g_LEVEL[x].hBitmapThermalVision = LoadABitmap("star2TH.bmp");
			}
			else if (x >= 5 && x < 10)
			{
				g_LEVEL[x].SIZEheight = 3;
				g_LEVEL[x].SIZEwidth = 3;
				LoadSprite(&g_LEVEL[x], "star1.bmp", g_LEVEL[x].SIZEwidth, g_LEVEL[x].SIZEheight, PLAYER_FRAMES);
				g_LEVEL[x].closeness = 4;

				g_LEVEL[x].hBitmapNormal = LoadABitmap("star1.bmp");
				g_LEVEL[x].hBitmapNightVision = LoadABitmap("star1NV.bmp");
				g_LEVEL[x].hBitmapThermalVision = LoadABitmap("star1TH.bmp");
			}
			else if (x >= 10 && x < 15)
			{
				g_LEVEL[x].SIZEheight = 3;
				g_LEVEL[x].SIZEwidth = 3;
				LoadSprite(&g_LEVEL[x], "meteor3.bmp", g_LEVEL[x].SIZEwidth, g_LEVEL[x].SIZEheight, PLAYER_FRAMES);
				g_LEVEL[x].closeness = 1;

				g_LEVEL[x].hBitmapNormal = LoadABitmap("meteor3.bmp");
				g_LEVEL[x].hBitmapNightVision = LoadABitmap("meteor3NV.bmp");
				g_LEVEL[x].hBitmapThermalVision = LoadABitmap("meteor3TH.bmp");
			}
			else if (x >= 15 && x < 20)
			{
				g_LEVEL[x].SIZEheight = 3;
				g_LEVEL[x].SIZEwidth = 3;
				LoadSprite(&g_LEVEL[x], "meteor2.bmp", g_LEVEL[x].SIZEwidth, g_LEVEL[x].SIZEheight, PLAYER_FRAMES);
				g_LEVEL[x].closeness = 2;

				g_LEVEL[x].hBitmapNormal = LoadABitmap("meteor2.bmp");
				g_LEVEL[x].hBitmapNightVision = LoadABitmap("meteor2NV.bmp");
				g_LEVEL[x].hBitmapThermalVision = LoadABitmap("meteor2TH.bmp");
			}
			else //if (x >= 20 && x < 25)
			{
				g_LEVEL[x].SIZEheight = 3;
				g_LEVEL[x].SIZEwidth = 3;
				LoadSprite(&g_LEVEL[x], "meteor.bmp", g_LEVEL[x].SIZEwidth, g_LEVEL[x].SIZEheight, PLAYER_FRAMES);
				g_LEVEL[x].closeness = 1;

				g_LEVEL[x].hBitmapNormal = LoadABitmap("meteor.bmp");
				g_LEVEL[x].hBitmapNightVision = LoadABitmap("meteorNV.bmp");
				g_LEVEL[x].hBitmapThermalVision = LoadABitmap("meteorTH.bmp");
			}
			SetSpritePosition(&g_LEVEL[x], 0, 0);
			SetSpriteSpeed(&g_LEVEL[x], TILE_WIDTH, TILE_HEIGHT);

			if (x < max_levels)
			{

					g_BACKROUND[x].SIZEwidth = 1;
					g_BACKROUND[x].SIZEheight = 1;
					LoadSprite(&g_BACKROUND[x], "None.bmp", g_BACKROUND[0].SIZEwidth, g_BACKROUND[0].SIZEheight, PLAYER_FRAMES);
					SetSpritePosition(&g_BACKROUND[0], 0, 0);
					SetSpriteSpeed(&g_BACKROUND[0], TILE_WIDTH, TILE_HEIGHT);	
			}
			g_ENEMY[x].SIZEheight = 32;
			g_ENEMY[x].SIZEwidth = 32;
			LoadSprite(&g_ENEMY[x], "Enemy.bmp", g_ENEMY[x].SIZEwidth, g_ENEMY[x].SIZEheight, PLAYER_FRAMES);
		}

		if (x == 0)
		{
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_RADARTARGET[0], "Rplayer.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_RADARTARGET[0], 0, 0);
			SetSpriteSpeed(&g_RADARTARGET[0], TILE_WIDTH, TILE_HEIGHT);
		}
		if (x != 0 && x < max_level_tiles + 1)
		{
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_RADARTARGET[x], "Renemy.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_RADARTARGET[x], 0, 0);
			SetSpriteSpeed(&g_RADARTARGET[x], TILE_WIDTH, TILE_HEIGHT);
		}
		if (x < maxally)
		{
			CreateDoubleBuffering(&g_Buffer, hwnd);
			LoadSprite(&g_RADARTARGET[max_level_tiles + 1 + x], "Rally.bmp", TILE_WIDTH, TILE_HEIGHT, PLAYER_FRAMES);
			SetSpritePosition(&g_RADARTARGET[max_level_tiles + 1 + x], 0, 0);
			SetSpriteSpeed(&g_RADARTARGET[max_level_tiles + 1 + x], TILE_WIDTH, TILE_HEIGHT);
		}
	}
	

	for(int y = 0; y < BOARD_HEIGHT; y++)
	{
		for(int x = 0; x < BOARD_WIDTH; x++)
		{
			switch(g_BoardArray[x + y * BOARD_WIDTH])
			{
				case SPACE:
					g_bmpTiles[x][y] = LoadABitmap("space.bmp");
					break;
			}
		}
	}

	ClearScreen(g_Buffer.hdcBack, g_Buffer.scrnRect, BLACK_BRUSH);	
	//done loading all sprites
}

void DeInit()
{

	//!SPRITE
	//this frees the sprite (i said that like i knew what it meant). i know you must have it.
	FreeSprite(&g_WEAPONHUD);
	FreeSprite(&g_WEAPONHUD2);
	FreeSprite(&g_HUNTER);
	FreeSprite(&g_PLAYER);
	FreeSprite(&g_ESCORT);
	FreeSprite(&g_MO);
	FreeSprite(&g_HEADLIGHT);
	FreeSprite(&g_BATTERY);
	FreeSprite(&g_CHARGEBAR);
	FreeSprite(&g_NUKEBAR);
	FreeSprite(&g_switcher);
	FreeSprite(&g_HEALTHBAR);
	FreeSprite(&g_AMMOBAR);
	FreeSprite(&g_LOADER);//teh l0@D3|7 |3@|7
	FreeSprite(&g_RADAR);
	FreeSprite(&g_HUD);
	FreeSprite(&g_NUKE);

	for (int z = 0; z < max_level_tiles + 1 + maxally; z++)
	{
		if (z < 4)
		{
			FreeSprite(&g_ENDING[z]);
		}
		if (z < max_digits)
		{
			FreeSprite(&g_SCORE[z]);
		}
		if (z < max_explosions)
		{
			FreeSprite(&g_EXPLOSION[z]);
		}
		if (z < max_particles)
		{
			FreeSprite(&g_PARTICLE[z]);
		}
		if (z < max_levels)
		{
			FreeSprite(&g_SCREEN[z]);
			FreeSprite(&g_BACKROUND[z]);
		}
		if (z < maxally)
		{
			FreeSprite(&g_ALLY[z]);
			FreeSprite(&g_ALLYBAR[z]);
		}
		if (z < maxally+1)
		{
			FreeSprite(&g_HEAD[z]);
			FreeSprite(&g_HEADBAR[z]);
		}
		if (z < lasermax)
		{
			FreeSprite(&g_LASER[z]);
			FreeSprite(&g_MGUN[z]);
			FreeSprite(&g_PULSE[z]);
			FreeSprite(&g_FLAME[z]);
			FreeSprite(&g_DLASER[z]);
			FreeSprite(&g_SLASER[z]);
			FreeSprite(&g_MISSILE[z]);
			FreeSprite(&g_ALLYSHOT[z]);
			FreeSprite(&g_POWERUP[z]);
			FreeSprite(&g_CHARGE[z]);
		}
		if (z < max_level_tiles)
		{
			FreeSprite(&g_SPARK[z]);
			FreeSprite(&g_SMOKE[z]);
			FreeSprite(&g_LEVEL[z]);
			FreeSprite(&g_ENEMY[z]);
			FreeSprite(&g_ELASER[z]);
		}

		FreeSprite(&g_RADARTARGET[z]);
	}

	// Go through and free all of our tiles
	for(int y = 0; y < BOARD_HEIGHT; y++)
	{
		for(int x = 0; x < BOARD_WIDTH; x++)
		{
			// Free the tile stored in this index
			DeleteObject(g_bmpTiles[x][y]);
		}
	}

	// Free the back buffer
	FreeBuffers(&g_Buffer);

	// Post the QUIT message to the window (0 = WM_QUIT)															
	PostQuitMessage(0);		
	
}

////////////////////////////////////////////////////////////////////
//
// *Quick Notes*
//  
// There you have it! There is a tile maze for you to play with.
// Once again, we would recommend that you read in something like this
// from a file.  That way you can change your levels by editing a text file.
// 
// We didn't change any code in Bitmap.cpp or Sprite.cpp, so you can just
// focus on this file.  We did however, add some #define's in main.h.
// 
// Basically, what we did to make tiles it read in 2 different types of bitmaps.
// We happen to know that they are 32 x 32 (pixels).  Then, we just set them
// next to each other across the screen.  We set our players speed to be the size
// of the tiles in pixels.  That way we move to a new tile each time we move.  See
// if you can get the player to smoothly move from tile to tile, without jumping.
// 
// To check for collision, all we did was take the players position, then divided
// it by the tile width and height for the X and Y index into the board array.
// Just like the ConsoleMaze tutorial, we use that index to see if we are on the
// same index as a wall, if we are... then just restore the old position of the player
// before it moved.
//
// The controls for this APP is:
//
//	- ARROW KEYS : Move the player up down left and right
//  - ESCAPE KEY : Quits the maze
// 
// Let us know what you think of this tutorial.  We are interested to see if this helps!
// 
// DigiBen
// www.GameTutorials.com
//
// © 2000-2003 GameTutorials      


