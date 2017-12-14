package test.chat.server;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
	
	public static void main(String[] args) throws Exception {
		InitServer();		
	}
		
	static List<HostThread> hostList = new ArrayList<HostThread>();
	
	public static  void InitServer() throws IOException {	
		ServerSocket server = new ServerSocket(6666);
		System.out.println("服务器开启");
		Socket client = null;
		boolean flag = true;
		
		while(flag) {
			client= server.accept();	
			Server.HostThread t1 = new Server().new HostThread(client);
			//hostList.add(client);
			t1.start();
		}
		client.close();
		server.close();
	}
	
	class HostThread extends Thread{
		
		String name;
		Socket client;
		DataInputStream is = null;
		DataOutputStream os = null;

		public HostThread(Socket client) {
			hostList.add(this);
			this.client = client;
		}
		
		public void init() throws IOException {
			is = new DataInputStream(client.getInputStream());	
			String str = "";
			boolean first=true;
			
			while(!str.equals("exit")) {
				str = is.readUTF();
				if(first) {
					this.name= str;
					str = "用户："+name+" 加入聊天室";
					System.out.println(str);
					first=false;
					sendMsg(str);
					continue;
				}	
				if(str.contains("@")&&str.contains(":")) {
					String name2 = str.substring(1,str.indexOf(":"));
					String content = str.substring(str.indexOf(":")+1);
					for(HostThread aThread:hostList) {
						if(aThread.equals(this)) {
							Socket aSocket = aThread.client;
							os = new DataOutputStream(aSocket.getOutputStream());
							os.writeUTF("你悄悄对"+name2+"说："+content);
				     		os.flush();
						}
						if(aThread.name.equals(name2)) {
							Socket aSocket = aThread.client;
							os = new DataOutputStream(aSocket.getOutputStream());
							os.writeUTF(this.name+"悄悄对你说："+content);
				     		os.flush();
						}	
					}	
					continue;
				}
				if(str.equals("exit")) {
					sendMsg("用户："+name+" 离开聊天室");
					break;
				}
	     		sendMsg(name+" 说 : "+str);
			}	
			hostList.remove(this);
			is.close();
			os.close();
		}

		public void sendMsg(String str) throws IOException {
			for(HostThread aThread:hostList) {
				Socket aSocket = aThread.client;
				os = new DataOutputStream(aSocket.getOutputStream());
				os.writeUTF(str);
	     		os.flush();
			}	
		}

		@Override
		public void run() {
			try {
				init();
			} catch (IOException e) {
				hostList.remove(this);
				//System.out.println("容器去除");
			}
		}
	
	}
	
}
