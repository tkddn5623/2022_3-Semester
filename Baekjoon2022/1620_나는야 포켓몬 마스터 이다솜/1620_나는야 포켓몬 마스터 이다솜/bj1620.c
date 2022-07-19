#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x, y;
	char input[100];
	scanf("%d%d", &x, &y);
	
	for (int i = 1; i <= x; i++) {
		//Begin writing codes form here
	}
	for (int i = 0; i < y; i++) {
		//Begin writing codes form here
	}
}
/* 
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
*/