import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class TestThread {
	
	public static void main(String[] args) {
		BlockingQueue<Integer> queue;
		queue = new ArrayBlockingQueue<Integer>(5);

		
		Producer producer = new Producer(queue);
		producer.start();
		Consumer consumer = new Consumer(queue);
		consumer.start();
	}

}