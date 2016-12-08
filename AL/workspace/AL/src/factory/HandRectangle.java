package factory;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;

public class HandRectangle implements IShape {
	private double x0, y0, x1, y1;
	private Color c;
	
	public HandRectangle(double x0, double y0, double x1, double y1, Color c) {
		this.x0 = x0; this.y0 = y0;
		this.x1 = x1; this.y1 = y1;
		this.c = c;
	}

	@Override
	public void draw(Graphics2D screen) {
		screen.setColor(c);
		IShapeFactory sf = new HandShapeFactory();
		sf.createLine(x0, y0, x0, y1, c).draw(screen);
		sf.createLine(x0, y1, x1, y1, c).draw(screen);
		sf.createLine(x1, y1, x1, y0, c).draw(screen);
		sf.createLine(x1, y0, x0, y0, c).draw(screen);

	}

}
