#include<iostream>
using namespace std;

void maxmin(int arr[],int i,int j,int *max,int *min)
{
    if(i==j)
        *max=*min=arr[i];
    else if(i+1==j){
        if(arr[i]>arr[j]){
            *max=arr[i];
            *min=arr[j];
        }
        else{
            *max=arr[j];
            *min=arr[i];
        }
    }   
    else{
        int mid=(i+j)/2;
        int max1,min1;
        maxmin(arr,i,mid,max,min);
        maxmin(arr,mid+1,j,&max1,&min1);
        if(max1>*max)
            *max=max1;
        if(min1<*min)
            *min=min1;
    }
}

int main(){
    int arr[]={5,6,3,8,2,9};
    int max,min;
    maxmin(arr,0,5,&max,&min);
    cout<<max<<endl<<min;
}