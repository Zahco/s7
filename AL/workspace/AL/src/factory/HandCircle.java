package factory;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

public class HandCircle implements IShape {
	private double cx, cy, rad;
	private Color c;

	public HandCircle(double cx, double cy, double rad, Color c) {
		this.cx = cx; this.cy = cy; this.rad = rad;
		this.c = c;
	}

	@Override
	public void draw(Graphics2D screen) {
		screen.setColor(c);
		screen.draw(new Ellipse2D.Double(cx-rad, cy-rad, rad*2 + Noise.getNoise(rad), rad*2 + Noise.getNoise(rad)));
	}

}
