/*
Title: Chapter Eighteen Search Program -- Source Code
Created by William Schaeffer
CPS 362
P. 1356, Challenge 4, Search Program, Week 11
04.07.2022
*/

#include <iostream>
#include "searchSortAlgo.hpp"
#include "DiceRollingClass.hpp"

using namespace std;

//template functions prototypes from header file

template <class elemType> int seqSearch(const elemType[], int, const elemType&);
template <class elemType> int binarySearch(elemType[], int, const elemType&);
template <class elemType> void bubbleSort(elemType[], int);
template <class elemType> void selectionSort(elemType[], int);
template <class elemType> void insertionSort(elemType[], int);
template <class elemType> void swap(elemType[], int, int);

//program function prototypes

void print(int[], int);


int main()
{
    const int n = 8;                                               //constant for intList size
	int intList[] = {16, 30, 24, 7, 62,  45, 5, 55};
    //int num = 56;                                                   //num to search for
    //int diceRoll = 0;                                               //initialize diceRoll for random numbers
    //Dice d100(100);                                                 //create 100 sided die
    

    //cout << "Please wait 25 seconds while number list is compiled..."
     //    << endl;

   // for (int i = 0; i < n; i++)
    //{
    //    intList[i] = d100.roll(2);                                  //roll 2 dice and store in intList
   // }

    print(intList, n);

    cout << "Now sorting..." << endl << endl;

    //bubbleSort(intList, n);

    selectionSort(intList, n);

    print(intList, n);

    //cout << "Now searching for the number " << num << "."
     //    << endl << endl;

    //int searchPos = binarySearch(intList, n, num);

//    if (searchPos == -1)
  //      cout << num << " was not found." << endl << endl;
    //if (intList[searchPos] == num)
      //  cout << num << " was found at position: " << searchPos 
        //     << endl << endl;
}

void print(int list[], int n)
{
    cout << "Current number list: " << endl << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "element " << i << ": " << list[i]
            << endl;
    }
}