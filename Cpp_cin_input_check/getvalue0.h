#ifndef GETVALUE0_H
#define GETVALUE0_H

//  Шаблон не можна розбити на декілька файлів

#include <iostream>
#include <limits>

namespace my {
using std::cin;
using std::cout;
using std::streamsize;

using std::numeric_limits;

// errorText це повідомлення яке буде відображене якщо ввести невірне значення
// Функцію можна викликати і без цієї змінної, ось так: getValue<int>();

template <typename T>
T getValue0(const char* errorText = 0) {
    T input;

    bool end = false;
    while(!end) {
        cin >> input;

        // cin.peek() - Зчитування одного символу із буфера, не видаляючи його
        if(cin.peek() == '\n') {
            end = true;
        } else {
            if(errorText != 0) {
                cout << errorText;
            }
        }

        cin.clear();        // Скинути флаги для потоку
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Видалити все з потоку
        // cin.ignore(cin.rdbuf()->in_avail(), '\n'); ??
    }

    return input;
}

}

#endif // GETVALUE0_H
