public class Weapon extends Sprite
{
	public int m_iBaseDamage;
	public int m_iBaseSpeed;
	public int m_iCost;
	public String m_sName;
	
	public Weapon(String name, int damage, int speed, int cost)
	{
		m_sName = name;
		m_iBaseDamage = damage;
		m_iBaseSpeed = speed;
		m_iCost = cost;
	}
}