#include <iostream>
#include <string>

//Factory Method example

class Animal {
public:
	virtual ~Animal() {}
	std::string type_of_animal;

	static Animal* getAnimalType(std::string type_of_animal);
};

class Cat : public Animal {
public:
	Cat()
	{
		type_of_animal = "cat";
	}
};

class Dog : public Animal {
public:
	Dog()
	{
		type_of_animal = "dog";
	}
};

Animal* Animal::getAnimalType(std::string type_of_animal)
{
	if (type_of_animal == "cat") return new Cat();
	else if (type_of_animal == "dog") return new Dog();
	else return 0;

}

int main()
{
	Animal* cats = Animal::getAnimalType("cat");
	std::cout << cats->type_of_animal << std::endl;

	Animal* dogs = Animal::getAnimalType("dog");
	std::cout << dogs->type_of_animal << std::endl;
}