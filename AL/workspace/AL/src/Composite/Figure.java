package Composite;

public class Figure implements IComponent {

	private String imgurl;

	public Figure(String imgurl) {
		this.imgurl = imgurl;
	}

	public String toString() {
		return imgurl;
	}

	public String toStringHTML() {
		return "<img src='" + imgurl + "'>";
	}

	@Override
	public void setStyle(Style s) {
		// TODO Auto-generated method stub
		
	}
}