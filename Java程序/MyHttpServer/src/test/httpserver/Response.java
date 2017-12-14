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
	


	public void response(String str,String code) throws IOException {
		
		String context = str;
		String dic;
		
		StringBuilder strb = new StringBuilder();
		//1)
		if(code.equals("200"))
			dic = "OK";
		else {
			dic = "Not Found";
		}
		strb.append("HTTP/1.1 ").append(code).append(" ").append(dic).append("\r\n");
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
		System.out.println(strb);
	}
}



