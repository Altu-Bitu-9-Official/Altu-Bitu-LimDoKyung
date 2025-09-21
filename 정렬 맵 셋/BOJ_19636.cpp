#include <iostream>
#include <cmath>

using namespace std;

void diet(int w0, int i0,int t,int d,int i,int a){

    int w1 = w0, w2 = w0;
    int m1 = i0, m2 = i0;

    for(int j = 0; j < d; j++){ 
        w1 += (i - (m1 + a));
    }

    for(int j = 0; j < d; j++){ 
        w2 += (i - (m2 + a));
        if(abs(i - (m2 + a)) > t){
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }

    if(w1 <= 0 || m1 <= 0){
        cout << "Danger Diet\n";
    }else{
        cout << w1 <<" "<< m1 << "\n";
    }

    if(w2 <= 0 || m2 <= 0){
        cout << "Danger Diet\n";
    }else{
        cout << w2 <<" "<< m2 << " ";

        if((i0 - m2) > 0){
            cout << "YOYO\n";
        }else{
            cout << "NO\n";
        }
    }
}

int main(){

    int w0, i0, t;
    int d, i, a;

    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    diet(w0, i0, t, d, i, a);

    return 0;
    
}
