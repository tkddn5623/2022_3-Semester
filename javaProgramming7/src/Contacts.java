import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Contacts {
	public HashMap<String,String> listOfContacts;
	private String pattern1 = "^[0-9]{3}-[0-9]{4}-[0-9]{4}$";
	public Contacts() {
		listOfContacts = new HashMap<String,String>();
	}
	public boolean isPhoneNumber(String phoneNumber) {
		if(!Pattern.matches(pattern1, phoneNumber))
			return false;
		else
			return true;
	}
	public boolean add(String s1, String s2) {
		if(!isPhoneNumber(s1) && !isPhoneNumber(s2)) {
			System.out.println("Invalid syntax: Please check again the syntax of your phone number");
			return false;
		}
		
		String phone = s1, name = s1;
		if(isPhoneNumber(s1)) name = s2;
		else phone = s2;
		
		listOfContacts.put(name, phone);
		System.out.println("Successfully added");
		return true; 
	}
	public void show() {
		for (Map.Entry<String, String> x : listOfContacts.entrySet()) 
			System.out.printf("%-15s %s\n", x.getKey(), x.getValue());
	}
	public void find(String string) { 
		for (Map.Entry<String, String> x : listOfContacts.entrySet()) 
			if(string.equals(x.getKey())) {
				System.out.println(x.getValue());
				break;
			}
			else if(string.equals(x.getValue()))
				System.out.println(x.getKey());
	}
	public void delete(String string) {
		for (Map.Entry<String, String> x : listOfContacts.entrySet()) 
			if(string.equals(x.getKey()) || string.equals(x.getValue())) {
				System.out.println("Deleted Successfully!");
				listOfContacts.remove(x.getKey());
				return;
			}
		System.out.println("No matching delete data");
	}
}