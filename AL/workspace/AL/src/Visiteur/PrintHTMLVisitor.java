package Visiteur;

public class PrintHTMLVisitor implements ComponentVisitor {

	@Override
	public void visiteFigure(Figure c) {
		System.out.println("<img src='" + c.getFigure() + "'>");
	}

	@Override
	public void visiteListe(Liste c) {
		String result = "<ul>";
		for (String l : c.getList()) {
			result += "<li>" + c.getStyle().wrap(l) + "</li>";
		}
		System.out.println(result + "</ul>");
	}

	@Override
	public void visiteParagraphe(Paragraphe c) {
		System.out.println("<p>" + c.getStyle().wrap(c.getText()) + "</p>");
	}

	@Override
	public void visiteSection(Section c) {
		System.out.println("<h1>" + c.getTitle() + "</h1>");
		for (IComponent element : c.getElements()) {
			element.accept(this);
		}
	}

}
