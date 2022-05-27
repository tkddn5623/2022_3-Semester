import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.Vector;

import javax.swing.JList;

public class TCPServerThreadOrder extends Thread {
	private Socket socket = null;
	private Vector<String> orderList;
	private Coffee c;
	private JList<String> guiList;
	
	public TCPServerThreadOrder(Socket socketUser, Vector<String> orderList, JList guiList) {
		this.socket = socketUser;
		this.orderList = orderList;
		this.guiList = guiList;
	}
   	public void run() {
   		try {
			ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
			while((c = (Coffee) ois.readObject()) != null) {
				orderList.add("주문 : " + c.getName());
				guiList.setListData(orderList);
			}
		} catch (Exception e) {
		    e.printStackTrace(); // 예외처리
		}    		
    }	
   	/*		try {
			InputStream input = socket.getInputStream();
			ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
			
			while((cp.coffeeMenu = (HashSet<Coffee>) ois.readObject()) != null) {
				cp.getMenuVector().clear();
				Iterator<Coffee> iter = cp.coffeeMenu.iterator();
				while(iter.hasNext()) {
					Coffee c = iter.next();
					cp.getMenuVector().add(c.getName() + "[" + c.getPrice() + "]");
				}
				cp.getMenuList().setListData(cp.getMenuVector());
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	*/
}
