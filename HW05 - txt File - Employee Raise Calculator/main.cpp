//Homework 5

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to read input from a 
 *                      txt file, and write output to a txt file. The 
 *                      information read in is in the order last name, 
 *                      first name, salary, and percent amountRaise. The output 
 *                      text file will write data in the order of first name, 
 *                      last name, and new salary.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/26/2017 12:13 PST
 */

#include<iostream>      //<< and >> operators
#include<iomanip>       //setw() function
#include<cstdlib>       //exit(EXIT_SUCCESS)
#include<fstream>       //ifstream, ofstream
#include<string>        //string class
#include<locale>        //locale to be imbued
#include<algorithm>     //count function
#include<sstream>       //stringstream

using namespace std;

//User defined function to covert a double to its dollar amount
//Accomplished with the imbue function and a stringstream
string dollarConvert(double amt)
{
    stringstream dollarAmt;
    locale myLocale("en_US.UTF-8");
    dollarAmt.imbue(myLocale);
    dollarAmt << fixed << showpoint << setprecision(2) << amt;
    return dollarAmt.str();
}

int main(int argc, char** argv)
{
    //Declare variables for use in program
    string nameFirst, nameLast, nameFull;
    double salary, amountRaise, percentamountRaise;
    int fileLength;
    
    //Declare file stream variables
    ifstream inData;
    ofstream outData;
    
    //Associate the file stream variables with input and output txt files
    inData.open("SalaryData.txt");
    
    if(!inData)
    {
        cout << "Failed to open file" << endl;
        exit(EXIT_FAILURE);
    }
    outData.open("SalaryamountRaises.txt");
    
    //Determine length of file to be used with for loop
    fileLength = count(istreambuf_iterator <char> (inData), 
                       istreambuf_iterator <char> (), '\n');
    
    //Return to beginning of file
    inData.seekg(0);
    
    //Do while to traverse through txt file
    for(int i = 0; i < fileLength; i++)
    {
        //Read data in from SalaryData.txt
        inData >> nameLast >> nameFirst >> salary >> percentamountRaise;
        
        //Determine full name
        nameFull = nameFirst + " " + nameLast;
        
        //Compute amountRaise
        amountRaise = salary * (percentamountRaise / 100.0);
        
        //Add amountRaise to salary
        salary = salary + amountRaise;
                
        //Write data out to SalaryamountRaises.txt
        outData << fixed << showpoint << setprecision(2) << setw(14) << left;  
        outData << nameFull << "\t" << "$" << dollarConvert(salary) << endl;
    }
    
    //Close the text files upon completion
    inData.close();
    outData.close();
    
    //Terminate program upon successful completion
    exit(EXIT_SUCCESS);
}
