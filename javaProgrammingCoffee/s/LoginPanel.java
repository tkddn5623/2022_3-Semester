import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;

import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.SwingConstants;
import javax.swing.JCheckBox;
import javax.swing.JButton;

public class LoginPanel extends JPanel {
	private int branch;
	private String id;
	private String password;
	private LoginPanel self;
	private JPanel northPanel;
	private JPanel centerPanel;
	private JPanel centerPanel_1;
	private JPanel centerPanel_2;
	private JPanel centerPanel_3;
	private JPanel southPanel;
	private JPanel eastPanel;
	private JLabel titleLabel;
	private JLabel msgLabel;
	private JLabel idLabel;
	private JLabel pwLabel;
	private JTextField idField;
	private JPasswordField pwField;
	private JCheckBox checkBox;
	private JButton button;
	public LoginPanel() {
		setBorder(new EmptyBorder(5, 5, 5, 5)); //Setting Design
		setLayout(new BorderLayout(10, 10));
		
		self = this; // Initialization variables
		id = "admin";
		password = "1234";
		
		northPanel = new JPanel(); // Declaring and adding: Panels
		centerPanel = new JPanel();
		centerPanel_1 = new JPanel(new GridLayout(1,2));
		centerPanel_2 = new JPanel(new GridLayout(1,2));
		centerPanel_3 = new JPanel(new GridLayout(3,1));
		southPanel = new JPanel();
		eastPanel = new JPanel(new BorderLayout(5,5));
		
		northPanel.setPreferredSize(new Dimension(50,120)); // Panels Setting size (design)
		northPanel.setLayout(new BorderLayout(0, 0));
		centerPanel.setLayout(new GridLayout(3,1));
		centerPanel.setBorder(new EmptyBorder(5, 55, 5, 5));
		southPanel.setPreferredSize(new Dimension(50,120));
		
		add(northPanel, BorderLayout.NORTH);
		add(centerPanel, BorderLayout.CENTER);
		centerPanel.add(centerPanel_1);
		centerPanel.add(centerPanel_2);
		centerPanel.add(centerPanel_3);
		add(southPanel, BorderLayout.SOUTH);
		add(eastPanel, BorderLayout.EAST);

		titleLabel = new JLabel("Cafe Application"); //Title: Welcome message
		msgLabel = new JLabel("Please sign in!");    //Login Message
		titleLabel.setVerticalAlignment(SwingConstants.BOTTOM);
		titleLabel.setHorizontalAlignment(SwingConstants.CENTER);
		titleLabel.setFont(new Font("Consolas", Font.PLAIN, 30));
		northPanel.add(titleLabel, BorderLayout.CENTER);
		southPanel.add(msgLabel);
		
		idLabel = new JLabel("NAME  ");
		idField = new JTextField();
		pwLabel = new JLabel("PW  ");
		pwField = new JPasswordField();
		checkBox = new JCheckBox("Sign in as Manager");
		button = new JButton("Sign in");
		idLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		pwLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		checkBox.setHorizontalAlignment(SwingConstants.RIGHT);
		centerPanel_1.add(idLabel);
		centerPanel_1.add(idField);
		centerPanel_2.add(pwLabel);
		centerPanel_2.add(pwField);
		centerPanel_2.setVisible(false);
		centerPanel_3.add(checkBox);
		eastPanel.add(button);
		checkBox.addActionListener(new CheckBoxListener());
		button.addActionListener(new SigninListener());
		setVisible(true);

	}
	public String getID() {
		return idField.getText();
	}
	public int getBranch() {
		return branch;
	}
	class CheckBoxListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			if(checkBox.isSelected()) {
				centerPanel_2.setVisible(true);
				idLabel.setText("ID  ");
			}
			else {
				centerPanel_2.setVisible(false);
				idLabel.setText("NAME  ");
				pwField.setText("");
				msgLabel.setText("Please sign in!");
			}
		}
	}
	class SigninListener implements ActionListener {
		public void actionPerformed (ActionEvent e) {
			if(checkBox.isSelected()) { //Try login as the Manager
				String tempID = self.getID();
				String tempPW = new String(pwField.getPassword());
				if(!(tempID.equals(id) && tempPW.contentEquals(password))) {
					msgLabel.setText("관리자가 아닙니다.");
				}
				else {
					self.branch = 2; // As the Manager
					self.setVisible(false);
					self.removeAll();
				}
			}
			else{                    //Try login as a Customer
				if(12 < self.getID().length() || self.getID().length() < 4)
					msgLabel.setText("아이디는 4글자 이상 12글자 이하로 설정해주세요.");
				else {
					self.branch = 1; // As a Customer
					self.setVisible(false);
					self.removeAll();
				}
			}
		}
	}
}