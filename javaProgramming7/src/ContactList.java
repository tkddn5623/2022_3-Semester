import java.util.Scanner;
public class ContactList {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Contacts contacts = new Contacts();

		while (true) {
			System.out.println("Please enter the command");
			String userCommand = scan.nextLine();
			String[] inputs = userCommand.split(" ");
			if (inputs[0].equals("show")) {
				if (inputs.length != 1) System.out.println("Invalid command");
				else contacts.show();
			}
			else if (inputs[0].equals("find")){
				if (inputs.length != 2) System.out.println("Invalid command");
				else contacts.find(inputs[1]);
			}
			else if (inputs[0].equals("add")){
				if (inputs.length != 3) System.out.println("Invalid command");
				else contacts.add(inputs[1], inputs[2]);
			}
			else if (inputs[0].equals("delete")){
				if (inputs.length != 2) System.out.println("Invalid command");
				else contacts.delete(inputs[1]);
			}
			else if (inputs[0].equals("end")) break;
		}
		scan.close(); //close scanner
	}
}
