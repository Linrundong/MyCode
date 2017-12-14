package test.Star;

import java.awt.Graphics;
import java.awt.Image;

public class Star {

	//长轴，短轴，速度，角度
	double long_r;
	double short_r;
	double speed;
	Image image;
	double angle;
	
	double width,heigh;
	double x,y;
	
	Star(Image image,double long_r,double short_r,Double speed,double width,double heigh)
	{
		this.long_r=long_r;
		this.short_r=short_r;
		this.speed=speed;
		this.width=width;
		this.heigh=heigh;
		
		this.image = image;
	}

	public void draw(Graphics g)
	{
		x = Const.widget_x/2-width/2 +  long_r * Math.cos(angle);
		y = Const.widget_y/2-heigh/2  +  short_r * Math.sin(angle);
		angle += speed;
		
		g.drawImage(image, (int)x, (int)y, null);
	}
	
}
