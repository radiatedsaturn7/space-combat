public class Entity_LevelChange extends Entity
{
	Level m_lLevel;
	public Entity_LevelChange (Entity_LevelChange e)
	{
		super(e.m_rcBoundingBox.x,e.m_rcBoundingBox.y,e.m_rcBoundingBox.width,e.m_rcBoundingBox.height);
	}
	
	public Entity_LevelChange (int x, int y, int w, int h, Level l)
	{
		super(x,y,w,h);
		m_lLevel = new Level(l);
	}
	
	public void Update(Sprite S)
	{
		if (!S.m_bIsPlayer)
			return;
	//	System.out.println("Level Changed");
		Util.m_lCurrentLevel = new Level(m_lLevel);
		super.Update(S);
	}
}
