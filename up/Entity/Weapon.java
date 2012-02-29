import java.awt.*;

public abstract class Weapon extends Sprite
{
	public int m_iBaseDamage;
	public int m_iMissileBaseDamage;
	public int m_iPowerLevel;
	public int m_iMaxPowerLevel;
	public int m_iPowerLevel2;
	public int m_iMaxPowerLevel2;
	public int m_iOwner;
	public Time m_tReloadTime;
	public Time m_tLastShotTime;
	public Time m_tMissileLastShotTime;
	public Time m_tMissileReloadTime;
	public String m_sName;
	
	public Weapon(String name, int damage, int damage2, int owner)
	{
		m_sName = name;
		m_iBaseDamage = damage;
		m_iMissileBaseDamage = damage2;
		m_tLastShotTime = new Time(Util.m_tTime);
		m_iPowerLevel = 1;
		m_iMaxPowerLevel = 9;
		m_iPowerLevel2 = 0;
		m_iMaxPowerLevel2 = 9;
		m_tMissileLastShotTime = new Time();
		m_tMissileReloadTime = new Time();
		m_iOwner = owner;
	}
	
	public boolean CanShoot()
	{
		if (Time.AddTime(m_tLastShotTime, m_tReloadTime).IsLessThan(Util.m_tTime))
			return true;
		return false;
	}
	public boolean CanShootMissile()
	{
		if (Time.AddTime(m_tMissileLastShotTime, m_tMissileReloadTime).IsLessThan(Util.m_tTime))
			return true;
		return false;
	}
		
	public abstract void Shoot(Point Position, Point Speed, int Faction, Time Life);
	public abstract void ShootMissile(Point Position, Point Speed, int Faction, Time Life);

}