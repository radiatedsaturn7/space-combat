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
	public boolean equals (final Object o)
	{
		if (o instanceof Vector2)
		{
			final Vector2 v = (Vector2)o;
			if (Math.abs(v.x - this.x) < 0.001 && Math.abs(v.y - this.y) < 0.001)
			{
				return true;
			}
		}
		return false;
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