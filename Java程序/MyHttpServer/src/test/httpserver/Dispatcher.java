package test.httpserver;

import java.net.Socket;

public class Dispatcher implements Runnable{

	Socket client;
	Servlet aServlet; 
	Request request;
	Response response;
	boolean isruning =true;
	String url;
	
	public Dispatcher(Socket client)  {
		isruning =true;
		this.client = client;
		request = new Request(client);
		try {
			request.parse();
		} catch (Exception e) {
			Thread.currentThread().interrupt();
		}
		response = new Response(client);
		this.url = request.getUrl();
	}


	@SuppressWarnings("deprecation")
	@Override
	public void run() {
			try {
				String name = Mapping.getservletMap(url);
				if(!name.equals("")) {
					aServlet = (Servlet)Class.forName(name).newInstance();
					aServlet.service(request,response);
					client.close();
				}
				else {
					response.response("", "404");
				}
			} catch (Exception e) {
				Thread.currentThread().interrupt();
			}
	}
}
