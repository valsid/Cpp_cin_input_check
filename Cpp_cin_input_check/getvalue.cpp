#include "getvalue.h"

#include <iostream>
using std::cout;    // считается, что поток вывода это обычный cout

#include <string>
using std::string;

#include <cstdlib>  // strtold
#include <conio.h>  // getch

char getLastSymbol(string *str) {
    return *( str->rbegin() );   // strRes.back() in C++11
}

char deleteLastSymbol(string *str) {
    char lastSymbol = getLastSymbol(str);
    str->erase(str->length() - 1);
    return lastSymbol;
}

// Може використати boost для переведення рядка символів до числа?..

long double getDoubleVal() {
    string strResult;          // В цій змінній, зберігається введене користувачем значення, яке буде переведене до числа
    char input = ' ';       // Тут зберігається введений користувачем символ
    bool isDecimalSeparatorInputted = false;    // Флаг, чи вводив користувач десятковий роздільник
    bool isExponentSymbolInputted = false;      //
    bool isInputWillBeDisplayed = false;        // Флаг який означає чи буде виведено введений користувачем символ
    //                                          // може краще використовувати continue;
    
    
    while(input != '\r') {
        input = getch();    // getch отримує один введений користувачем символ
        //                  // та не чекаючи натиснення ентеру повертає його
        
        switch(input) {
        case '-':
            if(strResult == "" || getLastSymbol(&strResult) == 'e') {
                strResult += '-';
                isInputWillBeDisplayed = true;
            }
            break;
        case '.':
        case ',':
            if(isDecimalSeparatorInputted == false) {
                isDecimalSeparatorInputted = true;
                strResult += '.';
                isInputWillBeDisplayed = true;
            }
            break;
        case 'e':
            if(isExponentSymbolInputted == false) {
                isExponentSymbolInputted = true;
                strResult += 'e';
                isInputWillBeDisplayed = true;
            }
            break;
        case '\b':  // Видалення символів
            if(!strResult.empty()) {
                char deletedSymbol = deleteLastSymbol(&strResult);
                
                switch(deletedSymbol) {
                case '.':
                case ',':
                    isDecimalSeparatorInputted = false;
                    break;
                case 'e':
                    isExponentSymbolInputted = false;
                    break;
                }
                
                cout << "\b \b";
                isInputWillBeDisplayed = false;
            }
            break;
        default:
            if((input >= 48 && input < 58)) {   // 47 < ch < 58 // Якщо введений символ це цифра
                //                              // числа від 47 до 58 в кодовій таблиці АСКІ це цифры
                strResult += input;           // додавання введеної цифри до рядку який в подальшому буде конвертований в число
                isInputWillBeDisplayed = true;
            }
            break;
        }
        
        if(isInputWillBeDisplayed == true) {
            cout << input;
            isInputWillBeDisplayed = false;
        }
    }
    
#ifdef _MSC_VER
    return _Stold(strRes.c_str(), 0, 0);
#else
    return strtold(strResult.c_str(), NULL); // stold() ?
#endif
}
