import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
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
	private Client client;
	private CoffeeServiceImpl service;
	public Vector<String> menuVector;
	private TimeThread t1;
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
		setBorder(new EmptyBorder(5, 5, 5, 5));
		setLayout(new BorderLayout(5, 5));
		client = new Client(name);
		service = new CoffeeServiceImpl();
		menuVector = new Vector<String>();
		
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
		moneyLabel.setText(client.getMoney() + " WON");
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
		getMenu(this, service.map); //////////////////////////////////////////////////GETTING MENU, but without thread, not change//
		
		clockLabel = new JLabel("");
		panel1.add(clockLabel);
		t1 = new TimeThread(clockLabel); //THREAD : for time clock
		t1.start();
		
		/*String str = service.viewAll();
		TCPClient c = new TCPClient();
		String m = c.tcp(str);*/
	}
	private void getMenu(CustomerPanel cPanel, Map menuMap) {
		cPanel.menuVector.clear(); //Whenever it called, All menu cleared.
		Set<Coffee> keySet = menuMap.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		while(keyIter.hasNext()) {
			Coffee coffee = keyIter.next();
			cPanel.menuVector.add(coffee.getCoffeeName() + "[" + menuMap.get(coffee) + "]"); //Vector's Entries :: "Americano", "Latte"
		}
	}
	class ChargeListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			int price = Integer.parseInt(textField.getText());
			client.setMoney(client.getMoney() + price);
			moneyLabel.setText(client.getMoney() + " WON");
		}
	}
	class OrderListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			Set<Coffee> keySet = service.map.keySet();
			Iterator<Coffee> keyIter = keySet.iterator();
			while(keyIter.hasNext()) {
				Coffee coffee = keyIter.next();
				String liststr = menuList.getSelectedValue();
				if(liststr != null && coffee.getCoffeeName().equals(liststr.substring(0, liststr.lastIndexOf('[')))) { //Searching "Coffee" by "String"
					if(client.getMoney() >= service.map.get(coffee)) { //Success!
						
						msgLabel.setText(coffee.getCoffeeName() + "를 주문하셨습니다.");
						client.setMoney(client.getMoney() - service.map.get(coffee));
						
					}
					else{ //Success, but no money
						msgLabel.setText("For " + coffee.getCoffeeName() + " , You need more " + (service.map.get(coffee) - client.getMoney()) + " Won.");
					}
					break;
				}
				else if(liststr != null && keyIter.hasNext() == false){ //Fail.
					msgLabel.setText("Bug encountered: There is no " + liststr.substring(0, liststr.lastIndexOf('[')));
				}
			}
			moneyLabel.setText(client.getMoney() + " WON");
		}
	}
}
