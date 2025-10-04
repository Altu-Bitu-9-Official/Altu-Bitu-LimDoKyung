#include <iostream>
#include <stack>
#include <string>

using namespace std;

string balance (const string& input){

    stack<char> s;

    for(char c: input) {

        if(c == '[' || c == '(') {
            s.push(c);
        }

        else if(c == ']'){
            if(s.empty() || s.top() != '['){
                return "no";
            }
            s.pop();
        }

        else if(c == ')'){
            if(s.empty() || s.top() != '('){
                return "no";
            }
            s.pop();
        }
    }

    if(s.empty()){
        return "yes";
    }else{
        return "no";
    }
}

int main() {

    string input;

    while(true) {

        getline(cin, input);

        if(input == "."){
            break;
        }

        cout << balance(input) << "\n";
    }
    
    return 0;
}