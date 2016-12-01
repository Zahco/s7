package ProxyD;

import java.util.HashSet;
import java.util.Set;

public class AllowFirst implements IPolicy {
	
	private Set<String> denyList;
	
	public AllowFirst() {
		denyList = new HashSet<String>();
	}
	
	@Override
	public void allow(String rule) {
		denyList.remove(rule);
	}

	@Override
	public void deny(String rule) {
		denyList.add(rule);
	}

	@Override
	public boolean isAllowed(String rule) {
		return !denyList.contains(rule);
	}

}
