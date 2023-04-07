#include <iostream>
#include <string>
#include "checking/inputCheck.h"
#include <vector>
#include "class_methods.h"


using namespace std;
//31. Розробити клас, який є абстракцією тексту та підтримує операції додавання
//        рядка до тексту і визначення відсотка приголосних літер у тексті. Створити масив
//об'єктів даного класу. Доповнити декілька текстів новими рядками. Визначити
//текст з найбільшим відсотком приголосних літер.




void app(){
    int option;
    int boolean;
    vector<str> stringObjects = {str("Привіт світ"), str("світло, привіт")};
    printf("1 - create sting object\n");
    printf("2 - read all string objects and calc percentage of consonants\n");
    printf("3 - calc the highest percentage of consonants from all objects\n");//no
    printf("4 - edit object\n");
    printf("5 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 1 || option > 5) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 1: {
                string text;
                cout << "Enter text: " << endl;
//                getchar();
                getline(cin, text);
                str object(text);
                stringObjects.push_back(object);
                break;
            }
            case 2: {
                readObjects(stringObjects);
                break;
            }
            case 3: {
                if(!stringObjects.empty()){
                    str object = calcHighestPercentage(stringObjects);
                    cout<<object.getText()<<" - має найбільший відсоток приголосних"<<"("<<object.calcPercantage()<<"%)"<<endl;
                }else {
                    cout<<"Object strings array is empty"<<endl;
                }
                break;
            }
            case 4: {
                cout << "Enter the number of the object: " << endl;
                int index;
                cin >> index;
                cin.ignore(); // discard the newline character
                if (index >= stringObjects.size()+1 || index == 0) {
                    cout << "number out of range." << endl;
                } else {
                    string text;
                    cout << "Enter the text you want to append" << endl;
//                    getchar();
                    getline(cin, text);
                    cout<<"Before: "<<stringObjects[index-1].getText()<<endl;
                    stringObjects[index-1].appendToText(text);
                    cout<<"After: "<<stringObjects[index-1].getText()<<endl;
                }
                break;
            }
            case 5: {
                boolean = 0;
                break;
            }
            default: {
                cout << "Invalid option." << endl;
                break;
            }
        }

    } while (boolean == 1);
}

int main() {
    app();
    return 0;
}
