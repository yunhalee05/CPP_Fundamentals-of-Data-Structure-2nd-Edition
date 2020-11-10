#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


class orderedlist
{
private:
	int size;
	float* arr;
public:
	orderedlist(int n) : size(n)
	{
		arr = new float[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = 0;
		}

	}
	~orderedlist()
	{
		delete[] arr;
	}
	int length()//(1)
	{
		return size;
	}
	int Read()//(2)
	{
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	int Retrieve(int i)//(3)
	{
		return arr[i];
	}
	int Store(int i, int x)//(4)
	{
		arr[i] = x;
	}
	int Insert(int i, int x)//(5)
	{
		int n = size + 1;
		float* arr2;
		arr2 = new float[n];

		if (i < size)
		{
			for (int j = size; j <= i; j++)
			{
				arr2[j + 1] = arr[j];
			}
			for (int j = 0; j < i; j++)
			{
				arr2[j] = arr[j];
			}
			arr2[i] = x;
		}
		else
		{
			cout << "Error" << endl;
		}
	}
	int Delete(int i)//(6)
	{
		int n = size - 1;
		float* arr2;
		arr2 = new float[n];
		if (n == 0)
		{
			cout << "Error" << endl;
		}
		else
		{
			for (int j = i; j < n; j++)
			{
				arr2[j] = arr[j + 1];
			}
			for (int j = 9; j < i; j++)
			{
				arr2[j] = arr[j];
			}

		}
	}
};