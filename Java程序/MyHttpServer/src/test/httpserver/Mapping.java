package test.httpserver;

import java.util.HashMap;

public class Mapping {
	
	static HashMap<String, String> servletMap = new HashMap<String, String>();
	
	static String getservletMap(String key) {
		servletMap.put("/log", "test.httpserver.LogServlet");
		servletMap.put("/Reg", "test.httpserver.RegServlet");
		
		if(!servletMap.containsKey(key)) {
			return "";
		}
		return servletMap.get(key);
	}
}
