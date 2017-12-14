package test.game;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;



public class GameFrame extends Myframe{
	
	public static void main(String[] args)
	{
		GameFrame Widget = new GameFrame();
		Widget.LunachFrame();
	}
	
	
	Image background_img = ImageUtil.getImage("images/background.png");
	Image player_img = ImageUtil.getImage("images/player.png");
	Player player = new Player("images/player.png", (int)Const.widget_x/2-player_img.getWidth(null)/2, (int)Const.widget_y-player_img.getHeight(null));
	Enemy aEnemy = new Enemy();
	
	/**
	 * 新建一个内部类-线程用来生产敌军
	 */
	ArrayList<Enemy> enemies = new ArrayList<Enemy>();

	class EnemyThread extends Thread{
		public void run()
		{
			while(true)
			{
				Enemy aEnemy = new Enemy();
				enemies.add(aEnemy);
				try {
					Thread.sleep(5000);
				} catch (Exception e) {
					// TODO: handle exception
				}
			}
		}
	} 
	
	@Override
	public void paint(Graphics g) {
		g.drawImage(background_img, 0, 0, null);
		
		player.draw(g);

		int enemyNum=0;
		for(enemyNum=0;enemyNum<enemies.size();enemyNum++)
		{
			Enemy tmp = enemies.get(enemyNum);
			tmp.draw(g);
			
			//Player与敌军相撞
			boolean boom =tmp.getRect().intersects(player.getRect());
			if(boom) { 
				tmp.setDie();
				player.setDie();	
				player.boom(g);
				tmp.boom(g);
				enemies.remove(enemyNum);
			}
			if(tmp.y>Const.widget_y-tmp.height)
				enemies.remove(enemyNum);
			
			//Player子弹射中敌军
			for(Bullet tmpb:player.bullets)
			{		
				boolean bulletBoom = tmp.getRect().intersects(tmpb.getRect());
				if(bulletBoom) { 
					tmp.setDie();
					tmp.boom(g);
					enemies.remove(enemyNum);
				}
			}
			
			//敌军子弹射中Player
			for(Bullet tmpa:tmp.enemyBullets)
			{
				boolean bulletBoom = tmpa.getRect().intersects(player.getRect());
				if(bulletBoom) { 
					player.setDie();
					player.boom(g);
				}
			}
			//System.out.println("敌军对象："+enemies.size()+" Player子弹对象："+player.bullets.size()+" 敌军子弹对象"+enemyNum+":"+tmp.enemyBullets.size());
			
			if(!player.isLive){
				player.ganmeOver(g);
			}
		}
	}
	
	
	
	@Override
	public void LunachFrame() {
		super.LunachFrame();
		// 增加键盘监听
        addKeyListener(new KeyControl());
        EnemyThread aThread = new EnemyThread();
		aThread.start();
	}


	//定义一个内部类，方便控制外部类
	class KeyControl extends KeyAdapter{
		@Override
		public void keyPressed(KeyEvent e) {
			player.adddirection(e);
			player.move();
		}

		@Override
		public void keyReleased(KeyEvent e) {
			player.miudirection(e);
		}
	}

}
