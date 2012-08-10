void player_controls()
{	
	//PLAYER CONTROLS

	if ((GetAsyncKeyState(VK_SHIFT) && NVWAIT >= 10) || g_PLAYER.battery <= 0)
	{ 
		g_PLAYER.vision++;
		if (g_PLAYER.battery >= g_PLAYER.maxbattery / 15)
		{
			if (g_PLAYER.vision == 1)
			{
				g_PLAYER.headlight = yes;
				g_PLAYER.thermalvision = no;
				g_PLAYER.nightvision = no;
				SetSpriteState(&g_HEADLIGHT, 0);
				g_HEADLIGHT.condition = alive;
				g_HEADLIGHT.position.y = g_PLAYER.position.y - 150;
				g_HEADLIGHT.position.x = g_PLAYER.position.x;
				g_PLAYER.hBitmap = g_PLAYER.hBitmapNormal;
				g_ESCORT.hBitmap = g_ESCORT.hBitmapNormal;

				for (int y = 0; y < max_level_tiles; y++)
				{
					if (y < maxally)
					{
							g_ALLY[y].hBitmap = g_ALLY[y].hBitmapNormal;
					}
					g_ENEMY[y].hBitmap = g_ENEMY[y].hBitmapNormal;
					g_ELASER[y].hBitmap = g_ELASER[y].hBitmapNormal;
					g_LASER[y].hBitmap = g_LASER[y].hBitmapNormal;
					g_MGUN[y].hBitmap = g_MGUN[y].hBitmapNormal;
					g_FLAME[y].hBitmap = g_FLAME[y].hBitmapNormal;
					g_PULSE[y].hBitmap = g_PULSE[y].hBitmapNormal;
					g_DLASER[y].hBitmap = g_DLASER[y].hBitmapNormal;
					g_SLASER[y].hBitmap = g_SLASER[y].hBitmapNormal;
					g_MISSILE[y].hBitmap = g_MISSILE[y].hBitmapNormal;
					g_CHARGE[y].hBitmap = g_CHARGE[y].hBitmapNormal;
					g_ALLYSHOT[y].hBitmap = g_ALLYSHOT[y].hBitmapNormal;
					if (y < lasermax)
					{
						g_POWERUP[y].hBitmap = g_POWERUP[y].hBitmapNormal;
					}
				}
			}
			else if (g_PLAYER.vision == 2)
			{
				g_PLAYER.headlight = no;
				g_PLAYER.nightvision = yes;
				g_PLAYER.thermalvision = no;

				g_HEADLIGHT.condition = dead;
				SetSpriteState(&g_HEADLIGHT, 1);
				g_HEADLIGHT.position.y = -160;
				g_HEADLIGHT.position.x = -160;

				g_ESCORT.hBitmap = g_ESCORT.hBitmapNightVision;
				g_PLAYER.hBitmap = g_PLAYER.hBitmapNightVision;

				for (int y = 0; y < max_level_tiles; y++)
				{
					//hBitmapNormal = "Enemy.bmp";
					//hBitmapNightVision = "EnemyNV.bmp";
					//hBitmapThermal = "EnemyTH.bmp";				
					if (y < maxally)
					{
							g_ALLY[y].hBitmap = g_ALLY[y].hBitmapNightVision;
					}
					g_ENEMY[y].hBitmap = g_ENEMY[y].hBitmapNightVision;
					g_ELASER[y].hBitmap = g_ELASER[y].hBitmapNightVision;
					g_LASER[y].hBitmap = g_LASER[y].hBitmapNightVision;
					g_MGUN[y].hBitmap = g_MGUN[y].hBitmapNightVision;
					g_FLAME[y].hBitmap = g_FLAME[y].hBitmapNightVision;
					g_PULSE[y].hBitmap = g_PULSE[y].hBitmapNightVision;
					g_DLASER[y].hBitmap = g_DLASER[y].hBitmapNightVision;
					g_SLASER[y].hBitmap = g_SLASER[y].hBitmapNightVision;
					g_MISSILE[y].hBitmap = g_MISSILE[y].hBitmapNightVision;
					g_CHARGE[y].hBitmap = g_CHARGE[y].hBitmapNightVision;
					g_ALLYSHOT[y].hBitmap = g_ALLYSHOT[y].hBitmapNightVision;
					if (y < lasermax)
					{
						g_POWERUP[y].hBitmap = g_POWERUP[y].hBitmapNightVision;
					}
				}
			}
			else if (g_PLAYER.vision == 3 && g_PLAYER.mission >= 9)
			{
				g_PLAYER.headlight = no;
				g_PLAYER.nightvision = no;
				g_PLAYER.thermalvision = yes;

				g_HEADLIGHT.condition = dead;
				SetSpriteState(&g_HEADLIGHT, 1);
				g_HEADLIGHT.position.y = -160;
				g_HEADLIGHT.position.x = -160;
				g_PLAYER.headlight = no;

				g_ESCORT.hBitmap = g_ESCORT.hBitmapThermalVision;
				g_PLAYER.hBitmap = g_PLAYER.hBitmapThermalVision;

				if (TALKING == no)
								{
				PlaySound("NV.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_PLAYER.nightvision = yes;
				for (int y = 0; y < max_level_tiles; y++)
				{
					//hBitmapNormal = "Enemy.bmp";
					//hBitmapNightVision = "EnemyNV.bmp";
					//hBitmapThermal = "EnemyTH.bmp";
					if (y < maxally)
					{
							g_ALLY[y].hBitmap = g_ALLY[y].hBitmapThermalVision;
					}
					g_ENEMY[y].hBitmap = g_ENEMY[y].hBitmapThermalVision;
					g_ELASER[y].hBitmap = g_ELASER[y].hBitmapThermalVision;
					g_LASER[y].hBitmap = g_LASER[y].hBitmapThermalVision;
					g_MGUN[y].hBitmap = g_MGUN[y].hBitmapThermalVision;
					g_FLAME[y].hBitmap = g_FLAME[y].hBitmapThermalVision;
					g_PULSE[y].hBitmap = g_PULSE[y].hBitmapThermalVision;
					g_DLASER[y].hBitmap = g_DLASER[y].hBitmapThermalVision;
					g_SLASER[y].hBitmap = g_SLASER[y].hBitmapThermalVision;
					g_MISSILE[y].hBitmap = g_MISSILE[y].hBitmapThermalVision;
					g_CHARGE[y].hBitmap = g_CHARGE[y].hBitmapThermalVision;
					g_ALLYSHOT[y].hBitmap = g_ALLYSHOT[y].hBitmapThermalVision;
					if (y < lasermax)
					{
						g_POWERUP[y].hBitmap = g_POWERUP[y].hBitmapThermalVision;
					}
				}
				Sleep(50);
			}
			else
			{
				g_HEADLIGHT.condition = dead;
				SetSpriteState(&g_HEADLIGHT, 1);
				g_HEADLIGHT.position.y = -160;
				g_HEADLIGHT.position.x = -160;
				g_PLAYER.headlight = no;

				g_PLAYER.vision = 0;

				g_PLAYER.headlight = no;
				g_PLAYER.nightvision = no;
				g_PLAYER.thermalvision = no;
				g_ESCORT.hBitmap = g_ESCORT.hBitmapNormal;
				g_PLAYER.hBitmap = g_PLAYER.hBitmapNormal;
				for (int y = 0; y < max_level_tiles; y++)
				{
					if (y < maxally)
					{
							g_ALLY[y].hBitmap = g_ALLY[y].hBitmapNormal;
					}
					g_ENEMY[y].hBitmap = g_ENEMY[y].hBitmapNormal;
					g_ELASER[y].hBitmap = g_ELASER[y].hBitmapNormal;
					g_LASER[y].hBitmap = g_LASER[y].hBitmapNormal;
					g_MGUN[y].hBitmap = g_MGUN[y].hBitmapNormal;
					g_FLAME[y].hBitmap = g_FLAME[y].hBitmapNormal;
					g_PULSE[y].hBitmap = g_PULSE[y].hBitmapNormal;
					g_DLASER[y].hBitmap = g_DLASER[y].hBitmapNormal;
					g_SLASER[y].hBitmap = g_SLASER[y].hBitmapNormal;
					g_MISSILE[y].hBitmap = g_MISSILE[y].hBitmapNormal;
					g_CHARGE[y].hBitmap = g_CHARGE[y].hBitmapNormal;
					g_ALLYSHOT[y].hBitmap = g_ALLYSHOT[y].hBitmapNormal;
					if (y < lasermax)
					{
						g_POWERUP[y].hBitmap = g_POWERUP[y].hBitmapNormal;
					}
				}
				Sleep(50);
			}
		}
		else
		{
			g_HEADLIGHT.condition = dead;
			SetSpriteState(&g_HEADLIGHT, 1);
			g_HEADLIGHT.position.y = -160;
			g_HEADLIGHT.position.x = -160;
			g_PLAYER.headlight = no;

			g_PLAYER.vision = 0;

			g_PLAYER.headlight = no;
			g_PLAYER.nightvision = no;
			g_PLAYER.thermalvision = no;
			g_ESCORT.hBitmap = g_ESCORT.hBitmapNormal;
			g_PLAYER.hBitmap = g_PLAYER.hBitmapNormal;
			for (int y = 0; y < max_level_tiles; y++)
			{
				if (y < maxally)
				{
						g_ALLY[y].hBitmap = g_ALLY[y].hBitmapNormal;
				}
				g_ENEMY[y].hBitmap = g_ENEMY[y].hBitmapNormal;
				g_ELASER[y].hBitmap = g_ELASER[y].hBitmapNormal;
				g_LASER[y].hBitmap = g_LASER[y].hBitmapNormal;
				g_MGUN[y].hBitmap = g_MGUN[y].hBitmapNormal;
				g_FLAME[y].hBitmap = g_FLAME[y].hBitmapNormal;
				g_PULSE[y].hBitmap = g_PULSE[y].hBitmapNormal;
				g_DLASER[y].hBitmap = g_DLASER[y].hBitmapNormal;
				g_SLASER[y].hBitmap = g_SLASER[y].hBitmapNormal;
				g_MISSILE[y].hBitmap = g_MISSILE[y].hBitmapNormal;
				g_CHARGE[y].hBitmap = g_CHARGE[y].hBitmapNormal;
				g_ALLYSHOT[y].hBitmap = g_ALLYSHOT[y].hBitmapNormal;
				if (y < lasermax)
				{
					g_POWERUP[y].hBitmap = g_POWERUP[y].hBitmapNormal;
				}
			}
			Sleep(50);
		}
		if (TALKING == no)
								{
		PlaySound("NV.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		NVWAIT = 0;
	}

	if (!(GetAsyncKeyState(VK_DOWN)) && !(GetAsyncKeyState(VK_UP)) && !(GetAsyncKeyState(VK_LEFT)) && !(GetAsyncKeyState(VK_RIGHT)))
	{
		if (g_time%3==0)
		{
			SetSpriteState(&g_PLAYER, NONE);
		}
		if (g_time%3==1 || g_time%3==-1)
		{
			SetSpriteState(&g_PLAYER, NORTH);
		}
		if (g_time%3==2 || g_time%3==-2)
		{
			SetSpriteState(&g_PLAYER, SOUTH);
		}
	}

	//check if player can move left, if so add momventum
	if (GetAsyncKeyState(VK_LEFT))
	{
		g_PLAYER.toleft = yes;
		if( (g_PLAYER.position.x + g_PLAYER.momentumx) >= 0)
		{
			if (g_PLAYER.momentumx >= -g_PLAYER.max_momentumX)
			{
				g_PLAYER.momentumx-=g_PLAYER.momentum_climb;
			}
			if (g_PLAYER.momentumx > 0)
			{
		g_PLAYER.momentumx=0;
			}
			g_PLAYER.position.x += g_PLAYER.momentumx; //actually add momentum
			if (g_time%3==0)
			{
				SetSpriteState(&g_PLAYER, WEST);
			}
			if (g_time%3==1||g_time%3==-1)
			{
				SetSpriteState(&g_PLAYER, NORTHWEST);
			}
			if (g_time%3==2||g_time%3==-2)
			{
				SetSpriteState(&g_PLAYER, SOUTHWEST);
			}
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		g_PLAYER.toleft = no;
		if( (g_PLAYER.position.x + g_PLAYER.momentumx) < WIDTH - 32)
		{
			if (g_PLAYER.momentumx <= g_PLAYER.max_momentumX)
			{
				g_PLAYER.momentumx+=g_PLAYER.momentum_climb;
			}
			if (g_PLAYER.momentumx < 0)
			{
				g_PLAYER.momentumx=0;
			}
			g_PLAYER.position.x += g_PLAYER.momentumx;
			if (g_time%3==0)
			{
				SetSpriteState(&g_PLAYER, EAST);
			}
			if (g_time%3==1||g_time%3==-1)
			{
				SetSpriteState(&g_PLAYER, NORTHEAST);
			}
			if (g_time%3==2||g_time%3==-2)
			{
				SetSpriteState(&g_PLAYER, SOUTHEAST);
			}
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if( (g_PLAYER.position.y + g_PLAYER.momentumy) >=  gridalignment * 0)
		{
			if (g_PLAYER.momentumy >= -g_PLAYER.max_momentumY)
			{
				g_PLAYER.momentumy-=g_PLAYER.momentum_climb;
			}
			if (g_PLAYER.momentumy > 0)
			{
				g_PLAYER.momentumy=0;
			}
			g_PLAYER.position.y += g_PLAYER.momentumy;
			SetSpriteState(&g_PLAYER, NORTH);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if( (g_PLAYER.position.y + g_PLAYER.momentumy) < gridalignment * 14)
		{
			if (g_PLAYER.momentumy <= g_PLAYER.max_momentumY / 4)
			{
				g_PLAYER.momentumy+=g_PLAYER.momentum_climb;
			}
			if (g_PLAYER.momentumy < 0)
			{
				g_PLAYER.momentumy=0;
			}
			g_PLAYER.position.y += g_PLAYER.momentumy;
			SetSpriteState(&g_PLAYER, SOUTH);
		}
	}


	//player will still slide for a little while, momentum doesnt stop
	if (!(GetAsyncKeyState(VK_UP)) && !(GetAsyncKeyState(VK_DOWN) &&
	( (g_PLAYER.position.y + g_PLAYER.momentumy) > 0) &&
	(g_PLAYER.position.y + g_PLAYER.momentumy) <  gridalignment * 14))
	{
		if (g_PLAYER.momentumy < -4)
		{
			g_PLAYER.momentumy+=g_PLAYER.momentum_climb;//slows down a little fast
		}
		else if (g_PLAYER.momentumy < 0)//slows down a little slower
		{
			g_PLAYER.momentumy++;
		}
		if (g_PLAYER.momentumy > 4)
		{
			g_PLAYER.momentumy-=4;
		}
		else if (g_PLAYER.momentumy > 0)
		{
			g_PLAYER.momentumy--;
		}
		if ((g_PLAYER.position.y + g_PLAYER.momentumy) >  gridalignment * 0 &&
			(g_PLAYER.position.y + g_PLAYER.momentumy) <  gridalignment * 14)
		{
			g_PLAYER.position.y += g_PLAYER.momentumy;
		}
	}
	if (!(GetAsyncKeyState(VK_LEFT)) && !(GetAsyncKeyState(VK_RIGHT)) &&
	( (g_PLAYER.position.x + g_PLAYER.momentumx) >= 0) &&
	( (g_PLAYER.position.x + g_PLAYER.momentumx) < gridalignment * 14))
	{
		if (g_PLAYER.momentumx < -4)
		{
			g_PLAYER.momentumx += 4;
		}
		else if (g_PLAYER.momentumx < 0)
		{
			g_PLAYER.momentumx++;
		}
		if (g_PLAYER.momentumx > 4)
		{
			g_PLAYER.momentumx-=4;
		}
		else if (g_PLAYER.momentumx > 0)
		{
			g_PLAYER.momentumx--;
		}
		if ((g_PLAYER.position.x + g_PLAYER.momentumx) >  gridalignment * 0 &&
			(g_PLAYER.position.x + g_PLAYER.momentumx) <  gridalignment * 14)
		{
			g_PLAYER.position.x += g_PLAYER.momentumx;
		}
	}

	//if two directions pressed, make player appear moving up and right
	if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_RIGHT))
	{
			SetSpriteState(&g_PLAYER, NORTHEAST);
	}
	if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_RIGHT))
	{
		SetSpriteState(&g_PLAYER, SOUTHEAST);
	}
	if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_LEFT))
	{
		SetSpriteState(&g_PLAYER, NORTHWEST);
	}
	if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_LEFT))
	{
		SetSpriteState(&g_PLAYER, SOUTHWEST);
	}

	//change [rimary weapon
	if (GetAsyncKeyState(VK_DELETE))
	{
		if 	(weapon == weapon_laser)
		{
			if(TALKING == no && g_MGUN[0].upgrade >= 1)
			{
				PlaySound("MgunSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon = weapon_mgun;
		}
		else if (weapon == weapon_mgun)
		{
			if(TALKING == no && g_FLAME[0].upgrade >= 1)
			{
				PlaySound("FlameSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon = weapon_flame;
		}
		else if (weapon == weapon_flame)
		{
			if(TALKING == no && g_PULSE[0].upgrade >= 1)
			{
				PlaySound("Pulse_LaserSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon = weapon_pulse;
		}
		else if (weapon == weapon_pulse)
		{
			if(TALKING == no && g_LASER[0].upgrade >= 1)
			{
				PlaySound("LaserSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon = weapon_laser;
		}
		Sleep(150);
	}

	if (weapon == weapon_laser && g_LASER[0].upgrade < 1)
	{
		weapon = weapon_mgun;
	}
	if (weapon == weapon_mgun && g_MGUN[0].upgrade < 1)
	{
		weapon = weapon_flame;
	}
	if (weapon == weapon_flame && g_FLAME[0].upgrade < 1)
	{
		weapon = weapon_pulse;
	}
	if (weapon == weapon_pulse && g_PULSE[0].upgrade < 1)
	{
		weapon = weapon_laser;
	}

	if (weapon2 == weapon_diagonallaser && g_DLASER[0].upgrade < 1)
	{
		weapon2 = weapon_sidelaser;
	}
	if (weapon2 == weapon_sidelaser && g_SLASER[0].upgrade < 1)
	{
		weapon2 = weapon_missile;
	}
	if (weapon2 == weapon_missile && g_MISSILE[0].upgrade < 1)
	{
		weapon2 = weapon_diagonallaser;
	}

	//change secondary weapon
	if(GetAsyncKeyState(VK_END))
	{
		if 	(weapon2 == weapon_diagonallaser)
		{
			if(TALKING == no && g_SLASER[0].upgrade >= 1)
			{
				PlaySound("SideSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon2 = weapon_sidelaser;
		}
		else if (weapon2 == weapon_sidelaser)
		{
			if(TALKING == no && g_MISSILE[0].upgrade >= 1)
			{
				PlaySound("MissileSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon2 = weapon_missile;
		}
		else if (weapon2 == weapon_missile)
		{
			if(TALKING == no && g_DLASER[0].upgrade >= 1)
			{
				PlaySound("DiagonalSel.wav", NULL, SND_FILENAME | SND_ASYNC);
				TALKING = 2;
			}
			weapon2 = weapon_diagonallaser;
		}
		Sleep(150);
	}
	/*
	if (TALKING >= 2)
	{
		TALKING++;
		if (TALKING >= 50)
		{
			TALKING = no;
		}
	}
	*/
	

	//pause button..this really sucks, but it works for now
	if(GetAsyncKeyState(VK_PAUSE) && PAUSE == no)
	{
		PAUSE = yes;
		while(PAUSE == yes)
		{
			if(GetAsyncKeyState(VK_PAUSE))
			{
				PAUSE = no;
			}
			Sleep(100);
		}
	}
	
	//charge laser
	if(GetAsyncKeyState(VK_CONTROL) && g_CHARGE[0].condition == dead)
	{
		if (g_PLAYER.charge < g_CHARGE[0].upgrade * 100)
		{
			g_PLAYER.charge += g_CHARGE[0].upgrade * 2;
		}
	}
	
	//chrage laser shoots
	if(!(GetAsyncKeyState(VK_CONTROL)) && g_PLAYER.charge >= 100)
	{
		space_hold_time+=20;
		if (TALKING == no)
								{
		PlaySound("ChargeShot.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		fire_charge();
	}
	
	//nuke..does 16 damage to everything, and kills all lasers on screen
	if(GetAsyncKeyState(VK_MENU) && !(GetAsyncKeyState(VK_CONTROL)))
	{
		fire_nuke();
	}

	if(!(GetAsyncKeyState(VK_CONTROL)) && g_PLAYER.charge >= 1 && g_time % 2 == 0)
	{
		g_PLAYER.charge--;
	}

	if (weapon2 < 0)
	{
		if (g_DLASER[0].upgrade >= 1)
		{
			weapon2 = weapon_diagonallaser;
		}
		if (g_SLASER[0].upgrade >= 1)
		{
			weapon2 = weapon_sidelaser;
		}
		if (g_MISSILE[0].upgrade >= 1)
		{
			weapon2 = weapon_missile;
		}
	}


	//primary and secondary fire
	if (GetAsyncKeyState(VK_SPACE) && !(GetAsyncKeyState(VK_CONTROL)) && space_hold_time <= 800 && overheat <= 0)
	{
		space_hold_time+=2;
		player_shot();
	}
	if (space_hold_time > 800)
	{
		overheat = 150;
	}
	if (((!(GetAsyncKeyState(VK_SPACE)) && overheat <= 0) || space_hold_time > 800 || overheat >= 0) &&  space_hold_time >= 1)
	{
		space_hold_time--;
		if (overheat >= 0)
		{
			overheat-=2;
		}
	}
}