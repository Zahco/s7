package Composite;

import java.util.ArrayList;
import java.util.List;

public class Section implements IComponent {

	private String title;
	private List<IComponent> elements;
	
	public Section(String title) {
		this.title = title;
		elements = new ArrayList<IComponent>();
	}

	@Override
	public String toString() {
		String result = title;
		for (IComponent element : elements) {
			result += element.toString();
		}
		return result;
	}
	
	@Override
	public String toStringHTML() {
		String result = "<h1>" + title + "</h1>";
		for (IComponent element : elements) {
			result += element.toStringHTML();
		}
		return result;
	}

	@Override
	public void setStyle(Style s) {
		for (IComponent element : elements) {
			element.setStyle(s);
		}
	}
	
	
	public void addComponent(IComponent element) {
		elements.add(element);
	}
	
	public IComponent removeLastComponent() {
		IComponent element = elements.get(elements.size() - 1);
		elements.remove(elements.size() - 1);
		return element;
	}
}