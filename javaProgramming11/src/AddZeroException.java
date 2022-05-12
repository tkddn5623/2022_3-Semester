
public class AddZeroException extends Exception {
	private String Message = "";
	AddZeroException(){
		Message = "Adding zero is not allowed!";
	}

	@Override
	public String toString() {
		return "OutOfRangeException [Message=" + Message + "]";
	}
}