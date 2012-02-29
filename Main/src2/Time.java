public class Time
{
	public int m_iMilliseconds;
	public int m_iSeconds;
	public int m_iMinutes;
	public int m_iHours;
	public int m_iDays;
	public int m_iYears;
	
	public Time ()
	{
	}
	public Time (Time t)
	{
		m_iMilliseconds=t.m_iMilliseconds;
		m_iSeconds=t.m_iSeconds;
		m_iMinutes=t.m_iMinutes;
		m_iHours=t.m_iHours;
		m_iDays=t.m_iDays;
		m_iYears=t.m_iYears;
	}
	public boolean IsGreaterThan (Time t)
	{
		t.Update();
		Update();
		//System.out.println(">>" + this + " > " + t);
		
		if (m_iYears > t.m_iYears)
			return true;
		else if (m_iYears < t.m_iYears)
			return false;
		if (m_iDays > t.m_iDays)
			return true;
		else if (m_iDays < t.m_iDays)
			return false;
		if (m_iHours > t.m_iHours)
			return true;
		else if (m_iHours < t.m_iHours)
			return false;
		if (m_iMinutes > t.m_iMinutes)
			return true;
		else if (m_iMinutes < t.m_iMinutes)
			return false;
		if (m_iSeconds > t.m_iSeconds)
			return true;
		else if (m_iSeconds < t.m_iSeconds)
			return false;
		if (m_iMilliseconds > t.m_iMilliseconds)
			return true;
		else if (m_iMilliseconds < t.m_iMilliseconds)
			return false;
		return false;
	}
	public boolean IsLessThan (Time t)
	{
		t.Update();
		Update();
		
		if (m_iYears < t.m_iYears)
			return true;
		else if (m_iYears > t.m_iYears)
			return false;
		if (m_iDays < t.m_iDays)
			return true;
		else if (m_iDays > t.m_iDays)
			return false;
		if (m_iHours < t.m_iHours)
			return true;
		else if (m_iHours > t.m_iHours)
			return false;
		if (m_iMinutes < t.m_iMinutes)
			return true;
		else if (m_iMinutes > t.m_iMinutes)
			return false;
		if (m_iSeconds < t.m_iSeconds)
			return true;
		else if (m_iSeconds > t.m_iSeconds)
			return false;
		if (m_iMilliseconds < t.m_iMilliseconds)
			return true;
		else if (m_iMilliseconds > t.m_iMilliseconds)
			return false;
		return false;
	}
	public boolean IsEqualTo (Time t)
	{
		t.Update();
		Update();
		
		if (m_iYears == t.m_iYears)
			return true;
		if (m_iDays == t.m_iDays)
			return true;
		if (m_iHours == t.m_iHours)
			return true;
		if (m_iMinutes == t.m_iMinutes)
			return true;
		if (m_iSeconds == t.m_iSeconds)
			return true;
		if (m_iMilliseconds == t.m_iMilliseconds)
			return true;
		return false;
	}

	public void AddMilliseconds(int i)
	{
		m_iMilliseconds+=i;
		Update();
	}
	public void AddSeconds(int i)
	{
		m_iSeconds+=i;
		Update();
	}
	public void AddMinutes(int i)
	{
		m_iMinutes+=i;
		Update();
	}
	public void AddHours(int i)
	{
		m_iHours+=i;
		Update();
	}
	public void AddDays(int i)
	{
		m_iDays+=i;
		Update();
	}
	public void AddYears(int i)
	{
		m_iYears+=i;
	}
	public void Update()
	{
		while (m_iMilliseconds >= 1000)
		{
			m_iSeconds++;
			m_iMilliseconds-=1000;
		}
		while (m_iSeconds >= 60)
		{
			m_iMinutes++;
			m_iSeconds-=60;
		}
		while (m_iMinutes >= 60)
		{
			m_iHours++;
			m_iMinutes-=60;
		}
		while (m_iHours >= 24)
		{
			m_iDays++;
			m_iHours-=24;
		}
		while (m_iDays >= 365)
		{
			m_iYears++;
			m_iDays-=365;
		}
	}
	public String toString()
	{
		String s = new String();
		s+= m_iYears + "y " + m_iDays + "d " + m_iHours + ":" + m_iMinutes + ":" + m_iSeconds + "." + m_iMilliseconds;
		return s;
	}
}