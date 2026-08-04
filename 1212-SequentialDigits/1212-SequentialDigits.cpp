// Last updated: 8/4/2026, 12:23:42 PM
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;

        int min = to_string(low).size();
        int max = to_string(high).size();

        for(int len = min; len <= max; len++){
            for(int i=0;i+len<=9;i++){
                int num = stoi(s.substr(i, len));

                if(num>=low&&num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};