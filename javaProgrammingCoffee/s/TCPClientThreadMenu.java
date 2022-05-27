import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.Vector;

/**
 * 1 대 1 소켓 통신 클라이언트 예제
 */
public class TCPClientThreadMenu extends Thread {
	private Socket socket = null;
	private CustomerPanel cp;
	
	public TCPClientThreadMenu(Socket socket, CustomerPanel cp) {
		this.socket = socket;
		this.cp = cp;
	}
	public void run() {
		try {
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

}
            
