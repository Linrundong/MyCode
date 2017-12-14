package test.game;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.util.LinkedList;
import java.util.ListIterator;

public class Player extends Object{
	
	boolean left;
	boolean up;
	boolean down;
	boolean right;
	int speed = 8;
	boolean shootFlag;
	boolean isLive = true;
	
	LinkedList<Bullet> bullets = new LinkedList<Bullet>();
	LinkedList<Image> boomimgs = new LinkedList<Image>();
	
	public Player(String path,double x, double y) {
		super(path, x, y);
		loadBoomImages();
	}
	
	
	public void setDie() {
		isLive = false;
	}
	
	public void loadBoomImages()
	{
		for(int i=0;i<9;i++)
		{
			int j=i+1;
			String path = "images/player_down ("+j+").png";
			//System.out.println(path);
			Image tmp = ImageUtil.getImage(path);
			boomimgs.add(tmp);
		}
	}
	
	
	public void shoot()
	{
			Bullet aBullet = new Bullet("images/bullet.png", x+img.getWidth(null)/2, y);
			bullets.add(aBullet);
	}
	
	public void draw(Graphics g)
	{
		if(isLive) {
			super.draw(g);
			
			ListIterator<Bullet> it = bullets.listIterator();
			while(it.hasNext())
			{	
				Bullet tmp = it.next();
				if(tmp.y>0) {
					tmp.move(7);
					tmp.draw(g);
				}
				else {
					it.remove();
				}
			}	
		}
	}
	
	public void ganmeOver(Graphics g) {
		
		Font f = new Font(null, Font.BOLD,50);
        g.setFont(f);
        Color color = g.getColor();
        g.setColor(Color.gray);
        g.drawString("Game Over", 30, (int) Const.widget_y/2);
        g.setColor(color);
	}
	
	public void boom(Graphics g) {
		if(!isLive) {
			for(Image tmp:boomimgs)
			{
				g.drawImage(tmp, (int)x, (int)y, null);
			}
			x=-width;
		}
	}
	
	public void move() {
		if(left)
			x-=speed;
		if(right)
			x+=speed;
		if(up)
			y-=speed;
		if(down)
			y+=speed;
	}
	
	public void adddirection(KeyEvent e)
	{
		switch (e.getKeyCode()) {
		case 37:
				left=true;
				break;
		case 38:
				up=true;
				break;
		case 39:
				right=true;
				break;
		case 40:
				down=true;
				break;
		case 32:
				shoot();
				break;
		default:
			break;
		}	
	}
	
	public void miudirection(KeyEvent e)
	{
		switch (e.getKeyCode()) {
		case 37:
				left=false;
				break;
		case 38:
				up=false;
				break;
		case 39:
				right=false;
				break;
		case 40:
				down=false;
				break;
		default:
			break;
		}
	}
	
	public double getx()
	{
		return x;
	}
	
	public double gety()
	{
		return y;
	}
	
}
