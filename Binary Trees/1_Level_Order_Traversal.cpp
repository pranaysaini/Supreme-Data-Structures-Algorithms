#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    
    vector<int> levelOrder(Node* node)
    {
      
        vector<int>ans;
        
        if(node == NULL){
            return ans;
        }
        
        queue<Node*>res;
        res.push(node);
        
        while(!res.empty()){
            
            int size = res.size();
            vector<int>flag;
            
            
            for(int i=0 ; i<size ; i++){
                

                Node* temp = res.front();
                res.pop();
                flag.push_back(temp->data);
                
                if(temp->left){
                    res.push(temp->left);
                }
                if(temp->right){
                    res.push(temp->right);
                }
            }
            for(auto &i:flag){
                ans.push_back(i);
            }
            
        }
        
        return ans;
        

    }
};





void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}


Node* buildTree(string str)
{   
    
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


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
        vector <int> res = ob.levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}



