#include "sensor.h"
#include <iostream>
#include <chrono>
#include <thread>

void RWA2::Sensor::read_data(unsigned int duration){
    std::cout<<"Sensor " << RWA2::Sensor::model_ 
    << " gathering data for " 
    << duration << " seconds\n";

    // Thread delayed for duration seconds
    std::this_thread::sleep_for(std::chrono::seconds(duration));

    //loop to generate sensor data
    for(int i; i < 50; i++){
        //generating a random int wi
        RWA2::Sensor::data_[i] = (rand() % 30);
    }
}