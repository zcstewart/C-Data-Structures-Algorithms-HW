//Homework 6

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to calculate the net
 *                      profit of a business (which is desired to be 10%) 
 *                      after paying all of the operating expenses. These 
 *                      expenses include merchandise cost, store rent, 
 *                      employee salaries, and the cost of electricity. The 
 *                      program will determine the markup that should be 
 *                      applied to the inventory in order to put the item 
 *                      on a 15% "sale". The net profit desired should be 
 *                      10% of the merchandise cost. The user will be 
 *                      prompted to enter the total cost of merchandise,
 *                      the total cost of employee salaries, the yearly 
 *                      rent, and the estimated electricity costs. The 
 *                      program will then output the total price the 
 *                      merchandise should be sold at. The program will 
 *                      then display that total revenues (after the 15%         
 *                      sale), as well is the net profit after the operating 
 *                      costs. The program will then verify that the net 
 *                      profit is 10% of the initial merchandise cost.
 * 
 *                      The desired profit percentage and sale percentage 
 *                      are constant double variables named "percentProfit" and
 *                      "percentSale", respectively.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/21/2017 12:13 PST
 */

#include<iostream>
#include<cstdlib>
#include<iomanip>


using namespace std;

int main()
{
    //Global constants for profit percentage and sale percentage
    //Also included is the markup percentage (too be determined)
    const double percentProfit = 10.0; //Desired profit percentage
    const double percentSale = 15.0;   //Desired sale price
    
    
    //Declare variables for program
    double costMerchandise = 0;         //Cost of merchandise
    double costLabor = 0;               //Cost of employee salaries
    double costRent = 0;                //Cost of rent
    double costElectricity = 0;         //Cost of electricity
    double costTotalOperating = 0;      //Operating cost
    double priceMarkup = 0;             //Price after applied markup
    double priceSale = 0;               //Price after sale   
    double profitNet = 0;               //Profit after merchandise sold on sale
    double amountMarkup = 0;            //Amount of markup
    
    //Declare "junk" char variable to read in '$'
    char junk;
    
    //Prompt user for input
    cout << "Please enter the total cost of the merchandise (including $): " << endl;
    cin >> junk >> costMerchandise;
    cout << "Please enter the total cost of all employee salaries (including $): " << endl;
    cin >> junk >> costLabor;
    cout << "Please enter the yearly rent (including $): " << endl;
    cin >> junk >> costRent;
    cout << "Please enter the estimated electricity costs (including $): " << endl;
    cin >> junk >> costElectricity;
    cout << endl << endl;
    
    //Determine total operating costs
    costTotalOperating = costMerchandise + costLabor + costRent + costElectricity;
    
    //Determine desired net profit (percentage from operating costs)
    profitNet = (percentProfit/100) * costMerchandise;
     //Determine sale price
    priceSale = profitNet + costTotalOperating;
    
    //Determine markup price (0.85*priceMarkup = priceSale)
    priceMarkup = priceSale * (100.0 / (100.0 - percentSale));
    
    //Determine total markup amount
    amountMarkup = priceMarkup - costMerchandise;
    
 
    //Output Statements
    cout << "Merchandise should be sold at $" << setprecision(2) << fixed 
         << showpoint << priceMarkup << "." << endl << endl;
    cout << "With a 15% sale, total revenues are $" << priceSale 
         << setprecision(2) << fixed << showpoint << endl << endl;
    cout << "After operating costs, the net profit is $" << profitNet
         << setprecision(2) << fixed << showpoint << "." << endl << endl;
    cout << "The net profit is calculated to be " << setprecision(1) << fixed
         << showpoint << percentProfit << "%" << endl;
    cout << "of the initial $" << setprecision(2) << fixed << showpoint 
         << costMerchandise << " merchandise cost." << endl;
    
    //Terminate program upon successful completion
    exit(EXIT_SUCCESS);
}