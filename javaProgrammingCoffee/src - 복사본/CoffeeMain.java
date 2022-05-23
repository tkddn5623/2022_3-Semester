
import java.util.*;

public class CoffeeMain {

	public static void main(String[] args) {
	
		CoffeeService service = new CoffeeServiceImpl();
		
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			
			System.out.println("(1)�մ� (2)Ŀ�Ǽ���� (3)���α׷� ����");
			int choice = scan.nextInt();
			
			if(choice == 1) {
				
				Loop1 : while(true) { // while�� �̸� ����
					
					System.out.println();
					System.out.println("########## Ŀ�Ǽ� �ֹ��ϱ� ##########");
					System.out.println("##  1. ��ü�޴� ���� 2. ������  ##");
					System.out.println("##  3. �ֹ��ϱ� 4. �ܾ׺��� 5. ������  ##");
					System.out.println("############################");
					System.out.println();
					System.out.print("�޴��� �Է��ϼ��� : ");
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
						System.out.println("������ �� ������~");
						break Loop1;
						default : 
							System.out.println("�߸� �Է��Ͽ����ϴ�.");
							continue;
					}
					
				}
				
			}else if(choice == 2) {
				
				Loop2 : while(true) {
					
					System.out.println();
					System.out.println("########## Ŀ�Ǽ� ���� ���α׷� ##########");
					System.out.println("##  1. Ŀ�Ǹ޴� ���� 2. Ŀ�Ǹ޴� ���  ##");
					System.out.println("##  3. �޴����� 4. �޴����� 5. ������  ##");
					System.out.println("###############################");
					System.out.println();
					System.out.println("�޴��� �Է��ϼ��� : ");
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
						System.out.println("�˹����� ���Ը� �ñ�� �����ϴ�.");
						break Loop2;
						default : 
							System.out.println("�߸��Է� �Ͽ����ϴ�.");
							continue;
					}
				}
			}else if(choice == 3) {
				System.out.println("���α׷��� �����մϴ�");
				System.exit(0);
			}else {
				System.out.println("�߸� �Է��Ͽ����ϴ�.");
			}
		}

	}

}
