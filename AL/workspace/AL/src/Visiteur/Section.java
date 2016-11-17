package Visiteur;

import java.util.ArrayList;
import java.util.List;

public class Section implements IComponent {

	private String title;
	private List<IComponent> elements;
	
	public Section(String title) {
		this.title = title;
		elements = new ArrayList<IComponent>();
	}
	
	public List<IComponent> getElements() {
		return elements;
	}

	public String getTitle() {
		return title;
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
	
	@Override
	public void accept(ComponentVisitor v) {
		v.visiteSection(this);
	}
}