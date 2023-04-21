// https://leetcode.com/problems/permutation-sequence/

// FIRST AAPPROACH: Generate all permutations
class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};


// SECOND APPROACH: Find answer directly
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        
        for(int i=1; i<n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        
        k -= 1; // as we are using 0-based indexing
        
        string res = "";
        
        while(true) {
            res += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            
            if(nums.size() == 0) break; // no more elements left
            
            k %= fact;
            fact /= nums.size();
        }
        
        return res;
    }
};
