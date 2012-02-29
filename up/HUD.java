import java.awt.*;

public class HUD {
	Sprite m_sDoodad1;
	Sprite m_sWeaponSelection;
	Sprite m_sHealth;
	Sprite m_sPointer;
	Sprite m_sCrosshair;
	Text m_tScore;
	
	Character m_cTarget;
	
	public HUD()
	{
		/*
		m_sHealth = new Sprite();
		m_cTarget = new Character();
		m_sDoodad1 = new Sprite();
		m_tScore = new Text();
		*/
	}
	
	public void Update()
	{
		if (m_cTarget == null || m_cTarget.m_iHealth <= 0)
		{
			if (m_sPointer != null)
			{
				m_sPointer.m_rcBoundingBox.x = -33;
				m_sPointer.m_rcBoundingBox.y = -33;
			}
		}
		if (m_sDoodad1 != null)
			m_sDoodad1.Update();
		if (m_sHealth != null && m_cTarget != null)
		{
			m_sHealth.Update();
			m_sHealth.PlayAnimation("0");
			int ratio = (int)(((((double) m_cTarget.m_iHealth) / ((double) m_cTarget.m_iMaxHealth))) * 100);
			
			if (ratio > 5)
				m_sHealth.PlayAnimation("10");
			if (ratio > 15)
				m_sHealth.PlayAnimation("20");
			if (ratio > 25)
				m_sHealth.PlayAnimation("30");
			if (ratio > 35)
				m_sHealth.PlayAnimation("40");
			if (ratio > 45)
				m_sHealth.PlayAnimation("50");
			if (ratio > 55)
				m_sHealth.PlayAnimation("60");
			if (ratio > 65)
				m_sHealth.PlayAnimation("70");
			if (ratio > 75)
				m_sHealth.PlayAnimation("80");
			if (ratio > 85)
				m_sHealth.PlayAnimation("90");
			if (ratio > 95)
				m_sHealth.PlayAnimation("100");
		
		}
		if (m_sCrosshair != null)
		{
			Sprite temp = new Sprite(m_sCrosshair);
			temp.m_rcBoundingBox.x += ((Character)(Util.m_alSprite.get(0))).m_pSpeed.x;
			temp.m_rcBoundingBox.y += ((Character)(Util.m_alSprite.get(0))).m_pSpeed.y;
			temp.Update();
			if (temp.CollidesWith(Util.m_rcScreen))
			{
				m_sCrosshair.m_rcBoundingBox.x += ((Character)(Util.m_alSprite.get(0))).m_pSpeed.x;
				m_sCrosshair.m_rcBoundingBox.y += ((Character)(Util.m_alSprite.get(0))).m_pSpeed.y;
				m_sCrosshair.Update();
			}
		}
		if (m_sPointer != null)
		{
			m_sPointer.m_rcBoundingBox.x = m_cTarget.m_rcBoundingBox.x;
			m_sPointer.m_rcBoundingBox.y = m_cTarget.m_rcBoundingBox.y + m_cTarget.m_rcBoundingBox.height + 3;
		}
		if (m_sWeaponSelection != null)
		{
			m_sWeaponSelection.PlayAnimation(m_cTarget.m_wWeapon.m_sName);
		}
		if (m_tScore != null && m_cTarget != null)
		{
			Integer i = new Integer(m_cTarget.m_iScore);
			//String temp = i.toString();
			//if (!(temp.equals(m_tScore.m_sText)))
				//System.out.println("Score : " + m_cTarget.m_iScore);
			i = new Integer(m_cTarget.m_iScore);
			m_tScore.m_sText = i.toString();
		}
	}
	public void Paint(Graphics g)
	{
		m_sDoodad1.Paint(g);
		m_sHealth.Paint(g);
		m_sWeaponSelection.Paint(g);
		m_sPointer.Paint(g);
		m_sCrosshair.Paint(g);
		m_tScore.Paint(g);
	}
	public void PaintAnimation(Graphics g)
	{
		if (Util.m_bInBattle)
		{
			g.setColor(Color.black);
			g.fillRoundRect(Util.m_rcScreen.x, Util.m_rcScreen.y+Util.m_rcScreen.height-100, Util.m_rcScreen.width,100,5,5);
			g.setColor(Color.white);
			g.fillRoundRect(Util.m_rcScreen.x+1, Util.m_rcScreen.y+Util.m_rcScreen.height-99, Util.m_rcScreen.width-2,98,5,5);
			g.setColor(Color.blue);
			g.fillRoundRect(Util.m_rcScreen.x+5, Util.m_rcScreen.y+Util.m_rcScreen.height-95, Util.m_rcScreen.width-10,90,5,5);
			g.setColor(Color.white);
		//	System.out.println
		}
		if (m_sDoodad1 != null)
			m_sDoodad1.PaintAnimation(g);

		if (m_sHealth != null)
			m_sHealth.PaintAnimation(g);
		
		if (m_sWeaponSelection != null)
			m_sWeaponSelection.PaintAnimation(g);
		
		if (m_sPointer != null)
			m_sPointer.PaintAnimation(g);
		
		if (m_sCrosshair != null)
			m_sCrosshair.PaintAnimation(g);
		
		if (m_tScore != null)
			m_tScore.Paint(g);
	}
}
