import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String input;
		Map map1 = new HashMap<String, Integer>();
		Map map2 = new HashMap<Integer, String>();
		
		int x = scn.nextInt();
		int y = scn.nextInt();
		scn.nextLine();
		for(int i = 1; i <= x; i++) {
			input = scn.nextLine();
			map1.put(input, i);
			map2.put(i, input);
		}
		for(int i = 0; i < y; i++) {
			if(scn.hasNextInt()) System.out.println(map2.get(Integer.parseInt(scn.nextLine())));
			else System.out.println(map1.get(scn.nextLine()));
		}
	}

}
