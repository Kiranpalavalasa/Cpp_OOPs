#include <iostream>
#include <chrono>
#include <thread>

#include "sensor.h"

void RWA2::Sensor::read_data(unsigned int duration){
    // Printing the Sensor status.
    std::cout<<"Sensor " << RWA2::Sensor::model_ 
    << " gathering data for " 
    << duration << " seconds\n";

    // Making the thread sleep for the duration.
    std::this_thread::sleep_for(std::chrono::seconds(duration));

    //loop to generate sensor data.
    for(int i; i < 50; i++){
        //generating a random int with in the range of 0,30.
        RWA2::Sensor::data_[i] = (rand() % 30);
        
    }
}
