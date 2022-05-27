
public class Client {

	private static Client client = new Client();
	private int money;
	private String name; //20220524 added
	private Client() {
	}
	public Client(String name) { //20220524 added
		this.name = name;
	}
	
	public int getMoney() {
		return money;
	}
	public String getName() { //20220524 added
		return name;
	}
	public String toString() { //20220524 added
		return name;
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
