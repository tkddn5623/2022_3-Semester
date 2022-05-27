import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	public Client() {
		Scanner scn = new Scanner(System.in);
		String serverIP = "localhost";
		Socket soc;
		System.out.println("client start");
		try {
			soc = new Socket(serverIP, 8011);
			InputStream in = soc.getInputStream();
			DataInputStream dis = new DataInputStream (in);
			java.io.OutputStream out = soc.getOutputStream();
			DataOutputStream dos = new DataOutputStream (out);
			while(true) {
				dos.writeUTF(scn.nextLine());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
