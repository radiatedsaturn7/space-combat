package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.RigidBody;

public class SimpleMovement extends Component {
	private float speedX = 0;
	private float speedY = 0;

	private RigidBody rigidBody;	
	
	public SimpleMovement (RigidBody r, float x, float y)
	{
		this.rigidBody = r;
		this.speedX = x;
		this.speedY = y;
	}
	
	public void setSpeed(float x, float y) {
		this.speedX = x;
		this.speedY = y;
		
		this.rigidBody.speed.x = this.speedX;
		this.rigidBody.speed.y = this.speedY;
	}
	
	public float getSpeedX ()
	{
		return speedX;
	}
	
	public float getSpeedY ()
	{
		return speedY;
	}
	
	@Override
	public void update() {
		this.rigidBody.speed.x = this.speedX;
		this.rigidBody.speed.y = this.speedY;
	}
}
