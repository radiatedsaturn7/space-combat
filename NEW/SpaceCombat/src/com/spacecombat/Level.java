package com.spacecombat;

import java.util.List;

public class Level extends Component 
{
	public int tileHeight;
	public int tileWidth;
	public int mapHeight;
	public int mapWidth;
	public int [][]map;
	public int [] solids;
	
	public GraphicAnimation [] wad;
	
	public int sizeX;
	public int sizeY;
	
	public void createLevel (int [] map, int mapWidth, int mapHeight, GenericGraphic image, int tileWidth, int tileHeight)
	{
		setMap(map, mapWidth, mapHeight);
		setWad(image, tileWidth, tileHeight);
		sizeX = mapWidth * tileWidth;
		sizeY = mapHeight * tileHeight;
	}

	
	public void setMap(int [] map, int mapWidth, int mapHeight)
	{		
		int x = 0;
		int y = 0;
		this.mapWidth = mapWidth;
		this.mapHeight = mapHeight;
		this.map = new int[this.mapWidth][this.mapHeight];

		System.out.println("--MAP--");//
		int i = 0;
		for (i = 0; i < map.length; i++)
		{
			if (i % this.mapWidth == 0 && i != 0)
			{
				System.out.println("   x=" + x + " y=" + y + " i=" + i);
				y++;
				x=0;
			}

			if (x < this.map.length && y < this.map[x].length)
			{
				System.out.print(map[i]);
				this.map[x][y] = map[i];
			}
			x++;
		}
		System.out.println("   x=" + x + " y=" + y + " i=" + i);
	}
	
	public void setWad(GenericGraphic image, int tileWidth, int tileHeight)
	{
		int tiles = (image.getHeight()-1)/(tileHeight+1);
		
		wad = new GraphicAnimation[tiles];
		
		for (int x = 0; x < wad.length; x++)
		{
			GraphicAnimation w = wad[x];
			Animation a = new Animation("idle",x-1,x-1,false,17,tileWidth,tileHeight);
			GraphicAnimation b = new GraphicAnimation(image,a);
			wad[x] = b;
		}
		
		this.tileHeight = tileHeight;
		this.tileWidth = tileWidth;
	}               
	
	public void draw()
	{						
		for (int x = 0; x < mapWidth; x++)
		{
			int row = 0;

			for (int y = mapHeight-1; y >= 0; y--)
			{
				wad[map[x][y]].draw();				
				row++;
			}
			
		}		
	}
}