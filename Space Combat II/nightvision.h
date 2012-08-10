void animate_NV_fog()
{
	if (g_PLAYER.nightvision == yes)
	{
		AnimateSprite(&g_Buffer, &g_SCREEN[5]);
	}
}

void set_vision_type()
{
	for (int x = 0; x < max_level_tiles; x++)
	{
		if (g_PLAYER.vision == 2)
		{
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapNightVision;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapNightVision;
			g_PLAYER.hBitmap = g_PLAYER.hBitmapNightVision;
			if (x < maxally)
			{
					g_ALLY[x].hBitmap = g_ALLY[x].hBitmapNightVision;
			}
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapNightVision;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapNightVision;
			g_LASER[x].hBitmap = g_LASER[x].hBitmapNightVision;
			g_MGUN[x].hBitmap = g_MGUN[x].hBitmapNightVision;
			g_FLAME[x].hBitmap = g_FLAME[x].hBitmapNightVision;
			g_PULSE[x].hBitmap = g_PULSE[x].hBitmapNightVision;
			g_DLASER[x].hBitmap = g_DLASER[x].hBitmapNightVision;
			g_SLASER[x].hBitmap = g_SLASER[x].hBitmapNightVision;
			g_MISSILE[x].hBitmap = g_MISSILE[x].hBitmapNightVision;
			g_CHARGE[x].hBitmap = g_CHARGE[x].hBitmapNightVision;
			g_ALLYSHOT[x].hBitmap = g_ALLYSHOT[x].hBitmapNightVision;
			g_SPARK[x].hBitmap = g_SPARK[x].hBitmapNightVision;
			g_SMOKE[x].hBitmap = g_SMOKE[x].hBitmapNightVision;
			g_LEVEL[x].hBitmap = g_LEVEL[x].hBitmapNightVision;
			if (x < max_levels)
			{
				g_BACKROUND[x].hBitmap = g_BACKROUND[x].hBitmapNightVision;
			}
			if (x < max_particles)
			{
				g_PARTICLE[x].hBitmap = g_PARTICLE[x].hBitmapNightVision;
			}
			if (x < max_explosions)
			{
				g_EXPLOSION[x].hBitmap = g_EXPLOSION[x].hBitmapNightVision;
			}
		}
		else if (g_PLAYER.vision == 3 && g_PLAYER.mission >= 9)
		{
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapThermalVision;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapThermalVision;
			g_PLAYER.hBitmap = g_PLAYER.hBitmapThermalVision;
			if (x < maxally)
			{
					g_ALLY[x].hBitmap = g_ALLY[x].hBitmapThermalVision;
			}
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapThermalVision;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapThermalVision;
			g_LASER[x].hBitmap = g_LASER[x].hBitmapThermalVision;
			g_MGUN[x].hBitmap = g_MGUN[x].hBitmapThermalVision;
			g_FLAME[x].hBitmap = g_FLAME[x].hBitmapThermalVision;
			g_PULSE[x].hBitmap = g_PULSE[x].hBitmapThermalVision;
			g_DLASER[x].hBitmap = g_DLASER[x].hBitmapThermalVision;
			g_SLASER[x].hBitmap = g_SLASER[x].hBitmapThermalVision;
			g_MISSILE[x].hBitmap = g_MISSILE[x].hBitmapThermalVision;
			g_CHARGE[x].hBitmap = g_CHARGE[x].hBitmapThermalVision;
			g_ALLYSHOT[x].hBitmap = g_ALLYSHOT[x].hBitmapThermalVision;
			g_SPARK[x].hBitmap = g_SPARK[x].hBitmapThermalVision;
			g_SMOKE[x].hBitmap = g_SMOKE[x].hBitmapThermalVision;
			g_LEVEL[x].hBitmap = g_LEVEL[x].hBitmapThermalVision;
			if (x < max_levels)
			{
				g_BACKROUND[x].hBitmap = g_BACKROUND[x].hBitmapThermalVision;
			}
			if (x < max_particles)
			{
				g_PARTICLE[x].hBitmap = g_PARTICLE[x].hBitmapThermalVision;
			}
			if (x < max_explosions)
			{
				g_EXPLOSION[x].hBitmap = g_EXPLOSION[x].hBitmapThermalVision;
			}
		}
		else
		{
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapNormal;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapNormal;
			g_PLAYER.hBitmap = g_PLAYER.hBitmapNormal;
			if (x < maxally)
			{
					g_ALLY[x].hBitmap = g_ALLY[x].hBitmapNormal;
			}
			g_ENEMY[x].hBitmap = g_ENEMY[x].hBitmapNormal;
			g_ELASER[x].hBitmap = g_ELASER[x].hBitmapNormal;
			g_LASER[x].hBitmap = g_LASER[x].hBitmapNormal;
			g_MGUN[x].hBitmap = g_MGUN[x].hBitmapNormal;
			g_FLAME[x].hBitmap = g_FLAME[x].hBitmapNormal;
			g_PULSE[x].hBitmap = g_PULSE[x].hBitmapNormal;
			g_DLASER[x].hBitmap = g_DLASER[x].hBitmapNormal;
			g_SLASER[x].hBitmap = g_SLASER[x].hBitmapNormal;
			g_MISSILE[x].hBitmap = g_MISSILE[x].hBitmapNormal;
			g_CHARGE[x].hBitmap = g_CHARGE[x].hBitmapNormal;
			g_ALLYSHOT[x].hBitmap = g_ALLYSHOT[x].hBitmapNormal;
			g_SPARK[x].hBitmap = g_SPARK[x].hBitmapNormal;
			g_SMOKE[x].hBitmap = g_SMOKE[x].hBitmapNormal;
			g_LEVEL[x].hBitmap = g_LEVEL[x].hBitmapNormal;
			if (x < max_levels)
			{
				g_BACKROUND[x].hBitmap = g_BACKROUND[x].hBitmapNormal;
			}
			if (x < max_particles)
			{
				g_PARTICLE[x].hBitmap = g_PARTICLE[x].hBitmapNormal;
			}
			if (x < max_explosions)
			{
				g_EXPLOSION[x].hBitmap = g_EXPLOSION[x].hBitmapNormal;
			}
		}

		if (x < maxally)
		{
			if (g_ALLY[x].condition == dead)
			{
				g_ALLY[x].hBitmap = g_switcher.hBitmap;
				FreeSprite(&g_ALLY[x]);
			}
		}
		if (g_SMOKE[x].condition == dead)
		{
			g_SMOKE[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_SMOKE[x]);
		}
		if (g_SPARK[x].condition == dead)
		{
			g_SPARK[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_SPARK[x]);
		}
		if (g_CHARGE[x].condition == dead)
		{
			g_CHARGE[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_CHARGE[x]);
		}
		if (g_ALLYSHOT[x].condition == dead)
		{
			g_ALLYSHOT[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_ALLYSHOT[x]);
		}
		if (g_MISSILE[x].condition == dead)
		{
			g_MISSILE[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_MISSILE[x]);
		}
		if (g_SLASER[x].condition == dead)
		{
			g_SLASER[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_SLASER[x]);
		}
		if (g_DLASER[x].condition == dead)
		{
			g_DLASER[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_DLASER[x]);
		}
		if (g_ENEMY[x].condition == dead)
		{
			g_ENEMY[x].hBitmap = g_switcher.hBitmap;
			g_ENEMY[x].width = 32;
			g_ENEMY[x].height = 32;
			FreeSprite(&g_ENEMY[x]);
		}
		if (g_ELASER[x].condition == dead)
		{
			g_ELASER[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_ELASER[x]);
		}
		if (g_LASER[x].condition == dead)
		{
			g_LASER[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_LASER[x]);
		}
		if (g_MGUN[x].condition == dead)
		{
			g_MGUN[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_MGUN[x]);
		}
		if (g_FLAME[x].condition == dead)
		{
			g_FLAME[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_FLAME[x]);
		}
		if (g_PULSE[x].condition == dead)
		{
			g_PULSE[x].hBitmap = g_switcher.hBitmap;
			FreeSprite(&g_PULSE[x]);
		}
	}
}

void use_battery()
{
	if (g_PLAYER.vision == 1)
	{
		g_PLAYER.battery -= g_PLAYER.vision;
	}
	else if (g_PLAYER.vision == 2)
	{
		g_PLAYER.battery -= g_PLAYER.vision;
	}
	else if (g_PLAYER.vision == 3)
	{
		if (g_PLAYER.mission < 9)
		{
			g_PLAYER.vision = 0;
		}
		g_PLAYER.battery -= g_PLAYER.vision;
	}
	else if (g_PLAYER.battery < g_PLAYER.maxbattery)
	{
		g_PLAYER.battery += 3;
	}
}
