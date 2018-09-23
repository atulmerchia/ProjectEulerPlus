#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned int n;
    cin >> n;

    const unsigned int MaxOrder = 16;

    // express perfect powers as orders of a
    vector<unsigned int> minExponent((n+1)*MaxOrder);
    for (unsigned int i = 1; i <= MaxOrder; i++)
        for (unsigned int j = 1; j <= n; j++)
            if (minExponent[i*j] == 0)
                minExponent[i*j] = i;

    vector<unsigned int> base(n + 1, 0);

    unsigned int repeated = 0;

    for (unsigned int x = 2; x <= n; x++){
        auto parent = base[x];

        // if original parent, populate children.
        if (parent == 0){
            auto power = x * x;
            while (power <= n){
                base[power] = x;
                power *= x;
            }

            continue;
        }

        // express a as order of parent
        unsigned int exponent = 0;
        auto reduce = x;
        while (reduce > 1){
            reduce /= parent;
            exponent++;
        }

        for (unsigned int y = 2; y <= n; y++){
            if (minExponent[y * exponent] < exponent)
                repeated++;
        }
    }

    unsigned long long total = n - 1;
    auto result = total*total - repeated;
    cout << result << endl;
    return 0;
}
