import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Client client;
		Server server;
		Scanner scn = new Scanner(System.in);
		if(scn.nextInt() == 1) client = new Client();
		else server = new Server();
	}

}
