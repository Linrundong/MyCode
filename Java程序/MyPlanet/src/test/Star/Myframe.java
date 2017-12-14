package test.Star;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.Thread;

public class Myframe extends Frame{

	public void LunachFrame() {
		this.setLocation(200, 100);
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
		
		class test
		{
			public void print_t()
			{
				System.out.println("111");
			}
		}
		
}
