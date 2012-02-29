package com.spacecombat;

public class Animation
{
	private String name;
	private int startFrame;
	private int endFrame;
	private boolean loop;
	private int fps;
	private int width;
	private int height;
	private int currentFrame;

	private boolean isDone;
	private int frameIncrement = 1;
	
	public Animation()
	{
		name = "NO_ANIMATION_LOADED";
		startFrame = 0;
		endFrame = 1;
		loop = true;
		fps = 17;
		width = 32;
		height = 32;
		isDone = false;
		this.frameIncrement = 1;
	}
	
	public Animation (String name, int start, int end, boolean loop, int fps, int width, int height)
	{
		this.name = name;
		this.startFrame = start;
		this.endFrame = end;
		this.loop = loop;
		this.fps = fps;
		this.width = width;
		this.height = height;
		this.isDone = false;
		this.frameIncrement = 1;
		this.currentFrame = startFrame;
	}
	
	public void setFrameIncrement(int x)
	{
		frameIncrement = x;
	}
	
	public Animation (Animation a)
	{
		name = a.name;
		startFrame = a.startFrame;
		endFrame = a.endFrame;
		loop = a.loop;
		fps = a.fps;
		width = a.width;
		height = a.height;
		currentFrame = a.currentFrame;
		isDone = a.isDone;
		frameIncrement = a.frameIncrement;
	}

	public int getStartFrame ()
	{
		return startFrame;
	}
	
	public int getEndFrame ()
	{
		return endFrame;
	}
	
	public int getFps()
	{
		return fps;
	}
	
	public int getX ()
	{
		return 1;
	}
	
	public int getY ()
	{
		return (int)(1 + (height * currentFrame) + currentFrame);
	}
	
	public int getWidth ()
	{
		return width;
	}
	
	public int getHeight ()
	{
		return height;
	}
	
	public void nextFrame ()
	{
		if (!isDone)
		{
			currentFrame+=frameIncrement;
		}
		else
		{
			return;
		}
		
		if (loop && currentFrame > endFrame )
		{
			currentFrame = startFrame;
		}
		else if (!loop && currentFrame >= endFrame)
		{
			isDone = true;
		}
	}
	
	public void restart ()
	{
		currentFrame = startFrame;
	}
	
	public int framesLeft ()
	{
		return endFrame - currentFrame;
	}
	
	public boolean isDone()
	{
		return isDone;
	}
	
	public String getName ()
	{
		return name;
	}
}