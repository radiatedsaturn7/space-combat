void addpoints(int f)
{
	int points_gained = 0;
	if (g_ENEMY[f].boss == no)
	{
		if(g_ENEMY[f].ship == 1)
		{
			points_gained = 5;
		}
		if(g_ENEMY[f].ship == 2)
		{
			points_gained = 10;
		}
		if(g_ENEMY[f].ship == 3)
		{
			points_gained = 15;
		}
		if(g_ENEMY[f].ship == 4)
		{
			points_gained = 20;
		}
		if(g_ENEMY[f].ship == 5)
		{
			points_gained = 24;
		}
		if(g_ENEMY[f].ship == 6)
		{
			points_gained = 30;
		}
		if(g_ENEMY[f].ship == 7)
		{
			points_gained = 34;
		}
		if(g_ENEMY[f].ship == 8)
		{
			points_gained = 36;
		}
		if(g_ENEMY[f].ship == 9)
		{
			points_gained = 50;
		}
		if(g_ENEMY[f].ship == 10)
		{
			points_gained = 75;
		}
		if(g_ENEMY[f].ship == 11)
		{
			points_gained = 5;
		}
		if(g_ENEMY[f].ship == 12)
		{
			points_gained = 4;
		}
		if(g_ENEMY[f].ship == 13)
		{
			points_gained = 3;
		}
	}
	else
	{
		points_gained = 500;
	}
	while (points_gained >= 1)
	{
		g_PLAYER.points++;
		points_gained--;
		if (g_PLAYER.points %  250 == 0)
		{
			power_up(-1);
		}
	}	
}