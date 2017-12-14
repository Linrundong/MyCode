package test.httpserver;

import java.io.IOException;

public class servlet {
	
	public void service(Request req,Response res) throws IOException {
		
			req.parse();
			String[] hoString =  req.getparameterValue("uname");
			String allstr=new String();
			for(String str:hoString) {
				allstr+=str;
			}
			
			String context = "<html>"
					+ "<head> <title> 标题</title> </head>"
					+ "<body>" +allstr+"欢迎回来"+ "</body>"
					+ "</html>";
			
			res.response(UtilDecode.decode(context,"UTF-8"));
		}
}
