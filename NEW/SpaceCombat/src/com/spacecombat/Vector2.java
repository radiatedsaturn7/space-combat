package com.spacecombat;

public class Vector2 {
	public float x = 0;
	public float y = 0;

	public Vector2() {
	}

	public Vector2(final float x, final float y) {
		this.x = x;
		this.y = y;
	}

	public Vector2(final Vector2 v) {
		this.x = v.x;
		this.y = v.y;
	}

	public void normalize() {
		final float l = (float) Math.sqrt(this.x * this.x + this.y * this.y);
		this.x = this.x / l;
		this.y = this.y / l;
	}

	public Vector2 toNormalize() {
		final float l = (float) Math.sqrt(this.x * this.x + this.y * this.y);
		return new Vector2(this.x / l, this.y / l);
	}

	@Override
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}