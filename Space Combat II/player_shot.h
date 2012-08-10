void player_shot()
{
	if (weapon2 == weapon_diagonallaser && WAIT2 >= 3)
	{
		for (int z = 0; z < g_DLASER[0].upgrade + 1 && g_DLASER[0].upgrade >= 0; z++)
		{
			if (g_DLASER[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_DLASER[0].position.x = g_PLAYER.position.x;
				g_DLASER[0].position.y = g_PLAYER.position.y - 16;
				g_DLASER[0].condition = alive;
				g_DLASER[0].xhold = laserspeed;
				break;
			}
			else if ((g_DLASER[z-1].condition == alive || g_DLASER[z-1].condition == dyingfour) &&  g_DLASER[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_DLASER[z].position.x = g_PLAYER.position.x;
				g_DLASER[z].position.y = g_PLAYER.position.y - 16;
				g_DLASER[z].condition = alive;

				if (z % 2 == 1)
				{
					g_DLASER[z].xhold = -laserspeed;
					break;
				}
				else
				{
					g_DLASER[z].xhold = laserspeed;
					break;
				}

				WAIT2 = 0;
			}
		}
	}
	if (weapon2 == weapon_sidelaser && WAIT2 >= 3)
	{
		for (int z = 0; z < g_SLASER[0].upgrade + 1 && g_SLASER[0].upgrade >= 0; z++)
		{
			if (g_SLASER[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_SLASER[0].position.x = g_PLAYER.position.x;
				g_SLASER[0].position.y = g_PLAYER.position.y - 16;
				g_SLASER[0].condition = alive;
				g_SLASER[0].xhold = laserspeed;
				break;
			}
			else if ((g_SLASER[z-1].condition == alive || g_SLASER[z-1].condition != alive) &&  g_SLASER[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_SLASER[z].position.x = g_PLAYER.position.x;
				g_SLASER[z].position.y = g_PLAYER.position.y - 16;
				g_SLASER[z].condition = alive;
				
				if (z % 2 == 1)
				{
					g_SLASER[z].xhold = -laserspeed;
					break;
				}
				else if (z % 2 == 0)
				{
					g_SLASER[z].xhold = laserspeed;
					break;
				}

				WAIT2 = 0;
				break;
			}
		}
	}
	if (weapon2 == weapon_missile && WAIT2 >= 5)
	{
		for (int z = 0; z < g_MISSILE[0].upgrade + 1 && g_MISSILE[0].upgrade >= 0; z++)
		{
			if (g_MISSILE[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Homing_Missile.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_MISSILE[0].position.x = g_PLAYER.position.x;
				g_MISSILE[0].position.y = g_PLAYER.position.y - 16;
				g_MISSILE[0].condition = alive;
				break;
			}
			else if ((g_MISSILE[z-1].condition == alive || g_MISSILE[z-1].condition == dyingfour) &&  g_MISSILE[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Homing_Missile.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_MISSILE[z].position.x = g_PLAYER.position.x;
				g_MISSILE[z].position.y = g_PLAYER.position.y - 16;
				g_MISSILE[z].condition = alive;
				WAIT2 = 0;
				break;
			}
		}
	}
	if (weapon == weapon_laser && WAIT >= 3)
	{
		for (int z = 0; z < 9 && g_LASER[0].upgrade >= 0; z++)
		{
			if (g_LASER[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_LASER[0].position.x = g_PLAYER.position.x;
				g_LASER[0].position.y = g_PLAYER.position.y - 8;
				g_LASER[0].condition = alive;
				if (space_hold_time >= 430)
				{
					g_LASER[0].speed.x = rand1.RandInt(-6, 6);
				}
				else
				{
					g_LASER[0].speed.x = rand1.RandInt(-1, 1);
				}
				WAIT = 0;
				break;
			}
			else if (g_LASER[z-1].condition == alive &&  g_LASER[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_LASER[z].position.x = g_PLAYER.position.x;
				g_LASER[z].position.y = g_PLAYER.position.y - 8;
				g_LASER[z].condition = alive;
				if (space_hold_time >= 430)
				{
					g_LASER[z].speed.x = rand1.RandInt(-6, 6);
				}
				else
				{
					g_LASER[z].speed.x = rand1.RandInt(-1, 1);
				}
				WAIT = 0;
				break;
			}
		}
	}

	if (weapon == weapon_mgun && WAIT >= 1)
	{
		for (int z = 0; z < 20 && g_MGUN[0].upgrade >= 0; z++)
		{
			if (g_MGUN[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Mgun.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_MGUN[0].position.x = g_PLAYER.position.x;
				g_MGUN[0].position.y = g_PLAYER.position.y - 16;
				g_MGUN[0].speed.x = rand1.RandInt(-4, 4);
				if (space_hold_time >= 430)
				{
					g_MGUN[0].speed.x = rand1.RandInt(-10, 10);
				}
				g_MGUN[0].condition = alive;
				WAIT = 0;
				break;
			}
			else if (g_MGUN[z-1].condition == alive &&  g_MGUN[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Mgun.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_MGUN[z].position.x = g_PLAYER.position.x;
				g_MGUN[z].speed.x = rand1.RandInt(-4, 4);
				if (space_hold_time >= 430)
				{
					g_MGUN[z].speed.x = rand1.RandInt(-10, 10);
				}
				g_MGUN[z].position.y = g_PLAYER.position.y - 16;
				g_MGUN[z].condition = alive;
				WAIT = 0;
				break;
			}
		}
	}

	if (weapon == weapon_pulse && WAIT >= 5)
	{
		if (g_PULSE[0].upgrade >= 0)
		{
			if (TALKING == no)
								{
			PlaySound("Pulse_Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		if (space_hold_time >= 430)
		{
			g_PULSE[0].position.x = g_PLAYER.position.x + rand1.RandInt(-3, 3);
		}
		else
		{
			g_PULSE[0].position.x = g_PLAYER.position.x;
		}
		for (int z = 0; z < 20 && g_PULSE[0].upgrade >= 0; z++)
		{	  
			if (g_PLAYER.position.y  - (1+z)*32 < -32)
			{
				break;
			}
			g_PULSE[z].position.y = g_PLAYER.position.y  - (1+z)*32;
			g_PULSE[z].position.x = g_PULSE[0].position.x;
			g_PULSE[0].speed.x = 0;
			if (g_PULSE[0].upgrade <= 2)
			{
				g_PULSE[z].condition = dyingfour;
				SetSpriteState(&g_PULSE[z], NONE);
			}
			else if (g_PULSE[0].upgrade <= 4)
			{
				g_PULSE[z].condition = dyingthree;
				g_PULSE[0].condition = dyingfour;

				SetSpriteState(&g_PULSE[z], WEST);
				SetSpriteState(&g_PULSE[0], NONE);
			}
			else if (g_PULSE[0].upgrade <= 6)
			{
				g_PULSE[z].condition = dyingtwo;
				g_PULSE[1].condition = dyingthree;
				g_PULSE[0].condition = dyingfour;

				SetSpriteState(&g_PULSE[z], SOUTH);
				SetSpriteState(&g_PULSE[1], WEST);
				SetSpriteState(&g_PULSE[0], NONE);
			}
			else if (g_PULSE[0].upgrade <= 8)
			{
				g_PULSE[z].condition = dyingone;
				g_PULSE[2].condition = dyingtwo;
				g_PULSE[1].condition = dyingthree;
				g_PULSE[0].condition = dyingfour;

				SetSpriteState(&g_PULSE[z], EAST);
				SetSpriteState(&g_PULSE[2], SOUTH);
				SetSpriteState(&g_PULSE[1], WEST);
				SetSpriteState(&g_PULSE[0], NONE);
			}
			else
			{
				g_PULSE[z].condition = alive;
				g_PULSE[3].condition = dyingone;
				g_PULSE[2].condition = dyingtwo;
				g_PULSE[1].condition = dyingthree;
				g_PULSE[0].condition = dyingfour;

				SetSpriteState(&g_PULSE[3], NORTH);
				SetSpriteState(&g_PULSE[3], EAST);
				SetSpriteState(&g_PULSE[2], SOUTH);
				SetSpriteState(&g_PULSE[1], WEST);
				SetSpriteState(&g_PULSE[0], NONE);
			}
			WAIT = 0;
		}
	}

	if (weapon == weapon_flame && WAIT >= 2)
	{
		for (int z = 0; z < 9 && g_FLAME[0].upgrade >= 0; z++)
		{
			if (g_FLAME[0].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Flame.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_FLAME[0].position.x = g_PLAYER.position.x;
				g_FLAME[0].position.y = g_PLAYER.position.y - 16;
				g_FLAME[0].condition = alive;
				g_FLAME[0].life = g_FLAME[0].upgrade * 2 + 5;
				if (space_hold_time >= 430)
				{
					g_FLAME[0].life += 2;
					g_FLAME[0].speed.x = rand1.RandInt(-10, 10);
				}
				else
				{
					g_FLAME[0].speed.x = rand1.RandInt(-2, 2);
				}
				break;
			}
			else if ((g_FLAME[z-1].condition != dead) &&  g_FLAME[z].condition == dead)
			{
				if (TALKING == no)
								{
				PlaySound("Flame.wav", NULL, SND_FILENAME | SND_ASYNC);
				}
				g_FLAME[z].position.x = g_PLAYER.position.x;
				g_FLAME[z].position.y = g_PLAYER.position.y - 16;
				g_FLAME[z].condition = alive;
				g_FLAME[z].life = g_FLAME[0].upgrade * 2 + 5;
				if (space_hold_time >= 430)
				{
					g_FLAME[z].life += 2;
					g_FLAME[z].speed.x = rand1.RandInt(-10, 10);
				}
				else
				{
					g_FLAME[z].speed.x = rand1.RandInt(-2, 2);
				}
				break;
			}
			WAIT = 0;
		}
	}
}