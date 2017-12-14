package test.Star;
import java.awt.*;



public class demo extends Myframe{
	private static final long serialVersionUID = 10000L;
		
	public static void main(String[] args) {
		
		demo aDemo = new demo();
		aDemo.LunachFrame();

		
	}
	
	double x;
	double y;
	static double angle=0;
	
	Image  img = ImageUtil.getImage("image/background.jpg");
	Image  sun = ImageUtil.getImage("image/Sun.jpg");	
	Image  mercury = ImageUtil.getImage("image/Mercury.jpg");
	Image  venus = ImageUtil.getImage("image/Venus.jpg");
	Image  earth = ImageUtil.getImage("image/Earth.jpg");
	Image  mars = ImageUtil.getImage("image/Mars.jpg");
	Image  jupiter = ImageUtil.getImage("image/jupiter.jpg");
	Image  saturn = ImageUtil.getImage("image/saturn.jpg");
	Image  uranus = ImageUtil.getImage("image/uranus.jpg");
	Image  neptune = ImageUtil.getImage("image/neptune.jpg");
	
	
	
	Star Mercury = new Star(mercury, 100, 70,  0.1,mercury.getWidth(null),mercury.getHeight(null));
	Star Venus = new Star(venus, 150, 100,  0.07,venus.getWidth(null),venus.getHeight(null));
	Star Earth = new Star(earth, 210, 135,  0.05,earth.getWidth(null),earth.getHeight(null));
	Star Mars = new Star(mars, 250, 175,  0.04,mars.getWidth(null),mars.getHeight(null));
	Star Jupiter = new Star(jupiter, 300, 200,  0.03,jupiter.getWidth(null),jupiter.getHeight(null));
	Star Saturn = new Star(saturn, 350, 240,  0.02,saturn.getWidth(null),saturn.getHeight(null));
	Star Uranus = new Star(uranus, 400, 280,  0.01,uranus.getWidth(null),uranus.getHeight(null));
	Star Neptune = new Star(neptune, 450, 310,  0.015,neptune.getWidth(null),neptune.getHeight(null));
	
	Ovel Mercury_o = new Ovel(100, 70,mercury.getWidth(null),mercury.getHeight(null));
	Ovel Venus_o = new Ovel(150, 100,venus.getWidth(null),venus.getHeight(null));
	Ovel Earth_o = new Ovel(210, 135,earth.getWidth(null),earth.getHeight(null));
	Ovel Mars_o = new Ovel(250, 175,earth.getWidth(null),earth.getHeight(null));
	Ovel Jupiter_o = new Ovel(300, 200,earth.getWidth(null),earth.getHeight(null));
	Ovel Saturn_o = new Ovel(350, 240,earth.getWidth(null),earth.getHeight(null));
	Ovel Uranus_o = new Ovel(400, 280,earth.getWidth(null),earth.getHeight(null));
	Ovel Neptune_o = new Ovel(450, 310,earth.getWidth(null),earth.getHeight(null));
	
	Image ImageBuffer = null;
	Graphics GraImage = null;
	
	//使用缓冲区消除闪烁
	public void update(Graphics g){		//覆盖update方法，截取默认的调用过程
		ImageBuffer = createImage(this.getWidth(), this.getHeight());	//创建图形缓冲区
		GraImage = ImageBuffer.getGraphics();		//获取图形缓冲区的图形上下文
		paint(GraImage);		//用paint方法中编写的绘图过程对图形缓冲区绘图
		GraImage.dispose();		//释放图形上下文资源
		g.drawImage(ImageBuffer, 0, 0, this);	//将图形缓冲区绘制到屏幕上
	}
	
	@Override
	public void paint(Graphics g) {
		
		//绘画背景图片
		g.drawImage(img, 0, 0, null);
		
		//绘画SUN图片	
		g.drawImage(sun, (int)Const.widget_x/2-sun.getWidth(null)/2, (int)Const.widget_y/2-sun.getHeight(null)/2, null);
		
		g.setColor(Color.GRAY);
		//绘画行星轨迹
		Mercury_o.draw(g);
		Venus_o.draw(g);
		Earth_o.draw(g);
		Mars_o.draw(g);
		Jupiter_o.draw(g);
		Saturn_o.draw(g);
		Uranus_o.draw(g);
		Neptune_o.draw(g);

		//绘画行星图片
		Mercury.draw(g);
		Venus.draw(g);
		Earth.draw(g);
		Mars.draw(g);
		Jupiter.draw(g);
		Saturn.draw(g);
		Uranus.draw(g);
		Neptune.draw(g);
		
	}

}
