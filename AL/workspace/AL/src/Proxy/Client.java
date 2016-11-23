package Proxy;

public class Client {
	public static void main(String args[]) {
		IMatrix m = new Matrix(2,2,0);
		IMatrix cowm = new COWMatrix(m);
		System.out.println("Get");
		cowm.get(0, 0);
		System.out.println("Set");
		cowm.set(0, 0, 1);
		cowm.set(0, 0, 2);
	}
}
