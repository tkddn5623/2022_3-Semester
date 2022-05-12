
public class OutOfRangeException extends Exception {
	private String Message = "";
	OutOfRangeException(int val){
		if(val > 1000)
			Message = "Result cannot be bigger than 1000!";
		else if(val < 0)
			Message = "Result cannot be smaller than 0!";
	}
	OutOfRangeException(int val, String str){
		if(val > 1000)
			Message = str + " - " + "Result is bigger than 1000!";
		else if(val < 0)
			Message = str + " - " + "Result is smaller than 1000!";
	}
	@Override
	public String toString() {
		return "OutOfRangeException [Message=" + Message + "]";
	}
}
