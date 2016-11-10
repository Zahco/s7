package Singleton.myLib;

public class LogFile extends Log {
	
	synchronized public static void setInstance(String filename) {
		instance = new LogFile(filename);
	}
	
	private String filename;
	
	protected LogFile (String filename) {
		this.filename = filename;
	}
	
	protected void sendMessage(String message) {
		++logCount;
		System.out.println("[" + filename + "]:" + prefixeWithCount(message));
	}
}