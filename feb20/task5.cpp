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

    double sumOfArr()
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr_ptr[i];
        }
        return sum;
    }

    friend void printAppendedArr(ArrayHandler &arr);
};

void printAppendedArr(ArrayHandler &arr)
{
    double num = arr.sumOfArr();
    cout << "Elements greater than last negative (" << num << "): ";
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.arr_ptr[i] < 0)
        {
            arr.arr_ptr[i] += num;
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
    printAppendedArr(handler);

    return 0;
}
