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

    double midAll()
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr_ptr[i];
        }
        return sum / size;
    }

    friend void printLowerThanMid(ArrayHandler &arr);
};

void printLowerThanMid(ArrayHandler &arr)
{
    double mid = arr.midAll();
    cout << "Elements lower than mid (" << mid << "): ";
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.arr_ptr[i] < mid)
        {
            cout << arr.arr_ptr[i] << " ";
        }
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
    printLowerThanMid(handler);

    return 0;
}
