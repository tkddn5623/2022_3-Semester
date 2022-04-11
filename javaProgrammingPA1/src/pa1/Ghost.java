package pa1;

public class Ghost extends GameObject{
	private boolean ready;
	public Ghost(int x, int y) {
		/* add your code, you can add parameter, too */
		setX(x);
		setY(y);
		ready = true;

	}	
	
	public void move(int Px, int Py) {
		/* add your code, you can add parameter, too */
		if(ready == true) {
			if(getX() < Px)
				setX(getX() + 1);
			if(getX() > Px)
				setX(getX() - 1);
			if(getY() < Py)
				setY(getY() + 1);
			if(getY() > Py)
				setY(getY() - 1);
		}
	ready = !ready;
	}
}
