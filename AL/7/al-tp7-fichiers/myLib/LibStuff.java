package myLib;

public class LibStuff {
	public LibStuff(int par) {
		// Info:"Creating a Stuff with "+par
		// ...
	}

	public void doSomething() {
		// Info:"Doing something on : "+this
		// ...
		// Info:"Something done!"
	}

	public void finalize() {
		// Info:"This stuff is dying :"+this;
	}
}