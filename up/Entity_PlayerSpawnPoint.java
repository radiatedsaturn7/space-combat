import java.awt.*;

public class Entity_PlayerSpawnPoint extends Entity
{
	public int m_iPlayerNumberToSpawnHere;
	public Entity_PlayerSpawnPoint(Entity_PlayerSpawnPoint e)
	{
		super((Entity)(e));
		m_iPlayerNumberToSpawnHere = e.m_iPlayerNumberToSpawnHere;
	}
	public Entity_PlayerSpawnPoint(int x, int y, int w, int h, Point p, int i)
	{
		super(x,y,w,h,p);
		m_iPlayerNumberToSpawnHere = i;
	}
	public void Update()
	{
		super.Update();
		for (int i = 0; i < Util.m_alSprite.size(); i++)
		{
			Sprite s = (Sprite)Util.m_alSprite.get(i);
			if (s.m_iPlayerNumber == m_iPlayerNumberToSpawnHere)
			{
				s.m_rcBoundingBox.x = m_rcBoundingBox.x;
				s.m_rcBoundingBox.y = m_rcBoundingBox.y;
				
				if ((m_iPlayerNumberToSpawnHere != 2) || (m_iPlayerNumberToSpawnHere == 2 && Util.m_iSetup[1] == 8))
				{
					Util.m_pGlobalOffset.x = -m_pGlobalOffsetPosition.x + 200;
					Util.m_pGlobalOffset.y = -m_pGlobalOffsetPosition.y + 200;
					
					if (Util.m_bOnWorldMap)
					{
						s.m_pWorldPos = new Point(m_pGlobalOffsetPosition);
						Util.m_pWorldGlobalOffset.x = -m_pGlobalOffsetPosition.x + 200;
						Util.m_pWorldGlobalOffset.y = -m_pGlobalOffsetPosition.y + 200;
					}
						
					if (Util.m_bOnTownMap)
					{
						s.m_pTownPos = new Point(m_pGlobalOffsetPosition);
						Util.m_pTownGlobalOffset.x = -m_pGlobalOffsetPosition.x + 200;
						Util.m_pTownGlobalOffset.y = -m_pGlobalOffsetPosition.y + 200;
					}
					if (Util.m_bInBattle)
					{
						s.m_pBattlePos = new Point(m_pGlobalOffsetPosition);
						Util.m_pBattleGlobalOffset.x = -m_pGlobalOffsetPosition.x + 200;
						Util.m_pBattleGlobalOffset.y = -m_pGlobalOffsetPosition.y + 200;
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
				}
			}
		}
	}
}
