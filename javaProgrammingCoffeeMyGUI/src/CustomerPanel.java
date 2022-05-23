import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.util.Calendar;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

import javax.swing.JTree;
import javax.swing.JButton;
import javax.swing.JList;
import javax.swing.UIManager;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;

public class CustomerPanel extends JPanel {
	private String clientName;
	private int money;
	private CoffeeServiceImpl service;
	public Vector menuVector;
	private TimeThread t1;
	private Thread t2; //For Menu
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	private JLabel clockLabel;
	private JLabel moneyLabel;
	private JButton orderButton;
	private JButton mchargeButton;
	private JList menuList;
	private JScrollPane scrollPane;
	public CustomerPanel(String name) {
		setBorder(new EmptyBorder(5, 5, 5, 5));
		setLayout(new BorderLayout(5, 5));
		
		clientName = name;
		money = 0;
		service = new CoffeeServiceImpl();
		menuVector = new Vector<String>();
		
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();
		scrollPane = new JScrollPane();
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		add(panel1, BorderLayout.NORTH);
		add(panel2, BorderLayout.CENTER);
		add(panel3, BorderLayout.SOUTH);
		add(scrollPane, BorderLayout.WEST);
		
		mchargeButton = new JButton("Money charge");
		panel3.add(mchargeButton);
		moneyLabel = new JLabel("");
		moneyLabel.setText(money + " WON");
		moneyLabel.setPreferredSize(new Dimension(60,10));
		panel3.add(moneyLabel);
		
		orderButton = new JButton("Order");
		add(orderButton, BorderLayout.EAST);
		
		menuList = new JList(menuVector);
		menuList.setPreferredSize(new Dimension(300,150));
		scrollPane.setViewportView(menuList);
		getMenu(this, service.map);
		
		clockLabel = new JLabel("");
		panel1.add(clockLabel);
		t1 = new TimeThread(clockLabel); //THREAD : for time clock
		t1.start();
	}
	private void getMenu(CustomerPanel cPanel, Map menuMap) {
		cPanel.menuVector.clear();
		Set<Coffee> keySet = menuMap.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		while(keyIter.hasNext()) {
			Coffee coffee = keyIter.next();
			cPanel.menuVector.add(coffee.getCoffeeName() + " [" + menuMap.get(coffee) + "]");
		}
	}
}
