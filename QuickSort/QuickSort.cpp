#include <iostream>


using namespace std;
int partition(int [], int , int);
void quicksort(int [], int ,int);


int partition(int arr[], int low ,int high){

    int pivot = high-1;
    int i = low-1;
    int j= low;
    // 80 30 20 10 60 70
    // 30 80 20 10 60 70
    // 30 20 80 10 60 70
    // 30 20 10 80 60 70
    // 30 20 10 60 70 80
    for( ;j != pivot; j++){
        
        if(arr[j] < arr[pivot])
        {
            swap(arr[i+1],arr[j]);
            i++;
        }
        
    }

    swap( arr[i+1] , arr[pivot] );


    return i+1;
}

void quicksort(int arr[],int low ,int high)
{
    if(low < high){
        int t = partition(arr, low , high);
        
        quicksort(arr,low,t);
        quicksort(arr,t+1,high);
    }
    return ;
}


int main()
{
    int arr[20] = {0};
    for(int i =0; i < 20;i++)
        arr[i] = rand() % 100;

    quicksort(arr , 0 ,sizeof(arr) / sizeof(arr[0]) );
    for(int i =0; i <sizeof(arr) / sizeof(arr[0]) ;i++)
        cout << arr[i] << " ";
}