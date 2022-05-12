
public class Coffee {

	private String coffeeName;
	
	public Coffee(String coffeeName) {
		this.coffeeName = coffeeName;
	}

	public String getCoffeeName() {
		return coffeeName;
	}

	public void setCoffeeName(String coffeeName) {
		this.coffeeName = coffeeName;
	}
	
	// get set �޼ҵ�
	// equals hashCode �������̵��ؼ� ����������
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Coffee) {
			Coffee coffee = (Coffee)obj;
			return coffee.coffeeName == coffeeName;
		}else {
			return false;
		}
	}
	
	public int hashCode() {
		return coffeeName.hashCode();
	}
	
}
