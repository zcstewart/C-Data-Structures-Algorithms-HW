//Homework 4

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            This program was created to calculate the total amount
 *                      of paint required to paint a room that contains a door,
 *                      two windows, and a bookshelf. The user is prompted to
 *                      enter the length, width, and height of the room 
 *                      (in feet). The user is then prompted to enter the 
 *                      length and width (in feet) of the door, first window, 
 *                      second window, and bookshelf. The program then outputs
 *                      the total paintable area (feet^2). It then outputs how 
 *                      many square feet can be painted per gallon, and the 
 *                      amount of paint (gallons) required.
 *             
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/19/2017 18:36 PST
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    //Area (ft^2) that can be painted with 1 gallon of paint
    const float squareFeetPerGallon = 120;
    
    //Declare variables for the length, width, and height of the room
    float lengthRoom = 0;
    float widthRoom = 0;
    float heightRoom = 0;
    
    //Declare variables for the length and width of the door, first window,
    //second window, and third window
    float heightDoor = 0;
    float widthDoor = 0;
    float heightWindow1 = 0;
    float widthWindow1 = 0;
    float heightWindow2 = 0;
    float widthWindow2 = 0;
    float heightBookshelf = 0;
    float widthBookshelf = 0;
    
    //Declare variables for the surface area of the room (not including the
    //ceiling), door, first window, second window, and bookshelf
    float areaRoom = 0;
    float areaDoor = 0;
    float areaWindow1 = 0;
    float areaWindow2 = 0;
    float areaBookshelf = 0;
    
    //Declare variables for the total paintable area, and amount (gallons) of
    //paint required.
    float paintableArea = 0;
    int gallonsRequired = 0;
    
    //Prompt user for length, width, and height of the room
    cout << "Enter the length, width, and height of the room in ft: "
         << endl;
    cin >> lengthRoom >> widthRoom >> heightRoom;
            
    //Prompt user for the length and width of the door
    cout << "Enter the height and width of the door in ft: " << endl;
    cin >> heightDoor >> widthDoor;
    
    //Prompt user for the length and width of the first window
    cout << "Enter the height and width of the first window in ft: " << endl;
    cin >> heightWindow1 >> widthWindow1;
    
    //Prompt user for the length and width of the second window
    cout << "Enter the height and width of the second window in ft: " << endl;
    cin >> heightWindow2 >> widthWindow2;
    
    //Prompt user for the length and width of the bookshelf
    cout << "Enter the height and width of the bookshelf in ft: " << endl;
    cin >> heightBookshelf >> widthBookshelf;
    cout << endl;   
    
    //Calculate paintable area of the room (Area of 4 walls minus the area
    //of the door, first window, second window, and bookshelf)
    areaRoom = ( 2 * lengthRoom * heightRoom) + (2 * widthRoom * heightRoom); 
    areaDoor = heightDoor * widthDoor;
    areaWindow1 = heightWindow1 * widthWindow1;
    areaWindow2 = heightWindow2 * widthWindow2;
    areaBookshelf = heightBookshelf * widthBookshelf;
    paintableArea = areaRoom - areaDoor - areaWindow1 - areaWindow2 - areaBookshelf;
    
    //Calculate gallons of paint required
    gallonsRequired = ceil(paintableArea / squareFeetPerGallon);
        
    
    //Output total paintable area
    cout << "The total paintable area is: " << paintableArea
         << setprecision(1) << fixed << " ft^2." << endl;
    
    //Output square feet per gallon, and required amount of paint
    cout << "At 120 ft^2/gallon, " << gallonsRequired 
         << " gallons of paint are needed." << endl;
    
    //Exit program upon successful completion of tasks
    exit(EXIT_SUCCESS);
}