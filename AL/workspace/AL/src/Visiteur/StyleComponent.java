package Visiteur;

public abstract class StyleComponent implements IComponent {
	
	protected Style style;

	
	protected StyleComponent() {
		style = Style.NONE;
	}
	public Style getStyle() {
		return style;
	}
	public void setStyle(Style s) {
		style = s;
	}
}