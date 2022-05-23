
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
	
	// get set 메소드
	// equals hashCode 오버라이딩해서 재정의하자
	
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
