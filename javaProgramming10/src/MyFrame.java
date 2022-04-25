import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class MyFrame extends JFrame {
	String id = "test";
	String password = "12345678"; // to compare
	JTextField textField1;
	JPasswordField textField2;
	
	MyFrame() {
		setTitle("Login");
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new GridLayout(3,1));
		// implement your code
		setSize(400, 150);
		
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		JPanel panel3 = new JPanel(new BorderLayout());
		
		JLabel label1 = new JLabel("ID: ");
		JLabel label2 = new JLabel("Password: ");
		
		textField1 = new JTextField(20);
		textField2 = new JPasswordField(20);
		JButton button = new JButton("login");
		button.addActionListener(new ButtonClickListener ());
		add(panel1);
		add(panel2);
		add(panel3);
		
		label1.setPreferredSize(new Dimension(80,10));
		label2.setPreferredSize(new Dimension(80,10));
		
	    panel1.add(label1);
		panel1.add(textField1);
		
		panel2.add(label2);
		panel2.add(textField2);
		
		panel3.add(button);
		

		pack(); // to combine
		setVisible(true);
	}
	class ButtonClickListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			String tempId = textField1.getText();
			String tempPassword = new String(textField2.getPassword());
			if (tempId.equals(id) && tempPassword.contentEquals(password)) {
				JOptionPane.showMessageDialog(null, "Success");
			} else {
				JOptionPane.showMessageDialog(null, "Fail");
			}
		}
	}
}

