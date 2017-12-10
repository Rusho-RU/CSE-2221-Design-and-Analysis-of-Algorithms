#include <bits/stdc++.h>
using namespace std;

vector<int>data;

void InsertionSort(){
    int index;
    for(int i=0; i<data.size(); i++){
        index = i;
        for(int j=i-1; j>=0; j--){
            if(data[j] > data[index]){
                swap(data[j], data[index]);
                index = i;
            }
        }
    }

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
    InsertionSort();
    stop = clock();

    double time = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("Execution time: %lf\n",time);

    //printf("After sorting:\n");
    //print();
}
