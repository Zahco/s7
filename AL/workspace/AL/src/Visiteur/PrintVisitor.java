package Visiteur;

public class PrintVisitor implements ComponentVisitor {

	@Override
	public void visiteFigure(Figure c) {
		System.out.println(c.getFigure());
	}

	@Override
	public void visiteListe(Liste c) {
		String result = "";
		for (String l : c.getList()) {
			result += l;
		}
		System.out.println(result);
	}

	@Override
	public void visiteParagraphe(Paragraphe c) {
		System.out.println(c.getText());
	}

	@Override
	public void visiteSection(Section c) {
		System.out.println(c.getTitle());
		for (IComponent element : c.getElements()) {
			element.accept(this);
		}
	}

}
