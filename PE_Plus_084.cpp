#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct loc{
    double prob;
    string s;

    bool operator<(loc other) const{
        return prob > other.prob;
    }
};

int main() {
    string names [40] = { "GO",   "A1", "CC1", "A2",  "T1", "R1", "B1",  "CH1", "B2", "B3",
                          "JAIL", "C1", "U1",  "C2",  "C3", "R2", "D1",  "CC2", "D2", "D3",
                          "FP",   "E1", "CH2", "E2",  "E3", "R3", "F1",  "F2",  "U2", "F3",
                          "G2J",  "G1", "G2",  "CC3", "G3", "R4", "CH3", "H1",  "T2", "H2" };
    int chance [3] = {7, 22, 36};
    int rail [3] = {15, 25, 5};
    int utility [3] = {12, 28, 12};

    vector<int> freq(40, 0);

    int diceNum; cin >> diceNum;
    int numMoves = diceNum * 2 + 1;

    double moveProb [numMoves];

    for(int i = 2; i <= diceNum; i++)
        moveProb[i] = i-1;
    for(int i = diceNum + 1; i < numMoves; i++)
        moveProb[i] = numMoves - i;

    for(double& d : moveProb)
        d /= diceNum * diceNum;



    vector<vector<double>> matrix(40, vector<double> (40, 0));

    for(int start = 0; start < 40; start++){
        for(int move = 2; move < numMoves; move++){
            double p = moveProb[move] / 16;

            int next = (start + move) % 40;

            bool mark = true;

            for(int i = 0; i < 3; i++){
                if(next == chance[i]){
                    matrix[start][0] += p;
                    matrix[start][10] += p;
                    matrix[start][11] += p;
                    matrix[start][24] += p;
                    matrix[start][39] += p;
                    matrix[start][5] += p;
                    matrix[start][rail[i]] += 2*p;
                    matrix[start][utility[i]] += p;
                    matrix[start][next] += 6*p;
                    if(next == 36){
                        matrix[start][33] += p * 0.875;
                        matrix[start][0] += p / 16;
                        matrix[start][10] += p / 16;
                    }
                    else
                        matrix[start][next - 3] += p;
                    mark = false;
                }
            }
            if(next == 2 || next == 17 || next == 33){
                matrix[start][0] += p;
                matrix[start][10] += p;
                matrix[start][next] += p * 14;
                mark = false;
            }
            if(next == 30)
                next = 10;

            if(mark)
                matrix[start][next] += moveProb[move];
        }
    }

    vector<double> probs (40, 0);
    probs[0] = 100.0;

    for(int move = 0; move < 100; move++){
        vector<double> next(40, 0);
        for(int i = 0; i < 40; i++)
            if(probs[i])
                for(int j = 0; j < 40; j++)
                    if(matrix[i][j])
                        next[j] += probs[i] * matrix[i][j];
        probs = next;
    }

    vector<loc> ans(40);
    for(int i = 0; i < 40; i++)
        ans[i] = {probs[i], names[i]};

    sort(ans.begin(), ans.end());

    int numOut; cin >> numOut;
    for(int i = 0; i < numOut; i++)
        cout << ans[i].s << " ";

    return 0;
}
