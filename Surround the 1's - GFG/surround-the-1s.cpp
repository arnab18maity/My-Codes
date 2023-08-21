//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++ ){
             int count = 0;
             int up = -1; int down = -1; int left = -1; int right = -1;int upL = -1;int upR = -1;int downL = -1;int downR = -1;
              if(matrix[i][j] == 1) {
               if(i > 0) up = matrix[i-1][j];
               if(i < n-1) down = matrix[i+1][j];
               if(j > 0) left = matrix[i][j-1];
               if(j < m-1) right = matrix[i][j+1];
               if(i > 0 && j > 0) upL = matrix[i-1][j-1];
               if(i > 0 && j < m-1) upR = matrix[i-1][j+1];
               if(i < n-1 && j > 0) downL = matrix[i+1][j-1];
               if(i < n-1 && j < m-1) downR = matrix[i+1][j+1];
                
               if(up == 0) count++;
               if(down == 0) count++;
               if(left == 0) count++;
               if(right == 0) count++;
               if(upL == 0) count++;
               if(upR == 0) count++;
               if(downL == 0) count++;
               if(downR == 0) count++;
              
               if(count > 0 && count % 2 == 0) ans++;
              }
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends