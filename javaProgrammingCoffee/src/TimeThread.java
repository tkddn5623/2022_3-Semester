import javax.swing.JLabel;
import java.util.Calendar;

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
			timeStr = strAMPM() + " " + cal.get(cal.HOUR) + " : " + cal.get(cal.MINUTE) + " : " + cal.get(cal.SECOND);
			clock.setText(timeStr);
			try {
				t.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	private String strAMPM() {
		if(cal.get(cal.AM_PM) == 0) return "AM";
		else return "PM";
	}
}
