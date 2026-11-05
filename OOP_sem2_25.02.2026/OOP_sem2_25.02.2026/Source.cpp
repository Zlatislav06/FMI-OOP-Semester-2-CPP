#include <iostream>
using std::cin;
using std::printf;
using std::endl;
using std::string;
//zad 1
class BankAccount
{
private:
	string owner_;
	double balance_;

public:
	double getBalance() { return balance_; }
	void setOwner(string o) 
	{
		if (o.size() <= 50)
		{
			owner_ = o;
		}
		else
		{
			printf("Error!!!");
			owner_ = "";
		}
	
	}
	void deposit(double amount)
	{
		if (amount<=0)
		{
			printf("The amount is less then zero!");
		}
		else
		{
			balance_ += amount;
			printf("The new balance is %f", round(balance_));
		}
	}
	void withdraw(double amount)
	{
		if (balance_ >= amount)
		{

			balance_ -= amount;
			printf("The new balance is %f", round(balance_));
		}
		else if(amount <= 0)
		{
			printf("The amount is less then zero!");
			
		}
		else
		{
			printf("Error!!!");
		}
	}
	BankAccount(string o,double b)
	{
		setOwner(o);
		balance_ = b;
	}
};
//zad 4
class Counter
{
private:
	 int value;
	 mutable int accessCount;
public:
	void increment()
	{
		value++;
	}
	int getValue() const
	{
		return value;
		accessCount++;
	}
	int getAccessCount() const
	{
		return accessCount;
	}
	Counter(int v,int a)
	{
		value = v;
		accessCount = a;
	}
	Counter()
	{
		value = 0;
		accessCount = 0;
	}
};
//zad 6
class Point2D
{
private:
	double x;
	double y;
public:
	Point2D()
	{
		x = 0;
		y = 0;
	}
	Point2D(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	~Point2D(){}
	void print()
	{
		printf("(%f,%f)", round(x), round(y));
	}
};

int main()
{
	Point2D b(5,10);
	
	b.print();
	return 0;
}
