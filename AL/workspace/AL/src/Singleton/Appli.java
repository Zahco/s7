package Singleton;
import Singleton.myLib.*;

public class Appli {
	private LibStuff stuff;

	public void initApp() {
		// Info:"Initializing App..."
		Log.getInstance().sendInfo("Initializing App...");
		// ... some code here
		stuff= new LibStuff();
		// Info:"Initialization done!"
		Log.getInstance().sendInfo("Initialization done !");
	}

	public void closeApp() {
		// Info:"Closing app..."
		Log.getInstance().sendInfo("Closing app...");
		// ... some code here
		// Info:"Ressources freeed!"
		Log.getInstance().sendInfo("Ressources freeed !");
	}

	public void run() {
		boolean errors=false;
		for(int i=0; i<10; ++i) {
			int action = (int)(100.0*Math.random());
			if (action<50) {
				stuff.doSomething(action);
			} else {
				// Error:"Invalide action : "+action
				Log.getInstance().sendError("Invalide action: " + action);
				errors=true;
			}
		}
		if (errors) {
			// Warning : some errors occured during processing.
			Log.getInstance().sendWarning("Some errors occured during processing.");
		}
	}

	public static void main(String[] args) {
		LogFile.setInstance("logger.log");
		Appli app=new Appli();
		app.initApp();
		app.run();
		app.closeApp();
	}
}