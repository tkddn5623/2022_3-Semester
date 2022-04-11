package pa1;
import java.util.Scanner;

public class Board implements Game {
	Player player;
	Ghost ghost;
	Key key;
	Door door;
	char[][] board;

	public Board() {		
		/* add your code, you can add parameter, too */
		board = new char[][] {
			 {' ','бс',' ',' ',' ',' ','бс',' ','бс',' ',' ',' ',' ',' ',' '},
			 {' ','бс',' ','бс','бс','бс','бс',' ','бс',' ','бс',' ','бс','бс',' '},
			 {' ','бс',' ',' ',' ','бс',' ',' ','бс',' ','бс',' ',' ','бс',' '},
			 {' ','бс',' ','бс',' ','бс',' ','бс','бс',' ','бс','бс',' ','бс',' '},
			 {' ',' ',' ','бс',' ','бс',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			 {' ','бс','бс','бс',' ',' ',' ','бс','бс','бс','бс','бс','бс','бс',' '},
			 {' ',' ',' ',' ',' ','бс',' ',' ',' ',' ',' ',' ',' ','бс',' '},
			 {'бс','бс',' ','бс','бс','бс',' ','бс','бс','бс','бс','бс',' ','бс',' '},
			 {' ',' ',' ',' ',' ',' ',' ','бс',' ',' ',' ',' ',' ','бс',' '},
			 {' ','бс','бс',' ','бс','бс',' ','бс',' ','бс','бс','бс',' ','бс',' '},
			 {' ','бс',' ',' ',' ',' ',' ','бс',' ',' ',' ','бс',' ','бс',' '},
			 {' ','бс',' ','бс','бс','бс','бс','бс','бс','бс','бс','бс',' ','бс',' '},
			 {' ','бс',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','бс',' '},
			 {' ','бс','бс','бс',' ','бс','бс','бс','бс','бс','бс','бс',' ','бс',' '},
			 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
			};
	}
	
	public void printBoard() {
		/* add your code, you can add parameter, too */
		for(int y = 0; y < 15; y++) {
			for(int x = 0; x < 15; x++) {
				if(player.getX() == x && player.getY() == y) System.out.print('P');
				else if(ghost.getX() == x && ghost.getY() == y) System.out.print('G');
				else if(key.getX() == x && key.getY() == y) System.out.print('K');
				else if(door.getX() == x && door.getY() == y) System.out.print('D');
				else System.out.print(board[y][x]);
			}
			System.out.println();
		}
		
	}

	public void initObjects() {
		/* add your code, you can add parameter, too */
		Scanner scn = new Scanner(System.in);
		int input1 = -1, input2 = -1;
		
		//Input begin
		while(input1 < 0 || input1 > 14 || input2 < 0 || input2 > 14
				|| board[input2][input1] == 'бс')
		{
			System.out.println("input player x, y (0 ~ 14) :");
			input1 = scn.nextInt();
			input2 = scn.nextInt();
		}
		
		player = new Player(input1, input2); //player
		
		input1 = -1;
		input2 = -1;
		while(input1 < 0 || input1 > 14 || input2 < 0 || input2 > 14 
				|| board[input2][input1] == 'бс'
				|| (player.getX() == input1 && player.getY() == input2))
		{
			System.out.println("input ghost x, y (0 ~ 14) :");
			input1 = scn.nextInt();
			input2 = scn.nextInt();
		}
		ghost = new Ghost(input1, input2); //ghost
		
		input1 = -1;
		input2 = -1;
		while(input1 < 0 || input1 > 14 || input2 < 0 || input2 > 14 
				|| board[input2][input1] == 'бс'
				|| (player.getX() == input1 && player.getY() == input2)
				|| (ghost.getX() == input1 && ghost.getY() == input2))
		{
			System.out.println("input key x, y (0 ~ 14) :");
			input1 = scn.nextInt();
			input2 = scn.nextInt();
		}
		key = new Key(input1, input2); //key
		
		input1 = -1;
		input2 = -1;
		while(input1 < 0 || input1 > 14 || input2 < 0 || input2 > 14 
				|| board[input2][input1] == 'бс'
				|| (player.getX() == input1 && player.getY() == input2)
				|| (ghost.getX() == input1 && ghost.getY() == input2)
				|| (key.getX() == input1 && key.getY() == input2))
		{
			System.out.println("input door x, y (0 ~ 14) :");
			input1 = scn.nextInt();
			input2 = scn.nextInt();
		}
		door = new Door(input1, input2); //door
		//Input end
		
		
	}
	
	public void movePlayer() {
		/* add your code, you can add parameter, too */
		
		char direction = ' ';
		int destX = player.getX(), destY = player.getY();
		Scanner scn2 = new Scanner(System.in);
		direction = scn2.next().charAt(0);
		switch(direction) {
		case 'u':
			destY = player.getY() - 1;
			break;
		case 'd':
			destY = player.getY() + 1;
			break;
		case 'l':
			destX = player.getX() - 1;
			break;
		case 'r':
			destX = player.getX() + 1;
		}
		if(destX < 0 || destX > 14 || destY < 0 || destY > 14 || board[destY][destX] == 'бс' ) {
			destX = player.getX();
			destY = player.getY();
		}
		
		
		player.move(destX, destY);
		if(player.getX() == key.getX() && player.getY() == key.getY()) {
			key.setPickup(true);
			key.setX(-1);
			key.setY(-1);
		}
		//scn2.close();
	}	
	
	public void moveGhost() {
		/* add your code, you can add parameter, too */
		ghost.move(player.getX(), player.getY());

	}
	
	public boolean isFinish() {
		/* add your code, you can add parameter, too */
		if(key.getPickup() == true && player.getX() == door.getX() && player.getY() == door.getY()) {
			System.out.println("YOU WIN");
			return true;
		}
		else if (player.getX() == ghost.getX() && player.getY() == ghost.getY()) {
			System.out.println("YOU LOSE");
			return true;
		}
			
		return false;

	}
}
