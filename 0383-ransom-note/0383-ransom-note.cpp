class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       if(ransomNote.length() > magazine.length()) return false;
        
        vector<int> a(26,0);
        
        for(int i = 0; i < magazine.length(); i++){
            char c = magazine[i];
            a[c-'a']++;
        }
        
        for(int i = 0; i < ransomNote.length(); i++){
            char c = ransomNote[i];            
            if(a[c-'a'] == 0){
                return false;
            }            
            a[c-'a']--;
        }
        
        return true; 
    }
};