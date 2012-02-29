import java.awt.*;

public class Entity_Teleport extends Entity
{
	public Point m_pTeleCoord;
	public Entity_Teleport (Entity_Teleport e)
	{
		super(e.m_rcBoundingBox.x,e.m_rcBoundingBox.y,e.m_rcBoundingBox.width,e.m_rcBoundingBox.height);
		m_pTeleCoord = new Point(e.m_pTeleCoord);
	}
	
	public Entity_Teleport (int x, int y, int w, int h, Point p)
	{
		super(x,y,w,h);
		m_pTeleCoord = new Point(p);
	}
	
	public void Update(Sprite S)
	{
		//System.out.println("Teleport");
		S.m_rcBoundingBox.x = m_pTeleCoord.x + Util.m_pGlobalOffset.x;
		S.m_rcBoundingBox.y = m_pTeleCoord.y + Util.m_pGlobalOffset.y;
		super.Update(S);
	}
}
