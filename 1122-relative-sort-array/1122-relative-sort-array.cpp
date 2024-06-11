class Solution {
public:
    static bool comp(pair<int,int> p1, pair<int,int> p2) {
        if(p1.second == p2.second) {
           return p1.first < p2.first;
        }
        
        return p1.second < p2.second;
    } 
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       unordered_map<int,int> mp;
        
       for(int i = 0; i < arr2.size(); i++) {
           mp[arr2[i]] = i;
       }
        
       vector<pair<int,int>> ans;
        
       for(int i = 0; i < arr1.size(); i++) {
          if(mp.find(arr1[i]) == mp.end()) {
            ans.push_back({arr1[i],arr2.size()}); 
          }
           
          else ans.push_back({arr1[i],mp[arr1[i]]}); 
       }
        
       sort(ans.begin(),ans.end(),comp);
        
       for(int i = 0; i < arr1.size(); i++) {
           arr1[i] = ans[i].first;
       }
        
       return arr1;
    }
};