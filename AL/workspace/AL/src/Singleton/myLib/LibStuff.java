package Singleton.myLib;

public class LibStuff {
	public LibStuff() {
		// Info:"Creating a Stuff with "+par
		// ...
		Log.getInstance().sendInfo("Creating a stuff.");
	}

	public void doSomething(int action) {
		// Info:"Doing something on : "+this
		// ...
		// Info:"Something done!"
		Log.getInstance().sendInfo("Doing something on: " + this);
		Log.getInstance().sendInfo("Something done!");
	}

	public void finalize() {
		// Info:"This stuff is dying :"+this;
		Log.getInstance().sendInfo("This stuff is dying: " + this);
	}
}