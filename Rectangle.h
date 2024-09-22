#ifndef RectangleClass_H
#define RectangleClass_H

#include "BasicShape.h"
#include "LineInfo.h"

using namespace std;

// Inherited Rectangle class from basic shape class
class RectangleClass : public BasicShapeClass
{
    private:
        double width;
        double length;
        double area;
        string IDString = "Rectangle";

    public:
        string getIDString()
        {
            return IDString;
        }
        // Constructor to define default. Also handles errors.
        RectangleClass(double w, double l)
        {
            string errorString = "";
            if (w < 0 || l < 0)
            {
                try
                {
                    if (w < 0)
                    {
                        errorString += "width is negative\n";
                    }
                    throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
                }
                catch (exception& e) 
                {
                    cout << e.what() << endl;
                    cout << endl << "Press the enter key once or twice to leave..." << endl;
                    cin.ignore(); cin.get();
                }
                try 
                {
                    if (l < 0)
                    {
                        errorString += "length is negative\n";
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
            width = w;
            length = l;

            calculateArea();
            setArea(area);
        }

        // Overrides the calculate area function to calculate the area.
        double calculateArea() 
        {
        return width * length;
        }
        // Displays the information.
        virtual void display()
        {
            cout << endl;
            cout << "Shape is a Rectangle :" << endl;
            cout << "Width : " << width << endl;
            cout << "Length : " << length << endl;
            cout << "Area : " << calculateArea() << endl;
        }
        
};

#endif
