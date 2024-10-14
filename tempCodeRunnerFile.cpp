#include <iostream>
#include <vector>
using namespace std;

pair<int,int> findminmax(vector<int> &v, int s, int e) {
     
     int mx, mn;

     if(s == e) {

        mn = v[s];
        mx = v[s];
     }
     else if ((s+1) == e) {

        if(v[e] > v[s]) { 

            mn = v[s];
            mx = v[e];
        }
        else {
            mn = v[e];
            mx = v[s]; 

        }
     }

     else {


        int mid = (s + e)/2;

        auto left = findminmax(v,s,mid);
        auto right = findminmax(v,mid+1,e);

        mn=min(left.first,right.first);
        mx=max(left.second,right.second);

     }

    return {mn,mx};
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> v(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
   
    pair<int, int>ans = findminmax(v,0,n-1);
    cout<<"Minimum : "<< ans.first << endl;
    cout<<"Maximum : "<< ans.second << endl;



    return 0;
}
