package tp5;

public abstract class Formulaire implements FormGenerator {
	
	protected FormLang traductor;
	
	protected String formulaire;
	
	public Formulaire(FormLang traductor) {
		this.traductor = traductor;
		formulaire = "";
	}
	
	public void addTitleHeader(String formTitle) {
		formulaire += "<title>" + formTitle + "</title>\n";
	}
}

class FormulaireHTML extends Formulaire {
	public FormulaireHTML(FormLang traductor) {
		super(traductor);
	}

	@Override
	public void addSeparator() {
		formulaire += "<hr/>\n";
	}

	@Override
	public void addNameLine() {
		formulaire += "<input type='text' name='name' placeholder='" + traductor.translate("nom") + "'>\n";
	}

	@Override
	public void addFirstNameLine() {
		formulaire += "<input type='text' name='firstname' placeholder='" + traductor.translate("prenom") + "'>\n";
	}

	@Override
	public void addEmailLine() {
		formulaire += "<input type='text' name='email' placeholder='" + traductor.translate("email") + "'>\n";
	}

	@Override
	public String send() {
		return "<html><body>\n" + formulaire + "<\\body><\\html>\n";
	}
}

class FormulairePDF extends Formulaire {
	public FormulairePDF(FormLang traductor) {
		super(traductor);
	}

	@Override
	public void addSeparator() {
		formulaire += "<pdf_hr/>\n";
	}

	@Override
	public void addNameLine() {
		formulaire += "<pdf_input type='text' name='name' placeholder='" + traductor.translate("nom") + "'>\n";
	}

	@Override
	public void addFirstNameLine() {
		formulaire += "<pdf_input type='text' name='firstname' placeholder='" + traductor.translate("prenom") + "'>\n";
	}

	@Override
	public void addEmailLine() {
		formulaire += "<pdf_input type='text' name='email' placeholder='" + traductor.translate("email") + "'>\n";
	}

	@Override
	public String send() {
		return "<pdf_body>\n" + formulaire + "<\\pdf_body>\n";
	}
	
}