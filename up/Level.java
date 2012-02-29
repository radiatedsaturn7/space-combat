import java.awt.*;
import java.util.*;

public class Level {
	
	public int m_iTileHeight;
	public int m_iTileWidth;
	public int m_iMapHeight;
	public int m_iMapWidth;
	public int [][]m_iMap;
	public int [] m_iSolid;
	public Sprite m_sWad;
	public ArrayList m_alEntities;
	public ArrayList m_alNodeGraph;
	
	public int m_iSizeX;
	public int m_iSizeY;
	
	public Level (Level L)
	{
		m_iTileHeight = L.m_iTileHeight;
		m_iTileWidth = L.m_iTileWidth;
		m_iMapHeight = L.m_iMapHeight;
		m_iMapWidth = L.m_iMapWidth;
		m_iMap = new int[L.m_iMap.length][L.m_iMap[0].length];
		m_iSolid = new int[L.m_iSolid.length];
		for (int x = 0; x < L.m_iMap.length; x++)
			for (int y = 0; y < L.m_iMap[x].length; y++)
				m_iMap[x][y] = L.m_iMap[x][y];
		for (int x = 0; x < L.m_iSolid.length; x++)
			m_iSolid[x] = L.m_iSolid[x];
		m_sWad = new Sprite(L.m_sWad);
		m_iSizeX = L.m_iSizeX;
		m_iSizeY = L.m_iSizeY;
		if (L.m_alEntities != null)
		{
			m_alEntities = new ArrayList();
			for (int x = 0; x < L.m_alEntities.size(); x++)
			{
				m_alEntities.add(((Entity)(L.m_alEntities.get(x))));
			}
		}
	}
	public Level (int [] map, int mapwidth, int mapheight, Sprite wad, int tilewidth, int tileheight)
	{
		SetMap (map, mapwidth, mapheight);
		SetWad (wad, tilewidth, tileheight);
		m_iSizeX = m_iMapWidth * m_iTileWidth;
		m_iSizeY = m_iMapHeight * m_iTileHeight;
	}
	
	public void SetEntities(ArrayList al)
	{
		m_alEntities = new ArrayList();
		for (int x = 0; x < al.size(); x++)
		{
		//	System.out.println("ADDED");
			m_alEntities.add(((Entity)(al.get(x))));
		}
	}
	
	public void SetMap(int [] map, int mapwidth, int mapheight)
	{
		m_iMap = new int[mapwidth][mapheight];
		int x = 0;
		int y = 0;
		m_iMapWidth = mapwidth;
		m_iMapHeight = mapheight;
		for (int i = 0; i < map.length; i++)
		{
			if (i % m_iMapWidth == 0 && i != 0)
			{
				y++;
				x=0;
			}
		//	System.out.println("["+x+"]["+y+"] = "+map[i]);
			if (x < m_iMap.length && y < m_iMap[x].length && i < map.length)
			{
				m_iMap[x][y] = map[i];
			}
			x++;
		}
	}
	
	public void SetWad(Sprite wad, int tileheight, int tilewidth)
	{
		m_sWad = new Sprite(wad);
		m_iTileHeight = tileheight;
		m_iTileWidth = tilewidth;
	}               
	public void AddImageToWad(Image i)
	{
		m_sWad.AddImage(i);	
	}
	public void SetWadFromImage(int i)
	{
		m_sWad.SetImage(i);
	}
	public void CollideWith (Sprite S)
	{
		
	//	System.out.println(S.speed.x + " " + S.speed.y);
		if (S.m_bIsSolid)
		{
			S.m_pSpeed.x = (int)(S.m_pSpeed.x/2);
			S.m_pSpeed.y = (int)(S.m_pSpeed.y/2);
		}
		if (S instanceof Shot)
		{
			//System.out.println("Level.java : SHOT COLLISION");
			S.m_bDelete = true;
		}
	//	System.out.println(S.speed.x + " " + S.speed.y);
		
	//	if (CollidesWith(S, true, false))
	//		S.speed.x = 0;
	//	if (CollidesWith(S, false, true))
	//		S.speed.y = 0;
		if (S instanceof Monster)
		{
		//	System.out.println("Level.Java : Collision with Monster");
		}
			
	}

	
	public boolean IsColliding (Rectangle S)
	{
		for (int x = 0; x < m_iMap.length; x++)
			for (int y = 0; y < m_iMap[x].length; y++)
			{
				if (IsSolid(m_iMap[x][y]))
				{
				//	System.out.println(m_iMap[x][y]);
					Rectangle r = new Rectangle();
					r.x = x*m_iTileWidth + Util.m_pGlobalOffset.x;
					r.y = y*m_iTileHeight + Util.m_pGlobalOffset.y;
					r.width = m_iTileWidth;
					r.height = m_iTileHeight;
	
					Rectangle q = new Rectangle(S);
					
					//players are tall, so only judge if they are hitting the
					// according to their feet
					/*
					q.y = R.m_rcBoundingBox.y;
					q.x = R.m_rcBoundingBox.x;
					q.width = R.m_rcBoundingBox.width;
					q.height = R.m_rcBoundingBox.height;
					*/

					if (r.intersects(q))
					{
						return true;
					}
				}
			}
		return false;
	}
	/*
	public boolean CollidesWith (Sprite S, boolean onx, boolean ony)
	{
		int tempx = S.speed.x;
		int tempy = S.speed.y;
		if (onx)
			S.speed.y = 0;
		if (ony)
			S.speed.x = 0;
		
		for (int x = 0; x < m_iMap.length; x++)
			for (int y = 0; y < m_iMap[x].length; y++)
			{
				if (IsSolid(m_iMap[x][y]))
				{
				//	System.out.println(m_iMap[x][y]);
					Rectangle r = new Rectangle();
					r.x = x*m_iTileWidth + Util.m_pGlobalOffset.x;
					r.y = y*m_iTileHeight + Util.m_pGlobalOffset.y;
					r.width = m_iTileWidth;
					r.height = m_iTileHeight;
	
					Rectangle q = new Rectangle(S.m_rcBoundingBox);
					
					//players are tall, so only judge if they are hitting the
					// according to their feet
					q.y = S.m_rcBoundingBox.y;
					q.x = S.m_rcBoundingBox.x;
					q.width = S.m_rcBoundingBox.width;
					q.height = S.m_rcBoundingBox.height;

					if (r.intersects(q))
					{
						//System.out.println(m_iMap[x][y]);
						S.speed.x = tempx;
						S.speed.y = tempy;
						return true;
					}
				}
			}
		S.speed.x = tempx;
		S.speed.y = tempy;
		return false;
	}
	*/
	
	public void SetSolids(int [] solid)
	{
		m_iSolid = new int[solid.length];
		for (int x = 0; x < solid.length; x++)
		{
			//System.out.println(solid[x]);
			m_iSolid[x] = solid[x];
		}
	}
	
	private boolean IsSolid (int a)
	{
		for (int x = 0; x < m_iSolid.length; x++)
			if (a == m_iSolid[x])
				return true;
		return false;
	}
	
	public void Paint(Graphics g)
	{
		
		Sprite Temp = new Sprite(m_sWad);

		
		for (int x = 0; x < m_iMapWidth; x++)
		{
			for (int y = 0; y < m_iMapHeight; y++)
			{
		//		System.out.print("paintingLEVEL");
				Temp.SetPosition(x*m_iTileWidth + Util.m_pGlobalOffset.x, y*m_iTileHeight + Util.m_pGlobalOffset.y);
				Temp.m_iFrame=(m_iMap[x][y]);
			//	boolean b = (x>=8);
			//	boolean c = (y==1);
		//		System.out.print(Temp.m_iFrame);
				if ( Temp.CollidesWith(Util.m_rcScreen) )
					Temp.Paint(g);
			}
		//	System.out.println();
		}
	//	System.out.println();
		
	}
	public void GenerateNodeGraph()
	{
		/*
		//place nodes on the ground
		for (int x = 0; x < m_iMapWidth; x++)
		{
			for (int y = 0; y < m_iMapHeight; y++)
			{
				if (IsSolid(m_iMap[x][y]) && y > 1)
				{
					if ((!IsSolid(m_iMap[x][y-1])) && (!IsSolid(m_iMap[x][y-2])))
					{
						Node n = new Node(x*m_iTileWidth,y*m_iTileHeight,m_iTileWidth,m_iTileHeight);
						m_alNodeGraph.add(n);
					}
				}
			}
		}
		for (int a = 0; a < m_alNodeGraph.size(); a++)
		{
			for (int b = 0; b < m_alNodeGraph.size(); b++)
			{
				Node n1 = (Node)(m_alNodeGraph.get(a));
				Node n2 = (Node)(m_alNodeGraph.get(b));
				Rectangle R = new Rectangle();
				if (b == a)
					continue;
				if (R.intersects(n2.m_rcNode))
				{
				}
			}
		}
		//place jumping nodes
		//if node is above ground node and in range
		
		//place crawling nodes
		//if node is on ground and too short
		
		//link the nodes together
		 */
	}
	public static void AddStar ()
	{
	//	System.out.println("STAR ADDED");
		int x = Util.RandomNumber(Util.m_rcScreen.x+2,Util.m_rcScreen.width-2);
		
		Sprite m2 = new Sprite(new Point(x,3), new Point(3,3), Util.m_imParticleImage ,1, false, false);
		m2.AddImage(Util.m_imParticleImageNV);
		m2.SetImage(Util.m_iVision);
		m2.m_tDeathTime = new Time(Util.m_tTime);
		
		int type = Util.RandomNumber(1,9);
		
		m2.m_tDeathTime.AddSeconds(type+3);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", type,type,true,12);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		m2.PlayAnimation("DIE");
		m2.m_pSpeed.x = 0;
		m2.m_pSpeed.y = 19-type;
		Util.m_alSprite.add(m2);
	}
}
