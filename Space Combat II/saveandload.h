#include <fstream>
void save_game()
{
ofstream save;
	save.open("savedfile.dat");
	if(save.fail())								
	{													 
		return;										
	}
	save<<g_PLAYER.startupgrade<<" ";
	save<<weapon<<" ";
	save<<weapon2<<" ";
	save<<g_PLAYER.points<<" ";
	save<<g_PLAYER.ship<<" ";
	save<<g_PLAYER.mission<<" ";
	save<<g_PLAYER.nuke<<" ";
	save<<g_PLAYER.difficulty<<" ";

	save<<g_LASER[0].upgrade<<" ";
	save<<g_LASER[0].damage<<" ";

	save<<g_MGUN[0].upgrade<<" ";
	save<<g_MGUN[0].damage<<" ";

	save<<g_FLAME[0].upgrade<<" ";
	save<<g_FLAME[0].damage<<" ";

	
	save<<g_PULSE[0].upgrade<<" ";
	save<<g_PULSE[0].damage<<" ";

	save<<g_DLASER[0].upgrade<<" ";
	save<<g_DLASER[0].damage<<" ";

	save<<g_SLASER[0].upgrade<<" ";
	save<<g_SLASER[0].damage<<" ";

	save<<g_MISSILE[0].upgrade<<" ";
	save<<g_MISSILE[0].damage<<" ";

	
	save<<g_CHARGE[0].upgrade<<" ";
	save<<g_CHARGE[0].damage<<" ";

	save<<g_ALLY[0].condition<<" ";
	save<<g_ALLY[1].condition<<" ";
	save<<g_ALLY[2].condition<<" ";
	save<<g_ALLY[3].condition<<" ";

	save<<g_PLAYER.cruel<<" ";
	save<<g_PLAYER.pariah<<" ";
	save<<g_PLAYER.renegade<<" ";
	save<<g_PLAYER.exemplar<<" ";

	save<<"\n";
	save.close();
}
void load_game()
{
	ifstream fin;
	fin.open("savedfile.dat");
	if(fin.fail())								
	{													 
		return;										
	}
	fin>>g_PLAYER.startupgrade;
	fin>>weapon;
	fin>>weapon2;
	fin>>g_PLAYER.points;
	fin>>g_PLAYER.ship;
	fin>>g_PLAYER.mission;
	fin>>g_PLAYER.nuke;
	fin>>g_PLAYER.difficulty;

	fin>>g_LASER[0].upgrade;
	fin>>g_LASER[0].damage;

	fin>>g_MGUN[0].upgrade;
	fin>>g_MGUN[0].damage;

	fin>>g_FLAME[0].upgrade;
	fin>>g_FLAME[0].damage;

	
	fin>>g_PULSE[0].upgrade;
	fin>>g_PULSE[0].damage;

	fin>>g_DLASER[0].upgrade;
	fin>>g_DLASER[0].damage;

	fin>>g_SLASER[0].upgrade;
	fin>>g_SLASER[0].damage;

	fin>>g_MISSILE[0].upgrade;
	fin>>g_MISSILE[0].damage;

	
	fin>>g_CHARGE[0].upgrade;
	fin>>g_CHARGE[0].damage;

	fin>>g_ALLY[0].condition;
	fin>>g_ALLY[1].condition;
	fin>>g_ALLY[2].condition;
	fin>>g_ALLY[3].condition;

	for (int q = 0; q < maxlaserupgrade;q++)
					{
						if (g_LASER[0].upgrade <= maxlaserupgrade)
						{
							SetSpriteState(&g_LASER[q], g_LASER[0].upgrade);
						}
						
					}
for (q = 0; q < maxmgunupgrade;q++)
					{
						if (g_MGUN[0].upgrade < maxmgunupgrade)
						{
							SetSpriteState(&g_MGUN[q], ((int)g_MGUN[0].upgrade / 2) - 2);
						}
					}

	fin>>g_PLAYER.cruel;
	fin>>g_PLAYER.pariah;
	fin>>g_PLAYER.renegade;
	fin>>g_PLAYER.exemplar;

	fin.close();

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
	g_time = -450;

	if (g_PLAYER.mission >= 10)
	{
		LoadSprite(&g_PLAYER, "Phunter.bmp", g_PLAYER.SIZEwidth, g_PLAYER.SIZEheight, PLAYER_FRAMES);
		g_PLAYER.hBitmapNormal = LoadABitmap("Phunter.bmp");
		g_PLAYER.hBitmapNightVision = LoadABitmap("PhunterNV.bmp");
		g_PLAYER.hBitmapThermalVision = LoadABitmap("PhunterTH.bmp");
		g_PLAYER.maxhealth = 15;
				g_PLAYER.max_momentumX = (int) (156 / 8);
				g_PLAYER.max_momentumX = (int) (142 / 8);
				g_PLAYER.momentum_climb = (int) (36 / 8);
	}

	for (int x = 0; x < maxally; x++)
	{
		if (g_ALLY[x].condition == alive)
		{
			g_ALLY[x].health = 10;
			g_ALLY[x].position.y = offscreen;
				g_ALLY[x].position.x = offscreen;
				g_ALLY[x].formation_type = wedgeformation;
				g_ALLY[x].formation_range = defending;
				g_ALLY[x].temp_formation = breakformation;
				g_ALLY[x].xhold = -1;
				g_ALLY[x].health = 10;
				g_ALLY[x].camefrom = none;
				g_ALLY[x].defend_formation_hold = 0;
				g_ALLY[x].maxhealth = 10;
		}
	}
	if (g_PLAYER.difficulty == easydif)
								{
									g_PLAYER.maxhealth *=2.5;
								}
								if (g_PLAYER.difficulty == normaldif)
								{
									g_PLAYER.maxhealth *=2;
								}
								if (g_PLAYER.difficulty == harddif)
								{
									g_PLAYER.maxhealth *=1.5;
								}

								g_PLAYER.health= g_PLAYER.maxhealth;

}