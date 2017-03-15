#include <iostream>

using namespace std;


int Partition (int *arr, int t, int l)
{
    int x = arr[l];
    int i = t - 1;
    for (int j = t; j < l; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[l]);
    return i + 1;
}

int medPartition(int *arr, int p, int r)
{
    int mid = arr[p + (r - p) / 2];
    int left = arr[p];
    int right = arr[r];

    if((mid < left) && (left < right) || (mid > left) && (left > right))
    {
        swap (left, right);
    }else
        if((mid > left) && (mid < right) || (mid < left) && (mid > right))
    {
        swap (mid, right);
    }

    return Partition(arr, p, r);
}

void qSort (int *arr, int p, int r)
{
    if (p < r)
    {
        int q = medPartition(arr, p, r);

        qSort(arr, p, q - 1);
        qSort(arr, q + 1, r);
    }

}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    qSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}
