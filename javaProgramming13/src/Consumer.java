//import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Consumer extends Thread {
	private Thread t; 
	private BlockingQueue<Integer> queue;
	private int count;
	int value;
	
	Consumer(BlockingQueue<Integer> queue){
		count = 0;
		this.queue = queue;
	}
	/* start() will call run() automatically */
	public void run() {
		while(count < 10) {
			if(queue.size() > 0) {
				try {
					System.out.println("Consumed: " + (value = queue.take()));
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				count++;
			}
			try {
				t.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

	} 
	public void start () {  
		if (t == null) { 
			t = new Thread (this); 
			t.start (); 
		} 
	} 

}