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

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Float.floatToIntBits(x);
		result = prime * result + Float.floatToIntBits(y);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Vector2 other = (Vector2) obj;
		if (Float.floatToIntBits(x) != Float.floatToIntBits(other.x))
			return false;
		if (Float.floatToIntBits(y) != Float.floatToIntBits(other.y))
			return false;
		return true;
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

	public float getAngle()
	{		
		if (y < 0)
		{
			return (float)Math.toDegrees(Math.atan(-this.x / this.y));
		}
		else
		{
			return 180.0f + (float)Math.toDegrees(Math.atan(-this.x / this.y));
		}
	}
	
	@Override
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}