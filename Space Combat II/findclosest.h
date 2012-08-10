int findclosest(int z, int x)
{
	int r = rand1.RandInt(1, 5);
	int f = r+1;
	if (r == 1)
	{
		for (f = 0; f < max_level_tiles; f++)
		{
			if (f>=max_level_tiles)
			{
				f=0;
			}
			if (g_ENEMY[f].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15)
			{
				g_ALLY[x].target = f;
				return f;
			}
		}
	}
	if (r == 2)
	{
		for (f = 5; f < max_level_tiles + 5; f++)
		{
			if (f>=max_level_tiles)
			{
				if (g_ENEMY[f-max_level_tiles].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15)
				{
					g_ALLY[x].target = f-max_level_tiles;
					return f;
				}
			}
			if (g_ENEMY[f].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15 && f<max_level_tiles)
			{
				g_ALLY[x].target = f;
				return f;
			}
		}
	}
	if (r == 3)
	{
		for (f = 10; f < max_level_tiles + 10; f++)
		{
			if (f>=max_level_tiles)
			{
				if (g_ENEMY[f-max_level_tiles].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15)
				{
					g_ALLY[x].target = f-max_level_tiles;
					return f;
				}
			}
			if (g_ENEMY[f].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15 && f<max_level_tiles)
			{
				g_ALLY[x].target = f;
				return f;
			}
		}
	}
	if (r == 4)
	{
		for (f = 15; f < max_level_tiles + 15; f++)
		{
			if (f>=max_level_tiles)
			{
				if (g_ENEMY[f-max_level_tiles].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15)
				{
					g_ALLY[x].target = f-max_level_tiles;
					return f;
				}
			}
			if (g_ENEMY[f].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15 && f<max_level_tiles)
			{
				g_ALLY[x].target = f;
				return f;
			}
		}
	}
	if (r == 5)
	{
		for (f = 20; f < max_level_tiles + 20; f++)
		{
			if (f>=max_level_tiles)
			{
				if (g_ENEMY[f-max_level_tiles].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15)
				{
					g_ALLY[x].target = f-max_level_tiles;
					return f;
				}
			}
			if (g_ENEMY[f].condition == alive && g_ENEMY[g_ALLY[x].target].SIZEheight + 128 < gridalignment * 15 && f<max_level_tiles)
			{
				g_ALLY[x].target = f;
				return f;
			}
		}
	}
	return g_ALLY[x].target;
}