// SortedDriver.cpp

// Evan Mora
// Construct sorted sequences and call functions that 
//   process the sorted sequences.


#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	sort(begin(theList), end(theList));

	return theList;
}


// post: a sorted list of numWords words of length
//         wordLength with characters chosen randomly from
//         alphabet has been returned.
list<string>
getWords(size_t numWords, size_t wordLength, string alphabet)
{
	list<string> theWords;
	for (size_t i = 0; i < numWords; ++i)
	{
		string word;
		for (size_t j = 0; j < wordLength; ++j)
		{
			word += alphabet.at(randInt(0, alphabet.size()));
		}
		theWords.push_back(word);
	}

	theWords.sort();

	return theWords;
}


// pre:  number is not empty; 
//       number is sorted from smallest to largest
// post: The most isolated entry in number has been returned
double
mostIsolated(vector<double> & number)
{
	int mostIsolatedLoc(0);
	double magnitude(0);
	for (int i(0); i <number.size(); i ++)
		if (i == 0)
		{
			double temp1 = number[i] - number[i + 1];
			checkNegative(temp1);
			if (temp1 > magnitude)
			{
				magnitude = temp1;
				mostIsolatedLoc = i;
			}
		}
		else if (i == number.size() - 1)
		{
			double temp2 = numnber[i] - number[i - 1];
			checkNegative(temp2);
			if (temp2 > magnitude)
			{
				magnitude = temp2;
				mostIsolatedLoc = i;
			}
		}
		else {

			double temp1 = number[i] - number[i - 1];
			double temp2 = number[i] - number[i + 1];
			checkNegitive(temp2);
			checkNegitive(temp1);
			if (temp1 < temp2) {
				if (temp1 > magnitude) {
					magnitude = temp1;
					mostIsolatedLocation = i;
				}
			}
			else if (temp2 > magnitude) {
				magnitude = temp2;
				mostIsolatedLocation = i;
			}
		}
}
return number[mostIsolatedLoc];
	}


// pre:  A and B are sorted.
// post: The number of strings in A that do not occur in B
//         has been returned.
int
unmatched(list<string> & A, list<string> & B)
{
	//setup
	int test(0);
	list<string>::iterator AList = A.begin();
	list<string>::iterator BList = B.begin();
	bool has = false;

	
	for (AList; AList != A.end(); AList++) {
		has = false;
		while (BList != B.end()) {
		if (*AList == *BList) {
		has = true;
		break;
			}
			else if (*AList < *BList) {
				B.pop_front();
				break;
			}
			else if (*BList<*AList)
				BList++;
		}
		if (has == false) {
			test++;
		}
	}
	return test;
}


int
main()
{
	cout << "Find the most isolated number" << endl
		<< "-----------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (n < 10)
			cout << numbers << endl << endl;

		// Report a most isolated isolated number
		Timer time;
		time.start();
		double isolated = mostIsolated(numbers);
		time.stop();
		cout << "The most isolated number is "
			<< isolated << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}


	cout << endl << endl;
	cout << "Count the unmatched words" << endl
		<< "-------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for words lists: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter word length: ";
		int wordSize;
		cin >> wordSize;
		cout << "Enter alphabet: ";
		string alphabet;
		cin >> alphabet;

		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct two sorted vectors of words
		Timer get;
		get.start();
		list<string> A = getWords(n, wordSize, alphabet);
		list<string> B = getWords(n, wordSize, alphabet);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (wordSize * n < 60)
		{
			cout << "A is: " << A << endl
				<< "B is: " << B << endl;
		}

		// Report the number of words in the first sorted list
		//   that are not in the second sorted list
		Timer time;
		time.start();
		int count = unmatched(A, B);
		time.stop();
		cout << count
			<< " words in A were not in B" << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}

	return 0;
}