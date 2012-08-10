void update_allys()
{
	if(GetAsyncKeyState(VK_PRIOR))
		{
			for (int x = 0; x < maxally; x++)
			{
				if (g_ALLY[x].formation_type != breakformation)
				{
					if (g_ALLY[x].formation_range < maxcloseformation)
					{
						g_ALLY[x].formation_range = maxcloseformation;
					}
					if (g_ALLY[x].formation_range > maxcloseformation)
					{
						g_ALLY[x].formation_range -= 32;
						if (TALKING == no)
								{
						PlaySound("tightening_formation.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else
					{
						if (TALKING == no)
								{
						PlaySound("sorry_i_cant.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
				}
				else
				{
					if (g_ALLY[x].formation_range == defending)
					{
						g_ALLY[x].formation_range = passive;
						if (TALKING == no)
								{
						PlaySound("passive.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else if (g_ALLY[x].formation_range != defending)
					{
						g_ALLY[x].formation_range = defending;
						if (TALKING == no)
								{
						PlaySound("defending.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else
					{
						if (TALKING == no)
								{
						PlaySound("passive.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
				}
			}
			Sleep(500);
		}
		if(GetAsyncKeyState(VK_NEXT))
		{
			for (int x = 0; x < maxally; x++)
			{
				if (g_ALLY[x].formation_type != breakformation)
				{
					if (g_ALLY[x].formation_range > maxopenformation)
					{
						g_ALLY[x].formation_range = maxcloseformation;
					}
					if (g_ALLY[x].formation_range < maxopenformation)
					{
						g_ALLY[x].formation_range += 32;
						if (TALKING == no)
								{
						PlaySound("loosening_formation.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else
					{
						if (TALKING == no)
								{
						PlaySound("sorry_i_cant.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
				}
				else
				{
					if (g_ALLY[x].formation_range == defending)
					{
						g_ALLY[x].formation_range = attacking;
						if (TALKING == no)
								{
						PlaySound("attacking.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else if (g_ALLY[x].formation_range != defending)
					{
						g_ALLY[x].formation_range = defending;
						if (TALKING == no)
								{
						PlaySound("defending.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					else
					{
						if (TALKING == no)
								{
						PlaySound("attacking.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
				}

			}
			Sleep(500);
		}
		if(GetAsyncKeyState(VK_HOME))
		{
			for (int x = 0; x < maxally; x++)
			{
				if (g_ALLY[x].formation_type < breakformation)
				{
					g_ALLY[x].formation_type++;

					if (g_ALLY[x].formation_type == columnformation)
					{
						if (TALKING == no)
								{
						PlaySound("taking_column.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					if (g_ALLY[x].formation_type == coverformation)
					{
						if (TALKING == no)
								{
						PlaySound("gotcha_covered.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
					if (g_ALLY[x].formation_type == breakformation)
					{
						g_ALLY[x].defend_formation_hold = 125;
						g_ALLY[x].formation_range = defending;
						if (TALKING == no)
								{
						PlaySound("breaking_formation.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
					}
				}
				else
				{
					g_ALLY[x].formation_type = wedgeformation;
					if (TALKING == no)
								{
					PlaySound("taking_wedge.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
				}
				if (g_ALLY[x].formation_type > breakformation)
				{
					g_ALLY[x].formation_type = 0;
				}
				if (g_ALLY[x].formation_type < 0)
				{
					g_ALLY[x].formation_type = 0;
				}
			}
			Sleep(500);
		}

		///////////////////////////////////////////////////

		for (int x = 0; x < maxally; x++)
		{
			g_ALLY[x].formationtime++;
			if (x % 2 == 0 && g_ALLY[x].condition > dead)
			{
				int signal = 0;
					if (g_ALLY[x].xhold <= 0)
					{
		
						if (g_ALLY[x].formation_type == wedgeformation || g_ALLY[x].temp_formation == wedgeformation)
						{
							if (g_ALLY[x].position.y >= g_PLAYER.position.y + 64 + g_ALLY[x].formation_range + (x * gridalignment))
							{
								g_ALLY[x].position.y -= allyspeed;
								SetSpriteState(&g_ALLY[x], NORTH);
								signal = 1;
							}
							else if (g_ALLY[x].position.y <= g_PLAYER.position.y + 48 + g_ALLY[x].formation_range  + (x * gridalignment)
								&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
							{
								g_ALLY[x].position.y += allyspeed;
								SetSpriteState(&g_ALLY[x], SOUTH);
								signal = 1;
							}
							if (g_ALLY[x].position.x >= g_PLAYER.position.x - 48 - g_ALLY[x].formation_range - (x * gridalignment))
							{
								g_ALLY[x].position.x -= allyspeed;
								SetSpriteState(&g_ALLY[x], WEST);
								signal = 1;
							}
							else if (g_ALLY[x].position.x <= g_PLAYER.position.x - 64 - g_ALLY[x].formation_range  - (x * gridalignment)
								 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
							{
								g_ALLY[x].position.x += allyspeed;
								SetSpriteState(&g_ALLY[x], EAST);
								signal = 1;
							}
						}
						if (g_ALLY[x].formation_type == lineformation || g_ALLY[x].temp_formation == lineformation)
						{
							if (g_ALLY[x].position.y >= g_PLAYER.position.y + 8 + (x * 8))
							{
								g_ALLY[x].position.y -= allyspeed;
								SetSpriteState(&g_ALLY[x], NORTH);
								signal = 1;
							}
							else if (g_ALLY[x].position.y <= g_PLAYER.position.y - 8 - (x * 8)
								&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
							{
								g_ALLY[x].position.y += allyspeed;
								SetSpriteState(&g_ALLY[x], SOUTH);
								signal = 1;
							}
							if (g_ALLY[x].position.x >= g_PLAYER.position.x - 48 - g_ALLY[x].formation_range - (x * gridalignment))
							{
								g_ALLY[x].position.x -= allyspeed;
								SetSpriteState(&g_ALLY[x], WEST);
								signal = 1;
							}
							else if (g_ALLY[x].position.x <= g_PLAYER.position.x - 64 - g_ALLY[x].formation_range
								 - (x * gridalignment)
								 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
							{
								g_ALLY[x].position.x += allyspeed;
								SetSpriteState(&g_ALLY[x], EAST);
								signal = 1;
							}
						}
						if (g_ALLY[x].formation_type == columnformation || g_ALLY[x].temp_formation == columnformation)
						{
							if (g_ALLY[x].position.y >= g_PLAYER.position.y + 64 + (int) (g_ALLY[x].formation_range / 2)  + (x * gridalignment) )
							{
								g_ALLY[x].position.y -= allyspeed;
								SetSpriteState(&g_ALLY[x], NORTH);
								signal = 1;
							}
							else if (g_ALLY[x].position.y <= g_PLAYER.position.y + 48 + (int) (g_ALLY[x].formation_range / 2)  + (x * gridalignment)
								&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
							{
								g_ALLY[x].position.y += allyspeed;
								SetSpriteState(&g_ALLY[x], SOUTH);
								signal = 1;
							}
							if (g_ALLY[x].position.x >= g_PLAYER.position.x - 16)
							{
								g_ALLY[x].position.x -= allyspeed;
								SetSpriteState(&g_ALLY[x], WEST);
								signal = 1;
							}
							else if (g_ALLY[x].position.x <= g_PLAYER.position.x - 32
								 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
							{
								g_ALLY[x].position.x += allyspeed;
								SetSpriteState(&g_ALLY[x], EAST);
								signal = 1;
							}
						}
						if (g_ALLY[x].formation_type == coverformation || g_ALLY[x].temp_formation == coverformation)
						{
							if (g_ALLY[x].position.y >= g_PLAYER.position.y + 16 + (int) (g_ALLY[x].formation_range / 2) + (x * gridalignment))
							{
								g_ALLY[x].position.y -= allyspeed;
								SetSpriteState(&g_ALLY[x], NORTH);
								signal = 1;
							}
							else if (g_ALLY[x].position.y <= g_PLAYER.position.y - 16 - (int) (g_ALLY[x].formation_range / 2) - (x * gridalignment)
								&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
							{
								g_ALLY[x].position.y += allyspeed;
								SetSpriteState(&g_ALLY[x], SOUTH);
								signal = 1;
							}
							if (g_ALLY[x].position.x >= g_PLAYER.position.x + 16 + (int) (g_ALLY[x].formation_range / 2)  + (x * gridalignment))
							{
								g_ALLY[x].position.x -= allyspeed;
								SetSpriteState(&g_ALLY[x], WEST);
								signal = 1;
							}
							else if (g_ALLY[x].position.x <= g_PLAYER.position.x - 16 - (int) (g_ALLY[x].formation_range / 2) - (x * gridalignment)
								 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
							{
								g_ALLY[x].position.x += allyspeed;
								SetSpriteState(&g_ALLY[x], EAST);
								signal = 1;
							}
						}

					}
					if (g_ALLY[x].formation_type == coverformation || g_ALLY[x].formation_type == coverformation || g_ALLY[x].temp_formation == 255)
				{
					for (int z = 0; z < lasermax; z++)
					{
						random = rand1.RandInt(0, 6);
						if (g_ALLY[x].condition == alive && g_ALLY[x].position.y > 0 && random == 1)
						{

							if (g_ALLYSHOT[0].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ALLYSHOT[0].position.x = g_ALLY[x].position.x;
								g_ALLYSHOT[0].position.y = g_ALLY[x].position.y - 8;
								g_ALLYSHOT[0].condition = alive;
								break;
							}
							else if (g_ALLYSHOT[z-1].condition == alive &&  g_ALLYSHOT[z].condition == dead && g_ALLY[z-1].shothold >= 2)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ALLYSHOT[z].position.x = g_ALLY[x].position.x;
								g_ALLYSHOT[z].position.y = g_ALLY[x].position.y - 8;
								g_ALLYSHOT[z].condition = alive;
								break;
							}
						}
					}
				}

				if (g_ALLY[x].formation_range != attacking)
				{
					for (int r = 0; r < max_level_tiles;r++)
							{	
								int signal2 = 0;
								if (g_ALLY[x].xhold <= 0)
								{
									
									if (g_ELASER[r].condition == alive && g_ELASER[r].position.x < g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].toleft--;	
									}
									else if (g_ELASER[r].condition == alive && g_ELASER[r].position.x > g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].toleft++;	
									}
								
									
									if (g_ELASER[r].condition == alive && g_ELASER[r].position.x - 16 <= g_ALLY[x].position.x && g_ELASER[r].position.x + 16 >= g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].xhold = 0;
										signal2 = 1;
									}
									
									if (g_ALLY[x].toleft > 0 && signal2 == 1)
									{
										g_ALLY[x].xhold = 64;
									}
									else if (g_ALLY[x].toleft < 0 && signal2 == 1)
									{
										g_ALLY[x].xhold = 64;
									}
								}
							}
							if (g_ALLY[x].xhold >= 0)
							{
								if (g_ALLY[x].toleft >= 0 && g_ALLY[x].position.x - allyspeed > 0)
								{
									g_ALLY[x].position.x -= allyspeed;
									g_ALLY[x].xhold-= allyspeed / 1.5;
									SetSpriteState(&g_ALLY[x], WEST);
									signal = 1;
									break;
								}
								else
								{
									g_ALLY[x].toleft = -1;
								}
								if (g_ALLY[x].toleft < 0 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
								{
									g_ALLY[x].position.x += allyspeed;
									g_ALLY[x].xhold-= allyspeed / 1.5;
									SetSpriteState(&g_ALLY[x], EAST);
									signal = 1;
									break;
								}
								else
								{
									g_ALLY[x].toleft = 1;
								}
							}
				}

				if (g_ALLY[x].formation_range == attacking)
				{
					g_ALLY[x].temp_formation = breakformation;
				}
				if (g_ALLY[x].formation_type == breakformation && g_ALLY[x].formationtime >= 200 && g_ALLY[x].formation_range == defending)
				{
					
						int min1 = -1;
						int min2 = -1;
						int max1 = -1;
						int max2 = -1;
						int ecount = 0;
						for (int j = 0; j < max_level_tiles;j++)
						{
							if (g_ENEMY[j].condition == alive)
							{
								ecount++;
							}
							if ((g_ENEMY[j].position.x < min1 || min1 == -1) && g_ENEMY[j].condition == alive)
							{
								min1 = g_ENEMY[j].position.x;
							}
							else if ((g_ENEMY[j].position.x < min2 || min2 == -1) && g_ENEMY[j].condition == alive)
							{
								min2 = g_ENEMY[j].position.x;
							}
							if ((g_ENEMY[j].position.x > max1 || max1 == -1) && g_ENEMY[j].condition == alive)
							{
								max1 = g_ENEMY[j].position.x;
							}
							else if ((g_ENEMY[j].position.x > max2 || max2 == -1) && g_ENEMY[j].condition == alive)
							{
								max2 = g_ENEMY[j].position.x;
							}
						}

						int determine [4] = {(max1 - min1), (max2 - min2),(max1 - min2),(max2 - min1)};
						int count = 0;
						int count2 = 0;

						for (int y = 0; y < 4; y++)
						{
							if (determine[y] > 214 && ecount >=4)
							{
								count++;
							}
							else if (determine[y] > 0 && ecount >=4)
							{
								count2++;
							}
						}
						if (count > count2)
						{
							int ymin1 = -1;
							int ymin2 = -1;
							int ymax1 = -1;
							int ymax2 = -1;
							int yecount = 0;
							for (int j = 0; j < max_level_tiles;j++)
							{
								if (g_ENEMY[j].condition == alive)
								{
									yecount++;
								}
								if ((g_ENEMY[j].position.y < ymin1 || ymin1 == -1) && g_ENEMY[j].condition == alive)
								{
									ymin1 = g_ENEMY[j].position.y;
								}
								else if ((g_ENEMY[j].position.y < ymin2 || ymin2 == -1) && g_ENEMY[j].condition == alive)
								{
									ymin2 = g_ENEMY[j].position.y;
								}
								if ((g_ENEMY[j].position.y > ymax1 || ymax1 == -1) && g_ENEMY[j].condition == alive)
								{
									ymax1 = g_ENEMY[j].position.y;
								}
								else if ((g_ENEMY[j].position.y > ymax2 || ymax2 == -1) && g_ENEMY[j].condition == alive)
								{
									ymax2 = g_ENEMY[j].position.y;
								}
							}
							int ydetermine [4] = {(ymax1 - ymin1), (ymax2 - ymin2),(ymax1 - ymin2),(ymax2 - ymin1)};
							int ycount = 0;
							int ycount2 = 0;

							for (int t = 0; t < 4; t++)
							{
								if (ydetermine[t] > 170)
								{
									ycount++;
								}
								else if (ydetermine[t] > 0)
								{
									ycount2++;
								}
							}

							if (ycount > ycount2)
							{
								g_ALLY[x].formationtime = 0;
								g_ALLY[x].temp_formation = lineformation;
							}
							else if (ycount2 > ycount)
							{
								g_ALLY[x].formationtime = 0;
								g_ALLY[x].temp_formation = wedgeformation;
							}
							else
							{
								g_ALLY[x].temp_formation = breakformation;
							}
						}
						else if (count2 > count)
						{
							g_ALLY[x].formationtime = 0;
							g_ALLY[x].temp_formation = columnformation;
						}
						else
						{
							g_ALLY[x].temp_formation = breakformation;
						}
						if (ecount <= 0)
						{
							g_ALLY[x].temp_formation = lineformation;
						}
						if (g_PLAYER.health <= 2)
						{
							g_ALLY[x].temp_formation = coverformation;
						}
						for (int u = 0; u < 5; u++)
						{
							if (g_POWERUP[u].condition == alive)
							{
								g_ALLY[x].temp_formation = 255;
								g_ALLY[x].formationtime = 200;
								if (g_POWERUP[u].position.x + g_POWERUP[u].SIZEwidth < g_ALLY[x].position.x + 12)
								{
									g_ALLY[x].position.x -= allyspeed;
									SetSpriteState(&g_ALLY[x], WEST);
								}
								if (g_POWERUP[u].position.x > g_ALLY[x].position.x + g_ALLY[x].SIZEwidth - 12)
								{
									g_ALLY[x].position.x += allyspeed;
									SetSpriteState(&g_ALLY[x], EAST);
								}
								break;
							}
						}
				}
				if (g_ALLY[x].formation_type == breakformation && g_ALLY[x].temp_formation == breakformation && g_ALLY[x].formation_range != passive)
				{
					int s = 0;
					int n = 0;

					if (g_ENEMY[g_ALLY[x].target].condition == dead || g_ENEMY[g_ALLY[x].target].SIZEheight + 128 > gridalignment * 15)
					{
						g_ALLY[x].target = findclosest(0, x);
					}
					if (g_ENEMY[g_ALLY[x].target].condition == alive)
					{
						if (g_ENEMY[g_ALLY[x].target].position.y + g_ENEMY[g_ALLY[x].target].SIZEheight + 64 + (16 * x)> g_ALLY[x].position.y)
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							s = 1;
						}
						if (g_ENEMY[g_ALLY[x].target].position.y + g_ENEMY[g_ALLY[x].target].SIZEheight + 68 + (16 * x) < g_ALLY[x].position.y)
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							n = 1;
						}
						if (g_ENEMY[g_ALLY[x].target].position.x + g_ENEMY[g_ALLY[x].target].SIZEwidth < g_ALLY[x].position.x + 4)
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							if (s == 1)
							{
								SetSpriteState(&g_ALLY[x], SOUTHWEST);
							}
							if (n == 1)
							{
								SetSpriteState(&g_ALLY[x], NORTHWEST);
							}
						}
						if (g_ENEMY[g_ALLY[x].target].position.x > g_ALLY[x].position.x + g_ALLY[x].SIZEwidth - 4)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							if (s == 1)
							{
								SetSpriteState(&g_ALLY[x], SOUTHEAST);
							}
							if (n == 1)
							{
								SetSpriteState(&g_ALLY[x], NORTHEAST);
							}
						}
					}
				}		

				for (int k = 0; k < max_level_tiles; k++)
						{
							if (g_ENEMY[k].condition == alive &&
								g_ENEMY[k].position.y < g_ALLY[x].position.y)
							{
								for (int a = 0; a < lasermax; a++)
								{
									random = rand1.RandInt(0, 6);
									if (g_ALLY[x].condition == alive && g_ALLY[x].position.y > 0 && random == 1)
									{

										if (g_ALLYSHOT[0].condition == dead)
										{
											if (TALKING == no)
								{
											PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
											}
											g_ALLYSHOT[0].position.x = g_ALLY[x].position.x;
											g_ALLYSHOT[0].position.y = g_ALLY[x].position.y - 8;
											g_ALLYSHOT[0].condition = alive;
											break;
										}
										else if (g_ALLYSHOT[a-1].condition == alive &&  g_ALLYSHOT[a].condition == dead && g_ALLY[a-1].shothold >= 2)
										{
											if (TALKING == no)
								{
											PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
											}
											g_ALLYSHOT[a].position.x = g_ALLY[x].position.x;
											g_ALLYSHOT[a].position.y = g_ALLY[x].position.y - 8;
											g_ALLYSHOT[a].condition = alive;
											break;
										}
									}
								}
							}
						}
				
				if (signal == 0)
				{
					if (g_time % 2 == 0)
					{
						SetSpriteState(&g_ALLY[x], NONE);
					}
					if (g_time % 2 == 1)
					{
						SetSpriteState(&g_ALLY[x], NORTH);
					}
					if (g_time % 2 == 2)
					{
						SetSpriteState(&g_ALLY[x], SOUTH);
					}
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (g_ALLY[x].condition > dead)
			{
				int signal = 0;
				if (g_ALLY[x].xhold <= 0)
				{
					if (g_ALLY[x].formation_type == wedgeformation  || g_ALLY[x].temp_formation == wedgeformation)
					{
						if (g_ALLY[x].position.y >= g_PLAYER.position.y + 64 + g_ALLY[x].formation_range  + ((x - 1) * (gridalignment)))
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							signal = 1;
						}
						else if (g_ALLY[x].position.y <= g_PLAYER.position.y + 48 + g_ALLY[x].formation_range  + ((x - 1) * (gridalignment))
							&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							signal = 1;
						}
						if (g_ALLY[x].position.x >= g_PLAYER.position.x + 64 + g_ALLY[x].formation_range  + ((x - 1) * (gridalignment)))
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							signal = 1;
						}
						else if (g_ALLY[x].position.x <= g_PLAYER.position.x + 48 + g_ALLY[x].formation_range + ((x - 1) * (gridalignment))
							&& g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							signal = 1;
						}
					}
					if (g_ALLY[x].formation_type == lineformation || g_ALLY[x].temp_formation == lineformation)
					{
						if (g_ALLY[x].position.y >= g_PLAYER.position.y + 8 + ((x-1) * 8))
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							signal = 1;
						}
						else if (g_ALLY[x].position.y <= g_PLAYER.position.y - 8 - ((x-1) * 8)
							&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							signal = 1;
						}
						if (g_ALLY[x].position.x >= g_PLAYER.position.x + 64 + g_ALLY[x].formation_range + ((x - 1) * gridalignment))
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							signal = 1;
						}
						else if (g_ALLY[x].position.x <= g_PLAYER.position.x + 48 + g_ALLY[x].formation_range + ((x - 1) * gridalignment)
							 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							signal = 1;
						}
					}
					if (g_ALLY[x].formation_type == columnformation || g_ALLY[x].temp_formation == columnformation)
					{
						if (g_ALLY[x].position.y >= g_PLAYER.position.y + 128 + g_ALLY[x].formation_range + ((x - 1) * gridalignment))
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							signal = 1;
						}
						else if (g_ALLY[x].position.y <= g_PLAYER.position.y + 112 + g_ALLY[x].formation_range + ((x - 1) * gridalignment)
							&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							signal = 1;
						}
						if (g_ALLY[x].position.x >= g_PLAYER.position.x + 32)
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							signal = 1;
						}
						else if (g_ALLY[x].position.x <= g_PLAYER.position.x + 16
							 && g_ALLY[x].position.y + allyspeed < gridalignment * fixmaxmovement)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							signal = 1;
						}
					}
					if (g_ALLY[x].formation_type == coverformation || g_ALLY[x].temp_formation == columnformation)
					{
						if (g_ALLY[x].position.y >= g_PLAYER.position.y + 96 + g_ALLY[x].formation_range + (x * gridalignment))
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							signal = 1;
						}
						else if (g_ALLY[x].position.y <= g_PLAYER.position.y - 96 - g_ALLY[x].formation_range - (x * gridalignment)
							&& g_ALLY[x].position.y + allyspeed < gridalignment * (fixmaxmovement - 1))
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							signal = 1;
						}
						if (g_ALLY[x].position.x >= g_PLAYER.position.x + 80 + g_ALLY[x].formation_range + (x * gridalignment))
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							signal = 1;
						}
						else if (g_ALLY[x].position.x <= g_PLAYER.position.x - 80 - g_ALLY[x].formation_range - (x * gridalignment)
							 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							signal = 1;
						}
					}
				}

					if (g_ALLY[x].formation_type == coverformation || g_ALLY[x].formation_type == coverformation || g_ALLY[x].temp_formation == 255)
				{
					for (int z = 0; z < lasermax; z++)
					{
						random = rand1.RandInt(0, 6);
						if (g_ALLY[x].condition == alive && g_ALLY[x].position.y > 0 && random == 1)
						{

							if (g_ALLYSHOT[0].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ALLYSHOT[0].position.x = g_ALLY[x].position.x;
								g_ALLYSHOT[0].position.y = g_ALLY[x].position.y - 8;
								g_ALLYSHOT[0].condition = alive;
								break;
							}
							else if (g_ALLYSHOT[z-1].condition == alive &&  g_ALLYSHOT[z].condition == dead && g_ALLY[z-1].shothold >= 2)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ALLYSHOT[z].position.x = g_ALLY[x].position.x;
								g_ALLYSHOT[z].position.y = g_ALLY[x].position.y - 8;
								g_ALLYSHOT[z].condition = alive;
								break;
							}
						}
					}
				}


				if (g_ALLY[x].formation_range != attacking)
				{
					for (int r = 0; r < max_level_tiles;r++)
							{	
								int signal2 = 0;
								if (g_ALLY[x].xhold <= 0)
								{
									
									if (g_ELASER[r].condition == alive && g_ELASER[r].position.x < g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].toleft--;	
									}
									else if (g_ELASER[r].condition == alive && g_ELASER[r].position.x > g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].toleft++;	
									}
								
									
									if (g_ELASER[r].condition == alive && g_ELASER[r].position.x - 16 <= g_ALLY[x].position.x && g_ELASER[r].position.x + 16 >= g_ALLY[x].position.x && g_ELASER[r].position.y + 8  <= g_ALLY[x].position.y)
									{
										g_ALLY[x].xhold = 0;
										signal2 = 1;
									}
									
									if (g_ALLY[x].toleft > 0 && signal2 == 1)
									{
										g_ALLY[x].xhold = 64;
									}
									else if (g_ALLY[x].toleft < 0 && signal2 == 1)
									{
										g_ALLY[x].xhold = 64;
									}
								}
							}
							if (g_ALLY[x].xhold >= 0)
							{
								if (g_ALLY[x].toleft >= 0 && g_ALLY[x].position.x - allyspeed > 0)
								{
									g_ALLY[x].position.x -= allyspeed;
									g_ALLY[x].xhold-= allyspeed / 1.5;
									SetSpriteState(&g_ALLY[x], WEST);
									signal = 1;
									break;
								}
								else
								{
									g_ALLY[x].toleft = -1;
								}
								if (g_ALLY[x].toleft < 0 && g_ALLY[x].position.x + allyspeed < gridalignment * fixmaxmovement)
								{
									g_ALLY[x].position.x += allyspeed;
									g_ALLY[x].xhold-= allyspeed / 1.5;
									SetSpriteState(&g_ALLY[x], EAST);
									signal = 1;
									break;
								}
								else
								{
									g_ALLY[x].toleft = 1;
								}
							}

				}
				if (g_ALLY[x].formation_range == attacking)
				{
					g_ALLY[x].temp_formation = breakformation;
				}
				if (g_ALLY[x].formation_type == breakformation && g_ALLY[x].formationtime >= 200 && g_ALLY[x].formation_range == defending)
				{
					
						int min1 = -1;
						int min2 = -1;
						int max1 = -1;
						int max2 = -1;
						int ecount = 0;
						for (int j = 0; j < max_level_tiles;j++)
						{
							if (g_ENEMY[j].condition == alive)
							{
								ecount++;
							}
							if ((g_ENEMY[j].position.x < min1 || min1 == -1) && g_ENEMY[j].condition == alive)
							{
								min1 = g_ENEMY[j].position.x;
							}
							else if ((g_ENEMY[j].position.x < min2 || min2 == -1) && g_ENEMY[j].condition == alive)
							{
								min2 = g_ENEMY[j].position.x;
							}
							if ((g_ENEMY[j].position.x > max1 || max1 == -1) && g_ENEMY[j].condition == alive)
							{
								max1 = g_ENEMY[j].position.x;
							}
							else if ((g_ENEMY[j].position.x > max2 || max2 == -1) && g_ENEMY[j].condition == alive)
							{
								max2 = g_ENEMY[j].position.x;
							}
						}

						int determine [4] = {(max1 - min1), (max2 - min2),(max1 - min2),(max2 - min1),};
						int count = 0;
						int count2 = 0;

						for (int y = 0; y < 4; y++)
						{
							if (determine[y] > 214 && ecount >=4)
							{
								count++;
							}
							else if (determine[y] > 0 && ecount >=4)
							{
								count2++;
							}
						}
						if (count > count2)
						{
							int ymin1 = -1;
							int ymin2 = -1;
							int ymax1 = -1;
							int ymax2 = -1;
							int yecount = 0;
							for (int j = 0; j < max_level_tiles;j++)
							{
								if (g_ENEMY[j].condition == alive)
								{
									yecount++;
								}
								if ((g_ENEMY[j].position.y < min1 || min1 == -1) && g_ENEMY[j].condition == alive)
								{
									ymin1 = g_ENEMY[j].position.y;
								}
								else if ((g_ENEMY[j].position.y < min2 || min2 == -1) && g_ENEMY[j].condition == alive)
								{
									ymin2 = g_ENEMY[j].position.y;
								}
								if ((g_ENEMY[j].position.y > max1 || max1 == -1) && g_ENEMY[j].condition == alive)
								{
									ymax1 = g_ENEMY[j].position.y;
								}
								else if ((g_ENEMY[j].position.y > max2 || max2 == -1) && g_ENEMY[j].condition == alive)
								{
									ymax2 = g_ENEMY[j].position.y;
								}
							}
							int ydetermine [4] = {(max1 - min1), (max2 - min2),(max1 - min2),(max2 - min1),};
							int ycount = 0;
							int ycount2 = 0;

							for (int t = 0; t < 4; t++)
							{
								if (ydetermine[t] > 170)
								{
									ycount++;
								}
								else if (ydetermine[t] > 0)
								{
									ycount2++;
								}
							}

							if (ycount > ycount2)
							{
								g_ALLY[x].formationtime = 0;
								g_ALLY[x].temp_formation = lineformation;
							}
							else if (ycount2 > ycount)
							{
								g_ALLY[x].formationtime = 0;
								g_ALLY[x].temp_formation = wedgeformation;
							}
							else
							{
								g_ALLY[x].temp_formation = breakformation;
							}
						}
						else if (count2 > count)
						{
							g_ALLY[x].formationtime = 0;
							g_ALLY[x].temp_formation = columnformation;
						}
						else
						{
							g_ALLY[x].temp_formation = breakformation;
						}
						if (ecount <= 0)
						{
							g_ALLY[x].temp_formation = lineformation;
						}
						if (g_PLAYER.health <= 2)
						{
							g_ALLY[x].temp_formation = coverformation;
						}
						for (int u = 0; u < 5; u++)
						{
							if (g_POWERUP[u].condition == alive)
							{
								g_ALLY[x].temp_formation = 255;
								g_ALLY[x].formationtime = 200;
								if (g_POWERUP[u].position.x + g_POWERUP[u].SIZEwidth < g_ALLY[x].position.x + 12)
								{
									g_ALLY[x].position.x -= allyspeed;
									SetSpriteState(&g_ALLY[x], WEST);
								}
								if (g_POWERUP[u].position.x > g_ALLY[x].position.x + g_ALLY[x].SIZEwidth - 12)
								{
									g_ALLY[x].position.x += allyspeed;
									SetSpriteState(&g_ALLY[x], EAST);
								}
								break;
							}
						}
				}
				if (g_ALLY[x].formation_type == breakformation && g_ALLY[x].temp_formation == breakformation && g_ALLY[x].formation_range != passive)
				{
					int s = 0;
					int n = 0;

					if (g_ENEMY[g_ALLY[x].target].condition == dead || g_ENEMY[g_ALLY[x].target].SIZEheight + 128 > gridalignment * 15)
					{
						g_ALLY[x].target = findclosest(0, x);
					}
					if (g_ENEMY[g_ALLY[x].target].condition == alive)
					{
						if (g_ENEMY[g_ALLY[x].target].position.y + g_ENEMY[g_ALLY[x].target].SIZEheight + 64  + (16 * x)> g_ALLY[x].position.y)
						{
							g_ALLY[x].position.y += allyspeed;
							SetSpriteState(&g_ALLY[x], SOUTH);
							s = 1;
						}
						if (g_ENEMY[g_ALLY[x].target].position.y + g_ENEMY[g_ALLY[x].target].SIZEheight + 68  + (16 * x)< g_ALLY[x].position.y)
						{
							g_ALLY[x].position.y -= allyspeed;
							SetSpriteState(&g_ALLY[x], NORTH);
							n = 1;
						}
						if (g_ENEMY[g_ALLY[x].target].position.x + g_ENEMY[g_ALLY[x].target].SIZEwidth < g_ALLY[x].position.x + 4)
						{
							g_ALLY[x].position.x -= allyspeed;
							SetSpriteState(&g_ALLY[x], WEST);
							if (s == 1)
							{
								SetSpriteState(&g_ALLY[x], SOUTHWEST);
							}
							if (n == 1)
							{
								SetSpriteState(&g_ALLY[x], NORTHWEST);
							}
						}
						if (g_ENEMY[g_ALLY[x].target].position.x > g_ALLY[x].position.x + g_ALLY[x].SIZEwidth - 4)
						{
							g_ALLY[x].position.x += allyspeed;
							SetSpriteState(&g_ALLY[x], EAST);
							if (s == 1)
							{
								SetSpriteState(&g_ALLY[x], SOUTHEAST);
							}
							if (n == 1)
							{
								SetSpriteState(&g_ALLY[x], NORTHEAST);
							}
						}
					}
				}
				for (int k = 0; k < max_level_tiles; k++)
						{
							if (g_ENEMY[k].condition == alive &&
								g_ENEMY[k].position.y < g_ALLY[x].position.y)
							{
								for (int a = 0; a < lasermax; a++)
								{
									random = rand1.RandInt(0, 6);
									if (g_ALLY[x].condition == alive && g_ALLY[x].position.y > 0 && random == 1)
									{

										if (g_ALLYSHOT[0].condition == dead)
										{
											if (TALKING == no)
								{
											PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
											}
											g_ALLYSHOT[0].position.x = g_ALLY[x].position.x;
											g_ALLYSHOT[0].position.y = g_ALLY[x].position.y - 8;
											g_ALLYSHOT[0].condition = alive;
											break;
										}
										else if (g_ALLYSHOT[a-1].condition == alive &&  g_ALLYSHOT[a].condition == dead && g_ALLY[a-1].shothold >= 2)
										{
											if (TALKING == no)
								{
											PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
											}
											g_ALLYSHOT[a].position.x = g_ALLY[x].position.x;
											g_ALLYSHOT[a].position.y = g_ALLY[x].position.y - 8;
											g_ALLYSHOT[a].condition = alive;
											break;
										}
									}
								}
							}
						}
				if (signal == 0)
				{
					if (g_time % 2 == 0)
					{
						SetSpriteState(&g_ALLY[x], NONE);
					}
					if (g_time % 2 == 1)
					{
						SetSpriteState(&g_ALLY[x], NORTH);
					}
					if (g_time % 2 == 2)
					{
						SetSpriteState(&g_ALLY[x], SOUTH);
					}
				}
			}
		}

		for (int fg = 0; fg < maxally; fg++)
		{
			g_ALLY[fg].shothold++;
		}
}