package Visiteur;

public interface IComponent {

	public void setStyle(Style s);
	
	public void accept(ComponentVisitor v);
}