//this contains many enemy functions

#include "script_sequence.h"
void scripte_sequence();

void check_for_enemy_shot()
{
	for (int x = 0; x < max_level_tiles; x++)
	{
		/*		im not sure if we should use this yet...				
		if (g_ENEMY[x].ship == 1 || g_ENEMY[x].ship == 2 || g_ENEMY[x].ship == 9 || g_ENEMY[x].ship == 11 || g_ENEMY[x].ship == 13)
		{
			random = rand1.RandInt(1,13);
		}
		if (g_ENEMY[x].ship == 3 || g_ENEMY[x].ship == 4 || g_ENEMY[x].ship == 5 || g_ENEMY[x].ship == 10)
		{
			random = rand1.RandInt(1,8);
		}
		if (g_ENEMY[x].ship == 6 || g_ENEMY[x].ship == 12)
		{
			random = rand1.RandInt(1,6);
		}
		if (g_ENEMY[x].ship == 7)
		{
			random = rand1.RandInt(1,4);
		}
		if (g_ENEMY[x].ship == 8)
		{
			random = rand1.RandInt(1,3);
		}
		if (g_ENEMY[x].boss_condition == BOSSONEPIT || g_ENEMY[x].boss_condition == BOSSONEWINGL ||  g_ENEMY[x].boss_condition == BOSSONEWINGR)
		{
			random = rand1.RandInt(1,5);
		}*/
				
		if (g_PLAYER.condition != alive)
		{
			random = 4;
		}

		random = rand1.RandInt(1, 4);
				
		if (g_ELASER[x].condition == alive && g_ELASER[x].xhold == 0 && g_ELASER[x].yhold == 0)
		{
			g_ELASER[x].yhold = laserspeed;
		}
		if (g_ENEMY[x].condition == alive && random < 4)
		{
			g_ENEMY[x].shothold++;
				if (g_ENEMY[x].special == 0)
				{
					g_ENEMY[x].special = rand1.RandInt(1, 2);
				}

				//LAST BOSS
				if ((g_ENEMY[x].boss == bossfive))
				{
					if (g_ENEMY[x].shothold % 3 == 0 && g_ENEMY[17].health > 0 && x == 17)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 3);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 239 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 280;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + 239 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 280 - g_PLAYER.position.y) / elaserspeed;
								}
								else if (r1 == 2)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 82 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 168;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 398 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 168;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].condition = alive;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					else if (g_ENEMY[x].shothold % 2 == 0 && g_ENEMY[17].health <= 0
						&& g_ENEMY[18].health > 25 && x == 18)
					{
						g_ENEMY[x].shotcount = 0;
						for (int q = 0; g_ENEMY[x].shotcount <= 4 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 5);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 82 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 184 - 16;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else if (r1 == 2)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 398 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 184 - 16;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else if (r1 == 3)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 128 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 203 - 16;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + 128 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 203 - 16 - g_PLAYER.position.y) / elaserspeed;
								}
								else if (r1 == 4)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 350 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 203 - 16;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + 350 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 203 - 16 - g_PLAYER.position.y) / elaserspeed;
								}
								else
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 239 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 231 - 16;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth / 2 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 90 - g_PLAYER.position.y) / elaserspeed;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].condition = alive;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					else if (g_ENEMY[18].health <= 25 && x == 19)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{			
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 5);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 178 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 222;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else if (r1 == 2)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 300 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 222;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else if (r1 == 3)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 238 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 230;
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
								}
								else if (r1 == 4)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 296 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 94;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + 296 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 94 - g_PLAYER.position.y) / elaserspeed;
								}
								else
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 184 - 16;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 94;
									g_ELASER[q].xhold = -((g_ENEMY[x].position.x + 184 - 16) - g_PLAYER.position.x) / elaserspeed;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 94 - g_PLAYER.position.y) / elaserspeed;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].condition = alive;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
				}

				//BOSS FOUR
				else if ((g_ENEMY[x].boss == bossfour))
				{
					if (g_ENEMY[x].shothold % 10 == 0 && g_ENEMY[17].health > 0 && x == 17)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 32;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;
								g_ELASER[q].position.x = g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth / 2 - 16;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					else if (g_ENEMY[x].shothold % 15 == 0 && g_ENEMY[17].health <= 0
						&& g_ENEMY[18].health > 0 && x == 18)
					{
						g_ENEMY[x].shotcount = 0;
						for (int q = 0; g_ENEMY[x].shotcount <= 4 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth / 2 - 16;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 90;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].xhold = 9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 2)
								{
									g_ELASER[q].xhold = -9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 3)
								{
									g_ELASER[q].xhold = 4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 4)
								{
									g_ELASER[q].xhold = -4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
									break;
								}
							}
						}
					}
					else if (g_ENEMY[x].shothold % 5 == 0 && g_ENEMY[18].health <= 0 && x == 19 && g_ENEMY[19].health > 0)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{			
							if (g_ELASER[q].condition == dead)
							{
								g_ENEMY[x].shothold = 0;
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth / 2 - 16;;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 90;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								g_ELASER[q].xhold = -((g_ENEMY[x].position.x + g_ENEMY[x].SIZEwidth / 2 - 16) - g_PLAYER.position.x) / elaserspeed;
								g_ELASER[q].yhold = -(g_ENEMY[x].position.y + 90 - g_PLAYER.position.y) / elaserspeed;

								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
				}
				//BOSS THREE
				else if ((g_ENEMY[x].boss == bossthree))
				{
					if (g_ENEMY[x].shothold % 10 == 0 && g_ENEMY[x].health < (bossthreehealth * g_PLAYER.difficulty / 3))
					{
						for (int q = 0; q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 2);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 230 - 16;
								}
								else
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x - 16;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 150;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					if (g_ENEMY[x].shothold % 10 == 0 && g_ENEMY[x].health < (bossthreehealth * g_PLAYER.difficulty / 3 * 2))
					{
						for (int q = 0; q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 2);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 160 - 16;
								}
								else
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 72 - 16;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 150;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					if (g_ENEMY[x].shothold % 5 == 0)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{
							if (g_ELASER[q].condition == dead)
							{
								int r1 = rand1.RandInt(1, 3);
								if (r1 == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 96 - 16;
								}
								if (r1 == 2)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 116 - 16;
								}
								if (r1 == 3)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 142 - 16;
								}
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 140;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					if (g_ENEMY[x].shothold > 10)
					{
						g_ENEMY[x].shothold = 0;
					}
				}
				//BOSS 2
				else if ((g_ENEMY[x].boss == bosstwo) && g_ENEMY[x].shothold >= 20 && g_ENEMY[x].shothold <= 1000)
				{
					if (g_ENEMY[x].scriptpos >= 900)
					{
						 g_ENEMY[x].shothold = 0;
					}
					else if (g_ENEMY[x].shothold <= 250)
					{
						for (int f = 0; f < max_level_tiles; f++)
						{	
							if (g_ELASER[f].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("EnemyFire.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								if (g_ENEMY[x].special == 1)
								{
									g_ELASER[f].position.x = g_ENEMY[x].position.x + ((g_ENEMY[x].SIZEwidth / 8) * 0) + 16;
									g_ENEMY[x].special = 2;
								}
								else if (g_ENEMY[x].special == 2)
								{
									g_ELASER[f].position.x = g_ENEMY[x].position.x + ((g_ENEMY[x].SIZEwidth / 8) * 6) - 8;
									g_ENEMY[x].special = 3;
								}
								else if (g_ENEMY[x].special == 3)
								{
									g_ELASER[f].position.x = g_ENEMY[x].position.x + ((g_ENEMY[x].SIZEwidth / 8) * 1) + 8;
									g_ENEMY[x].special = 4;
								}
								else if (g_ENEMY[x].special == 4)
								{
									g_ELASER[f].position.x = g_ENEMY[x].position.x + ((g_ENEMY[x].SIZEwidth / 8) * 7) - 16;
									g_ENEMY[x].special = 1;
								}
												
								g_ELASER[f].position.y = g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight - 48;
								g_ELASER[f].condition = alive;
								g_ELASER[f].xhold = 0;
								g_ELASER[f].yhold = laserspeed;
								break;
							}
						}
					}
					else if (g_ENEMY[x].shothold >= 260 && g_ENEMY[x].shothold < 450 && g_ENEMY[x].shothold % 20 == 0)
					{	
						g_ENEMY[x].shotcount = 0;
						//SHOTGUN
						for (int q = 0; g_ENEMY[x].shotcount < 5 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("EnemyFire.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x + (g_ENEMY[x].SIZEwidth / 2) - 16;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + g_ENEMY[x].SIZEheight;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = laserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].xhold = 9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 2)
								{
									g_ELASER[q].xhold = -9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 3)
								{
									g_ELASER[q].xhold = 4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 4)
								{
									g_ELASER[q].xhold = -4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
								}
								else
								{
									g_ELASER[q].xhold = 0;
								}
								q++;
								g_ENEMY[x].shothold++;
								if (g_ENEMY[x].shothold >= 450)
								{
									g_ENEMY[x].shothold = 450;
								}
							}
						}		
					}
					if (g_ENEMY[x].shothold % 3 == 0 && g_ENEMY[x].shothold >= 450)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{			
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x + (g_ENEMY[x].SIZEwidth / 2);
								g_ELASER[q].position.y = g_ENEMY[x].position.y + (g_ENEMY[x].SIZEheight / 2 /
									rand1.RandInt(1,3));

								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = elaserspeed;
								if (rand1.RandInt(0,1))
								{
									g_ELASER[q].yhold = elaserspeed;
								}
								else
								{
									g_ELASER[q].yhold = 0;
								}
								if (rand1.RandInt(0,1))
								{
									g_ELASER[q].xhold = -elaserspeed;
								}
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
				}
				//2 square shot things  (similar to circle)
				else if ((g_ENEMY[x].ship == 13) && g_ENEMY[x].shothold >= 16)
				{
					if (g_ENEMY[x].shothold >= 16)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{
							if (g_ELASER[q].condition == dead && (g_ENEMY[x].shothold == 16 || 
								g_ENEMY[x].shothold == 32 || g_ENEMY[x].shothold == 48))
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shothold == 16)
								{
									g_ELASER[q].xhold = 4;
									g_ELASER[q].yhold = 15;
									break;
								}
								else if (g_ENEMY[x].shothold == 32)
								{
									g_ELASER[q].xhold = -4;
									g_ELASER[q].yhold = 15;
									break;
								}
								else if (g_ENEMY[x].shothold == 48)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = 18;
									break;
								}
							}
						}
					}
					if (g_ENEMY[x].shothold >= 96)
					{
						g_ENEMY[x].shothold = 0;
					}
				}
				else if ((g_ENEMY[x].ship == 12) && g_ENEMY[x].shothold >= 25)
				{
					g_ENEMY[x].shotcount = 0;
					if (g_ENEMY[x].shothold >= 18)
					{
						for (int q = 0; g_ENEMY[x].shotcount <= 1 && q < max_level_tiles && g_ENEMY[x].shothold == 25; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x + 8;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
									g_ELASER[q].xhold = (int)(elaserspeed/2);
									g_ELASER[q].yhold = (int)(elaserspeed/2);
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].position.x = g_ENEMY[x].position.x - 8;
									g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
									g_ELASER[q].xhold = -(int)(elaserspeed/2);
									g_ELASER[q].yhold = (int)(elaserspeed/2);
									g_ENEMY[x].shotcount++;
								}
							}
						}
					}
					if (g_ENEMY[x].shothold == 50)
					{
						for (int q = 0; q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								g_ELASER[q].position.x = g_ENEMY[x].position.x;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
								break;
							}
						}
					}
					if (g_ENEMY[x].shothold >= 75)
					{
						g_ENEMY[x].shothold = 0;
					}
					break;
				}
				else if ((g_ENEMY[x].ship == 11) && g_ENEMY[x].shothold >= 25)
				{
					g_ENEMY[x].shotcount = 0;
					if (g_ENEMY[x].shothold >= 18)
					{
						for (int q = 0; g_ENEMY[x].shotcount <= 2 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].xhold = (int)(elaserspeed/2);
									g_ELASER[q].yhold = (int)(elaserspeed/2);
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 2)
								{
									g_ELASER[q].xhold = -(int)(elaserspeed/2);
									g_ELASER[q].yhold = (int)(elaserspeed/2);
									g_ENEMY[x].shotcount++;
								}
							}
						}
					}
					g_ENEMY[x].shothold = 0;
					break;
				}
				//2 square shot things  (similar to circle)
				else if ((g_ENEMY[x].ship == 10) && g_ENEMY[x].shothold >= 25)
				{
					g_ENEMY[x].shotcount = 0;
					if (g_ENEMY[x].shothold >= 18)
					{
						for (int q = 0; g_ENEMY[x].shotcount <= 3 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].xhold = elaserspeed;
									g_ELASER[q].yhold = 0;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 2)
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = -elaserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 3)
								{
									g_ELASER[q].xhold = -elaserspeed;
									g_ELASER[q].yhold = 0;
									g_ENEMY[x].shotcount++;
								}
							}
						}
					}
					g_ENEMY[x].shothold = 0;
					break;
				}
				//CIRCLE
				else if ((g_ENEMY[x].ship == 9) && g_ENEMY[x].shothold >= 25)
				{
					g_ENEMY[x].shotcount = 0;
					for (int q = 0; g_ENEMY[x].shotcount <= 7 && q < max_level_tiles; q++)
					{				
						if (g_ELASER[q].condition == dead)
						{
							if (TALKING == no)
								{
							PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
							}
							g_ELASER[q].position.x = g_ENEMY[x].position.x;
							g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
							g_ELASER[q].condition = alive;
							g_ELASER[q].xhold = 0;

							if (g_ENEMY[x].shotcount == 0)
							{
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = elaserspeed;
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 1)
							{
								g_ELASER[q].xhold = (int)(elaserspeed/2);
								g_ELASER[q].yhold = (int)(elaserspeed/2);
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 2)
							{
								g_ELASER[q].xhold = elaserspeed;
								g_ELASER[q].yhold = 0;
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 3)
							{
								g_ELASER[q].xhold = (int)(elaserspeed/2);
								g_ELASER[q].yhold = -(int)(elaserspeed/2);
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 4)
							{
								g_ELASER[q].xhold = 0;
								g_ELASER[q].yhold = -elaserspeed;
								g_ENEMY[x].shotcount++;

							}
							else if (g_ENEMY[x].shotcount == 5)
							{
								g_ELASER[q].xhold = -(int)(elaserspeed/2);
								g_ELASER[q].yhold = -(int)(elaserspeed/2);
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 6)
							{
								g_ELASER[q].xhold = -elaserspeed;
								g_ELASER[q].yhold = 0;
								g_ENEMY[x].shotcount++;
							}
							else if (g_ENEMY[x].shotcount == 7)
							{
								g_ELASER[q].xhold = -(int)(elaserspeed/2);
								g_ELASER[q].yhold = (int)(elaserspeed/2);
								g_ENEMY[x].shotcount++;
							}
							q++;
						}
					}
								
					g_ENEMY[x].shothold = 0;
					break;
				}

				//MGUN2 (shoots more)
				else if ((g_ENEMY[x].ship == 8) && g_ENEMY[x].shothold >= 30)
				{
					if (g_ENEMY[x].shotcount < 15)
					{
						g_ENEMY[x].shothold = 48;
					}
					if (g_ENEMY[x].shotcount >= 15 && g_ENEMY[x].shothold >= 30)
					{
						g_ENEMY[x].shotcount = 0;
						g_ENEMY[x].shothold = -1;
					}
					for (int q = 0; g_ENEMY[x].shotcount < 15 && q < max_level_tiles; q++)
					{			
						if (g_ELASER[q].condition == dead)
						{
							if (TALKING == no)
								{
							PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
							}
							g_ELASER[q].position.x = g_ENEMY[x].position.x;
							g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
							g_ELASER[q].condition = alive;
							g_ELASER[q].xhold = 0;

							g_ELASER[q].xhold = -(g_ENEMY[x].position.x - g_PLAYER.position.x) / elaserspeed;
							g_ELASER[q].yhold = -(g_ENEMY[x].position.y - g_PLAYER.position.y) / elaserspeed;

							g_ELASER[q].yhold = elaserspeed;
							g_ENEMY[x].shotcount++;
							break;
						}
					}
				}

						//MGUN1
				else if ((g_ENEMY[x].ship == 7) && g_ENEMY[x].shothold >= 30)
				{
					if (g_ENEMY[x].shotcount < 10)
					{
						g_ENEMY[x].shothold = 48;
					}
					if (g_ENEMY[x].shotcount >= 10 && g_ENEMY[x].shothold >= 30)
					{
						g_ENEMY[x].shotcount = 0;
						g_ENEMY[x].shothold = -1;
					}
					for (int q = 0; g_ENEMY[x].shotcount < 10 && q < max_level_tiles; q++)
					{			
						if (g_ELASER[q].condition == dead)
						{
							if (TALKING == no)
								{
							PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
							}
							g_ELASER[q].position.x = g_ENEMY[x].position.x;
							g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
							g_ELASER[q].condition = alive;
							g_ELASER[q].xhold = 0;

							g_ELASER[q].xhold = -(g_ENEMY[x].position.x - g_PLAYER.position.x) /elaserspeed;
							g_ELASER[q].yhold = -(g_ENEMY[x].position.y - g_PLAYER.position.y) /elaserspeed;

							g_ELASER[q].yhold = elaserspeed;
							g_ENEMY[x].shotcount++;
							break;
						}
					}
				}

				//SHOTGUN
				else if ((g_ENEMY[x].ship == 5 || g_ENEMY[x].ship == 6 || g_ENEMY[x].boss_condition == BOSSONEPIT) && g_ENEMY[x].shothold >= 20)
				{
					g_ENEMY[x].shotcount = 0;
						for (int q = 0; g_ENEMY[x].shotcount <= 4 && q < max_level_tiles; q++)
						{				
							if (g_ELASER[q].condition == dead)
							{
								if (TALKING == no)
								{
								PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
								}
								g_ELASER[q].position.x = g_ENEMY[x].position.x;
								g_ELASER[q].position.y = g_ENEMY[x].position.y + 8;
								g_ELASER[q].condition = alive;
								g_ELASER[q].xhold = 0;

								if (g_ENEMY[x].shotcount == 0 && (g_ENEMY[x].ship == 5 || g_ENEMY[x].boss_condition == BOSSONEPIT))
								{
									g_ELASER[q].xhold = 0;
									g_ELASER[q].yhold = elaserspeed;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 1)
								{
									g_ELASER[q].xhold = 9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 2)
								{
									g_ELASER[q].xhold = -9;
									g_ELASER[q].yhold = 9;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 3)
								{
									g_ELASER[q].xhold = 4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
								}
								else if (g_ENEMY[x].shotcount == 4)
								{
									g_ELASER[q].xhold = -4;
									g_ELASER[q].yhold = 15;
									g_ENEMY[x].shotcount++;
								}

								if (g_ENEMY[x].shotcount == 0 && g_ENEMY[x].ship == 6)
								{
									g_ELASER[q].xhold = -(g_ENEMY[x].position.x - g_PLAYER.position.x) / 18;
									g_ELASER[q].yhold = -(g_ENEMY[x].position.y - g_PLAYER.position.y) / 18;
									g_ENEMY[x].shotcount++;
								}
							}
						}
				
					g_ENEMY[x].shothold = 0;
					break;
				}

				//HOMING
				else if (((g_ENEMY[x].ship == 1 || g_ENEMY[x].ship == 2) && 
					!(g_ENEMY[x].boss_condition == BOSSONEWINGL || g_ENEMY[x].boss_condition == BOSSONEWINGR))
					&& g_ENEMY[x].shothold >= 20 || (g_ENEMY[x].ship == 3 || g_ENEMY[x].ship == 4) 
					&& g_ENEMY[x].shothold >= 15)
				{
					for (int f = 0; f < max_level_tiles; f++)
					{	
						if (g_ELASER[f].condition == dead)
						{
							if (TALKING == no)
								{
							PlaySound("Laser.wav", NULL, SND_FILENAME | SND_ASYNC);
							}
							g_ELASER[f].position.x = g_ENEMY[x].position.x;
							g_ELASER[f].position.y = g_ENEMY[x].position.y + 8;
							g_ELASER[f].condition = alive;
							g_ELASER[f].xhold = 0;

							if (g_ENEMY[x].ship == 3 || g_ENEMY[x].ship == 4)
							{
								g_ELASER[f].xhold = -(g_ENEMY[x].position.x - g_PLAYER.position.x) / elaserspeed;
								g_ELASER[f].yhold = -(g_ENEMY[x].position.y - g_PLAYER.position.y) / elaserspeed;
								g_ENEMY[x].shotcount++;
							}
							g_ENEMY[x].shothold = 0;
							break;
						}
					}
				}//enemy type					
		}//enemy alive
	}//forloop
}

void kill_laser_if_dead(int x)
{
	if (g_ELASER[x].position.y > gridalignment * 15 ||
		g_ELASER[x].position.y < gridalignment * 0 ||
		g_ELASER[x].position.x > gridalignment * 15 ||
		g_ELASER[x].position.x < gridalignment * 0 ||
		g_ELASER[x].condition == dead)
	{
		g_ELASER[x].condition = dead;
		g_ELASER[x].damage = 1;
		g_ELASER[x].position.y = offscreen-50;
		g_ELASER[x].position.x = offscreen-50;
		SetSpriteState(&g_ELASER[x], NORTH);
	}
}
void kill_enemy_if_dead(int x)
{
	if (g_ENEMY[x].position.y > gridalignment * 18)
	{
		g_ENEMY[x].condition = dead;//if laser is off screen, set to dead
	}

	//explosion animation for enemy
	if (g_ENEMY[x].condition == dyingone && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + g_ENEMY[x].condition);
		g_ENEMY[x].condition = dyingtwo;

		if (g_ENEMY[x].particles == yes)
		{
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
	}
	else if (g_ENEMY[x].condition == dyingtwo && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + g_ENEMY[x].condition);
		g_ENEMY[x].condition = dyingthree;

		if (g_ENEMY[x].particles == yes)
		{
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
	}
	else if (g_ENEMY[x].condition == dyingthree && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + g_ENEMY[x].condition);
		g_ENEMY[x].condition = dyingfour;

		if (g_ENEMY[x].particles == yes)
		{
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
	}
	else if (g_ENEMY[x].condition == dyingfour && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + g_ENEMY[x].condition);
		g_ENEMY[x].condition = dead;
	
		if (g_ENEMY[x].particles == yes)
		{
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
	}
	else if (g_ENEMY[x].condition == alive && g_time%3 == 0 && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + 6);
	}
	else if (g_ENEMY[x].condition == alive && (g_time%3 == 1 || g_time%3 == -1)&& g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)) + 7);
	}
	else if (g_ENEMY[x].condition == alive && (g_time%3 == 2 || g_time%3 == -2) && g_ENEMY[x].boss == no)
	{
		SetSpriteState(&g_ENEMY[x], (8 * (g_ENEMY[x].ship - 1)));
	}
	if (g_ENEMY[x].condition == dead)
	{
		g_ENEMY[x].ship = 1;
	}
}
void check_for_kill_or_load_enemy(int x)
{
	for (x = 0; x < max_level_tiles; x++)
	{
		if (g_ENEMY[x].position.y >= gridalignment * 17 || g_ENEMY[x].position.y <= gridalignment * -3)
		{
			g_ENEMY[x].condition = dead;
		}
		if (g_ENEMY[x].condition == dead && g_ENEMY[x].loaded == yes)
		{
			//FIX
			g_ENEMY[x].SIZEwidth = 32;
			g_ENEMY[x].SIZEheight = 32;
			g_ENEMY[x].hBitmap = g_switcher.hBitmap;
			g_ENEMY[x].hBitmapNormal = g_switcher.hBitmap;
			g_ENEMY[x].hBitmapNightVision = g_switcher.hBitmap;
			g_ENEMY[x].hBitmapThermalVision = g_switcher.hBitmap;
			g_ENEMY[x].position.y = offscreen-500;
			g_ENEMY[x].position.x = offscreen-500;
			g_ENEMY[x].loaded = no;
		}
		if (g_ENEMY[x].condition == alive && g_ENEMY[x].loaded == no)
		{
			g_ENEMY[x].hBitmap = enemyBMPnorm;
			g_ENEMY[x].hBitmapNormal = enemyBMPnorm;
			g_ENEMY[x].hBitmapNightVision = enemyBMPnv;
			g_ENEMY[x].hBitmapThermalVision = enemyBMPth;
			g_ENEMY[x].loaded = yes;
			Sleep(1);
		}
	}
}

void update_enemy_laser(int x)
{
	if (g_ELASER[x].condition != dead)
	{
		if (g_ELASER[x].condition < 7)
		{
			g_ELASER[x].condition++;
		}
		else
		{
			g_ELASER[x].condition = 1;
		}

		SetSpriteState(&g_ELASER[x], g_ELASER[x].condition-1);
	}

	if (g_ELASER[x].condition != dead)//makes laser go
	{
		g_ELASER[x].position.y += g_ELASER[x].yhold;
		g_ELASER[x].position.x += g_ELASER[x].xhold;
	}
}

void set_enemy_type()
{
	for (int x = 0; x < max_level_tiles; x++)
	{
		if (g_ENEMY[x].boss == no)
		{
		//	if (g_ENEMY[x].ship == 1 && g_ENEMY[x].condition == alive)
		//	{
		//		SetSpriteState(&g_ENEMY[x], 7*g_ENEMY[x].ship-7);
		//	}
		}
		else if (g_ENEMY[17].boss == bossone)
		{
			SetSpriteState(&g_ENEMY[17], g_ENEMY[17].boss_condition);
			SetSpriteState(&g_ENEMY[18], g_ENEMY[18].boss_condition);
			SetSpriteState(&g_ENEMY[19], g_ENEMY[19].boss_condition);
		}
		if (g_ENEMY[x].headlight == no && g_PLAYER.darkmission == yes && g_PLAYER.vision != 2 && g_PLAYER.vision != 3)
		{
			if (g_ENEMY[x].condition == alive)
			{
				SetSpriteState(&g_ENEMY[x], 200);
			}
		}
		if (g_PLAYER.vision != 3 && g_ENEMY[x].cloaked == yes && g_ENEMY[x].boss == no)
		{
			if (g_ENEMY[x].condition == alive)
			{
				SetSpriteState(&g_ENEMY[x], 200);
			}
		}
	}
}

void create_enemy(int time_to_create, int ship_number_ONE_TO_THIRTEEN, int script_number_NEGATIVEONE_TO_TEN, int sway_YES_OR_NO, int sway_right_ZERO_TO_FIVE, int sway_left_ZERO_TO_FIVE, int special_YES_OR_NO)
{
	if (g_time == time_to_create || time_to_create == -1)
	{
		for (int x = 0; x < max_level_tiles; x++)
		{
			if (g_ENEMY[x].condition == dead)
			{
				g_ENEMY[x].boss = no;
				g_ENEMY[x].condition = alive;
				g_ENEMY[x].ship = ship_number_ONE_TO_THIRTEEN;
				g_ENEMY[x].script  = script_number_NEGATIVEONE_TO_TEN;
				g_ENEMY[x].scriptpos = -1;
				g_ENEMY[x].special = special_YES_OR_NO;
				g_ENEMY[x].randomdirectionpicked = sway_YES_OR_NO;
				if (g_ENEMY[x].randomdirectionpicked == yes)
				{
					g_ENEMY[x].toleft = sway_left_ZERO_TO_FIVE;
					g_ENEMY[x].toright = sway_right_ZERO_TO_FIVE;
				}
				return;
			}
		}
	}
}