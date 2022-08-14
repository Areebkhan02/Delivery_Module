#pragma once
#include<iostream>
using namespace std;

class Truck
{public:
    string driver;
    double petrol;
    string regNo;
    int fullMileage;
    int emptyMileage;

    Truck(string name="",double petrol1=0,string regNo1="",int fullMileage1=0,int emptyMileage1=0){
        driver=name;
        petrol=petrol1;
        regNo=regNo1;
        fullMileage=fullMileage1;
        emptyMileage=emptyMileage1;
    }
};

