#include<stdio.h>
#include<stdlib.h>

struct Job{
    int start, finish, profit;
};

int isNotOverLap(struct Job i, struct Job j){
    if(i.start >= j.finish){
        return 1;
    }
    return 0;
}

void weigthedJob(struct Job arr[], int i){
     int j=0;
     while(j < i){
        if(isNotOverLap(arr[i], arr[j])){
            arr[i].profit = (arr[i].profit + arr[j].profit > arr[i].profit) ? arr[i].profit + arr[j].profit:arr[i].profit;//max(arr[i].profit + arr[j].profit , arr[i].profit);
        }
        j++;
     }
}

void jobAllocation(struct Job arr[], int n){
    for(int i=1;i<n; i++){
        weigthedJob(arr,i);
    }
}
int cmpfunc(const void *a, const void *b){
    const struct Job *i = a;
    const struct Job *j = b;

    return i->profit - j->profit;
}
int main(){
    int n;
    printf("Enter the number of Jobs : ");
    scanf("%d", &n);
    struct Job *arr = (struct Job *)malloc(n * sizeof(struct Job));
    for(int i=0; i < n;i++){
        printf("\nEnter start, finish and profit : ");
        scanf("%d%d%d", &arr[i].start, &arr[i].finish, &arr[i].profit);
    }

    qsort(arr,n, sizeof(struct Job), cmpfunc);
    
    
    jobAllocation(arr,n);
    for(int i = 0 ; i< n;i++){
        printf("start : %d, finish: %d, profit: %d\n", arr[i].start, arr[i].finish, arr[i].profit);
    }
    return 0;
}