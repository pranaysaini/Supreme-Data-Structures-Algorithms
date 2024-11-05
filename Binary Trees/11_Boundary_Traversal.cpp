#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
    
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        
        if(currVal != "N") {

            currNode->left = newNode(stoi(currVal));

            
            queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    
    void solveLeft(Node* root, vector<int>&ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return ;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            solveLeft(root->left, ans);
        }
        else{
            solveLeft(root->right, ans);
        }
    }
    
    void solveLeaf(Node* root, vector<int>&ans){
        
        if(root==NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return ;
        }
        
        solveLeaf(root->left, ans);
        solveLeaf(root->right, ans);
    }
    
    void solveRight(Node* root, vector<int>&ans){
        if((root == NULL) ||(root->left == NULL && root->right == NULL)){
            return ;
        }
        
       if(root->right){
           solveRight(root->right, ans);
       }
       else{
           solveRight(root->left, ans);
       }
        
        ans.push_back(root->data);
    }
    
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        solveLeft(root->left, ans);
        
        solveLeaf(root->left, ans);
        solveLeaf(root->right, ans);
        
        solveRight(root->right, ans);
        
        return ans;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
