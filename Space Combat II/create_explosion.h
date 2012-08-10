void create_explosion(int x, int y, int momy, int momx)
{
	for (int parts = 0; parts < max_explosions; parts++)
	{
		if (g_EXPLOSION[parts].condition != alive)
		{
			g_EXPLOSION[parts].condition =alive;
			g_EXPLOSION[parts].position.x = x;
			g_EXPLOSION[parts].position.y = y;
			g_EXPLOSION[parts].momentumx = momx;
			g_EXPLOSION[parts].momentumy = momy;
			g_EXPLOSION[parts].life = 0;
			break;
		}
	}
}