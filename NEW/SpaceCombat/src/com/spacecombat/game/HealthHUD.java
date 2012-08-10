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

public class HealthHUD extends Component 
{
	private HealthController healthController;
	
	private float lastHealth = 0;
	private int maxHealth = 0;
	private float timeToPlay = 0.5f;
	private float lastTime = 0.0f;
	private boolean createGameOver = false;
	
	public HealthHUD (HealthController healthController)
	{		
		this.healthController = healthController;
		maxHealth = healthController.maxHealth;
		lastHealth = maxHealth;
	}
	
	public void onGUI()
	{
		if (healthController.health <= 0)
		{
			GUI.drawText("Game Over", 220, 400, 20, 20);
			GUI.drawText("Play Again?", 220, 420, 20, 20);
			
			if (GUI.drawText("Yes", 200, 440, 20, 20))
			{
				LevelLoader.loadLevel(LevelLoader.getLastLevelLoaded(),true);
			}
			
			if (GUI.drawText("No", 240, 440, 20, 20))
			{
				Engine.exit();
			}
		}
	}
	
	public void update ()
	{		
		int health = healthController.health;
		
		if (lastHealth != health && (health < lastHealth || health == maxHealth))
		{
			double value = ((float)health) / ((float)maxHealth);
			value *= 10;
			int floor = (int) Math.floor(value);
			floor *= 10;
			int percentage = floor;
			gameObject.playAnimation(percentage+"%");
			lastTime = Time.getTime();			
		}
		
		if (Time.getTime() > lastTime + timeToPlay)
		{
			gameObject.playAnimation("none");
		}
			 
		lastHealth = healthController.health;
	}	
	
	private Vector2 dir = new Vector2(0,1);	
	public void collide(final GameObject whatIHit) 
	{		
		if (!whatIHit.hasTag(this.gameObject.getTags())) 
		{
			dir.x = gameObject.transform.position.x - whatIHit.transform.position.x;
			dir.y = gameObject.transform.position.y - whatIHit.transform.position.y;
			gameObject.transform.rotation.x = dir.getAngle() + 180;
		}
	}
}
