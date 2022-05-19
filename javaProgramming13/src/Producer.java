import java.util.concurrent.BlockingQueue;

public class Producer extends Thread {
	private Thread t; 
	private int count;
	private BlockingQueue<Integer> queue;
	
	Producer(BlockingQueue<Integer> queue){
		count = 0;
		this.queue = queue;
	}
	/* start() will call run() automatically */
	public void run() {
		while(count < 10) {
			if(queue.remainingCapacity() > 0) {
				queue.add(count);
				System.out.println("Produced: " + count++);
			}
			try {
				t.sleep(300);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	/* start the thread */
	public void start () {  
		if (t == null) { 
			t = new Thread (this); 
			t.start (); 
		} 
	} 
}