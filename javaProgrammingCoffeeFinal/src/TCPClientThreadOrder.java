import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class TCPClientThreadOrder extends Thread { 
	Socket socket = null;
	Coffee coffee;
	public TCPClientThreadOrder(Socket socket) {
		this.socket = socket; 
	}
	
	public void run() {
		try {
			ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
			while(true) {
				if(coffee != null) {
					oos.writeObject(coffee);
					coffee = null;
				}
				sleep(1000);
			}
			
		} catch (Exception e) {
			e.printStackTrace(); 
		}
		
	}
	public void setCoffee(Coffee c) {
		coffee = c;
	}

}