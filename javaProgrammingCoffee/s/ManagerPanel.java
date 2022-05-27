import javax.swing.JPanel;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import javax.swing.JTextField;

import javax.swing.JButton;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Vector;
import java.awt.Font;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JList;
import javax.swing.JTextPane;

public class ManagerPanel extends JPanel {
	private ServerSocket svsocket;
	private Socket ussocket;
	private TCPServerThreadOrder t1;
	private TCPServerThreadMenu t2;
	private Vector<String> orderList;
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	private JTextField textField_5;
	private JTextField textField_6;
	private JButton btnNewButton_1;
	private JButton btnNewButton_2;
	private JTextPane textPane;
	
	CoffeeService service = new CoffeeServiceImpl();
	private JButton btnNewButton_3;
	private JButton btnNewButton_4;
	private JList<String> list;

	/**
	 * Create the panel.
	 */
	public ManagerPanel() {
		try {
			svsocket = new ServerSocket(9000);
			ussocket = svsocket.accept();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		orderList = new Vector<String>();
		setLayout(null);
		
		textField = new JTextField();
		textField.setFont(new Font("굴림", Font.BOLD, 14));
		textField.setText("\uAD00\uB9AC\uC790 \uBA54\uB274");
		textField.setBounds(0, 0, 450, 21);
		add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setText("\uBA54\uB274 \uC774\uB984");
		textField_1.setBounds(22, 33, 106, 21);
		add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setText("\uAC00\uACA9");
		textField_2.setBounds(155, 33, 106, 21);
		add(textField_2);
		textField_2.setColumns(10);
		
		JButton btnNewButton = new JButton("\uBA54\uB274 \uC218\uC815");
		btnNewButton.addActionListener(new ButtonClickListener ());
		btnNewButton.setBounds(293, 31, 95, 23);
		add(btnNewButton);
		
		textField_3 = new JTextField();
		textField_3.setText("\uBA54\uB274 \uC774\uB984");
		textField_3.setBounds(22, 64, 106, 21);
		add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setText("\uAC00\uACA9");
		textField_4.setBounds(155, 64, 106, 21);
		add(textField_4);
		textField_4.setColumns(10);
		
		textField_5 = new JTextField();
		textField_5.setText("\uBA54\uB274 \uC774\uB984");
		textField_5.setBounds(22, 95, 106, 21);
		add(textField_5);
		textField_5.setColumns(10);
		
		textField_6 = new JTextField();
		textField_6.setText("\uAC00\uACA9");
		textField_6.setBounds(155, 95, 106, 21);
		add(textField_6);
		textField_6.setColumns(10);
		
		btnNewButton_1 = new JButton("\uBA54\uB274 \uC0AD\uC81C");
		btnNewButton_1.setBounds(293, 64, 95, 23);
		btnNewButton_1.addActionListener(new ButtonClickListener1 ());
		add(btnNewButton_1);
		
		btnNewButton_2 = new JButton("\uBA54\uB274 \uCD94\uAC00");
		btnNewButton_2.setBounds(293, 94, 95, 23);
		btnNewButton_2.addActionListener(new ButtonClickListener2 ());
		add(btnNewButton_2);
		
		btnNewButton_3 = new JButton("\uBA54\uB274 \uD655\uC778");
		btnNewButton_3.setBounds(95, 126, 95, 23);
		btnNewButton_3.addActionListener(new ButtonClickListener3 ());
		add(btnNewButton_3);
		
		btnNewButton_4 = new JButton("\uC885\uB8CC\uD558\uAE30");
		btnNewButton_4.setBounds(231, 126, 95, 23);
		btnNewButton_4.addActionListener(new ButtonClickListener4 ());
		add(btnNewButton_4);
		
		list = new JList<String>(orderList);
		list.setBounds(411, 35, 156, 359);
		add(list);

		t1 = new TCPServerThreadOrder(ussocket, orderList, list);
		
		textPane = new JTextPane();
		textPane.setBounds(22, 157, 366, 237);
		add(textPane);
		t2 = new TCPServerThreadMenu(ussocket, service);
		t1.start();
		t2.start();

	}
	
	class ButtonClickListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String menuName= textField_1.getText();
			int menuPrice = Integer.parseInt(textField_2.getText());
			boolean success = service.menuEdit(menuName, menuPrice);
			if (success == true) {
				JOptionPane.showMessageDialog(null, "메뉴를 수정하였습니다.");
				t2.resume();
			} else {
				JOptionPane.showMessageDialog(null, "수정하려는 메뉴가 없습니다.");
			}
		}
	}
	
	class ButtonClickListener1 implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String menuName= textField_3.getText();
			int menuPrice = Integer.parseInt(textField_4.getText());
			boolean success = service.menuDelete(menuName, menuPrice);
			if (success == true) {
				JOptionPane.showMessageDialog(null, "메뉴를 삭제하였습니다.");
				t2.resume();
			} else {
				JOptionPane.showMessageDialog(null, "삭제하려는 메뉴가 없습니다.");
			}
		}
	}
	
	class ButtonClickListener2 implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String menuName= textField_5.getText();
			int menuPrice = Integer.parseInt(textField_6.getText());
			boolean success = service.menuRegister(menuName, menuPrice);
			if (success == true) {
				JOptionPane.showMessageDialog(null, "메뉴를 추가하였습니다.");
				t2.resume();
			}else {
				JOptionPane.showMessageDialog(null, "오류가 발생하였습니다.");
			}
		}
	}
	
	class ButtonClickListener3 implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String str = service.viewAll();
			textPane.setText(str);
		}
	}
	
	class ButtonClickListener4 implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			new MainFrame();
			setVisible(false);
		}
	}
}
