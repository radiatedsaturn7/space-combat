package com.spacecombat;

public class RigidBody extends Component {
	public Vector2 speed = new Vector2(0, 0);
	public Collider collider = null;

	public Collider getCollider() {
		return this.collider;
	}

	public void setCollider(final Collider collider) {
		this.collider = collider;
		collider.setRigidBody(this);
	}

	@Override
	public String toString() {
		final StringBuffer s = new StringBuffer();
		//
		if (this.gameObject != null) {
			s.append("RigidBody.position=");
			s.append(this.gameObject.transform.position);
			s.append("\n");
		}

		s.append("RigidBody.speed=");
		s.append(this.speed.toString());
		s.append("\n");
		return s.toString();
	}

	@Override
	public void update() {
		// System.out.println(speed + " * " + Time.getDeltaTime());
		this.gameObject.transform.position.x += (this.speed.x * Time
				.getDeltaTime());
		this.gameObject.transform.position.y += (this.speed.y * Time
				.getDeltaTime());
	}
}
