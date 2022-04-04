
public class StringMethod {
	// Returns the string created by adding 's2' after position 'index' of 's1'.
	static String addString(String s1, int index, String s2) {
		if(index < 0)
			return s2 + s1;
		else if (index >= s1.length())
			return s1 + s2;
		else {
			String s3 = s1.substring(0, index + 1);
			s3 = s3.concat(s2);
			s3 = s3.concat(s1.substring(index + 1, s1.length()));
			return s3;
		}
	}
	// Returns reversed string of 's'
	static String reverse(String s) {
		String s1 = "";
		for(int i = s.length() - 1; i >= 0; i--) 
			s1 = s1 + s.charAt(i);	
		return s1;
	}
	// Returns a string with all 's2's removed from 's1'
	static String removeString(String s1, String s2) {
		if(s1.length() < s2.length() || s2.length() == 0)
			return s1;
		else 
			for(int i = 0; i + s2.length() <= s1.length(); i++)
				if(s1.substring(i, i + s2.length()).equals(s2)) 
					return removeString(s1.substring(0, i) + s1.substring(i + s2.length(), s1.length()), s2);
			return s1;
		
	}
	public static void main(String[] args) {
		System.out.println(addString("0123456", 3, "-"));
		System.out.println(reverse("abc"));
		System.out.println(removeString("01001000", "00"));

	}

}
