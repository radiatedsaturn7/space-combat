package com.spacecombat;

public class AIScriptFive extends AIScript {

	private RigidBody rigidBody;

	private final Vector2 accel = new Vector2(2, 2);
	private final Vector2 maxSpeed = new Vector2(32, 32);
	private final GameObject target;

	public AIScriptFive(final String[] targets) {
		this.target = GameObject.findRandomByTags(targets);
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

		if (this.target != null) {
			this.gameObject.transform.position.x = this.target.transform.position.x;
		}

		if (this.rigidBody.speed.y < this.maxSpeed.y) {
			this.rigidBody.speed.y += this.accel.y;
		}
	}
}
