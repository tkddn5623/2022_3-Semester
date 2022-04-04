import java.util.Random;
import java.util.Scanner;

class Room {
	Room(){
		Random random = new Random();
		this.States = false;
		this.Capacity = random.nextInt(4) + 1;
	}
	int getCapacity() { return Capacity; }
	boolean getStates() { return States; }
	void setStates(boolean argm) { States = argm; }
	boolean States;
	int Capacity;

}


public class Hotel {

	public static void main(String[] args) {
		Hotel hotel = new Hotel(); //Make Hotel object using Hotel class
		Room[] room = new Room[10]; //Make 10 Room objects using Room class
		
		for (int i = 0; i < 10; i++) 
			room[i] = new Room();
		
		System.out.println("Each Room's Capacity");
		for(int i = 0; i < 10; i++) {
			System.out.print(room[i].getCapacity()); //Print each room's capacity.
			System.out.print(" ");
		}
		System.out.println("");
		
		int n, j;
		boolean flag = true;
		Scanner scn = new Scanner(System.in);
		
		while(flag) {
			System.out.println("Enter number (1 : check in), (2 : check out), (3 : Finish)");
			switch(scn.nextInt()) { //Create Menu and it receives input from the user.
			case 1:
				System.out.println("Enter room number");
				n = scn.nextInt();
				System.out.println("How many people?");
				j = scn.nextInt();
				hotel.checkin(n, j, room);
				break;
			case 2:
				System.out.println("Enter room number");
				n = scn.nextInt();
				hotel.checkout(n, room);
				break;
			default:
				flag = false;
				scn.close();
				break;
			}
		}
	}
	public void checkin(int n, int j, Room[] r) {
		if (n <= 0 || n > 10 || r[n - 1].getStates() == true) 
			System.out.println("Check in error : already occupied");
		else if (j <= 0 || r[n - 1].getCapacity() < j) 
			System.out.println("Check in error : capacity exceed.");
		else {
			r[n - 1].setStates(true);
			System.out.println("Check in Success");
		}
	}
	public void checkout(int n, Room[] r) {
		if (n <= 0 || n > 10 || r[n - 1].getStates() == false) 
			System.out.println("Check out error : already checked out ");
		else {
			r[n - 1].setStates(false);
			System.out.println("Check out Success");
		}
	}
}
