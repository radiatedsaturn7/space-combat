package com.spacecombat.game;

import com.spacecombat.Camera;
import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Pool;
import com.spacecombat.Poolable;
import com.spacecombat.RigidBody;

public class PlayerFollower extends Component
{
	public GameObject target;
	public float minWidth;
	public float maxWidth;
	public float startScrollLeft;
	public float startScrollRight;
	public float yScroll;
	public SimpleMovement simpleMovement;
	
	public PlayerFollower (GameObject target, SimpleMovement simpleMovement, float minWidth, float maxWidth, float startScrollLeft, float startScrollRight, float yScroll)
	{
		this.target = target;
		this.maxWidth = maxWidth;
		this.minWidth = minWidth;
		this.startScrollLeft = startScrollLeft;
		this.startScrollRight = startScrollRight;
		this.yScroll = yScroll;
		this.simpleMovement = simpleMovement;
	}
	
	public void update ()
	{
		if (this.target == null || this.target.isDestroyed() || this.gameObject.getRigidBody() == null || simpleMovement == null)
		{
			this.target = GameObject.findByName("player");
			System.out.println("NONE" + this.target);
			return;
		}

		if (this.target.transform.position.x - Camera.mainCamera.gameObject.transform.position.x > startScrollRight/* && Camera.mainCamera.gameObject.transform.position.x < maxWidth*/)
		{
			//System.out.println("MOVE RIGHT");
			simpleMovement.setSpeed(32, yScroll);
		}
		else if (this.target.transform.position.x - Camera.mainCamera.gameObject.transform.position.x < startScrollLeft/* && Camera.mainCamera.gameObject.transform.position.x > minWidth*/)
		{
			//System.out.println("CAMERA:"+this.gameObject.transform.rotation);
			//System.out.println("TARGET:"+this.target.transform.rotation);
			simpleMovement.setSpeed(-32, yScroll);
		}
		else
		{
			simpleMovement.setSpeed(0, yScroll);
		}
	}
}