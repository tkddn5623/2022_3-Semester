package pa1;
import java.util.Scanner;

public class Player extends GameObject{
	
	public Player(int x, int y) {
		/* add your code, you can add parameter, too */
		setX(x);
		setY(y);
	}	
	
	public void move(int destX, int destY) {
		/* add your code, you can add parameter, too */
		setX(destX);
		setY(destY);

	}
}
