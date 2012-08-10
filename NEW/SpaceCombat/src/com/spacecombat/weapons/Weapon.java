package com.spacecombat.weapons;

import com.spacecombat.Audio;
import com.spacecombat.Component;
import com.spacecombat.Time;
import com.spacecombat.Util;
import com.spacecombat.Vector2;

public abstract class Weapon extends Component {
	protected float baseDamage;
	protected int powerLevel;
	protected int maxPowerLevel;
	protected float reloadTime;
	protected float nextShotTime;
	protected String name;
	protected float shotSpeed;
	protected float life;
	protected Vector2 shotSpeedVector;
	protected float accuracy;
	protected boolean usePhysics = false;
	protected int magazineSize;
	protected int shots;
	protected float magazineReloadTime;
	protected String [] tags = null;
	protected boolean useMagazine = true;
	private final Vector2 shotPosition;
	protected int powerUpType = -1;
	private Audio audio;

	public Weapon(final String name, final float damage, final float accuracy,
			final float reloadTime, final int magazineSize,
			final float magazineReloadTime, final float life,
			final float shotSpeed, final Vector2 shootDirection,
			final boolean usePhysics, final int powerUpType) {
		this.name = name;
		this.baseDamage = damage;
		this.nextShotTime = 0;
		this.powerLevel = 1;
		this.maxPowerLevel = 9;
		this.reloadTime = reloadTime;
		this.accuracy = accuracy;
		this.shotSpeed = shotSpeed;
		this.life = life;
		this.usePhysics = usePhysics;
		this.shots = 0;
		this.magazineSize = magazineSize;
		this.magazineReloadTime = magazineReloadTime;
		this.powerUpType = powerUpType;
		this.shotPosition = new Vector2(0.0f,0.0f);		

		setShootDirection(shootDirection);
	}

	public boolean canShoot() {				
		if (Time.getTime() > this.nextShotTime && powerLevel >= 1) {
			return true;
		}
		return false;
	}

	protected abstract boolean fire(Vector2 position);

	public Vector2 getShotDirection() {
		return this.shotSpeedVector;
	}

	public void powerUp() {
		this.powerLevel++;
	}

	public void setShootDirection(final Vector2 v) {
		v.normalize();

		if (this.shotSpeedVector == null) {
			this.shotSpeedVector = new Vector2();
		}

		this.shotSpeedVector.x = v.x * this.shotSpeed;
		this.shotSpeedVector.y = v.y * this.shotSpeed;
	}

	public void setUseMagazine (final boolean use)
	{
		this.useMagazine = use;
	}

	public void shoot() {

		if (!canShoot()) {
			return;
		}	

		if (this.tags == null)
		{
			this.tags = this.gameObject.getTags().clone();
			final String [] temp = new String [this.tags.length+2];

			for (int x = 0; x < this.tags.length; x++)
			{
				temp[x] = this.tags[x];				
			}
			temp[temp.length-1] = "shot";
			temp[temp.length-2] = "node";
		}

		this.shots++;

		if (this.shots > this.magazineSize) {
			if (this.useMagazine)
			{
				this.nextShotTime = Time.getTime() + this.magazineReloadTime;
			}
			else
			{
				this.nextShotTime = Time.getTime() + this.reloadTime;
			}
			this.shots = 0;
		} else {
			this.nextShotTime = Time.getTime() + this.reloadTime;
		}

		if (this.usePhysics && this.gameObject.getRigidBody() != null) {
			this.shotSpeedVector.x += this.gameObject.getRigidBody().speed.x;
			this.shotSpeedVector.y += this.gameObject.getRigidBody().speed.y;
		}

		float randomX = Util.randomNumber(0, this.accuracy);
		float randomY = Util.randomNumber(0, this.accuracy);

		final int upDown = Util.randomNumber(0, 1);
		final int leftRight = Util.randomNumber(0, 1);

		if (upDown == 1) {
			randomY = -randomY;
		}
		if (leftRight == 1) {
			randomX = -randomX;
		}

		this.shotSpeedVector.x += randomX;
		this.shotSpeedVector.y += randomY;

		this.shotPosition.x = this.gameObject.transform.position.x;
		this.shotPosition.y = this.gameObject.transform.position.y;
		
		if (fire(this.shotPosition))
		{
			if (audio != null)
			{
				audio.playOnce();
			}			
		}

		this.shotSpeedVector.x -= randomX;
		this.shotSpeedVector.y -= randomY;

		if (this.usePhysics && this.gameObject.getRigidBody() != null) {
			this.shotSpeedVector.x -= this.gameObject.getRigidBody().speed.x;
			this.shotSpeedVector.y -= this.gameObject.getRigidBody().speed.y;
		}
	}
	
	public int getPowerUpType ()
	{
		return powerUpType;
	}
	
	public void setPowerLevel (int pl)
	{
		powerLevel = pl;
	}

	public void addAudio(Audio sound) {
		audio = sound;
	}
	
	public void destroy ()
	{
		if (audio != null)
		{
			audio.destroy();
		}
	}
}
