
import java.util.*;

public class CoffeeServiceImpl implements CoffeeService{
	public HashSet<Coffee> coffeeMenu;
	
	public CoffeeServiceImpl() {
		coffeeMenu = new HashSet<Coffee>();
		coffeeMenu.add(new Coffee("아메리카노", 2000));
		coffeeMenu.add(new Coffee("카페라떼", 3000));
	}
	public HashSet<Coffee> getMenu() {
		return coffeeMenu;
	}
	
	@Override
	public String viewAll() {
		String str = "";
		Iterator<Coffee> iter = coffeeMenu.iterator();
		while(iter.hasNext()) {
			Coffee coffee = iter.next();
			str += coffee.getName() + " : " + coffee.getPrice() + "원" + "  ";
		}
		return str;
	}

	@Override
	public boolean menuRegister(String menuName, int menuPrice) {
		coffeeMenu.add(new Coffee(menuName, menuPrice));
		return true;
	}

	@Override
	public boolean menuEdit(String menuName, int menuPrice) {
		Iterator<Coffee> iter = coffeeMenu.iterator();
		while(iter.hasNext()) {
			Coffee edit = iter.next();
			if(edit.getName().equals(menuName)) {
				coffeeMenu.remove(edit);
				coffeeMenu.add(new Coffee(menuName, menuPrice));
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean menuDelete(String menuName, int menuPrice) {
		Iterator<Coffee> iter = coffeeMenu.iterator();
		while(iter.hasNext()) {
			Coffee edit = iter.next();
			if(edit.getName().equals(menuName)) {
				coffeeMenu.remove(edit);
				return true;
			}
		}
		return false;
	}
}
