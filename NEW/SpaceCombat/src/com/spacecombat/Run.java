package com.spacecombat;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;

import com.spacecombat.game.LevelLoader;
import com.spacecombat.game.PrefabFactory;

public class Run extends Activity {
	public static Engine e = null;
	public static Paint paint = null;
	public static boolean created = false;
	
	private class DemoView extends View implements View.OnTouchListener {

		public DemoView(final Context context) {			
			super(context);			
			paint = new Paint();
			PrefabFactory.setContext(context);
			LevelLoader.setContext(context);
			CanvasGraphic.setPaint(paint);
			CanvasText.setPaint(paint);
			if (!created)
			{
				e = new Engine();
				e.createGameObjects();
			}
			created = true;
		}

		@Override
		protected void onDraw(final Canvas canvas) {

			super.onDraw(canvas);
			CanvasGraphic.setCanvas(canvas);
			CanvasText.setCanvas(canvas);
			e.drawLoop();
			this.invalidate();			
		}

		@Override
		public boolean onTouch(final View v, final MotionEvent event) {

			Input.setX(event.getX());
			Input.setY(event.getY());

			if (event.getAction() == MotionEvent.ACTION_DOWN)
			{
				Input.setClickDown(true);
			}
			if (event.getAction() == MotionEvent.ACTION_UP)
			{
				Input.setClickDown(false);
			}			
			return true;
		}
	}

	DemoView demoview;
	SharedPreferences preferences = null;
	
	@Override
	public void onCreate(final Bundle savedInstanceState) {
		preferences = this.getSharedPreferences(getPackageName(), MODE_PRIVATE);
		super.onCreate(savedInstanceState);
		this.demoview = new DemoView(this);
		this.demoview.setOnTouchListener(this.demoview);
		setContentView(this.demoview);
	}
	
	@Override
	public void onResume ()
	{
		//load previous state		
		e.fromBackground(preferences);
	}
	
	@Override
	public void onPause ()
	{
		//save previous state
		e.toBackground(preferences.edit());
	}
}
