//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Meeting{
    int s;
    int e;
    int pos;
    
    Meeting(int start, int end, int pos) {
       this -> s = start;
       this -> e = end;
       this -> pos = pos;
    }
};

class Solution {
  public:
    static bool comp(Meeting m1, Meeting m2) {
        return (m1.e < m2.e);
    }
  
    int maxMeetings(int n, int start[], int end[]) {
        vector<Meeting> meet;
        
        for(int i = 0; i < n; i++) {
           Meeting m(start[i],end[i],i+1);
           meet.push_back(m);
        }
        
        sort(meet.begin(),meet.end(),comp);
        
        int count = 1, maxEnd = meet[0].e;
        
        for(int i = 1; i < n; i++) {
           if(meet[i].s > maxEnd) {
               maxEnd = meet[i].e;
               count++;
           }
        }
        
        return count;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends