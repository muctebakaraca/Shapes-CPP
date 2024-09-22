#ifndef CircleShapeClass_H
#define CircleShapeClass_H

#include "BasicShape.h"
#include "LineInfo.h"
#include <string>

using namespace std;

// The inherited Circle shape class that derives from the basic shape class
class CircleShapeClass : public BasicShapeClass
{
    private:
        double PI;
        double centerX;
        double centerY;
        double radius;
        string IDString = "Circle";

    public:
    // Overrides the virtual class to calculate circle area
    virtual double calculateArea()
    {
        return (PI * radius * radius);
    };

    // Displays the necessary information
    virtual void display()
    {
        cout << endl;
        cout << "Shape is a circle :" << endl;
        cout << "centerX : " << centerX << endl;
        cout << "centerY : " << centerY << endl;
        cout << "Radius : " << radius << endl;
        cout << "Area : " << calculateArea() << endl;
    }
// Constructor makes the default circle class. Also checks errors.
CircleShapeClass(double x, double y, double r)
{
    string errorString = "";
    if (x < 0 || y < 0 || r < 0)
    {
        try 
        {
            if (x < 0)
            {
                errorString += "x is negative\n";
            }
            if (y < 0)
            {
                errorString += "y is negative\n";
            }
            if (r < 0)
            {
                errorString += "radius is negative\n";
            }
            throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
        }
        catch (exception& e) 
        {
            cout << e.what() << endl;
            cout << endl << "Press the enter key once or twice to leave..." << endl;
            cin.ignore(); cin.get();
        }
    }
    centerX = x; 
    centerY = y;
    radius = r;
    PI = 3.14159;

    double a = calculateArea();

    setArea(a);
}

    
        

};


#endif
