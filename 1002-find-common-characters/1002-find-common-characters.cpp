class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<int> freq(26,0);
        
       for(int i = 0; i < words[0].size(); i++) {
          char ch = words[0][i];
          freq[ch - 'a']++;
       }
        
      
       for(int i = 1; i < words.size(); i++) {
           vector<int> tempFreq(26,0);
           
           for(int j = 0; j < words[i].size(); j++) {
              char ch = words[i][j];
              tempFreq[ch - 'a']++;
           }
           
           for(int k = 0; k < 26; k++) {
              freq[k] = min(freq[k], tempFreq[k]);
           }
       }
        
       vector<string> res;
        
       for(int k = 0; k < 26; k++) {
          while(freq[k] > 0) {
             char ch =  'a' + k;
             string temp = "";
             temp += ch;
             res.push_back(temp);
             freq[k]--;
          } 
       } 
        
       return res;
        
    }
};