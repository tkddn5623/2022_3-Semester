
public class SubtractZeroException extends Exception {
	private String Message = "";
	SubtractZeroException(){
		Message = "Subtracting zero is not allowed!";
	}

	@Override
	public String toString() {
		return "OutOfRangeException [Message=" + Message + "]";
	}
}
