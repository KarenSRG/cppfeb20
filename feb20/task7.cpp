#include <iostream>
using namespace std;

class ArrayHandler
{
private:
    double *arr_ptr;
    int size;

public:
    ArrayHandler(double *arr, int s)
    {
        size = s;
        arr_ptr = arr;
    }

    double MinOfArr()
    {
        double min = arr_ptr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr_ptr[i] < min)
            {
                min = arr_ptr[i];
            }
        }
        return min;
    }

    friend void printAppendedNegative(ArrayHandler &arr);
};

void printAppendedNegative(ArrayHandler &arr)
{
    double num = arr.MinOfArr();
    cout << "Elements greater than last negative (" << num << "): ";
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.arr_ptr[i] > 0)
        {
            arr.arr_ptr[i] -= num;
        }
        cout << arr.arr_ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    double arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ArrayHandler handler(arr, n);
    printAppendedNegative(handler);

    return 0;
}
