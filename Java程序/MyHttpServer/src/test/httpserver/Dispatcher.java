package test.httpserver;

import java.net.Socket;

public class Dispatcher implements Runnable{

	Socket client;
	servlet aServlet; 
	Request request;
	Response response;
	boolean isruning =true;
	
	public Dispatcher(Socket client) {
		isruning =true;
		this.client = client;
		request = new Request(client);
		response = new Response(client);
	}


	@Override
	public void run() {
			try {
				aServlet = new servlet();
				aServlet.service(request,response);
				client.close();
			} catch (Exception e) {
				Thread.currentThread().interrupt();
			}
	}
}
