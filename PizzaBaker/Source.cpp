#include <iostream>
#include <string>

using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Достоинства паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

   /*
		* Pizza (продукт) представляет сложный конструируемый объект.
		* ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
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

   // Abstract Builder задает абстрактный интерфейс (класс) для создания частей объекта Product (в нашем случае, Pizza);
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

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

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

// Director(распорядитель) - конструирует объект (Pizza), пользуясь интерфейсом Builder
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

// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
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