#pragma once
class FeetInches
{
private:
	int feet;
	int inches;
public:
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
	}
	void setFeet(int val)
	{
		feet = val;
	}
	void setInches(int val)
	{
		inches = val;
	}
	int getFeet()
	{
		return feet;
	}
	int getInches()
	{
		return inches;
	}
	double operator*(FeetInches r)
	{
		double i, f, area;
		i = getFeet() + (static_cast<double>(getInches()) / 12);
		f = r.getFeet() + (static_cast<double>(r.getInches()) / 12);
		area = i * f;
		return area;
	}
};

// class RoomDimension.
class RoomDimension
{
private:
	FeetInches length;
	FeetInches Width;
public:
	// Constructor and other supported functions.
	RoomDimension(FeetInches l = 0, FeetInches w = 0) : length(l), Width(w)
	{}
	void setLength(FeetInches l)
	{
		this->length = l;
	}
	void setwidth(FeetInches w)
	{
		this->Width = w;
	}
	FeetInches getLength()
	{
		return length;
	}
	FeetInches getWidth()
	{
		return Width;
	}
	FeetInches calculateArea()
	{
		FeetInches Area;

		double i, f, area;
		int feet;
		double inch;
		i = length.getFeet() + (static_cast<double>(length.getInches()) / 12);
		f = Width.getFeet() + (static_cast<double>(Width.getInches()) / 12);
		area = i * f;

		feet = int(area);
		inch = (area - feet) * 12;

		Area.setFeet(feet);
		Area.setInches(int(inch));

		return Area;
	}

};

// class RoomCarpet.
class RoomCarpet
{
private:
	RoomDimension length;
	float cost_per_square_foot;
public:
	// Constructor and other supported functions.
	RoomCarpet() :cost_per_square_foot(0) {};
	RoomCarpet(RoomDimension a, float cost = 8) :length(a)
	{
		if (cost > 0)
			this->cost_per_square_foot = cost;
		else
			this->cost_per_square_foot = 0;
	}
	float calculateTotalCost()
	{
		double i;
		i = length.getLength() * length.getWidth() * cost_per_square_foot;
		return i;
	}
	void setLength(RoomDimension r)
	{
		length = r;
	}
	void setCost(float cost)
	{
		this->cost_per_square_foot = cost;
	}
	float getCost() const
	{
		return this->cost_per_square_foot;
	}
	RoomDimension getLengthDimension()
	{
		return length;
	}
};