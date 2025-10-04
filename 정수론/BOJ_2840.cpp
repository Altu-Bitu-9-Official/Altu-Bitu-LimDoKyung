#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic;
const int Alpha = 26;

string printWheel(int n, int index, vector<char> &wheel){
    string ans = "";
    for(int i = index + n; i > index; i--){
        ans += wheel[i%n];
    }
    return ans;
}

string makeWheel(int n, int k, vector<ic> &record){
    vector<char> wheel(n, '?');
    vector<bool> is_available(Alpha, false);

    int index = 0;

    for(int i = 0; i < k; i++){
        int s = record[i].first;
        char ch = record[i].second;

        index = (index + s) % n;

        if(wheel[index] == ch){
            continue;
        }

        if(wheel[index] != '?' || is_available[ch - 'A']){
            return "!";
        }

        wheel[index] = ch;
        is_available[ch - 'A'] = true;

    }

    return printWheel(n, index, wheel);
}

int main(){

    int n, k;

    cin >> n >> k;

    vector<ic> record(k);

    for(int i = 0; i < k; i++){
        cin >> record[i].first >> record[i].second;
    }

    cout << makeWheel(n, k, record);

    return 0;
}