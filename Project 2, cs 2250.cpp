/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Project 2 , convert to pig latin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer : Heri Matabaro, CS 2250

#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
struct Word
{
	string english;  
	string piglatin;
};

//Function Prototype

Word* spliteSentence(const string words, int& size);
void convertToPigLatin(Word wordArr[], int size);
void displayPigLatin(const Word wordArr[], int size);

int main()
{
	string EnglishSentence;
	int size = 0;

	cout << "Please enter a string and I will convert it into piglatin";
	cout << endl;
	getline(cin, EnglishSentence);

	Word* Phrase = spliteSentence(EnglishSentence, size);
	
	for (int i = 0; i < size; i++)
	{
		cout << Phrase[i].english << " ";
		
	}
	cout << endl;
	
	//Calling the convertTopigLatin function here 
	
	convertToPigLatin(Phrase, size);
	
	return 0;

}

Word* spliteSentence(const string words, int& size)
{
	int numOfwords = 0;  //We don not know the number of words before counting them 
	char temp;
	bool check = true;

	// A for loop that will count up the number of words inside the sentence 

	for (int i = 0; i < words.length(); i++)
	{
		temp = words[i];
		if (isalpha (temp))
		{
			if (check)
			{
				//check = false;
				numOfwords++;
		    }
		}
		    else if (isspace(temp))
		{
			check = true;
		}
	}
    
	// Then allocate the new array

	Word* Phrase = new Word[numOfwords];
	
	int index = -1; //Passing the negative index 
	numOfwords = 0;
	check = true;
	
	for (int i = 0; i < words.length(); i++)
	{
		temp = words[i];
		
		if (isalpha(temp))
		{
			if (check)
			{
				check = false;
				numOfwords++;
				index++;
			}

			if (isupper(temp))
			{
				temp = tolower(temp);

		    }
		     Phrase[index].english += temp;
		}

		else if (isspace(temp))
		{
			check = true;
		}
	}
	size = numOfwords;

	return Phrase;
	
}

void convertToPigLatin(Word wordArr[], int size)
{
	// If consonant , move the first letter to the end and add "ay" , and if vowell , just add way at the end of the word.

	// First of all , reduce the lenght of the string and then put the word at the end of the string 

	string stringTwo;
	string stringThree;

	for (int i = 0; i < size; i++)
	{
		if (wordArr[i].english[0] == 'a' || wordArr[i].english[0] == 'e' || wordArr[i].english[0] == 'u' || wordArr[i].english[0] == 'i' || wordArr[i].english[0] == 'o')
		{
            wordArr[i].piglatin = wordArr[i].english + "way";
        }
		else
		{
			stringTwo = wordArr[i].english.substr(0, 1) + "ay";

			stringThree = wordArr[i].english.erase(0, 1);

			wordArr[i].piglatin = stringThree + stringTwo;

			stringThree = "";
			stringTwo = "";

		}
	}

	displayPigLatin(wordArr, size);

}

void displayPigLatin(const Word wordArr[], int size)
{
	cout << "Here is Your sentence in pigLatin : ";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << wordArr[i].piglatin << " ";
	}
}
