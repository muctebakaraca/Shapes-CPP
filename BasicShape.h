#ifndef BasicShapeClass_H
#define BasicShapeClass_H
#include <string>
#include <iostream>
using namespace std;

// The Basic Shape Class
class BasicShapeClass
{
    private:
        double area;
        string IDString;
    public:
        void setArea(double area);
        string getIDString()
        {
            return IDString;
        }
    virtual double calculateArea() = 0;
    virtual void display() = 0;

};

// Sets area
void BasicShapeClass::setArea(double a)
{
    area = a;
}


#endif
