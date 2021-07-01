#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
   
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    char *bag = (char *)malloc(26 * sizeof(char));
    memset(bag, '$', 26);
    printf("\n\nBefore : %s\n\n", *bag);
    int i=0, count1=0, count2=0;
    for(i=0;i < strlen(a); i++){
        if(bag[a[i]-97] == '$'){
           bag[a[i]-97] = '1';
           count1++;
        }
    }
    
    printf("\n\nAfter : %s\n\n", *bag);
    memset(bag, '$', 26);

    printf("\n\nBefore : %s\n\n", *bag);
    for(i=0;i < strlen(a); i++){
        if(bag[a[i]-97] == '$'){
           bag[a[i]-97] = '1';
           count2++;
        }
    }

    puts(bag);
    int r = count1 - count2;
    free(bag);
    if(r!=0)
        return r;
    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int r = strlen(a) - strlen(b);
    return (r)? r: lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i=0,top = len-1;
   
    char go= 0;
    while(! go){
        go = 1;
        for(i=0; i< top;i++){
            if(cmp_func(arr[i], arr[i+1]) > 0 ){
                char *v = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = v;
                go = 0;
            }
        }
        top--;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
