/*
Title: Final Program: Fantasy Dice Roller -- DiceRollingClass Header File
Program Created by William Schaeffer
CPS 212
11.08.21
*/

#pragma once

#ifndef DICE_CLASS
#define DICE_CLASS
#include <stdio.h>										//NULL
#include <time.h>										//for time
#include <stdlib.h>										//for srand, rand
using namespace std;

//Class Declaration

class Dice
{
private:
	int maxSides;
public:
	Dice(int maxSides = 6)
	{
		this->maxSides = maxSides;						//optional constructor, default value is 6 sides
	}
	~Dice()												//default destructor
	{

	}

	int roll(int times = 1)								//To return value of number of rolls, default 1 roll
	{

		//srand(static_cast<unsigned int>(time(0)));		//Time Magic, not needed for this exercise
		
		int result = 0, randomNumber = rand();			//initialize result to return, randomNumber variable 
		
		for (int i = 0; i < times; i++)					//For multiple rolls of the same dice
		{
			result += randomNumber % maxSides - 1;
		}

		return result;
	}
};

#endif