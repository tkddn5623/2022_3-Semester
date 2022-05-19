import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;

public class ManagerPanel extends JPanel {
	public ManagerPanel() {
		setBorder(new EmptyBorder(5, 5, 5, 5));
		setLayout(new BorderLayout(10, 10));
		
		setBackground(Color.PINK); //JUST FOR TESTING
	}
}
