#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int *findKeyValue(char *key){

   int i, *Arr = (int *)malloc(strlen(key) * sizeof(int));
   int index[strlen(key)];
   for(i=0; i < strlen(key) ; i++){
      Arr[i] = key[i] - 96;
   }
   return Arr;
}

char *transposition( char* message,  char* key, int nu){
   // char **temp = (char **)malloc(strlen(message)/strlen(key) * sizeof(char *));
    
    //char **temp;// , *messTemp = message , *keytemp =key;
   
     int i=0,k=0,j=0,row = ceil(strlen(message)/ strlen(key));
     char **temp =(char **)malloc(row * sizeof(char *));
     
     int *keyArr;
     keyArr = findKeyValue(key);

     for(i =0,k=0 ;i < row ; i++){
	temp[i] = (char *) malloc(strlen(key) * sizeof(char));
	for(j=0;j < strlen(key);j++ ){
	   if(k < strlen(message)){
	     temp[i][j] = message[k++];
	   }else{
	     temp[i][j] = 'X';
	   }
	}
    } 
   
  // printf("%s",*temp);
  char *res = (char *) malloc(strlen(message) * sizeof(char));
   for(i=0;i<row;i++){ 
	    k = keyArr[i] * row - 1;
     for(j=0;j<strlen(key);j++){
       res[k++] = temp[i][j];
     }
   }
   res[i*j] = '\0';
    free(temp);
    return  res;

}

int main(){
   char *message = "ATTACKMEIFUCANINANYWHERE";
   char *key = "cbdae";
   int numTran = 1;
   char *res;
   res = transposition(message , key , numTran);
   printf("%s", res);
   return 0;
}
