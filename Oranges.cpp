
#include <iostream>


using namespace std;

void setBad(int** arr, int x, int y, int k, int l, int r)
{
	int up, down, count = -1;
	up = y + r;
	down = y - r;
	//Set the oranges from the lowest cell, to the middle
	for (int i = down; i < (up + down) / 2 + 1; i++)
	{
		count++;
		for (int j = count * -1; j < count + 1; j++)
		{
			//Check if index is in boundaries
			if (i > -1 &&j+x>-1&&j+x<l)
			{
				//Set orange as rotten
				arr[i][j + x] = 0;
			}
		}
	}
	//Set the oranges from the middle, to the highest cell
	count = -1;
	for (int i = up; i > (up + down) / 2; i--)
	{
		count++;
		for (int j = count * -1; j < count + 1; j++)
		{
			//Check if index is in boundaries
			if (i < k && j + x > -1 && j + x < l)
			{
				//Set orange as rotten
				arr[i][j + x] = 0;
			}
		}
	}
}

int main()
{
	int k, l, r, x1, y1, x2, y2;


	cin >> k >> l >> r;
	int** arr = new int* [k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = new int[l];
	}
	cin >> y1 >> x1>> y2 >> x2;
	x1--;
	y1--;
	x2--;
	y2--;
	setBad(arr, x1, y1, k, l, r);
	setBad(arr, x2, y2, k, l, r);
	int sum = 0;
	for (int i = 0;i<k;i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (arr[i][j]!=0)
			{
				sum++;
			}
		}		
	}
	cout << sum;

	for (size_t i = 0; i < k; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}
