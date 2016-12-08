package factory;

import java.awt.Color;

public interface IShapeFactory {
	public IShape createLine(double x0, double y0, double x1, double y1, Color c);
	public IShape createCircle(double cx, double cy, double rad, Color c);
	public IShape createRectangle(double x0, double y0, double x1, double y1, Color c);
}
