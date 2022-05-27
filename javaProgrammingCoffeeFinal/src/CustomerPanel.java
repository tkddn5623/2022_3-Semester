import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Calendar;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.ScrollPaneConstants;
import javax.swing.border.EmptyBorder;

public class CustomerPanel extends JPanel {
	public HashSet<Coffee> coffeeMenu;
	private Vector<String> menuVector;
	private int money;
	private Socket socket;
	private Thread timet;
	private Thread t1;
	private Thread t2;
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	private JLabel clockLabel;
	private JLabel moneyLabel;
	private JButton orderButton;
	private JButton mchargeButton;
	private JList<String> menuList;
	private JScrollPane scrollPane;
	private JLabel msgLabel;
	private JTextField textField;
	private JLabel lblNewLabel;
	public CustomerPanel(String name) {
		try {
			socket = new Socket("localhost", 9000);
		} catch (IOException e) {
			System.out.println("Error: Fail to connect");
			e.printStackTrace();
		}
		setBorder(new EmptyBorder(5, 5, 5, 5));
		setLayout(new BorderLayout(5, 5));
		coffeeMenu = new HashSet<Coffee>();
		menuVector = new Vector<String>();
		money = 0;
		
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();
		scrollPane = new JScrollPane();
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		add(panel1, BorderLayout.NORTH);
		add(panel2, BorderLayout.CENTER);
		
		msgLabel = new JLabel("");
		panel2.add(msgLabel);
		add(panel3, BorderLayout.SOUTH);
		add(scrollPane, BorderLayout.WEST);
		
		mchargeButton = new JButton("Money charge");
		mchargeButton.addActionListener(new ChargeListener());
		moneyLabel = new JLabel();
		//moneyLabel.setHorizontalAlignment(SwingConstants.CENTER);
		moneyLabel.setText(money + " WON");
		moneyLabel.setPreferredSize(new Dimension(80,10));
		
		textField = new JTextField();
		panel3.add(textField);
		textField.setColumns(10);
		panel3.add(mchargeButton);
		panel3.add(moneyLabel);
		
		orderButton = new JButton("Order");
		orderButton.addActionListener(new OrderListener());
		add(orderButton, BorderLayout.EAST);
		
		menuList = new JList<String>(menuVector);
		menuList.setPreferredSize(new Dimension(300, 200));
		scrollPane.setViewportView(menuList);
		getMenu(this, coffeeMenu); //////////////////////////////////////////////////GETTING MENU, but without thread, not change//
		clockLabel = new JLabel("");
		panel1.add(clockLabel);
		timet = new TimeThread(clockLabel); //THREAD : for time clock
		timet.start();
		t1 = new TCPClientThreadMenu(socket, this);
		t2 = new TCPClientThreadOrder(socket);
		t1.start();
		t2.start();
		
	}
	public Vector<String> getMenuVector(){
		return menuVector;
	}
	public JList<String> getMenuList() {
		return menuList;
	}
	private void getMenu(CustomerPanel cPanel, Set<Coffee> coffeeMenu) {
		cPanel.menuVector.clear(); //Whenever it called, All menu cleared.
		Iterator<Coffee> iter = coffeeMenu.iterator();
		while(iter.hasNext()) {
			Coffee c = iter.next();
			cPanel.menuVector.add(c.getName() + "[" + c.getPrice() + "]"); //Vector's Entries :: "Americano", "Latte"
		}
	}
	class ChargeListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			int price = Integer.parseInt(textField.getText());
			money += price;
			moneyLabel.setText(money + " WON");
		}
	}
	class OrderListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			String liststr = menuList.getSelectedValue();
			Iterator<Coffee> iter = coffeeMenu.iterator();
			while(iter.hasNext()) {
				Coffee c = iter.next();
				if(liststr != null && c.getName().equals(liststr.substring(0, liststr.lastIndexOf('[')))) { //Searching "Coffee" by "String"
					if(money >= c.getPrice()) { //Success!
						msgLabel.setText(c.getName() + "를 주문하셨습니다.");
						money -= c.getPrice();
						TCPClientThreadOrder t2Casting = (TCPClientThreadOrder) t2;
						t2Casting.setCoffee(c);
					}
					else{ //Success, but no money
						msgLabel.setText(c.getName() + "를 마시려면 " + (c.getPrice() - money) + " 원이 더 필요합니다.");
					}
					break;
				}
				else if(liststr != null && iter.hasNext() == false){ //Fail.
					msgLabel.setText("버그발생 : 찾을 수 없음 " + liststr.substring(0, liststr.lastIndexOf('[')));
				}
			}
			moneyLabel.setText(money + " WON");
		}
	}
	public class TimeThread extends Thread {
		private Thread t; 
		private JLabel clock;
		private Calendar cal;
		public String timeStr;
		public TimeThread(JLabel clock) {
			this.clock = clock;
		}
		public void start () {  
			if (t == null) { 
				t = new Thread (this); 
				t.start (); 
			} 
		}
		public void run() {
			while(true) {
				cal = Calendar.getInstance();
				timeStr = cal.get(cal.AM_PM) == 0 ? "AM" : "PM" + " " + cal.get(cal.HOUR) + " : " + cal.get(cal.MINUTE) + " : " + cal.get(cal.SECOND);
				clock.setText(timeStr);
				try {
					t.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

}
