#include <iostream>
#include <string>

using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����������� �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

   /*
		* Pizza (�������) ������������ ������� �������������� ������.
		* ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
		* */
class Car
{
	string speed;
	string brand;
	string color;
public:
	void Setspeed(string speed)
	{
		this->speed = speed;
	}
	string Getspeed()
	{
		return this->speed;
	}
	void Setbrand(string brand)
	{
		this->brand = brand;
	}
	string Getbrand()
	{
		return this->brand;
	}
	void Setcolor(string color)
	{
		this->color = color;
	}
	string Getcolor()
	{
		return this->color;
	}
	void ShowCar()
	{
		cout << "Brand: " + brand + "\nSpeed: " + speed + "\nColor: " + color + "\n";
	}
};

   // Abstract Builder ������ ����������� ��������� (�����) ��� �������� ������ ������� Product (� ����� ������, Pizza);
   /** "Abstract Builder" */
class CarBuilder abstract
{
protected:
	Car car;
public:
	Car Getcar()
	{
		return car;
	}
	virtual void Buildspeed() abstract;
	virtual void Buildbrand() abstract;
	virtual void Buildcolor() abstract;
};

// ConcreteBuilder ��������� ��������� ��������:
// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
// - ���������� ����������� ������������� � ������ �� ���;
// - ������������� ��������� ��� ������� � ��������

class AudiCarBuilder: public CarBuilder
{
public:
	void Buildspeed() override
	{
		car.Setspeed("190 km/h");
	}
	void Buildbrand() override
	{
		car.Setbrand("Audi");
	}
	void Buildcolor() override
	{
		car.Setcolor("Grey");
	}
};

class FordCarBuilder: public CarBuilder
{
public:  
	void Buildspeed() override
	{
		car.Setspeed("210 km/h");
	}
	void Buildbrand() override
	{
		car.Setbrand("Ford");
	}
	void Buildcolor() override
	{
		car.Setcolor("Blue");
	}
};

// Director(�������������) - ������������ ������ (Pizza), ��������� ����������� Builder
class Shop
{
	CarBuilder *carBuilder;
public:
	void SetCarBuilder(CarBuilder* pb)
	{
		carBuilder = pb;
	}
	Car GetCar()
	{
		return carBuilder->Getcar();
	}
	void ConstructCar()
	{
		carBuilder->Buildspeed();
		carBuilder->Buildbrand();
		carBuilder->Buildcolor();
	}
};

// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
void client(CarBuilder * builder)
{
	Shop waiter;
	waiter.SetCarBuilder(builder);
	waiter.ConstructCar();
	Car pizza = waiter.GetCar();
	pizza.ShowCar();
}

void main()
{
	CarBuilder * builder = new AudiCarBuilder();
	client(builder);
	delete builder;
	cout << "---------------\n";
	builder = new FordCarBuilder();
	client(builder);
	delete builder;
	system("pause");
}