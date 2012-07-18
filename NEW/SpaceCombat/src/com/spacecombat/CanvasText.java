package com.spacecombat;

import android.graphics.Canvas;
import android.graphics.Paint;

public class CanvasText implements GenericText
{
	private String text;
	private static Canvas canvas;
	private static Paint paint;
	
	public static void setCanvas(final Canvas canvas) {
		CanvasText.canvas = canvas;
	}

	public static void setPaint(final Paint paint) {
		CanvasText.paint = paint;
	}
	
	public void create(final String text) {
		this.text = text;
	}

	@Override
	public void draw(final int offsetx, final int offsety, final int rotx, final int roty, final int scalex, final int scaley) {
		//System.out.println("DRAWING:" + text + " AT (" + offsetx + "," + offsety + ")");
		CanvasText.canvas.drawText(text, offsetx, offsety, paint);
	}

	@Override
	public int getHeight() {
		return 0;
	}

	@Override
	public int getWidth() {
		return 0;
	}

}
