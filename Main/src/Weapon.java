import java.awt.*;

public abstract class Weapon extends Sprite
{
	public int m_iBaseDamage;
	public int m_iPowerLevel;
	public int m_iMaxPowerLevel;
	public int m_iPowerLevel2;
	public int m_iMaxPowerLevel2;
	public Time m_tReloadTime;
	public Time m_tLastShotTime;
	public String m_sName;
	
	public Weapon(String name, int damage)
	{
		m_sName = name;
		m_iBaseDamage = damage;
		m_tLastShotTime = new Time(Util.m_tTime);
		m_iPowerLevel = 1;
		m_iMaxPowerLevel = 9;
		m_iPowerLevel2 = 0;
		m_iMaxPowerLevel2 = 9;
	}
	
	public boolean CanShoot()
	{
		if (Time.AddTime(m_tLastShotTime, m_tReloadTime).IsLessThan(Util.m_tTime))
			return true;
		return false;
	}
	
	public abstract void Shoot(Point Position, Point Speed, int Faction, Time Life);

}