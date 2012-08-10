package com.spacecombat.ai;

import com.spacecombat.RigidBody;
import com.spacecombat.Vector2;

public class AIScriptEight extends AIScript {
	private RigidBody rigidBody;
	private final Vector2 accel = new Vector2(2, -2);
	private final Vector2 maxSpeed = new Vector2(32, -32);

	public AIScriptEight(final boolean isReverse) {
		if (isReverse) {
			this.maxSpeed.y = this.maxSpeed.y * .5f;
		}
	}

	@Override
	public void onCreate() {
		this.rigidBody = this.gameObject.getRigidBody();
	}

	@Override
	public void update() {
		if (this.rigidBody == null) {
			return;
		}

		if (this.rigidBody.speed.y > this.maxSpeed.y) {
			this.rigidBody.speed.y += this.accel.y;
		}
	}
}
