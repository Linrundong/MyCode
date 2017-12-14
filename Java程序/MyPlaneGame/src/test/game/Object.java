package test.game;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;

public class Object {
	
	double x;
	double y;
	int width;
	int height;
	Image img;
	
	public Object() {
	}
	
	public Object(String path,double x, double y) {
		this.x = x;
		this.y = y;
		this.img = ImageUtil.getImage(path);
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);
	}
	
	public void draw(Graphics g)
	{
		g.drawImage(img, (int)x, (int)y, null);
	}
	
	public Rectangle getRect()
	{
		return new Rectangle((int)x, (int)y, width, height);
	}
}
