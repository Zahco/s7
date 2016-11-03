package Composite;

import java.util.ArrayList;
import java.util.List;

public class Client {	
	public static void main(String[] args) {
		Section doc = new Section("coucou");
		IComponent p1 = new Paragraphe("un para");
		p1.setStyle(Style.BOLD);
		doc.addComponent(p1);
		doc.addComponent(new Paragraphe("deux para"));
		doc.addComponent(new Paragraphe("trois para"));
		List<String> liste = new ArrayList<String>();
		liste.add("item 1");
		liste.add("item 2");
		liste.add("item 3");
		doc.addComponent(new Liste(liste));
		doc.addComponent(new Figure("url_image"));
		System.out.println(doc.toStringHTML());
	}
}



