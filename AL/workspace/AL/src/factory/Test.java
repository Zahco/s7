package factory;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;
import java.util.*;

public class Test {
	// Code d'initialisation :
	public static java.util.List<IShape> getDemo() {
		java.util.List<IShape> ls=new ArrayList<IShape>();
		IShapeFactory sf = new HandShapeFactory();
		ls.add(sf.createLine(0, 500, 800, 500, Color.GREEN));
		ls.add(sf.createLine(300, 0, 0, 300, Color.YELLOW));
		
		ls.add(sf.createLine(30, 300, 180, 200, Color.BLUE));
		ls.add(sf.createLine(330, 300, 180, 200, Color.BLUE));
		ls.add(sf.createRectangle(30, 300,330, 500, Color.RED));

		double sunX = 600;
		double sunY = 120;
		double sunRad = 60; 
		ls.add(sf.createCircle(sunX, sunY, sunRad, Color.BLACK));
		int sunRay = 20;
		for (int i=0; i<sunRay; ++i) {
			double tau=i*2*Math.PI/sunRay;
			ls.add(sf.createLine(sunX+(sunRad+5)*Math.cos(tau),
				sunY-(sunRad+5)*Math.sin(tau),  
				sunX+(1.5*sunRad+5)*Math.cos(tau),
				sunY-(1.5*sunRad+5)*Math.sin(tau),
				Color.BLACK));
		}

		double manX=600;
		double manY=450;
		ls.add(sf.createLine(manX, manY-70, manX-40, manY-110, Color.RED));
		ls.add(sf.createLine(manX, manY-70, manX+40, manY-110, Color.RED));
		ls.add(sf.createCircle(manX, manY-120, 20, Color.GRAY));
		ls.add(sf.createLine(manX, manY, manX, manY-100, Color.BLUE));
		ls.add(sf.createLine(manX, manY, manX-20, manY+50, Color.BLACK));
		ls.add(sf.createLine(manX, manY, manX+20, manY+50, Color.BLACK));
		

		return ls;
	}
	
	// Code du client :
	public static void main(String[] args)  {
		GraphicViewer gv = new GraphicViewer();
		java.util.List<IShape> demo=getDemo();
		gv.draw(demo);
	}
}
