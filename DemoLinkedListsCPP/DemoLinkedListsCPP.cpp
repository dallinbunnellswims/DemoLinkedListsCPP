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
	// now we can do the switching
	newCar->next = position->next;
	//
	position->next = newCar;
}

void deleteCar(int position_in_train, trainCar *start) {
	//okay, so i need to remove the links by reassigning the next pionter
	trainCar *position = start;
	
	int car_number = 0;
	while (car_number < position_in_train-1)
	{
		position = position->next;
		car_number++;
	}
	trainCar *one_to_remove = position;
	one_to_remove++;	
	//position->next = one_to_remove->next;
	//delete one_to_remove;
	


}
int countCars(trainCar *start) {
	int number = 0;
	trainCar *position = start;
	if (position !=0)
		while (position->next != 0)
		{
			position->next;
			number++;

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
	//std::cout << "How many cars (including the caboose) should we add? " << std::endl;
	int cars_to_add=10;
	//std::cin >> cars_to_add;

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
	

	

	// Let's insert a new car
	insertCar(5, root, "Dining Car");
	insertCar(2, root, "luggage car");
	insertCar(12, root, "New Caboose 1");
	insertCar(13, root, "New Caboose 2");
	deleteCar(3, root);
	countCars(root);



	position = root;
	printCars(root);
	

	system("Pause");
}