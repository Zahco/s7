package tpfacade;
import java.util.*;

public interface FacadeAdmin {
	public void addVehicule (String name, int price, String wdoc, String pdoc);
}

class FacadeAdminImpl implements FacadeAdmin {

	public void addVehicule(String name, int price, String wdoc, String pdoc) {
		Vehicule v = new VehiculeImpl(name, price, wdoc, pdoc);
		DatabaseImpl.getContext().addVehicule(v);
	}
	
}