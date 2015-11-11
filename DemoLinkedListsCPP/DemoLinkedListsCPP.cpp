// DemoLinkedListsCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct trainCar {
	std::string name;
	trainCar *next;
};

void insertCar(int position_in_train, trainCar *start,std::string name) {
	// Let's assume we have 10 cars
	trainCar *newCar = new trainCar;
	newCar->name = name;
	// we need a pointer to car1 and car2
	trainCar *position = start;
	int car_number = 0;

	while (car_number < position_in_train) {
		position = position->next;
		car_number++;
	}
	// now we can do the switching, new car is given the same as position's next
	newCar->next = position->next;
	//position's next is reassigned to newCar
	position->next = newCar;
}

void deleteCar(int position_in_train, trainCar *start) {
	//okay, so i need to remove the links by reassigning the next pionter
	trainCar *position = start;
	trainCar *one_to_remove = start;
	
	int car_number = 0;
	while (car_number < position_in_train-1)
	{
		position = position->next;
		car_number++;
	}
	car_number = 0;
	while (car_number < position_in_train)
	{
		one_to_remove = one_to_remove->next;
		car_number++;
	}
		
	position->next = one_to_remove->next;
	delete one_to_remove;
	


}
int countCars(trainCar *start) 
{
	int number = 0;
	trainCar *position = start;
	if (position != 0) 	
	{
		while (position->next != 0)
		{
			position = position->next;
			number++;
		}
		return number+1;

	}
}

void printCars(trainCar *start) {
	trainCar *position = start;
	if (position != 0) { //Makes sure there is a place to start
		while (position->next != 0) {
			std::cout << position->name << std::endl;
			position = position->next;
		}
		std::cout << position->name << std::endl;
	}
}

int main()
{
	trainCar *root;      // This will be the unchanging first node
	trainCar *position; // Will point to each node 
	root = new trainCar; // Now root points to a node struct
	root->next = 0;  // The node root points to has its next pointer
					 //  set equal to a null pointer
	root->name = "engine";     // By using the -> operator, you can modify the node
					 //  a pointer (root in this case) points to.
	position = root;
	if (position->next != 0) {
		while (position->next != 0)
		{
			position = position->next;
		}
	}
	// We're at the end
	// we'll add a new car at the end
	std::cout << "How many cars (including the caboose) should we add? " << std::endl;
	int cars_to_add;
	std::cin >> cars_to_add;

	for (int x = 1; x <= cars_to_add; x++) {
		position->next = new trainCar;
		position = position->next;
		position->next = 0;
		
		if (x < cars_to_add) {
			position->name = "This is the car #" + std::to_string(x);
		}
		else {
			position->name = "Caboose";
		}
	}
	

	// Let's insert a new car, but now with some user input
	std::cout << "Do you want to insert a new car? y or n." << std::endl;
	char answer;
	std::cin >> answer;
	char answer2;
	do 
	{
		if (answer == 'y')
		{
			std::cout << "Where should we insert the car?" << std::endl;
			int new_car_position;
			std::cin >> new_car_position;
			std::cout << "What should we call the new car? (no spaces)" << std::endl;
			std::string new_car_name;
			std::cin >> new_car_name;
			insertCar(new_car_position, root, new_car_name);
		}
		std::cout << "Do you want to insert another? y or n" << std::endl;
		std::cin >> answer2;

	} while (answer2=='y');

	//Let's delete some cars
	std::cout << "Do you want to delete a car?" << std::endl;
	char answer3;
	char answer4;
	std::cin >> answer3;
	do
	{
		if (answer3 == 'y')
		{
			std::cout << "Which car should we delete?" << std::endl;
			int deleted_car_position;
			std::cin >> deleted_car_position;
			deleteCar(deleted_car_position, root);
		}
		std::cout << "Do you want to delete another? y or n" << std::endl;
		std::cin >> answer4;
	} while (answer4 == 'y');

	position = root;
	//Let's see what the trail looks like now
	std::cout << "Here's what the train loooks like:" << std::endl;
	printCars(root);
	//and let's see how many there are
	std::cout << "The number of cars is " << countCars(root) << std::endl;

	system("Pause");
}