class Solution {
public:
/****optimal solution****/
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
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
};
/*****better solution****/
// void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<int> dummyRow(m, 0);
//         vector<int> dummyCol(n, 0);

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     dummyRow[i]=dummyCol[j]=1;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(dummyRow[i] || dummyCol[j]){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }

 /******brute force******/
//     void setRow(vector<vector<int>>& matrix, int i, int n){
//         for(int j=0;j<n;j++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]=-1e9;
//             }
//         }
//     }
//     void setCol(vector<vector<int>>& matrix, int j, int m){
//         for(int i=0;i<m;i++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]=-1e9;
//             }
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     setRow(matrix, i, n);
//                     setCol(matrix, j, m);
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==-1e9){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
/*****My approach*****/
// void allZeros(vector<vector<int>>& matrix,vector<vector<int>>& v, int i, int j, int m, int n){
//         int row=0;
//         while(row<m){
//             matrix[row][j]=0;
//             row++;
//         }
//         int col=0;
//         while(col<n){
//             matrix[i][col]=0;
//             col++;
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<vector<int>> v;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     v.push_back({i,j});
//                 }
//             }
//         }
//         for(int i=0;i<v.size();i++){
//             allZeros(matrix, v, v[i][0], v[i][1], m, n);
//         }
//     }