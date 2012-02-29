package com.spacecombat;

public class Rectangle 
{
		public int x;
		public int y;
		public int width;
		public int height;
		
		public Rectangle() {}
		public Rectangle(int i, int j, int k, int l) {
			x = i;
			y = j;
			width = k;
			height = l;
		}
		public int getWidth() { return width; }
		public int getHeight() { return height; }
		public int getX() { return x; }
		public int getY() { return height; }
		
		public boolean collidesWith (Rectangle r)
		{
			int otherTop = r.y;
			int otherBottom = r.y - r.height;
			int otherLeft = r.x;
			int otherRight = r.x + r.width;
			
			int myTop = y;
			int myBottom = y - height;
			int myLeft = x;
			int myRight = x + width;
			
			if (myLeft > otherRight ||
				myRight < otherLeft ||
				myBottom > otherTop ||
				myTop < otherBottom)			
				{
						return false;
				}
				
				return true;
		}
		
		public String toString ()
		{
			return new String("RECT x:" + x + " y:" + y + " w:" + width + " h:" + height);
		}
}
