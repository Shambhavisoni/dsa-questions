//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string isCircular(string path);

int main(){
    int t;
    cin >> t;
    while(t--){
        string path;
        cin >> path;
        cout << isCircular(path) << endl;
    }
return 0;
}
// } Driver Code Ends


string isCircular(string path){
    //complete the function here
    int n=path.size(), x=0, y=0;
    // north->1 south->2 east->3 west->4
    int dir=3;
    
    for(int i=0;i<n;i++){
        if(path[i]=='G'){
            if(dir==1){
                x--;
            }
            else if(dir==2){
                x++;
            }
            else if(dir==3){
                y++;
            }
            else if(dir==4){
                y--;
            }
        }
        else if(path[i]=='L'){
            if(dir==1){
                dir=4;
            }
            else if(dir==2){
                dir=3;
            }
            else if(dir==3){
                dir=1;
            }
            else if(dir==4){
                dir=2;
            }
        }
        else{
            if(dir==1){
                dir=3;
            }
            else if(dir==2){
                dir=4;
            }
            else if(dir==3){
                dir=2;
            }
            else if(dir==4){
                dir=1;
            }
        }
    }
    if(x==0 && y==0){
        return "Circular";
    }
    return "Not Circular";
}