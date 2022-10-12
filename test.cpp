#include<bits/stdc++.h>
using namespace std;

// 11,2,33, 4

// [1] -> [4, 2]
// [2] -> [33, 11]
// [3] -> [321]
// 433321211
// [2,23]
// [1]->2
// [2]->23
// 232
// 223
// [2, 21]
// [1]->2
// [2]->21

// ..
// [k] -> [] 
// [k+1] -> []
// k+1 > k choose k digit
// else choose k+1 digit

void solve(vector<string> arr){
	unordered_map<int, vector<string>> umap;
	// [1]->[1,2,3]

	// [1]->[3,2]
	// [2]->[32]
	for(int i=0;i<arr.size();i++){
		umap[arr[i].length()].push_back(arr[i]);
	}
	for(auto [k,v]:umap){
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		umap[k]=v;
	}
	// [1]->[3,2,1]
	int n = arr.size();
	k
	string ans="";
	while(n--){
		string curr = "";
		for(auto [k,v]:umap){
			if(v.size()==0) continue;
			string num = v[0]; //32
			// curr = max(curr, num);
			if(curr.length()==0){
				curr = num;
			}
			// k
			// k+i
			bool isbig = false;
			for(int i=0;i<curr.length();i++){
				if(curr[i] < num[i]){
					curr = num;
					break;
				}
				else if(curr[i] > num[i]){
					isbig= true;
					break;
				}

			}
			if(isbig) break;
			else if(curr[curr.length()-1] < num[curr.length()]){
				curr = num;
			}
		}
		ans += curr;
		//321
		// 3
		umap[k].erase(umap[k].find(curr));
	}
	cout << ans << endl;


}

int print(int x){
	return x;
}

int main(){
	//[1,2,3]
	// [2, 3, 32]
	int n;
	cin >> n;
	vector<string> arr(n);
	for(i=0;i<n;i++){
		cin >> arr[i];
	}
	solve(arr);
	print(4);


}
