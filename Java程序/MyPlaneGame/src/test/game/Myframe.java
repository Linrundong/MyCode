package test.game;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.Thread;

public class Myframe extends Frame{

	public void LunachFrame() {
		this.setLocation(400, 100);
		this.setSize((int)Const.widget_x, (int)Const.widget_y);
		this.setVisible(true);
		
		new PaintThread().start();
				
		/**
		 * 窗口关闭功能
		 */	  
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e)
			{
				System.exit(0);
			}
		});
		
	 }
		
		
	
		/**
		 * 新建一个内部类-线程用来刷新
		 */
		class PaintThread extends Thread{
			public void run()
			{
				while(true)
				{
					repaint();
					try {
						Thread.sleep(50);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		} 

		//使用缓冲区消除闪烁
		Image ImageBuffer = null;
		Graphics GraImage = null;
		
		public void update(Graphics g){		//覆盖update方法，截取默认的调用过程
			ImageBuffer = createImage(this.getWidth(), this.getHeight());	//创建图形缓冲区
			GraImage = ImageBuffer.getGraphics();		//获取图形缓冲区的图形上下文
			paint(GraImage);		//用paint方法中编写的绘图过程对图形缓冲区绘图
			GraImage.dispose();		//释放图形上下文资源
			g.drawImage(ImageBuffer, 0, 0, this);	//将图形缓冲区绘制到屏幕上
		}

}
