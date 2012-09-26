package com.spacecombat;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

public class CanvasGraphic implements GenericGraphic {

	private static Rect screen = new Rect(0,0,480,800);
	private static Canvas canvas;
	private static Paint paint;
	private static HashMap<String, Bitmap> loaded;	

	public static void setCanvas(final Canvas canvas) {
		CanvasGraphic.canvas = canvas;
	}

	public static void setPaint(final Paint paint) {
		CanvasGraphic.paint = paint;
	}

	private Rect src;

	private Rect dst;

	private Bitmap myBitmap;
	private int layer;
	private String name = null;

	public CanvasGraphic() {
	}
	
	public String getName()
	{
		return name;
	}

	@Override
	public void create(final String name, InputStream is, final int layer) {
		this.src = new Rect(0, 0, 32, 32);
		this.dst = new Rect(0, 0, 32, 32);
		this.layer = layer;
		if (CanvasGraphic.loaded == null) {
			CanvasGraphic.loaded = new HashMap<String, Bitmap>();
		}

		if (CanvasGraphic.loaded.containsKey(name)) {
			this.myBitmap = CanvasGraphic.loaded.get(name);
			return;
		}
		
		if (is == null)
		{
			throw new RuntimeException("INPUT STREAM IS NULL");
		}

		Bitmap bitmap = null;
		try {
			// BitmapFactory is an Android graphics utility for images
			bitmap = BitmapFactory.decodeStream(is);
		} finally {
			// Always clear and close
			try {
				is.close();
				is = null;
			} catch (final IOException e) {
				throw new RuntimeException(e);
			}
		} 
		
		if (bitmap == null)
		{
			throw new RuntimeException("GRAPHIC CREATED, IS NULL");
		}

		CanvasGraphic.loaded.put(name, bitmap);
		this.myBitmap = CanvasGraphic.loaded.get(name);
		
		if (this.myBitmap == null)
		{
			throw new RuntimeException("GRAPHIC CREATED, STILL NULL");
		}
		this.name  = name;
	}

	@Override
	public void draw(final int x, final int y, final int width,
			final int height, final int offsetX, final int offsetY,
			final int rotx, final int roty, final int scalex, final int scaley) {

		this.dst.set(0, 0, width, height);

		if (!this.dst.intersect(CanvasGraphic.screen))
		{
			return;
		}
		
		if (this.myBitmap == null)
		{
			throw new RuntimeException("BITMAP IS NULL");
		}


		if (CanvasGraphic.canvas != null && CanvasGraphic.paint != null) {
			// Bitmap bitmap = loaded.get(name);

			// Rect src = new Rect(x,y,x+width,y+height);
			// Rect dst = new Rect(offsetX,offsetY,offsetX+width,offsetY+width);

			// canvas.drawBitmap(bitmap, 100, 100, paint);			
			
			this.src.set(x, y, x + width, y + height);

			
			if (rotx != 0)
			{
				CanvasGraphic.canvas.save();
				CanvasGraphic.canvas.rotate(rotx,offsetX+width/2,offsetY+height/2);
				CanvasGraphic.canvas.translate(offsetX,offsetY);
				CanvasGraphic.canvas.drawBitmap(this.myBitmap, this.src, this.dst, CanvasGraphic.paint);	
				CanvasGraphic.canvas.restore();
			}
			else
			{
				CanvasGraphic.canvas.save();
				CanvasGraphic.canvas.translate(offsetX,offsetY);
				CanvasGraphic.canvas.drawBitmap(this.myBitmap, this.src, this.dst,					
						CanvasGraphic.paint);	
				CanvasGraphic.canvas.restore();
			}

		} else if (CanvasGraphic.canvas == null) {
			throw new RuntimeException("Canvas is null");
		} else if (CanvasGraphic.paint == null) {
			throw new RuntimeException("paint is null");
		}
	}

	@Override
	public int getHeight() {
		return this.myBitmap.getHeight();
	}

	@Override
	public int getLayer ()
	{
		return this.layer;
	}

	@Override
	public int getWidth() {
		return this.myBitmap.getWidth();
	}
}
