void update_radar(int x)
{
	if (g_ENEMY[x].position.y < 0 || g_ENEMY[x].position.x < 0)
	{
		g_RADARTARGET[x + 1].position.y = -32;
		g_RADARTARGET[x + 1].position.x = -32;
	}
	else
	{
		g_RADARTARGET[x + 1].position.y =  1 + ((int)g_ENEMY[x].position.y / 16 + RADARFIXy);
		g_RADARTARGET[x + 1].position.x = 1 + ((int)g_ENEMY[x].position.x / 16 + RADARFIXx);
	}
	//fix player radar target
	g_RADARTARGET[0].position.y = 1 + ((int)g_PLAYER.position.y / 16 + RADARFIXy);
	g_RADARTARGET[0].position.x = 1 + ((int)g_PLAYER.position.x / 16 + RADARFIXx);

	//fix ally radar target
	if (x < maxally)
	{
		if (g_ALLY[x].position.y < 0 || g_ALLY[x].position.x < 0 || g_ALLY[x].condition == dead)
		{
			g_RADARTARGET[max_level_tiles + 1 + x].position.y = -32;
			g_RADARTARGET[max_level_tiles + 1 + x].position.x = -32;
		}
		else
		{
			g_RADARTARGET[max_level_tiles + 1 + x].position.y = 1 + ((int)g_ALLY[x].position.y / 16 + RADARFIXy);
			g_RADARTARGET[max_level_tiles + 1 + x].position.x = 1 + ((int)g_ALLY[x].position.x / 16 + RADARFIXx);
		}
	}
}