// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string A) {
    string str;
    int n=A.length();
    while(1)
    {
        str=A;
        reverse(str.begin(),str.end());
        if(str==A) break;
        else A.pop_back();
    }
    return n-A.length();
}
