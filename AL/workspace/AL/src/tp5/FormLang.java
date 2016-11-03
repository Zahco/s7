package tp5;

import java.util.HashMap;
import java.util.Map;

public interface FormLang {
	public String translate(String key);
}

class FormEn implements FormLang {

	private static Map<String, String> m;
	
	public FormEn() {
		m = new HashMap<String, String>();
		m.put("nom", "lastname");
		m.put("prenom", "firstname");
		m.put("adress", "address");
		m.put("ville", "city");
		m.put("age", "age");
		m.put("email", "email");
	}
	
	public String translate(String key) {
		return m.get(key);
	}
}

class FormFr implements FormLang {

	private static Map<String, String> m;
	
	public FormFr() {
		m = new HashMap<String, String>();
		m.put("nom", "nom");
		m.put("prenom", "prenom");
		m.put("adress", "adress");
		m.put("ville", "ville");
		m.put("age", "age");
		m.put("email", "email");
	}
	
	public String translate(String key) {
		return m.get(key);
	}
}