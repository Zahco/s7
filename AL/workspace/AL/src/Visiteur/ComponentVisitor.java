package Visiteur;

public interface ComponentVisitor {
	public void visiteFigure(Figure c);
	public void visiteListe(Liste c);
	public void visiteParagraphe(Paragraphe c);
	public void visiteSection(Section c);
}
