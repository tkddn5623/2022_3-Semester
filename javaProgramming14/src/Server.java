import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
public class Server {
	public Server() {
		ServerSocket ss;
		Scanner scn = new Scanner(System.in);
		System.out.println("server start");
		try {
			ss = new ServerSocket(8011);
			Socket soc = ss.accept();
			InputStream in = soc.getInputStream();
			DataInputStream dis = new DataInputStream (in);
			java.io.OutputStream out = soc.getOutputStream();
			DataOutputStream dos = new DataOutputStream (out);
			while (true) {
				
				System.out.println (dis.readUTF ());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}