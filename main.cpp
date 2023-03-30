#include <iostream>
#include "checking/inputCheck.h"
#include <vector>
using namespace std;
//31. Розробити клас, який є абстракцією тексту та підтримує операції додавання
//        рядка до тексту і визначення відсотка приголосних літер у тексті. Створити масив
//об'єктів даного класу. Доповнити декілька текстів новими рядками. Визначити
//текст з найбільшим відсотком приголосних літер.
class str{
private:
    string text;
    int num;
    bool isConsonant(char c) ;
    bool isUkrainianLetter(char c);
public:
    str(){
        text = "";
    }
    static int counter;
    str(string text):text(text){
        num = counter;
        counter++;
    };
    string getText();
    int getNum();
    void appendToText(string substr);
    double calcPercantage();

};
int str::getNum(){
    return num;
};
int str::counter = 1;
bool str::  isUkrainianLetter(char c) {
    string ukrainianLetters = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
    return (ukrainianLetters.find(c) != string::npos);
}
bool str:: isConsonant(char c){
    c = tolower(c);
    string consonants = "бвгґджзклмнпрстфхцчшщ";
    return (consonants.find(c) != string::npos);
}
void  str::appendToText(string substr) {
    text+=substr;
}
double str::calcPercantage(){
    int trigger=0;
    int countConsonants = 0;//20 - x
    int countLetters = 0;//   55 - 100
    for (char c : text) {
        if (isConsonant(c)) {
            countConsonants++;
        }
        if (isUkrainianLetter(c)) {
            countLetters++;
            trigger=1;
        }
    }
    double percentageConsonants = (countConsonants / (double)countLetters) * 100.0;
    return trigger?percentageConsonants:0;
};
string str::getText() {
    return text;
}

void readObjects(vector<str> array){
    for(str e :array ){
        cout<<e.getNum()<<": "<<e.getText()<<"; "<<e.calcPercantage()<<"%"<<endl;
    }
}

str calcHighestPercentage(vector<str> arr){
    str object;
    for(str e : arr){
        if(e.calcPercantage()>object.calcPercantage()){
            object = e;
        }
    }
    return object;
};

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
