#include <iostream>
#include <vector>

using namespace std;

class ArrayHandler {
private:
    vector<double> arr;
    int size;

public:
    ArrayHandler(double* arr_ptr, int s) {
        size = s;
        arr.assign(arr_ptr, arr_ptr + s); 
    }

    ArrayHandler(const ArrayHandler& other) {
        size = other.size;
        arr = other.arr;
    }

    double midNegative() {
        double sum = 0;
        int count = 0;
        for (double num : arr) {
            if (num < 0) {
                sum += num;
                count++;
            }
        }
        return (count > 0) ? (sum / count) : 0;
    }

    friend void printGreaterThanMidNegative(ArrayHandler arr);
};

void printGreaterThanMidNegative(ArrayHandler arr) {
    double mid_neg = arr.midNegative();
    cout << "Elements greater than mid_negative (" << mid_neg << "): ";
    for (double num : arr.arr) {
        if (num > mid_neg) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    double arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ArrayHandler handler(arr, n);
    printGreaterThanMidNegative(handler);

    return 0;
}
