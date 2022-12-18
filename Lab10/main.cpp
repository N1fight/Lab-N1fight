#include <iostream>
#include <vector>

class Part
{
private:

	std::string m_engine;
	std::string m_chassis;
	std::string m_carcase;

public:

	Part(std::string engine, std::string chassis, std::string carcase) 
	{
		m_engine = engine;
		m_chassis = chassis;
		m_carcase = carcase;
	}
	std::string Engine() 
	{
		return m_engine;
	}
	std::string Chassis() 
	{
		return m_chassis;
	}
	std::string Carcase()
	{
		return m_carcase;
	}
};

class Car 
{
private:

	unsigned int m_id;
	std::string m_model;
	std::vector<Part*> m_parts;

public:

	Car(unsigned int id, std::string model) 
	{
		m_id = id;
		m_model = model;
	}

	void AddPart(Part*& part) 
	{
		m_parts.push_back(part);
	}

	void PrintPart() 
	{
		for (size_t i = 0; i < m_parts.size(); i++) 
		{
			std::cout << m_parts[i]->Engine() << std::endl;
			std::cout << m_parts[i]->Chassis() << std::endl;
			std::cout << m_parts[i]->Carcase() << std::endl;
		}
	}
};

int main()
{

	Car* car = new Car(0, "Light vehicles");

	Part* part1 = new Part("Carbureted", "Automotive", "Sedan");
	car->AddPart(part1);

	Part* part2 = new Part("Diesel", "Vania", "Station wagon");
	car->AddPart(part2);

	Part* part3 = new Part("Petrol", "Stone", "Coupe");
	car->AddPart(part3);


	car->PrintPart();
	delete car;

	return 0;
}
