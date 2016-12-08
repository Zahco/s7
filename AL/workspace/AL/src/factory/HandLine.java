package factory;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.QuadCurve2D;

public class HandLine implements IShape {
	private double x0, y0, x1, y1;
	private Color c;
	
	public HandLine(double x0, double y0, double x1, double y1, Color c) {
		this.x0 = x0; this.y0 = y0;
		this.x1 = x1; this.y1 = y1;
		this.c = c;
	}

	@Override
	public void draw(Graphics2D screen) {
		screen.setColor(c);
		screen.draw(new QuadCurve2D.Double(
				x0, y0, 
				(x0 + x1) / 2 + Noise.getNoise(), (y0 + y1) / 2 + Noise.getNoise() * 2,
				x1, y1));
	}

}
