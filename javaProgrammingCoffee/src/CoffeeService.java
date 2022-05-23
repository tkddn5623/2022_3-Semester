
public interface CoffeeService {

	public abstract String viewAll();
	
	public abstract boolean menuRegister(String menuName, String menuPrice);
	
	public abstract boolean menuDelete(String menuName, String menuPrice);
	
	public abstract void chargeMoney();
	
	public abstract void order();
	
	public abstract void showMoney();

	public abstract boolean menuEdit(String menuName, String menuPrice);
	
}
