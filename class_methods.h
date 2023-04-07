//
// Created by User on 07.04.2023.
//
//#include "class_string.cpp"
#include <vector>
#include <iostream>
#include "class_string.h"

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
