/*

    Program Name: Shapes Assignment
    Date Written: 04/22/2024
    Author      : Mucteba Karaca
    Module Purpose:
    This program demonstates the use of classes and polymorphism through a demonstation of 
    a base shape class and its children, the specific shapes.  
*/
// Includes any possibly necessary libraries using the standard namespace.
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "LineInfo.h"
#include <iostream>
#include <fstream>
using namespace std;

// The main function of the program
int main()
{
    // Sets the constant integer of number shapes to 3
    const int NUMBER_SHAPES = 3;
    // Makes a three entry array of BasicShape objects
    BasicShapeClass * shapesArray[NUMBER_SHAPES]; 

    // Initializes necessary counters and tracker variables
    bool done = false;
    int choice = 0;
    int shapesCounter = 0;
    
    cout << "Choose 3 shapes and enter attributes, when all 3 shapes are entered the calculated results for all 3 shapes will display" << endl;

    // Loops through until the done variable is set to true
    while (done == false)
    {
        
        cout << "Choose your shape : " << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        // Sets the errorString to empty string
        string errorString = "";

        // Applies basic error handling on the choice to assure it is in the correct range.
        if (choice < 1 || choice > 2)
        {
            // Try/Catch to properly implement exception handling
            try
            {
                if (choice < 1)
                {
                    errorString += "Choice cannot be below 1\n";
                    throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
                }
            }
            catch (exception& e) 
            {
                cout << e.what() << endl;
                cout << endl << "Press the enter key once or twice to leave..." << endl;
                cin.ignore(); cin.get();
            }
            try
            {
                if (choice > 2)
                {
                    errorString += "Choice cannot be above 2\n";
                    throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
                }
            }
            catch (exception& e) 
            {
                cout << e.what() << endl;
                cout << endl << "Press the enter key once or twice to leave..." << endl;
                cin.ignore(); cin.get();
            }
            cout << "Please try again....." << endl;
        }
        // If the choice is valid, proceeds
        else
        {
            // Decides which choice was chosen
            if (choice == 1)
            {
                // Sets the necessary variables for use
                double x, y, radius;

                // Ingests the necessary variables
                cout << "Enter the circle's x, y, radius : ";
                cin >> x >> y >> radius;

                // Sets the object in the shapesArray array of objects at the index to a Circle object
                shapesArray[shapesCounter] = new CircleShapeClass(x, y, radius);

                // Iterates the number of valid shapes
                shapesCounter++;
            }
            else if (choice == 2)
            {
                // Sets the necessary variables for use
                double length, width;
                // Ingests the necessary variables
                cout << "Enter the rectangle's length, width : ";
                cin >> length >> width;
                // Sets the object in the shapesArray array of objects at the index to a Circle object
                shapesArray[shapesCounter] = new RectangleClass(width, length);   
                // Iterates the number of valid shapes
                shapesCounter++;
            }
            if (shapesCounter >= 3)
            {
                // Decides if there are 3 valid shapes, if so, marks Done as true.
                done = true;
            }
        }
    }

    // Uses the display virtual method to display the necessary information at the given index of shapesArray
    for (int i = 0; i < NUMBER_SHAPES; ++i) {
        shapesArray[i]->display();
    }



}
