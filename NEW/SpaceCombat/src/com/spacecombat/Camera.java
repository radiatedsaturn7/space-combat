package com.spacecombat;

public class Camera extends Component {
	public static Camera mainCamera = null;
		
	public static void setMainCamera (final Camera c)
	{
		Camera.mainCamera = c;
	}
}
