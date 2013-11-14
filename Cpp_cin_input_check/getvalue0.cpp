#include "getvalue0.h"

#include <iostream>
using std::cin;
using std::cout;
using std::streamsize;

#include <limits>
using std::numeric_limits;


// errorText це повідомлення яке буде відображене якщо ввести невірне значення
// Функцію можна викликати і без цієї змінної, ось так: getValue<int>();

template <typename T>
T getValue0(const char* errorText) {
    T input;

    bool end = false;
    while(!end) {
        cin >> input;

        // cin.peek() - Зчитування одного символу із буфера, не видаляючи його
        if(cin.peek() == '\n') {
            end = true;
        } else {
            if(errorText != 0) {
                cout << errorText << "\n";
            }
        }

        cin.clear();        // Скинути флаги для потоку
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Видалити все з потоку
    }

    return input;
}
