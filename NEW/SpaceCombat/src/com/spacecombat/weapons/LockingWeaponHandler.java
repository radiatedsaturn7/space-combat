package com.spacecombat.weapons;

import java.util.LinkedList;
import java.util.List;

import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Tags;
import com.spacecombat.Time;
import com.spacecombat.Util;
import com.spacecombat.Vector2;

public class LockingWeaponHandler extends Component {
	private final Weapon w;
	private GameObject go = null;
	private final Vector2 defaultDirection;
	private final Vector2 temp;
	private int targets = 0;
	private final float searchTime = 2.0f;
	private float nextSearch = 0.0f;
	private List<GameObject> gos;
	private boolean autoShoot = false;
	private final int nonTargets = Tags.shot | Tags.camera;

	public LockingWeaponHandler(final Weapon w, final int targets, final boolean autoShoot) {
		this.gos = new LinkedList<GameObject>();
		this.w = w;
		final Vector2 t = new Vector2(w.getShotDirection());
		this.defaultDirection = t;
		this.targets = targets;
		this.temp = new Vector2();
		this.autoShoot = autoShoot;
	}

	public void calculateTrajectory() {
		this.temp.x = (this.go.transform.position.x - (this.gameObject.transform.position.x + w.getOffset().x));
		this.temp.y = (this.go.transform.position.y - (this.gameObject.transform.position.y + w.getOffset().y));

		this.temp.x -= this.gameObject.getRigidBody().speed.x;
		this.temp.y -= this.gameObject.getRigidBody().speed.y;

		this.w.setShootDirection(this.temp);
	}

	public boolean canSearch() {
		return (Time.getTime() > this.nextSearch);
	}

	public void search() {
		this.nextSearch = Time.getTime() + this.searchTime;

		this.gos = GameObject.findAllByTags(this.targets, this.nonTargets, this.gos);

		if (this.gos == null || this.gos.size() == 0) {
			this.w.setShootDirection(this.defaultDirection);
			this.go = null;
			return;
		}

		final int x = Util.randomNumber(0, this.gos.size() - 1);

		this.go = this.gos.get(x);
	}

	@Override
	public void update() {
		
		if (canSearch()) {
			search();
			if (this.go == null) {
				this.w.setShootDirection(this.defaultDirection);
			}
		}

		if (this.go != null) {
			calculateTrajectory();
		}

		if (this.autoShoot && this.w != null && this.w.canShoot()) {
			this.w.shoot();
		}
	}
}