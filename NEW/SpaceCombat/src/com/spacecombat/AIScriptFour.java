package com.spacecombat;

public class AIScriptFour extends AIScript {

	private RigidBody rigidBody;

	private final Vector2 accel = new Vector2(2, 2);
	private final Vector2 maxSpeed = new Vector2(64, 160);
	private final GameObject target;

	private final int give = 8;

	public AIScriptFour(final String[] targets) {
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
			if (this.gameObject.transform.position.x > this.target.transform.position.x
					+ this.give) {
				if (this.rigidBody.speed.x > -this.maxSpeed.x) {
					this.rigidBody.speed.x -= this.accel.x;
				}
			} else if (this.gameObject.transform.position.x < this.target.transform.position.x
					- this.give) {
				if (this.rigidBody.speed.x < this.maxSpeed.x) {
					this.rigidBody.speed.x += this.accel.x;
				}
			} else {
				if (this.rigidBody.speed.x < 0) {
					this.rigidBody.speed.x += this.accel.x;
				} else if (this.rigidBody.speed.x > 0) {
					this.rigidBody.speed.x -= this.accel.x;
				}
			}
		}

		if (this.rigidBody.speed.y < this.maxSpeed.y) {
			this.rigidBody.speed.y += this.accel.y;
		}
	}
}
