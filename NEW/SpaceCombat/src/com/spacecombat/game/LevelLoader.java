package com.spacecombat.game;

import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedInputStream;
import android.content.Context;

import com.spacecombat.BoxCollider;
import com.spacecombat.Collider;
import com.spacecombat.FixedJoint;
import com.spacecombat.GameObject;
import com.spacecombat.R;
import com.spacecombat.Util;
import com.spacecombat.R.raw;
import com.spacecombat.RigidBody;
import com.spacecombat.Vector2;

public class LevelLoader {
	
	private static Context context;
	
	public static void setContext (Context c)
	{
		LevelLoader.context = c;
	}
	
	public static void loadLevel (String name) 
	{
		GameObject.create(PrefabFactory.createTopOfScreen());
		InputStream is = getLevel(name);
		java.io.InputStreamReader br = new java.io.InputStreamReader(is);

		StringBuffer sb = new StringBuffer();

		GameObject level = null;
		while (true)
		{
			int ascii;
			
			try {
				ascii = br.read();
			} catch (IOException e) {
				try {
					br.close();
				} catch (IOException e1) {
					throw new RuntimeException(e1);
				}
				throw new RuntimeException(e);
			}
			
			if (ascii == -1)
			{
				break;
			}

			char letter = (char)ascii;
			sb.append(letter);
		}

		String file = sb.toString();
		String[] lines = file.split("\\n");
		
		for (int x = 0; x < lines.length; x++)
		{
			if (lines[x].startsWith("createLevel"))
			{
				x++;
				String wadName = lines[x].trim();
				x++;
				String smapWidth = lines[x].trim();
				x++;
				String smapHeight = lines[x].trim();
				
				int mapWidth = Integer.parseInt(smapWidth);
				int mapHeight = Integer.parseInt(smapHeight);
				int [] map = new int[mapWidth*mapHeight];

				for (int y = 0; y < mapHeight; y++)
				{
					x++;
					String [] parts = lines[x].split(",");
					for (int z = 0; z < parts.length && z < mapWidth; z++)
					{
						map[y*mapWidth + z] = Integer.parseInt(parts[z].trim());
					}
					System.out.println();
				}
				
				level = PrefabFactory.createLevel(map, mapWidth, mapHeight, wadName);
				level.addComponent(new RandomSpawner());
				GameObject.create(level);
			}
			
			if (lines[x].startsWith("createEnemy"))
			{
				x++;
				String sspawnX = lines[x].trim();
				int spawnX = Integer.parseInt(sspawnX);
				x++;
				String sspawnY = lines[x].trim();
				int spawnY = Integer.parseInt(sspawnY);
				x++;
				String senemyX = lines[x].trim();
				int enemyX = Integer.parseInt(senemyX);
				x++;
				String senemyY = lines[x].trim();
				int enemyY = Integer.parseInt(senemyY);
				x++;
				String senemyType = lines[x].trim();
				int enemyType = Integer.parseInt(senemyType);
				x++;
				String sscriptType = lines[x].trim();
				int scriptType = Integer.parseInt(sscriptType);
				x++;
				String sisReversed = lines[x].trim();
				boolean isReversed = Boolean.parseBoolean(sisReversed);
				
				System.out.println("CREATED ENEMY:" + new Vector2(enemyX,enemyY) + " " + enemyType + " " + scriptType + " " + isReversed);
				GameObject objectToCreate = PrefabFactory.createEnemy("enemy", new Vector2(enemyX,enemyY), enemyType, scriptType, isReversed);
				GameObject spawner = PrefabFactory.createSpawner(level, spawnX, spawnY, objectToCreate);
								
				GameObject.create(spawner);
			}
			
			if (lines[x].startsWith("createPowerUp"))
			{
				x++;
				int spawnX = Integer.parseInt(lines[x].trim());
				x++;
				int spawnY = Integer.parseInt(lines[x].trim());
				x++;
				int powerupX = Integer.parseInt(lines[x].trim());
				x++;
				int powerupY = Integer.parseInt(lines[x].trim());
				x++;
				int powerupType = Integer.parseInt(lines[x].trim());
				x++;
				boolean canChange = Boolean.parseBoolean(lines[x].trim());
				
				System.out.println("CREATED POWER UP:" + new Vector2(powerupX,powerupY) + " " + powerupType + " " + " " + canChange);
				
				GameObject objectToCreate = PrefabFactory.createPowerUp(new Vector2(powerupX,powerupY), powerupType, canChange);
				GameObject spawner = PrefabFactory.createSpawner(level, spawnX, spawnY, objectToCreate);
								
				GameObject.create(spawner);
			}
			
			if (lines[x].startsWith("createAlly"))
			{
				x++;
				int spawnX = Integer.parseInt(lines[x].trim());
				x++;
				int spawnY = Integer.parseInt(lines[x].trim());
				x++;
				int allyX = Integer.parseInt(lines[x].trim());
				x++;
				int allyY = Integer.parseInt(lines[x].trim());
				x++;
				String allyType = lines[x].trim();
				x++;
				String weapon = lines[x].trim();
				
				System.out.println("CREATED ALLY:" + new Vector2(allyX,allyY) + " " + allyType + " " + " " + weapon);
				
				GameObject objectToCreate = PrefabFactory.createAlly("Ally - " + allyType, new Vector2(allyX, allyY), allyType, weapon);
				GameObject spawner = PrefabFactory.createSpawner(level, spawnX, spawnY, objectToCreate);
				
				GameObject.create(spawner);
			}
			
			if (lines[x].startsWith("createPlayer"))
			{
				x++;
				int spawnX = Integer.parseInt(lines[x].trim());
				x++;
				int spawnY = Integer.parseInt(lines[x].trim());
				x++;
				int playerX = Integer.parseInt(lines[x].trim());
				x++;
				int playerY = Integer.parseInt(lines[x].trim());
				x++;
				String playerType = lines[x].trim();
				
				System.out.println("CREATED PLAYER:" + new Vector2(playerX,playerY) + " " + playerType + " ");
				
				GameObject objectToCreate = PrefabFactory.createPlayer("Player1", new Vector2(playerX,playerY), playerType);
				GameObject spawner = PrefabFactory.createSpawner(level, spawnX, spawnY, objectToCreate);
				
				GameObject.create(spawner);
			}
		}
		
		try {
			br.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	private static Vector2 Vector2(int i, int j) {
		// TODO Auto-generated method stub
		return null;
	}

	public static InputStream getLevel (String name)
	{
		if (name.equalsIgnoreCase("level1"))
		{
			System.out.println("Loading level1");
			return LevelLoader.context.getResources().openRawResource(R.raw.level1);
		}
		
		System.out.println("ERROR");
		return null;
	}
}
