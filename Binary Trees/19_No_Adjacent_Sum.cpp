#include<bits/stdc++.h> 
using namespace std; 

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

class Solution{
  public:
    
    pair<int,int>solve (Node* root){
        
        if(root == NULL){
            pair<int,int>p = make_pair(0, 0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<int,int>p = make_pair(root->data, 0);
            return p;
        }
        
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        
        pair<int,int>ans;
        
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        
        return ans;

    }
    int getMaxSum(Node *root) 
    {
        return max(solve(root).first, solve(root).second);
    }
};

int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  
cout << "~" << "\n";
}
  return 0;
}