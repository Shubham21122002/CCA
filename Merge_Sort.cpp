#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &v, int s,int mid, int e) { 
    
    vector<int> temp (e-s+1);

    int ind1 = s;
    int ind2 = mid+1;
    int x=0;
    int k=0;

    while(ind1 <= mid && ind2 <= e) {

        if(v[ind1] < v[ind2]) {
            temp[x] = v[ind1];
            x++;
            ind1++;
        }
        else {
            temp[x] = v[ind2];
            x++;
            ind2++;
        }
    }

    while(ind1 <= mid) { 

        temp[x] = v[ind1];
            x++;
            ind1++;
    }
    
    while(ind2 <= e) {

        temp[x] = v[ind2];
            x++;
            ind2++;
    }

    for (int j=0 ; j<temp.size(); j++) {

        v[s+j]= temp[j];
    }
}

void merge_sort(vector<int> &v, int s, int e) {
    if(s<e) {
        int mid = (s + e)/2;
        merge_sort(v, s, mid);
        merge_sort(v, mid+1, e);

        merge(v,s,mid,e);
    }
}

void printArray(const vector<int>&v,int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
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
    cout << "Before sorting : ";
    printArray(v,n);

    merge_sort(v, 0, n - 1);

    cout << "After sorting : ";
    printArray(v,n);

    return 0;
}

