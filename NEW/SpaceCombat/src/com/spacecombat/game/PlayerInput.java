package com.spacecombat.game;

import com.spacecombat.BoxCollider;
import com.spacecombat.ClickListener;
import com.spacecombat.Component;
import com.spacecombat.Input;
import com.spacecombat.Time;
import com.spacecombat.weapons.WeaponController;

public class PlayerInput extends Component implements ClickListener {
	
	WeaponController wc = null;
	BoxCollider collider = null;
	
	float changeTime = 0.25f;
	float nextChange = 0.0f;
	float lastX = 0;
	float lastY = 0;

	public PlayerInput(final WeaponController wc, final BoxCollider c) {
		Input.subscribeListener(this);
		this.wc = wc;
		this.collider = c;		
	}

	@Override
	public void onClick(float x, float y) {		
		if (this.gameObject == null) {
			return;
		}

		if (this.wc.getSelectedWeapon() != null) {
			this.wc.getSelectedWeapon().shoot();
		}		
		
		lastX = this.gameObject.transform.position.x;
		lastY = this.gameObject.transform.position.y;
		
		this.gameObject.transform.position.x = x;
		this.gameObject.transform.position.y = y;
		
		if (collider != null)
		{
			this.gameObject.transform.position.x -= collider.size.x * .5;
			this.gameObject.transform.position.y -= collider.size.y * 2;				
		}
	}
	
	public void update ()
	{
		if (Time.getTime() <= nextChange)
		{
			return;			
		}				
		
		if (lastY < this.gameObject.transform.position.y)
		{
			nextChange = Time.getTime() + changeTime;
			if (lastX < this.gameObject.transform.position.x)
			{
				gameObject.playAnimation("DOWNRIGHT");				
			}
			else if (lastX > this.gameObject.transform.position.x)
			{
				gameObject.playAnimation("DOWNLEFT");
			}
			else
			{
				gameObject.playAnimation("DOWN");
			}
		}
		else if (lastY > this.gameObject.transform.position.y)
		{
			nextChange = Time.getTime() + changeTime;
			if (lastX < this.gameObject.transform.position.x)
			{
				gameObject.playAnimation("UPLEFT");
			}
			else if (lastX > this.gameObject.transform.position.x)
			{
				gameObject.playAnimation("UPLEFT");
			}
			else
			{
				gameObject.playAnimation("UP");
			}			
		}
		else
		{
			if (lastX < this.gameObject.transform.position.x)
			{
				nextChange = Time.getTime() + changeTime;
				gameObject.playAnimation("RIGHT");
			}
			else if (lastX > this.gameObject.transform.position.x)
			{
				nextChange = Time.getTime() + changeTime;
				gameObject.playAnimation("LEFT");
			}
			else
			{
				gameObject.playAnimation("IDLE");
			}
		}
		
		lastX = this.gameObject.transform.position.x;
		lastY = this.gameObject.transform.position.y;

	}
}