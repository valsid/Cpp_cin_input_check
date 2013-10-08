#include "getvalue0.h"

#include <iostream>
#include <limits>
#include <cstdlib>
/*
using std::string;
using std::cin;
using std::cout;
*/
using namespace std;

// errorText це повідомлення яке буде відображене якщо ввести невірне значення
// errBuf це змінна в яку запишеться все що залилишось в буфері введення після
//          того як користувач введе деяке значення, якщо ця змінна не буде передана до функції то все

// Функцію можна викликати і без цих змінних( input0 = getValue<int>() ), але
//      я рекомендую передавати в функцію текст який буде відображений користувачу якщо віг ввів невірний текст
//              input0 = getValue<int>();
template <typename T>
T getValue0(const char* errorText = 0, string *errBuf = 0) {
    string buf;         // Тимчасовий буфер в який буде записуватися вміст буферу
    T input;

    bool end = false;
    while(!end) {
        if(cin >> input) {          // Якщо було введено вiрне значення, то йти на вихід
            end = true;
        } else {
            if(errorText != 0 ) {   // В іншому випадку повідомити користувача
                cout << errorText;  // Тобто вивести текст який
            }
        }

        cin.clear();            // Скинути флаги для потоку
        if(errBuf != 0) {       // Якщо в функцію передали змінну в яку запишеться вміст буферу, тобто якщо адреса цієї змінної не дорівнює нулю
            buf.clear();        // Очистити тимчасовий буфер
            char c;             // Змінна в яку запишеться один символ із буферу
            for(int i = 0; ; i++) {
                c = cin.peek();     // Зчитати один символ із буфера, не видаляючи його
                cin.ignore(1, c);   // Видалити попередньо зчитаний символ із буферу
                if(c == 10) break;  // Якщо цей символ це символ кінця рядка (буферу?) то одразу вийти з циклу

                buf.push_back(c);   // Додати отриманий символ до тимчасового буферу
            }
        }
        //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(errBuf != 0) errBuf->append(buf);    // Якщо
    return input;
}
