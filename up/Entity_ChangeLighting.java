import java.awt.*;
class Entity_ChangeLighting extends Entity
{
	public int m_iStatus;
	public Entity_ChangeLighting(Entity_ChangeLighting e)
	{
		super((Entity)e);
		m_iStatus = e.m_iStatus;
	}
	public Entity_ChangeLighting(int x, int y, int w, int h, Point p, int i)
	{
		super(x,y,w,h,p);
		m_iStatus = i;
	}
	public void Update(Sprite S)
	{
		m_bUpdated = true;
		Util.m_bDayTime = true;
		if (m_iStatus == Util.NIGHT)
			Util.m_bDayTime = false;
		Util.m_iLightStatus = m_iStatus;
		if (m_eTarget != null)
			m_eTarget.Update(S);
	}
	public void Update()
	{
		//System.out.println("UPDATED");
		m_bUpdated = true;
		Util.m_bDayTime = true;
		if (m_iStatus == Util.NIGHT)
			Util.m_bDayTime = false;
		Util.m_iLightStatus = m_iStatus;
		if (m_eTarget != null)
			m_eTarget.Update();
	}
}
