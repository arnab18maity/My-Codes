class Solution { 
public:
    int minimumPushes(string word) {
        int minPush = 0;
        vector<int> freq(26,0);
        
        for(int i = 0; i < word.size(); i++) {
           freq[word[i] - 'a']++;
        }
        
        sort(freq.rbegin(), freq.rend()); //Sorting the array in decending order
        
        int i = 1;
        int push = 1;
        
        for(auto it : freq) {
           minPush += it*push;
           i++;
           if(i % 8 == 1) push++;
        }
        
        return minPush;
    }
};