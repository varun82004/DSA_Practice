// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high,int &count);
void mergesort(int arr[],int low,int high,int &count)
{
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        mergesort(arr,low,mid,count);
        mergesort(arr,mid+1,high,count);
        merge(arr,low,mid,high,count);
    }
    return;
}
void merge(int arr[], int low, int mid, int high, int &count)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1];
    int r[n2];
    
    for (int i = 0; i < n1; i++)
    {
        count += 1;
        l[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        count += 1;
        r[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        count += 1;
        if (l[i] <= r[j])
        {
            arr[k++] = l[i++];
        }
        else
        {
            arr[k++] = r[j++];
        }
    }
    
    // Copy remaining elements of l[] and r[], if any
    while (i < n1)
    {
        count += 1;
        arr[k++] = l[i++];
    }
    while (j < n2)
    {
        count += 1;
        arr[k++] = r[j++];
    }
}

int main() {
    int arr[6]={7,8,9,1,3,4};
    cout<<"Before Sorting : \n";
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<"\t";;
    }
    int count;
    mergesort(arr,0,5,count);
    cout<<endl;
    cout<<"After Sorting : \n";
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<"\t";;
    }
    cout<<endl<<"No. of iterations = "<<count;
    return 0;
}