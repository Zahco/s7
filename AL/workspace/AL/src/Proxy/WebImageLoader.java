package Proxy;

public class WebImageLoader implements IWebImage {
	// url de l'image :
	private final String _URL;
	
	private IWebImage wi;

	public WebImageLoader(String URL) {
		_URL = URL;
	}

	public synchronized void display(int length, int height) {
		if (wi == null) {
			wi = new WebImage(_URL);
		}
		wi.display(length, height);
	}
}

