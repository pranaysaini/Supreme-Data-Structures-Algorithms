#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

class Solution {
  public:
    
    int solve(Node* node){
        
        if(node == NULL) return 0;
        
        int left = solve(node->left);
        int right = solve(node->right);
        
        int originalValue = node->data;
        
        node->data = left+right;
        
        return originalValue + node->data;

    }
    
    void toSumTree(Node *node)
    {
        solve(node);   
    }
};

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 1;
}