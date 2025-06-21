#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;
    
    //insert

    //1.
    pair<string, int> pair1 = {"Rohan", 5};
    m.insert(pair1);

    //2.
    pair<string, int> pair2("Rahim", 3);
    m.insert(pair2);

    //3. 
    m["Hello"] = 8;

    //output
    cout << m["Rohan"] << "\n";
    // cout << m.at("unknownKey") << "\n"; ->this will give error as it tries to find the value of the key which doesn't exist
    cout << m["unknownKey"] << "\n"; // this won't give error like before as it creates a corresponding entry with 0 for the unknown key

    //size
    cout << m.size() << "\n";

    //to check if a key exists
    cout << m.count("nice") << "\n"; // 0 as nice not exists in map
    cout << m.count("Rohan") << "\n"; // 1 as Rohan exists in map

    //erase 
    m.erase("unknownKey");

    //traverse

    //loop
    for(auto i: m) {
        cout << i.first << " " << i.second << "\n";
    }

    //iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout << it->first << " " << it->second << "\n";
        it++;
    }

    return 0;
}