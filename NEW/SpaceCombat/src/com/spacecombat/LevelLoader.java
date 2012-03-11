package com.spacecombat;

import java.io.File;
import android.content.Context;

import com.nea.nehe.lesson06.R;

public class LevelLoader {
	
	private static Context context;
	
	public static void setContext (Context c)
	{
		LevelLoader.context = c;
	}
	
	public static void LoadLevel (String name)
	{
		File f = getLevel(name);
	}
	
	public static File getLevel (String name)
	{
		if (name.equalsIgnoreCase("level1"))
		{
			LevelLoader.context.getResources().openRawResource(R.raw.level1);
		}
		
		return null;
	}
}
