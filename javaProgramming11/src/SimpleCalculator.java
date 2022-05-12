
public class SimpleCalculator {
	private static int result = 2021313504;
	public static void add(int a, int b) throws OutOfRangeException, AddZeroException{
		int val = a + b;
		if(a == 0 || b == 0) 
			throw new AddZeroException();
		if(val < 0 || val > 1000) 
			throw new OutOfRangeException(val, "Add");
		result = val;
	}
	public static void subtract(int a, int b) throws OutOfRangeException, SubtractZeroException{
		int val = a - b;
		if(a == 0 || b == 0) 
			throw new SubtractZeroException();
		if(val < 0 || val > 1000) 
			throw new OutOfRangeException(val, "Sub");
		result = val;
	}
	public static void print() {
		System.out.println(getResult());
	}
	public static void reset() {
		result = 0;
	}
	public static int getResult() {
		return result; /*Don't modify*/
	}
	public static void setResult(int input) throws OutOfRangeException{
		if(input < 0 || input > 1000)
			throw new OutOfRangeException(input);
	}
	public static void main(String[] args) {
		try {
			add(1,0);
		} catch(OutOfRangeException e1) {
			System.out.println(e1);
		} catch (AddZeroException e2) {
			System.out.println(e2);
		}
		try {
			subtract(0,1);
		} catch(OutOfRangeException e1) {
			System.out.println(e1);
		} catch (SubtractZeroException e2) {
			System.out.println(e2);
		}
		try {
			add(999,2);
		} catch(OutOfRangeException e1) {
			System.out.println(e1);
		} catch (AddZeroException e2) {
			System.out.println(e2);
		}
		try {
			subtract(1002,1);
		} catch(OutOfRangeException e1) {
			System.out.println(e1);
		} catch (SubtractZeroException e2) {
			System.out.println(e2);
		}
		try {
			setResult(1001);
		} catch(OutOfRangeException e1) {
			System.out.println(e1);
		}
		System.out.println("result = " + getResult());
	}
}
