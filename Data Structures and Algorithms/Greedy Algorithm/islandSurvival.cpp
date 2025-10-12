#include<bits/stdc++.h>
using namespace std;

/*
    Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

    N – The maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.

    Currently, it’s Monday, and she needs to survive for the next S days.
    Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.
*/

int minimumDays(int S, int N, int M) {
    // code here
    //edge cases
    if(S > 6 && ((7*M) > (6*N))) return -1;
    
    int sundays = S/7;
    int maxBuyDay = S - sundays;
    
    double totalFood = S*M;
    
    int neededBuyDay = (int)ceil(totalFood/N);
    
    return (neededBuyDay <= maxBuyDay) ? neededBuyDay: -1;
}

int main() {
    cout << minimumDays(5, 2, 2) << endl;
    return 0;
}