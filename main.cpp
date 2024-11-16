// Ethan Dilk | Lab 33 Toll Plaza | COMSC 210
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
    // constant to store starting # of cars & # of lanes 
    int INITIAL = 2;
    int SIMULATIONS = 5;
    // constants for probabilities
    int CAR_LEAVES = 46;
    int CAR_JOINS = 39;
    int CAR_SHIFTS = 15;

    srand(time(0));

    // create a deque to store cars
    array<deque<Car>, 4> carDequeArray;

    cout << "Intial queue:" << endl;

    // Loop through each deque in the array
    for (int d = 0; d < carDequeArray.size(); d++) {

        // add the INITIAL constant number of cars to that particular deque 
        for (int i = 0; i < INITIAL; i++) {
            Car tempCar;
            carDequeArray[d].push_back(tempCar);
        }
        // display that lane after all cars have been initially added
        cout << "Lane " << d + 1 << ":" << endl;
        displayDeque(carDequeArray[d], carDequeArray[d].size());
    }
    
    // initialize counter to track operations
    int counter = 0;

    // run 20 time period simulations 
    for (int sim = 0; sim < SIMULATIONS; sim++) {
        cout << "Time: " << sim + 1 << endl;

        




    }





    // while (carDeque.empty() == false) {

    //     // create random operation between 0 and 100
    //     int lineOperation = (rand() % 100);

    //     // if random number less than or equal to 55 --> car leaves toll both
    //     if (lineOperation <= 55) {
    //         cout << "Time: " << counter + 1 << " Operation: ";
    //         cout << "Car paid: ";
    //         // print info on the first car in the deque that is leaving
    //         carDeque.front().print();
    //         // pop the first car in line
    //         carDeque.pop_front();
    //     }
    //     // else --> car joined the lane
    //     else {
    //         // create new car
    //         Car tempCar;
    //         cout << "Time: " << counter + 1 << " Operation: ";
    //         cout << "Joined lane: ";
    //         tempCar.print();
    //         // push back a new car to the back of the line
    //         carDeque.push_back(tempCar);
    //     }
    //     cout << "Queue: " << endl;
    //     // display all elements in deque
    //     displayDeque(carDeque, carDeque.size());
    //     cout << endl;

    //     counter++;
    // }

    return 0;
}