#include "Day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm> // for std::reverse
#include <numeric>

using namespace std;

vector<int> calibrations;
list<string> reversedList;


void sumAll(vector<int> calibrations) {
	int total = accumulate(calibrations.begin(), calibrations.end(), 0);
	cout << "Total sum of calibrations: " << total << endl;
}

void extractFirstDigit(list<string> myList) {

	for (auto i : myList) {
		for (char ch : i) {
			if (isdigit(ch)) {
				calibrations.push_back(ch - '0');
				break;
			}
		}
	}
}

void extractLastDigit(list<string> myList) {
	int j = 0;

	for (auto i : reversedList) {
		for (char ch : i) {
			if (isdigit(ch)) {
				int lastDigit = ch - '0';
				calibrations[j] = calibrations[j] * 10 + lastDigit;
				j++;
				break;
			}
		}
	}
	sumAll(calibrations);

}

void reverseList(list<string> myList) {

	//go to each index and swap the strings
	for (auto str : myList) {
		reverse(str.begin(), str.end());
		reversedList.push_back(str);
	}
	extractLastDigit(reversedList);
}

void day1()
{
	list<string> myList;
	string line;
	ifstream inputFile("Day1/day1input");

	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			myList.push_back(line);
		}
		inputFile.close();

		extractFirstDigit(myList);
		reverseList(myList);

	}
	else
	{
		cerr << "Error opening the file.";
	}
}