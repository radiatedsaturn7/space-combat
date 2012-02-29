import java.awt.*;

public class Entity_SpawnPoint extends Entity 
{
	public Point m_pStartPosition;
	public int m_iPlayerNumberToSpawnHere;
	public Entity m_eTarget;
	
	public Entity_SpawnPoint(Entity_SpawnPoint e)
	{
		super(e.m_rcBoundingBox.x,e.m_rcBoundingBox.y,e.m_rcBoundingBox.width,e.m_rcBoundingBox.height);
		m_pStartPosition = new Point(m_pStartPosition);
		m_iPlayerNumberToSpawnHere = e.m_iPlayerNumberToSpawnHere;
	}
	public Entity_SpawnPoint(int x, int y, int w, int h, Point p, int i)
	{
		super(x,y,w,h);
		m_pStartPosition = new Point(p);
		m_iPlayerNumberToSpawnHere = i;
	}
	public void Update()
	{
		for (int i = 0; i < Util.m_alSprite.size(); i++)
		{
			Sprite s = (Sprite)Util.m_alSprite.get(i);
			if (s.m_iPlayerNumber == m_iPlayerNumberToSpawnHere)
			{
				System.out.println(Util.m_pGlobalOffset.x + " " + Util.m_pGlobalOffset.y);
				
				s.m_rcBoundingBox.x = m_rcBoundingBox.x;
				s.m_rcBoundingBox.y = m_rcBoundingBox.y;
				
				if ((m_iPlayerNumberToSpawnHere != 2) || (m_iPlayerNumberToSpawnHere == 2 && Util.m_iSetup[1] == 8))
				{
					Util.m_pGlobalOffset.x = -m_pStartPosition.x + 200;
					Util.m_pGlobalOffset.y = -m_pStartPosition.y + 200;
					
					if (Util.m_bOnWorldMap)
					{
						s.m_pWorldPos = new Point(m_pStartPosition);
						Util.m_pWorldGlobalOffset.x = -m_pStartPosition.x + 200;
						Util.m_pWorldGlobalOffset.y = -m_pStartPosition.y + 200;
					}
						
					if (Util.m_bOnTownMap)
					{
						s.m_pTownPos = new Point(m_pStartPosition);
						Util.m_pTownGlobalOffset.x = -m_pStartPosition.x + 200;
						Util.m_pTownGlobalOffset.y = -m_pStartPosition.y + 200;
					}
					if (Util.m_bInBattle)
					{
						s.m_pBattlePos = new Point(m_pStartPosition);
						Util.m_pBattleGlobalOffset.x = -m_pStartPosition.x + 200;
						Util.m_pBattleGlobalOffset.y = -m_pStartPosition.y + 200;
					}
					if (Util.m_pWorldGlobalOffset.x > 0)
						Util.m_pWorldGlobalOffset.x = 0;
					if (Util.m_pWorldGlobalOffset.y > 0)
						Util.m_pWorldGlobalOffset.y = 0;
					if (Util.m_pTownGlobalOffset.x > 0)
						Util.m_pTownGlobalOffset.x = 0;
					if (Util.m_pTownGlobalOffset.y > 0)
						Util.m_pTownGlobalOffset.y = 0;
					if (Util.m_pBattleGlobalOffset.x > 0)
						Util.m_pBattleGlobalOffset.y = 0;
					if (Util.m_pBattleGlobalOffset.y > 0)
						Util.m_pBattleGlobalOffset.y = 0;
					if (Util.m_pGlobalOffset.x > 0)
						Util.m_pGlobalOffset.y = 0;
					if (Util.m_pGlobalOffset.y > 0)
						Util.m_pGlobalOffset.y = 0;
					
					System.out.println(Util.m_pGlobalOffset.x + " " + Util.m_pGlobalOffset.y);
				}
			}
		}
	}
}
