#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	Node *root = new Node(stoi(ip[0]));

	queue<Node*> queue;
	queue.push(root);

	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		Node* currNode = queue.front();
		queue.pop();

		string currVal = ip[i];

		if (currVal != "N") {

			currNode->left = new Node(stoi(currVal));
			queue.push(currNode->left);
		}

		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		if (currVal != "N") {

			currNode->right = new Node(stoi(currVal));
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

class Solution {
  public:
  
  string solve(Node* root, unordered_map<string,int>&tripletToId, unordered_map<int,int>&cnt, int &ans){
      
    if(root == NULL) return "#";
    if(!root->left && !root->right) return to_string(root->data);
    

    string left = solve(root->left, tripletToId, cnt, ans);
    string right = solve(root->right, tripletToId, cnt, ans);
    
    string triplet = left + "," + to_string(root->data) + "," + right;
    
    if(!tripletToId.count(triplet)){
        tripletToId[triplet] = tripletToId.size() + 1;
    }
    
    int id = tripletToId[triplet];
    cnt[id]++;
    
    
    if(cnt[id] == 2){
        ans = 1;
    }
    
    return triplet;

  }
  
  
    int dupSub(Node *root) {
        
        unordered_map<string, int>tripletToId;
        unordered_map<int,int>cnt;
        int ans = 0;
        
        solve(root, tripletToId, cnt, ans);
        
        return ans;
        
        
    }
};

int main()
{
	
	int t;
	cin >> t;

	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	
cout << "~" << "\n";
}
	return 0;
}