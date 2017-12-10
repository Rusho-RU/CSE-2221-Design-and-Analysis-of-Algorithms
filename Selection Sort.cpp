#include <bits/stdc++.h>
using namespace std;

vector<int>data;

void SelectionSort(){
    for(int i=0; i<data.size(); i++){
        int m = i;

        for(int j=i+1; j<data.size(); j++)
            if(data[j] < data[m])
                m = j;

        swap(data[i], data[m]);
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
    SelectionSort();
    stop = clock();

    double time = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("Execution time: %lf\n",time);

    //printf("After sorting:\n");
    //print();
}
