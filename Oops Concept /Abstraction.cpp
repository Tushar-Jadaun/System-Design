#include<iostream>
#include<string>

using namespace std;
class car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual void Car () {}
};

class SportsCar : public car{
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b ,string m){
        this->brand=b;
        this->model=m;
        isEngineOn = false;
        currentSpeed=0;
        currentGear=0;
    }

    void startEngine(){
        isEngineOn=true;
        cout<<brand<<" "<<model<<":Engine starts with a roar!"<<endl; 
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand<<" "<<" :Engine is off ! Cannot Shift Gear "<<endl;
            return;
        }
        currentGear = gear;
        cout<<brand<<" "<<model<<" :Shifted to gear "<<currentGear<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" :Engine is off ! Cannot accelerate Gear "<<endl;
            return;
        }
        currentSpeed +=20;
        cout<<brand<<" "<<model<<" :Accelerating to "<<currentSpeed<<"km/h"<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<" :Braking ! speed is now "<<currentSpeed<<"km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear =0;
        currentSpeed=0;
        cout<<brand<<" "<<model<<" :Engine turned off. "<<endl;
    }

};

int main(){
    car*myCar = new SportsCar("ford","mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}
