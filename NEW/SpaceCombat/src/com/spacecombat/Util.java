package com.spacecombat;

import java.util.Random;

public class Util {
	private static Random random;

	static {
		Util.random = new Random();
	}

	public static float randomNumber(final float num1, final float num2) {
		return Util.random.nextFloat() * num2 + num1;
	}

	public static int randomNumber(final int num1, int num2) {
		num2 = num2 + 1;
		return (Math.abs(Util.random.nextInt()) % (num2 - num1)) + num1;
	}
}
