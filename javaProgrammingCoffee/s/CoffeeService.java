import java.util.HashSet;

public interface CoffeeService {
	public HashSet<Coffee> getMenu();
	public abstract String viewAll();
	public abstract boolean menuRegister(String menuName, int menuPrice);
	public abstract boolean menuDelete(String menuName, int menuPrice);
	public abstract boolean menuEdit(String menuName, int menuPrice);
	
}
