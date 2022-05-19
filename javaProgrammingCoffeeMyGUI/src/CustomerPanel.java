import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;

public class CustomerPanel extends JPanel {
	private String name;
	public CustomerPanel(String name) {
		this.name = name;
		setBorder(new EmptyBorder(5, 5, 5, 5));
		setLayout(new BorderLayout(10, 10));
		
		setBackground(Color.CYAN); //JUST FOR TESTING
	}
}
