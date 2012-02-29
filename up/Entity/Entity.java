import java.awt.*;

public abstract class Entity
{
	public Rectangle m_rcBoundingBox;
	public Entity m_eTarget;
	
	public Entity(Entity e)
	{
		m_rcBoundingBox = new Rectangle(e.m_rcBoundingBox);
	}
	public Entity(int x, int y, int w, int h)
	{
		m_rcBoundingBox = new Rectangle(x,y,w,h);
	}
	public void Update(Sprite S)
	{
		if (m_eTarget != null)
			m_eTarget.Update(S);
	}
	
	public boolean IsColliding(Rectangle B)
	{
		if (this.m_rcBoundingBox.intersects(B))
		{
			return true;
		}
		return false;
	}
}
