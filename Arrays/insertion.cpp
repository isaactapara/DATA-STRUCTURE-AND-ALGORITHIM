// BSE-05-0065-2024 ISAACK TAPARA

#include <iostream>
using namespace std;

void insertElement(int arr[], int& size, int value, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements right to make space
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Original array:" << endl;
    displayArray(arr, size);

    int value, pos;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position to insert at (0-based index): ";
    cin >> pos;

    insertElement(arr, size, value, pos);

    cout << "After insertion:" << endl;
    displayArray(arr, size);

    return 0;
}
