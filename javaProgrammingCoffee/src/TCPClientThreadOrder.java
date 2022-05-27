import java.io.ObjectOutputStream;
import java.net.Socket;

public class TCPClientThreadOrder extends Thread { 
	Socket socket = null;
	Coffee coffee;
	String name;
	public TCPClientThreadOrder(Socket socket, String name) {
		this.socket = socket; 
		this.name = name;
	}
	
	public void run() {
		try {
			ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
			while(true) {
				if(coffee != null) {
					oos.writeObject(name);
					oos.writeObject(coffee);
					coffee = null;
				}
				sleep(1000);
			}
			
		} catch (Exception e) {
			e.printStackTrace(); 
		}
		
	}
	public void setOrder(Coffee c, String n) {
		coffee = c;
		name = n;
	}
	public void setOrder(Coffee c) {
		coffee = c;
	}

}