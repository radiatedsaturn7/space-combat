package com.spacecombat.ai;

import com.spacecombat.Camera;
import com.spacecombat.GameObject;
import com.spacecombat.RigidBody;
import com.spacecombat.Time;
import com.spacecombat.Vector2;
import com.spacecombat.game.HealthController;
import com.spacecombat.game.PrefabFactory;

public class AIBoss4 extends AIScript {
	private boolean isReverse = false;

	private RigidBody rigidBody;
	private final Vector2 accel = new Vector2(2, 2);
	private final Vector2 maxSpeed = new Vector2(30, 15);
	private Vector2 startPos = new Vector2(0, 0);
	private float nextSpawnTime = 5;
	private float lastSpawnTime = 0;
	private final int maxWidth = 200;
	
	private HealthController hc;

	public AIBoss4(HealthController hc) {
		this.hc = hc;
	}

	@Override
	public void onCreate() {
		this.rigidBody = this.gameObject.getRigidBody();
		this.startPos = new Vector2(this.gameObject.transform.position);
		this.rigidBody.speed.x = maxSpeed.x;
		this.rigidBody.speed.y = maxSpeed.y;
	}

	private boolean leftRight = false;
	@Override
	public void update() {
		
		if (this.rigidBody == null) {
			return;
		}
		
		if (Time.getTime() > lastSpawnTime + nextSpawnTime)
		{
			lastSpawnTime = Time.getTime();
			Vector2 v1 = null;
			Vector2 v2 = null;
			
			int ship = 2;
			float percentage = ((float)(hc.health)) / ((float)(hc.maxHealth));
			
			if (percentage < .40)
			{
				ship = 5;
				nextSpawnTime = 6;
			}
			
			leftRight = !leftRight;
			v1 = new Vector2(gameObject.transform.position.x,gameObject.transform.position.y-32);
			v2 = new Vector2(gameObject.transform.position.x+208-32,gameObject.transform.position.y-32);
			
			if (leftRight)
			{
				GameObject.create(PrefabFactory.createEnemy("enemy", v1, ship, 6, leftRight));
			}
			
			if (!leftRight)
			{
				GameObject.create(PrefabFactory.createEnemy("enemy", v2, ship, 6, leftRight));
			}
		}
		
		if (this.gameObject.transform.position.y > Camera.mainCamera.gameObject.transform.position.y)
		{
			this.rigidBody.speed.y = 0;
		}
		else
		{
			this.rigidBody.speed.y = maxSpeed.y;
		}

		if (!this.isReverse && this.gameObject.transform.position.x < this.startPos.x + this.maxWidth) {
			if (this.rigidBody.speed.x < this.maxSpeed.x) {
				this.rigidBody.speed.x += this.accel.x;
			}
		} else if (this.gameObject.transform.position.x > this.startPos.x - this.maxWidth) {
			this.isReverse = true;
			if (this.rigidBody.speed.x > -this.maxSpeed.x) {
				this.rigidBody.speed.x -= this.accel.x;
			}
		} else {
			this.isReverse = false;
		}
	}
}
