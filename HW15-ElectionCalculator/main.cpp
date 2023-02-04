//Homework 15

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to determine the winner
 *                      of an election 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/31/2017 15:34 PST
 */

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <iomanip>

//Namespace
using namespace std;

//Declare global constant N for number of candidates
const int N = 5;

//--------------------------------------------------------------------------//

//Function Definitions

// Reads in the Voting Data
void getVotes(string candidates[N], int votes[N], int &totalVotes);

// Calculates the Voting Percentages
void calculatePercentages(const int votes[N], const int totalVotes,
                          double percentages[N]);

// Calculates the Election Winner
void calculateWinner(const int votes[N], int &winnerIndex);

// Prints the Election Results to Terminal
void printResults(const string candidates[N], const int votes[N],
                  const int totalVotes, const double percentages[N],
                  const int winnerIndex); 

//--------------------------------------------------------------------------//

// Main function
int main(int argc, char** argv)
{
    string name[N] = {};    // Array of strings for candidate names
    int votes[N] = {0};     // Array of integers for vote count
    int num_votes = 0;      // Integer for total number of votes
    int wIndex;             // Integer for winnder index
    double percent_votes[N] = {0};  // Double array containing percent of total vote
    //cout.imbue(locale("en_US.UTF-8"));
     
    getVotes(name, votes, num_votes);
    calculatePercentages(votes, num_votes, percent_votes);
    calculateWinner(votes, wIndex);
    printResults(name, votes, num_votes, percent_votes, wIndex);
       
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

//Function:     void getVotes(string candidates[N], int votes[N], int &totalVotes)
//
//Inputs:       string candidates[N], int votes[N], int &totalVotes
//Outputs:      void
//Purpose:      The purpose of this function is to prompt the user for candidate names
//              and the amount of votes they received, then store in separate arrays
void getVotes(string candidates[N], int votes[N], int &totalVotes)
{
    if(!cin)
    {
        cout << "Invalid input stream" << endl;
        exit(EXIT_FAILURE);
    }

    //Prompt user to enter candidate name and votes received
    for(int i = 0; i < N ; i++)
    {
        cout << "Enter candidate name and number of votes (ex: Donald 50): " << endl;
        cin >> candidates[i] >> votes[i];
        totalVotes += votes[i];
    }// Calculates the Voting Percentages
    cout << endl << endl;
}

//Function:     calculatePercentages(const int votes[N], const int totalVotes, double percentages[N])
//
//Inputs:       const int votes[N], const int totalVotes, double percentages[N]
//Outputs:      void
//Purpose:      The purpose of this function is to calculate the percentage of the total vote each
//              candidate received
void calculatePercentages(const int votes[N], const int totalVotes,
                          double percentages[N])
{
    int vote_Total;
    for(int i = 0; i < N; i++)
    {
        vote_Total = votes[i];
        percentages[i] = (((static_cast<double>(vote_Total)*100.0) / totalVotes));
    }
}

//Function:     void calculateWinner(const int votes[N], int &winnerIndex)
//
//Inputs:       const int votes[N], int &winnerIndex
//Outputs:      void
//Purpose:      The purpose of this function is to calculate the winner of the election
//              by returning (through reference) the index of the candidate with the most
//              votes
void calculateWinner(const int votes[N], int &winnerIndex)
{
    winnerIndex = 0;
    for(int i = 0; i < N; i++)
    {
        if(votes[i] > winnerIndex)
        {
            winnerIndex = i;
        }
    }
}

//Function:     void printResults(const string candidates[N], const int votes[N], 
//                                const int totalVotes, const double percentages[N],
//                                const int winnerIndex)
//
//Inputs:       (const string candidates[N], const int votes[N], 
//               const int totalVotes, const double percentages[N],
//               const int winnerIndex)
//Outputs:      void
//Purpose:      The purpose of this function is to print a table of the candidates,
//              votes received, percentage of total vote, total votes, and winner of the 
//              election using formatting.
void printResults(const string candidates[N], const int votes[N],
                  const int totalVotes, const double percentages[N],
                  const int winnerIndex)
{
    string candidate = "Candidate";
    string recievedVotes = "Votes Received";
    string percentVotes = "\% of Total Votes";
    
    string sumVotes = "Total:";
    string electionWinner = "The Winner of the Election is: ";
    
    cout << left << setw(20) << candidate << setw(20) << recievedVotes
                 << setw(20) << percentVotes << endl << endl;

    for(int i = 0; i < N; i++)
    {
        cout << left;
        cout << setw(20) << candidates[i];
        cout << setw(20) << votes[i];
        cout << fixed << showpoint << setprecision(2) << setw(20);
        cout << percentages[i];
        cout << endl << endl;
    }
    cout.unsetf(ios::fixed);
    cout << left << setw(20) << sumVotes;
    cout << setw(20) << totalVotes << endl << endl;
    cout << setw(20) <<electionWinner<< candidates[winnerIndex];
    cout << endl << endl;
}