//
// Created by User on 07.04.2023.
//
using namespace std;
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

void readObjects(vector<str> array);
str calcHighestPercentage(vector<str> arr);
