package Composite;

import java.util.List;

public class Liste extends StyleComponent {

	private List<String> list;

	public Liste(List<String> list) {
		super();
		this.list = list;
	}

	public String toString() {
		String result = "";
		for (String l : list) {
			result += l;
		}
		return result;
	}

	public String toStringHTML() {
		String result = "<ul>";
		for (String l : list) {
			result += "<li>" + style.wrap(l) + "</li>";
		}
		return result + "</ul>";
	}
}