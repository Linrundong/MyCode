package test.game;

import java.awt.Graphics;

public class Bullet extends Object{
	
	String path;
	
	public Bullet(String path,double x, double y) {
		super( path, x, y);
	}
	
	public void move(int speed)
	{
		y-=speed;
	}
	
	public void draw(Graphics g)
	{
		g.drawImage(img, (int)x, (int)y, null);
	}
}
