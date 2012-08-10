package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class LoadLevelOnDestroy extends Component {

	private final String level;

	public LoadLevelOnDestroy (final String level) 
	{
		this.level = level;
	}

	@Override
	public void destroy ()
	{
		LevelLoader.loadLevel(this.level,false);
	}
}
