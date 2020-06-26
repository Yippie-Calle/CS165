/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Alvey, CS165
* Author:
*    Bryan Calle
* Summary: 
*   A program that scans through a log to identify users who accessed 
*	files in a particular window of time. When a line with bad data is
*	encountered, display a message noting the bad line, but then skip 
*	it and move on.

*    Estimated:  1.0 hrs   
*    Actual:     2.0 hrs

************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//structs
struct AccessRecord
{
	string userName;
	string fileName;
	long timeStamp;
};

// constant variables
const int MAX = 500;
//ProtoTypes

string getAccessRecord();
int readFile(string recordName, AccessRecord accessRecords[]);
//void getTimes();
void display(int readCount, long startTime, long endTime, struct AccessRecord accessRecords[]);
void displayFile(AccessRecord accessRecords[], int readCount);
void displayRecord(const AccessRecord& accessRecords);
AccessRecord parseLine(string line) throw (string);

/**********************************************************************
 * Main will organize my code to work correctly. 
 ***********************************************************************/
int main()
{
	int count = 0;


	string recordName = getAccessRecord();
	AccessRecord accessRecords[MAX];

	int recordCount = readFile(recordName, accessRecords);

	long startTime;
	long endTime;

	cout << endl;
	cout << "Enter the start time: ";
	cin >> startTime;
	cout << "Enter the end time: ";
	cin >> endTime;

	display(recordCount, startTime, endTime, accessRecords);
   return 0;
}
string getAccessRecord()
{
	string recordName;
	cout << "Enter the access record file: ";
	cin >> recordName;
	// cout << endl;
	return recordName;
}



int readFile(string recordName, AccessRecord accessRecords[])
{
	int count = 0;

	ifstream fin(recordName.c_str());
	if (fin.fail())
	{
		cout << "Error opening the file.\n";
		return -1;
	}

	string line; 
	while (getline(fin, line))
	{
		try {
			AccessRecord record = parseLine(line);

			accessRecords[count] = record;
			count++;
		}
		catch (string message)
		{
			cout << message << endl;
		}
	}
	fin.close();
	return count;
}

AccessRecord parseLine(string line) throw (string)
{
	stringstream ss;
	ss.str(line);
	AccessRecord record;
	ss >> record.fileName;
	ss >> record.userName;
	ss >> record.timeStamp;
	if (ss.fail() || record.timeStamp < 1000000000 || record.timeStamp > 10000000000)
	{
		throw string("Error parsing line: ") + line;
	}
	return record;
}

void display(int readCount, long startTime, long endTime, struct AccessRecord accessRecords[])
{
	cout << endl;
	cout << "The following records match your criteria:\n";
	cout << endl;
	cout << setw(15) << "Timestamp" << setw(20) << "File" << setw(21) << "User\n";
	cout << "---------------" << " " << "-------------------" << " " << "-------------------\n";
	for (int i = 0; i < readCount; i++)
	{
		if (startTime < accessRecords[i].timeStamp && accessRecords[i].timeStamp < endTime)
		{
			displayRecord(accessRecords[i]);
		}
	}
	cout << "End of records\n";
}

void displayFile(struct AccessRecord accessRecords[], int readCount)
{
	cout << "All records\n";
	cout << "---\n";
	for (int i = 0; i < readCount; i++)
	{
		displayRecord(accessRecords[i]);
	}
	cout << "---\n";
}

void displayRecord(const AccessRecord& accessRecords)
{
	cout << setw(15) << accessRecords.timeStamp << setw(20) << accessRecords.fileName << setw(20) << accessRecords.userName;
	cout << endl;
}
