package com.spacecombat;

public class GraphicAnimation extends Component 
{
	private GenericGraphic graphic;
	private Animation animation;
	private float lastDraw = 0;
	
	public GraphicAnimation (GenericGraphic graphic, Animation animation)
	{
		this.graphic = graphic;
		this.animation = animation;
		setEnabled(false);
	}
	
	public float getDuration ()
	{
		
		return (1.0f / (float)animation.getFps()) * (float)(animation.getEndFrame() - animation.getStartFrame());
	}
	
	public void play()
	{
		setEnabled(true);
	}
	
	public boolean isDone ()
	{
		return animation.isDone();
	}//
	
	public void draw ()
	{
		graphic.draw(animation.getX(), animation.getY(), animation.getWidth(), animation.getHeight(),(int)gameObject.transform.position.x,(int)gameObject.transform.position.y,(int)gameObject.transform.rotation.x,(int)gameObject.transform.rotation.y,(int)gameObject.transform.scale.x,(int)gameObject.transform.scale.y);		
		
		if (Time.getTime() - lastDraw > (1.0/(float)animation.getFps()))
		{
			lastDraw = Time.getTime();
			animation.nextFrame();
		}
	}
	
	public String getName ()
	{
		return animation.getName();
	}
}
