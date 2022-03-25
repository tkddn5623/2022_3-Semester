import java.util.Scanner;
public class week1 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int num = scn.nextInt();
		int temp = 1;
		int[] num1 = new int[31];
		System.out.print("b ");
		for (int i = 0; i < 31; i++) {
			if(i == 0) {
				temp = num;
			}
			num1[i] = temp % 2;
			if(temp/2 == 0) {
				for(int j = i; j >= 0; j--) {
					System.out.print(num1[j]);
				}
				break;
			}
			else {
				temp = temp / 2;
			}
		}
		System.out.println("");
		System.out.print("o ");
		for (int i = 0; i < 31; i++) {
			if(i == 0) {
				temp = num;
			}
			num1[i] = temp % 8;
			if(temp/8 == 0) {
				for(int j = i; j >= 0; j--) {
					System.out.print(num1[j]);
				}
				break;
			}
			else {
				temp = temp / 8;
			}
				
		}
		System.out.println("");
		System.out.print("h ");
		for (int i = 0; i < 31; i++) {
			if(i == 0) {
				temp = num;
			}
			num1[i] = temp % 16;
			if(temp/16 == 0) {
				for(int j = i; j >= 0; j--) {
					if(num1[j] < 10) {
						System.out.print(num1[j]);
					}
					else if(num1[j] == 10) {
						System.out.print("a");
					}
					else if(num1[j] == 11) {
						System.out.print("b");
					}
					else if(num1[j] == 12) {
						System.out.print("c");
					}
					else if(num1[j] == 13) {
						System.out.print("d");
					}
					else if(num1[j] == 14) {
						System.out.print("e");
					}
					else if(num1[j] == 15) {
						System.out.print("f");
					}
				}
				break;
			}
			else {
				temp = temp / 16;
			}
				
		}
		
		
		scn.close();
	}
}
