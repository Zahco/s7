package ProxyD;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class PolicyProxy implements InvocationHandler {
	
	public static Object newInstance(Object employee, IPolicy policy) {
		ClassLoader loader = employee.getClass().getClassLoader();
		Class[] interfaces = employee.getClass().getInterfaces();
		return Proxy.newProxyInstance(loader, interfaces, new PolicyProxy(employee, policy));
	}
	
	private Object employee;
	private IPolicy policy;
	
	public PolicyProxy(Object employee, IPolicy policy) {
		this.employee = employee;
		this.policy = policy;
	}
	
	@Override
	public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
		if (!policy.isAllowed(method.getName())) {
			return "****** (" + method.getName() + " => Access Deny)";
		}
		return method.invoke(employee, args);
	}
	public String whoAmI() {
		String result = "";
		result += employee.getClass().getName();
		for (Class interfase : employee.getClass().getInterfaces()) {
			result += " " + interfase.getName();
		}
		return result;
	}
}
