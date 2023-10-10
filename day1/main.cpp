/*
    swperb

    This is my implementation of day1 of AOC 2022. I used vectors due to the size of the input being unknown,
    and there is definitely a more efficient and effective method, but this is what came to my head first, which 
    speaks moreso to the point of the exercise.

    In addition, I am well aware that I could have used Introsort via std::sort (since C++11 to my knowledge), 
    but given that Introsort and Quicksort have the same time complexity O(nlogn), (and ignoring the fact that Quicksort
    is O(n^2) in its worst case) I felt that std::sort was the easy route and wanted
    to give myself the challenge of implementing Quicksort (as well as enforce my learning in DSA).
*/

//includes for i/o, file parsing of input, vectors and string functions
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//cringe namespace semantic
using namespace std;


//partition function of quicksort
//passes in total calories vector, first and last element
int partition(vector<int> &totals, const int &p, const int &r) {

    //iteration/counter variables
    //tmp for swapping
    int x;
    int i;
    int j;
    int tmp;

    //set last element as pivot
    x = totals[r];

    //put iterator at -1 index
    i = p - 1;
    
    //iterare through vector
    for (j = p; j < r; j++) {

        //if current element is less than or equal to pivot, it belongs on low side
        if(totals[j] <= x) {

            //increment iterator
            i = i + 1;

            //swap iterated element with current element
            tmp = totals[i];
            totals[i] = totals[j];
            totals[j] = tmp;
        }
    }

    //vector is partitioned, move pivot just above low side (middle of vector)
    tmp = totals[i + 1];
    totals[i + 1] = totals[r];
    totals[r] = tmp;

    //return pivot
    return i + 1;
}


//quicksort function, passes in vector, first and last element
void quicksort(vector<int> &totals, const int &p, const int &r) {

    //if list still isn't sorted
    if (p < r) {
        
        //pivot variable
        int q;

        //partition vector to find pivot
        q = partition(totals, p, r);

        //iteratively recurse on low and high side
        quicksort(totals, p, q - 1);
        quicksort(totals, q + 1, r);
    }
}



//main function
int main() {

    //two vectors, one to parse the file, the other to store calorie totals for each elf
    vector<int> calories;
    vector<int> totals;

    //variables for future use
    int num;
    int count = 0;
    int currSum = 0;

    
    //file variable
    ifstream file;

    //open given input file
    file.open("input.txt");

    
    //string buffer for getline() to read into
    string line;
    
    //loop until EOF
    while(getline(file, line)) { 
        
        //blank line separates elves
        //if a blank line is read, the size of the string will be 0 bytes
        if(line.length() == 0) {

            //push a 0 to the vector to indicate separator
            calories.push_back(0);

        }

        //otherwise, if a calorie line is read in
        else {

            //convert calorie string to int value, push it into the vector
            num = stoi(line);
            calories.push_back(num);
        }

    }

    //close file
    file.close();


    //loops the parsed file vector
    for (int i = 0; i < calories.size(); i++) {

        //if a separator is detected
        if(calories[i] == 0) {

            //increment a counter to indicate a new elf
            count++;

            //push the sum of all of the current calories to the new vector, totals
            totals.push_back(currSum);

            //reset the sum variable for new elf
            currSum = 0;


        }

        //increment calorie counter
        currSum += calories[i];
    }


    //run quicksort on totals vector
    quicksort(totals, 0, totals.size() - 1);

    
    //print out last element of vector to find greatest overall calorie value
    cout << "Highest total calories: " << totals[totals.size() - 1] << endl;


    return 0;
}