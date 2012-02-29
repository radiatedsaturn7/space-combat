public class Animation
{
	public String m_sName;
	public int m_iStartFrame;
	public int m_iEndFrame;
	public boolean m_bLoop;
	public int m_iFPS;
	
	public Animation()
	{
		m_sName = "NO_ANIMATION_LOADED";
		m_iStartFrame = 0;
		m_iEndFrame = 1;
		m_bLoop = true;
		m_iFPS = 17;
	}
	public Animation (String name, int start, int end, boolean loop, int fps)
	{
		m_sName = name;
		m_iStartFrame = start;
		m_iEndFrame = end;
		m_bLoop = loop;
		m_iFPS = fps;
	}
	
	public Animation (Animation a)
	{
		m_sName = new String(a.m_sName);
		m_iStartFrame = a.m_iStartFrame;
		m_iEndFrame = a.m_iEndFrame;
		m_bLoop = a.m_bLoop;
		m_iFPS = a.m_iFPS;
	}
}