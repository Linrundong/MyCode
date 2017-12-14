package test.chat.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.Socket;

public class Client {
	
	public static void main(String[] args) throws Exception, Exception {
		System.out.println("请输入用户名");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String name = br.readLine();
		InitClient(name);
	}
	
	public static  void InitClient(String name) throws Exception, IOException {
		Socket client = new Socket(InetAddress.getLocalHost(), 6666);
		//System.out.println("客户端开启");
		
		sendThread t1 = new sendThread(client,name);
		t1.start();
		receviceThread t2 = new receviceThread(client);
		t2.start();
	}
	
}






