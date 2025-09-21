#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;

    set<string> result;

    for(int len = 1; len <= s.length(); len++){
        for(int i = 0; i <= s.length() - len; i++){
            result.insert(s.substr(i,len));
        }
    }

    cout << result.size();

    return 0;

}
