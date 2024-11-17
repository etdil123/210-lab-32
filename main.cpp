// Ethan Dilk | Lab 33 Toll Plaza | COMSC 210
#include "Car-1.h"
#include <iostream>
#include <random>
#include <deque>

using namespace std;

void displayDeque(deque<Car>, int);

// displayDeque returns no value - used to loop through a deque of Car objects and utilize built-in print method
void displayDeque(deque<Car> carDeque, int size) {
    // if the deque is empty - print out empty
    if (carDeque.empty() == true) {
        cout << "   ";
        cout << "Empty" << endl;
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
    // constant to store starting # of cars, simulations, and lanes
    int INITIAL = 2;
    int SIMULATIONS = 20;
    int LANES = 4;

    // constants for probabilities
    int CAR_LEAVES = 46;
    int CAR_JOINS = 39;
    int CAR_SHIFTS = 15;
    int EMPTY = 50;

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
        cout << "\nTime: " << sim + 1 << endl;

         // Loop through each deque in the array - so an action can occur
        for (int d = 0; d < carDequeArray.size(); d++) {
            
            // If the deque is empty - 50/50 shot of new car entering 
            if (carDequeArray[d].empty() == true) {
                int emptyLineOperation = (rand() % (100 + 1));

                // 50/50 shot of new car joining 
                if (emptyLineOperation < EMPTY) {
                    // create new car
                    Car tempCar;
                    // display info on action
                    cout << "Lane: " << d + 1 << " Car Joined: ";
                    tempCar.print();
                    // push back a new car to the back of the line
                    carDequeArray[d].push_back(tempCar); 
                }
                else 
                    // display info on action
                    cout << "Lane: " << d + 1 << " No action: " << endl;

            }
            // else deque DOES have cars - need to randomly select between car leaving, joining, or switching and perform action
            else {
                // create random operation between 0 and 100
                int lineOperation = (rand() % (100 + 1));

                // if lineOperation less than 46 --> car at head leaves 
                if (lineOperation < CAR_LEAVES) {
                    // display info on action
                    cout << "Lane: " << d + 1 << " Car Paid: ";
                    // print info on first car leaving 
                    carDequeArray[d].front().print();
                    // pop the first car in line
                    carDequeArray[d].pop_front();
                }
                // else if lineOperation is between 46 and 85 --> car joins the queue 
                else if (lineOperation > CAR_LEAVES && lineOperation < (CAR_JOINS + CAR_LEAVES)) {
                    // create new car
                    Car tempCar;
                    // display info on action
                    cout << "Lane: " << d + 1 << " Car Joined: ";
                    tempCar.print();
                    // push back a new car to the back of the line
                    carDequeArray[d].push_back(tempCar);         
                }
                // else the rear car will shift lanes to a random lane
                else {
                    // display info on action
                    cout << "Lane: " << d + 1 << " Car Switched: ";
                    // print info on the final car in the deque that will be switching 
                    carDequeArray[d].back().print();

                    // get random lane that car will switch to 
                    int randomLane;
                    do {
                        randomLane = rand() % LANES;
                    } while (d == randomLane); // make sure it is not the same lane - redo until it isn't

                    // move the last car into the end of the new randomly selected lane
                    carDequeArray[randomLane].push_back(carDequeArray[d].back());

                    // Pop that car from the original lane
                    carDequeArray[d].pop_back();

                }
            }    
        }

        // All actions have happened in that specific time period 
        // Display the queue of each lane 
        for (int d = 0; d < carDequeArray.size(); d++) {

            cout << "Lane " << d + 1 << " Queue:" << endl;
            displayDeque(carDequeArray[d], carDequeArray[d].size());
        }
    }

    return 0;
}