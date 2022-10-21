#include <Arduino.h>
#include <Servo.h>

class Motor
{
public:
    Motor(int pin):
    pin(pin)
    ,speed(0)
    {
        ESC.attach(pin);
    }

    void updateSpeed(int ds)
    {
        this->speed = this->speed + ds > this->limit ? this->limit : this->speed + ds;
    }

    void run()
    {
        this->ESC.write(this->speed);
    }

    size_t getSpeed() const 
    {
        return this->speed;
    }


private:
    const int pin;
    int speed;
    Servo ESC;
    static constexpr int limit = 100;
};
