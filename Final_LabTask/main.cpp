#include <iostream>
#include <string>
using namespace std;

bool Final(char state) {
    return (state == 'A' || state == 'B' || state == 'C' || state == 'D' || state == 'E' || state == 'F' || state == 'G' || state == 'H' || state == 'I');
}

char DFA(char state, char input) {
    switch (state) {

    case 'A':
        if (input == 'a')
            return 'B';
        else
            return 'C';

    case 'B':
        if (input == 'a')
            return 'D';
        else
            return 'E';

    case 'C':
        if (input == 'a')
            return 'F';
        else
            return 'G';

    case 'D':
        if (input == 'a')
            return 'D';
        else
            return 'H';

    case 'E':
        if (input == 'a')
            return 'D';
        else
            return 'I';

    case 'F':
        if (input == 'a')
            return 'D';
        else
            return 'F';

    case 'G':
        if (input == 'a')
            return 'E';
        else
            return 'G';

    case 'H':
        if (input == 'a')
            return 'E';
        else
            return 'H';

    case 'I':
        if (input == 'a')
            return 'E';
        else
            return 'F';

    default:
        return 0;
    }
}

int main()
{
    string input;
    char currentState = 'A';

    cout << "Enter a string : ";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c != 'a' && c != 'b') {
              cout << "Invalid input!" << endl;
           return 0;
        }

      currentState = DFA(currentState, c);
    }

    if (Final(currentState)) {
        cout << "String is accepted!" << endl;
    }
    else {
        cout << "String is rejected!" << endl;
    }

 return 0;
}
