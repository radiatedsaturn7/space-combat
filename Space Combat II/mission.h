void mission()
{
	int random = 0;
	int r = 0;
	int z = 0;
	//MISSION STUFF

	if (g_PLAYER.mission == 0 && g_time < 0)
	{
		if (g_time == -1)
		{
			TALKING = no;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			TALKING = no;
			g_time = 0;
			PlaySound("STOP.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		if (g_time == -2348)
		{
			TALKING = yes;
			PlaySound("TUTORIAL.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}

	if (g_PLAYER.mission != 0)
	{
		create_enemy(-50,  13, 1, no, 0, 0, no);
		create_enemy(-51,  13, 2, no, 0, 0, no);
		create_enemy(-105, 13, 3, no, 0, 0, no);
		create_enemy(-106, 13, 4, no, 0, 0, no);
		create_enemy(-150, 13, 3, no, 0, 0, no);
		create_enemy(-151, 13, 4, no, 0, 0, no);
		create_enemy(-205, 13, 1, no, 0, 0, no);
		create_enemy(-206, 13, 2, no, 0, 0, no);
		create_enemy(-250, 13, 1, no, 0, 0, no);
		create_enemy(-251, 13, 2, no, 0, 0, no);
		create_enemy(-290, 13, 3, no, 0, 0, no);
		create_enemy(-291, 13, 4, no, 0, 0, no);
	}
		if(g_PLAYER.mission == -1)
		{
			
				create_enemy(50, 1, -1, no, 0, 0, no);
				create_enemy(52, 2, -1, no, 0, 0, no);
				create_enemy(54, 3, -1, no, 0, 0, no);
				create_enemy(56, 4, -1, no, 0, 0, no);
				create_enemy(58, 5, -1, no, 0, 0, no);
				create_enemy(60, 6, -1, no, 0, 0, no);
				create_enemy(62, 7, -1, no, 0, 0, no);
				create_enemy(64, 8, -1, no, 0, 0, no);
				create_enemy(68, 9, -1, no, 0, 0, no);
				create_enemy(70, 10, -1, no, 0, 0, no);
				create_enemy(72, 11, -1, no, 0, 0, no);
				create_enemy(74, 12, -1, no, 0, 0, no);
				create_enemy(76, 13, -1, no, 0, 0, no);
				

				for (z = 0; z < max_level_tiles && g_ENEMY[z].condition == alive; z++)
				{
					g_ENEMY[z].position.x = (z * 32) + 48;
					g_ENEMY[z].position.y = 140;
				}

		}
		if (g_PLAYER.mission == 2)
		{
			if (g_time == 0)
			{
				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;
						g_ALLY[x].formation_type = wedgeformation;
						break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_time == 0)
			{
				power_up(g_PLAYER.startupgrade);
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			if (g_time == 0)
			{
				/*
				g_PLAYER.startpoints = g_PLAYER.points;
				g_PLAYER.begin_upgrade = g_PLAYER.begin_upgrade;
				g_PLAYER.begin_upgradediagonal = g_PLAYER.upgradediagonal;
				g_PLAYER.begin_upgradeside = g_PLAYER.upgradeside;
				g_PLAYER.begin_upgrademgun = g_PLAYER.upgrademgun;
				g_PLAYER.begin_upgradeflame = g_PLAYER.upgradeflame;
				g_PLAYER.begin_upgradepulse = g_PLAYER.upgradepulse;
				g_PLAYER.begin_upgrademissile = g_PLAYER.upgrademissile;
				g_PLAYER.begin_upgradecharge = g_PLAYER.upgradecharge;
				g_PLAYER.begin_nuke = g_PLAYER.nuke;
				*/
				
			}
			if (g_time == 50 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script  = 1;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 60 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 2;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 70 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 1;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 80 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 2;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 200 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 2;
				g_ENEMY[4].script = 2;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 200 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 2;
				g_ENEMY[5].script = 1;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 200 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 3;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 300 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 1;
				g_ENEMY[7].script = 1;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 310 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 1;
				g_ENEMY[8].script = 2;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 320 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 1;
				g_ENEMY[9].script = 1;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 330 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 1;
				g_ENEMY[10].script = 2;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 380 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 2;
				g_ENEMY[11].script = 0;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = yes;
				g_ENEMY[11].toleft = 5;
				g_ENEMY[11].toright = 0;
			}
			if (g_time == 390 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 2;
				g_ENEMY[12].script = 0;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = yes;
				g_ENEMY[12].toright = 5;
				g_ENEMY[12].toleft = 0;
			}
			if (g_time == 500 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 4;
				g_ENEMY[13].script = 0;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = yes;
			}
			if (g_time == 500 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 1;
				g_ENEMY[14].script = 3;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 500 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 1;
				g_ENEMY[15].script = 4;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 600 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 1;
				g_ENEMY[16].script = 1;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 600 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].script = 2;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 650 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = 1;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 650 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = 2;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 700 && g_ENEMY[0].condition != alive)
			{ 
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 3;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = yes;
			}
			if (g_time == 710 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 2;
				g_ENEMY[1].script = 1;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 710 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 2;
				g_ENEMY[2].script = 2;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 720)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 760 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 3;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 760 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 4;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 760 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 1;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = yes;
			}
			if (g_time == 760 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 1;
				g_ENEMY[6].script = 2;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 770 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 2;
				g_ENEMY[7].script = 3;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 770 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 2;
				g_ENEMY[8].script = 4;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 780 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 2;
				g_ENEMY[9].script = 0;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = yes;
				g_ENEMY[9].toleft = 5;
				g_ENEMY[9].toright = 0;
			}
			if (g_time == 780 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 2;
				g_ENEMY[10].script = 0;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = yes;
				g_ENEMY[10].toleft = 0;
				g_ENEMY[10].toright = 5;
			}
			if (g_time == 950 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 1;
				g_ENEMY[11].script = 0;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = yes;
			}
			if (g_time == 950 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 1;
				g_ENEMY[12].script = 0;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = yes;
			}
			if (g_time == 950 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 1;
				g_ENEMY[13].script = 0;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = yes;
			}
			if (g_time == 950 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 1;
				g_ENEMY[14].script = 0;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = yes;
			}
			if (g_time == 970 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 2;
				g_ENEMY[15].script = 0;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = yes;
			}
			if (g_time == 970 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 2;
				g_ENEMY[16].script = 0;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = yes;
			}
			if (g_time == 970 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 2;
				g_ENEMY[17].script = 0;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = yes;
			}
			if (g_time == 970 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 2;
				g_ENEMY[18].script = 0;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = yes;
			}
			if (g_time == 1000 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 3;
				g_ENEMY[19].script = 0;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = yes;
			}
			if (g_time == 1100 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = yes;
			}
			if (g_time == 1100 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = yes;
			}
			if (g_time == 1100 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = yes;
			}
			if (g_time == 1100 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 0;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = yes;
			}
			if (g_time == 1300 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 1;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1310 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 2;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1320 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 1;
				g_ENEMY[6].script = 1;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1330 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 1;
				g_ENEMY[7].script = 2;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1340 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 1;
				g_ENEMY[8].script = 1;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1350 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 1;
				g_ENEMY[9].script = 2;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1360 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 2;
				g_ENEMY[10].script = 3;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1370 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 2;
				g_ENEMY[11].script = 4;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1380 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 2;
				g_ENEMY[12].script = 3;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1390 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 2;
				g_ENEMY[13].script = 4;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1400 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 2;
				g_ENEMY[14].script = 3;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1410 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 2;
				g_ENEMY[15].script = 4;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1420 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 2;
				g_ENEMY[16].script = 3;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1430 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 2;
				g_ENEMY[17].script = 4;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1440 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 2;
				g_ENEMY[18].script = 3;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1450 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 2;
				g_ENEMY[19].script = 4;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1600 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 2;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = yes;
			}
			if (g_time == 1610 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 2;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = yes;
			}
			if (g_time == 1620 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 2;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = yes;
			}
			if (g_time == 1630 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 2;
				g_ENEMY[3].script = 0;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = yes;
			}
			if (g_time == 1640 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 5;
				g_ENEMY[4].script = 0;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = yes;
			}
			if (g_time == 1750 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 13;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1760 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 13;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1760 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 13;
				g_ENEMY[7].script = 0;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1770 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 13;
				g_ENEMY[8].script = 0;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1780 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 13;
				g_ENEMY[9].script = 1;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1790 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 13;
				g_ENEMY[10].script = 2;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1800 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 13;
				g_ENEMY[11].script = 1;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1810 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 13;
				g_ENEMY[12].script = 2;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1820 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 3;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1830 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 4;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1840 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 3;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1850 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 13;
				g_ENEMY[16].script = 4;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1875)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time >= 2000 && g_ENEMY[17].condition != alive && g_ENEMY[18].condition != alive && g_ENEMY[19].condition!= alive)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].boss = bossone;
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].script = scriptbossone;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss_condition = BOSSONEPIT;

				g_ENEMY[18].boss = bossone;
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = scriptbossone;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
				g_ENEMY[18].boss_condition = BOSSONEWINGR;

				g_ENEMY[19].boss = bossone;
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = scriptbossone;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
				g_ENEMY[19].boss_condition = BOSSONEWINGL;
			}
			
			if (g_time > 2000 && g_ENEMY[17].condition == dead && g_ENEMY[17].boss == bossone)
			{
				fire_nuke();
				g_PLAYER.nuke++;

				g_ENEMY[17].boss = no;
				g_ENEMY[18].boss = no;
				g_ENEMY[19].boss = no;
				g_PLAYER.mission = 3;
				g_time = -450;
			}
			
		}


		if(g_PLAYER.mission == 5)
		{
			if (g_time == 0)
			{
				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;
						g_ALLY[x].formation_type = wedgeformation;
						break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_ALLY[0].condition == alive)
			{
				g_ALLY[0].formation_type = breakformation;
				g_ALLY[0].temp_formation = breakformation;
				g_ALLY[0].position.y-=allyspeed;
			}
			if (g_ALLY[0].position.y <= -28)
			{
				g_ALLY[0].condition = dead;
				g_ALLY[0].position.y = -40;
			}
			if (g_time == 0)
			{
				/*
				g_PLAYER.startpoints = g_PLAYER.points;
				g_PLAYER.begin_upgrade = g_PLAYER.begin_upgrade;
				g_PLAYER.begin_upgradediagonal = g_PLAYER.upgradediagonal;
				g_PLAYER.begin_upgradeside = g_PLAYER.upgradeside;
				g_PLAYER.begin_upgrademgun = g_PLAYER.upgrademgun;
				g_PLAYER.begin_upgradeflame = g_PLAYER.upgradeflame;
				g_PLAYER.begin_upgradepulse = g_PLAYER.upgradepulse;
				g_PLAYER.begin_upgrademissile = g_PLAYER.upgrademissile;
				g_PLAYER.begin_upgradecharge = g_PLAYER.upgradecharge;
				g_PLAYER.begin_nuke = g_PLAYER.nuke;
				*/
				

				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 15)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = g_PLAYER.startupgrade;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 30)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addnuke;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 50 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 2;
				g_ENEMY[0].script = 1;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = yes;
			}
			if (g_time == 50 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 2;
				g_ENEMY[1].script = 2;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = yes;
			}
			if (g_time == 50 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 3;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = yes;
			}
			if (g_time == 50 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 2;
				g_ENEMY[3].script = 4;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = yes;
			}
			if (g_time == 50 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 5;
				g_ENEMY[4].script = 5;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = yes;
			}

			if (g_time == 150 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 1;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = yes;
			}
			if (g_time == 150 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 1;
				g_ENEMY[6].script = 2;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = yes;
			}
			if (g_time == 150 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 1;
				g_ENEMY[7].script = 3;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = yes;
			}
			if (g_time == 150 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 1;
				g_ENEMY[8].script = 4;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = yes;
			}
			if (g_time == 150 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 3;
				g_ENEMY[9].script = 5;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = yes;
			}

			if (g_time == 250 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 2;
				g_ENEMY[10].script = 1;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = yes;
			}
			if (g_time == 250 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 2;
				g_ENEMY[11].script = 2;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = yes;
			}
			if (g_time == 250 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 2;
				g_ENEMY[12].script = 2;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = yes;
			}
			if (g_time == 250 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 2;
				g_ENEMY[13].script = 2;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = yes;
			}
			if (g_time == 250 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 5;
				g_ENEMY[14].script = 2;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = yes;
			}
			if (g_time == 350 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 6;
				g_ENEMY[15].script = 2;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = yes;
			}
			if (g_time == 450 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 5;
				g_ENEMY[16].script = 5;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = yes;
			}
			if (g_time == 450 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].script = 0;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 450 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = 0;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 500)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
						g_time++;break;
					}
				}
			}
			if (g_time == 600 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 13;
				g_ENEMY[19].script = 0;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 610 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 13;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 620 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 13;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 630 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 13;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 640 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 13;
				g_ENEMY[3].script = 0;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 650 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 13;
				g_ENEMY[4].script = 0;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 660 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 13;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 670 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 13;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 680 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 13;
				g_ENEMY[7].script = 0;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 690 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 13;
				g_ENEMY[8].script = 0;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 700 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 13;
				g_ENEMY[9].script = 0;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 900 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 5;
				g_ENEMY[10].script = 5;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1000 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 5;
				g_ENEMY[11].script = 5;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1100 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 2;
				g_ENEMY[12].script = 1;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1100 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 2;
				g_ENEMY[13].script = 2;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1150 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 5;
				g_ENEMY[14].script = 3;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1150 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 5;
				g_ENEMY[15].script = 4;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1200 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 5;
				g_ENEMY[16].script = 4;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1300 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 6;
				g_ENEMY[17].script = 0;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1310 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 6;
				g_ENEMY[18].script = 0;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1320 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = 0;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1330 && g_ENEMY[0].condition != alive)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1530 && g_ENEMY[1].condition != alive)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 3;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1550 && g_ENEMY[2].condition != alive)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 3;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1570 && g_ENEMY[3].condition != alive)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 3;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1590 && g_ENEMY[4].condition != alive)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 3;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1610 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 3;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1630 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 1;
				g_ENEMY[6].script = 3;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1630 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 1;
				g_ENEMY[7].script = 3;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1650 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 1;
				g_ENEMY[8].script = 4;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1670 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 1;
				g_ENEMY[9].script = 4;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1690 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 1;
				g_ENEMY[10].script = 4;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1710 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 1;
				g_ENEMY[11].script = 4;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1730 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 1;
				g_ENEMY[12].script = 4;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1750 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 1;
				g_ENEMY[13].script = 4;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1770 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 1;
				g_ENEMY[14].script = 4;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1900 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 5;
				g_ENEMY[14].script = 5;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 2000 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 6;
				g_ENEMY[15].script = 5;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 2050)
			{
				power_up(addhealth);
			}
			if (g_time == 2100)
			{
				power_up(addnuke);
			}
			if (g_time == 2200)
			{
				power_up(addnuke);
			}
			if (g_time >= 2300 && g_ENEMY[17].condition != alive && g_ENEMY[17].boss != bosstwo)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].boss = bosstwo;
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].loaded = yes;
				g_ENEMY[17].script = scriptbosstwo;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss_condition = 0;
				g_ENEMY[17].SIZEwidth = 208;
				g_ENEMY[17].SIZEheight = 98;
				LoadSprite(&g_ENEMY[17], "LargeEnemy.bmp", g_ENEMY[17].SIZEwidth, g_ENEMY[17].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[17].hBitmapNormal = LoadABitmap("LargeEnemy.bmp");
				g_ENEMY[17].hBitmapNightVision = LoadABitmap("LargeEnemyNV.bmp");
				g_ENEMY[17].hBitmapThermalVision = LoadABitmap("LargeEnemyTH.bmp");
				SetSpriteState(&g_ENEMY[17], 0);
			}
			if (g_time > 2300 && g_ENEMY[17].health <= 0 && g_ENEMY[17].condition == alive && g_ENEMY[17].boss == bosstwo)
			{
				g_ENEMY[17].condition = dead;
				g_ENEMY[17].position.y = offscreen;
				fire_nuke();
				g_PLAYER.nuke++;
				g_ENEMY[17].boss = no;
				g_PLAYER.mission = 6;
				g_time = -450;
				g_ENEMY[17].SIZEwidth = 32;
				g_ENEMY[17].SIZEheight = 32;
				g_ENEMY[17].hBitmap = enemyBMPnorm;
				g_ENEMY[17].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[17].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[17].hBitmapThermalVision = enemyBMPth;
				SetSpriteState(&g_ENEMY[17], 0);
			}
			if (g_time >= 2300 && g_ENEMY[17].condition == alive && g_ENEMY[17].shothold == 540)
			{
				g_PLAYER.special = 0;
				create_enemy(-1, 1, 1, no, 0, 0, yes);
				create_enemy-1, 1, 2, no, 0, 0, yes);
				create_enemy(-1, 1, 3, no, 0, 0, yes);
				create_enemy(-1, 1, 4, no, 0, 0, yes);
				g_ENEMY[17].shothold++;
			}
			if (g_PLAYER.special >= 4)
			{
				g_PLAYER.special = 0;
				power_up(addnuke);
				power_up(addnuke);
				power_up(addhealth);
			}
		}
		if (g_PLAYER.mission == 8)
		{
			if (g_time == 0)
			{
				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;
						g_ALLY[x].formation_type = wedgeformation;
						break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
				for (x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;
						g_ALLY[x].formation_type = wedgeformation;
						break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_time == 0)
			{
				power_up(g_PLAYER.startupgrade);
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			if (g_time == 0)
				{
					PlaySound("nolunar.wav", NULL, SND_FILENAME | SND_ASYNC);
					TALKING = yes;
				}
				if (g_time == 100)
				{
					TALKING = no;
				}
			if (g_time == 0)
			{
				g_PLAYER.darkmission = no;
				/*
				g_PLAYER.startpoints = g_PLAYER.points;
				g_PLAYER.begin_upgrade = g_PLAYER.begin_upgrade;
				g_PLAYER.begin_upgradediagonal = g_PLAYER.upgradediagonal;
				g_PLAYER.begin_upgradeside = g_PLAYER.upgradeside;
				g_PLAYER.begin_upgrademgun = g_PLAYER.upgrademgun;
				g_PLAYER.begin_upgradeflame = g_PLAYER.upgradeflame;
				g_PLAYER.begin_upgradepulse = g_PLAYER.upgradepulse;
				g_PLAYER.begin_upgrademissile = g_PLAYER.upgrademissile;
				g_PLAYER.begin_upgradecharge = g_PLAYER.upgradecharge;
				g_PLAYER.begin_nuke = g_PLAYER.nuke;
				*/

				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_time == 100)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 110)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = 6;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 120)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 130)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = 6;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 140)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 150)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].script = 6;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 160)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 170)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 1;
				g_ENEMY[16].script = 6;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 180)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 190)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 1;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 3;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 3;
				g_ENEMY[7].script = 0;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 2;
				g_ENEMY[8].script = 1;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 2;
				g_ENEMY[9].script = 2;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 270)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 2;
				g_ENEMY[10].script = 3;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 270)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 2;
				g_ENEMY[11].script = 4;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 290)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 5;
				g_ENEMY[12].script = 5;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 350)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 1;
				g_ENEMY[13].script = 6;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 370)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 1;
				g_ENEMY[14].script = 6;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 390)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 1;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 410)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 1;
				g_ENEMY[16].script = 6;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 460)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 4;
				g_ENEMY[17].script = 0;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = yes;
			}
			if (g_time == 460)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 4;
				g_ENEMY[18].script = 0;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = yes;
			}
			if (g_time == 500)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 5;
				g_ENEMY[19].script = 5;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = yes;
			}
			if (g_time == 550)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 6;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = yes;
			}
			if (g_time == 615)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 650)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 7;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 650)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 7;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 700)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 5;
				g_ENEMY[3].script = 5;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 740)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 13;
				g_ENEMY[4].script = 0;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 750 && g_ENEMY[5].condition != alive)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 13;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 760 && g_ENEMY[6].condition != alive)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 13;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 760 && g_ENEMY[7].condition != alive)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 13;
				g_ENEMY[7].script = 0;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 770 && g_ENEMY[8].condition != alive)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 13;
				g_ENEMY[8].script = 0;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 780 && g_ENEMY[9].condition != alive)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 13;
				g_ENEMY[9].script = 1;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 790 && g_ENEMY[10].condition != alive)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 13;
				g_ENEMY[10].script = 2;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 800 && g_ENEMY[11].condition != alive)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 13;
				g_ENEMY[11].script = 1;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 810 && g_ENEMY[12].condition != alive)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 13;
				g_ENEMY[12].script = 2;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 820 && g_ENEMY[13].condition != alive)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 3;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 830 && g_ENEMY[14].condition != alive)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 4;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 840 && g_ENEMY[15].condition != alive)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 3;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 850 && g_ENEMY[16].condition != alive)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 13;
				g_ENEMY[16].script = 4;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 860 && g_ENEMY[17].condition != alive)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 13;
				g_ENEMY[17].script = 4;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 870 && g_ENEMY[18].condition != alive)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 13;
				g_ENEMY[18].script = 4;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 880 && g_ENEMY[19].condition != alive)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 13;
				g_ENEMY[19].script = 4;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 900)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 950)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 7;
				g_ENEMY[0].script = 4;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1000)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 7;
				g_ENEMY[1].script = 4;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1050)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 8;
				g_ENEMY[2].script = 4;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1150)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 4;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1160)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 0;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1170)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 1;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1190)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 2;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = yes;
			}
			if (g_time == 1200)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 2;
				g_ENEMY[7].script = 0;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = yes;
			}
			if (g_time == 1230)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 3;
				g_ENEMY[8].script = 3;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1240)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 3;
				g_ENEMY[9].script = 4;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1260)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 4;
				g_ENEMY[10].script = 1;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1270)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 4;
				g_ENEMY[10].script = 1;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1300)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 5;
				g_ENEMY[11].script = 5;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1350)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 6;
				g_ENEMY[12].script = 5;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1400)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 0;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1410)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 0;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1420)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 0;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1430)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 13;
				g_ENEMY[16].script = 0;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1440)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 13;
				g_ENEMY[17].script = 0;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1450)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 13;
				g_ENEMY[18].script = 0;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1460)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 13;
				g_ENEMY[19].script = 0;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1470)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 13;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1480)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 13;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1490)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 13;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1500)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 13;
				g_ENEMY[3].script = 0;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1550)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1500)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 11;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1525)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 11;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1550)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 11;
				g_ENEMY[6].script = 6;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1575)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 11;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1600)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 11;
				g_ENEMY[8].script = 6;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 8;
				g_ENEMY[9].script = 5;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 13;
				g_ENEMY[10].script = 2;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 13;
				g_ENEMY[11].script = 1;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 8;
				g_ENEMY[12].script = 5;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1750)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 1;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1750)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 5;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 3;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 9;
				g_ENEMY[16].script = 5;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 13;
				g_ENEMY[17].script = 4;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1850)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 11;
				g_ENEMY[19].script = 0;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1850)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 11;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1900)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 9;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1915)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}

			if (g_time >= 2000 && g_ENEMY[17].condition != alive && g_ENEMY[17].boss != bossthree)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].boss = bossthree;
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].loaded = yes;
				g_ENEMY[17].script = scriptbossthree;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss_condition = 0;
				g_ENEMY[17].SIZEwidth = 231;
				g_ENEMY[17].SIZEheight = 140;
				LoadSprite(&g_ENEMY[17], "LargeEnemy2.bmp", g_ENEMY[17].SIZEwidth, g_ENEMY[17].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[17].hBitmapNormal = LoadABitmap("LargeEnemy2.bmp");
				g_ENEMY[17].hBitmapNightVision = LoadABitmap("LargeEnemy2NV.bmp");
				g_ENEMY[17].hBitmapThermalVision = LoadABitmap("LargeEnemy2TH.bmp");
				SetSpriteState(&g_ENEMY[17], 0);
			}
			if (g_time > 2300 && g_ENEMY[17].health <= 0 && g_ENEMY[17].boss == bossthree)
			{
				g_ENEMY[17].condition = dead;
				fire_nuke();
				g_PLAYER.nuke++;
				g_ENEMY[17].boss = no;
				g_PLAYER.mission = 9;
				g_time = -450;
				g_ENEMY[17].SIZEwidth = 32;
				g_ENEMY[17].SIZEheight = 32;
				g_ENEMY[17].hBitmap = enemyBMPnorm;
				g_ENEMY[17].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[17].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[17].hBitmapThermalVision = enemyBMPth;
				SetSpriteState(&g_ENEMY[17], 0);
			}
		}

		if (g_PLAYER.mission == 10)
		{
			if (g_time == 0)
			{
				power_up(g_PLAYER.startupgrade);
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			if (g_time == 0)
			{
				/*
				g_PLAYER.startpoints = g_PLAYER.points;
				g_PLAYER.begin_upgrade = g_PLAYER.begin_upgrade;
				g_PLAYER.begin_upgradediagonal = g_PLAYER.upgradediagonal;
				g_PLAYER.begin_upgradeside = g_PLAYER.upgradeside;
				g_PLAYER.begin_upgrademgun = g_PLAYER.upgrademgun;
				g_PLAYER.begin_upgradeflame = g_PLAYER.upgradeflame;
				g_PLAYER.begin_upgradepulse = g_PLAYER.upgradepulse;
				g_PLAYER.begin_upgrademissile = g_PLAYER.upgrademissile;
				g_PLAYER.begin_upgradecharge = g_PLAYER.upgradecharge;
				g_PLAYER.begin_nuke = g_PLAYER.nuke;
				*/
				

				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_time == 100)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 7;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 110)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 2;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 120)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 2;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 130)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 2;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 140)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 2;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 150)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 2;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 160)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 2;
				g_ENEMY[6].script = 6;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 170)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 2;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 180)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 2;
				g_ENEMY[8].script = 6;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 190)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 2;
				g_ENEMY[9].script = 6;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 5;
				g_ENEMY[10].script = 5;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 7;
				g_ENEMY[11].script = 7;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 7;
				g_ENEMY[12].script = 7;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 275)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 7;
				g_ENEMY[13].script = 0;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 275)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 7;
				g_ENEMY[14].script = 0;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 300)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 4;
				g_ENEMY[15].script = 1;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 300)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 4;
				g_ENEMY[16].script = 2;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 325)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 4;
				g_ENEMY[17].script = 8;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 325)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 4;
				g_ENEMY[18].script = 9;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 460)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 11;
				g_ENEMY[19].script = 6;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 470)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 11;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 480)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 11;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 490)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 11;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 500)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 11;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 500)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 11;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 510)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 11;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 510)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 11;
				g_ENEMY[6].script = 6;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 520)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 11;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 530)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 11;
				g_ENEMY[8].script = 6;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 540)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 11;
				g_ENEMY[9].script = 6;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 550)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 11;
				g_ENEMY[10].script = 6;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 560)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 11;
				g_ENEMY[11].script = 6;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 570)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 11;
				g_ENEMY[12].script = 6;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 580)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 11;
				g_ENEMY[13].script = 6;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 590)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 11;
				g_ENEMY[14].script = 6;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 600)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 11;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 625)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 650)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 9;
				g_ENEMY[16].script = 3;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 650)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 9;
				g_ENEMY[17].script = 4;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 675)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 9;
				g_ENEMY[18].script = 1;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 675)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 9;
				g_ENEMY[19].script = 2;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 700)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 6;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 725)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 4;
				g_ENEMY[1].script = 10;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 725)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 4;
				g_ENEMY[2].script = 11;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 750)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 3;
				g_ENEMY[3].script = 8;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 750)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 3;
				g_ENEMY[4].script = 9;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 800)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 4;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 825)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 3;
				g_ENEMY[6].script = 1;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 850)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 3;
				g_ENEMY[7].script = 2;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 875)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 4;
				g_ENEMY[8].script = 3;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 900)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 4;
				g_ENEMY[9].script = 3;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 950)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 4;
				g_ENEMY[10].script = 3;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1000)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 6;
				g_ENEMY[11].script = 0;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1020)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 6;
				g_ENEMY[12].script = 0;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1040)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 7;
				g_ENEMY[13].script = 1;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1060)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 7;
				g_ENEMY[13].script = 2;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1080)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 8;
				g_ENEMY[14].script = 3;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1100)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 8;
				g_ENEMY[15].script = 4;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1150)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 9;
				g_ENEMY[16].script = 5;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1175)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 11;
				g_ENEMY[17].script = 6;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1185)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 11;
				g_ENEMY[18].script = 6;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1195)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 11;
				g_ENEMY[19].script = 6;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1205)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 11;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1215)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 11;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1225)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 11;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1235)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 11;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1245)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 11;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1255)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 11;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1265)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 11;
				g_ENEMY[6].script = 6;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1275)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 11;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1285)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 11;
				g_ENEMY[8].script = 6;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1295)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 11;
				g_ENEMY[9].script = 6;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1300)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 11;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1375)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1400)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 11;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1410)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 11;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1460)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 9;
				g_ENEMY[4].script = 5;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1500)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 8;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1500)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 8;
				g_ENEMY[6].script = 0;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1550)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 8;
				g_ENEMY[7].script = 7;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1550)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 8;
				g_ENEMY[8].script = 7;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1600)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 4;
				g_ENEMY[9].script = 1;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1600)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 4;
				g_ENEMY[10].script = 2;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1650)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 3;
				g_ENEMY[11].script = 0;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = yes;
			}
			if (g_time == 1650)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 3;
				g_ENEMY[12].script = 0;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = yes;
			}
			if (g_time == 1700)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 8;
				g_ENEMY[13].script = 1;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 8;
				g_ENEMY[14].script = 1;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1750)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 9;
				g_ENEMY[15].script = 5;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 8;
				g_ENEMY[16].script = 8;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 8;
				g_ENEMY[17].script = 9;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1850)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 6;
				g_ENEMY[18].script = 7;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1850)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 6;
				g_ENEMY[19].script = 7;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1900)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 5;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1915)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}


			if (g_time == 2015)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].condition = alive;
				g_ENEMY[17].script = scriptbossfour;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss = bossfour;
				g_ENEMY[17].loaded = yes;
				g_ENEMY[18].loaded = yes;
				g_ENEMY[19].loaded = yes;

				g_ENEMY[18].condition = alive;
				g_ENEMY[18].script = scriptbossfour;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
				g_ENEMY[18].boss = bossfour;

				g_ENEMY[19].condition = alive;
				g_ENEMY[19].script = scriptbossfour;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
				g_ENEMY[19].boss = bossfour;

				g_ENEMY[17].SIZEwidth = 208;
				g_ENEMY[18].SIZEwidth = 208;
				g_ENEMY[19].SIZEwidth = 208;
				g_ENEMY[17].SIZEheight = 98;
				g_ENEMY[18].SIZEheight = 98;
				g_ENEMY[19].SIZEheight = 98;

				LoadSprite(&g_ENEMY[17], "LargeEnemy3c.bmp", g_ENEMY[17].SIZEwidth, g_ENEMY[17].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[17].hBitmapNormal = LoadABitmap("LargeEnemy3c.bmp");
				g_ENEMY[17].hBitmapNightVision = LoadABitmap("LargeEnemy3cNV.bmp");
				g_ENEMY[17].hBitmapThermalVision = LoadABitmap("LargeEnemy3cTH.bmp");
				
				LoadSprite(&g_ENEMY[18], "LargeEnemy3b.bmp", g_ENEMY[18].SIZEwidth, g_ENEMY[18].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[18].hBitmapNormal = LoadABitmap("LargeEnemy3b.bmp");
				g_ENEMY[18].hBitmapNightVision = LoadABitmap("LargeEnemy3bNV.bmp");
				g_ENEMY[18].hBitmapThermalVision = LoadABitmap("LargeEnemy3bTH.bmp");
				
				LoadSprite(&g_ENEMY[19], "LargeEnemy3a.bmp", g_ENEMY[19].SIZEwidth, g_ENEMY[19].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[19].hBitmapNormal = LoadABitmap("LargeEnemy3a.bmp");
				g_ENEMY[19].hBitmapNightVision = LoadABitmap("LargeEnemy3aNV.bmp");
				g_ENEMY[19].hBitmapThermalVision = LoadABitmap("LargeEnemy3aTH.bmp");
				
			}
			if (g_time > 2015 && (g_ENEMY[17].health <= 0 && g_ENEMY[18].health <= 0 && 
				g_ENEMY[19].health <= 0) && g_ENEMY[17].boss == bossfour)
			{
				fire_nuke();
				g_PLAYER.nuke++;
				g_ENEMY[17].condition = dead;
				g_ENEMY[18].condition = dead;
				g_ENEMY[17].boss = no;
				g_ENEMY[18].boss = no;
				g_ENEMY[19].condition = dead;
				g_ENEMY[19].boss = no;
				g_PLAYER.mission = 11;
				g_time = -450;

				g_ENEMY[17].SIZEwidth = 32;
				g_ENEMY[18].SIZEwidth = 32;
				g_ENEMY[19].SIZEwidth = 32;
				g_ENEMY[17].SIZEheight = 32;
				g_ENEMY[18].SIZEheight = 32;
				g_ENEMY[19].SIZEheight = 32;

				g_ENEMY[17].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[17].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[17].hBitmapThermalVision = enemyBMPth;
				g_ENEMY[18].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[18].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[18].hBitmapThermalVision = enemyBMPth;
				g_ENEMY[19].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[19].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[19].hBitmapThermalVision = enemyBMPth;
			}
		}

		if (g_PLAYER.mission == 12)
		{
			if (g_time == 0)
			{
				power_up(addcharge);
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			if (g_time == 0)
			{
				/*
				g_PLAYER.startpoints = g_PLAYER.points;
				g_PLAYER.begin_upgrade = g_PLAYER.begin_upgrade;
				g_PLAYER.begin_upgradediagonal = g_PLAYER.upgradediagonal;
				g_PLAYER.begin_upgradeside = g_PLAYER.upgradeside;
				g_PLAYER.begin_upgrademgun = g_PLAYER.upgrademgun;
				g_PLAYER.begin_upgradeflame = g_PLAYER.upgradeflame;
				g_PLAYER.begin_upgradepulse = g_PLAYER.upgradepulse;
				g_PLAYER.begin_upgrademissile = g_PLAYER.upgrademissile;
				g_PLAYER.begin_upgradecharge = g_PLAYER.upgradecharge;
				g_PLAYER.begin_nuke = g_PLAYER.nuke;
				*/
				

				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			if (g_time == 45)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 60)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}

			if (g_time == 160)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 1;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 8;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 1;
				g_ENEMY[3].script = 2;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 200)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 1;
				g_ENEMY[4].script = 9;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 5;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 250)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 5;
				g_ENEMY[6].script = 7;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 275)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 2;
				g_ENEMY[7].script = 3;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 275)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 2;
				g_ENEMY[8].script = 4;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 275)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 2;
				g_ENEMY[9].script = 3;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 300)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 2;
				g_ENEMY[10].script = 10;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 300)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 2;
				g_ENEMY[11].script = 11;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 300)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 12;
				g_ENEMY[12].script = 6;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 310)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 12;
				g_ENEMY[13].script = 6;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 320)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 12;
				g_ENEMY[14].script = 6;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 330)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 12;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 340)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 12;
				g_ENEMY[16].script = 6;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 350)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 12;
				g_ENEMY[17].script = 6;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 360)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 12;
				g_ENEMY[18].script = 6;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 370)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 12;
				g_ENEMY[19].script = 6;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 380)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 12;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 390)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 12;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 400)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 13;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 405)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 13;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 410)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 13;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 415)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 13;
				g_ENEMY[3].script = 6;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 420)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 13;
				g_ENEMY[4].script = 6;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 425)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 13;
				g_ENEMY[5].script = 6;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 430)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 13;
				g_ENEMY[6].script = 6;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 435)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 13;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 440)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 13;
				g_ENEMY[8].script = 6;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 445)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 13;
				g_ENEMY[9].script = 6;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 450)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 13;
				g_ENEMY[10].script = 6;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 455)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 13;
				g_ENEMY[11].script = 6;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 460)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 13;
				g_ENEMY[12].script = 6;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 465)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 6;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 470)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 6;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 475)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 480)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 13;
				g_ENEMY[16].script = 6;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 485)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 13;
				g_ENEMY[17].script = 6;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 490)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 13;
				g_ENEMY[18].script = 6;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 495)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 13;
				g_ENEMY[19].script = 6;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}

			if (g_time == 525)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 5;
				g_ENEMY[0].script = 5;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 545)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 5;
				g_ENEMY[1].script = 5;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 565)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 5;
				g_ENEMY[2].script = 5;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 585)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 6;
				g_ENEMY[3].script = 5;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 600)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 6;
				g_ENEMY[4].script = 5;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 625)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 6;
				g_ENEMY[5].script = 5;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 625)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 2;
				g_ENEMY[6].script = 8;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 625)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 2;
				g_ENEMY[7].script = 9;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 650)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			
			
			if (g_time == 775)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 3;
				g_ENEMY[8].script = 3;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 775)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 3;
				g_ENEMY[9].script = 4;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 775)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 3;
				g_ENEMY[10].script = 8;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 775)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 3;
				g_ENEMY[10].script = 9;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 775)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 4;
				g_ENEMY[11].script = 5;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 775)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 1;
				g_ENEMY[12].script = 6;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 785)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 1;
				g_ENEMY[13].script = 3;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 785)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 1;
				g_ENEMY[14].script = 4;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 785)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 1;
				g_ENEMY[15].script = 10;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 785)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 1;
				g_ENEMY[16].script = 11;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}

			if (g_time == 785)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 1;
				g_ENEMY[16].script = 11;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}

			if (g_time == 800)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
						g_time++;break;
					}
				}
			}

			if (g_time == 875)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 0;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 885)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 2;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = yes;
			}
			if (g_time == 895)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 3;
				g_ENEMY[2].script = 1;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 905)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 4;
				g_ENEMY[3].script = 2;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 915)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 5;
				g_ENEMY[4].script = 3;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 925)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 6;
				g_ENEMY[5].script = 4;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 935)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 7;
				g_ENEMY[6].script = 5;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 945)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 8;
				g_ENEMY[7].script = 6;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 955)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 9;
				g_ENEMY[8].script = 7;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 965)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 9;
				g_ENEMY[9].script = 7;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = yes;
			}
			if (g_time == 975)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 10;
				g_ENEMY[10].script = 8;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 985)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 11;
				g_ENEMY[11].script = 9;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 995)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 12;
				g_ENEMY[12].script = 10;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 105)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 13;
				g_ENEMY[13].script = 11;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1015)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 13;
				g_ENEMY[14].script = 12;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}

			if (g_time == 1065)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}

			if (g_time == 1130)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 13;
				g_ENEMY[15].script = 6;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1140)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 13;
				g_ENEMY[16].script = 6;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1150)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = 1;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1150)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = 2;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1200)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 10;
				g_ENEMY[17].script = 5;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1225)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 1;
				g_ENEMY[0].script = 6;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1235)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 1;
				g_ENEMY[1].script = 6;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1235)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 1;
				g_ENEMY[2].script = 6;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1265)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 6;
				g_ENEMY[3].script = 3;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1265)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 6;
				g_ENEMY[4].script = 4;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1300)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 10;
				g_ENEMY[5].script = 8;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}
			if (g_time == 1350)
			{
				g_ENEMY[6].condition = alive;
				g_ENEMY[6].ship = 10;
				g_ENEMY[6].script = 9;
				g_ENEMY[6].scriptpos = -1;
				g_ENEMY[6].randomdirectionpicked = no;
			}
			if (g_time == 1400)
			{
				g_ENEMY[7].condition = alive;
				g_ENEMY[7].ship = 10;
				g_ENEMY[7].script = 10;
				g_ENEMY[7].scriptpos = -1;
				g_ENEMY[7].randomdirectionpicked = no;
			}
			if (g_time == 1450)
			{
				g_ENEMY[8].condition = alive;
				g_ENEMY[8].ship = 10;
				g_ENEMY[8].script = 11;
				g_ENEMY[8].scriptpos = -1;
				g_ENEMY[8].randomdirectionpicked = no;
			}
			if (g_time == 1450)
			{
				g_ENEMY[9].condition = alive;
				g_ENEMY[9].ship = 10;
				g_ENEMY[9].script = 11;
				g_ENEMY[9].scriptpos = -1;
				g_ENEMY[9].randomdirectionpicked = no;
			}
			if (g_time == 1500)
			{
				g_ENEMY[10].condition = alive;
				g_ENEMY[10].ship = 10;
				g_ENEMY[10].script = 5;
				g_ENEMY[10].scriptpos = -1;
				g_ENEMY[10].randomdirectionpicked = no;
			}
			if (g_time == 1550)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1600)
			{
				g_ENEMY[11].condition = alive;
				g_ENEMY[11].ship = 12;
				g_ENEMY[11].script = 6;
				g_ENEMY[11].scriptpos = -1;
				g_ENEMY[11].randomdirectionpicked = no;
			}
			if (g_time == 1610)
			{
				g_ENEMY[12].condition = alive;
				g_ENEMY[12].ship = 12;
				g_ENEMY[12].script = 6;
				g_ENEMY[12].scriptpos = -1;
				g_ENEMY[12].randomdirectionpicked = no;
			}
			if (g_time == 1620)
			{
				g_ENEMY[13].condition = alive;
				g_ENEMY[13].ship = 12;
				g_ENEMY[13].script = 8;
				g_ENEMY[13].scriptpos = -1;
				g_ENEMY[13].randomdirectionpicked = no;
			}
			if (g_time == 1630)
			{
				g_ENEMY[14].condition = alive;
				g_ENEMY[14].ship = 12;
				g_ENEMY[14].script = 9;
				g_ENEMY[14].scriptpos = -1;
				g_ENEMY[14].randomdirectionpicked = no;
			}
			if (g_time == 1640)
			{
				g_ENEMY[15].condition = alive;
				g_ENEMY[15].ship = 12;
				g_ENEMY[15].script = 10;
				g_ENEMY[15].scriptpos = -1;
				g_ENEMY[15].randomdirectionpicked = no;
			}
			if (g_time == 1650)
			{
				g_ENEMY[16].condition = alive;
				g_ENEMY[16].ship = 12;
				g_ENEMY[16].script = 11;
				g_ENEMY[16].scriptpos = -1;
				g_ENEMY[16].randomdirectionpicked = no;
			}
			if (g_time == 1650)
			{
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 6;
				g_ENEMY[17].script = 3;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
			}
			if (g_time == 1650)
			{
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 6;
				g_ENEMY[18].script = 4;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 6;
				g_ENEMY[19].script = 1;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
			}
			if (g_time == 1700)
			{
				g_ENEMY[0].condition = alive;
				g_ENEMY[0].ship = 6;
				g_ENEMY[0].script = 2;
				g_ENEMY[0].scriptpos = -1;
				g_ENEMY[0].randomdirectionpicked = no;
			}
			if (g_time == 1800)
			{
				g_ENEMY[1].condition = alive;
				g_ENEMY[1].ship = 3;
				g_ENEMY[1].script = 0;
				g_ENEMY[1].scriptpos = -1;
				g_ENEMY[1].randomdirectionpicked = no;
			}
			if (g_time == 1825)
			{
				g_ENEMY[2].condition = alive;
				g_ENEMY[2].ship = 3;
				g_ENEMY[2].script = 0;
				g_ENEMY[2].scriptpos = -1;
				g_ENEMY[2].randomdirectionpicked = no;
			}
			if (g_time == 1850)
			{
				g_ENEMY[3].condition = alive;
				g_ENEMY[3].ship = 3;
				g_ENEMY[3].script = 0;
				g_ENEMY[3].scriptpos = -1;
				g_ENEMY[3].randomdirectionpicked = no;
			}
			if (g_time == 1875)
			{
				g_ENEMY[4].condition = alive;
				g_ENEMY[4].ship = 3;
				g_ENEMY[4].script = 0;
				g_ENEMY[4].scriptpos = -1;
				g_ENEMY[4].randomdirectionpicked = no;
			}
			if (g_time == 1900)
			{
				g_ENEMY[5].condition = alive;
				g_ENEMY[5].ship = 3;
				g_ENEMY[5].script = 0;
				g_ENEMY[5].scriptpos = -1;
				g_ENEMY[5].randomdirectionpicked = no;
			}

			if (g_time == 1910)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1925)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1940)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1955)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 1970)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 2000)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 2015)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 2030)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addnuke;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 2045)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}
			if (g_time == 2060)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = -1;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}
			}

			if (g_time == 2165)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].condition = alive;
				g_ENEMY[17].script = scriptbossfive;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss = bossfive;
				g_ENEMY[17].loaded = yes;
				g_ENEMY[18].loaded = yes;
				g_ENEMY[19].loaded = yes;

		//		g_ENEMY[18].condition = alive;
				g_ENEMY[18].script = scriptbossfive;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
				g_ENEMY[18].boss = bossfive;

		//		g_ENEMY[19].condition = alive;
				g_ENEMY[19].script = scriptbossfive;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
				g_ENEMY[19].boss = bossfive;

				g_ENEMY[17].SIZEwidth = 478;
				g_ENEMY[18].SIZEwidth = 478;
				g_ENEMY[19].SIZEwidth = 478;
				g_ENEMY[17].SIZEheight = 298;
				g_ENEMY[18].SIZEheight = 298;
				g_ENEMY[19].SIZEheight = 298;

				LoadSprite(&g_ENEMY[17], "finalbossc.bmp", g_ENEMY[17].SIZEwidth, g_ENEMY[17].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[17].hBitmapNormal = LoadABitmap("finalbossa.bmp");
				g_ENEMY[17].hBitmapNightVision = LoadABitmap("finalbossaNV.bmp");
				g_ENEMY[17].hBitmapThermalVision = LoadABitmap("finalbosaTH.bmp");
				/*
				LoadSprite(&g_ENEMY[18], "finalbossb.bmp", g_ENEMY[18].SIZEwidth, g_ENEMY[18].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[18].hBitmapNormal = LoadABitmap("finalbossb.bmp");
				g_ENEMY[18].hBitmapNightVision = LoadABitmap("finalbossbNV.bmp");
				g_ENEMY[18].hBitmapThermalVision = LoadABitmap("finalbossbTH.bmp");
				
				LoadSprite(&g_ENEMY[19], "finalbossa.bmp", g_ENEMY[19].SIZEwidth, g_ENEMY[19].SIZEheight, PLAYER_FRAMES);
				g_ENEMY[19].hBitmapNormal = LoadABitmap("finalbossa.bmp");
				g_ENEMY[19].hBitmapNormal = g_ENEMY[19].hBitmap;
				g_ENEMY[19].hBitmapNightVision = LoadABitmap("finalbossaNV.bmp");
				g_ENEMY[19].hBitmapThermalVision = LoadABitmap("finalbossaTH.bmp");
				*/
				
			}
			if (g_time > 2165 && g_ENEMY[17].health <= 0 && g_ENEMY[17].condition == alive && g_ENEMY[17].boss == bossfive)
			{
				fire_nuke();
				g_PLAYER.nuke++;
				g_ENEMY[17].condition = dead;
				g_ENEMY[18].condition = dead;
				g_ENEMY[17].boss = no;
				g_ENEMY[18].boss = no;
				g_ENEMY[19].condition = dead;
				g_ENEMY[19].boss = no;
				g_PLAYER.mission = -5;
				g_time = -2360;

				g_ENEMY[17].SIZEwidth = 32;
				g_ENEMY[18].SIZEwidth = 32;
				g_ENEMY[19].SIZEwidth = 32;
				g_ENEMY[17].SIZEheight = 32;
				g_ENEMY[18].SIZEheight = 32;
				g_ENEMY[19].SIZEheight = 32;

				g_ENEMY[17].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[17].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[17].hBitmapThermalVision = enemyBMPth;
				g_ENEMY[18].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[18].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[18].hBitmapThermalVision = enemyBMPth;
				g_ENEMY[19].hBitmapNormal = enemyBMPnorm;
				g_ENEMY[19].hBitmapNightVision = enemyBMPnv;
				g_ENEMY[19].hBitmapThermalVision = enemyBMPth;
			}
			if (g_time > 2165 && g_time % 500 == 0)
			{
				for (int s = 0; s < 4; s++)
				{
					if (g_POWERUP[s].condition == dead)
					{
						g_POWERUP[s].script = scriptpowerup;
						g_POWERUP[s].scriptpos = -1;
						g_POWERUP[s].condition = alive;
						g_POWERUP[s].type = addhealth;
						g_POWERUP[s].change = no;
						g_POWERUP[s].position.x = gridalignment * rand1.RandInt(5,14);
						g_POWERUP[s].position.y = gridalignment * 0;
						SetSpriteState(&g_POWERUP[s], g_POWERUP[s].type);
						g_time++;break;
					}
				}	
			}
		}
		/*
			#define addlaser         0
			#define addmgun          1 
			#define addflame         2
			#define addpulse         3
			#define addhealth        4
			#define adddiagonallaser 5
			#define addsidelaser     6
			#define addmissile       7
			#define addnuke          8
			#define addcharge        9
			 -1 == random
		  
		  /*
		if (g_PLAYER.mission == 0)//mission1
		{

			create_enemy(50,  1, 1, no, 0, 0, no);
			if (g_time >= 2000 && g_ENEMY[17].condition != alive && g_ENEMY[18].condition != alive && g_ENEMY[19].condition!= alive)
			{
//FM				if(!music.Init("boss.mp3"))			
//FM				exit(1);
//FM				music.PlaySong();
				MUSIC_PLAYING = 2;

				g_ENEMY[17].boss = bossone;
				g_ENEMY[17].condition = alive;
				g_ENEMY[17].ship = 1;
				g_ENEMY[17].script = scriptbossone;
				g_ENEMY[17].scriptpos = -1;
				g_ENEMY[17].randomdirectionpicked = no;
				g_ENEMY[17].boss_condition = BOSSONEPIT;

				g_ENEMY[18].boss = bossone;
				g_ENEMY[18].condition = alive;
				g_ENEMY[18].ship = 1;
				g_ENEMY[18].script = scriptbossone;
				g_ENEMY[18].scriptpos = -1;
				g_ENEMY[18].randomdirectionpicked = no;
				g_ENEMY[18].boss_condition = BOSSONEWINGR;

				g_ENEMY[19].boss = bossone;
				g_ENEMY[19].condition = alive;
				g_ENEMY[19].ship = 1;
				g_ENEMY[19].script = scriptbossone;
				g_ENEMY[19].scriptpos = -1;
				g_ENEMY[19].randomdirectionpicked = no;
				g_ENEMY[19].boss_condition = BOSSONEWINGL;
			}
			
			if (g_time > 2000 && g_ENEMY[17].condition == dead && g_ENEMY[17].boss == bossone)
			{
				g_ENEMY[17].boss = no;
				g_ENEMY[18].boss = no;
				g_ENEMY[19].boss = no;
				g_PLAYER.mission = 1;
				g_time = -450;
			}
		}
		*/
		if (g_PLAYER.mission == -5)
		{
			g_PLAYER.position.y = offscreen;
			g_PLAYER.condition = alive;
		}
		if (g_PLAYER.mission == 0)
		{
			if (g_time == 0)
			{
				for (int x = 0; x < maxally; x++)
				{
					if (g_ALLY[x].condition != alive)
					{
						g_ALLY[x].condition = alive;
						g_ALLY[x].health = 10;
						g_HEAD[x+1].condition = spawning;
						g_time++;
						g_time++;
						g_ALLY[x].formation_type = wedgeformation;
						break;
					}
					else
					{
						g_ALLY[x].health = 10;
					}
				}
			}
			//time ship script sway L R special
			create_enemy(50,  1, 0, no, 0, 0, no);
			create_enemy(75,  1, 0, no, 0, 0, no);
			create_enemy(100,  1, 0, no, 0, 0, no);
			create_enemy(125,  1, 0, no, 0, 0, no);
			create_enemy(150,  1, 0, no, 0, 0, no);
			create_enemy(175,  1, 0, no, 0, 0, no);
			create_enemy(200,  1, 0, no, 0, 0, no);
			create_enemy(225,  2, 1, no, 0, 0, no);
			create_enemy(250,  2, 2, no, 0, 0, no);
			create_enemy(275,  1, 1, no, 0, 0, no);
			create_enemy(300,  1, 2, no, 0, 0, no);
			create_enemy(325,  1, 0, no, 0, 0, no);
			create_enemy(350,  1, 0, no, 0, 0, no);
			create_enemy(375,  1, 1, no, 0, 0, no);
			create_enemy(400,  1, 2, no, 0, 0, no);
			if (g_time == 400)
			{
				power_up(addhealth);
			}
			create_enemy(425,  1, 1, no, 0, 0, no);
			create_enemy(450,  1, 2, no, 0, 0, no);
			create_enemy(500,  13, 0, no, 0, 0, no);
			create_enemy(525,  13, 0, no, 0, 0, no);
			create_enemy(550,  13, 0, no, 0, 0, no);
			create_enemy(575,  13, 0, no, 0, 0, no);
			create_enemy(600,  13, 1, no, 0, 0, no);
			create_enemy(625,  13, 2, no, 0, 0, no);
			create_enemy(650,  13, 1, no, 0, 0, no);
			create_enemy(675,  13, 2, no, 0, 0, no);
			create_enemy(700,  2, 1, no, 0, 0, no);
			create_enemy(715,  1, 0, no, 0, 0, no);
			create_enemy(725,  2, 2, no, 0, 0, no);
			create_enemy(735,  1, 0, no, 0, 0, no);
			create_enemy(750,  2, 1, no, 0, 0, no);
			create_enemy(775,  2, 2, no, 0, 0, no);
			create_enemy(800,  13, 0, no, 0, 0, no);
			create_enemy(820,  13, 0, no, 0, 0, no);
			create_enemy(840,  13, 0, no, 0, 0, no);
			create_enemy(860,  13, 0, no, 0, 0, no);
			create_enemy(900,  13, 1, no, 0, 0, no);
			create_enemy(920,  13, 2, no, 0, 0, no);
			create_enemy(940,  13, 1, no, 0, 0, no);
			create_enemy(960,  13, 2, no, 0, 0, no);
			if (g_time == 960)
			{
				power_up(addhealth);
			}
			create_enemy(1050,  1, 2, no, 0, 0, no);
			create_enemy(1075,  1, 2, no, 0, 0, no);
			create_enemy(1100,  1, 2, no, 0, 0, no);
			create_enemy(1125,  1, 2, no, 0, 0, no);
			create_enemy(1135,  2, 0, no, 0, 0, no);
			create_enemy(1150,  1, 2, no, 0, 0, no);
			create_enemy(1175,  1, 2, no, 0, 0, no);
			create_enemy(1200,  1, 2, no, 0, 0, no);
			create_enemy(1225,  2, 1, no, 0, 0, no);
			create_enemy(1235,  2, 0, no, 0, 0, no);
			create_enemy(1250,  2, 2, no, 0, 0, no);
			create_enemy(1275,  1, 1, no, 0, 0, no);
			create_enemy(1300,  1, 1, no, 0, 0, no);
			create_enemy(1325,  1, 1, no, 0, 0, no);
			create_enemy(1350,  1, 1, no, 0, 0, no);
			create_enemy(1365,  2, 0, no, 0, 0, no);
			create_enemy(1375,  1, 1, no, 0, 0, no);
			create_enemy(1400,  1, 1, no, 0, 0, no);
			create_enemy(1425,  2, 1, no, 0, 0, no);
			create_enemy(1450,  2, 2, no, 0, 0, no);
			create_enemy(1500,  13, 0, no, 0, 0, no);
			if (g_time == 1500)
			{
				power_up(addhealth);
			}
			create_enemy(1525,  13, 0, no, 0, 0, no);
			create_enemy(1550,  13, 0, no, 0, 0, no);
			create_enemy(1565,  3, 0, no, 0, 0, no);
			create_enemy(1575,  13, 0, no, 0, 0, no);
			create_enemy(1600,  13, 1, no, 0, 0, no);
			create_enemy(1625,  13, 2, no, 0, 0, no);
			create_enemy(1650,  13, 1, no, 0, 0, no);
			create_enemy(1675,  13, 2, no, 0, 0, no);
			create_enemy(1700,  2, 1, no, 0, 0, no);
			create_enemy(1715,  1, 0, no, 0, 0, no);
			create_enemy(1725,  2, 2, no, 0, 0, no);
			create_enemy(1735,  1, 0, no, 0, 0, no);
			create_enemy(1750,  2, 1, no, 0, 0, no);
			create_enemy(1765,  3, 0, no, 0, 0, no);
			create_enemy(1775,  2, 2, no, 0, 0, no);
			create_enemy(1800,  13, 1, no, 0, 0, no);
			if (g_time == 1800)
			{
				power_up(addhealth);
			}
			create_enemy(1820,  13, 2, no, 0, 0, no);
			create_enemy(1840,  13, 0, no, 0, 0, no);
			create_enemy(1860,  13, 0, no, 0, 0, no);
			create_enemy(1885,  3, 0, no, 0, 0, no);
			create_enemy(1900,  13, 1, no, 0, 0, no);
			create_enemy(1920,  13, 2, no, 0, 0, no);
			create_enemy(1940,  13, 1, no, 0, 0, no);
			create_enemy(1960,  13, 2, no, 0, 0, no);
			
			if (g_time > 2000)
			{
				g_PLAYER.mission = 1;
				g_time = -450;
			}
		}
		if (g_PLAYER.mission == 1)//headlight
		{
			if (g_time == 0)
				{
					PlaySound("lunar.wav", NULL, SND_FILENAME | SND_ASYNC);
					TALKING = yes;
				}
				if (g_time == 200)
				{
					TALKING = no;
				}
			if (g_time == 0)
			{
				if(g_PLAYER.nightvision == yes && g_PLAYER.darkmission == yes)
				{
					g_SCREEN[5].condition = alive;
					g_SCREEN[5].position.x = -479;
					g_SCREEN[5].position.y = -543;
					SetSpriteState(&g_SCREEN[5], 0);
					Sleep(50);
				}
				g_PLAYER.special = 0;
				g_PLAYER.darkmission = yes;
			}
			if (g_time == 0)
			{
				power_up(addlaser);
			}
			if (g_time == 15)
			{
				power_up(addhealth);
			}
			create_enemy(50,  1, 1, no, 0, 0, no);
			create_enemy(75,  1, 2, no, 0, 0, no);
			create_enemy(105, 1, 3, no, 0, 0, no);
			create_enemy(125, 1, 4, no, 0, 0, no);
			create_enemy(205, 1, 1, no, 0, 0, no);
			create_enemy(225, 1, 2, no, 0, 0, no);
			create_enemy(250, 2, 1, no, 0, 0, no);
			create_enemy(275, 2, 2, no, 0, 0, no);
			create_enemy(310, 3, 0, no, 0, 0, no);
			create_enemy(340, 2, 4, no, 0, 0, no);
			create_enemy(370, 2, 4, no, 0, 0, no);
			create_enemy(460, 2, 4, no, 0, 0, no);
			create_enemy(520, 2, 4, no, 0, 0, no);
			create_enemy(550, 2, 4, no, 0, 0, no);
			create_enemy(610, 2, 4, no, 0, 0, no);
			if (g_time == 610)
			{
				power_up(addhealth);
			}
			create_enemy(660, 1, 0, no, 0, 0, yes);
			create_enemy(685, 1, 0, no, 0, 0, yes);
			create_enemy(710, 1, 0, no, 0, 0, yes);
			create_enemy(735, 1, 0, no, 0, 0, yes);
			create_enemy(760, 1, 0, no, 0, 0, yes);
			create_enemy(785, 1, 0, no, 0, 0, yes);
			if (g_time == 761)
			{
				power_up(addhealth);
			}
			create_enemy(810, 2, 3, no, 0, 0, no);
			create_enemy(840, 2, 3, no, 0, 0, no);
			create_enemy(870, 2, 3, no, 0, 0, no);
			create_enemy(930, 2, 3, no, 0, 0, no);
			create_enemy(960, 2, 3, no, 0, 0, no);
			create_enemy(990, 2, 3, no, 0, 0, no);
			create_enemy(1080, 2, 3, no, 0, 0, no);
			if (g_time == 1080)
			{
				power_up(addhealth);
			}
			create_enemy(1110, 1, 0, no, 0, 0, no);
			create_enemy(1140, 1, 0, no, 0, 0, no);
			create_enemy(1170, 1, 0, no, 0, 0, no);

			if (g_time == 1210)
			{
				power_up(addhealth);
			}
			create_enemy(1310, 13, 0, no, 0, 0, no);
			create_enemy(1340, 13, 0, no, 0, 0, no);
			create_enemy(1410, 13, 1, no, 0, 0, no);
			create_enemy(1440, 13, 1, no, 0, 0, no);
			if (g_time == 1471)
			{
				power_up(addhealth);
			}
			create_enemy(1510, 13, 3, no, 0, 0, no);
			create_enemy(1540, 13, 4, no, 0, 0, no);
			if (g_time == 1571)
			{
				power_up(addhealth);
			}
			create_enemy(1630, 3, 0, no, 0, 0, no);
			create_enemy(1730, 3, 0, no, 0, 0, no);
			create_enemy(1810, 1, 1, no, 0, 0, no);
			create_enemy(1825, 1, 1, no, 0, 0, no);
			create_enemy(1855, 1, 1, no, 0, 0, no);
			create_enemy(1870, 1, 1, no, 0, 0, no);
			create_enemy(1885, 1, 1, no, 0, 0, no);
			create_enemy(1910, 1, 2, no, 0, 0, no);
			create_enemy(1925, 1, 2, no, 0, 0, no);
			create_enemy(1940, 1, 2, no, 0, 0, no);
			create_enemy(1970, 1, 2, no, 0, 0, no);
			create_enemy(1985, 1, 2, no, 0, 0, no);
			create_enemy(2010, 3, 3, no, 0, 0, no);
			create_enemy(2110, 3, 4, no, 0, 0, no);
			if (g_PLAYER.special >= 6)
			{
				g_PLAYER.special = 0;
				power_up(-1);
			}
			if (g_time >= 2140)
			{
				g_time = -450;
				g_PLAYER.mission = 2;
				g_PLAYER.special = 0;
				g_PLAYER.darkmission = no;  
				if (g_time == 0)
				{
					PlaySound("nolunar.wav", NULL, SND_FILENAME | SND_ASYNC);
					TALKING = yes;
				}
				g_SCREEN[4].condition = no;
				g_SCREEN[4].position.y = -900;
				g_SCREEN[4].position.x = -900;
				g_SCREEN[3].condition = dead;
				g_SCREEN[3].position.y = -900;
				g_SCREEN[3].position.x = -900;
			}
	
		}
		if (g_PLAYER.mission == 3)
		{
			if (g_ALLY[0].condition == alive)
			{
				g_ALLY[0].formation_type = breakformation;
				g_ALLY[0].temp_formation = breakformation;
				g_ALLY[0].position.y-=allyspeed;
			}
			if (g_ALLY[0].position.y <= -28)
			{
				g_ALLY[0].condition = dead;
				g_ALLY[0].position.y = -40;
			}
			if (g_time == -200)
			{
				TALKING = no;
			}
			if (g_time == 0)
			{
				power_up(addmgun);
			}
			if (g_time == 15)
			{
				power_up(addhealth);
			}
			create_enemy(25, 3, 0, no, 0, 0, no);
			create_enemy(50, 3, 0, no, 0, 0, no);
			create_enemy(75, 13, 4, no, 0, 0, no);
			create_enemy(95, 13, 4, no, 0, 0, no);
			create_enemy(105, 13, 4, no, 0, 0, no);
			create_enemy(115, 13, 4, no, 0, 0, no);
			create_enemy(125, 13, 4, no, 0, 0, no);
			create_enemy(135, 13, 4, no, 0, 0, no);
			create_enemy(145, 13, 4, no, 0, 0, no);
			create_enemy(165, 13, 4, no, 0, 0, no);
			create_enemy(210, 3, 0, no, 0, 0, no);
			create_enemy(220, 13, 4, no, 0, 0, no);
			create_enemy(240, 13, 4, no, 0, 0, no);
			create_enemy(260, 13, 3, no, 0, 0, no);
			create_enemy(280, 13, 3, no, 0, 0, no);
			create_enemy(300, 13, 3, no, 0, 0, no);
			create_enemy(340, 13, 3, no, 0, 0, no);
			create_enemy(360, 13, 3, no, 0, 0, no);
			create_enemy(380, 13, 3, no, 0, 0, no);
			create_enemy(450, 13, 4, no, 0, 0, no);
			create_enemy(460, 13, 4, no, 0, 0, no);
			create_enemy(480, 13, 4, no, 0, 0, no);
			create_enemy(500, 13, 4, no, 0, 0, no);
			if (g_time == 500)
			{
				power_up(addhealth);
			}
			create_enemy(520, 13, 4, no, 0, 0, no);
			create_enemy(530, 3,  0, no, 0, 0, no);
			create_enemy(540, 13, 4, no, 0, 0, no);
			create_enemy(560, 13, 4, no, 0, 0, no);
			create_enemy(580, 13, 4, no, 0, 0, no);
			create_enemy(600, 13, 4, no, 0, 0, no);
			create_enemy(610, 4,  0, no, 0, 0, no);
			create_enemy(620, 2,  1, no, 0, 0, no);
			create_enemy(630, 2,  2, no, 0, 0, no);
			create_enemy(640, 2,  1, no, 0, 0, no);
			create_enemy(650, 2,  2, no, 0, 0, no);
			create_enemy(660, 2,  1, no, 0, 0, no);
			create_enemy(670, 2,  2, no, 0, 0, no);
			create_enemy(680, 2,  1, no, 0, 0, no);
			create_enemy(690, 2,  2, no, 0, 0, no);
			create_enemy(700, 4,  0, no, 0, 0, no);
			create_enemy(800, 3,  0, no, 0, 0, no);
			create_enemy(820, 1,  1, no, 0, 0, no);
			create_enemy(830, 1,  2, no, 0, 0, no);
			create_enemy(840, 1,  1, no, 0, 0, no);
			create_enemy(870, 1,  2, no, 0, 0, no);
			create_enemy(880, 1,  1, no, 0, 0, no);
			create_enemy(890, 1,  2, no, 0, 0, no);
			create_enemy(900, 3,  0, no, 0, 0, no);
			create_enemy(1000, 5,  0, no, 0, 0, no);
			if (g_time == 1000)
			{
				power_up(addhealth);
			}
			create_enemy(1100, 5,  0, no, 0, 0, no);
			create_enemy(1200, 4,  0, no, 0, 0, no);
			create_enemy(1220, 2,  1, no, 0, 0, no);
			create_enemy(1240, 2,  1, no, 0, 0, no);
			create_enemy(1260, 2,  1, no, 0, 0, no);
			create_enemy(1280, 2,  1, no, 0, 0, no);
			create_enemy(1330, 2,  2, no, 0, 0, no);
			create_enemy(1350, 2,  2, no, 0, 0, no);
			create_enemy(1370, 2,  2, no, 0, 0, no);
			create_enemy(1390, 2,  2, no, 0, 0, no);
			create_enemy(1400, 4,  0, no, 0, 0, no);
			create_enemy(1500, 5,  0, no, 0, 0, no);
			create_enemy(1525, 4,  0, no, 0, 0, no);
			if (g_time == 1500)
			{
				power_up(addhealth);
			}
			create_enemy(1600, 5,  0, no, 0, 0, no);
			create_enemy(1625, 4,  0, no, 0, 0, no);
			create_enemy(1700, 4,  0, no, 0, 0, no);
			create_enemy(1725, 2,  1, no, 0, 0, no);
			create_enemy(1726, 2,  2, no, 0, 0, no);
			create_enemy(1750, 3,  0, no, 0, 0, no);
			create_enemy(1800, 5,  0, no, 0, 0, no);
			create_enemy(1850, 3,  0, no, 0, 0, no);
			create_enemy(1875, 2,  1, no, 0, 0, no);
			create_enemy(1875, 2,  2, no, 0, 0, no);
			create_enemy(1900, 4,  0, no, 0, 0, no);
			create_enemy(1950, 3,  0, no, 0, 0, no);


			if (g_time > 2100)
			{
				g_PLAYER.mission = 4;
				g_time = -450;
			}
		}
		if (g_PLAYER.mission == 4)//rescue
		{
			if (g_time == 0)
			{
				g_PLAYER.time_left = 5200;
				g_PLAYER.special = 0;
				g_PLAYER.rescue_mission_loop_count = 0;
				power_up(addhealth);
			}
			if (g_time == 15)
			{
				power_up(addpulse);
			}

			if (g_PLAYER.rescue_mission_loop_count == 0)
			{
				create_enemy(50,  13, 0, no, 0, 0, yes);
				create_enemy(60,  13, 0, no, 0, 0, yes);
				create_enemy(70,  13, 0, no, 0, 0, yes);
				create_enemy(80,  13, 0, no, 0, 0, yes);
				create_enemy(90,  13, 0, no, 0, 0, yes);
				create_enemy(100,  13, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 1)
			{
				create_enemy(50,  13, 2, no, 0, 0, yes);
				create_enemy(60,  13, 2, no, 0, 0, yes);
				create_enemy(70,  13, 2, no, 0, 0, yes);
				create_enemy(80,  13, 2, no, 0, 0, yes);
				create_enemy(90,  13, 2, no, 0, 0, yes);
				create_enemy(100,  13, 2, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 2)
			{
				create_enemy(50,  13, 1, no, 0, 0, yes);
				create_enemy(60,  13, 1, no, 0, 0, yes);
				create_enemy(70,  13, 1, no, 0, 0, yes);
				create_enemy(80,  13, 1, no, 0, 0, yes);
				create_enemy(90,  13, 1, no, 0, 0, yes);
				create_enemy(100,  13, 1, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 3)
			{
				create_enemy(50,  13, 1, no, 0, 0, yes);
				create_enemy(51,  13, 2, no, 0, 0, yes);
				create_enemy(75,  13, 1, no, 0, 0, yes);
				create_enemy(76,  13, 2, no, 0, 0, yes);
				create_enemy(100,  13, 1, no, 0, 0, yes);
				create_enemy(101,  13, 2, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 4)
			{
				create_enemy(50,  13, 3, no, 0, 0, yes);
				create_enemy(51,  13, 4, no, 0, 0, yes);
				create_enemy(75,  13, 3, no, 0, 0, yes);
				create_enemy(76,  13, 4, no, 0, 0, yes);
				create_enemy(100,  13, 3, no, 0, 0, yes);
				create_enemy(101,  13, 4, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 5)
			{
				create_enemy(50,  13, 1, no, 0, 0, yes);
				create_enemy(51,  13, 2, no, 0, 0, yes);
				create_enemy(75,  13, 3, no, 0, 0, yes);
				create_enemy(76,  13, 4, no, 0, 0, yes);
				create_enemy(100,  13, 0, no, 0, 0, yes);
				create_enemy(101,  13, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 6)
			{
				create_enemy(50,  1, 1, no, 0, 0, yes);
				create_enemy(51,  1, 2, no, 0, 0, yes);
				create_enemy(75,  1, 3, no, 0, 0, yes);
				create_enemy(76,  1, 4, no, 0, 0, yes);
				create_enemy(100,  3, 0, no, 0, 0, yes);
				create_enemy(101,  3, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 7)
			{
				create_enemy(50,  1, 1, no, 0, 0, yes);
				create_enemy(51,  1, 2, no, 0, 0, yes);
				create_enemy(75,  2, 3, no, 0, 0, yes);
				create_enemy(76,  2, 4, no, 0, 0, yes);
				create_enemy(100,  3, 0, no, 0, 0, yes);
				create_enemy(101,  3, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 8)
			{
				create_enemy(50,  1, 3, no, 0, 0, yes);
				create_enemy(51,  1, 4, no, 0, 0, yes);
				create_enemy(75,  1, 3, no, 0, 0, yes);
				create_enemy(76,  1, 4, no, 0, 0, yes);
				create_enemy(100,  1, 1, no, 0, 0, yes);
				create_enemy(201,  5, 2, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 9)
			{
				create_enemy(50,  1, 3, no, 0, 0, yes);
				create_enemy(75,  1, 4, no, 0, 0, yes);
				create_enemy(100,  2, 3, no, 0, 0, yes);
				create_enemy(125,  2, 4, no, 0, 0, yes);
				create_enemy(150,  2, 1, no, 0, 0, yes);
				create_enemy(201,  4, 2, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 10)
			{
				create_enemy(50,  2, 3, no, 0, 0, yes);
				create_enemy(75,  2, 3, no, 0, 0, yes);
				create_enemy(100,  2, 3, no, 0, 0, yes);
				create_enemy(125,  3, 3, no, 0, 0, yes);
				create_enemy(150,  4, 3, no, 0, 0, yes);
				create_enemy(201,  4, 3, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 11)
			{
				create_enemy(50,  2, 4, no, 0, 0, yes);
				create_enemy(75,  2, 4, no, 0, 0, yes);
				create_enemy(100,  2, 4, no, 0, 0, yes);
				create_enemy(125,  3, 4, no, 0, 0, yes);
				create_enemy(150,  4, 4, no, 0, 0, yes);
				create_enemy(201,  4, 4, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 12)
			{
				create_enemy(50,  1, 0, no, 0, 0, yes);
				create_enemy(51,  1, 0, no, 0, 0, yes);
				create_enemy(52,  1, 0, no, 0, 0, yes);
				create_enemy(53,  2, 0, no, 0, 0, yes);
				create_enemy(54,  3, 0, no, 0, 0, yes);
				create_enemy(55,  3, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 13)
			{
				create_enemy(50,  4, 1, no, 0, 0, yes);
				create_enemy(51,  2, 2, no, 0, 0, yes);
				create_enemy(75,  1, 1, no, 0, 0, yes);
				create_enemy(75,  1, 2, no, 0, 0, yes);
				create_enemy(54,  1, 3, no, 0, 0, yes);
				create_enemy(55,  1, 4, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 14)
			{
				create_enemy(50,  5, 3, no, 0, 0, yes);
				create_enemy(51,  2, 4, no, 0, 0, yes);
				create_enemy(100,  1, 1, no, 0, 0, yes);
				create_enemy(100,  1, 2, no, 0, 0, yes);
				create_enemy(75,  1, 3, no, 0, 0, yes);
				create_enemy(75,  1, 4, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 15)
			{
				create_enemy(50,  5, 3, no, 0, 0, yes);
				create_enemy(75,  1, 4, no, 0, 0, yes);
				create_enemy(75,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.rescue_mission_loop_count == 16)
			{
				create_enemy(50,  7, 0, no, 0, 0, yes);
				create_enemy(75,  1, 0, no, 0, 0, yes);
				create_enemy(75,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
				create_enemy(100,  1, 0, no, 0, 0, yes);
			}
			if (g_PLAYER.special == 6 && g_PLAYER.rescue_mission_loop_count == 4)
			{
				power_up(addhealth);
			}
			if (g_PLAYER.special == 6 && g_PLAYER.rescue_mission_loop_count == 8)
			{
				power_up(addhealth);
			}
			if (g_PLAYER.special == 6 && g_PLAYER.rescue_mission_loop_count == 12)
			{
				power_up(addhealth);
			}
			if (g_time >= 200 && g_PLAYER.rescue_mission_loop_count <= 7 && g_PLAYER.special < 6)
			{
				g_time = 31;
			}
			if (g_time >= 300 && g_PLAYER.rescue_mission_loop_count > 7 && g_PLAYER.rescue_mission_loop_count < 17&& g_PLAYER.special < 6)
			{
				g_time = 31;
			}

			if (g_PLAYER.special >= 6)
			{
				g_PLAYER.special = 0;
				g_PLAYER.rescue_mission_loop_count++;
			}

			if (g_PLAYER.time_left <= 0 && g_PLAYER.rescue_mission_loop_count < 17 && g_time >= 0)
			{
				g_PLAYER.health = 0;
			}
			if (g_PLAYER.rescue_mission_loop_count >= 17)
			{
				g_PLAYER.darkmission = no;
				if (g_ALLY[0].condition != alive)
				{
					g_ALLY[0].position.y = 0;
					g_ALLY[0].position.x = 0;
					g_ALLY[0].condition = alive;
					g_ALLY[0].formation_type = lineformation;
					g_ALLY[0].formation_range = 32;
					g_ALLY[0].temp_formation = lineformation;
					g_ALLY[0].health = 10;
					g_time++;
				}
				if (g_time >= 700)
				{
					g_time = 0;
					g_PLAYER.mission = 5;
				}
			}
			if (g_PLAYER.time_left >= 0 && g_time >= 0)
			{
				g_PLAYER.time_left--;
			}
		}

		if (g_PLAYER.mission == 6)
		{
			if (g_ALLY[0].condition == alive)
			{
				g_ALLY[0].formation_type = breakformation;
				g_ALLY[0].temp_formation = breakformation;
				g_ALLY[0].position.y-=allyspeed;
			}
			if (g_ALLY[0].position.y <= -28)
			{
				g_ALLY[0].condition = dead;
				g_ALLY[0].position.y = -40;
			}
			if (g_time == 0)
			{
				power_up(addflame);
			}
			if (g_time == 15)
			{
				power_up(addhealth);
			}

			create_enemy(50,  6, 3, no, 0, 0, no);
			create_enemy(80,  6, 4, no, 0, 0, no);
			create_enemy(120 ,  7, 3, no, 0, 0, no);
			create_enemy(160,  7, 4, no, 0, 0, no);
			create_enemy(200 , 12, 3, no, 0, 0, no);
			create_enemy(200,  12, 4, no, 0, 0, no);
			create_enemy(215 , 12, 3, no, 0, 0, no);
			create_enemy(215,  12, 4, no, 0, 0, no);
			create_enemy(230 , 12, 3, no, 0, 0, no);
			create_enemy(230,  12, 4, no, 0, 0, no);
			create_enemy(245 , 12, 3, no, 0, 0, no);
			create_enemy(245,  12, 4, no, 0, 0, no);
			create_enemy(260 , 4, 0, no, 0, 0, no);
			create_enemy(260,  4, 0, no, 0, 0, no);
			create_enemy(300 , 12, 6, no, 0, 0, no);
			create_enemy(310,  12, 6, no, 0, 0, no);
			create_enemy(320 , 12, 6, no, 0, 0, no);
			create_enemy(330,  12, 6, no, 0, 0, no);
			create_enemy(340 , 12, 6, no, 0, 0, no);
			create_enemy(350,  12, 6, no, 0, 0, no);
			create_enemy(360 , 12, 6, no, 0, 0, no);
			create_enemy(370,  12, 6, no, 0, 0, no);
			create_enemy(400 , 4, 1, no, 0, 0, no);
			create_enemy(400,  4, 2, no, 0, 0, no);
			create_enemy(400,  5, 0, no, 0, 0, no);
			create_enemy(470 , 1, 6, no, 0, 0, no);
			create_enemy(485,  1, 6, no, 0, 0, no);
			create_enemy(500 , 1, 6, no, 0, 0, no);
			create_enemy(515,  1, 6, no, 0, 0, no);
			if (g_time == 520)
			{
				power_up(addhealth);
			}
			create_enemy(570 , 4, 3, no, 0, 0, no);
			create_enemy(570,  4, 4, no, 0, 0, no);
			create_enemy(570 , 13, 6, no, 0, 0, no);
			create_enemy(580,  13, 6, no, 0, 0, no);
			create_enemy(590 , 13, 6, no, 0, 0, no);
			create_enemy(600,  13, 6, no, 0, 0, no);
			create_enemy(610 , 1, 6, no, 0, 0, no);
			create_enemy(620,  1, 6, no, 0, 0, no);
			create_enemy(630 , 1, 6, no, 0, 0, no);
			create_enemy(640,  1, 6, no, 0, 0, no);
			create_enemy(650 , 2, 6, no, 0, 0, no);
			create_enemy(660,  2, 6, no, 0, 0, no);
			create_enemy(670 , 2, 6, no, 0, 0, no);
			create_enemy(680,  2, 6, no, 0, 0, no);
			create_enemy(690 , 3, 6, no, 0, 0, no);
			create_enemy(700,  3, 6, no, 0, 0, no);
			create_enemy(710 , 3, 6, no, 0, 0, no);
			create_enemy(720,  3, 6, no, 0, 0, no);
			create_enemy(820,  6, 0, no, 0, 0, no);
			create_enemy(820,  6, 0, no, 0, 0, no);
			create_enemy(820,  1, 6, no, 0, 0, no);
			create_enemy(820,  1, 6, no, 0, 0, no);
			create_enemy(850,  1, 0, no, 0, 0, no);
			create_enemy(850,  1, 0, no, 0, 0, no);
			create_enemy(900,  1, 0, no, 0, 0, no);
			create_enemy(950,  7, 0, no, 0, 0, no);
			if (g_time == 950)
			{
				power_up(addhealth);
				power_up(addnuke);
			}
			create_enemy(1050,  6, 1, no, 0, 0, no);
			create_enemy(1070,  6, 2, no, 0, 0, no);
			create_enemy(1090,  1, 3, no, 0, 0, no);
			create_enemy(1110,  1, 4, no, 0, 0, no);
			create_enemy(1225,  5 , 0, no, 0, 0, no);
			create_enemy(1225,  3, 0, no, 0, 0, no);
			create_enemy(1280,  1, 0, no,  0, 0, no);
	 		create_enemy(1285,  1, 0, no, 0, 0, no);
 			create_enemy(1320,  5, 0, no, 0, 0, no);
			create_enemy(1325,  5, 0, no, 0, 0, no);
			create_enemy(1350,  2, 1, no, 0, 0, no);
			create_enemy(1375,  4, 2, no, 0, 0, no);
			create_enemy(1400,  4, 3, no, 0, 0, no);
			create_enemy(1425,  2, 4, no, 0, 0, no);
			create_enemy(1475,  2          , 1, no, 0, 0, no);
			create_enemy(1500,  5, 2, no, 0, 0, no);
			if (g_time == 1500)
			{
				power_up(addhealth);
			}
				create_enemy(1600,  7, 0, no, 0, 0, no);
				create_enemy(1610,  1, 0, no, 0, 0, no);
				create_enemy(1610,  1, 0, no, 0, 0, no);
				create_enemy(1630,  1, 0, no, 0, 0, no);
				create_enemy(1630,  1, 0, no, 0, 0, no);
				create_enemy(1670,  5, 0, no, 0, 0, no);
				create_enemy(1700,  6, 0, no, 0, 0, no);
				create_enemy(1725,  6, 0, no, 0, 0, no);
				create_enemy(1750,  7, 0, no, 0, 0, no);
				create_enemy(1750 , 2, 6, no, 0, 0, no);
				create_enemy(1760,  2, 6, no, 0, 0, no);
				create_enemy(1770 , 2, 6, no, 0, 0, no);
				create_enemy(1775,  7, 0, no, 0, 0, no);
				create_enemy(1780,  2, 6, no, 0, 0, no);
				create_enemy(1790 , 3, 6, no, 0, 0, no);
				create_enemy(1800,  3, 6, no, 0, 0, no);
				create_enemy(1810 , 3, 6, no, 0, 0, no);
				create_enemy(1820,  3, 6, no, 0, 0, no);
				create_enemy(1850,  7, 5, no, 0, 0, no);
				create_enemy(1875,  5, 5, no, 0, 0, no);
				create_enemy(1900,  6, 5, no, 0, 0, no);
				if (g_time == 1900)
			{
				power_up(addhealth);
			}

			if (g_time > 2000)
			{
				g_PLAYER.mission = 7;
				g_time = -450;
			}
		}
	
		if (g_PLAYER.mission == 7)//NV
		{
			if (g_time == 0)
			{
				power_up(adddiagonallaser);
				g_PLAYER.darkmission = yes;
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			create_enemy(50, 7, 1, no, 5, 0, no);
			create_enemy(100, 7, 2, no, 5, 0, no);
			create_enemy(150, 8, 1, no, 5, 0, no);
			create_enemy(200, 8, 2, no, 5, 0, no);
			create_enemy(250, 9, 0, no, 5, 0, no);
			create_enemy(250, 10, 0, no, 5, 0, no);
			create_enemy(300, 3, 1, no, 5, 0, no);
			create_enemy(320, 3, 2, no, 5, 0, no);
			create_enemy(340, 2, 1, no, 5, 0, no);
			create_enemy(360, 2, 2, no, 5, 0, no);
			create_enemy(400, 4, 1, no, 5, 0, no);
			create_enemy(420, 4, 2, no, 5, 0, no);
			create_enemy(440, 2, 1, no, 5, 0, no);
			create_enemy(460, 2, 2, no, 5, 0, no);
			create_enemy(500, 7, 1, no, 5, 0, no);
			create_enemy(580, 6, 0, no, 5, 0, no);
			create_enemy(620, 7, 1, no, 5, 0, no);
			create_enemy(670, 4, 5, no, 5, 0, no);
			create_enemy(720, 7, 2, no, 5, 0, no);
			create_enemy(780, 4, 5, no, 5, 0, no);
			create_enemy(800, 8, 5, no, 5, 0, no);
			create_enemy(820, 4, 5, no, 5, 0, no);
			if (g_time == 840)
			{
				power_up(addnuke);
			}
			if (g_time == 850 || g_time == 1610)
			{
				power_up(addhealth);
			}
			if (g_time == 0 || g_time == 550 || g_time == 1100 || g_time == 1600)
			{
				power_up(addbattery);
			}
			create_enemy(900, 9, 7, no, 5, 0, no);
			create_enemy(920, 9, 8, no, 5, 0, no);
			create_enemy(940, 2, 9, no, 5, 0, no);
			create_enemy(960, 2, 10, no, 5, 0, no);
			create_enemy(1000, 9, 1, no, 5, 0, no);
			create_enemy(1020, 9, 2, no, 5, 0, no);
			create_enemy(1040, 2, 3, no, 5, 0, no);
			create_enemy(1060, 2, 4, no, 5, 0, no);
			create_enemy(1200, 2, 0, no, 5, 0, no);
			create_enemy(1250, 8, 1, no, 5, 0, no);
			create_enemy(1300, 8, 2, no, 5, 0, no);
			create_enemy(1350, 8, 1, no, 5, 0, no);
			create_enemy(1400, 8, 2, no, 5, 0, no);
			create_enemy(1450, 7, 5, no, 5, 0, no);
			create_enemy(1490, 5, 5, no, 5, 0, no);
			create_enemy(1500, 13, 6, no, 5, 0, no);
			create_enemy(1510, 13, 6, no, 5, 0, no);
			create_enemy(1520, 13, 6, no, 5, 0, no);
			create_enemy(1530, 13, 6, no, 5, 0, no);
			create_enemy(1540, 13, 6, no, 5, 0, no);
			create_enemy(1550, 13, 6, no, 5, 0, no);
			create_enemy(1560, 13, 6, no, 5, 0, no);
			create_enemy(1570, 13, 6, no, 5, 0, no);
			create_enemy(1580, 13, 6, no, 5, 0, no);
			create_enemy(1590, 13, 6, no, 5, 0, no);
			create_enemy(1650, 3, 1, no, 5, 0, no);
			create_enemy(1675, 3, 2, no, 5, 0, no);
			create_enemy(1700, 4, 1, no, 5, 0, no);
			create_enemy(1725, 4, 2, no, 5, 0, no);
			create_enemy(1750, 4, 1, no, 5, 0, no);
			create_enemy(1775, 4, 2, no, 5, 0, no);
			create_enemy(1800, 7, 1, no, 5, 0, no);
			create_enemy(1825, 7, 2, no, 5, 0, no);
			create_enemy(1850, 5, 1, no, 5, 0, no);
			create_enemy(1875, 5, 2, no, 5, 0, no);
			create_enemy(1900, 9, 5, no, 5, 0, no);
			create_enemy(1920, 8, 5, no, 5, 0, no);
			create_enemy(1940, 6, 5, no, 5, 0, no);
			create_enemy(1960, 4, 5, no, 5, 0, no);
			create_enemy(1980, 2, 5, no, 5, 0, no);
			create_enemy(2000, 2, 0, no, 5, 0, no);

			if (g_time >= 2100)
			{
				g_PLAYER.mission = 8;
				g_PLAYER.darkmission = no;
				g_time = -450;
			}
		}

		if (g_PLAYER.mission == 9)
		{
			if (g_time == -448)
			{
				PlaySound("ir.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = yes;
			}
			if (g_time == -200)
			{
				TALKING = no;
			}
			if (g_time == 0)
			{
				power_up(addmissile);
			}
			if (g_time == 15)
			{
				power_up(addnuke);
			}
			if (g_time == 30)
			{
				power_up(addhealth);
			}
			create_enemy(50,  6, 3, no, 0, 0, no);
			create_enemy(70,  6, 4, no, 0, 0, no);
			create_enemy(90,  2, 3, no, 0, 0, no);
			create_enemy(110,  2, 4, no, 0, 0, no);
			create_enemy(130,  7, 3, no, 0, 0, no);
			create_enemy(150,  7, 4, no, 0, 0, no);
			create_enemy(170,  9, 3, no, 0, 0, no);
			create_enemy(190,  9, 4, no, 0, 0, no);
			create_enemy(220,  4, 1, no, 0, 0, no);
			create_enemy(221,  4, 2, no, 0, 0, no);
			create_enemy(250,  6, 5, no, 0, 0, no);
			create_enemy(370,  7, 5, no, 0, 0, no);
			create_enemy(400, 8, 1, no, 5, 0, no);
			create_enemy(450, 8, 2, no, 5, 0, no);
			create_enemy(500, 8, 1, no, 5, 0, no);
			create_enemy(550, 8, 2, no, 5, 0, no);
			if (g_time == 550)
			{
				power_up(addhealth);
			}
			create_enemy(610, 13, 6, no, 5, 0, no);
			create_enemy(615, 13, 6, no, 5, 0, no);
			create_enemy(620, 13, 6, no, 5, 0, no);
			create_enemy(625, 13, 6, no, 5, 0, no);
			create_enemy(630, 13, 6, no, 5, 0, no);
			create_enemy(635, 13, 6, no, 5, 0, no);
			create_enemy(640, 13, 6, no, 5, 0, no);
			create_enemy(645, 13, 6, no, 5, 0, no);
			create_enemy(650, 13, 6, no, 5, 0, no);
			create_enemy(655, 13, 6, no, 5, 0, no);
			create_enemy(660, 13, 6, no, 5, 0, no);
			create_enemy(665, 13, 6, no, 5, 0, no);
			create_enemy(670, 13, 6, no, 5, 0, no);
			create_enemy(675, 13, 6, no, 5, 0, no);
			create_enemy(680, 13, 6, no, 5, 0, no);
			create_enemy(685, 13, 6, no, 5, 0, no);
			create_enemy(690, 13, 6, no, 5, 0, no);
			create_enemy(695, 13, 6, no, 5, 0, no);
			create_enemy(720, 9, 0, no, 5, 0, no);
			create_enemy(725, 10, 0, no, 5, 0, no);
			create_enemy(740, 9, 0, no, 5, 0, no);
			create_enemy(745, 10, 0, no, 5, 0, no);
			create_enemy(770, 3, 0, no, 5, 0, no);
			create_enemy(800, 4, 0, no, 5, 0, no);
			create_enemy(950, 3, 8, no, 5, 0, no);
			create_enemy(950, 3, 9, no, 5, 0, no);
			create_enemy(950, 3, 1, no, 5, 0, no);
			create_enemy(950, 3, 2, no, 5, 0, no);
			if (g_time == 1000)
			{
				power_up(addhealth);
			}
			create_enemy(1075, 4, 8, no, 5, 0, no);
			create_enemy(1075, 4, 9, no, 5, 0, no);
			create_enemy(1100, 4, 10, no, 5, 0, no);
			create_enemy(1100, 4, 11, no, 5, 0, no);
			create_enemy(1125, 2, 0, no, 5, 0, no);
			create_enemy(1150, 5, 5, no, 5, 0, no);
			create_enemy(1200, 4, 10, no, 5, 0, no);
			create_enemy(1200, 4, 11, no, 5, 0, no);
			create_enemy(1225, 2, 0, no, 5, 0, no);
			create_enemy(1250, 4, 3, no, 5, 0, no);
			create_enemy(1250, 4, 4, no, 5, 0, no);
			create_enemy(1300, 4, 3, no, 5, 0, no);
			create_enemy(1300, 4, 4, no, 5, 0, no);
			create_enemy(1325, 2, 0, no, 5, 0, no);
			create_enemy(1350, 13, 6, no, 5, 0, no);
			create_enemy(1350, 13, 6, no, 5, 0, no);
			create_enemy(1400, 8, 3, no, 5, 0, no);
			create_enemy(1400, 8, 4, no, 5, 0, no);
			create_enemy(1425, 2, 0, no, 5, 0, no);
			create_enemy(1500, 4, 1, no, 5, 0, no);
			create_enemy(1500, 4, 2, no, 5, 0, no);
			if (g_time == 1500)
			{
				power_up(addhealth);
				g_HUNTER.condition = alive;
				g_HUNTER.position.y = -32;
				g_HUNTER.position.x = g_PLAYER.position.x;
				g_HUNTER.hBitmapNormal = LoadABitmap("Phunter.bmp");
				g_HUNTER.hBitmapNightVision = LoadABitmap("PhunterNV.bmp");
				g_HUNTER.hBitmapThermalVision = LoadABitmap("PhunterTH.bmp");
				g_HUNTER.hBitmap = g_HUNTER.hBitmapNormal;
			}
			if (g_time >= 1500 && g_HUNTER.condition == alive)
			{
				g_HUNTER.position.y++;
				g_HUNTER.position.x = g_PLAYER.position.x;
			}
			if (g_HUNTER.position.y >= g_PLAYER.position.y)
			{
				fire_nuke();
				g_PLAYER.nuke++;
				g_PLAYER.hBitmapNormal=g_HUNTER.hBitmapNormal;
				g_PLAYER.hBitmapNightVision=g_HUNTER.hBitmapNightVision;
				g_PLAYER.hBitmapThermalVision=g_HUNTER.hBitmapThermalVision;
				g_PLAYER.hBitmap=g_HUNTER.hBitmap;

				g_HUNTER.position.y = offscreen-offscreen;
				g_HUNTER.position.x = offscreen-offscreen;
				g_HUNTER.condition = dead;

				g_PLAYER.maxhealth = 15;
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
				g_PLAYER.max_momentumX = (int) (156 / 8);
				g_PLAYER.max_momentumX = (int) (142 / 8);
				g_PLAYER.momentum_climb = (int) (36 / 8);
			}


			create_enemy(1550, 13, 6, no, 5, 0, no);
			create_enemy(1555, 13, 6, no, 5, 0, no);
			create_enemy(1560, 13, 6, no, 5, 0, no);
			create_enemy(1565, 13, 6, no, 5, 0, no);
			create_enemy(1570, 13, 6, no, 5, 0, no);
			create_enemy(1575, 13, 6, no, 5, 0, no);
			create_enemy(1580, 13, 6, no, 5, 0, no);
			create_enemy(1585, 13, 6, no, 5, 0, no);
			create_enemy(1590, 13, 6, no, 5, 0, no);
			create_enemy(1595, 13, 6, no, 5, 0, no);
			create_enemy(1600, 13, 6, no, 5, 0, no);
			create_enemy(1605, 13, 6, no, 5, 0, no);
			create_enemy(1610, 13, 6, no, 5, 0, no);
			create_enemy(1615, 13, 6, no, 5, 0, no);
			create_enemy(1620, 13, 6, no, 5, 0, no);
			create_enemy(1625, 13, 6, no, 5, 0, no);
			create_enemy(1630, 13, 6, no, 5, 0, no);
			create_enemy(1635, 13, 6, no, 5, 0, no);
			create_enemy(1630, 13, 6, no, 5, 0, no);
			create_enemy(1635, 13, 6, no, 5, 0, no);
			create_enemy(1675, 8, 1, no, 5, 0, no);
			create_enemy(1695, 8, 2, no, 5, 0, no);
			create_enemy(1755, 8, 3, no, 5, 0, no);
			create_enemy(1775, 8, 4, no, 5, 0, no);
			create_enemy(1795, 9, 0, no, 5, 0, no);
			create_enemy(1800, 10,0, no, 5, 0, no);
			create_enemy(1810, 10,0, no, 5, 0, no);
			create_enemy(1820, 10,0, no, 5, 0, no);
			create_enemy(1830, 10,0, no, 5, 0, no);
			create_enemy(1840, 10,0, no, 5, 0, no);
			create_enemy(1850, 10,0, no, 5, 0, no);
			create_enemy(1860, 10,0, no, 5, 0, no);
			create_enemy(1870, 10,0, no, 5, 0, no);
			create_enemy(1880, 10,0, no, 5, 0, no);
			create_enemy(1890, 10,0, no, 5, 0, no);
			create_enemy(1900, 10,1, no, 5, 0, no);
			create_enemy(1910, 10,2, no, 5, 0, no);
			create_enemy(1920, 10,2, no, 5, 0, no);
			create_enemy(1930, 10,1, no, 5, 0, no);
			create_enemy(1940, 10,2, no, 5, 0, no);
			if (g_time == 1950)
			{
				power_up(addhealth);
			}
			if (g_time > 2000)
			{
			
				g_PLAYER.mission = 10;
				g_time = -450;
			}
		}

		if (g_PLAYER.mission == 11)//escort
		{
			//////////NON ENEMY MISSION CRAP/////////////////
			if (g_time == 0)
			{
				power_up(addhealth);
				g_ESCORT.condition = 4;
				g_ESCORT.health = 30;
				g_ESCORT.position.y = gridalignment * 16;
				g_ESCORT.position.x = (int)(gridalignment * 7.5);
				SetSpriteState(&g_ESCORT, g_ESCORT.condition);
			}
			if (g_time % 10== 0 && g_time <= 80 && g_time >= 40)
			{
				for (int a = 0; a < maxally; a++)
				{
					if (g_ALLY[a].condition != alive)
					{
						g_ALLY[a].condition = alive;
						g_ALLY[a].health = 10;
						g_ALLY[a].formation_type = wedgeformation;
						g_ALLY[a].formation_range = maxcloseformation;
						g_ALLY[a].position.y = g_ESCORT.position.y + 15;
						g_ALLY[a].position.x = g_ESCORT.position.x + 8;
						break;
					}
				}  
			}      
			if (g_time == 2)
			{
				power_up(addsidelaser);
			}
			if (g_time == 150)
			{
				for (int a = 0; a < maxally; a++)
				{
					g_ALLY[a].formation_type = breakformation;
					g_ALLY[a].formation_range = attacking;
				}
			}
			if (g_time <= 105 && g_time >= 100 && g_ESCORT.condition != dead)
			{
				SetSpriteState(&g_ESCORT, g_ESCORT.condition);
				g_ESCORT.condition--;
				if (g_ESCORT.condition == dead)
				{
					SetSpriteState(&g_ESCORT, 0);
					g_ESCORT.condition = alive;
				}
			}
			if (g_time < 500 && g_ESCORT.position.y > gridalignment * 5 && g_ESCORT.condition != dead)
			{
				g_ESCORT.position.y-=2;
			}
			if (g_ESCORT.health <= 0 && g_time > 0)
			{
				g_PLAYER.health = 0;
			}
			if (g_time > 1900 && g_ESCORT.position.y >= -300 && g_ESCORT.condition != dead)
			{
				g_ESCORT.position.y-=2;
				for (int a = 0; a < maxally; a++)
				{
					if (g_ALLY[a].position.y >= -32)
					{
						g_ALLY[a].position.y -= allyspeed;
					}
					if (g_ALLY[a].position.y <= -32)
					{
						g_ALLY[a].condition = dead;
					}
				}
			}
			if (g_ESCORT.position.y < -290 && g_time > 0)
			{
				g_time = -450;
				g_PLAYER.mission = 12;
				g_ESCORT.condition = dead;
				g_ESCORT.position.y = -580;
				g_ESCORT.position.x = -580;
			}
			//////////END NON ENEMY MISSION CRAP/////////////////
			//          time SHP SPT SWY R L special
			create_enemy(150, 13, 0, yes, 5, 0, no);
			create_enemy(155, 13, 0, yes, 0, 5, no);
			create_enemy(160, 13, 0, yes, 5, 0, no);
			create_enemy(165, 13, 0, yes, 0, 5, no);
			create_enemy(170, 13, 0, yes, 5, 0, no);
			create_enemy(175, 13, 0, yes, 0, 5, no);
			create_enemy(180, 13, 0, yes, 5, 0, no);
			create_enemy(185, 13, 0, yes, 0, 5, no);
			create_enemy(190, 13, 0, yes, 5, 0, no);
			create_enemy(195, 13, 0, yes, 0, 5, no);
			create_enemy(200, 13, 0, yes, 5, 0, no);
			create_enemy(205, 13, 0, yes, 0, 5, no);

			create_enemy(210, 13, 1, no,  0, 0, no);
			create_enemy(215, 13, 1, no,  0, 0, no);
			create_enemy(220, 13, 1, no,  0, 0, no);
			create_enemy(225, 13, 1, no,  0, 0, no);
			create_enemy(230, 13, 1, no,  0, 0, no);
			create_enemy(235, 13, 1, no,  0, 0, no);
			create_enemy(240, 13, 1, no,  0, 0, no);
			create_enemy(245, 13, 1, no,  0, 0, no);
			create_enemy(250, 13, 1, no,  0, 0, no);
			create_enemy(255, 13, 1, no,  0, 0, no);
			create_enemy(260, 13, 1, no,  0, 0, no);
			create_enemy(265, 13, 1, no,  0, 0, no);
			create_enemy(270, 13, 1, no,  0, 0, no);
			create_enemy(275, 13, 1, no,  0, 0, no);
			create_enemy(280, 13, 1, no,  0, 0, no);
			create_enemy(285, 13, 1, no,  0, 0, no);
			create_enemy(290, 13, 1, no,  0, 0, no);
			create_enemy(295, 13, 1, no,  0, 0, no);

			create_enemy(310, 13, 2, no,  0, 0, no);
			create_enemy(315, 13, 2, no,  0, 0, no);
			create_enemy(320, 13, 2, no,  0, 0, no);
			create_enemy(325, 13, 2, no,  0, 0, no);
			create_enemy(330, 13, 2, no,  0, 0, no);
			create_enemy(335, 13, 2, no,  0, 0, no);
			create_enemy(340, 13, 2, no,  0, 0, no);
			create_enemy(345, 13, 2, no,  0, 0, no);
			create_enemy(350, 13, 2, no,  0, 0, no);
			create_enemy(355, 13, 2, no,  0, 0, no);
			create_enemy(360, 13, 2, no,  0, 0, no);
			create_enemy(365, 13, 2, no,  0, 0, no);
			create_enemy(370, 13, 2, no,  0, 0, no);
			create_enemy(375, 13, 2, no,  0, 0, no);
			create_enemy(380, 13, 2, no,  0, 0, no);
			create_enemy(385, 13, 2, no,  0, 0, no);
			create_enemy(390, 13, 2, no,  0, 0, no);
			create_enemy(395, 13, 2, no,  0, 0, no);

			create_enemy(450, 1, 0, yes, 5, 0, no);
			create_enemy(455, 1, 1, no, 0, 5, no);
			create_enemy(460, 1, 2, no, 5, 0, no);
			create_enemy(465, 1, 3, no, 0, 5, no);
			create_enemy(470, 1, 4, no, 5, 0, no);
			create_enemy(475, 1, 0, yes, 0, 5, no);
			create_enemy(480, 1, 1, no, 5, 0, no);
			create_enemy(485, 1, 2, no, 0, 5, no);
			create_enemy(490, 1, 3, no, 5, 0, no);
			create_enemy(495, 1, 4, no, 0, 5, no);

			create_enemy(550, 2, 0, yes, 5, 0, no);
			create_enemy(555, 2, 1, no, 0, 5, no);
			create_enemy(560, 2, 2, no, 5, 0, no);
			create_enemy(565, 2, 3, no, 0, 5, no);
			create_enemy(570, 2, 4, no, 5, 0, no);
			create_enemy(575, 2, 0, yes, 0, 5, no);
			create_enemy(580, 2, 1, no, 5, 0, no);
			create_enemy(585, 2, 2, no, 0, 5, no);
			create_enemy(590, 2, 3, no, 5, 0, no);
			create_enemy(595, 2, 4, no, 0, 5, no);

			create_enemy(650, 7, 1, no, 5, 0, no);
			create_enemy(650, 2, 2, no, 0, 5, no);
			create_enemy(655, 2, 1, no,  0, 0, no);
			create_enemy(655, 1, 2, no,  0, 0, no);
			create_enemy(660, 1, 3, no,  0, 0, no);
			create_enemy(660, 2, 4, no,  0, 0, no);
			create_enemy(670, 13, 0, no,  0, 0, no);
			create_enemy(670, 13, 0, no,  0, 0, no);

			if (g_time == 870)
			{
				power_up(addhealth);
			}

			create_enemy(1200, 13, 1, no, 5, 0, no);
			create_enemy(1200, 13, 2, no, 0, 5, no);
			create_enemy(1200, 13, 3, no, 5, 0, no);
			create_enemy(1200, 13, 4, no, 0, 5, no);
			create_enemy(1205, 3, 1, no, 5, 0, no);
			create_enemy(1205, 13, 2, no, 0, 5, no);
			create_enemy(1205, 13, 3, no, 5, 0, no);
			create_enemy(1205, 13, 4, no, 0, 5, no);
			create_enemy(1210, 3, 1, no, 5, 0, no);
			create_enemy(1210, 13, 2, no, 0, 5, no);
			create_enemy(1210, 13, 3, no, 5, 0, no);
			create_enemy(1210, 13, 4, no, 0, 5, no);
			create_enemy(1215, 3, 1, no, 5, 0, no);
			create_enemy(1215, 13, 2, no, 0, 5, no);
			create_enemy(1215, 13, 3, no, 5, 0, no);
			create_enemy(1215, 13, 4, no, 0, 5, no);

			create_enemy(1250, 13, 1, no, 5, 0, no);
			create_enemy(1250, 13, 2, no, 0, 5, no);
			create_enemy(1250, 13, 3, no, 5, 0, no);
			create_enemy(1250, 13, 4, no, 0, 5, no);
			create_enemy(1255, 13, 1, no, 5, 0, no);
			create_enemy(1255, 13, 2, no, 0, 5, no);
			create_enemy(1255, 13, 3, no, 5, 0, no);
			create_enemy(1255, 13, 4, no, 0, 5, no);
			create_enemy(1260, 13, 1, no, 5, 0, no);
			create_enemy(1260, 13, 2, no, 0, 5, no);
			create_enemy(1260, 13, 3, no, 5, 0, no);
			create_enemy(1260, 13, 4, no, 0, 5, no);
			create_enemy(1265, 4, 1, no, 5, 0, no);
			create_enemy(1265, 13, 2, no, 0, 5, no);
			create_enemy(1265, 13, 3, no, 5, 0, no);
			create_enemy(1265, 13, 4, no, 0, 5, no);

			create_enemy(1250, 4, 1, no, 5, 0, no);
			create_enemy(1250, 13, 2, no, 0, 5, no);
			create_enemy(1250, 13, 3, no, 5, 0, no);
			create_enemy(1250, 4, 4, no, 0, 5, no);
			create_enemy(1255, 13, 0, no, 5, 0, no);
			create_enemy(1255, 13, 0, no, 0, 5, no);
			create_enemy(1255, 13, 0, no, 5, 0, no);
			create_enemy(1255, 13, 0, no, 0, 5, no);
			create_enemy(1280, 1, 0, no, 5, 0, no);
			create_enemy(1280, 1, 0, no, 0, 5, no);
			create_enemy(1280, 1, 0, no, 5, 0, no);
			create_enemy(1280, 1, 0, no, 0, 5, no);
			create_enemy(1285, 1, 1, no, 5, 0, no);
			create_enemy(1285, 1, 2, no, 0, 5, no);
			create_enemy(1285, 1, 3, no, 5, 0, no);
			create_enemy(1285, 1, 4, no, 0, 5, no);

			create_enemy(1510, 2, 0, no, 5, 0, no);
			create_enemy(1510, 2, 0, no, 0, 5, no);
			create_enemy(1510, 2, 0, no, 5, 0, no);
			create_enemy(1510, 2, 0, no, 0, 5, no);
			create_enemy(1515, 9, 1, no, 5, 0, no);
			create_enemy(1515, 13, 2, no, 0, 5, no);
			create_enemy(1515, 13, 3, no, 5, 0, no);
			create_enemy(1515, 13, 4, no, 0, 5, no);
			create_enemy(1520, 9, 1, no, 5, 0, no);
			create_enemy(1520, 13, 2, no, 0, 5, no);
			create_enemy(1520, 13, 3, no, 5, 0, no);
			create_enemy(1520, 13, 4, no, 0, 5, no);

			if (g_time == 1520)
			{
				power_up(addhealth);
			}

			create_enemy(1710, 13, 0, no, 5, 0, no);
			create_enemy(1715, 13, 0, no, 5, 0, no);
			create_enemy(1720, 13, 0, no, 5, 0, no);
			create_enemy(1725, 13, 0, no, 5, 0, no);
			create_enemy(1730, 13, 0, no, 5, 0, no);
			create_enemy(1735, 13, 0, no, 5, 0, no);
			create_enemy(1740, 13, 0, no, 5, 0, no);
			create_enemy(1745, 13, 0, no, 5, 0, no);
			create_enemy(1750, 13, 0, no, 5, 0, no);
			create_enemy(1755, 13, 0, no, 5, 0, no);
			create_enemy(1760, 13, 0, no, 5, 0, no);
			create_enemy(1765, 13, 0, no, 5, 0, no);
			create_enemy(1770, 13, 0, no, 5, 0, no);
			create_enemy(1775, 13, 0, no, 5, 0, no);
			create_enemy(1780, 13, 0, no, 5, 0, no);
			create_enemy(1785, 13, 0, no, 5, 0, no);
			create_enemy(1790, 13, 0, no, 5, 0, no);
			create_enemy(1795, 13, 0, no, 5, 0, no);
			create_enemy(1800, 13, 0, no, 5, 0, no);
			create_enemy(1805, 13, 0, no, 5, 0, no);
			create_enemy(1810, 2, 1, no, 5, 0, no);
			create_enemy(1815, 2, 1, no, 5, 0, no);
			create_enemy(1820, 2, 2, no, 5, 0, no);
			create_enemy(1825, 2, 2, no, 5, 0, no);
			create_enemy(1830, 2, 1, no, 5, 0, no);
			create_enemy(1835, 2, 2, no, 5, 0, no);
			create_enemy(1840, 2, 3, no, 5, 0, no);
			create_enemy(1845, 2, 4, no, 5, 0, no);
			create_enemy(1840, 2, 1, no, 5, 0, no);
			create_enemy(1845, 2, 2, no, 5, 0, no);
			create_enemy(1850, 2, 1, no, 5, 0, no);
			create_enemy(1855, 2, 2, no, 5, 0, no);
			create_enemy(1860, 13, 0, no, 5, 0, no);
			create_enemy(1865, 13, 0, no, 5, 0, no);
			create_enemy(1870, 13, 0, no, 5, 0, no);
			create_enemy(1875, 13, 0, no, 5, 0, no);
			create_enemy(1880, 2, 1, no, 5, 0, no);
			create_enemy(1885, 2, 2, no, 5, 0, no);
			create_enemy(1890, 2, 3, no, 5, 0, no);
			create_enemy(1895, 2, 4, no, 5, 0, no);
			create_enemy(1900, 2, 3, no, 5, 0, no);
			create_enemy(1905, 2, 4, no, 5, 0, no);
			create_enemy(1910, 2, 1, no, 5, 0, no);
			create_enemy(1915, 2, 1, no, 5, 0, no);
			create_enemy(1920, 2, 2, no, 5, 0, no);
			create_enemy(1925, 2, 2, no, 5, 0, no);
			create_enemy(1930, 2, 1, no, 5, 0, no);
			create_enemy(1935, 2, 2, no, 5, 0, no);
			create_enemy(1940, 2, 3, no, 5, 0, no);
			create_enemy(1945, 2, 4, no, 5, 0, no);
			create_enemy(1940, 2, 1, no, 5, 0, no);
			create_enemy(1945, 2, 2, no, 5, 0, no);
			create_enemy(1950, 2, 1, no, 5, 0, no);
			create_enemy(1955, 8, 2, no, 5, 0, no);
		}
		/*
		if (g_PLAYER.mission == 12)
		{
			if (g_time == 2)
			{
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
			}
			if (g_time == 40)
			{
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
				power_up(g_PLAYER.startupgrade);
			}
			create_enemy(50, 2, 1, no, 5, 0, no);
			create_enemy(55, 2, 2, no, 5, 0, no);
			create_enemy(60, 2, 1, no, 5, 0, no);
			create_enemy(65, 2, 2, no, 5, 0, no);
			create_enemy(70, 2, 1, no, 5, 0, no);
			create_enemy(75, 2, 2, no, 5, 0, no);
			create_enemy(80, 2, 1, no, 5, 0, no);
			create_enemy(90, 2, 3, no, 5, 0, no);
			create_enemy(95, 2, 4, no, 5, 0, no);
			create_enemy(100, 2, 3, no, 5, 0, no);
			create_enemy(105, 2, 4, no, 5, 0, no);
			create_enemy(110, 2, 1, no, 5, 0, no);
			create_enemy(115, 2, 1, no, 5, 0, no);
			create_enemy(120, 2, 2, no, 5, 0, no);
			create_enemy(125, 2, 2, no, 5, 0, no);
			create_enemy(130, 2, 1, no, 5, 0, no);
			create_enemy(135, 2, 2, no, 5, 0, no);
			create_enemy(140, 2, 3, no, 5, 0, no);
			create_enemy(145, 2, 4, no, 5, 0, no);
			create_enemy(140, 2, 1, no, 5, 0, no);
			create_enemy(145, 2, 2, no, 5, 0, no);
			create_enemy(150, 2, 1, no, 5, 0, no);
			create_enemy(155, 8, 2, no, 5, 0, no);
			create_enemy(205, 8, 1, no, 5, 0, no);
			create_enemy(255, 8, 2, no, 5, 0, no);
			create_enemy(305, 8, 1, no, 5, 0, no);
			create_enemy(355, 8, 2, no, 5, 0, no);
			create_enemy(405, 6, 1, no, 5, 0, no);
			create_enemy(405, 6, 2, no, 5, 0, no);
			create_enemy(455, 9, 3, no, 5, 0, no);
			create_enemy(455, 9, 4, no, 5, 0, no);
			create_enemy(475, 10, 3, no, 5, 0, no);
			create_enemy(475, 10, 4, no, 5, 0, no);
			create_enemy(475, 3, 3, no, 5, 0, no);
			create_enemy(475, 3, 4, no, 5, 0, no);
			if (g_time == 500)
			{
				power_up(addhealth);
			}
			create_enemy(605, 13, 6, no, 5, 0, no);
			create_enemy(610, 13, 6, no, 5, 0, no);
			create_enemy(615, 13, 6, no, 5, 0, no);
			create_enemy(620, 13, 6, no, 5, 0, no);
			create_enemy(621, 5, 5, no, 5, 0, no);
			create_enemy(625, 13, 6, no, 5, 0, no);
			create_enemy(630, 13, 6, no, 5, 0, no);
			create_enemy(635, 13, 6, no, 5, 0, no);
			create_enemy(640, 13, 6, no, 5, 0, no);
			create_enemy(645, 13, 6, no, 5, 0, no);
			create_enemy(650, 13, 6, no, 5, 0, no);
			create_enemy(655, 13, 6, no, 5, 0, no);
			create_enemy(660, 13, 6, no, 5, 0, no);
			create_enemy(665, 13, 6, no, 5, 0, no);
			create_enemy(670, 13, 6, no, 5, 0, no);
			create_enemy(675, 13, 6, no, 5, 0, no);
			create_enemy(680, 13, 6, no, 5, 0, no);
			create_enemy(685, 13, 6, no, 5, 0, no);
			create_enemy(690, 13, 6, no, 5, 0, no);
			create_enemy(695, 13, 6, no, 5, 0, no);
			create_enemy(720, 7, 5, no, 5, 0, no);
			create_enemy(760, 7, 5, no, 5, 0, no);
			create_enemy(800, 8, 1, no, 5, 0, no);
			create_enemy(800, 8, 2, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 1, 0, no, 5, 0, no);
			create_enemy(900, 5, 0, no, 5, 0, no);
			create_enemy(900, 13, 6, no, 5, 0, no);
			create_enemy(925, 13, 6, no, 5, 0, no);
			create_enemy(950, 13, 6, no, 5, 0, no);
			create_enemy(975, 13, 6, no, 5, 0, no);
			if (g_time == 1000)
			{
				power_up(addhealth);
			}
			create_enemy(1100, 5, 1, no, 5, 0, no);
			create_enemy(1100, 5, 2, no, 5, 0, no);
			create_enemy(1120, 5, 3, no, 5, 0, no);
			create_enemy(1120, 5, 4, no, 5, 0, no);
			create_enemy(1140, 5, 5, no, 5, 0, no);
			create_enemy(1160, 5, 6, no, 5, 0, no);
			create_enemy(1180, 6, 11, no, 5, 0, no);
			create_enemy(1200, 6, 10, no, 5, 0, no);
			create_enemy(1220, 6, 8, no, 5, 0, no);
			create_enemy(1240, 6, 9, no, 5, 0, no);
			create_enemy(1250, 13, 6, no, 5, 0, no);
			create_enemy(1252, 13, 6, no, 5, 0, no);
			create_enemy(1254, 13, 6, no, 5, 0, no);
			create_enemy(1256, 13, 6, no, 5, 0, no);
			create_enemy(1258, 13, 6, no, 5, 0, no);
			create_enemy(1300, 8, 1, no, 5, 0, no);
			create_enemy(1350, 8, 2, no, 5, 0, no);
			create_enemy(1400, 8, 3, no, 5, 0, no);
			create_enemy(1450, 8, 4, no, 5, 0, no);
			if (g_time == 1500)
			{
				power_up(addhealth);
			}
			create_enemy(1600, 3, 1, no, 5, 0, no);
			create_enemy(1620, 3, 8, no, 5, 0, no);
			create_enemy(1640, 3, 2, no, 5, 0, no);
			create_enemy(1660, 3, 9, no, 5, 0, no);
			create_enemy(1680, 3, 3, no, 5, 0, no);
			create_enemy(1700, 3, 10, no, 5, 0, no);
			create_enemy(1720, 3, 4, no, 5, 0, no);
			create_enemy(1740, 3, 11, no, 5, 0, no);
			create_enemy(1800, 2, 1, no, 5, 0, no);
			create_enemy(1800, 2, 2, no, 5, 0, no);
			create_enemy(1800, 2, 3, no, 5, 0, no);
			create_enemy(1800, 2, 4, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);
			create_enemy(1800, 2, 0, no, 5, 0, no);

			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 3, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);
			create_enemy(1900, 4, 0, no, 5, 0, no);

			if (g_time == 2000)
			{
				g_time = -450;
				g_PLAYER.mission++;
			}
		}
		*/


					//////////////////////////////////////////////////
		if (g_ENEMY[17].boss == bossfive && g_ENEMY[17].scriptpos <= -1)
		{
			g_ENEMY[17].health = bossfivehealth;
			g_ENEMY[17].damage = 1;
			g_ENEMY[17].shiptype = 'T';
		//	g_ENEMY[18].health = bossfivehealth * 2;
			g_ENEMY[18].damage = 1;
			g_ENEMY[18].shiptype = 'I';
			g_ENEMY[17].scriptpos++;
			g_ENEMY[18].scriptpos++;
		//	g_ENEMY[19].health = bossfivehealth * 3;
			g_ENEMY[19].damage = 1;
			g_ENEMY[19].shiptype = 'I';
			g_ENEMY[19].scriptpos++;
		}

		if (g_ENEMY[17].boss == bossfour && g_ENEMY[17].scriptpos <= -1)
		{
			g_ENEMY[17].health = (bossfourhealth / 8 * 5);
			g_ENEMY[17].damage = 1;
			g_ENEMY[17].shiptype = 'U';
			g_ENEMY[18].health = (bossfourhealth / 8 * 6);
			g_ENEMY[18].damage = 1;
			g_ENEMY[18].shiptype = 'I';

			g_ENEMY[19].health = bossfourhealth;
			g_ENEMY[19].damage = 1;
			g_ENEMY[19].shiptype = 'U';

			g_ENEMY[17].scriptpos++;
			g_ENEMY[18].scriptpos++;
			g_ENEMY[19].scriptpos++;
		}
		if (g_ENEMY[17].boss == bossthree && g_ENEMY[17].scriptpos <= -1)
		{
			g_ENEMY[17].health = bossthreehealth;
			g_ENEMY[17].damage = 1;
			g_ENEMY[17].shiptype = 'Y';
			g_ENEMY[17].scriptpos++;
		}
		if (g_ENEMY[17].boss == bosstwo && g_ENEMY[17].scriptpos <= -1)
		{
			g_ENEMY[17].health = bosstwohealth;
			g_ENEMY[17].damage = 1;
			g_ENEMY[17].shiptype = 'U';
			g_ENEMY[17].scriptpos++;
		}
		if (g_ENEMY[17].boss == bossone && g_ENEMY[17].scriptpos <= -1)
		{
			g_ENEMY[17].health = bossonehealth;
			g_ENEMY[17].damage = 1;
			g_ENEMY[17].shiptype = 'H';
			SetSpriteState(&g_ENEMY[17], g_ENEMY[17].boss_condition);
			g_ENEMY[17].scriptpos++;
			g_ENEMY[18].health = bossonehealth / 2;
			g_ENEMY[18].damage = 1;
			g_ENEMY[18].shiptype = 'Y';
			g_ENEMY[18].scriptpos++;
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
			g_ENEMY[19].health = bossonehealth / 2;
			g_ENEMY[19].damage = 1;
			g_ENEMY[19].shiptype = 'H';
			g_ENEMY[19].scriptpos++;
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}
		if ((g_ENEMY[18].boss == bossone && g_ENEMY[18].health >= 1) ||(g_ENEMY[19].boss == bossone && g_ENEMY[19].health >= 1))
		{
			g_ENEMY[17].health = 50;
		}
	for (z = 0; z < 20; z++)
	{

		if (g_ENEMY[z].boss == no && g_ENEMY[z].scriptpos == -1)
		{
			if (g_ENEMY[z].ship == 13 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 2 ;
				g_ENEMY[z].damage = 4;
				g_ENEMY[z].shiptype = 'O';
			}
			if (g_ENEMY[z].ship == 12 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 16 ;
				g_ENEMY[z].damage = 2;
				g_ENEMY[z].shiptype = 'o';
			}
			if (g_ENEMY[z].ship == 11 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 1 ;
				g_ENEMY[z].damage = 9;
				g_ENEMY[z].shiptype = '0';
			}
			//28  //4
			//6
			if (g_ENEMY[z].ship == 10 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 6 ;
				g_ENEMY[z].damage = 2;
				g_ENEMY[z].shiptype = 'I';
			}
			if (g_ENEMY[z].ship == 9 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 6 ;
				g_ENEMY[z].damage = 3;
				g_ENEMY[z].shiptype = 'M';
			}
			if (g_ENEMY[z].ship == 8 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 20 ;
				g_ENEMY[z].damage = 1;
				g_ENEMY[z].shiptype = 'U';
			}
			if (g_ENEMY[z].ship == 7 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 20 ;
				g_ENEMY[z].damage = 2;
				g_ENEMY[z].shiptype = 'H';
			}
			if (g_ENEMY[z].ship == 6 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 24 ;
				g_ENEMY[z].damage = 1;
				g_ENEMY[z].shiptype = 'Y';
			}
			if (g_ENEMY[z].ship == 5 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 20 ;
				g_ENEMY[z].damage = 1;
				g_ENEMY[z].shiptype = 'T';
			}
			if (g_ENEMY[z].ship == 4 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 16 ;
				g_ENEMY[z].damage = 2;
				g_ENEMY[z].shiptype = 'W';
			}
			if (g_ENEMY[z].ship == 3 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 12 ;
				g_ENEMY[z].damage = 1;
				g_ENEMY[z].shiptype = 'V';
			}
			if (g_ENEMY[z].ship == 2 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 8 ;
				g_ENEMY[z].damage = 2;
				g_ENEMY[z].shiptype = 'w';
			}
			if (g_ENEMY[z].ship == 1 && g_ENEMY[z].scriptpos == -1)
			{
				if (g_ENEMY[z].special == no && g_ENEMY[z].boss == no && g_PLAYER.mission >= 9)
				{
					g_ENEMY[z].cloaked = rand1.RandInt(1, 30 - g_PLAYER.mission);
				}
				else 
				{
					g_ENEMY[z].cloaked = no;
				}
				g_ENEMY[z].health = 4 ;
				g_ENEMY[z].damage = 1;
				g_ENEMY[z].shiptype = 'v';
			}
			g_ENEMY[z].scriptpos = 0;
		}

		if (g_ENEMY[z].condition == alive)
		{
			script_sequence(z, no);
		}

		if (g_PLAYER.mission >= 9 && g_time >= 1000 && g_time <= 1400)
		{
			g_ENEMY[z].cloaked = yes;
		}
	}
}