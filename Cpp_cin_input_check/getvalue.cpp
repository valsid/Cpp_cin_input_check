#include "getvalue.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using std::cout;    // считается, что поток вывода это обычный cout
using std::string;

//template <typename T>
long double getDoubleVal() {
    string strRes;          // Храниться введенное пользователем значение
    char input = ' ';       // В этой переменной хранится символ, который вводится на каждой итерации цикла
    int lastElementIndex = 0;   // используется при удалении символа
    bool isDecimalSeparatorInputted = false;
    bool isValidInput = false;
    bool endInput = false;


    while(!endInput) {
        input = getch();       // getch записывает введенный символ в переменную не дожидаясь нажатия ентера

        switch(input) {
        case '-':
            if(strRes == "") {
                strRes += '-';
                isValidInput = true;    // Для вывода введенного символа, может лучше использовать continue?
            }
            break;
        case 13:                // Числа вводятся пока не будет нажат ентер(символ 13)
            endInput = true;
            break;
        case '.':
        case ',':
            if(isDecimalSeparatorInputted == false) {
                isDecimalSeparatorInputted = true;
                strRes += '.';
                isValidInput = true;
            }
            break;
        case '\b':  // удаление символов
            lastElementIndex = strRes.length() - 1;
            if(lastElementIndex >= 0) {
                char lastElem = strRes.at(lastElementIndex);
                if(lastElem == '.' || lastElem == ',') {
                    isDecimalSeparatorInputted = false;
                }
                strRes.erase(lastElementIndex, 1);
                cout << "\b \b";
                continue;
            }
            break;
        default:
            if((input >= 48 && input < 58)) {   // 47 < ch < 58 // Если введенный символ это цифра то...
                // числа от 47 до 58 в кодовой таблице это цифры
                strRes += input;           // Добавление введенных символов к строке для последующего распознавания
                isValidInput = true;
            }
            break;
        }

        if(isValidInput == true) {
            cout << input;
            isValidInput = false;
        }
    }

#ifdef _MSC_VER
    return _Stold(strRes.c_str(), NULL, 0);
#else
    return strtold(strRes.c_str(), NULL); // stold() ?
#endif
}
