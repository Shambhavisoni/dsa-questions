#include <bits/stdc++.h>
vector<long long int> createRow(int i, int n){
  vector<long long int> arr;
  long long int ans=1;
  arr.push_back(1);
  for(int i=1;i<n;i++){
    ans=ans*(n-i);
    ans=ans/i;
    arr.push_back(ans);
  }
  return arr;
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  for(int i=1;i<=n;i++){
    ans.push_back(createRow(i,n));
  }
  return ans;

}
