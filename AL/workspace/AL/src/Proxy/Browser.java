package Proxy;

import java.util.ArrayList;
import java.util.List;

public class Browser {
	List<IWebImage> images;
	
	public void loadPage() {
		images = new ArrayList<IWebImage>();
		for (int i = 0; i < 50; ++i) {
			images.add(new WebImageLoader("http://image.com/image-" + i + ".png"));
		}
		System.out.println("Done");
	}
	
	public void showPage() {
		for (int i = 0; i < 5; ++i) {
			images.get(i).display(320, 200);
		}
	}
}
