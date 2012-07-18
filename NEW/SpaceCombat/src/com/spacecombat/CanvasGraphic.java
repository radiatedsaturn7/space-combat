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

	public CanvasGraphic() {
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

		CanvasGraphic.loaded.put(name, bitmap);
		this.myBitmap = CanvasGraphic.loaded.get(name);
	}

	@Override
	public void draw(final int x, final int y, final int width,
			final int height, final int offsetX, final int offsetY,
			final int rotx, final int roty, final int scalex, final int scaley) {

		this.dst.set(offsetX, offsetY, offsetX + width, offsetY + height);

		if (!this.dst.intersect(CanvasGraphic.screen))
		{
			return;
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
				CanvasGraphic.canvas.rotate(rotx,this.dst.left+width/2,this.dst.top+height/2);
								CanvasGraphic.canvas.drawBitmap(this.myBitmap, this.src, this.dst,					
						CanvasGraphic.paint);	
				CanvasGraphic.canvas.restore();
			}
			else
			{
				CanvasGraphic.canvas.drawBitmap(this.myBitmap, this.src, this.dst,					
						CanvasGraphic.paint);	
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
