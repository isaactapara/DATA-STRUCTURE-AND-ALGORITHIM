/*
 * BSE-05-0065-2024 ISAACK TAPARA
 * Implementation of simple stack in C++
 */

#include <iostream>
#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; --i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    int numElements, value;

    std::cout << "How many elements do you want to push to the stack? ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        std::cout << "Enter value #" << (i + 1) << ": ";
        std::cin >> value;
        s.push(value);
    }

    s.display();

    std::cout << "Popped: " << s.pop() << "\n";
    s.display();

    std::cout << "Top element: " << s.peek() << "\n";
    return 0;
}
