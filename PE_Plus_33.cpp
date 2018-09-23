#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

string stringify(int x, int digits){
    string result;
    while (digits-- > 0){
        int digit = x % 10;
        result += char(digit + '0');
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

unsigned int combine(string& fill, string& mask){
    auto it = fill.begin();
    unsigned int result = 0;
    for(char c : mask){
        result *= 10;
        if (c == '.')
            result += *it++ - '0';
        else
            result += c - '0';
    }
    return result;
}

int main(){
    int digits, cancel; cin >> digits >> cancel;
    int keep = digits - cancel;

    int numSum  = 0;
    int denSum  = 0;

    int minNum = pow(10, digits - 1);
    int maxDen = pow(10, keep);
    int maxRem = pow(10, cancel);

    set<string> pairs;

    for (int den = 1; den < maxDen; den++)
        for (int num = 1; num < den; num++){
            string numStr = stringify(num, keep);
            string denStr = stringify(den, keep);

            for (int rem = maxRem/10; rem < maxRem; rem++){
                string mask = stringify(rem, cancel);

                bool isAscending = true;
                for (int i = 1; i < mask.size(); i++)
                    if (mask[i - 1] > mask[i]){
                        isAscending = false;
                        break;
                    }

                if (!isAscending)
                    continue;

                mask.insert(0, keep, '.');

                string numMask = mask;
                do{
                    int bigNum = combine(numStr, numMask);

                    if (bigNum < minNum)
                        continue;

                    string denMask = mask;
                    do{
                        int bigDen = combine(denStr, denMask);

                        if (bigNum * den == bigDen * num){
                            string id = to_string(bigNum) + " " + to_string(bigDen);
                            if (pairs.find(id) == pairs.end()){
                                numSum += bigNum;
                                denSum += bigDen;

                                pairs.insert(id);
                            }
                        }
                    }while (next_permutation(denMask.begin(), denMask.end()));
                }while (next_permutation(numMask.begin(), numMask.end()));
            }
        }

    cout << numSum << " " << denSum << endl;
    return 0;
}
