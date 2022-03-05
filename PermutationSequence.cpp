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
    int factorial(int n){
        // cout<<"IH";
        int ans=1;
        for(int i=1; i<=n; i++) ans*=i;
        return ans;
    }
    string getPermutation(int n, int k) {
        string ans="";
        int n1=n;
        vector<int> a(n+1,0);
        while(n!=0)
        {
            int p = factorial(n-1);
            int l = k/p;
            if(k%p==0)
            {
                int k1=0;
                for(int i=1; i<=n1; i++)
                {
                    if(a[i]==0 && k1++==l-1)
                        ans+=to_string(i),a[i]=1;
                }
                for(int i=n1; i>=1; i--)
                    if(!a[i]) ans+=to_string(i);
                break;
            }
            else
            {
                int k1=0;
                for(int i=1; i<=n1; i++)
                {
                    if(a[i]==0 && k1++==l)
                        ans+=to_string(i),a[i]=1;
                }
            }
            n--;
            k-=p*l;
        }
        return ans;
    }
};
