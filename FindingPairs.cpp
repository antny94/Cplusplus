#include <iostream>
#include <algorithm>

using namespace std;

void findPair(int bbq[], int n, int sum)
{

	sort(bbq, bbq + n);

	for (int i = 0; i < n; i++)
	{
		cout << bbq[i] << " ";
	}

	int low = 0;
	int high = 19;

	while (low < high)
	{
		if (bbq[low] + bbq[high] == sum)
		{
			cout << "Pair found: " << bbq[low] << " and " << bbq[high] << endl;
			return;
		}
			
			(bbq[low] + bbq[high] < sum)?
			
				low++:
				high--;
			
	}
}

int main()
{
	int arr[] = {8, 7, 2, 5, 3, 1, 20, 50, 60, 5, 4, 3, 8 ,11, 21, 22,23, 24, 25};

	int sum = 11;

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Sizeof(arr) = " << sizeof(arr) << endl;

	cout << "Sizeof(arr[0]) = " << sizeof(arr[0]) << endl;

	cout << "Sizeof(arr) / sizeof(arr[0] = )" << n << endl;

	cout << endl << "Pair found?" << endl;

	findPair(arr, n, sum);


	system("PAUSE");

}