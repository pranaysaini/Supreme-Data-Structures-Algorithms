#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }


        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];


        if (currVal != "N") {


            currNode->right = newNode(stoi(currVal));

            
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
    public:
    
    pair<bool,int>solve(Node* root){
        
        if(root == NULL){
            pair<bool,int>p = make_pair(true, 0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int>left = solve(root->left);
        pair<bool,int>right = solve(root->right);
        
        bool isSumTreeNot = (root->data == left.second + right.second);
        
        bool check = left.first && right.first && isSumTreeNot;
        int sum = root->data + left.second + right.second;
        
        return make_pair(check, sum);
    }
    
    bool isSumTree(Node* root)
    {
        
        return solve(root).first;
    }
};

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;

        getline(cin, s);

        Node* root = buildTree(s);
        Solution ob;
        if (ob.isSumTree(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 1;
}