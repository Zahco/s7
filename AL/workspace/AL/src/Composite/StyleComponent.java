package Composite;

public abstract class StyleComponent implements IComponent {
	
	protected Style style;
	
	protected StyleComponent() {
		style = Style.NONE;
	}
	
	public void setStyle(Style s) {
		style = s;
	}
}