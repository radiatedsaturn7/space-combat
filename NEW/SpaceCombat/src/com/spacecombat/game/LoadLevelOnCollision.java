package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class LoadLevelOnCollision extends Component {

	private boolean isFired;
	private final String level;

	public LoadLevelOnCollision (final String level) 
	{
		this.isFired = false;
		this.level = level;
	}

	@Override
	public void  collide (final GameObject whatIHit)
	{
		if (whatIHit.getName().equals("TopOfScreen"))
		{
			if (this.isFired)
			{
				return;
			}
			this.isFired = true;

			LevelLoader.loadLevel(this.level);
		}
	}
}
