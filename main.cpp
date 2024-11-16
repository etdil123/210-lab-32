#include "Car-1.h"
#include <iostream>
#include <random>
#include <deque>

using namespace std;

void displayDeque(deque<Car>, int);

void displayDeque(deque<Car> carDeque, int size) {
    // if the deque is empty - print out empty
    if (carDeque.empty() == true) {
        cout << "   ";
        cout << "Empty";
    }
    else {
        // for each element in deque - using Car print method 
        for (int i = 0; i < size; i++) {
            cout << "   ";
            carDeque[i].print();
        }
    }
}

int main() {
    // constant to store starting # of cars
    int INITIAL = 2;
    srand(time(0));

    // create a deque to store cars
    deque<Car> carDeque;

    // add the INITIAL constant number of cars to deque 
    for (int i = 0; i < INITIAL; i++) {
        Car tempCar;
        carDeque.push_back(tempCar);
    }
    // display initial queue
    cout << "Initial queue:" << endl;
    displayDeque(carDeque, carDeque.size());
    
    // initialize counter to track operations
    int counter = 0;

    while (carDeque.empty() == false) {

        // create random operation between 0 and 100
        int lineOperation = (rand() % 100);

        // if random number less than or equal to 55 --> car leaves toll both
        if (lineOperation <= 55) {
            cout << "Time: " << counter + 1 << " Operation: ";
            cout << "Car paid: ";
            // print info on the first car in the deque that is leaving
            carDeque.front().print();
            // pop the first car in line
            carDeque.pop_front();
        }
        // else --> car joined the lane
        else {
            // create new car
            Car tempCar;
            cout << "Time: " << counter + 1 << " Operation: ";
            cout << "Joined lane: ";
            tempCar.print();
            // push back a new car to the back of the line
            carDeque.push_back(tempCar);
        }
        cout << "Queue: " << endl;
        // display all elements in deque
        displayDeque(carDeque, carDeque.size());
        cout << endl;
        
        counter++;
    }

    return 0;
}