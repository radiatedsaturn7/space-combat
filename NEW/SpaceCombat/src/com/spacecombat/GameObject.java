package com.spacecombat;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class GameObject extends Component implements Poolable {
	
	private boolean trace = false;	
	private static List<GameObject> gameObjects = new ArrayList<GameObject>();
	private static Vector2 distances = new Vector2();

	private static Pool gameObjectsPool;

	static {
		GameObject.gameObjectsPool = new Pool();
		GameObject.gameObjectsPool.init(GameObject.class,100);
	}
	
	public static GameObject findByName(final String search) {
		GameObject staticXGameObject = null;
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX);
			if (staticXGameObject.getName().equals(search)) {
				return staticXGameObject;
			}
		}
		return null;
	}
	public static GameObject findRandomByTags(final int search) {
		GameObject staticXGameObject = null;
		final LinkedList<GameObject> gos = new LinkedList<GameObject>();		
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX);
			if (staticXGameObject.hasTag(search)) {
				gos.add(staticXGameObject);
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

	public static void executeOnAllWithTags(final int search,
			final Function f) {
		GameObject staticXGameObject = null;
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX);
			if (staticXGameObject.hasTag(search)) {
				f.execute(staticXGameObject);
			}
		}
	}

	public static List<GameObject> findAllByName(final String search) {
		final LinkedList<GameObject> gos = new LinkedList<GameObject>();
		GameObject staticXGameObject = null;
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX); 
			if (staticXGameObject.getName().equals(search)) {
				gos.add(staticXGameObject);
			}
		}
		return gos;
	}

	public static List<GameObject> findAllByTags(final int search,
			final List<GameObject> gos) {
		gos.clear();
		GameObject staticXGameObject = null;

		float xMin = 800;
		float xMax = 0;
		float yMin = 800;
		float yMax = 0;

		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX);
			if (staticXGameObject.hasTag(search)) {
				xMax = Math.max(
						staticXGameObject.transform.position.x,
						xMax);
				xMin = Math.min(
						staticXGameObject.transform.position.x,
						xMin);
				yMax = Math.max(
						staticXGameObject.transform.position.y,
						yMax);
				yMin = Math.min(
						staticXGameObject.transform.position.y,
						yMin);

				gos.add(staticXGameObject);
			}
		}
		GameObject.distances.x = xMax - xMin;
		GameObject.distances.y = yMax - yMin;

		return gos;
	}

	public static List<GameObject> findAllByTags(final int hasThese, final int butNotThese,
			final List<GameObject> gos) {
		gos.clear();

		float xMin = 800;
		float xMax = 0;
		float yMin = 800;
		float yMax = 0;
		GameObject staticXGameObject = null;
		for (int staticX = 0; staticX < GameObject.gameObjects.size(); staticX++) {
			staticXGameObject = GameObject.gameObjects.get(staticX);

			if (staticXGameObject.hasTag(hasThese) && !staticXGameObject.hasTag(butNotThese)) {
				
				xMax = Math.max(
						staticXGameObject.transform.position.x,
						xMax);
				xMin = Math.min(
						staticXGameObject.transform.position.x,
						xMin);
				yMax = Math.max(
						staticXGameObject.transform.position.y,
						yMax);
				yMin = Math.min(
						staticXGameObject.transform.position.y,
						yMin);

				gos.add(staticXGameObject);
			}
		}
		GameObject.distances.x = xMax - xMin;
		GameObject.distances.y = yMax - yMin;
		
		
		if (hasThese == Tags.enemy && butNotThese == (Tags.shot | Tags.spawner))
		{
			new Exception().printStackTrace();
			System.out.println("SEARCHING:" + gos.size());
		}
		
		return gos;
	}

	public Transform transform;

	private float destroyTimeStamp;

	private RigidBody rigidBody;

	private String name = "GameObject";

	private int tags;

	private boolean isDestroyed = false;

	private boolean isDestroying = false;

	private final List<Component> components;

	private int poolId;

	public GameObject() {		
		this.name = "GameObject";
		trace = false;	
		this.tags = 0;
		this.transform = new Transform();
		this.components = new ArrayList<Component>();
		doTrace();
	}

	public void addComponent(final Component c) {
		doTrace();
		c.setGameObject(this);
		this.components.add(c);		
	}

	public void addTag(final int tag)
	{
		doTrace();

		this.tags = this.tags | tag;
	}

	@Override
	public void clean() {
		doTrace();
		this.components.clear();
		
		this.trace = false;	
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
		doTrace();
		
		if (this.isDestroyed) {
			return;
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).collide(g);
		}
	}
	
	@Override
	public void onGUI() {
		doTrace();
		
		if (this.isDestroyed) {
			return;
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).onGUI();
		}
	}
	
	public static void clear()
	{
		System.out.println("REMOVING ALLN OBJECTS");
		for (int x = 0; x < GameObject.gameObjects.size(); x++)
		{
			gameObjects.get(x).destroy();
		} 

		gameObjects.clear();
	}
	
	@Override
	public void destroy() {
		doTrace();	
		this.isDestroyed = true;		
	}
	
	public void release()
	{
		doTrace();
		
		int size = this.components.size();
		//System.out.println("releasing:"+size);
		for (int x = 0; x < size; x++) {
			//System.out.println("    :"+x+"  "+this.components.get(x).getClass().getSimpleName()+"   ="+this.components.size());
			this.components.get(x).destroy();
			
			//System.out.println("    :"+x+"  "+this.components.get(x).getClass().getSimpleName()+"   ="+this.components.size());
		}
		
		GameObject.gameObjectsPool.release(this);
	}

	public void destroyAfter(final float time) {
		doTrace();
		
		this.destroyTimeStamp = Time.getTime();

		this.destroyTimeStamp += time;
		this.isDestroying = true;
	}

	@Override
	public void draw() {
		doTrace();
		
		if (this.isDestroyed) {
			return;
		}

		if (this.rigidBody != null) {
			this.rigidBody.draw();
		}

		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);
			if (xComponent.isEnabled()) {
				xComponent.draw();
			}
		}
	}

	public boolean equals (final GameObject g)
	{
		doTrace();
		
		if (g.getId() == this.id)
		{
			return true;
		}
		return false;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + id;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + poolId;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		GameObject other = (GameObject) obj;
		if (id != other.id)
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (poolId != other.poolId)
			return false;
		return true;
	}
	
	public GraphicAnimation getAnimation(final String name) {
		doTrace();
		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {			
			xComponent = this.components.get(x);
			if (xComponent instanceof GraphicAnimation) {
				if (((GraphicAnimation) xComponent).getName()
						.equals(name)) {
					return (GraphicAnimation) xComponent;
				}
			}

		}
		return null;
	}

	private Component xc;
	public Component getComponent(final Class<? extends Component> getClass) 
	{
		return getComponent(getClass,false);
	}

	public Component getComponent(final Class<? extends Component> getClass, boolean print) {
		doTrace();
		
		
		//String s = "";
		for (int x = 0; x < this.components.size(); x++) { 
			xc = this.components.get(x);
			 //s += xc.getClass().getSimpleName() + ",";
			if (xc.getClass() == getClass) {
				return xc; 
			}
		}

		if (print)
		{
			//System.out.println(getName() + " does not have a " + getClass.getSimpleName());
			//System.out.println(getClass.getSimpleName() + " is not in: " + s);
		}

		return null;
	}

	public GraphicAnimation getCurrentAnimation() {
		doTrace();
		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);
			if (xComponent instanceof GraphicAnimation) {
				if (xComponent.isEnabled()) {
					return (GraphicAnimation) xComponent;
				}
			}
		}
		return null;
	}


	public boolean getDestroyOnLevelLoad ()	
	{
		doTrace();
		
		return this.destroyOnLevelLoad;
	}

	public int getId()
	{
		doTrace();
		
		return this.id;
	}

	public String getName() {
		doTrace();
		

		return this.name;
	}

	@Override
	public int getPoolId ()	
	{
		doTrace();
		
		return this.poolId;
	}

	public RigidBody getRigidBody() {
		//doTrace();
		
		return this.rigidBody;
	}

	public int getTags() {
		doTrace();		
		return this.tags;
	}

	public boolean hasTag(final int tag) {
		doTrace();		
		return Tags.compareTagsOr(this.tags, tag);
	}

	public boolean isDestroyed() {
		doTrace();
		return this.isDestroyed;
	}

	@Override
	public void onAfterUpdate() {
		doTrace();
		
		if (this.isDestroyed) {
			return;
		}

		// technically should happen somewhereElse
		if (this.rigidBody != null) {
			this.rigidBody.onAfterUpdate();
		}

		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);			
			if (xComponent.isEnabled()) {
				// c.getClass().getSimpleName());
				xComponent.onAfterUpdate();
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
		doTrace();

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
		doTrace();
		
		if (this.rigidBody != null) {
			this.rigidBody.onStart();
		}

		for (int x = 0; x < this.components.size(); x++) {
			this.components.get(x).onStart();
		}
	}

	public GraphicAnimation playAnimation(final String name) {
		doTrace();
		
		GraphicAnimation animation = null;
		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);
			if (xComponent instanceof GraphicAnimation) {
				final GraphicAnimation gl = (GraphicAnimation) xComponent;

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
		doTrace();
		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);
			if (xComponent.getClass() == getClass) {
				this.components.remove(xComponent);
				return;
			}

		}
	}

	public void removeComponent(final Component c) {
		doTrace();
		
		this.components.remove(c);
	}

	public void setDestroyOnLevelLoad (final boolean d)
	{
		doTrace();
		
		this.destroyOnLevelLoad = d;
	}

	public void setName(final String name) {
		doTrace();
		
		this.name = name;
	}

	@Override
	public void setPoolId (final int x)
	{
		doTrace();
		this.poolId = x;
	}

	public void setRigidBody(final RigidBody rigidBody) {
		doTrace();
		
		rigidBody.setGameObject(this);
		this.rigidBody = rigidBody;
		rigidBody.setGameObject(this);
	}
	public void setTags(final int tags) {
		doTrace();		
		this.tags = tags;
	}
	@Override
	public void update() {
		doTrace();
		
		if (this.isDestroyed) {
			return;
		}

		// technically should happen somewhereElse
		if (this.rigidBody != null) {
			this.rigidBody.update();
		}

		Component xComponent = null;
		for (int x = 0; x < this.components.size(); x++) {
			xComponent = this.components.get(x);			
			if (xComponent.isEnabled()) {
				// c.getClass().getSimpleName());
				xComponent.update();
			}
		}
	}
	
	public String toString()
	{
		String string = "";
		string += "GameObject [" + this.name + "]:\n";
		string += "    PoolID [" + this.poolId + "]:\n";
		string += "    Transform:" + transform.position + " " + transform.rotation + " " + transform.scale + "\n";
		string += "    RigidBody:" + rigidBody;	
		
		if (rigidBody != null)
		{
			string += "    Speed    :" + rigidBody.speed + "\n";
		}
		string += "    Components:" + components.size() + "\n";
		
		for (int x = 0; x < components.size(); x++)
		{
			string += "        " + components.get(x).getClass().getSimpleName() + "\n";
		}
		return string;		
	}
	
	public void setTrace(boolean t)
	{
		doTrace();
		trace = t;
	}
		
	public void doTrace()
	{
		if (trace)
		{
			Exception e = new Exception("---TRACING---\n" + toString());
			e.printStackTrace();
		}
	}
}
