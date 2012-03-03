package com.spacecombat;

import java.util.Random;
import android.content.Context;

public class Util 
{
	private static Random random;
	
	static
	{
		random = new Random();
	}
	
	public static int randomNumber (int num1, int num2)
	{		
		num2 = num2+1;
		return (Math.abs(random.nextInt()) % (num2-num1)) + num1;
	}
	
	public static float randomNumber (float num1, float num2)
	{
		return random.nextFloat() * num2 + num1;
	}
}
