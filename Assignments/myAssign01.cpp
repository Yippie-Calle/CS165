/***********************************************************************
* Program:
*    Assignment 01, Genetic Geneology  
*    Brother Alvey, CS165
* Author:
*    Bryan Calle
* Summary: 
*   This program will assist us in finding match in partners. 

*    Estimated:  2.0 hrs   
*    Actual:     24.0 hrs
*      trying to do the comparison of the two arrays to make a string. 
************************************************************************/

#include <iostream>
#include <string>

using namespace std;
/**********************************************************************
 * ProtoTypes
 ***********************************************************************/

void promptForRelativesNames(string[], int count);
void promptForRelativesDna(string nameList[], string dnaList[], int count);
int computeMatch(string dna1, string dna2);
void displayMatchPercent(string userDna, string nameList[], string dnaList[], int count);


/**********************************************************************
 * Function: Main will map out the order of events. 
 * Purpose: Main driver.
 ***********************************************************************/
int main()
{
	const int MAX_COUNT = 50;
	string nameList[MAX_COUNT];
	string dnaList[MAX_COUNT];

	string userDna;
	cout << "Enter your DNA sequence: ";
	cin >> userDna;

	int count;
	cout << "Enter the number of potential relatives: ";
	cin >> count;

	promptForRelativesNames(nameList, count);
	promptForRelativesDna(nameList, dnaList, count);

	displayMatchPercent(userDna, nameList, dnaList, count);

   return 0;
}

void promptForRelativesNames(string nameList[], int count)
{
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Please enter the name of relative #" << i + 1 << ": ";
		cin >> nameList[i];
	}
}

void promptForRelativesDna(string nameList[], string dnaList[], int count)
{
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Please enter the DNA sequence for ";
		cout << nameList[i];
		cout << ": ";
		cin >> dnaList[i];
	}
}

int computeMatch(string userDna, string dnaList)
{
	int match = 0; 
	for (int i = 0; i < userDna.length(); i++)
	{
		if (userDna[i] == dnaList[i])
			match += 10; 
	}
	return match;
}

void displayMatchPercent(string userDna, string nameList[], string dnaList[], int count)
{
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		int percent = computeMatch(userDna, dnaList[i]);
		cout << "Percent match for " << nameList[i] << ": " << percent << "%\n";
	}
}
