#include "Car-1.h"
#include <deque>

using namespace std;

void displayDeque(deque<Car>, int);

void displayDeque(deque<Car> carDeque, int size) {

    // for each element in deque - using print method 
    for (int i = 0; i < size; i++) {
        cout << "   ";
        carDeque[i].print();
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
        carDeque.push_front(tempCar);
    }

    cout << "Initial queue:" << endl;
    displayDeque(carDeque, carDeque.size());

    return 0;
}