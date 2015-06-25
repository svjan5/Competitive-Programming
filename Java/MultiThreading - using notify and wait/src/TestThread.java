
public class TestThread {
	public static void main(String[] args) {
		Chat m = new Chat();
		new T2(m);
		new T1(m);
	}
}