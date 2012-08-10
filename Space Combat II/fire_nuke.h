void fire_nuke()
{ 
	if (g_NUKE.condition == dead && g_PLAYER.nuke >= 1)
	{
		for (int x = 0; x < max_level_tiles; x++)
		{
			if (x < lasermax)
			{
				g_LASER[x].condition = dead;
				g_MGUN[x].condition = dead;
				g_PULSE[x].condition = dead;
				g_FLAME[x].condition = dead;
				g_ALLYSHOT[x].condition = dead;
				g_CHARGE[x].condition = dead;
				g_DLASER[x].condition = dead;
				g_SLASER[x].condition = dead;
				g_MISSILE[x].condition = dead;

				g_LASER[x].position.y = -300;
				g_MGUN[x].position.y = -300;
				g_PULSE[x].position.y = -300;
				g_FLAME[x].position.y = -300;
				g_ALLYSHOT[x].position.y = -300;
				g_CHARGE[x].position.y = -300;
				g_DLASER[x].position.y = -300;
				g_SLASER[x].position.y = -300;
				g_MISSILE[x].position.y = -300;

				g_LASER[x].position.x = -300;
				g_MGUN[x].position.x = -300;
				g_PULSE[x].position.x = -300;
				g_FLAME[x].position.x = -300;
				g_ALLYSHOT[x].position.x = -300;
				g_CHARGE[x].position.x = -300;
				g_DLASER[x].position.x = -300;
				g_SLASER[x].position.x = -300;
				g_MISSILE[x].position.x = -300;
			}
			g_ELASER[x].condition = dead;
			g_ELASER[x].position.y = offscreen-300;
			g_ELASER[x].position.x = offscreen-300;

			g_ENEMY[x].health -= 16.0;
		}

		g_PLAYER.nuke--;
		g_NUKE.condition = dyingone;
		if (TALKING == no)
								{
		PlaySound("Nuke.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		g_NUKE.position.y = 0;
		g_NUKE.position.x = 0;
		SetSpriteState(&g_NUKE, 0);
	}
}