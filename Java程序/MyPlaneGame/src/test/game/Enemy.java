package test.game;

import java.awt.Graphics;
import java.awt.Image;
import java.util.LinkedList;
import java.util.ListIterator;

public class Enemy extends Object{
	
	double speed=2;
	boolean isLive = true;
	
	LinkedList<Image> boomimgs = new LinkedList<Image>();
	LinkedList<Bullet> enemyBullets = new LinkedList<Bullet>();
	
	public void move()
	{
		y-=speed;
	}
	
	public Enemy()
	{
		this.y = 30;
		this.x = Math.random()*Const.widget_x-70;
		while(x<0)
			this.x = Math.random()*Const.widget_x-70;
		int tmp=0;
		while(tmp == 0)
		{
			tmp = (int)(Math.random()*10)%3;
		}
		String path = "images/enemy"+tmp+".png";
		this.img = ImageUtil.getImage(path);	
		
		width = img.getWidth(null);
		height = img.getHeight(null);
		
		loadBoomImages(tmp);
		
		bulletThread t1 = new bulletThread();
		t1.start();
	}
	
	public void shoot()
	{
			Bullet aBullet = new Bullet("images/bullet2.png", x+img.getWidth(null)/2, y+img.getHeight(null));
			enemyBullets.add(aBullet);
	}
	
	class bulletThread extends Thread{
		public void run()
		{
			while(true)
			{
				shoot();
				try {
					Thread.sleep(2000);
				} catch (Exception e) {
					// TODO: handle exception
				}
			}
		}
	} 
	
	public void loadBoomImages(int number)
	{
		for(int i=0;i<12;i++)
		{
			int j=i+1;
			String path = "images/enemy"+number+"_down ("+j+").png";
			Image tmp = ImageUtil.getImage(path);
			boomimgs.add(tmp);
		}
	}
	
	public void draw(Graphics g)
	{
		if(isLive) {
			y += speed;
			g.drawImage(img, (int)x, (int)y, null);
			
			ListIterator<Bullet> it =enemyBullets.listIterator();
			while(it.hasNext())
			{	
				Bullet tmp = it.next();
				if(tmp.y<Const.widget_y) {
					tmp.move(-5);
					tmp.draw(g);
				}
				else {
					it.remove();
				}
			}
		}
	}
	
	public void boom(Graphics g) {
		if(!isLive) {
			for(Image tmp:boomimgs)
			{
				g.drawImage(tmp, (int)x, (int)y, null);
			}
		}
	}
	
	public void setDie()
	{
		this.isLive = false;
	}
}
