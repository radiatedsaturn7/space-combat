package com.spacecombat;

import com.spacecombat.game.SimpleMovement;

public class Animation implements Poolable {
	
	private static Pool animationPool;
	
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
	
	public static Animation getNew ()
	{
		return (Animation)animationPool.retreive();
	}

	public Animation() {
		this.name = "NO_ANIMATION_LOADED";
		this.startFrame = 0;
		this.endFrame = 1;
		this.loop = true;
		this.fps = 17;
		this.width = 32;
		this.height = 32;
		this.isDone = false;
		this.frameIncrement = 1;
	}

	public Animation(final Animation a) {
		this.name = a.name;
		this.startFrame = a.startFrame;
		this.endFrame = a.endFrame;
		this.loop = a.loop;
		this.fps = a.fps;
		this.width = a.width;
		this.height = a.height;
		this.currentFrame = a.currentFrame;
		this.isDone = a.isDone;
		this.frameIncrement = a.frameIncrement;
	}

	public void init (String name, int start, int end,
			boolean loop, int fps, int width, int height) {
		this.name = name;
		this.startFrame = start;
		this.endFrame = end;
		this.loop = loop;
		this.fps = fps;
		this.width = width;
		this.height = height;
		this.isDone = false;
		this.frameIncrement = 1;
		this.currentFrame = this.startFrame;
	}

	public int framesLeft() {
		return this.endFrame - this.currentFrame;
	}

	public int getEndFrame() {
		return this.endFrame;
	}

	public int getFps() {
		return this.fps;
	}

	public int getHeight() {
		return this.height;
	}

	public String getName() {
		return this.name;
	}

	public int getStartFrame() {
		return this.startFrame;
	}

	public int getWidth() {
		return this.width;
	}

	public int getX() {
		return 1;
	}

	public int getY() {
		return (1 + (this.height * this.currentFrame) + this.currentFrame);
	}

	public boolean isDone() {
		return this.isDone;
	}

	public void nextFrame() {
		if (!this.isDone) {
			this.currentFrame += this.frameIncrement;
		} else {
			return;
		}

		if (this.loop && this.currentFrame > this.endFrame) {
			this.currentFrame = this.startFrame;
		} else if (!this.loop && this.currentFrame >= this.endFrame) {
			this.isDone = true;
		}
	}

	public void restart() {
		this.currentFrame = this.startFrame;
	}

	public void setFrameIncrement(final int x) {
		this.frameIncrement = x;
	}

	@Override
	public void clean() {
		this.name = "NO_ANIMATION_LOADED";
		this.startFrame = 0;
		this.endFrame = 1;
		this.loop = true;
		this.fps = 17;
		this.width = 32;
		this.height = 32;
		this.isDone = false;
		this.frameIncrement = 1;
	}

	private int poolId;
	@Override	
	public int getPoolId() {
		return poolId;
	}

	@Override
	public void setPoolId(int id) {
		poolId = id;
	}
	//
	public void onBeforeDestroy ()
	{
		Animation.animationPool.release(this);
	}
	
	static
	{
		animationPool = new Pool();
		animationPool.init(Animation.class, 100);
	}
}