package Composite;

public class Paragraphe extends StyleComponent {

	private String text;

	public Paragraphe(String text) {
		super();
		this.text = text;
	}

	public String toString() {
		return text;
	}

	public String toStringHTML() {
		return "<p>" + style.wrap(text) + "</p>";
	}
}