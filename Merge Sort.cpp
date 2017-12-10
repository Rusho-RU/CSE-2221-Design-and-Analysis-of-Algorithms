#include <bits/stdc++.h>
using namespace std;

vector<int>data;

void mergeSort(int left, int right){
    if(left==right)
        return;
    int mid = (left + right)/2;

    mergeSort(left, mid);
    mergeSort(mid+1, right);

    vector<int>temp;

    for(int i=left, j=mid+1, k=left; k <= right; k++){
        if(i==mid+1) temp.push_back(data[j++]);
        else if(j==right+1) temp.push_back(data[i++]);
        else if(data[i] < data[j]) temp.push_back(data[i++]);
        else temp.push_back(data[j++]);
    }

    for(int i=0, j=left; j<=right; i++, j++)
        data[j] = temp[i];

    return;
}

void print(){
    for(int i=0; i<data.size(); i++)
        printf("%d\n",data[i]);
    puts("");
}

int main(){
    int n;
    clock_t start, stop;

    printf("How many data you want to sort: ");
    scanf("%d",&n);

    while(n--)
        data.push_back(rand());

    //printf("Before sorting:\n");
    //print();

    start = clock();
    mergeSort(0, data.size()-1);
    stop = clock();

    double time = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("Execution time: %lf\n",time);

    //printf("After sorting:\n");
    //print();
}
