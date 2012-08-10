void sprite_collisions()
{
	for (int z = 0; z < max_level_tiles; z++)
	{
		if (g_ENEMY[z].condition == alive &&
			g_ENEMY[z].position.y +  g_ENEMY[z].SIZEheight >= g_HEADLIGHT.position.y - 300 &&
			g_ENEMY[z].position.y <= g_HEADLIGHT.position.y + 140 &&
			g_ENEMY[z].position.x >= g_HEADLIGHT.position.x  - 100 &&
			g_ENEMY[z].position.x <= g_HEADLIGHT.position.x + 100)
		{
			g_ENEMY[z].headlight = yes;
		}
		else
		{
			g_ENEMY[z].headlight = no;
		}
		if (g_ELASER[z].condition == alive &&
			g_ELASER[z].position.y + 32 >= g_HEADLIGHT.position.y - 300 &&
			g_ELASER[z].position.y <= g_HEADLIGHT.position.y + 140 &&
			g_ELASER[z].position.x >= g_HEADLIGHT.position.x  - 100 &&
			g_ELASER[z].position.x <= g_HEADLIGHT.position.x + 100)
		{
			g_ELASER[z].headlight = yes;
		}
		else
		{
			g_ELASER[z].headlight = no;
		}
	}
	for (z = 0; z < lasermax; z++)
	{
		if (z < maxally)
		{
			if (g_ALLY[z].condition == dead && (g_ALLY[z].position.y < -32 || g_ALLY[z].position.x < -32))
			{
				g_ALLY[z].health = 10;
				g_ALLY[z].position.y -= allyspeed;
				g_ALLY[z].position.x -= allyspeed;
			}
		}
		//did our beloved hero touch a powerup?
		if (g_POWERUP[z].condition == alive && 
			g_PLAYER.position.y + 32  >= g_POWERUP[z].position.y &&
			g_PLAYER.position.y <= g_POWERUP[z].position.y + 32 &&
			g_PLAYER.position.x + 32 >= g_POWERUP[z].position.x &&
			g_PLAYER.position.x <= g_POWERUP[z].position.x + 32)
		{
			//check type of powerup & add stuff
			if (g_POWERUP[z].type == addlaser)
			{
				if (g_LASER[0].upgrade < maxlaserupgrade)
				{
					g_LASER[0].upgrade++;
					g_LASER[0].damage += 1;//I USED PORPORTIONS TO SOLVE
					g_POWERUP[z].condition = dead;
					
					for (int q = 0; q < maxlaserupgrade;q++)
					{
						if (g_LASER[0].upgrade <= maxlaserupgrade)
						{
							SetSpriteState(&g_LASER[q], g_LASER[0].upgrade);
						}
						
					}

				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addmgun)
			{
				if (g_MGUN[0].upgrade < maxmgunupgrade)
				{
					g_MGUN[0].upgrade+=2;
					g_MGUN[0].damage += .375;
					g_POWERUP[z].condition = dead;

					if (g_MGUN[0].upgrade >= 0 && g_MGUN[0].upgrade < 4)
					{
						g_MGUN[0].upgrade = 4;
					}
					for (int q = 0; q < maxmgunupgrade;q++)
					{
						if (g_MGUN[0].upgrade < maxmgunupgrade)
						{
							SetSpriteState(&g_MGUN[q], ((int)g_MGUN[0].upgrade / 2) - 2);
						}
					}
				}

				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addflame)
			{
				if (g_FLAME[0].upgrade < maxflameupgrade)
				{
					g_FLAME[0].upgrade++;
					g_FLAME[0].damage += 1;
					g_POWERUP[z].condition = dead;
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addpulse)
			{
				if (g_PULSE[0].upgrade < maxpulseupgrade)
				{
					g_PULSE[0].upgrade++;
					g_PULSE[0].damage += .10;
					g_POWERUP[z].condition = dead;
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addhealth)
			{
				g_PLAYER.health = g_PLAYER.maxhealth;
				for (int a = 0; a < maxally; a++)
				{
					if (g_ALLY[a].condition == alive)
					{
						g_ALLY[a].health = g_ALLY[a].maxhealth;
					}
				}
				g_POWERUP[z].condition = dead;
			}
			else if (g_POWERUP[z].type == adddiagonallaser)
			{
				if (g_DLASER[0].upgrade < maxlaserupgrade)
				{
					g_DLASER[0].upgrade++;
					g_DLASER[0].damage += 1;
					g_POWERUP[z].condition = dead;
					for (int q = 0; q < maxmgunupgrade;q++)
					{
						if (g_DLASER[0].upgrade < maxlaserupgrade)
						{
							SetSpriteState(&g_DLASER[q], 0);
						}
					}
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addsidelaser)
			{
				if (g_SLASER[0].upgrade < maxlaserupgrade)
				{
					g_SLASER[0].upgrade++;
					g_SLASER[0].damage += 1;
					g_POWERUP[z].condition = dead;
					for (int q = 0; q < maxmgunupgrade;q++)
					{
						if (g_SLASER[0].upgrade < maxlaserupgrade)
						{
							SetSpriteState(&g_SLASER[q], 0);
						}
					}
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addmissile)
			{
				if (g_MISSILE[0].upgrade < maxlaserupgrade)
				{
					g_MISSILE[0].upgrade++;
					g_MISSILE[0].damage += .25;
					g_POWERUP[z].condition = dead;
					for (int q = 0; q < maxmgunupgrade;q++)
					{
						if (g_MISSILE[0].upgrade < maxlaserupgrade)
						{
							SetSpriteState(&g_MISSILE[q], 0);
						}
					}
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			else if (g_POWERUP[z].type == addnuke)
			{
				if (g_PLAYER.nuke < maxnuke)
				{
					g_PLAYER.nuke++;
					g_POWERUP[z].condition = dead;
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			
			else if (g_POWERUP[z].type == addcharge)
			{
				if (g_CHARGE[0].upgrade < 5)
				{
					g_CHARGE[0].upgrade++;
					g_POWERUP[z].condition = dead;
				}
				else
				{
					g_POWERUP[z].type++;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}

			else if (g_POWERUP[z].type == addbattery)
			{
				if (g_PLAYER.battery < g_PLAYER.maxbattery)
				{
					g_PLAYER.battery = g_PLAYER.maxbattery;
					g_POWERUP[z].condition = dead;
				}
				else
				{
					g_POWERUP[z].type = 0;
					SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
				}
			}
			
			else
			{
				g_POWERUP[z].type = rand1.RandInt(addlaser, addbattery);
				SetSpriteState(&g_POWERUP[z], g_POWERUP[z].type);
			}
		}
		if (g_POWERUP[z].condition == dead)
		{
			g_POWERUP[z].position.y = -32;
			g_POWERUP[z].position.x = -32;
		}

		//okay, our player touched a powerup, but did his laser touch enemy? or did he touch enemy laser?

		for (int x = 0; x < max_level_tiles; x++)
		{
			if (g_ENEMY[x].health <= 0 && g_ENEMY[x].condition == alive && g_ENEMY[x].boss == no)
			{
				addpoints(x);
				if (g_ENEMY[x].special == yes)
				{
					g_PLAYER.special++;
				}
				g_ENEMY[x].particles = no;

				int ra = rand1.RandInt(0, 6);
				if (ra == 0 || g_ENEMY[x].boss != no)
				{
					g_ENEMY[x].particles = yes;
				}
				if (g_ENEMY[x].particles == no)
				{
					if (TALKING == no)
								{
					PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
				}
				if (ra == 1 || g_ENEMY[x].boss != no)
				{
					if (TALKING == no)
								{
					PlaySound("Explode2.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					create_explosion(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
					g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), rand1.RandInt(-15,15), rand1.RandInt(-15,15));
					create_explosion(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
					g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), rand1.RandInt(-15,15), rand1.RandInt(-15,15));
					create_explosion(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
					g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), rand1.RandInt(-15,15), rand1.RandInt(-15,15));
				}
				if (g_ENEMY[x].particles == yes)
				{
					if (TALKING == no)
								{
					PlaySound("Explode2.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					g_MOMX1 = rand1.RandInt(-20,20);
					g_MOMX2 = rand1.RandInt(-20,20);
					g_MOMX3 = rand1.RandInt(-20,20);
					g_MOMX4 = rand1.RandInt(-20,20);
					g_MOMX5 = rand1.RandInt(-20,20);

					g_MOMY1 = rand1.RandInt(-20,20);
					g_MOMY2 = rand1.RandInt(-20,20);
					g_MOMY3 = rand1.RandInt(-20,20);
					g_MOMY4 = rand1.RandInt(-20,20);
					g_MOMY5 = rand1.RandInt(-20,20);

					create_particle(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
					g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), g_MOMX1, g_MOMY1);
					create_particle(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
						g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), g_MOMX2, g_MOMY2);
					create_particle(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
						g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), g_MOMX3, g_MOMY3);
					create_particle(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
						g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), g_MOMX4, g_MOMY4);
					create_particle(g_ENEMY[x].position.x + (int)(g_ENEMY[x].SIZEwidth / 2), 
						g_ENEMY[x].position.y + (int)(g_ENEMY[x].SIZEheight/ 2), g_MOMX5, g_MOMY5);
				}
				g_ENEMY[x].condition = dyingone;
			}

			//did laser hit enemy? if it did pull her from screen

			if ( g_LASER[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_LASER[z].position.y + 32 >= g_ENEMY[x].position.y
				&& g_LASER[z].position.y      <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight
				&& g_LASER[z].position.x + 32 >= g_ENEMY[x].position.x
				&& g_LASER[z].position.x      <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_LASER[z].condition = dead;
				g_LASER[z].position.x = -1000;
				g_LASER[z].position.y = -1000;
				g_ENEMY[x].health -= g_LASER[0].damage;
			}
			if (g_ENEMY[x].condition == alive 
				&& g_ALLYSHOT[z].condition == alive
				&& g_ALLYSHOT[z].position.y + 32 >= g_ENEMY[x].position.y
				&& g_ALLYSHOT[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight 
				&& g_ALLYSHOT[z].position.x +32 >= g_ENEMY[x].position.x
				&& g_ALLYSHOT[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_ALLYSHOT[z].condition = dead;
				g_ALLYSHOT[z].position.x = -1000;
				g_ALLYSHOT[z].position.y = -1000;
				g_ENEMY[x].health -= g_ALLYSHOT[0].damage;
			}
			if ( g_MGUN[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_MGUN[z].position.y >= g_ENEMY[x].position.y 
				&& g_MGUN[z].position.y <= g_ENEMY[x].position.y+ g_ENEMY[x].SIZEheight 
				&& g_MGUN[z].position.x >= g_ENEMY[x].position.x  - g_ENEMY[x].SIZEwidth 
				&& g_MGUN[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_MGUN[z].position.x = -1000;
				g_MGUN[z].position.y = -1000;
				g_MGUN[z].condition = dead;
				g_ENEMY[x].health -= g_MGUN[0].damage;
			}

			if ( g_DLASER[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_DLASER[z].position.y +32 >= g_ENEMY[x].position.y 
				&& g_DLASER[z].position.y<= g_ENEMY[x].position.y+ g_ENEMY[x].SIZEheight
				&& g_DLASER[z].position.x +32 >= g_ENEMY[x].position.x 
				&& g_DLASER[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_DLASER[z].position.x = -1000;
				g_DLASER[z].position.y = -1000;
				g_DLASER[z].condition = dead;
				g_ENEMY[x].health -= g_DLASER[0].damage;
			}

			if ( g_SLASER[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_SLASER[z].position.y +32>= g_ENEMY[x].position.y
				&& g_SLASER[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight 
				&& g_SLASER[z].position.x +32>= g_ENEMY[x].position.x
				&& g_SLASER[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_SLASER[z].position.x = -1000;
				g_SLASER[z].position.y = -1000;
				g_SLASER[z].condition = dead;
				g_ENEMY[x].health -= g_SLASER[0].damage;
			}

			if ( g_CHARGE[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_CHARGE[z].position.y +32>= g_ENEMY[x].position.y
				&& g_CHARGE[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight
				&& g_CHARGE[z].position.x +32>= g_ENEMY[x].position.x
				&& g_CHARGE[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_CHARGE[z].position.x = -1000;
				g_CHARGE[z].position.y = -1000;
				g_CHARGE[z].condition = dead;
				g_ENEMY[x].health -= g_CHARGE[0].damage;
			}

			if ( g_MISSILE[z].condition == alive && g_ENEMY[x].condition == alive &&
				g_MISSILE[z].position.y +32>= g_ENEMY[x].position.y
				&& g_MISSILE[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight 
				&& g_MISSILE[z].position.x +32>= g_ENEMY[x].position.x  - g_ENEMY[x].SIZEwidth 
				&& g_MISSILE[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_MISSILE[z].position.x = -1000;
				g_MISSILE[z].position.y = -1000;
				g_MISSILE[z].condition = dead;
				g_ENEMY[x].health -= g_MISSILE[0].damage;
			}

			if ( g_FLAME[z].condition != dead && g_ENEMY[x].condition == alive &&
				g_FLAME[z].position.y +32>= g_ENEMY[x].position.y 
				&& g_FLAME[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight
				&& g_FLAME[z].position.x +32>= g_ENEMY[x].position.x
				&& g_FLAME[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
			{
				g_FLAME[z].position.x = -1000;
				g_FLAME[z].position.y = -1000;
				g_FLAME[z].condition = dead;
				g_ENEMY[x].health -= g_FLAME[0].damage;
			}

			if ( g_PULSE[z].condition != dead && g_ENEMY[x].condition == alive &&
					g_PULSE[z].position.y +32>= g_ENEMY[x].position.y 
					&& g_PULSE[z].position.y <= g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight 
					&& g_PULSE[z].position.x +32>= g_ENEMY[x].position.x 
					&& g_PULSE[z].position.x <= g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth)
				{
					g_ENEMY[x].health -= g_PULSE[0].damage;
				}
			

			//fix below
			if ( g_ELASER[z].condition != dead && g_PLAYER.condition == alive &&
				g_ELASER[z].position.y +32>= g_PLAYER.position.y 
				&& g_ELASER[z].position.y <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ELASER[z].position.x +32>= g_PLAYER.position.x
				&& g_ELASER[z].position.x <= g_PLAYER.position.x + g_PLAYER.SIZEwidth)
			{
				g_ELASER[z].condition = dead;
				g_ELASER[z].position.x = -1000;
				g_ELASER[z].position.y = -1000;
				g_PLAYER.health -= g_ELASER[z].damage;
				if (g_PLAYER.condition == alive)
				{
					g_HEAD[0].condition = dyingone;
					if (TALKING == no)
								{
					PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
				}

			} 

				//ERROR HERE
			if (g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x <= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss != bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

			if (g_ENEMY[x].position.y + 169 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y + 139 <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x <= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

			if (g_ENEMY[x].position.y + 201 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y + 170 <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + 412 >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x + 67 <= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

			if (g_ENEMY[x].position.y + 201 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y + 170 <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + 412 >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x + 67 <= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

			if (g_ENEMY[x].position.y + 230 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y + 202 <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + 334 >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x + 146<= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

			if (g_ENEMY[x].position.y + 298 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y + 231 <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + 257 >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x + 222 <= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}
			if (g_ENEMY[x].position.y + 138 >= g_PLAYER.position.y 
					&& g_ENEMY[x].position.y <= g_PLAYER.position.y + g_PLAYER.SIZEheight
				&& g_ENEMY[x].position.x + 333 >= g_PLAYER.position.x
				&& g_ENEMY[x].position.x + 146<= g_PLAYER.position.x + g_PLAYER.SIZEwidth
				&& g_ENEMY[x].condition == alive
				  && g_PLAYER.condition == alive && g_ENEMY[x].boss == bossfive)
				{
					g_ENEMY[x].health -= .25;
					g_PLAYER.health -= .25;
					if (g_PLAYER.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}

				}

				//ERROR HERE
			if (g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight >= g_ESCORT.position.y 
					&& g_ENEMY[x].position.y <= g_ESCORT.position.y + g_ESCORT.SIZEheight
				&& g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth >= g_ESCORT.position.x
				&& g_ENEMY[x].position.x <= g_ESCORT.position.x + g_ESCORT.SIZEwidth
				 && g_ENEMY[x].condition == alive
				  && g_ESCORT.condition == alive)
				{
					g_ENEMY[x].health = 0;
					g_ESCORT.health -= 1;
					if (g_ESCORT.condition == alive)
					{
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					
				}

				//ERROR HERE
			if ( g_ELASER[z].condition != dead && g_ESCORT.condition == alive &&
				g_ELASER[z].position.y +32>= g_ESCORT.position.y 
					&& g_ELASER[z].position.y <= g_ESCORT.position.y + g_ESCORT.SIZEheight
				&& g_ELASER[z].position.x +32>= g_ESCORT.position.x
				&& g_ELASER[z].position.x <= g_ESCORT.position.x + g_ESCORT.SIZEwidth)
				{
					g_ELASER[z].condition = dead;
					g_ELASER[z].position.x = -32;
					g_ELASER[z].position.y = -32;
					g_ESCORT.health -= g_ELASER[z].damage;
					if (g_ESCORT.condition == alive)
					{
						g_HEAD[0].condition = dyingone;
						PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					
				}

			//ERROR HERE
			if (g_ALLY[z].condition == alive
				&& g_ELASER[z].condition != dead
				&& g_ELASER[z].position.y + 32>= g_ALLY[z].position.y 
				&& g_ELASER[z].position.y <= g_ALLY[z].position.y + 32
				&& g_ELASER[z].position.x + 32>= g_ALLY[z].position.x
				&& g_ELASER[z].position.x <= g_ALLY[z].position.x + 32
				&& z < maxally)
			{
				g_ELASER[z].condition = dead;
				g_ELASER[z].position.x = -32;
				g_ELASER[z].position.y = -32;
				g_ALLY[z].health -= g_ELASER[z].damage;
				g_HEAD[z+1].condition = dyingone;
				PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
				if (g_ALLY[z].health <= 0)
				{
					g_HEAD[z+1].condition = unspawning;
					g_ALLY[z].condition = dead;
				}
			}
		}

		//OH GOD! SHIELD YOUR EYES!!! THERE MUST BE AN EASIER WAY TO DO THIS!!!
		//info for boss 1

		//BOSS ONE WING L
		
		//REMOVE THIS FUCKING CRAP
		
		if (g_ENEMY[19].health <= 0 && g_ENEMY[19].condition == alive && g_ENEMY[19].boss_condition == BOSSONEWINGL)
		{
			if (TALKING == no)
								{
			PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
			g_ENEMY[19].boss_condition = BOSSONEWINGLH;
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}
		else if (g_ENEMY[17].health <= 0 && g_ENEMY[19].health <= 0 && g_ENEMY[19].condition == alive && g_ENEMY[19].boss_condition == BOSSONEWINGLH)
		{
			g_ENEMY[19].boss_condition = BOSSONEWINGLD1;
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}
		else if (g_ENEMY[17].health <= 0 && g_ENEMY[19].health <= 0 && g_ENEMY[19].condition == alive && g_ENEMY[19].boss_condition == BOSSONEWINGLD1)
		{
			g_ENEMY[19].boss_condition = BOSSONEWINGLD1;
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}
		else if (g_ENEMY[19].health <= 0 && g_ENEMY[19].condition == alive && g_ENEMY[19].boss_condition == BOSSONEWINGLD2)
		{
			g_ENEMY[19].condition = dead;
			g_ENEMY[19].position.y = -32;
			g_ENEMY[19].position.x = -32;
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}

		//BOSS ONE WING R
		if (g_ENEMY[18].health <= 0 && g_ENEMY[18].condition == alive && g_ENEMY[18].boss_condition == BOSSONEWINGR)
		{
			if (TALKING == no)
								{
			PlaySound("Explode.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
			g_ENEMY[18].boss_condition = BOSSONEWINGRH;
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
		}
		else if (g_ENEMY[17].health <= 0 && g_ENEMY[18].health <= 0 && g_ENEMY[18].condition == alive && g_ENEMY[18].boss_condition == BOSSONEWINGRH)
		{
			g_ENEMY[18].boss_condition = BOSSONEWINGRD1;
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
		}
		else if (g_ENEMY[17].health <= 0 && g_ENEMY[18].health <= 0 && g_ENEMY[18].condition == alive && g_ENEMY[18].boss_condition == BOSSONEWINGRD1)
		{
			g_ENEMY[18].boss_condition = BOSSONEWINGRD1;
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
		}
		else if (g_ENEMY[18].health <= 0 && g_ENEMY[18].condition == alive && g_ENEMY[18].boss_condition == BOSSONEWINGRD2)
		{
			g_ENEMY[18].condition = dead;
			g_ENEMY[18].position.y = -32;
			g_ENEMY[18].position.x = -32;
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
		}

		//BOSS ONE PIT		
		if (g_ENEMY[17].health <= 0 && g_ENEMY[17].condition == alive && g_ENEMY[17].boss_condition == BOSSONEPIT)
		{
			g_ENEMY[17].boss_condition = BOSSONEPITD1;
			SetSpriteState(&g_ENEMY[17], g_ENEMY[17].boss_condition);
		}
		else if (g_ENEMY[17].boss_condition >= BOSSONEPITD1 && g_ENEMY[17].boss_condition < BOSSONEPITD5)
		{
			g_ENEMY[17].boss_condition++;
			SetSpriteState(&g_ENEMY[17], g_ENEMY[17].boss_condition);
		}
		else if (g_ENEMY[17].health <= 0 && g_ENEMY[17].condition == alive && g_ENEMY[17].boss_condition == BOSSONEPITD5)
		{
			g_ENEMY[17].condition = dead;
			g_ENEMY[17].position.y = -32;
			g_ENEMY[17].position.x = -32;
			SetSpriteState(&g_ENEMY[17], g_ENEMY[17].boss_condition);
		}		
			
		//UPDATE ALL LASER POSITIONS
		if (g_DLASER[z].position.y < 0 || g_DLASER[z].position.x < 0 || g_DLASER[z].position.x > 32 * GRID_WIDTH)
		{
			g_DLASER[z].condition = dead;
			g_DLASER[z].position.x = -32;
			g_DLASER[z].position.y = -32;
		}
		if (g_DLASER[z].condition == alive)
		{
			g_DLASER[z].position.y -= laserspeed;
			g_DLASER[z].position.x += g_DLASER[z].xhold;
		}	

		if (g_SLASER[z].position.x < 0 || g_SLASER[z].position.x > 480)
		{
			g_SLASER[z].condition = dead;
			g_SLASER[z].position.x = -32;
			g_SLASER[z].position.y = -32;
		}
		if (g_SLASER[z].condition == alive)
		{
			g_SLASER[z].position.x += g_SLASER[z].xhold;
		}	

		if (g_CHARGE[z].position.y < 0)
		{
			g_CHARGE[z].condition = dead;
			g_CHARGE[z].position.x = -32;
			g_CHARGE[z].position.y = -32;
		}
		if (g_CHARGE[z].condition == alive)
		{
			g_CHARGE[z].position.y -= laserspeed;
		}

			//targets for missile
		g_MISSILE[z].target = 0;
		for (int r = 0; r < max_level_tiles == alive; r++)
		{
			for (int q = 0; q < max_level_tiles; q++)
			{
				int addup;
				int addup2;
				if (g_ENEMY[r].condition == alive && g_ENEMY[q].condition == alive && q != r)
				{
					addup = g_ENEMY[r].position.y + g_ENEMY[r].position.x;
					addup2 = g_ENEMY[q].position.y + g_ENEMY[q].position.x;
					if (addup > addup2)
					{
						g_MISSILE[z].target = r;
					}
				}
				if (g_MISSILE[r].target == q && g_ENEMY[q].condition == dead)
				{
					g_MISSILE[r].target = r;
					break;
				}
			}
		}

		if (g_MISSILE[z].condition == alive)
		{
			for (int s = 0; s < max_level_tiles; s++)
			{
				if (g_SMOKE[0].condition == dead)
				{
					g_SMOKE[0].life = 0;
					g_SMOKE[0].position.y = g_MISSILE[z].position.y;
					g_SMOKE[0].position.x = g_MISSILE[z].position.x;
					g_SMOKE[0].type = rand1.RandInt(1,3);
					g_SMOKE[0].condition = alive;
					g_SMOKE[0].yhold = 0;
					g_SMOKE[0].xhold = rand1.RandInt(-1,1);
					break;
				}
				else if (g_SMOKE[s-1].life >= 14
					&& g_SMOKE[s].condition == dead)
				{
					g_SMOKE[s].life = 0;
					g_SMOKE[s].position.y = g_MISSILE[z].position.y + rand1.RandInt(4,12);
					g_SMOKE[s].position.x = g_MISSILE[z].position.x;
					g_SMOKE[s].condition = alive;
					g_SMOKE[s].type = rand1.RandInt(1,3);
					g_SMOKE[s].yhold = 0;
					g_SMOKE[s].xhold = rand1.RandInt(-1,1);
					break;
				}
			}
		}

		if (g_ENEMY[g_MISSILE[z].target].position.x - g_ENEMY[g_MISSILE[z].target].SIZEwidth/2
			> g_MISSILE[z].position.x && g_ENEMY[g_MISSILE[z].target].condition == alive)
		{
			g_MISSILE[z].position.x+=laserspeed;
			g_MISSILE[z].position.y-=laserspeed;
		}
		else if (g_ENEMY[g_MISSILE[z].target].position.x + g_ENEMY[g_MISSILE[z].target].SIZEwidth /2
			< g_MISSILE[z].position.x && g_ENEMY[g_MISSILE[z].target].condition == alive)
		{
			g_MISSILE[z].position.x-=laserspeed;
			g_MISSILE[z].position.y-=laserspeed;
		}
		else
		{
			g_MISSILE[z].position.y-=laserspeed;
		}

		if (g_MISSILE[z].position.y < 0)
		{
			g_MISSILE[z].condition = dead;
		}

		if (g_LASER[z].position.y < 0)
		{
			g_LASER[z].condition = dead;
			g_LASER[z].position.x = -32;
			g_LASER[z].position.y = -32;
		}
		if (g_LASER[z].condition == alive)
		{
			g_LASER[z].position.y -= laserspeed;
			g_LASER[z].position.x -= g_LASER[z].speed.x;
		}

		if (g_ALLYSHOT[z].position.y < 0)
		{
			g_ALLYSHOT[z].condition = dead;
			g_ALLYSHOT[z].position.x = -32;
			g_ALLYSHOT[z].position.y = -32;
		}
		if (g_ALLYSHOT[z].condition == alive)
		{
			g_ALLYSHOT[z].position.y -= laserspeed;
		}

		if (g_MGUN[z].position.y < 0)
		{
			g_MGUN[z].condition = dead;
			g_MGUN[z].position.x = -32;
			g_MGUN[z].position.y = -32;
		}
		if (g_MGUN[z].condition == alive)
		{
			g_MGUN[z].position.y -= mgunspeed;
			g_MGUN[z].position.x += g_MGUN[z].speed.x;
		}

		//make fade effect
		if (g_PULSE[z].condition == alive)
		{
			g_PULSE[z].condition = dyingone;
			SetSpriteState(&g_PULSE[z], EAST);
		}
		else if (g_PULSE[z].condition == dyingone)
		{
			g_PULSE[z].condition = dyingtwo;
			SetSpriteState(&g_PULSE[z], SOUTH);
		}
		else if (g_PULSE[z].condition == dyingtwo)
		{
			g_PULSE[z].condition = dyingthree;
			SetSpriteState(&g_PULSE[z], WEST);
		}
		else if (g_PULSE[z].condition == dyingthree)
		{
			g_PULSE[z].condition = dyingfour;
			SetSpriteState(&g_PULSE[z], NONE);
		}
		else if (g_PULSE[z].condition == dyingfour)
		{
			g_PULSE[z].condition = dead;
			SetSpriteState(&g_PULSE[z], NORTH);
			g_PULSE[z].position.y = -32;
			g_PULSE[z].position.x = -32;
		}

		//life : life of flame...make fade effect

		g_FLAME[z].life--;
		g_FLAME[z].position.y -= flamespeed;
		g_FLAME[z].position.x -= g_FLAME[z].speed.x;

		if (g_FLAME[z].condition == alive)
		{
			SetSpriteState(&g_FLAME[z], NORTH);
			g_FLAME[z].condition = 100;
		}
		else if (g_FLAME[z].condition == 100)
		{
			SetSpriteState(&g_FLAME[z], NONE);
			g_FLAME[z].condition = alive;
		}

		if (g_FLAME[z].life == 2)
		{
			g_FLAME[z].condition = dyingone;
			SetSpriteState(&g_FLAME[z], EAST);
		}
		else if (g_FLAME[z].life == 1)
		{
			g_FLAME[z].condition = dyingtwo;
			SetSpriteState(&g_FLAME[z], SOUTH);
		}
		else if (g_FLAME[z].life == 0)
		{
			g_FLAME[z].condition = dyingthree;
			SetSpriteState(&g_FLAME[z], WEST);
		}
		else if (g_FLAME[z].life <= -1)
		{
			g_FLAME[z].condition = dead;
			SetSpriteState(&g_FLAME[z], NORTH);
			g_FLAME[z].position.y = -32;
			g_FLAME[z].position.x = -32;
		}		
	}
}