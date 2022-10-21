#include <Directions.h>
#include <Arduino.h>

class Command
{

private:

    bool checkState(const char& state) const
    {
        return state < '7' && state >= '0';
    }
    void reset()
    {
        this->state = Directions::stabilize;
    }
public:
    char getState() const
    {
        return this->state;
    }

    char readCommand() const
    {
        char iState = '0';
        if(Serial.available() > 0)
        {
            iState = Serial.read();
        }
        return iState;
    }

    void AssignState()
    {
        char iState = readCommand();
        this->state = this->checkState(iState) ? iState : this->state;
    }


private:
    char state = Directions::stabilize;
};