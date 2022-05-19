import java.awt.event.ContainerEvent;
import java.awt.event.ContainerListener;
import javax.swing.JFrame;

public class MainFrame extends JFrame {
	private LoginPanel loginPanel;
	private CustomerPanel customerPanel;
	private ManagerPanel managerPanel;

	public MainFrame() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 640, 480);
		StartLogin(); ///////////////////////////////////////////////////////////////¡ÚLOGIN¡Ú////
		setVisible(true);
	}
	public void StartLogin() {
		setTitle("Cafe application - Welcome");
		loginPanel = new LoginPanel();
		add(loginPanel);
		loginPanel.addContainerListener(new LoginListner());
	}
	public void StartCustomer(String name) {
		setTitle("Logged as " + name);
		customerPanel = new CustomerPanel(name);
		add(customerPanel);
		remove(loginPanel);
	}
	public void StartManager() {
		setTitle("Logged as Manager");
		managerPanel = new ManagerPanel();
		add(managerPanel);
		remove(loginPanel);
	}
	class LoginListner implements ContainerListener{
		public void componentAdded(ContainerEvent e) {}
		public void componentRemoved(ContainerEvent e) {
			if(customerPanel == null && managerPanel == null) {
				if(loginPanel.getBranch() == 1) 
					StartCustomer(loginPanel.getID()); /////////////////////////////¡ÚCustomer¡Ú///
				else if(loginPanel.getBranch() == 2) 
					StartManager(); ////////////////////////////////////////////////¡ÚManager¡Ú////
			}
		}
	}
}
