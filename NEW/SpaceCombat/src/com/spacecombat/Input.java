package com.spacecombat;

import java.util.ArrayList;
import java.util.List;

public class Input {

	private static float xPos;
	private static float yPos;
	private static boolean isMouseDown = false; 

	private static List<ClickListener> listeners;

	private static void fireOnClick() 	{
		if (Input.listeners == null) {
			return;
		}

		for (int x = 0; x < Input.listeners.size(); x++) {
			Input.listeners.get(x).onClick(Input.xPos, Input.yPos);
		}
	}

	public static void setClickDown	(final boolean b) 
	{
		Input.isMouseDown = b;
	}

	public static void setX(final float x) {
		Input.xPos = x;
	}

	public static void setY(final float y) {
		Input.yPos = y;
	}

	public static void subscribeListener(final ClickListener l) {
		if (Input.listeners == null) {
			Input.listeners = new ArrayList<ClickListener>();
		}
		Input.listeners.add(l);
	}

	public static void update ()
	{
		if (Input.isMouseDown)
		{
			Input.fireOnClick();
		}
	}
}
