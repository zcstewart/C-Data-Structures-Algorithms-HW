//Homework 7

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is do determine the type
 *                      of line represented by two points submitted by 
 *                      the user. The points are given with respect to the
 *                      standard x-y coordinate system. The program will
 *                      prompt the user to input two points on the x-y plane.
 *                      Using the data entered by the user, the program
 *                      will determine whether the line is a horizontal,
 *                      vertical, increasing, or decreasing line.
 *                      
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/24/2017 19:26 PST
 */
#include <iostream>     //cin and cout
#include <cstdlib>      //EXIT_SUCCESS
#include <cmath>        //fabs() function
#include <iomanip>      //setprecision

using namespace std;
        
int main(int argc, char** argv) {
    
    //Declare variables to be used
    double x1, x2, y1, y2;
    double rise, run, int_b, slope_m;
    
    //Declare Junk Character to read comma
    char junk;
    
    //Prompt user to enter two points
    cout << "Please enter the first x,y point with format \"x,y\": " << endl;
    cin >> x1 >> junk >> y1;
    cout << "Please enter the second x,y point with format \"x,y\": " << endl;
    cin >> x2 >> junk >> y2;
    cout << endl << endl;
    
    //Determine Rise
    rise = y2 - y1;
    
    //Determine Run
    run = x2 - x1;
    
    if(x2 != x1)
    {
        slope_m = rise / run;
    }
    
    int_b = y2 - (slope_m * x2);
    
    //If, else if, Else loop to determine line type    
    //Line is Vertical
    if((x2 == x1) && (y2 != y1))
    {
        if(x2 < 0)
        {
            cout << "Vertical Line: x = -" << fixed << showpoint
             << setprecision(2) << fabs(x2) << endl;
        }
        else
        {
            cout << "Vertical Line: x = " << fixed << showpoint
             << setprecision(2) << x2 << endl;
        }
        
    }
    //Line is Horizontal
    else if((x2 != x1) && (y2 == y1))
    {
        if(y2 < 0)
        {
            cout << "Horizontal Line: y = -" << fixed << showpoint
             << setprecision(2) << fabs(y2) << endl;
        }
        else
        {
            cout << "Horizontal Line: y = " << fixed << showpoint
             << setprecision(2) << y2 << endl;
        }
    }
    //Line is Diagonal and Increasing (positive slope)
    else if((slope_m > 0) && (x2 != x1))
    {   
        //Negative Y-Intercept
        if(int_b < 0)
        {
            cout << "Increasing Line: y = " << fixed << showpoint
             << setprecision(2) << slope_m <<"x - " << fabs(int_b) << endl;
        }
        //Positive Y-Intercept
        else
        {
            cout << "Increasing Line: y = " << fixed << showpoint
             << setprecision(2) << slope_m <<"x + " << (int_b) << endl;
        }
    }
    //Line is Diagonal and Decreasing (negative slope)
    else if((slope_m < 0) && (x2 != x1))
    {        
        //Negative Y-Intercept
        if(int_b < 0)
        {
            cout << "Decreasing Line: y = -" << fixed << showpoint
                 << setprecision(2) << fabs(slope_m) <<"x - " 
                 << fabs(int_b) << endl;
        }
        //Positive Y-Intercept
        else
        {
            cout << "Decreasing Line: y = -" << fixed << showpoint
                 << setprecision(2) << fabs(slope_m) <<"x + " 
                 << int_b << endl;
        }
    }
    //Points are same coordinates
    else
    {
        cout << "You have entered invalid data points." << endl;
        cout << "You must enter two DIFFERENT points." << endl;
    }

    exit(EXIT_SUCCESS);
}

