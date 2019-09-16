#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Three non-terminal state: 0, 1, and 3
//Two final state: 2, 4

int main()
{
	// initalize variables

	string testString;
	size_t nextchar;

	// Ask user for string to test RegEx: A(A+T+G+C)*A + T(A+T+G+C)*T.
	cout << "Enter a DNA sequence." << endl;
	cin >> testString;
	cout << endl;

	//convert string to uppercase
	transform(testString.begin(), testString.end(), testString.begin(), ::toupper);

	//Start State 0

	//Goes through the string
	for (int i = 0; i < testString.length(); i++)
	{

		//checking for starting A
		if (testString[i] == 'A')
		{
			//State 1

			//checking if next char is an A
			if (testString[i + 1] == 'A')
			{
				//Checking final state 2 (a), and printing the characters in between that are applicable to the RegEx
				nextchar = testString.rfind('A');

				for (int j = i; j < nextchar + 1; j++)
				{

					if ((testString[j] == 'A') || (testString[j] == 'T') || (testString[j] == 'G') || (testString[j] == 'C'))
					{
						cout << testString[j];
					}

				}
				cout << endl;
			}

			else
			{
				//Checking final state 2

				//check for next A position
				nextchar = testString.find('A', i + 1);

				// if next A exist, print out (A+T+C+G)* inbetween the As
				if (nextchar != string::npos)
				{
					//check for (A+T+G+C)*
					for (int j = i; j <= nextchar; j++)
					{

						if ((testString[j] == 'A') || (testString[j] == 'T') || (testString[j] == 'G') || (testString[j] == 'C'))
						{
							cout << testString[j];
						}

					}
					cout << endl;
				}
			}
		}
		else
		{
			//checking for starting T
			if (testString[i] == 'T')
			{
				//State 3

				//checking if next char is a T
				if (testString[i + 1] == 'T')
				{
					nextchar = testString.rfind('T');
					// State 4
					//if another T exist, print inbetweens
						for (int j = i; j < nextchar+1; j++)
						{
							if ((testString[j] == 'A') || (testString[j] == 'T') || (testString[j] == 'G') || (testString[j] == 'C'))
							{
								cout << testString[j];
							}
						}

					cout << endl;
				}

				else
				{
					//State 3
					//check for next T position
					nextchar = testString.find('T', i + 1);

					// if next T exist, print out (A+T+C+G)* inbetween the Ts
					if (nextchar != string::npos)
					{
						// State 4

						//print for (A+T+G+C)*
						for (int j = i; j <= nextchar+1; j++)
						{

							if ((testString[j] == 'A') || (testString[j] == 'T') || (testString[j] == 'G') || (testString[j] == 'C'))
							{
								cout << testString[j];
							}

						}
						cout << endl;
					}
				}
			}
		}
	}

	system("PAUSE");
}