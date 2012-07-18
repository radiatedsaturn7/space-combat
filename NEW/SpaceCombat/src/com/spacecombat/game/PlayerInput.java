package com.spacecombat.game;

import com.spacecombat.BoxCollider;
import com.spacecombat.Camera;
import com.spacecombat.ClickListener;
import com.spacecombat.Component;
import com.spacecombat.Input;
import com.spacecombat.Time;
import com.spacecombat.weapons.WeaponController;

public class PlayerInput extends Component implements ClickListener {

	WeaponController [] wc = null;
	BoxCollider collider = null;

	float changeTime = 0.25f;
	float nextChange = 0.0f;
	float lastX = 0;
	float lastY = 0;
	boolean clicked = false;

	public PlayerInput(final WeaponController [] wc, final BoxCollider c) {
		Input.subscribeListener(this);
		this.wc = wc;
		this.collider = c;		
	}

	@Override
	public void onClick(final float x, final float y) {		
		if (this.gameObject == null) {
			return;
		}

		for (int d = 0; d < this.wc.length; d++)
		{
			if (this.wc[d].getSelectedWeapon() != null) {				
				this.wc[d].getSelectedWeapon().shoot();
			}
		}

		this.lastX = this.gameObject.transform.position.x;
		this.lastY = this.gameObject.transform.position.y;

		this.gameObject.transform.position.x = x + Camera.mainCamera.gameObject.transform.position.x;
		this.gameObject.transform.position.y = y + Camera.mainCamera.gameObject.transform.position.y;

		if (this.collider != null)
		{
			this.gameObject.transform.position.x -= this.collider.size.x * .5;
			this.gameObject.transform.position.y -= this.collider.size.y * 4;				
		}
		clicked = true;
	}

	@Override
	public void update ()
	{
		if (!clicked)
		{
			this.gameObject.getRigidBody().speed.y = -10;
		}
		else
		{
			this.gameObject.getRigidBody().speed.y = 0;
		}
		
		clicked = false;
		if (Time.getTime() <= this.nextChange)
		{
			return;			
		}				

		if (this.lastY < this.gameObject.transform.position.y)
		{
			this.nextChange = Time.getTime() + this.changeTime;
			if (this.lastX < this.gameObject.transform.position.x)
			{
				this.gameObject.playAnimation("DOWNRIGHT");				
			}
			else if (this.lastX > this.gameObject.transform.position.x)
			{
				this.gameObject.playAnimation("DOWNLEFT");
			}
			else
			{
				this.gameObject.playAnimation("DOWN");
			}
		}
		else if (this.lastY > this.gameObject.transform.position.y)
		{
			this.nextChange = Time.getTime() + this.changeTime;
			if (this.lastX < this.gameObject.transform.position.x)
			{
				this.gameObject.playAnimation("UPLEFT");
			}
			else if (this.lastX > this.gameObject.transform.position.x)
			{
				this.gameObject.playAnimation("UPLEFT");
			}
			else
			{
				this.gameObject.playAnimation("UP");
			}			
		}
		else
		{
			if (this.lastX < this.gameObject.transform.position.x)
			{
				this.nextChange = Time.getTime() + this.changeTime;
				this.gameObject.playAnimation("RIGHT");
			}
			else if (this.lastX > this.gameObject.transform.position.x)
			{
				this.nextChange = Time.getTime() + this.changeTime;
				this.gameObject.playAnimation("LEFT");
			}
			else
			{
				this.gameObject.playAnimation("IDLE");
			}
		}

		this.lastX = this.gameObject.transform.position.x;
		this.lastY = this.gameObject.transform.position.y;

	}
}
