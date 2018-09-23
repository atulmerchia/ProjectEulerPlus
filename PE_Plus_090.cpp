#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int m;
long ans = 0;
vector<vector<int>> dice;
vector<string> square;

void validate_2(){
    vector<bool> vec1(9, false);
    vector<bool> vec2(9, false);

    for(int i : dice[0]){
        if(i == 9) i = 6;
        vec1[i] = true;
    }

    for(int i : dice[1]){
        if(i == 9) i = 6;
        vec2[i] = true;
    }

    for(string s : square){
        if(vec1[s[0]] && vec2[s[1]])
            continue;
        if(vec2[s[0]] && vec1[s[1]])
            continue;
        return;
    }
    ans++;
}
auto validate = validate_2;

void validate_3(){
    vector<bool> vec1(9, false);
    vector<bool> vec2(9, false);
    vector<bool> vec3(9, false);

    for(int i : dice[0]){
        if(i == 9) i = 6;
        vec1[i] = true;
    }

    for(int i : dice[1]){
        if(i == 9) i = 6;
        vec2[i] = true;
    }

    for(int i : dice[2]){
        if(i == 9) i = 6;
        vec3[i] = true;
    }

    for(string s : square){
        if(vec1[s[0]] && vec2[s[1]] && vec3[s[2]])
            continue;
        if(vec1[s[0]] && vec3[s[1]] && vec2[s[2]])
            continue;
        if(vec2[s[0]] && vec1[s[1]] && vec3[s[2]])
            continue;
        if(vec2[s[0]] && vec3[s[1]] && vec1[s[2]])
            continue;
        if(vec3[s[0]] && vec1[s[1]] && vec2[s[2]])
            continue;
        if(vec3[s[0]] && vec2[s[1]] && vec1[s[2]])
            continue;
        return;
    }
    ans++;
}

bool next(int diceNum){
    vector<int> vec = dice[diceNum];

    int index = 5;
    while(true){
        vec[index]++;
        if(vec[index] == 5 + index){
            if(index)
                vec[index--] = 0;
            else
                return false;
        }
        else
            break;
    }

    for(int i = index + 1; i < 6; i++)
        vec[i] = vec[i-1] + 1;

    dice[diceNum] = vec;

    return true;
}

void recurse(int diceNum){
    if(diceNum == m){
        validate();
        return;
    }
    dice[diceNum] = dice[diceNum - 1];
    do{
        recurse(diceNum + 1);
    }while(next(diceNum));
}

int main() {
    int n;
    cin >> n >> m;

    if(m == 1){
        if(n == 1)
            cout << 126;
        else if(n == 2)
            cout << 70;
        else if(n == 3)
            cout << 55;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        string s = to_string(i*i);
        while(s.length() < m)
            s = "0" + s;
        for(char &c : s){
            c -= '0';
            if(c == 9)
                c -= 3;
        }
        square.push_back(s);
    }

    if(m == 3) validate = validate_3;

    dice.resize(m, vector<int>(6, 0));

    dice[0] = {0, 1, 2, 3, 4, 5};

    do{
        recurse(1);
    }while(next(0));

    cout << ans;

    return 0;
}
