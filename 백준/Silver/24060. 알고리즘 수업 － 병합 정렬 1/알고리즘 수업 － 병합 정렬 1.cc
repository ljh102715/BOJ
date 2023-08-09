#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
void merge_sort(int arr[], int start, int end, int k);
void merge(int arr[], int start, int middle, int end, int k);
int cnt = 0;
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num, k;
	int arr[500000];
	cin >> num >> k;
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	
	merge_sort(arr, 0, num-1, k);
	if(cnt < k) cout << "-1";
}
void merge_sort(int arr[], int start, int end, int k){
    int p = start, r = end, q;
    if(p<r){
        q = (p+r)/2;
        merge_sort(arr, p, q, k);
        merge_sort(arr, q+1, r, k);
        merge(arr, p, q, r, k);
    }
}
void merge(int arr[], int p, int q, int r, int k){
    int tmp[r+2]; 
    int i = p, j = q+1, t = 1;
    while(i<=q && j<=r){
        if(arr[i]<=arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }
    while(i<=q)
        tmp[t++] = arr[i++];
    while(j<=r)
        tmp[t++] = arr[j++];
    i = p, t = 1;
    while(i<=r){
        arr[i++] = tmp[t++];
    	if(++cnt==k)   cout << tmp[t-1];
    }
}