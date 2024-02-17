#include <iostream>
#include <cstdlib>
#include <string>

#include <vector>
//there are more : multimap, multiset, unordered_set, etc.

using namespace std;

// Unlike array, vectors' size is dynamic, just like arrayList.

int main() {

        vector<int> number(2); // size of 2

        number[0]= 12;
        number[1] = 14; // max space at this point
        number.push_back(30); // Too add 30 to the end.

        for (int i = 0; i < number.size(); i++)
        {
                cout <<" "<<number[i];
        };

        return 0;
}
