package tp5;

public class TestForm {
	public FormGenerator getFormGenerator() {
		// Obscure fonction retournant un generateur de formulaire.
		// Vous la definirez pour vos tests.
		// Ex: return new HTMLForm();
		return new FormulairePDF(new FormEn());
	}
	
	public void testGenerator(FormGenerator fg) {
		fg.addTitleHeader("URouen Corp.");
		fg.addSeparator();
		fg.addNameLine();
		fg.addFirstNameLine();
		fg.addSeparator();
		fg.addEmailLine();

		String Result = fg.send();
		System.out.println(Result);
	}
	
	public static void main(String[] args) {
		TestForm t = new TestForm();
		t.testGenerator(t.getFormGenerator());
	}
}


