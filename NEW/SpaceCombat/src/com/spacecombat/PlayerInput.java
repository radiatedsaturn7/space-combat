package com.spacecombat;

public class PlayerInput extends Component implements ClickListener {
	
	Weapon weapon = null;
	BoxCollider collider = null;

	public PlayerInput(final Weapon w, final BoxCollider c) {
		Input.subscribeListener(this);
		this.weapon = w;
		this.collider = c;		
	}

	@Override
	public void onClick(float x, float y) {		
		if (this.gameObject == null) {
			return;
		}

		if (this.weapon != null) {
			this.weapon.shoot();
		}

		this.gameObject.transform.position.x = x;
		this.gameObject.transform.position.y = y;
		
		if (collider != null)
		{
			this.gameObject.transform.position.x -= collider.size.x * .5;
			this.gameObject.transform.position.y -= collider.size.y * 2;				
		}
	}
}
