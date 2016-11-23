package Proxy;

public interface IMatrix {
	public int getSizeM();
	public int getSizeN();
	public int get(int m, int n);
	public void set(int m, int n, int val);
}
