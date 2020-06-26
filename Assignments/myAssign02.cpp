/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Bryan Calle
* Summary: 
*    We will be lookin git inspect system of logs to see who timed in and out. 
*
*    Estimated:  2.0 hrs   
*    Actual:     1.0 weeks
*      How to make my function display what it is supposed to display. 
*		passing structs
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
	int count = 0;
	//char recordName[256];

	string recordName = getAccessRecord();
	AccessRecord accessRecords[MAX];
	//getAcccessRecord(recordName);
	//readFile(recordName, accessRecords, &count);
	int recordCount = readFile(recordName, accessRecords);

	long startTime;
	long endTime;

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
	cout << endl;
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
	//We will be taking this out for assignment 3
	while (!fin.eof())
	{
		fin >> accessRecords[count].userName;
		fin >> accessRecords[count].fileName;
		fin >> accessRecords[count].timeStamp;
		if (!fin.fail())
		{
			count++;
		}
	}
	/*else
	{
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> accessRecords[i].userName;
			fin >> accessRecords[i].fileName;
			fin >> accessRecords[i].timeStamp;
			count++;
		}*/
	fin.close();
	return count;
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
		//cout << setw(15) << accessRecords[i].timeStamp << setw(20) << accessRecords[i].fileName << setw(21) << accessRecords[i].userName << "\n";
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
	cout << setw(15) << accessRecords.timeStamp << setw(20) << accessRecords.userName << setw(20) << accessRecords.fileName;
	cout << endl;
}

/*void getTimes()
{
	double startTime;
	double endTime;
	cout << "Enter the start time: ";
	cin >> startTime;
	cout << "Enter the end time: ";
	cin >> endTime;
}
*/