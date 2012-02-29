import java.awt.*;

public class PowerUp extends Sprite 
{
	public int m_iType;
	public PowerUp(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super(Pos, Size, image, frame, solid, applygravity);
		m_iFaction = 100;
		m_iType = 0;
	}
	public void Update()
	{
		super.Update();
		if (m_rcBoundingBox.y > Util.m_rcScreen.y + Util.m_rcScreen.height)
			m_bDelete = true;
		if (m_rcBoundingBox.y + m_rcBoundingBox.height < Util.m_rcScreen.y)
			m_bDelete = true;
		//HACK something wrong with a script...this will temp fix it
		if (m_rcBoundingBox.x + m_rcBoundingBox.width < Util.m_rcScreen.x)
			m_bDelete = true;
		if (m_rcBoundingBox.x > Util.m_rcScreen.x + Util.m_rcScreen.width)
			m_bDelete = true;
	}
	public void CollideWith (Sprite S)
	{
		if (S instanceof Character)
		{
			if ((((Character)(S)).m_bIsPlayer || S instanceof AllyShip) && ((Character)(S)).m_wWeapon.m_iPowerLevel < ((Character)(S)).m_wWeapon.m_iMaxPowerLevel)
			{
				if (m_iType == 0)
					((Character)(S)).m_wWeapon.m_iPowerLevel++;
				if (m_iType == 1)
					((Character)(S)).m_iHealth = 100;
				m_bDelete = true;
			}
		}
	}
}
