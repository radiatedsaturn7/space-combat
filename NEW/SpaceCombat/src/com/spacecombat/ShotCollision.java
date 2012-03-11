package com.spacecombat;

public class ShotCollision extends Component {
	public float damage = 1;

	@Override
	public void collide(final Collision collision) {
		if (collision.getWhatIHit() == null) {
			// System.out.println("Something Wrong");
		} else {
			// System.out.println("Shot hit " + whatIHit.getName() );
		}

		if (collision.getWhatIHit().hasTag("shot")) {
			return;
		}

		if (!(collision.getWhatIHit().hasTag(collision.getMe().getTags()))) {
			collision.getMe().destroy();
		}
	}

	public float getDamage() {
		return this.damage;
	}

	public void setDamage(final float damage) {
		this.damage = damage;
	}
}
