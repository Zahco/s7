package Visiteur;

public class Figure implements IComponent {

	private String imgurl;

	public Figure(String imgurl) {
		this.imgurl = imgurl;
	}

	public String getFigure() {
		return imgurl;
	}
	
	@Override
	public void setStyle(Style s) {

	}
	
	@Override
	public void accept(ComponentVisitor v) {
		v.visiteFigure(this);
	}
}
