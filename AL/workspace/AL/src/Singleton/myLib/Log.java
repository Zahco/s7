package Singleton.myLib;

public class Log {
	
	protected static Log instance;
	
	protected int logCount;
	
	synchronized public static Log getInstance() {
		if (instance == null) {
			instance = new Log();
		}
		return instance;
	}
	
	protected Log() {
		logCount = 0;
	}

	public void sendInfo(String message) {
		sendMessage("[INFO] " + message);
	}
	public void sendWarning(String message) {
		sendMessage("[WARNING] " + message);
	}
	public void sendError(String message) {
		sendMessage("[ERROR] " + message);
	}
	
	protected String prefixeWithCount(String message) {
		return "[" + logCount + "]" + message;
	}
	
	protected void sendMessage(String message) {
		++logCount;
		System.out.println(prefixeWithCount(message));
	}
}