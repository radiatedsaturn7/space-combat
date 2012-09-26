package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Time;

public class LoadLevelAfter extends Component {

	private boolean isFired;
	private final String level;
	private float start;
	private float seconds;

	public LoadLevelAfter (final String level, float seconds) 
	{
		this.isFired = false;
		this.level = level;
		this.start = Time.getTime();
		this.seconds = seconds;
	}

	@Override
	public void  update ()
	{
		if (Time.getTime() > start + seconds)
		{
			LevelLoader.loadLevel(this.level,false);
		}
	}
}
