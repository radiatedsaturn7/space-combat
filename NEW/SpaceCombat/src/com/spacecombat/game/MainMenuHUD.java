package com.spacecombat.game;

import com.spacecombat.Camera;
import com.spacecombat.Component;
import com.spacecombat.Engine;
import com.spacecombat.GUI;
import com.spacecombat.GameObject;
import com.spacecombat.GraphicAnimation;
import com.spacecombat.TextAnimation;
import com.spacecombat.Time;
import com.spacecombat.Vector2;

public class MainMenuHUD extends Component 
{	
	public MainMenuHUD ()
	{
	}
	
	public void onGUI()
	{
		GUI.setDrawColor(255, 0, 0);
		GUI.drawText("Select Difficulty", 220, 400, 20, 20);
		
		if (GUI.drawText("Easy", 220, 420, 20, 20))
		{
			PrefabFactory.setDifficulty(PrefabFactory.EASY);
			LevelLoader.loadLevel("level1",true);
		}
		else if (GUI.drawText("Medium", 220, 450, 20, 20))
		{
			PrefabFactory.setDifficulty(PrefabFactory.MEDIUM);
			LevelLoader.loadLevel("level1",true);
		}
		else if (GUI.drawText("Hard", 220, 480, 20, 20))
		{
			PrefabFactory.setDifficulty(PrefabFactory.HARD);
			LevelLoader.loadLevel("level1",true);
		}
		GUI.setDrawColor(0, 0, 0);
	}
}
