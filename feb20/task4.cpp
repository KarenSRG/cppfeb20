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

    double lastNeagtive()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (arr_ptr[i] < 0)
            {
                return arr_ptr[i];
            }
        }
    }

    friend void printGreaterThanLastNegative(ArrayHandler &arr);
};

void printGreaterThanLastNegative(ArrayHandler &arr)
{
    double num = arr.lastNeagtive();
    cout << "Elements greater than last negative (" << num << "): ";
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.arr_ptr[i] > num)
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
    printGreaterThanLastNegative(handler);

    return 0;
}
