package factory;		// TODO Auto-generated constructor stub

import java.awt.Color;

public class HandShapeFactory implements IShapeFactory {

	@Override
	public IShape createLine(double x0, double y0, double x1, double y1, Color c) {
		return new HandLine(x0, y0, x1, y1, c);
	}

	@Override
	public IShape createCircle(double cx, double cy, double rad, Color c) {
		return new HandCircle(cx, cy, rad, c);
	}

	@Override
	public IShape createRectangle(double x0, double y0, double x1, double y1, Color c) {
		return new HandRectangle(x0, y0, x1, y1, c);
	}

}
