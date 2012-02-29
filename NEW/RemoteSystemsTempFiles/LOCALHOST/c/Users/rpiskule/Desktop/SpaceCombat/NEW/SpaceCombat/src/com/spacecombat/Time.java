package com.spacecombat;

public class Time 
{
	private static float currentTime = 0;
	private static float deltaTime = 0;
	private static float lastTime = 0;
	
	public static float getTime ()
	{
		return currentTime;
	}
	
	public static float getDeltaTime ()
	{
		return deltaTime;
	}
	
	public static void tick ()
	{
		float f = (float)System.nanoTime();
		currentTime = f / 1000000.0f / 1000.0f;
		if (lastTime == 0)
		{
			lastTime = currentTime;
		}
		deltaTime = currentTime - lastTime;
	}
	
}
