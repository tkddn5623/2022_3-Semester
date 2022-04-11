package pa1;

public class Key extends GameObject{
	private boolean pickup;
	public boolean getPickup() {return pickup;}
	public void setPickup(boolean value) {pickup = value;} 
	public Key(int x, int y) {
		/* add your code, you can add parameter, too */
		setX(x);
		setY(y);
		pickup = false;

	}
}
