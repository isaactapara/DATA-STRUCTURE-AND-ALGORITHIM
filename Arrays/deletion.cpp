// BSE-05-0065-2024 ISAACK TAPARA

#include <iostream>
using namespace std;

void deleteElement(int arr[], int& size, int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements left from the position
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Reduce array size
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

    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;

    deleteElement(arr, size, pos);

    cout << "After deletion:" << endl;
    displayArray(arr, size);

    return 0;
}
