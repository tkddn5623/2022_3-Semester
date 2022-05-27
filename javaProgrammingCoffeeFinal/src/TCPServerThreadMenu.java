import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

import javax.swing.JList;

public class TCPServerThreadMenu extends Thread{
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
				oos.writeObject(cs.getMenu().clone());
				this.suspend();
			}
			
		} catch (Exception e) {
		    e.printStackTrace();
		}    		
    }	
}
