void init_game(int Primary_or_Secondary)
{
	if (Primary_or_Secondary == 1)
	{
		//INIT FUNCTION...WILL BE CHANGED...PLAYER WILL BE ABLE TO SELECT 1st WEAPON
		g_PLAYER.mission = -2;//mission 0 (first level)
		g_PLAYER.nuke = 1; //1 nuke missile (fire w/ ALT)
		g_PLAYER.charge = 0; //charge gun, needs HUD, (fire by holding CTRL and releasing)
		//UPGRADES
		g_LASER[0].upgrade = -1;//1st upgrade
		g_MGUN[0].upgrade = -1;//4th upgrade (actually 1st, counts by 2)
		g_FLAME[0].upgrade = -1;//starts with 2 because gun is hard to use & short
		g_PULSE[0].upgrade = -1;//starts with 30...i forgot what this does ???
		g_CHARGE[0].upgrade = 1;//starts with 1...hold for a little while and shoot 1..if
		//upgrade hold longer for more

		g_DLASER[0].upgrade = 0;//start with no secondarys
		g_SLASER[0].upgrade = 0;
		g_MISSILE[0].upgrade = 0;
		g_PLAYER.toleft = no;

		g_PLAYER.condition = dead;//player is now alive
		g_PLAYER.mission = 255;

		g_PLAYER.startupgrade = addlaser;

		g_PLAYER.SelectionsComplete = no;
		g_PLAYER.screen = titlesel;

		g_PLAYER.difficulty = easydif;
		g_time = -265;//-265

		g_PLAYER.cruel = unlocked;
		g_PLAYER.exemplar = unlocked;
		g_PLAYER.pariah = unlocked;
		g_PLAYER.renegade = unlocked;

		g_PLAYER.particles = no;

		g_PLAYER.shiptype = 0;
		g_PLAYER.momentum_climb = 4;

		g_HUD.condition = 2;

		g_PLAYER.nightvision = no;

		g_PLAYER.darkmission = no;

		g_PLAYER.special = 0;

		g_HEADLIGHT.condition = dead;
		g_HEADLIGHT.position.y = -160;
		g_HEADLIGHT.position.x = -160;

		g_PLAYER.vision = 0;

		g_PLAYER.battery = 0;
		g_PLAYER.maxbattery = max_battery;

		g_CHARGEBAR.condition = alive;
		g_CHARGEBAR.position.y = 460;
		g_CHARGEBAR.position.x = 72;

		g_NUKEBAR.condition = alive;
		g_NUKEBAR.position.y = 486;
		g_NUKEBAR.position.x = 407;
		g_MO.position.y = 426;
		g_MO.position.x = 240;
	}
	if (Primary_or_Secondary == 2)
	{
		g_WEAPONHUD.position.y = 0;
		g_WEAPONHUD.position.x = 200;
		g_WEAPONHUD2.position.y = 13;
		g_WEAPONHUD2.position.x = 200;

		//set players speed
		g_PLAYER.speed.x = 6;
		g_PLAYER.speed.y = 6;

		//current movement (Adds and subtracts depending on button pushed
		g_PLAYER.momentumx = 0;
		g_PLAYER.momentumy = 0;

		g_PLAYER.position.x = -400;//center middle of screen
		g_PLAYER.position.y = -400;

		g_BATTERY.position.x = gridalignment * 15;//center middle of screen
		g_BATTERY.position.y = 0;

		g_HUD.position.x =  (gridalignment - 32); //set hud position
		g_HUD.position.y = 15.25 * (gridalignment);

		g_RADAR.position.x = RADARFIXx - 8;//set radar position
		g_RADAR.position.y = RADARFIXy - 8;

		g_NUKE.position.x = offscreen-900; //sprite position of neke..dont want to see it, so -900 -900
		g_NUKE.position.y = offscreen-900;

		g_PLAYER.points = 0;
		//init allys, enemys, enemy lasers ect

		for (int x = 0; x < max_particles;x++)
		{
			if (x < 4)
			{
				g_ENDING[x].condition = dyingone;
				g_ENDING[x].SIZEwidth = 1;
				g_ENDING[x].SIZEheight = 1;
				g_ENDING[x].position.y = offscreen;
				g_ENDING[x].position.x = offscreen;
			}
			g_PARTICLE[x].position.x = offscreen;
			g_PARTICLE[x].position.x = offscreen;
			g_PARTICLE[x].condition = dead;
		}
		for (x = 0; x < max_digits; x++)
		{
			g_SCORE[x].condition = 10;
			g_SCORE[x].position.y = 1;
			g_SCORE[x].position.x = (x * 9);
		}
		for (x = 0; x < max_explosions;x++)
		{
			g_EXPLOSION[x].position.x = offscreen;
			g_EXPLOSION[x].position.x = offscreen;
			g_EXPLOSION[x].condition = dead;
		}

		for (x = 0; x < maxally; x++)
		{
			if (x % 2 == 0)
			{
				g_ALLY[x].position.y = offscreen;
				g_ALLY[x].position.x = offscreen;
				g_ALLY[x].condition = dead;
				g_ALLY[x].formation_type = wedgeformation;
				g_ALLY[x].formation_range = defending;
				g_ALLY[x].temp_formation = breakformation;
				g_ALLY[x].xhold = -1;
				g_ALLY[x].health = 10;
				g_ALLY[x].camefrom = none;
				g_ALLY[x].defend_formation_hold = 0;
				g_ALLY[x].maxhealth = 10;
			}
			if (x % 2 == 1)
			{
				g_ALLY[x].position.y = -32;
				g_ALLY[x].position.x = 15 * gridalignment + 32;
				g_ALLY[x].condition = dead;
				g_ALLY[x].formation_type = wedgeformation;
				g_ALLY[x].formation_range = defending;
				g_ALLY[x].temp_formation = breakformation;
				g_ALLY[x].xhold = -1;
				g_ALLY[x].health = 10;
				g_ALLY[x].camefrom = none;
				g_ALLY[x].defend_formation_hold = 0;
				g_ALLY[x].maxhealth = 10;
			}
			g_ALLY[x].hBitmapNormal = LoadABitmap("Aally.bmp");
			g_ALLY[x].hBitmapNightVision = LoadABitmap("AallyNV.bmp");
			g_ALLY[x].hBitmapThermalVision = LoadABitmap("AallyTH.bmp");
			g_ALLY[x].shothold = 0;
			g_ALLY[x].particles = no;
		}
		g_ESCORT.position.y = offscreen-580;
		g_ESCORT.position.x = offscreen-580;
		g_ESCORT.condition = dead;
		g_ESCORT.hBitmapNormal = LoadABitmap("Escort.bmp");
		g_ESCORT.hBitmapNightVision = LoadABitmap("EscortNV.bmp");
		g_ESCORT.hBitmapThermalVision = LoadABitmap("EscortTH.bmp");

		for (x = 0; x < max_level_tiles; x++)
		{
			if (x < max_particles)
			{
				g_PARTICLE[x].hBitmapNormal = LoadABitmap("particle.bmp");
				g_PARTICLE[x].hBitmapNightVision = LoadABitmap("particleNV.bmp");
				g_PARTICLE[x].hBitmapThermalVision = LoadABitmap("particleTH.bmp");
			}
			if (x < lasermax)
			{
				g_POWERUP[x].hBitmapNormal = LoadABitmap("powerup.bmp");
				g_POWERUP[x].hBitmapNightVision = LoadABitmap("powerupNV.bmp");
				g_POWERUP[x].hBitmapThermalVision = LoadABitmap("powerupTH.bmp");
			}
			if ( x < max_levels)
			{
				g_SCREEN[x].condition = dead;
				g_BACKROUND[x].loaded = no;
				g_BACKROUND[x].condition = alive;
				g_BACKROUND[x].hBitmapNormal = LoadABitmap("None.bmp");
				g_BACKROUND[x].hBitmapNightVision = LoadABitmap("None.bmp");
				g_BACKROUND[x].hBitmapThermalVision = LoadABitmap("None.bmp");
			}
			g_LEVEL[x].position.y = 560;
			SetSpriteState(&g_LEVEL[x], NORTH);

			g_ENEMY[x].hBitmap = enemyBMPnorm;
			g_ENEMY[x].hBitmapNormal = enemyBMPnorm;
			g_ENEMY[x].hBitmapNightVision = enemyBMPnv;
			g_ENEMY[x].hBitmapThermalVision = enemyBMPth;
			g_ENEMY[x].position.y = offscreen-32;
			g_ENEMY[x].position.x = offscreen-32;
			g_ENEMY[x].boss = no;
			g_ENEMY[x].particles = no;
			g_ENEMY[x].condition = dead;
			g_ENEMY[x].ship = 1;
			g_ENEMY[x].headlight = no;
			g_ENEMY[x].script = scriptone;
			g_ENEMY[x].shotcount = 0;
			SetSpriteState(&g_ENEMY[x], NORTH);
			g_ELASER[x].position.y = offscreen-32;
			g_ELASER[x].position.x = offscreen-32;
			g_ELASER[x].condition = dead;
			g_ELASER[x].damage = 1;
			g_ENEMY[x].shothold = 0;
			g_ENEMY[x].loaded = no;

			g_BACKROUND[x].condition = dyingone;
			SetSpriteState(&g_BACKROUND[0], NORTH);
			g_BACKROUND[x].position.y = -500;
			g_BACKROUND[x].position.x = -500;
		}

		for (x = 0; x < maxally+1; x++)
		{
			g_HEAD[x].condition = dead;
			g_HEAD[x].position.y = gridalignment -400;
			g_HEAD[x].position.x = gridalignment -400;
			g_HEADBAR[x].condition = dead;
			g_HEADBAR[x].position.y = -400;
			g_HEADBAR[x].position.x = -400;
		}

		//set first head to spawning (your player)
		//now it will do the need scrolll thing in the begining
		g_HEAD[0].condition = spawning;
	}

}