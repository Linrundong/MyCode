package test.chat.client;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class receviceThread extends Thread{
	Socket client;
	boolean isRuning = true;
	DataInputStream is = null;
	
	public receviceThread(Socket client) {
		this.client = client;
	}


	public void read() {
		try {
			is = new DataInputStream(client.getInputStream());
			String str = is.readUTF();
			System.out.println(str);

		}
		catch (IOException e) {
			isRuning=false;
		}
		
	}
	
	@Override
	public void run() {
		while(isRuning) {
			read();
		}
	}
}