#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int totGas = 0, totCost = 0;

	for(int val: gas) totGas += val;
	for(int val: cost) totCost += val;

	if(totGas < totCost) return -1;
	
	//unique solution exists
	int currGas = 0, st = 0;
	for(int i = 0; i < gas.size(); i++) {
		currGas += gas[i] - cost[i];
		if(currGas < 0) {
			st = i+1;
			currGas = 0;
		}
	}

	return st;
}

int main() {
	vector<int> gas = {2, 3, 4};
	vector<int> cost = {3, 4, 5};

	cout << canCompleteCircuit(gas, cost) << "\n";

	return 0;
}