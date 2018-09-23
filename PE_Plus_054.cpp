#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

enum Hand {HIGH, PAIR, TWOPAIR, THREE, STRAIGHT, FLUSH, FULL, FOUR, STRAIGHTFLUSH, ROYALFLUSH};

const int specialCase [] {14, 5, 4, 3, 2};

struct player{
    Hand hand;
    int score;
    vector<int> cardFreq;
    vector<int> suitFreq;
    vector<int> cardVals;

    void read(){
        cardFreq.clear();
        suitFreq.clear();
        cardVals.clear();
        cardFreq.resize(15, 0);
        suitFreq.resize(4, 0);
        cardVals.resize(5);

        for(int i = 0; i < 5; i++){
            string card; cin >> card;
            int val, suit;
            switch(card[0]){
                case 'T': val = 10; break;
                case 'J': val = 11; break;
                case 'Q': val = 12; break;
                case 'K': val = 13; break;
                case 'A': val = 14; break;
                default: val = card[0] - '0'; break;
            }
            switch(card[1]){
                case 'C': suit = 0; break;
                case 'D': suit = 1; break;
                case 'H': suit = 2; break;
                case 'S': suit = 3; break;
            }
            cardFreq[val]++;
            suitFreq[suit]++;
            cardVals[i] = val;
        }

        sort(cardVals.begin(), cardVals.end(), greater<int>());
        evaluate();
    }
    void evaluate(){
        bool special = true;
        for(int i = 0; i < 5; i++)
            if(cardVals[i] != specialCase[i]){
                special = false;
                break;
            }
        if(special){
            cardVals = {5, 4, 3, 2, 1};
            cardFreq = {0, 1, 1, 1, 1, 1};
        }

        bool straight = true;
        for(int i = 1; i < 5; i++)
            if(cardVals[i] != cardVals[i-1] - 1){
                straight = false;
                break;
            }
        bool flush = false;
        for(int i : suitFreq)
            if(i == 5)
                flush = true;
        if(flush && straight){
            if(cardVals[0] == 14)
                hand = ROYALFLUSH;
            else{
                hand = STRAIGHTFLUSH;
                score = cardVals[0];
            }
            return;
        }

        int pair = 0, three = 0;

        for(int i = 14; i >= 2; i--)
            if(cardFreq[i] == 2)
                pair = pair * 100 + i;
            else if(cardFreq[i] == 3)
                three = i;
            else if(cardFreq[i] == 4){
                hand = FOUR;
                score = i;
                return;
            }

        if(three && pair){
            hand = FULL;
            score = three * 100 + pair;
        }
        else if(flush){
            hand = FLUSH;
            score = cardVals[0];
        }
        else if(straight){
            hand = STRAIGHT;
            score = cardVals[0];
        }
        else if(three){
            hand = THREE;
            score = three;
        }
        else if(pair > 100){
            hand = TWOPAIR;
            score = pair;
        }
        else if(pair){
            hand = PAIR;
            score = pair;
        }
        else{
            hand = HIGH;
            score = cardVals[0];
        }
    }
};

int main() {
    int t; cin >> t;

    player * a = new player;
    player * b = new player;
    while(t--){
        a->read(); b->read();
        if(a->hand > b->hand)
            cout << "Player 1";
        else if(b->hand > a->hand)
            cout << "Player 2";
        else if(a->score > b->score)
            cout << "Player 1";
        else if(b->score > a->score)
            cout << "Player 2";
        else
            for(int i = 0; i < 5; i++)
                if(a->cardVals[i] == b->cardVals[i])
                    continue;
                else{
                    cout << (a->cardVals[i] > b->cardVals[i] ? "Player 1" : "Player 2");
                    break;
                }
        cout << endl;
    }
    return 0;
}
