package test.httpserver;

import java.io.IOException;

public abstract class Servlet {
	
	public abstract void service(Request req,Response res) throws IOException ;
	
}