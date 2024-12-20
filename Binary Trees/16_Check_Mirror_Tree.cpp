#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        
        unordered_map<int, vector<int>>m1, m2;
        
        for(int i=0 ; i<2*e ; i+=2){
            
            m1[A[i]].push_back(A[i+1]);
            m2[B[i]].push_back(B[i+1]);
        }
        
        for(int i=1 ; i<n+1 ; i++){
            reverse(m1[i].begin(), m1[i].end());
            
            if(m1[i] != m2[i]){
                return 0;
            }
        }
        return 1;
        
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    
cout << "~" << "\n";
}
    return 0;
}