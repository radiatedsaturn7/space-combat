package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Time;
import com.spacecombat.Util;
import com.spacecombat.Vector2;

public class RandomSpawner extends Component {
	public float nextSpawn = 0;
	public float spawnTime = 1.0f;
	
	public void update ()
	{
		if (Time.getTime() > nextSpawn)
		{
			nextSpawn = Time.getTime() + spawnTime;
			
			if (Util.randomNumber(0, 1) == 1)
			{
				return;
			}
			
			int spawn = Util.randomNumber(0,15);
			int x = Util.randomNumber(0,400);
			
			if (spawn <= 13)
			{
				int scriptType = Util.randomNumber(1,5);
				boolean reverse = Util.randomNumber(0,1) == 1;
				GameObject.create(PrefabFactory.createEnemy("E"+new String(new Integer(spawn).toString()), new Vector2(x,0), spawn, scriptType, reverse));
			}
			else
			{
				GameObject.create(PrefabFactory.createPowerUp(new Vector2(x,0), 0, true));
			}
		}
	}
}
