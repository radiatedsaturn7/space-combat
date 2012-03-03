package com.spacecombat;

import android.app.Activity;


import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.Rect;
import android.os.Bundle;
import android.view.View;

import java.io.IOException;
import java.io.InputStream;
import android.content.Context;
import com.nea.nehe.lesson06.R;

public class Run extends Activity {

	DemoView demoview;	

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		demoview = new DemoView(this);
		setContentView(demoview);
	}

	private class DemoView extends View
	{
		private Engine e;
		private Context context;
		private Paint paint;
		
		public DemoView(Context context){
			super(context);					
			this.context = context;
			paint = new Paint();
			PrefabFactory.setContext(context);
			CanvasGraphic.setPaint(paint);
			e = new Engine(context);
			e.createGameObjects();				
		}

		@Override 
		protected void onDraw(Canvas canvas) 
		{						
			super.onDraw(canvas);					
			CanvasGraphic.setCanvas(canvas);
			e.drawLoop();			
			this.invalidate();
		}
	}
}
