import java.io.ObjectInputStream;
import java.net.Socket;
import java.util.Vector;
import javax.swing.JList;

public class TCPServerThreadOrder extends Thread {
	private Socket socket = null;
	private Vector<String> orderList;
	private Coffee c;
	private String name;
	private JList<String> guiList;
	
	public TCPServerThreadOrder(Socket socketUser, Vector<String> orderList, JList<String> guiList) {
		this.socket = socketUser;
		this.orderList = orderList;
		this.guiList = guiList;
	}
   	public void run() {
   		try {
			ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
			while((name = (String)ois.readObject()) != null) {
				if(socket.isClosed()) {
					this.interrupt();
				}
				c = (Coffee) ois.readObject();
				orderList.add(name + ": " +  c.getName());
				guiList.setListData(orderList);
			}
		} catch (Exception e) {
			this.interrupt();
		}    		
    }	
}
