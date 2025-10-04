#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    stack<int> s1, s2, result;

    string A, B;
    int carry = 0;

    cin >> A >> B;

    for(char c: A){
        s1.push(c - '0');
    }

    for(char c: B){
        s2.push(c - '0');
    }

    while( !s1.empty() || !s2.empty() || carry > 0 ) {

        int a = 0;
        if(!s1.empty()){

            a = s1.top();
            s1.pop();
        }

        int b = 0;
        if(!s2.empty()){

            b = s2.top();
            s2.pop();
        }
        
        int sum = a + b + carry;
        carry = sum / 10;

        result.push(sum % 10);

    }

    while(!result.empty()){

        cout << result.top();
        result.pop();
    }

    return 0; 

}