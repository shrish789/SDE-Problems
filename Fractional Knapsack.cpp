class Solution
{
private:
    bool static comparator (Item a, Item b) {
        return a.value * 1.0 / a.weight > b.value * 1.0 / b.weight;
    }
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comparator);
        double ans = 0.0;
        for (int i = 0; i < n && W > 0; i++) {
            if (W >= arr[i].weight) {
                ans += arr[i].value;
                W -= arr[i].weight;
            } else {
                ans += arr[i].value * 1.0 / arr[i].weight * W;
                W = 0;
            }
        }
        return ans;
    }
        
};
