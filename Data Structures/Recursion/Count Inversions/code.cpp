#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
 	vector<int> temporary;
 	int i = st, j = mid+1, invCount = 0;
 
 	//merging the sorted arrays
 	while(i <= mid && j <= end) {
 		if(arr[i] <= arr[j]) {
 			temporary.push_back(arr[i]);
 			i++;
 		} else {
 			temporary.push_back(arr[j]);
 			j++;
 			invCount += mid-i+1;
 		}
 	}
 
 	//putting remaining values
 	while(i <= mid) {
 		temporary.push_back(arr[i]);
 		i++;
 	}
 	while(j <= end) {
 		temporary.push_back(arr[j]);
 		j++;
 	}
 
 	//copy the temp value to main array
 	for(int idx = 0; idx < temporary.size(); idx++) {
 		arr[st + idx] = temporary[idx];
 	}

 	return invCount;
}
 
int optimal(vector<int>& arr, int st, int end) {
 	if(st < end) {
 		int mid = st + (end-st)/2;
 		int leftInvCount = optimal(arr, st, mid); //left side
 		int rightInvCount = optimal(arr, mid+1, end); //right side
 
 		int invCount = merge(arr, st, mid, end); //merging the left and right arrays

 		return leftInvCount + rightInvCount + invCount;
 	}
 	return 0;
 }

int bruteForce(vector<int>& vec) {
	int count = 0;
	for(int i = 0; i < vec.size(); i++) {
		for(int j = i+1; j < vec.size(); j++) {
			if(vec[j] < vec[i]) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	vector<int> vec = {6, 3, 5, 2, 7};

	cout << optimal(vec, 0, vec.size()-1) << "\n";

	return 0;
}