// BSE-05-0065-2024 ISAACK TAPARA

#include <iostream>
using namespace std;

void updateElement(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }

    cout << "Updating index " << index << " from " << arr[index] << " to " << newValue << endl;
    arr[index] = newValue;
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {11, 22, 33, 44, 55};
    int size = 5;

    cout << "Original array:" << endl;
    displayArray(arr, size);

    int index, newValue;
    cout << "Enter index to update (0-based): ";
    cin >> index;
    cout << "Enter new value: ";
    cin >> newValue;

    updateElement(arr, size, index, newValue);

    cout << "After update:" << endl;
    displayArray(arr, size);

    return 0;
}
