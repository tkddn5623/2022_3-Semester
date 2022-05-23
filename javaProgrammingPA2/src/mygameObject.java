
public class mygameObject extends gameObject {
	private String str;
	public mygameObject(int x, int y, char type, char color, char target) {
		super(x, y, type, color, target);
		str = "" + getColor() + getType() + getTarget();
	}
	public String Name() {
		return str;
	}
}
