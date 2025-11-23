#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int card_search(const vector<int>& cards, int target){

    int left = 0;
    int right = cards.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(cards[mid] == target){
            return 1;
        }
        else if(cards[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, num;

    cin >> N;

    vector<int> cards(N);

    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> num;

        cout << card_search(cards, num) << " ";
    }

    return 0;

}