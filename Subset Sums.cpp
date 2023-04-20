/*
Given a list arr of N integers, print sums of all subsets in it.
*/

class Solution
{
private:
    void subsetSumUtil(vector <int> arr, int n, int pos, int sum, vector <int> &res) {
        if (pos == n) {
            return;
        }
        
        for (int i = pos; i < n; i++) {
            sum += arr[i];
            res.push_back(sum);
            subsetSumUtil(arr, n, i + 1, sum, res);
            sum -= arr[i];
        }
    }
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector <int> res;
        res.push_back(0);
        subsetSumUtil(arr, N, 0, 0, res);
        return res;
    }
    
};

// Another way
class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
