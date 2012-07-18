package com.spacecombat;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class GameObject extends Component implements Poolable {

	private static List<GameObject> gameObjects = new ArrayList<GameObject>();
	private static Vector2 distances = new Vector2();

	private static Pool gameObjectsPool;

	static {
		GameObject.gameObjectsPool = new Pool();
		GameObject.gameObjectsPool.init(GameObject.class,100);
	}
	
	public static GameObject findByName(final String search) {
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX);
			if (GameObject.staticXGameObject.getName().equals(search)) {
				return GameObject.staticXGameObject;
			}
		}
		return null;
	}
	public static GameObject findRandomByTags(final String[] search) {

		final LinkedList<GameObject> gos = new LinkedList<GameObject>();		
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX);
			if (GameObject.staticXGameObject.hasTag(search)) {
				gos.add(GameObject.staticXGameObject);
			}
		}
		if (gos.size() == 0) {
			return null;
		}
		return gos.get(Util.randomNumber(0, gos.size() - 1));
	}

	public static List<GameObject> getAllGameObjects() {
		return GameObject.gameObjects;
	}
	public static Vector2 getDistances() {
		return GameObject.distances;
	}

	public static GameObject getNew ()
	{
		return (GameObject)GameObject.gameObjectsPool.retreive();
	}

	private boolean destroyOnLevelLoad = true;

	private static GameObject staticXGameObject;

	private GameObject XGameObject;

	private Component xComponent;

	private int id = 0;

	private static int nextId = 0;
	
	public static GameObject create(final GameObject gameObject) {

		//HACKY CODE
		//technically something could have multiple graphics here
		//but we assume one... this will get tricky if we do this with layers
		//this would be very complicated to fix, would need seperate rendering engine
		final GraphicAnimation g = (GraphicAnimation) gameObject.getComponent(GraphicAnimation.class);

		//ordering graphics into layers
		boolean added = false;
		if (g != null)
		{
			GraphicAnimation g2;
			for (int x = 0; x < GameObject.gameObjects.size(); x++)
			{
				g2 = (GraphicAnimation)(GameObject.gameObjects.get(x)).getComponent(GraphicAnimation.class);
				if (g2 != null && g2.getLayer() > g.getLayer())
				{			
					GameObject.gameObjects.add(x,gameObject);
					added = true;
					break;
				}
			}
		}

		final Level l = (Level)gameObject.getComponent(Level.class);
		if (!added && l != null)
		{
			GameObject.gameObjects.add(0,gameObject);
			added = true;
		}

		if (!added)
		{
			GameObject.gameObjects.add(gameObject);
		}
		
		gameObject.onCreate();
		gameObject.onStart();		

		return gameObject;
	}

	public static void executeOnAllWithTags(final String[] search,
			final Function f) {
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX);
			if (GameObject.staticXGameObject.hasTag(search)) {
				f.execute(GameObject.staticXGameObject);
			}
		}
	}

	public static List<GameObject> findAllByName(final String search) {
		final LinkedList<GameObject> gos = new LinkedList<GameObject>();
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX); 
			if (GameObject.staticXGameObject.getName().equals(search)) {
				gos.add(GameObject.staticXGameObject);
			}
		}
		return gos;
	}

	public static List<GameObject> findAllByTags(final String[] search,
			final List<GameObject> gos) {
		gos.clear();

		float xMin = 800;
		float xMax = 0;
		float yMin = 800;
		float yMax = 0;

		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX);
			if (GameObject.staticXGameObject.hasTag(search)) {
				xMax = Math.max(
						GameObject.staticXGameObject.transform.position.x,
						xMax);
				xMin = Math.min(
						GameObject.staticXGameObject.transform.position.x,
						xMin);
				yMax = Math.max(
						GameObject.staticXGameObject.transform.position.y,
						yMax);
				yMin = Math.min(
						GameObject.staticXGameObject.transform.position.y,
						yMin);

				gos.add(GameObject.staticXGameObject);
			}
		}
		GameObject.distances.x = xMax - xMin;
		GameObject.distances.y = yMax - yMin;

		return gos;
	}

	public static List<GameObject> findAllByTags(final String[] hasThese, final String [] butNotThese,
			final List<GameObject> gos) {
		gos.clear();

		float xMin = 800;
		float xMax = 0;
		float yMin = 800;
		float yMax = 0;

		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			GameObject.staticXGameObject = GameObject.gameObjects.get(staticX);
			if (GameObject.staticXGameObject.hasTag(hasThese) && !GameObject.staticXGameObject.hasTag(butNotThese)) {
				xMax = Math.max(
						GameObject.staticXGameObject.transform.position.x,
						xMax);
				xMin = Math.min(
						GameObject.staticXGameObject.transform.position.x,
						xMin);
				yMax = Math.max(
						GameObject.staticXGameObject.transform.position.y,
						yMax);
				yMin = Math.min(
						GameObject.staticXGameObject.transform.position.y,
						yMin);

				gos.add(GameObject.staticXGameObject);
			}
		}
		GameObject.distances.x = xMax - xMin;
		GameObject.distances.y = yMax - yMin;

		return gos;
	}

	public Transform transform;

	private float destroyTimeStamp;

	//
	private RigidBody rigidBody;

	private String name = "GameObject";

	private String[] tags;

	private boolean isDestroyed = false;

	private boolean isDestroying = false;

	private final List<Component> components;

	private int poolId;

	public GameObject() {
		this.name = "GameObject";
		this.tags = null;
		this.transform = new Transform();
		this.components = new ArrayList<Component>();
	}

	public void addComponent(final Component c) {
		c.setGameObject(this);
		this.components.add(c);
	}

	public void addTag(final String tag)
	{
		if (this.hasTag(tag))
		{
			return;
		}

		if (this.tags == null)
		{
			this.tags = new String [] {};
		}

		final String [] newTags = new String[this.tags.length+1];
		for (int x = 0; x < newTags.length-1; x++)
		{
			newTags[x] = this.tags[x];
		}
		newTags[newTags.length-1] = tag;
		this.tags = newTags;		
	}

	@Override
	public void clean() {
		this.components.clear();
		this.rigidBody = null;
		this.transform.position.x = 0;
		this.transform.position.y = 0;
		this.transform.rotation.x = 0;
		this.transform.rotation.y = 0;
		this.transform.scale.x = 1;
		this.transform.scale.y = 1;
		this.isDestroying = false;
		this.isDestroyed = true;
	}

	@Override
	public void collide(final GameObject g) {
		if (this.isDestroyed) {
			return;
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).collide(g);
		}
	}

	@Override
	public void destroy() {
		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).onBeforeDestroy();
		}

		this.isDestroyed = true;
		GameObject.gameObjectsPool.release(this);
	}

	public void destroyAfter(final float time) {
		this.destroyTimeStamp = Time.getTime();

		this.destroyTimeStamp += time;
		this.isDestroying = true;
	}

	@Override
	public void draw() {
		if (this.isDestroyed) {
			return;
		}

		if (this.rigidBody != null) {
			this.rigidBody.draw();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);
			if (this.xComponent.isEnabled()) {
				this.xComponent.draw();
			}
		}
	}

	public boolean equals (final GameObject g)
	{
		if (g.getId() == this.id)
		{
			return true;
		}
		return false;
	}

	public GraphicAnimation getAnimation(final String name) {
		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);
			if (this.xComponent instanceof GraphicAnimation) {
				if (((GraphicAnimation) this.xComponent).getName()
						.equals(name)) {
					return (GraphicAnimation) this.xComponent;
				}
			}

		}
		return null;
	}

	private Component xc;
	public Component getComponent(final Class<? extends Component> getClass) {
		// String s = "";		
		for (int x = 0; x < this.components.size(); x++) {
			xc = this.components.get(x);
			// s += c.getClass().getSimpleName() + ",";
			if (xc.getClass() == getClass) {
				return xc;
			}
		}

		// getClass.getSimpleName() + " in " + s);
		return null;
	}

	public GraphicAnimation getCurrentAnimation() {
		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);
			if (this.xComponent instanceof GraphicAnimation) {
				if (this.xComponent.isEnabled()) {
					return (GraphicAnimation) this.xComponent;
				}
			}
		}
		return null;
	}


	public boolean getDestroyOnLevelLoad ()
	{
		return this.destroyOnLevelLoad;
	}

	public int getId()
	{
		return this.id;
	}

	public String getName() {
		return this.name;
	}

	@Override
	public int getPoolId ()
	{
		return this.poolId;
	}

	public String getPrintableTags() {
		String s = "";
		if (this.tags != null) {
			for (int x = 0; x < this.tags.length; x++) {
				s += this.tags[x] + ",";
			}
		}
		return s;
	}

	public RigidBody getRigidBody() {
		return this.rigidBody;
	}

	public String[] getTags() {
		return this.tags;
	}

	public boolean hasTag(final String tag) {
		if (this.tags == null) {
			return false;
		}
		if (tag == null) {
			return false;
		}

		for (int x = 0; x < this.tags.length; x++) {
			if (this.tags[x].equalsIgnoreCase(tag)) {
				return true;
			}
		}

		return false;
	}

	public boolean hasTag(final String[] otherTags) {
		if (this.tags == null) {
			return false;
		}
		if (otherTags == null) {
			return false;
		}

		for (int x = 0; x < this.tags.length; x++) {
			for (int y = 0; y < otherTags.length; y++) {
				if (this.tags[x].equalsIgnoreCase(otherTags[y])
						&& otherTags[y] != null) {
					return true;
				}
			}
		}

		return false;
	}

	public boolean isDestroyed() {
		return this.isDestroyed;
	}

	@Override
	public void onAfterUpdate() {
		if (this.isDestroyed) {
			return;
		}

		// technically should happen somewhereElse
		if (this.rigidBody != null) {
			this.rigidBody.onAfterUpdate();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);			
			if (this.xComponent.isEnabled()) {
				// c.getClass().getSimpleName());
				this.xComponent.onAfterUpdate();
			}
		}

		if (this.isDestroying) {
			if (this.destroyTimeStamp < Time.getTime()) {
				destroy();
			}
		}
	}

	@Override
	public void onCreate() {
		this.isDestroyed = false;
		this.id = GameObject.nextId;
		GameObject.nextId++;

		if (this.rigidBody != null) {
			this.rigidBody.onCreate();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).onCreate();
		}
	}

	@Override
	public void onStart() {
		if (this.rigidBody != null) {
			this.rigidBody.onStart();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).onStart();
		}
	}

	public GraphicAnimation playAnimation(final String name) {
		GraphicAnimation animation = null;

		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);
			if (this.xComponent instanceof GraphicAnimation) {
				final GraphicAnimation gl = (GraphicAnimation) this.xComponent;

				if (gl.getName().equalsIgnoreCase(name)) {
					gl.setEnabled(true);
					animation = gl;
				} else {
					gl.setEnabled(false);
				}
			}
		}

		return animation;
	}

	public void removeComponent(final Class<? extends Component> getClass) {
		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);
			if (this.xComponent.getClass() == getClass) {
				this.components.remove(this.xComponent);
				return;
			}

		}
	}

	public void removeComponent(final Component c) {
		this.components.remove(c);
	}

	public void setDestroyOnLevelLoad (final boolean d)
	{
		this.destroyOnLevelLoad = d;
	}

	public void setName(final String name) {
		this.name = name;
	}

	@Override
	public void setPoolId (final int x)
	{
		this.poolId = x;
	}

	public void setRigidBody(final RigidBody rigidBody) {
		rigidBody.setGameObject(this);
		this.rigidBody = rigidBody;
		rigidBody.setGameObject(this);
	}
	public void setTags(final String[] tags) {
		this.tags = tags;
	}
	@Override
	public void update() {
		if (this.isDestroyed) {
			return;
		}

		// technically should happen somewhereElse
		if (this.rigidBody != null) {
			this.rigidBody.update();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.xComponent = this.components.get(x);			
			if (this.xComponent.isEnabled()) {
				// c.getClass().getSimpleName());
				this.xComponent.update();
			}
		}
	}
}
