package test.httpserver;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Date;


public class Response {
	 Socket client;

	public Response() {
	}

	public Response(Socket client) {
		this.client = client;
	}
	


	public void response(String str) throws IOException {
		
		String context = str;
		
		StringBuilder strb = new StringBuilder();
		//1)
		strb.append("HTTP/1.1 200 OK").append("\r\n");
		//2)
		strb.append("Server:dong Server/0.01").append("\r\n");
		strb.append("Date:").append(new Date()).append("\r\n");
		strb.append("Content-type:text/html;charset=UTF-8").append("\r\n");
		strb.append("Content-Length:").append(context.getBytes().length).append("\r\n");
		//3)
		strb.append("\r\n");
		strb.append(context);
		
		BufferedWriter bw = new BufferedWriter(
				new OutputStreamWriter(client.getOutputStream()));
		bw.write(strb.toString());
		bw.flush();
		bw.close();
		//System.out.println("响应完毕");
	}
}



