void power_up(int type)
{
	int x;
	if (type == -1)
	{

				for (x = 0; x < 5; x++)
				{
					if (g_POWERUP[x].condition == dead)
					{
						g_POWERUP[x].condition = alive;
						g_POWERUP[x].script = scriptpowerup;
						g_POWERUP[x].scriptpos = 0;
						g_POWERUP[x].type = rand1.RandInt(0, 10);
						g_POWERUP[x].yhold = 0;
						g_POWERUP[x].change = yes;
						SetSpriteState(&g_POWERUP[x], g_POWERUP[x].type);
						break;
					}
				}

	}
	if (type == -2)
	{
		random = rand1.RandInt(0, 350);
			if (random == 1)
			{
				for (x = 0; x < 5; x++)
				{
					if (g_POWERUP[x].condition == dead)
					{
						g_POWERUP[x].condition = alive;
						g_POWERUP[x].script = scriptpowerup;
						g_POWERUP[x].scriptpos = 0;
						g_POWERUP[x].type = rand1.RandInt(0, 10);
						g_POWERUP[x].yhold = 0;
						g_POWERUP[x].change = yes;
						SetSpriteState(&g_POWERUP[x], g_POWERUP[x].type);
						break;
					}
				}
			}
	}
	else
	{
		for (x = 0; x < 5; x++)
				{
					if (g_POWERUP[x].condition == dead)
					{
						g_POWERUP[x].condition = alive;
						g_POWERUP[x].change = no;
						g_POWERUP[x].script = scriptpowerup;
						g_POWERUP[x].scriptpos = 0;
						g_POWERUP[x].type = type;
						g_POWERUP[x].yhold = 0;
						SetSpriteState(&g_POWERUP[x], g_POWERUP[x].type);
						break;
					}
				}
	}
	g_time++;
}