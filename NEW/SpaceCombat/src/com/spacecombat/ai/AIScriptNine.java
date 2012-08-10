package com.spacecombat.ai;

import com.spacecombat.RigidBody;
import com.spacecombat.Vector2;

public class AIScriptNine extends AIScript {
	private boolean isReverse = false;

	private RigidBody rigidBody;
	private final Vector2 accel = new Vector2(2, 2);
	private final Vector2 maxSpeed = new Vector2(32, -32);

	public AIScriptNine(final boolean isReverse) {
		this.isReverse = isReverse;
	}

	@Override
	public void onCreate() {
		this.rigidBody = this.gameObject.getRigidBody();

		this.rigidBody.speed.x = this.maxSpeed.x;
		this.rigidBody.speed.y = this.maxSpeed.y;

		if (this.isReverse) {
			this.rigidBody.speed.x = -this.rigidBody.speed.x;
		}
	}

	@Override
	public void update() {
		if (this.rigidBody == null) {
			return;
		}

		if (!this.isReverse
				&& this.gameObject.transform.position.x < 416) {
			if (this.rigidBody.speed.x < this.maxSpeed.x) {
				this.rigidBody.speed.x += this.accel.x;
			}
		} else if (this.gameObject.transform.position.x > 64) {
			this.isReverse = true;
			if (this.rigidBody.speed.x > -this.maxSpeed.x) {
				this.rigidBody.speed.x -= this.accel.x;
			}
		} else {
			this.isReverse = false;
		}
	}
}
