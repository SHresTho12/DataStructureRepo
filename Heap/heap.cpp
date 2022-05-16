#include<bits/stdc++.h> 
using namespace std;

//inserting a element in the heap
void Insert(int Array[],int n){
    int temp , i = n;
    temp = Array[n];

    while(i>1 && temp>Array[i/2]){
        Array[i] = Array[i/2];
        i = i / 2 ;
    }
    Array[i] = temp;
}

//In heap you always delete the top element
int heapDelete(int Array[] , int n){
    int temp , i , j , value;
    value = Array[1];
    temp = Array[n];
    Array[n] = Array[1];
    Array[1] = temp;
   
    i = 1 ; j = 2 * i;

while(j<n-1){
    if(Array[j]<Array[j+1]){
        j = j+1;
        }
    if(Array[i]<Array[j]){
        int temp2 = Array[i];
        Array[i] = Array[j];
        Array[j] = temp2;
        i = j;
        j = 2 * j;
    }
    else{break;}
}
return value;
}
void createHeap(int Array[] , int n){
    for(int i = 1 ; i < n ; i++ ){
        Insert(Array , i);
    }
}
void printArray(int Array[],int n){
    for(int i= 0 ; i <n ; i++){
        cout<<Array[i]<<endl;
    }
}



int main(){
int Array[]= {0 , 10 , 20 , 30 , 25 , 5 , 40 , 35};
createHeap(Array,8);
printArray(Array,8);

//Heap sort using delete option
for(int i = 7 ; i >1 ; i--){
    heapDelete(Array,i);
}
cout<<endl;
printArray(Array,8);
}