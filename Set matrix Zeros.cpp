#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int col0=1,m=matrix.size(), n=matrix[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0){
				if(j==0){
					col0=0;
				}
				else{
					matrix[0][j]=matrix[i][0]=0;
				}
			}
		}
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(matrix[0][j]==0 || matrix[i][0]==0){
				matrix[i][j]=0;
			}
		}
	}
	if(matrix[0][0]==0){
		for(int j=0;j<n;j++){
			matrix[0][j]=0;
		}
	}
	if(col0==0){
		for(int i=0;i<m;i++){
			matrix[i][0]=0;
		}
	}
}
