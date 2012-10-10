package com.spacecombat;

public class FixedJoint extends Component {
	private final GameObject attachedTo;
	private final Vector2 lastPosition;

	public FixedJoint (final GameObject thisIsAttachedTo)
	{
		this.attachedTo = thisIsAttachedTo;
		this.lastPosition = new Vector2(this.attachedTo.transform.position.x,this.attachedTo.transform.position.y);
	}	

	@Override
	public void onAfterUpdate()
	{
		if (this.attachedTo == null) {
			return;
		}

		if (!this.attachedTo.transform.position.equals(this.lastPosition))
		{
			final float xDiff = this.lastPosition.x - this.attachedTo.transform.position.x;
			final float yDiff = this.lastPosition.y - this.attachedTo.transform.position.y;

			this.gameObject.transform.position.x -= xDiff;
			this.gameObject.transform.position.y -= yDiff;

			this.lastPosition.x = this.attachedTo.transform.position.x;
			this.lastPosition.y = this.attachedTo.transform.position.y;
		}	
	}
}
