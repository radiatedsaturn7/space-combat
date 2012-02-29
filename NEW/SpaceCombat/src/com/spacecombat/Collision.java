package com.spacecombat;

public class Collision
{
		private GameObject me;
		private GameObject whatIHit;
		protected boolean isDestroyed = false;
		
		public Collision (GameObject me, GameObject whatIHit)
		{
			this.me = me;
			this.whatIHit = whatIHit;
		}
		
		public GameObject getMe ()
		{
			return me;
		}
		
		public GameObject getWhatIHit ()
		{
			return whatIHit;
		}
}
