package test.Star;

import java.awt.Graphics;

public class Ovel {
	
	//长轴，短轴，速度，角度
	double long_r;
	double short_r;
	double x,y;
	
	Ovel(double long_r,double short_r,double width,double heigh)
	{
		this.long_r=long_r;
		this.short_r=short_r;
	}

	public void draw(Graphics g)
	{
		g.drawOval((int)Const.widget_x/2-(int)long_r, (int)Const.widget_y/2-(int)short_r, (int)long_r*2, (int)short_r*2);
	}
	
}
