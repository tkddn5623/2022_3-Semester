
import java.util.*;

public class CoffeeServiceImpl implements CoffeeService{

	HashMap<Coffee, Integer> map;
	
	Set<Client> set;
	
	Scanner scan;
	
	public CoffeeServiceImpl() {
		map = new HashMap<Coffee, Integer>();
		scan = new Scanner(System.in);
		set = new HashSet<Client>();
		map.put(new Coffee("�Ƹ޸�ī��"), 2000);
		map.put(new Coffee("ī���"), 3000);
	}
	
	@Override
	public String viewAll() {
		// Ŀ�Ǹ޴� ���
		String str = "";
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		while(keyIter.hasNext()) {
			Coffee coffee = keyIter.next();
			str += coffee.getCoffeeName() + " : " + map.get(coffee) + "��" + " \n";
		}
		return str;
	}

	@Override
	public boolean menuRegister(String menuName, String menuPrice) {
		// �޴��̸��� �޴������� �Է¹޾� �޴����
		map.put(new Coffee(menuName), Integer.parseInt(menuPrice));
		return true;
	}

	@Override
	public boolean menuEdit(String menuName, String menuPrice) {
		// �޴��̸��� �Է¹޾Ƽ� ���ݼ���
		
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		
		while(keyIter.hasNext()) {
			Coffee edit = keyIter.next();
			if(edit.getCoffeeName().equals(menuName)) {
				map.put(edit, Integer.parseInt(menuPrice));
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean menuDelete(String menuName, String menuPrice) {
		// �޴��̸��� �Է¹޾� �޴�����
		
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		
		while(keyIter.hasNext()) {
			Coffee del = keyIter.next();
			if(del.getCoffeeName().equals(menuName)) {
				map.remove(del);
				return true;
			}
		}
		return false;
	}

	@Override
	public void chargeMoney() {
		// �ݾ��� �Է¹޾� ������ ����
		System.out.println("�����Ͻ� �ݾ��� �Է��ϼ��� : ");
		int money = scan.nextInt();
		Client client = Client.getInstance();
		client.addMoney(money);
		set.add(client);
		System.out.println(money + "���� �����Ǿ����ϴ�.");
	}

	@Override
	public void order() {
		// �޴� �̸��� �Է¹޾� �޴��ֹ� (�� �����ݿ��� �޴� ���ݸ�ŭ ����)
		System.out.println("�ֹ��Ͻ� �޴��� �Է��ϼ��� : ");
		String name = scan.next();
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		Client client = Client.getInstance();
		while(keyIter.hasNext()) {
			Coffee coffee= keyIter.next();
			if(coffee.getCoffeeName().equals(name)) {
				if(client.getMoney() >= map.get(coffee)) {
					client.setMoney(client.getMoney()-map.get(coffee));
					System.out.println(name + "��(��) �ֹ��Ǿ����ϴ�.");
					System.out.println("���� �ܾ��� " + client.getMoney() + "�� �Դϴ�.");
					return;
				}else {
					System.out.println("���� �ݾ��� �����մϴ�.");
					return;
				}
			}
		}
	}

	@Override
	public void showMoney() {
		// ������ ����
		Iterator<Client> setIter = set.iterator();
		
		while(setIter.hasNext()) {
			Client client = setIter.next();
			int money = client.getMoney();
			System.out.println("���� ���� �ܾ��� " + money + "�� �Դϴ�.");
			return;
		}
		System.out.println("�������� �����ϴ�.\n������ ���ּ���.");
	}	
	
}
