#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU =1;

string judge(cards& deck){
    int do_deck = deck[DO].size(), su_deck = deck[SU].size();
    if(do_deck > su_deck){
        return "do";
    }
    else if(su_deck > do_deck){
        return "su";
    }
    return "dosu";
}

void groundToDeck(deque<int>& deck, deque<int>& ground){
    while(!ground.empty()){
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

void ringTheBell(int bell, cards& deck, cards& ground){
    groundToDeck(deck[bell], ground[!bell]);
    groundToDeck(deck[bell], ground[bell]);
}

int whoCanRingTheBell(cards& ground){
    if(!ground[DO].empty() && ground[DO].front() == 5){
        return DO;
    }
    else if(!ground[SU].empty() && ground[SU].front() == 5){
        return DO;
    }
    else if(!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)){
        return SU;
    }

    return -1;
}

string game(int m, cards& deck, cards& ground){
    bool turn = DO;
    while(m--){
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();

        if(deck[turn].empty()){
            break;
        }

        int bell = whoCanRingTheBell(ground);

        if(bell != -1){
            ringTheBell(bell, deck, ground);
        }

        turn = !turn;
    }

    return judge(deck);
}

int main(){
    int n, m, do_card, su_card;
    cards deck(2), ground(2);

    cin >> n >> m;
    while(n--){
        cin >> do_card >> su_card;
        deck[DO].push_front(do_card);
        deck[SU].push_front(su_card);
    }

    cout << game(m, deck, ground);

}