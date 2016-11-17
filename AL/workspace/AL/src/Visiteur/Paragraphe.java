package Visiteur;

public class Paragraphe extends StyleComponent {

	private String text;

	public Paragraphe(String text) {
		super();
		this.text = text;
	}
	
	public String getText() {
		return text;
	}
	@Override
	
	public void accept(ComponentVisitor v) {
		v.visiteParagraphe(this);
	}
}