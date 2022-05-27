import java.io.Serializable;

public class Coffee implements Serializable{
	private String name;
	private int price;
	public Coffee(String coffeeName) {
		this.name = coffeeName;
		this.price = 2000;
	}
	public Coffee(String name, int price) {
		this.name = name;
		this.price = price;
	}
	public int getPrice() {
		return price;
	}
	public String getName() {
		return name;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	public void setName(String coffeeName) {
		this.name = coffeeName;
	}
	public String toString() {
		return name;
	}

	
	public boolean equals(Object obj) {
		if(obj instanceof Coffee) 
			return ((Coffee)obj).getName() == name;
		else return false;
	}
}
