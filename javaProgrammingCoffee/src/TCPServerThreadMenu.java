import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;


public class TCPServerThreadMenu extends Thread{
	private ArrayList<ObjectOutputStream> outList;
	private Socket socket = null;
	private CoffeeService cs;
	
	public TCPServerThreadMenu(Socket socketUser, CoffeeService cs) {
		this.socket = socketUser;
		this.cs = cs;
	}
   	public void run() {
   		try {
			ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream()); 
			while(true) {
				if(socket.isConnected()) {
					oos.writeObject(cs.getMenu().clone());
					this.suspend();
				}
			}
			
		} catch (Exception e) {
		    this.suspend();
		}    		
    }	
}
