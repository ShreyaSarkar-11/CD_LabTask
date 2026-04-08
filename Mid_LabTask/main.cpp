#include <iostream>
#include <fstream>
using namespace std;

string key[] = {"int", "float", "string", "char", "double", "return", "void", "main"};
int keyNo = 8;

char punc[] = {',', ';', ':', '{', '}', '[', ']', '(', ')', '"'};
int puncNo = 10;

char op[] = {'+', '-', '*', '/', '=', '>', '<', '!', '&', '%'};
int opNo = 10;

void ExternalText(){
     string text;
     ifstream ReadFile("myFile.txt");
     while (!ReadFile.eof()){
        getline (ReadFile, text);
        cout<<text<<endl;
     }
     ReadFile.close();
}

bool Keyword(string x){
    for(int i=0; i<keyNo; i++){
        if (x == key[i]) return true;
    }
    return false;
}

bool Operator(char x){
    for(int i=0; i<opNo; i++){
        if(x == op[i]) return true;
    }
    return false;
}

bool Punctuation(char x){
    for(int i=0; i<puncNo; i++){
        if(x == punc[i]) return true;
    }
    return false;
}

bool Constant(string x){
    if(x.empty()) return false;
    for(int i = 0; i < x.length(); i++){
        if(x[i] < '0' || x[i] > '9') return false;
    }
    return true;
}

void printToken(string s){
    if(s.empty()) return;

    if(Keyword(s)){
        cout << s << " = Keyword" << endl;
    }
    else if(Constant(s)){
        cout << s << " = Constant" << endl;
    }
    else{
        cout << s << " = Identifier" << endl;
    }
}

void Tokenization(){
    ifstream myFile("myFile.txt");
    if(!myFile){
        cout << "File not found!" << endl;
        return;
    }

    string text;

    while(getline(myFile, text)){
        string token = "";

        for(int i = 0; i < text.length(); i++){
            char c = text[i];

            if(c == ' '){
                printToken(token);
                token = "";
            }
            else if(Punctuation(c)){
                printToken(token);
                token = "";
                cout << c << " = Punctuation" << endl;
            }
            else if(Operator(c)){
                printToken(token);
                token = "";
                cout << c << " = Operator" << endl;
            }
            else{
                token += c;
            }
        }

        printToken(token);
    }

    myFile.close();
}

int main(){
    ExternalText();
    Tokenization();
    return 0;
}
