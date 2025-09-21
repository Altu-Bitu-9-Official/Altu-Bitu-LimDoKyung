#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int getSum(const string& serial){
    
    int sum = 0;

    for(int i = 0; i < serial.length(); i++){
        if(serial[i] >= '0' && serial[i] <= '9'){
            sum += serial[i] - '0';
        }
    }

    return sum;
}

bool comp(const string& A, const string& B){
    
    if(A.length() != B.length()){
        return A.length() < B.length();
    }

    int sumA = getSum(A);
    int sumB = getSum(B);

    if(sumA != sumB){
        return sumA < sumB;
    }

    return A < B;
}

int main()
{
    int n;
    cin >> n;

    vector<string> serial_number(n);

    for(int i = 0; i < n; i++){
        cin >> serial_number[i];
    }

    sort(serial_number.begin(), serial_number.end(), comp);

    for(int i = 0; i < n; i++){
        cout << serial_number[i] << '\n';
    }

    return 0;

}