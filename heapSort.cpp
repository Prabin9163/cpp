
  // Sorting - Heap Sort

#include<iostream>
using namespace std;

void Heapify(int arr[],int n,int i)
{
    int largest=i;  
    int l=2*i+1;    
    int r=2*i+2;    
    if(l<n && arr[l]>arr[largest]) 
        largest=l;
    if(r<n && arr[r]>arr[largest])  
        largest=r;
    if(largest !=i) 
    {
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);   
    }
}
void HeapSort(int arr[],int n)
{
   for(int i=n/2-1;i>=0;i--)  
        Heapify(arr,n,i);
   for(int i=n-1;i>0;i--)     
   {
       swap(arr[0],arr[i]);    
       Heapify(arr,i,0);      
   }
}
int main()
{
    int arr[]={4,1,3,8,5,7,10,6,9,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Given array : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    HeapSort(arr,n);

    cout<<"\nSorted array : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
