package com.spacecombat;

import java.util.LinkedList;
import java.util.List;

import com.spacecombat.game.PrefabFactory;

public class GUI {
	
	private static List<GameObject> guiElements = new LinkedList<GameObject>();	
	
	public static boolean drawImage (GenericGraphic g, int x, int y, float width, float height)
	{
		GameObject temp = GameObject.getNew();
		temp.transform.position.x = x + Camera.mainCamera.gameObject.transform.position.x; 
		temp.transform.position.y = y + Camera.mainCamera.gameObject.transform.position.y; 
		Animation a = new Animation();
		a.init("Idle", 0, 0, false,
				1, 32, 32);
		GraphicAnimation ga = new GraphicAnimation(g,a);
		temp.addComponent(ga);		
		add(temp);
		
		if (Input.xPos >= x && Input.xPos <= x + width)
		{
			if (Input.yPos >= x && Input.yPos <= y + height)
			{
				return true;
			}
		}
		return false;
	}
	

	private static GenericText genericText = new CanvasText();
	public static boolean drawText (String text, float x, float y, float width, float height)
	{
		genericText.setText(text);
		genericText.draw(x, y, 0, 0, 1, 1);

		if (Input.xPos >= x && Input.xPos <= x + width)
		{
			if (Input.yPos >= x && Input.yPos <= y + height)
			{
				return true;
			}
		}
		return false;
	} 
	
	public static void add(GameObject go)
	{
		go.onCreate();
		go.onStart();
		guiElements.add(go);
	}
		
	public static void draw()
	{
		/*
		for (int x = 0; x < guiElements.size(); x++)
		{
			TextAnimation ta = (TextAnimation)guiElements.get(x).getComponent(TextAnimation.class);			
			guiElements.get(x).draw();
		}

		for (int x = 0; x < guiElements.size(); x++)
		{
			guiElements.get(x).destroy();			
		}
		guiElements.clear();
		*/
	}
}
