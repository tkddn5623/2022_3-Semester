
public class Client {

	private static Client client = new Client();
	private int money;
	
	private Client() {}
	
	public int getMoney() {
		return money;
	}
	
	public void setMoney(int money) {
		this.money = money;
	}
	
	public void addMoney(int money) {
		this.money += money;
	}
	
	public static Client getInstance() {
		return client;
	}
	
}
