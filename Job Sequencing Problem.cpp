// Using normal array for finding free slot
class Solution 
{
public:
    bool static comparator(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
    
        vector <int> slot(maxi + 1, -1);
        int cnt = 0, profit = 0;
        for (int i =0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    cnt++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, profit};
    } 
};

// Using set for finding free slot
class Solution 
{
public:
    bool static comparator(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        int cnt = 0, profit = 0;
        set <int> s;
        for (int i = 1; i <= maxi; i++) {
            s.insert(i);
        }
        for (int i = 0; i < n; i++) {
            auto it = s.upper_bound(arr[i].dead);
            if (it != s.begin()) {
                it--;
                s.erase(it);
                cnt++;
                profit += arr[i].profit;
            }
        }
        return {cnt, profit};
    } 
};
