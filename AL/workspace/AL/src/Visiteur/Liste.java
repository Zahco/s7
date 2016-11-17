package Visiteur;

import java.util.List;

public class Liste extends StyleComponent {

	private List<String> list;

	public Liste(List<String> list) {
		super();
		this.list = list;
	}
	
	public List<String> getList() {
		return list;
	}

	@Override
	public void accept(ComponentVisitor v) {
		v.visiteListe(this);
	}
}