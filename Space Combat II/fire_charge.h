void fire_charge()
{
	for (int x = 0; x < 100; x++)
	{
		if (g_PLAYER.charge >= 100)
		{
			g_PLAYER.charge -= 100;
			g_PLAYER.momentumy += g_PLAYER.max_momentumY;
			g_CHARGE[x].position.x = g_PLAYER.position.x;
			g_CHARGE[x].position.y = g_PLAYER.position.y - 16;
			g_CHARGE[x].condition = alive;

			if (x >= 0)
			{
				if (x % 2 == 0)
				{
					g_CHARGE[x].position.x = g_PLAYER.position.x + (13 * x);
				}
				else
				{
					g_CHARGE[x].position.x = g_PLAYER.position.x - (13 * x);
				}
			}
		}
	}
	g_PLAYER.charge = 0;
}