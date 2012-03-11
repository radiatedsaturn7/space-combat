package com.spacecombat;

public class Component {
	protected GameObject gameObject = null;
	protected boolean isEnabled = true;

	public void collide(final Collision collision) {
	}

	public void destroy() {
		if (this.gameObject != null) {
			this.gameObject.removeComponent(this);
		}
	}

	public void draw() {
	}

	public boolean isEnabled() {
		return this.isEnabled;
	}

	public void onBeforeDestroy() {
	}

	public void onCreate() {
	}

	public void onStart() {
	}

	public void setEnabled(final boolean enabled) {
		this.isEnabled = enabled;
	}

	public void setGameObject(final GameObject o) {
		this.gameObject = o;
	}

	public void update() {
	}
}
