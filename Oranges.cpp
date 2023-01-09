
#include <iostream>

using namespace std;

void setBad(int** arr, int x, int y, int k, int l)
{

    if (x+1<l)
    {
        arr[x+1][y] = 0;
    }
    if (x-1>-1)
    {
        arr[x - 1][y] = 0;
    }
    if (y+1<k)
    {
        arr[x][y + 1] = 0;
    }
    if (y-1>-1)
    {
        arr[x][y - 1] = 0;
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
    cin >> x1 >> y1 >> x2 >> y2;
    arr[x1][y1] = 0;
    arr[x2][y2] = 0;

    while (--r)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < l; j++)
            {
                if (arr[i][j]==0)
                {
                    setBad(arr, i, j, k, l);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (arr[i][j] != 0)
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
