package test.httpserver;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class httpserver {
	public static void main(String[] args) throws IOException {
		start();
	}
	
	static ServerSocket server;
	static boolean isrunning = true;
	
	public static void start() throws IOException {
		server = new ServerSocket(8888);
		try {
			while(isrunning) {
				//System.out.println(Thread.activeCount());
				Socket client = server.accept();
				new Thread(new Dispatcher(client)).start();
			}
		} catch (IOException e) {
			isrunning=false;
			e.printStackTrace();
		}
	}
}
