#include <iostream>
using namespace std;

class ArrayHandler {
private:
    double* arr_ptr;
    int size;

public:
    ArrayHandler(double* arr, int s) {
        size = s;
        arr_ptr = new double[size]; 
        for (int i = 0; i < size; i++) {
            arr_ptr[i] = arr[i];
        }
    }

    ArrayHandler(const ArrayHandler& other) {
        size = other.size;
        arr_ptr = new double[size];
        for (int i = 0; i < size; i++) {
            arr_ptr[i] = other.arr_ptr[i];
        }
    }
    ~ArrayHandler() {
        delete[] arr_ptr;
    }

    double midNegative() {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr_ptr[i] < 0) {
                sum += arr_ptr[i];
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
    for (int i = 0; i < arr.size; i++) {
        if (arr.arr_ptr[i] > mid_neg) {
            cout << arr.arr_ptr[i] << " ";
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
