package com.spacecombat;

public class TextAnimation extends Component 
{
	private final GenericText text;
	public TextAnimation (final GenericText text)
	{
		this.text = text;
	}

	public void setText (String s)
	{
		text.setText(s);
	}
	
	@Override
	public void draw ()
	{
		this.text.draw(
				(int) (this.gameObject.transform.position.x-Camera.mainCamera.gameObject.transform.position.x),
				(int) (this.gameObject.transform.position.y-Camera.mainCamera.gameObject.transform.position.y),
				(int) this.gameObject.transform.rotation.x,
				(int) this.gameObject.transform.rotation.y,
				(int) this.gameObject.transform.scale.x,
				(int) this.gameObject.transform.scale.y);
	}
}
