// BSE-05-0065-2024 ISAACK TAPARA

#include <iostream>
using namespace std;

void searchElement(int arr[], int size, int key) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element " << key << " not found in the array." << endl;
    }
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {15, 28, 34, 47, 59};
    int size = 5;

    displayArray(arr, size);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    searchElement(arr, size, key);

    return 0;
}
