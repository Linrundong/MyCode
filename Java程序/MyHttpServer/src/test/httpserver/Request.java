package test.httpserver;

import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * 根据请求提取出请求方式、请求URL、请求参数
 * @author dong
 *
 */
public class Request {
	
	Socket client;
	private String allMsg;
	 //请求方式
    private String method;
    //请求资源
    private String url;
    //请求参数
    //private Map<String,List<String>> parameterMapValues;
	
	public Request() {
	}

	public Request(Socket client) {
		this.client = client;
	}
	
	public void accept() throws IOException {
		//System.out.println("连接成功");
		byte[] data = new byte[20480];
		int len = client.getInputStream().read(data);
		allMsg = new String(data, 0, len).trim();
		//System.out.println(allMsg);
		//System.out.println("读取完毕");
	}
	
	public void parse() throws IOException{
		accept();
		String firstLine = allMsg.substring(0, allMsg.indexOf("\r\n")).trim();
		String parameterString ;
		this.method = firstLine.substring(0,firstLine.indexOf("/")-1).trim();
		
		if(method.equalsIgnoreCase("get")) {
			this.url = firstLine.substring(firstLine.indexOf("/"),firstLine.indexOf("?"));
			parameterString = firstLine.substring
					(firstLine.indexOf("?")+1,firstLine.indexOf("HTTP/")).trim();
		}
		else if(method.equalsIgnoreCase("post")) {
			this.url = firstLine.substring(firstLine.indexOf("/"),firstLine.indexOf("HTTP/")).trim();
			int index = allMsg.lastIndexOf("\r\n");
			parameterString = allMsg.substring(index).trim();
		}
		else {
			return;
		}
		
		parseParameter(parameterString);
	}
	
	HashMap<String, ArrayList<String>> parameterMap = new HashMap<String, ArrayList<String>>();
	private void parseParameter(String parameterString) {
		// TODO 自动生成的方法存根
		StringTokenizer sTokenizer = new StringTokenizer(parameterString, "&");
		while(sTokenizer.hasMoreTokens()) {
			String keyvalues  = sTokenizer.nextToken();
			String[] keyvalue = keyvalues.split("=");
			
			if(keyvalue.length==1) {
				keyvalue = Arrays.copyOf(keyvalue, 2);
				keyvalue[1] = null;
			}
			String key = keyvalue[0].trim();
			String value = keyvalue[1].trim();
//			System.out.println(key);
//			System.out.println(value);
		
			if(!parameterMap.containsKey(key)) {
				parameterMap.put(key, new ArrayList<String>());
			}
			ArrayList<String> valueList = parameterMap.get(key);
			valueList.add(value);		
		}
	}
	
	public String[] getparameterValue(String key) {
		ArrayList<String> valueList = parameterMap.get(key);
		if(valueList==null) {
			return null;
		}
		else {
			return valueList.toArray(new String[0]);
		}
	}

	public String getMethod() {
		return method;
	}

	public String getUrl() {
		return url;
	}
}
