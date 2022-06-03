#pragma once
#ifndef FOSSILFUEL_H
#define FOSSILFUEL_H

class FossilFuel
{
private:
	int id;
	float rate;
	int AmountAvailable;
public:
	FossilFuel()
	{
		this->id = 0;
		this->rate = 0;
		this->AmountAvailable = 0;
	}

	FossilFuel(int id, float rate, int amount)
	{
		this->id = (id >= 0 && id <= 2) ? id : 0;
		this->rate = (rate > 0) ? rate : 0;
		this->AmountAvailable = (amount > 0) ? amount : 0;
	}

	void setID(int id)
	{
		this->id = (id >= 0 && id <= 2) ? id : 0;
	}

	void setRate(float rate)
	{
		this->rate = (rate > 0) ? rate : 0;
	}

	void setAmount(int amount)
	{
		this->AmountAvailable = (amount > 0) ? amount : 0;
	}

	int getID() const
	{
		return this->id;
	}

	float getRate() const
	{
		return this->rate;
	}

	int getAmount() const
	{
		return this->AmountAvailable;
	}

	virtual float calculatePrice(int amount) 
	{
		return (amount * rate);
	}
};


class Coal : public FossilFuel
{
public:
	virtual float calculatePrice(int amount) override
	{
		return (amount * this->getRate());
	}
};

class CrudeOil : public FossilFuel
{
public:
	virtual float calculatePrice(int amount) override
	{
		return (amount * this->getRate());
	}
};

class NaturalGas : public FossilFuel
{
public:
	virtual float calculatePrice(int amount) override
	{
		return (amount * this->getRate());
	}
};

#endif // !FOSSILFUEL_H
