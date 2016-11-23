package Proxy;

public class COWMatrix implements IMatrix {

	private IMatrix matrix;
	private boolean readyToClone;
	
	public COWMatrix(int m, int n, int val) {
		readyToClone = false;
		matrix = new Matrix(m, n, val);
	}
	public COWMatrix(IMatrix m) {
		readyToClone = true;
		matrix = m;
	}
	@Override
	public int get(int m, int n) {
		return matrix.get(m, n);
	}

	@Override
	public void set(int m, int n, int val) {
		if (readyToClone) {
			matrix = new Matrix(matrix);
			readyToClone = false;
		}
		matrix.set(m, n, val);
	}
	@Override
	public int getSizeM() {
		return matrix.getSizeM();
	}
	@Override
	public int getSizeN() {
		return matrix.getSizeN();
	}

}
