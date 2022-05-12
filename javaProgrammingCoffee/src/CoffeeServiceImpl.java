
import java.util.*;

public class CoffeeServiceImpl implements CoffeeService{

	HashMap<Coffee, Integer> map;
	
	Set<Client> set;
	
	Scanner scan;
	
	public CoffeeServiceImpl() {
		map = new HashMap<Coffee, Integer>();
		scan = new Scanner(System.in);
		set = new HashSet<Client>();
		map.put(new Coffee("아메리카노"), 2000);
		map.put(new Coffee("카페라떼"), 3000);
	}
	
	@Override
	public void viewAll() {
		// 커피메뉴 출력
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		while(keyIter.hasNext()) {
			Coffee coffee = keyIter.next();
			System.out.println(coffee.getCoffeeName() + " : " + map.get(coffee) + "원");
		}
	}

	@Override
	public void menuRegister() {
		// 메뉴이름과 메뉴가격을 입력받아 메뉴등록
		System.out.println("새로 등록하실 메뉴를 입력하세요 : ");
		String name = scan.next();
		System.out.println("새로 등록하실 메뉴의 가격을 입력하세요 : ");
		int price = scan.nextInt();
		map.put(new Coffee(name), price);
	}

	@Override
	public void menuEdit() {
		// 메뉴이름을 입력받아서 가격수정
		System.out.println("가격을 수정하실 메뉴를 입력하세요 : ");
		String name = scan.next();
		
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		
		while(keyIter.hasNext()) {
			Coffee edit = keyIter.next();
			if(edit.getCoffeeName().equals(name)) {
				System.out.println("수정하실 가격을 입력하세요 : ");
				int price = scan.nextInt();
				map.put(edit, price);
				System.out.println(name + "의 가격을 수정하였습니다.");
				return;
			}
		}
		System.out.println(name + "은(는) 메뉴에 없습니다.");
	}

	@Override
	public void menuDelete() {
		// 메뉴이름을 입력받아 메뉴삭제
		System.out.println("삭제하실 메뉴를 입력하세요 : ");
		String name = scan.next();
		
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		
		while(keyIter.hasNext()) {
			Coffee del = keyIter.next();
			if(del.getCoffeeName().equals(name)) {
				map.remove(del);
				System.out.println(name + " 메뉴를 삭제하였습니다.");
				return;
			}
		}
		System.out.println(name + "은(는) 메뉴에 없습니다.");
	}

	@Override
	public void chargeMoney() {
		// 금액을 입력받아 충전금 충전
		System.out.println("충전하실 금액을 입력하세요 : ");
		int money = scan.nextInt();
		Client client = Client.getInstance();
		client.addMoney(money);
		set.add(client);
		System.out.println(money + "원이 충전되었습니다.");
	}

	@Override
	public void order() {
		// 메뉴 이름을 입력받아 메뉴주문 (내 충전금에서 메뉴 가격만큼 차감)
		System.out.println("주문하실 메뉴를 입력하세요 : ");
		String name = scan.next();
		Set<Coffee> keySet = map.keySet();
		Iterator<Coffee> keyIter = keySet.iterator();
		Client client = Client.getInstance();
		while(keyIter.hasNext()) {
			Coffee coffee= keyIter.next();
			if(coffee.getCoffeeName().equals(name)) {
				if(client.getMoney() >= map.get(coffee)) {
					client.setMoney(client.getMoney()-map.get(coffee));
					System.out.println(name + "이(가) 주문되었습니다.");
					System.out.println("현재 잔액은 " + client.getMoney() + "원 입니다.");
					return;
				}else {
					System.out.println("충전 금액이 부족합니다.");
					return;
				}
			}
		}
	}

	@Override
	public void showMoney() {
		// 충전금 보기
		Iterator<Client> setIter = set.iterator();
		
		while(setIter.hasNext()) {
			Client client = setIter.next();
			int money = client.getMoney();
			System.out.println("현재 충전 잔액은 " + money + "원 입니다.");
			return;
		}
		System.out.println("충전금이 없습니다.\n충전을 해주세요.");
	}

	
	
}
