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
    // constant to store starting # of cars, simulations, and lanes
    int INITIAL = 2;
    int SIMULATIONS = 5;
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
        cout << "Time: " << sim + 1 << endl;

         // Loop through each deque in the array - so an action can occur
        for (int d = 0; d < carDequeArray.size(); d++) {
            
            // If the deque is empty - 50/50 shot of new car entering 
            if (carDequeArray[d].empty() == true){
                int emptyLineOperation = (rand() % (100 + 1));
                
                // 50/50 shot of new car joining 
                if (emptyLineOperation < EMPTY) {
                    // create new car
                    Car tempCar;
                    // display info on action
                    cout << "Lane: " << d + 1 << "Car Joined: ";
                    tempCar.print();
                    // push back a new car to the back of the line
                    carDequeArray[d].push_back(tempCar); 
                }

            }
            // else deque has cars - need to randomly select between car leaving, joining, or switching
            else {
                // create random operation between 0 and 100
                int lineOperation = (rand() % (100 + 1));

                // if lineOperation less than 46 --> car at head leaves 
                if (lineOperation < CAR_LEAVES) {
                    // display info on action
                    cout << "Lane: " << d + 1 << "Car Paid: ";
                    // print info on first car leaving 
                    carDequeArray[d].front().print();
                    // pop the first car in line
                    carDequeArray[d].pop_front();
                }
                // else if lineOperation is between 46 and 85 --> car joins the queue 
                else if (lineOperation > CAR_LEAVES && lineOperation <= (CAR_JOINS + CAR_LEAVES)) {
                    // create new car
                    Car tempCar;
                    // display info on action
                    cout << "Lane: " << d + 1 << "Car Joined: ";
                    tempCar.print();
                    // push back a new car to the back of the line
                    carDequeArray[d].push_back(tempCar);         
                }
                // else the rear car will shift lanes to a random lane
                else {
                    // display info on action
                    cout << "Lane: " << d + 1 << "Car Switched: ";
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