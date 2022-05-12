
import java.util.*;

public class CoffeeMain {

	public static void main(String[] args) {
	
		CoffeeService service = new CoffeeServiceImpl();
		
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			
			System.out.println("(1)손님 (2)커피숍사장 (3)프로그램 종료");
			int choice = scan.nextInt();
			
			if(choice == 1) {
				
				Loop1 : while(true) { // while문 이름 지정
					
					System.out.println();
					System.out.println("########## 커피숍 주문하기 ##########");
					System.out.println("##  1. 전체메뉴 보기 2. 돈충전  ##");
					System.out.println("##  3. 주문하기 4. 잔액보기 5. 나가기  ##");
					System.out.println("############################");
					System.out.println();
					System.out.print("메뉴를 입력하세요 : ");
					int choice1 = scan.nextInt();
					
					switch(choice1) {
					case 1 : 
						service.viewAll();
						break;
					case 2 :
						service.chargeMoney();
						break;
					case 3 :
						service.order();
						break;
					case 4 :
						service.showMoney();
						break;
					case 5 :
						System.out.println("다음에 또 오세요~");
						break Loop1;
						default : 
							System.out.println("잘못 입력하였습니다.");
							continue;
					}
					
				}
				
			}else if(choice == 2) {
				
				Loop2 : while(true) {
					
					System.out.println();
					System.out.println("########## 커피숍 관리 프로그램 ##########");
					System.out.println("##  1. 커피메뉴 보기 2. 커피메뉴 등록  ##");
					System.out.println("##  3. 메뉴수정 4. 메뉴삭제 5. 나가기  ##");
					System.out.println("###############################");
					System.out.println();
					System.out.println("메뉴를 입력하세요 : ");
					int choice2 = scan.nextInt();
					
					switch(choice2) {
					case 1 : 
						service.viewAll();
						break;
					case 2 : 
						service.menuRegister();
						break;
					case 3 :
						service.menuEdit();
						break;
					case 4 :
						service.menuDelete();
						break;
					case 5 :
						System.out.println("알바한테 가게를 맡기고 나갑니다.");
						break Loop2;
						default : 
							System.out.println("잘못입력 하였습니다.");
							continue;
					}
				}
			}else if(choice == 3) {
				System.out.println("프로그램을 종료합니다");
				System.exit(0);
			}else {
				System.out.println("잘못 입력하였습니다.");
			}
		}

	}

}
