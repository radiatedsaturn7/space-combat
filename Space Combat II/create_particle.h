void create_particle(int x, int y, int momy, int momx)
{
	for (int parts = 0; parts < max_particles; parts++)
	{
		if (g_PARTICLE[parts].condition != alive)
		{
			g_PARTICLE[parts].condition =alive;
			g_PARTICLE[parts].position.x = x;
			g_PARTICLE[parts].position.y = y;
			g_PARTICLE[parts].momentumx = momx;
			g_PARTICLE[parts].momentumy = momy;
			g_PARTICLE[parts].life = 0;
			break;
		}
	}
}