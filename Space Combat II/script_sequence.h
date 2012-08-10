void script_sequence(int& z, int P)
//z = position in array P = is it a powerup?
{
	RandGen rand;
	int random;

//	for (int z = 0; z < max_level_tiles; z++)
//	{
	//starts in middle somewhere, moves left, then right, then left
	if (g_POWERUP[z].script == scriptpowerup && P == yes)
	{
		if (g_POWERUP[z].scriptpos == 0)
		{
			g_POWERUP[z].position.x = gridalignment * 7;
			g_POWERUP[z].position.y = gridalignment * -1;
			g_POWERUP[z].scriptpos++;
		}

		g_POWERUP[z].position.y+= powerupspeed;

		if (g_POWERUP[z].randomdirectionpicked == no)
		{
			random = rand.RandInt(1,2);
			g_POWERUP[z].randomdirectionpicked = yes;
			if (random == 1)
			{
				g_POWERUP[z].toleft = 10;
				g_POWERUP[z].toright = 0;
			}
			else
			{
				g_POWERUP[z].toleft = 0;
				g_POWERUP[z].toright = 10;
			}
		}

		if (g_POWERUP[z].xhold <= 1)
		{
			if (g_POWERUP[z].toleft > 0)
			{
				g_POWERUP[z].position.x -= powerupspeed;
				g_POWERUP[z].toleft--;
				if (g_POWERUP[z].toleft <= 0)
				{
					g_POWERUP[z].toright = 5;
				}
			}
			if (g_POWERUP[z].toright > 0)
			{
				g_POWERUP[z].position.x+= powerupspeed;
				g_POWERUP[z].toright--;
				if (g_POWERUP[z].toright <= 0)
				{
					g_POWERUP[z].toleft = 5;
				}
			}
			g_POWERUP[z].xhold = 2;
		}
		else if (g_POWERUP[z].xhold >= 2 && g_POWERUP[z].xhold <= 8)
		{
			g_POWERUP[z].xhold = 0;
		}
		else
		{
			g_POWERUP[z].xhold = 0;
		}
		//return;
	}

	if (P == no)
	{
		if (g_ENEMY[z].script == -2)
		{
			if (g_ENEMY[z].scriptpos <= 1000)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * 7;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].scriptpos = 10000;
			}
		}
		if (g_ENEMY[z].script == scriptone)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * rand.RandInt(5,14);
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}

			g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			g_ENEMY[z].yhold = 2;

			if (g_ENEMY[z].randomdirectionpicked == no)
			{
				random = rand.RandInt(1,2);
				g_ENEMY[z].randomdirectionpicked = yes;
				if (random == 1)
				{
					g_ENEMY[z].toleft = 5;
					g_ENEMY[z].toright = 0;
				}
				else
				{
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].toright = 5;
				}
			}

			if (g_ENEMY[z].toleft > 0)
			{
				g_ENEMY[z].position.x-= (int)(enemyspeed/ 2);
				g_ENEMY[z].toleft--;
				if (g_ENEMY[z].toleft <= 0)
				{
					g_ENEMY[z].toright = 5;
				}
			}
			if (g_ENEMY[z].toright > 0)
			{
				g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				g_ENEMY[z].toright--;
				if (g_ENEMY[z].toright <= 0)
				{
					g_ENEMY[z].toleft = 5;
				}
			}
		}

		//starts top left, bounces right to left
		if (g_ENEMY[z].script == scripttwo)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = no;
				g_ENEMY[z].position.x = gridalignment * 0;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;

			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].toleft == no)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 15)
					{
						g_ENEMY[z].toleft = yes;
					}
				}
				if (g_ENEMY[z].toleft == yes)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 0)
					{
						g_ENEMY[z].toleft = no;
					}
				}

				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
		}

		//starts top right, bounces left to right
		if (g_ENEMY[z].script == scriptthree)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 15;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].toleft == no)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 15)
					{
						g_ENEMY[z].toleft = yes;
					}
				}
				if (g_ENEMY[z].toleft == yes)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 0)
					{
						g_ENEMY[z].toleft = no;
					}
				}
					g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
		}

		//hugs left, 1/2 way down, moves to right, hugs right
		if (g_ENEMY[z].script == scriptfour)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 0;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].position.y == gridalignment * 9 && g_ENEMY[z].position.x != gridalignment * 15)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				else if (g_ENEMY[z].position.y < gridalignment * 9 && g_ENEMY[z].position.x == gridalignment * 0)
				{
					g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
				}
				else
				{
					g_ENEMY[z].position.y+= enemyspeed;
				}
			}
		}

		//hugs right, 1/2 way down, moves to left, hugs left
		if (g_ENEMY[z].script == scriptfive)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 15;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].position.y ==gridalignment * 9 && g_ENEMY[z].position.x > gridalignment * 0)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
				}
				else if (g_ENEMY[z].position.y < gridalignment * 9 && g_ENEMY[z].position.x == gridalignment * 15)
				{
						g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
				}
				else
				{
					g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
				}
			}
		}

		//follows g_PLAYERs X position
		if (g_ENEMY[z].script == scriptsix)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = g_PLAYER.position.x;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				g_ENEMY[z].position.x = g_PLAYER.position.x;
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
		}

		//suicide guy, trys to hit g_PLAYER
		if (g_ENEMY[z].script == scriptseven)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = g_PLAYER.position.x;
				g_ENEMY[z].position.y = gridalignment * -1;
				g_ENEMY[z].xhold = 0;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed);
			}
			else
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed * 2);
				if (g_PLAYER.position.x > g_ENEMY[z].position.x)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed);
				}
				if (g_PLAYER.position.x < g_ENEMY[z].position.x)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed);
				}
			}
		}

		//same as script one, but starts at bottom and moves up
		if (g_ENEMY[z].script == scripteight)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * rand.RandInt(5,14);
				g_ENEMY[z].position.y = gridalignment * 17;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y > gridalignment * 15)
			{
				g_ENEMY[z].position.y-= (int)(enemyspeed / 2);
			}

				g_ENEMY[z].position.y -= (int)(enemyspeed / 2);

			if (g_ENEMY[z].randomdirectionpicked == no)
			{
				random = rand.RandInt(1,2);
				g_ENEMY[z].randomdirectionpicked = yes;
				if (random == 1)
				{
					g_ENEMY[z].toleft = 5;
					g_ENEMY[z].toright = 0;
				}
				else
				{
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].toright = 5;
				}
			}

			if (g_ENEMY[z].toleft > 0)
			{
				g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
				g_ENEMY[z].toleft--;
				if (g_ENEMY[z].toleft <= 0)
				{
					g_ENEMY[z].toright = 5;
				}
			}
			if (g_ENEMY[z].toright > 0)
			{
				g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				g_ENEMY[z].toright--;
				if (g_ENEMY[z].toright <= 0)
				{
					g_ENEMY[z].toleft = 5;
				}
			}
			g_ENEMY[z].xhold = 2;
		}

		//starts at bottom left , bounces to top
		if (g_ENEMY[z].script == scriptnine)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = no;
				g_ENEMY[z].position.x = gridalignment * 0;
				g_ENEMY[z].position.y = gridalignment * 17 - 3;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y > gridalignment * 15)
			{
				g_ENEMY[z].position.y-= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].toleft == no)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 15)
					{
						g_ENEMY[z].toleft = yes;
					}
				}
				if (g_ENEMY[z].toleft == yes)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 0)
					{
						g_ENEMY[z].toleft = no;
					}
				}

				g_ENEMY[z].position.y -= (int)(enemyspeed / 2);
			}
		}

		//starts bottom right, bounces to top
		if (g_ENEMY[z].script == scriptten)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 15;
				g_ENEMY[z].position.y = gridalignment * 17 - 3;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y > gridalignment * 15)
			{
				g_ENEMY[z].position.y-= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].toleft == no)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 15)
					{
						g_ENEMY[z].toleft = yes;
					}
				}
				if (g_ENEMY[z].toleft == yes)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
					if (g_ENEMY[z].position.x ==gridalignment * 0)
					{
						g_ENEMY[z].toleft = no;
					}
				}

				g_ENEMY[z].position.y -= (int)(enemyspeed / 2);
			}
		}

		//starts at bottom left, hugs left then moves to right, hugs right
		if (g_ENEMY[z].script == scripteleven)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 0;
				g_ENEMY[z].position.y = gridalignment * 17;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y > gridalignment * 15)
			{
				g_ENEMY[z].position.y-= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].position.y ==gridalignment * 9 && g_ENEMY[z].position.x != gridalignment * 15)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				else if (g_ENEMY[z].position.y < gridalignment * 9 && g_ENEMY[z].position.x == gridalignment * 0)
				{
					g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
				}
				else
				{
					g_ENEMY[z].position.y -= (int)(enemyspeed / 2);
				}
			}
		}

		//starts at bottom right, hugs right then moves to left, hugs left
		if (g_ENEMY[z].script == scripttwelve)
		{
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].toleft = yes;
				g_ENEMY[z].position.x = gridalignment * 15;
				g_ENEMY[z].position.y = gridalignment * 17;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y > gridalignment * 15)
			{
				g_ENEMY[z].position.y-= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].position.y ==gridalignment * 9 && g_ENEMY[z].position.x > gridalignment *  0)
				{
					g_ENEMY[z].position.x -= (int)(enemyspeed / 2);
				}
				else if (g_ENEMY[z].position.y < gridalignment *  9 && g_ENEMY[z].position.x == gridalignment * 15)
				{
					g_ENEMY[z].position.y -= (int)(enemyspeed / 2);
				}
				else
				{
					g_ENEMY[z].position.y -= (int)(enemyspeed / 2);
				}
			}
		}

		//BOSS ONE

		if (g_ENEMY[z].script == scriptbossone)
		{
			if (g_ENEMY[z].scriptpos <= -50)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * -1;
			}
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * 0;
				g_ENEMY[z].scriptpos++;

				if (g_ENEMY[z].boss == bossone)
				{
					g_ENEMY[z+1].position.y = g_ENEMY[z].position.y;
					g_ENEMY[z+1].position.x = g_ENEMY[z].position.x + 32;

					g_ENEMY[z+2].position.y = g_ENEMY[z].position.y;
					g_ENEMY[z+2].position.x = g_ENEMY[z].position.x - 32;
				}
				g_ENEMY[z].toleft = 0;

				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
				if (g_ENEMY[z].boss == bossone)
				{
					g_ENEMY[z+1].shothold = 1000;
					g_ENEMY[z+1].shotcount = -1;
					g_ENEMY[z+2].shothold = 1000;
					g_ENEMY[z+2].shotcount = -1;
				}
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
				g_ENEMY[z+1].position.y+= (int)(enemyspeed / 2);
				g_ENEMY[z+2].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				int random = 0;
				if (g_ENEMY[z].scriptpos >= 5 && g_ENEMY[z].scriptpos < 30)
				{
					g_ENEMY[z].position.y+= enemyspeed;
					g_ENEMY[z].position.x+= enemyspeed;
					if (g_ENEMY[z].scriptpos == 29)
					{
						g_ENEMY[z].toleft = rand1.RandInt(3,4);
					}
					if (g_ENEMY[z].toleft == 3)
					{
						g_ENEMY[z].scriptpos = 300;
					}
				}
				if (g_ENEMY[z].scriptpos > 30 && g_ENEMY[z].scriptpos <= 85 && g_ENEMY[z].toleft == 4)
				{
					g_ENEMY[z].position.x -= enemyspeed;
					if (g_ENEMY[z].scriptpos == 85)
					{
						g_ENEMY[z].toleft = rand1.RandInt(0,2);
					}
				}
				if (g_ENEMY[z].scriptpos >= 85 && g_ENEMY[z].scriptpos <= 110 && g_ENEMY[z].toleft == 1)
				{
					if (g_ENEMY[z].position.x < gridalignment * 7)
					{
						g_ENEMY[z].position.x+= enemyspeed;
					}
					if (g_ENEMY[z].position.y > gridalignment * 0)
					{
						g_ENEMY[z].position.y-= enemyspeed;
					}
				}
				if (g_ENEMY[z].scriptpos >= 85 && g_ENEMY[z].scriptpos < 150 && g_ENEMY[z].toleft == 0)
				{
					if (g_ENEMY[z].scriptpos <= 110)
					{
						g_ENEMY[z].position.y+= enemyspeed;
					}
					g_ENEMY[z].position.x+= enemyspeed;
				}
				if (g_ENEMY[z].scriptpos >= 150 && g_ENEMY[z].scriptpos < 210 && g_ENEMY[z].toleft == 0)
				{
					if (g_ENEMY[z].position.x > gridalignment * 7)
					{
						g_ENEMY[z].position.x-= enemyspeed;
					}
					if (g_ENEMY[z].position.y > gridalignment * 0)
					{
						g_ENEMY[z].position.y-= enemyspeed;
					}
				}

				if (g_ENEMY[z].scriptpos > 85 && g_ENEMY[z].scriptpos <= 150 && g_ENEMY[z].toleft == 2)
				{
					g_ENEMY[z].position.x += enemyspeed;
					if (g_ENEMY[z].scriptpos == 150)
					g_ENEMY[z].toleft = rand1.RandInt(1,2);
					if (g_ENEMY[z].toleft == 1)
					{
						g_ENEMY[z].scriptpos = 28;
					}
				}
				if (g_ENEMY[z].scriptpos > 150 && g_ENEMY[z].scriptpos <= 215 && g_ENEMY[z].toleft == 2)
				{
					if (g_ENEMY[z].scriptpos <= 175)
					{
						g_ENEMY[z].position.y+= enemyspeed;
					}
					g_ENEMY[z].position.x -= enemyspeed;
				}
				if (g_ENEMY[z].scriptpos >= 215 && g_ENEMY[z].scriptpos < 275 && g_ENEMY[z].toleft == 2)
				{
					if (g_ENEMY[z].position.x < gridalignment * 7)
					{
						g_ENEMY[z].position.x+= enemyspeed;
					}
					if (g_ENEMY[z].position.y > gridalignment * 0)
					{
						g_ENEMY[z].position.y-= enemyspeed;
					}
				}

				if (g_ENEMY[z].scriptpos > 300 && g_ENEMY[z].scriptpos <= 355 && g_ENEMY[z].toleft == 3)
				{
					if (g_ENEMY[z].scriptpos <= 325)
					{
						g_ENEMY[z].position.y+= enemyspeed;
					}
					g_ENEMY[z].position.x -= enemyspeed;
				}
				if (g_ENEMY[z].scriptpos >= 355 && g_ENEMY[z].scriptpos < 410 && g_ENEMY[z].toleft == 3)
				{
					if (g_ENEMY[z].position.x < gridalignment * 7)
					{
						g_ENEMY[z].position.x+= enemyspeed;
					}
					if (g_ENEMY[z].position.y > gridalignment * 0)
					{
						g_ENEMY[z].position.y-= enemyspeed;
					}
				}

		
				if (g_ENEMY[z].scriptpos >= 110 && g_ENEMY[z].toleft == 1)
				{
					g_ENEMY[z].scriptpos = 1;
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].shothold = 1000;
					g_ENEMY[z].shotcount = -1;
					if (g_ENEMY[z].boss == bossone)
					{
						g_ENEMY[z+1].shothold = 1000;
						g_ENEMY[z+1].shotcount = -1;
						g_ENEMY[z+1].scriptpos = 1;
						g_ENEMY[z+2].shothold = 1000;
						g_ENEMY[z+2].shotcount = -1;
						g_ENEMY[z+2].scriptpos = 1;
					}
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].script = 13;
					}
				}
				if (g_ENEMY[z].scriptpos >= 210 && g_ENEMY[z].toleft == 0)
				{
					g_ENEMY[z].scriptpos = 1;
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].shothold = 1000;
					g_ENEMY[z].shotcount = -1;
					if (g_ENEMY[z].boss == bossone)
					{
						g_ENEMY[z+1].shothold = 1000;
						g_ENEMY[z+1].shotcount = -1;
						g_ENEMY[z+1].scriptpos = 1;
						g_ENEMY[z+2].shothold = 1000;
						g_ENEMY[z+2].shotcount = -1;
						g_ENEMY[z+2].scriptpos = 1;
					}
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].script = 13;
					}
				}
				if (g_ENEMY[z].scriptpos >= 275 && g_ENEMY[z].toleft == 2)
				{
					g_ENEMY[z].scriptpos = 1;
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].shothold = 1000;
					g_ENEMY[z].shotcount = -1;
					if (g_ENEMY[z].boss == bossone)
					{
						g_ENEMY[z+1].shothold = 1000;
						g_ENEMY[z+1].shotcount = -1;
						g_ENEMY[z+1].scriptpos = 1;
						g_ENEMY[z+2].shothold = 1000;
						g_ENEMY[z+2].shotcount = -1;
						g_ENEMY[z+2].scriptpos = 1;
					}
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].script = 13;
					}
				}
				if (g_ENEMY[z].scriptpos >= 410 && g_ENEMY[z].toleft == 3)
				{
					g_ENEMY[z].scriptpos = 1;
					g_ENEMY[z].toleft = 0;
					g_ENEMY[z].shothold = 1000;
					g_ENEMY[z].shotcount = -1;
					if (g_ENEMY[z].boss == bossone)
					{
						g_ENEMY[z+1].shothold = 1000;
						g_ENEMY[z+1].shotcount = -1;
						g_ENEMY[z+1].scriptpos = 1;
						g_ENEMY[z+2].shothold = 1000;
						g_ENEMY[z+2].shotcount = -1;
						g_ENEMY[z+2].scriptpos = 1;
					}
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].script = 13;
					}
				}
				g_ENEMY[z].scriptpos++;
				if (g_ENEMY[z].boss == bossone)
				{
					g_ENEMY[z+1].scriptpos = g_ENEMY[z].scriptpos;
					g_ENEMY[z+2].scriptpos = g_ENEMY[z].scriptpos;

					g_ENEMY[z+1].position.y = g_ENEMY[z].position.y;
					g_ENEMY[z+1].position.x = g_ENEMY[z].position.x + 32;

					g_ENEMY[z+2].position.y = g_ENEMY[z].position.y;
					g_ENEMY[z+2].position.x = g_ENEMY[z].position.x - 32;
				}
			}
		}

		if (g_ENEMY[z].script == scriptbosstwo)
		{
			if (g_ENEMY[z].scriptpos <= -50)
			{
				g_ENEMY[z].position.x = gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2);
				g_ENEMY[z].position.y = gridalignment * 7;
				g_ENEMY[z].scriptpos = 1;
			}
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2);
				g_ENEMY[z].position.y = gridalignment * -2;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].toleft = 0;

				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			else if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y+= (int)(enemyspeed / 2);
			}
			else
			{
				if (g_ENEMY[z].scriptpos < 50 && g_ENEMY[z].scriptpos >= 0)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].scriptpos < 149 && g_ENEMY[z].scriptpos >= 60)
				{
					g_ENEMY[z].position.x-= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].scriptpos < 249 && g_ENEMY[z].scriptpos >= 160)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].scriptpos < 349 && g_ENEMY[z].scriptpos >= 260)
				{
					g_ENEMY[z].position.x-= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].scriptpos < 449 && g_ENEMY[z].scriptpos >= 360)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].scriptpos < 549 && g_ENEMY[z].scriptpos >= 460)
				{
					g_ENEMY[z].position.x-= (int)(enemyspeed / 2);
				}
				if (g_ENEMY[z].position.x < gridalignment * 8 - (int)(g_ENEMY[z].SIZEwidth / 2) && g_ENEMY[z].scriptpos >= 560)
				{
					g_ENEMY[z].position.x+= (int)(enemyspeed / 2);
				}
				//560

				if (g_ENEMY[z].scriptpos >= 900)
				{
					g_ENEMY[z].scriptpos = 0;
					g_ENEMY[z].shothold = 0;
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].scriptpos = -1;
						g_ENEMY[z].script = 14;
					}
				}
				g_ENEMY[z].scriptpos++;
			}
		}

		if (g_ENEMY[z].script == scriptbossthree)
		{

			if (g_ENEMY[z].scriptpos <= -50)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * 7;
				g_ENEMY[z].scriptpos = 1;
			}
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2);
				g_ENEMY[z].position.y = gridalignment * -2;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].position.y+=enemyspeed;

				g_ENEMY[z].toleft = 3;//rand1.RandInt(1,3);

				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;

			}
			if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y += enemyspeed;
			}
			else
			{
				if (g_ENEMY[z].toleft == 1) 
				{
					if (g_ENEMY[z].scriptpos >= 0 && g_ENEMY[z].scriptpos < 320)
					{
						if(g_ENEMY[z].position.x + g_ENEMY[z].SIZEwidth/2 < g_PLAYER.position.x  && g_ENEMY[z].position.x < gridalignment * 15 - enemyspeed)
						{
							g_ENEMY[z].position.x+=enemyspeed;
						}
						if(g_ENEMY[z].position.x + g_ENEMY[z].SIZEwidth/2 > g_PLAYER.position.x + 32 && g_ENEMY[z].position.x > enemyspeed)
						{
							g_ENEMY[z].position.x-=enemyspeed;
						}
					}
				}
				if (g_ENEMY[z].toleft == 2) 
				{
					if (g_ENEMY[z].scriptpos < 30 && g_ENEMY[z].scriptpos >= 5)
					{
						g_ENEMY[z].position.x+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 30 && g_ENEMY[z].scriptpos <= 55)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 55 && g_ENEMY[z].scriptpos <= 105)
					{
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 105 && g_ENEMY[z].scriptpos <= 125&& g_ENEMY[z].position.x > enemyspeed)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					//279 + 32 = 1/2....for 3
					if (g_ENEMY[z].scriptpos > 125 && g_ENEMY[z].scriptpos <= 165&& g_ENEMY[z].position.x > enemyspeed)
					{
						g_ENEMY[z].position.x-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 165 && g_ENEMY[z].scriptpos <= 185&& g_ENEMY[z].position.x > enemyspeed&& g_ENEMY[z].position.y > 0)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 185 && g_ENEMY[z].scriptpos <= 245&& g_ENEMY[z].position.y > 0)
					{
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos == 244)
					{
						g_ENEMY[z].scriptpos = 320;
					}
				}
				if (g_ENEMY[z].toleft == 4) 
				{
					if (g_ENEMY[z].scriptpos > 120 && g_ENEMY[z].scriptpos <= 180&& g_ENEMY[z].position.x < gridalignment * 15 - enemyspeed)
					{
						g_ENEMY[z].position.x+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 180 && g_ENEMY[z].scriptpos <= 200&& g_ENEMY[z].position.x < gridalignment * 15 - enemyspeed && g_ENEMY[z].position.y > 0)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos > 200 && g_ENEMY[z].scriptpos <= 260&& g_ENEMY[z].position.y > 0)
					{
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos == 260)
					{
						g_ENEMY[z].scriptpos = 320;
					}
				}

				if (g_ENEMY[z].toleft == 3) 
				{
					if (g_ENEMY[z].scriptpos < 99 && g_ENEMY[z].scriptpos >= 0)
					{
						g_ENEMY[z].position.y+=enemyspeed;
						if (g_ENEMY[z].scriptpos == 98)
						{
							g_ENEMY[z].toleft = rand1.RandInt(2,3);
							g_ENEMY[z].scriptpos = 156;
							if (g_ENEMY[z].toleft == 3)
							{
								g_ENEMY[z].scriptpos = 156;
								g_ENEMY[z].toleft = 4;
							}
						}
					}
					if (g_ENEMY[z].scriptpos < 320 && g_ENEMY[z].scriptpos >= 99)
					{
						if(g_ENEMY[z].position.x + g_ENEMY[z].SIZEwidth/2 < g_PLAYER.position.x  && g_ENEMY[z].position.x < gridalignment * 15 - enemyspeed)
						{
							g_ENEMY[z].position.x+=enemyspeed;
						}
						if(g_ENEMY[z].position.x + g_ENEMY[z].SIZEwidth/2 > g_PLAYER.position.x + 32 && g_ENEMY[z].position.x > enemyspeed)
						{
							g_ENEMY[z].position.x-=enemyspeed;
						}
					}
				}

				if (g_ENEMY[z].scriptpos > 320 && g_ENEMY[z].scriptpos < 440)
					{
						if (g_ENEMY[z].position.x < gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2))
						{
							g_ENEMY[z].position.x+=enemyspeed;
						}
						if (g_ENEMY[z].position.y > (gridalignment * 0) + 1)
						{
							g_ENEMY[z].position.y-=enemyspeed;
						}
						if (g_ENEMY[z].position.x > gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2))
						{
							g_ENEMY[z].position.x-=enemyspeed;
						}
						if (g_ENEMY[z].position.y < (gridalignment * 0) + 1)
						{
							g_ENEMY[z].position.y+=enemyspeed;
						}

						if (g_ENEMY[z].position.y == gridalignment * 0 && g_ENEMY[z].position.x == gridalignment * 7)
						{
							g_ENEMY[z].scriptpos = 400;
						}
					}

				if (g_ENEMY[z].scriptpos >= 440)
				{
					g_ENEMY[z].scriptpos = 0;
					g_ENEMY[z].toleft = 3;
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].scriptpos = 0;
						g_ENEMY[z].script = 14;
					}
				}
				g_ENEMY[z].scriptpos++;
			}
			g_ENEMY[z].scriptpos++;
		}

		if (g_ENEMY[z].script == scriptbossfour)
		{
			if (g_ENEMY[z].scriptpos <= -50)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * 7;
				g_ENEMY[z].scriptpos = 1;
			}
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2);
				g_ENEMY[z].position.y = (gridalignment * 0) + 1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].position.y+=enemyspeed;

				g_ENEMY[z].toleft = rand1.RandInt(1,3);

				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y += enemyspeed;
				g_ENEMY[z].scriptpos++;
			}
			else
			{
				if (g_ENEMY[18].health >= 0)
				{
					g_ENEMY[18].toleft = g_ENEMY[19].toleft;
				}
				else
				{
					g_ENEMY[18].condition = dead;
					g_ENEMY[18].position.y = offscreen;
					g_ENEMY[18].position.x = offscreen;
				}
				if (g_ENEMY[17].health >= 0)
				{
					g_ENEMY[17].toleft = g_ENEMY[19].toleft;
				}
				else
				{
					g_ENEMY[17].condition = dead;
					g_ENEMY[17].position.y = offscreen;
					g_ENEMY[17].position.x = offscreen;
				}
				if (g_ENEMY[19].health <= 0)
				{
					g_ENEMY[19].condition = dead;
				}
				if (g_ENEMY[z].toleft == 1) 
				{
					if (g_ENEMY[z].scriptpos >= 0 && g_ENEMY[z].scriptpos < 50)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 50 && g_ENEMY[z].scriptpos < 80)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 80 && g_ENEMY[z].scriptpos < 100)
					{
						g_ENEMY[z].position.x-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 100 && g_ENEMY[z].scriptpos < 140)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 140 && g_ENEMY[z].scriptpos < 180)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
						if (g_ENEMY[z].scriptpos == 179)
						{
							g_ENEMY[z].scriptpos = 320;
						}
					}
				}
				if (g_ENEMY[z].toleft == 2) 
				{
					if (g_ENEMY[z].scriptpos >= 0 && g_ENEMY[z].scriptpos < 40)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 40 && g_ENEMY[z].scriptpos < 80)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 80 && g_ENEMY[z].scriptpos < 100)
					{
						g_ENEMY[z].position.x+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 100 && g_ENEMY[z].scriptpos < 140)
					{
						g_ENEMY[z].position.x+=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 140 && g_ENEMY[z].scriptpos < 180)
					{
						g_ENEMY[z].position.x-=enemyspeed;
						g_ENEMY[z].position.y-=enemyspeed;
						if (g_ENEMY[z].scriptpos == 179)
						{
							g_ENEMY[z].scriptpos = 320;
						}
					}
				}

				if (g_ENEMY[z].toleft == 3) 
				{
					if (g_ENEMY[z].scriptpos >= 0 && g_ENEMY[z].scriptpos < 80)
					{
						g_ENEMY[z].position.y+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 80 && g_ENEMY[z].scriptpos < 120)
					{
						g_ENEMY[z].position.x+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 120 && g_ENEMY[z].scriptpos < 200)
					{
						g_ENEMY[z].position.x-=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 200 && g_ENEMY[z].scriptpos < 240)
					{
						g_ENEMY[z].position.x+=enemyspeed;
					}
					if (g_ENEMY[z].scriptpos >= 240 && g_ENEMY[z].scriptpos < 320)
					{
						g_ENEMY[z].position.y-=enemyspeed;
					//	if (g_ENEMY[z].scriptpos == 220)
					//	{
					//		g_ENEMY[z].scriptpos = 320;
					//	}
					}
				}

				if (g_ENEMY[z].scriptpos > 320 && g_ENEMY[z].scriptpos < 440)
					{
						if (g_ENEMY[z].position.x < gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2))
						{
							g_ENEMY[z].position.x+=enemyspeed;
						}
						if (g_ENEMY[z].position.x > (gridalignment * 0) + 1)
						{
							g_ENEMY[z].position.y-=enemyspeed;
						}
						if (g_ENEMY[z].position.x > gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2))
						{
							g_ENEMY[z].position.x-=enemyspeed;
						}
						if (g_ENEMY[z].position.y < (gridalignment * 0) + 1)
						{
							g_ENEMY[z].position.y+=enemyspeed;
						}

						if (g_ENEMY[z].position.y == gridalignment * 0 && g_ENEMY[z].position.x == gridalignment * 7 - (int)(g_ENEMY[z].SIZEwidth / 2))
						{
							g_ENEMY[z].scriptpos = 400;
						}
					}

				if (g_ENEMY[z].scriptpos >= 440)
				{
					g_ENEMY[z].scriptpos = 0;
					g_ENEMY[z].toleft = rand1.RandInt(1,3);
					if (g_ENEMY[z].boss == bossfive)
					{
						g_ENEMY[z].scriptpos = -1;
						g_ENEMY[z].script = 14;
					}
				}
				g_ENEMY[z].scriptpos++;
			}
			g_ENEMY[z].scriptpos++;
		}

		if (g_ENEMY[z].script == scriptbossfive)
		{
			if (g_ENEMY[z].scriptpos <= -50)
			{
				g_ENEMY[z].position.x = gridalignment * 7;
				g_ENEMY[z].position.y = gridalignment * 7;
				g_ENEMY[z].scriptpos = 1;
			}
			if (g_ENEMY[z].scriptpos == 0)
			{
				g_ENEMY[z].position.x = gridalignment * 0;
				g_ENEMY[z].position.y = (gridalignment * -2) + 1;
				g_ENEMY[z].scriptpos++;
				g_ENEMY[z].position.y+=enemyspeed;

				g_ENEMY[z].toleft = rand1.RandInt(1,3);

				g_ENEMY[z].shothold = 1000;
				g_ENEMY[z].shotcount = -1;
			}
			if (g_ENEMY[z].position.y < 0)
			{
				g_ENEMY[z].position.y += 3;
				g_ENEMY[z].scriptpos++;
			}
			else
			{
				g_ENEMY[17].position.y = g_ENEMY[17].position.y;
				g_ENEMY[17].position.x = g_ENEMY[17].position.x;
				g_ENEMY[z].scriptpos--;
			}
			g_ENEMY[z].scriptpos++;
		}

		if (g_ENEMY[z].position.y > gridalignment * 18 || g_ENEMY[z].position.y < gridalignment * -6 || 
			g_ENEMY[z].position.x < gridalignment * -1 || 
			g_ENEMY[z].position.x > gridalignment * 20)
		{
			g_ENEMY[z].condition = dead;
			g_ENEMY[z].position.y = gridalignment * -6;
			g_ENEMY[z].randomdirectionpicked = no;
		}


		if (g_ENEMY[z].boss == bossone)
		{
			z+=3;//first boss primitive, need this
		}

	}// p == no
}