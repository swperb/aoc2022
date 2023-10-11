/*
    swperb

    This is my implementation of the solution for day2. Yet again, it is probably exceedingly inefficient in the game
    logic, but it is *my* solution after all. Nevertheless, it's pretty simple in that it reads the puzzle input lines
    as elements of a string vector in the format "A X", where A is p1's choice and X is p2's choice. It iterates over this
    vector and sees who won, then computes p2's score based on that (since we only care about p2).


*/


//includes for i/o, file, vector
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//one main function, could have separated, seemed unnecessary
int main() {

    //variable initialization
    vector<string> results;     //string vector to store round results
    ifstream file;              //file variable
    string match;               //string buffer for getline
    int p2score = 0;            //p2's score total counter


    //open the input file
    file.open("input.txt");


    //loop through file, reading each line at a time
    //lines indicate round results in the file
    while(getline(file, match)) {

        //push each line into the vector
        results.push_back(match);
        
    }

    //close file
    file.close();

    //loop through vector
    for(int i = 0; i < results.size(); i++) {

        //if p1 played rock and p2 played rock
        if(results[i] == "A X") {

            //draw

            //+1 for playing rock
            p2score += 1;

            //+3 for draw
            p2score += 3;

        }    

        //if p1 played rock and p2 played paper
        else if(results[i] == "A Y") {

            //p2 wins

            //+2 for playing paper
            p2score += 2;

            //+6 for winning
            p2score += 6;
        }

        //if p1 played rock and p2 played scissors
        else if(results[i] == "A Z") {

            //p1 wins

            //+3 for playing scissors
            p2score += 3;

        }

        //if p1 played paper and p2 played rock
        else if(results[i] == "B X") {

            //p1 wins

            //+1 for playing rock
            p2score += 1;

        }

        //if p1 played paper and p2 played paper
        else if(results[i] == "B Y") {

            //draw

            //+2 for playing paper
            p2score += 2;

            //+3 for draw
            p2score += 3;
        }

        //if p1 played paper and p2 played scissors
        else if(results[i] == "B Z") {

            //p2 wins

            //+3 for playing scissors
            p2score += 3;

            //+6 for winning
            p2score += 6;
        }

        //if p1 played scissors and p2 played rock
        else if(results[i] == "C X") {

            //p2 wins

            //+1 for playing rock
            p2score += 1;

            //+6 for winning
            p2score += 6;
        }

        //if p1 played scissors and p2 played paper
        else if(results[i] == "C Y") {

            //p1 wins

            //+2 for playing paper
            p2score += 2;

        }

        //if p1 played scissors and p2 played scissors
        else if(results[i] == "C Z") {

            //draw

            //+3 for playing scissors
            p2score += 3;

            //+3 for draw
            p2score += 3;
        }



        

    }
    
    //print out p2's final score for answer
    cout << "Player 2's total score: " << p2score << endl;
       
    return 0;
}