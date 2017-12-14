package test.chat.client;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class sendThread extends Thread{
	Socket aclient;
	String name;
	DataOutputStream op;
	
	public sendThread(Socket aclient, String name) {
		this.aclient = aclient;
		this.name = name;
	}
	
	public void send() throws IOException {
		op = new DataOutputStream(aclient.getOutputStream());
		String input = "";
		boolean first = true;
		boolean isRuning = true;
		while(isRuning)
		{
			if(first) {
				first=false;
				op.writeUTF(name);
				op.flush();
			}
				
			input = inputReturn();
			if(input.equals("exit")) {
				op.writeUTF(input);
				op.flush();
				isRuning=false;
				break;
			}
			op.writeUTF(input);
			op.flush();
		}	
		is.close();
		op.close();
		aclient.close();
		System.out.println("断开连接");
	}

	static InputStreamReader is = new InputStreamReader(System.in);
	static BufferedReader br =  new BufferedReader(is);
	public static String inputReturn() throws IOException {		
		String name = br.readLine();	
		return name;
	}
	
	@Override
	public void run() {
		try {
			send();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
}