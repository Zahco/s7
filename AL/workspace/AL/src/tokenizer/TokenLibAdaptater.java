package tokenizer;

import java.util.Enumeration;
import java.util.Iterator;

public class TokenLibAdaptater<E> implements Iterator<E> {
	
	private Enumeration<E> enumE;
	
	public TokenLibAdaptater(Enumeration<E> enumE) {
		this.enumE = enumE;
	}

	@Override
	public boolean hasNext() {
		return enumE.hasMoreElements();
	}

	@Override
	public E next() {
		return enumE.nextElement();
	}

	@Override
	public void remove() {
	}
}
