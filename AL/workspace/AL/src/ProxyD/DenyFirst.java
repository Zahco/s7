package ProxyD;

import java.util.HashSet;
import java.util.Set;

public class DenyFirst implements IPolicy {
	
	private Set<String> allowList;
	
	public DenyFirst() {
		allowList = new HashSet<String>();
	}
	@Override
	public void allow(String rule) {
		allowList.add(rule);
	}

	@Override
	public void deny(String rule) {
		allowList.remove(rule);
	}

	@Override
	public boolean isAllowed(String rule) {
		return allowList.contains(rule);
	}

}
