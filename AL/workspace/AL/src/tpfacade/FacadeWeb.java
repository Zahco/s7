package tpfacade;
import java.util.*;

public interface FacadeWeb {
	public String findVehicule(String name);
	public String findVehiculeByPrice(int lo, int hi);
	public String orderVehiculeDoc(String name, String address);
}

class FacadeWebImpl implements FacadeWeb {
	
	private String sendFormatedHtml(String content) {
		return "<html><body>\n"+content+"\n</body></html>\n";
	}

	@Override
	public String findVehicule(String name) {
		return sendFormatedHtml(DatabaseImpl.getContext().getVehicule(name).getWebDescription());
	}

	@Override
	public String findVehiculeByPrice(int lo, int hi) {
		List<Vehicule> lv = DatabaseImpl.getContext().getVehiculesByPrice(lo, hi);
		String allDesc = "";
		for(Vehicule v : lv) {
			allDesc += v.getWebDescription();
		}
		return sendFormatedHtml(allDesc);
	}

	@Override
	public String orderVehiculeDoc(String name, String address) {
		Vehicule v = DatabaseImpl.getContext().getVehicule(name);
		int id = PrinterImpl.getDefaultPrinter().print(v.getPrintableDocument());
		Mailing m = new MailingImpl();
		return sendFormatedHtml(m.send(id, address));
	}
}