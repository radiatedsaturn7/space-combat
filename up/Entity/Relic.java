public class Relic
{
	public int m_iHealth;
	public int m_iMagic;
	
	public int m_iStrength;
	public int m_iDefense;
	
	public int m_iMagicStrength;
	public int m_iMagicDefense;
	
	public int m_iSpeed;
	public int m_iEndurance;
	
	public int m_iLuck;
	public int m_iDetermination;
	
	public Relic (int h, int m, int s, int d, int ms, int md, int sp, int e, int l, int de)
	{
	 	m_iHealth = h;
	 	m_iMagic = m;
	
		m_iStrength = s;
	 	m_iDefense = d;
	
	 	m_iMagicStrength = ms;
	 	m_iMagicDefense = md;
	
	 	m_iSpeed = sp;
	 	m_iEndurance = e;
	
		m_iLuck = l;
		m_iDetermination = de;
	}
}