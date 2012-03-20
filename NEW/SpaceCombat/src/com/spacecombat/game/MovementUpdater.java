package com.spacecombat.game;

import com.spacecombat.Component;

public class MovementUpdater extends Component {
	@Override
	public void update() {
		if (this.gameObject != null) {
			this.gameObject.transform.rotation.x += 1;
			// gameObject.transform.rotation.y+=.3;
			// gameObject.transform.rotation.z+=.4;

			this.gameObject.transform.position.x += .2;
			// gameObject.transform.position.y+=.3;
			// gameObject.transform.position.z+=.4;
		}

	}
}
