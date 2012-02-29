import java.awt.*;

public class HUD {
	Sprite m_sDoodad1;
	Sprite m_sWeaponSelection;
	Sprite m_sHealth;
	Character m_cTarget;
	
	public HUD()
	{
		m_sHealth = new Sprite();
		m_cTarget = new Character();
		m_sDoodad1 = new Sprite();
	}
	
	public void Update()
	{
		m_sDoodad1.Update();
		m_sHealth.Update();
		m_sHealth.PlayAnimation("0");
		if (m_cTarget.m_iHealth > 5)
			m_sHealth.PlayAnimation("10");
		if (m_cTarget.m_iHealth > 15)
			m_sHealth.PlayAnimation("20");
		if (m_cTarget.m_iHealth > 25)
			m_sHealth.PlayAnimation("30");
		if (m_cTarget.m_iHealth > 35)
			m_sHealth.PlayAnimation("40");
		if (m_cTarget.m_iHealth > 45)
			m_sHealth.PlayAnimation("50");
		if (m_cTarget.m_iHealth > 55)
			m_sHealth.PlayAnimation("60");
		if (m_cTarget.m_iHealth > 65)
			m_sHealth.PlayAnimation("70");
		if (m_cTarget.m_iHealth > 75)
			m_sHealth.PlayAnimation("80");
		if (m_cTarget.m_iHealth > 85)
			m_sHealth.PlayAnimation("90");
		if (m_cTarget.m_iHealth > 95)
			m_sHealth.PlayAnimation("100");
		m_sWeaponSelection.PlayAnimation(m_cTarget.m_wWeapon.m_sName);
	}
	public void Paint(Graphics g)
	{
		m_sDoodad1.PaintAnimation(g);
		m_sHealth.PaintAnimation(g);
		m_sWeaponSelection.PaintAnimation(g);
	}
	public void PaintAnimation(Graphics g)
	{
		if (m_sDoodad1 != null)
			m_sDoodad1.PaintAnimation(g);

		if (m_sHealth != null)
			m_sHealth.PaintAnimation(g);
		
		if (m_sWeaponSelection != null)
			m_sWeaponSelection.PaintAnimation(g);
	}
}
