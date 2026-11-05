#pragma once
enum Crop
{
	WHEAT, 
	BARLEY, 
	CORN, 
	NOTHING
};
class Plot
{
private:
	static int br;
	int id;
	double width;
	double height;
	Crop cropType;
public:
	Plot();
	Plot(double w,double h,Crop c);
	int getId();
	double getWidth();
	double getHeight();
	Crop getCropType();
	void setWidth(double w);
	void setHeight(double h);	
	void sow(Crop c);
	void reap();
};
