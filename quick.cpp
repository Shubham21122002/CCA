#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int s, int e) {
    int p = v[e];
    int i = s - 1;                                       //         p
    for (int j = s; j < e; j++) {                        //   4 3 2 1
                                                         // i j     
        if (v[j] < p) {
            i++;
            swap(v[i], v[j]);
        }
    }
    i++;
    swap(v[i], v[e]);
    return i;
}

void quick_sort(vector<int>& v, int s, int e) {
    if (s < e) {
        int p_index = partition(v, s, e);
        //quick_sort(v, s, p_index - 1);
        quick_sort(v, p_index + 1, e);
    }
}

void printArray(const vector<int>& v,int n) {
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

    quick_sort(v, 0, n - 1);

    cout << "After sorting : ";
    printArray(v,n);

    return 0;
}

