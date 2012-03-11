package com.spacecombat;

public class Collision {
	private final GameObject me;
	private final GameObject whatIHit;
	protected boolean isDestroyed = false;

	public Collision(final GameObject me, final GameObject whatIHit) {
		this.me = me;
		this.whatIHit = whatIHit;
	}

	public GameObject getMe() {
		return this.me;
	}

	public GameObject getWhatIHit() {
		return this.whatIHit;
	}
}
