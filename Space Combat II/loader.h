void display_loading()
{
	g_LOADER.condition = alive;
	g_LOADER.position.y = gridalignment * 6;
	g_LOADER.position.x = gridalignment * 6;
	g_LOADER.life = 0;
}

void update_loader()
{
	if (g_LOADER.life < 11 && g_LOADER.condition == alive)
	{
		SetSpriteState(&g_LOADER, g_LOADER.life);
		g_LOADER.life++;
	}
	else
	{
		g_LOADER.position.y = gridalignment * -7;
		g_LOADER.position.x = gridalignment * -7;
		g_LOADER.condition = dead;
	}
}