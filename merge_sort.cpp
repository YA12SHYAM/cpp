#include<iostream>
using namespace std;

void merge_sort(int [], int start, int end);
void merge (int [],int start, int mid, int end);
void print_array(int [], int start, int end);
void swap(int*, int*);

int main(int argc, char const *argv[])
{   
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    //cout<<"input the size of the array"<<endl;

    int arr[size];

    //cout<<"input the array"<<endl;
    for( int i=0; i<size;i++){
        cin>>arr[i];
    }

    print_array(arr,0,size-1);
    
    merge_sort(arr,0,size-1);

    print_array(arr,0,size-1);


    int a = 9;
    int b = 10;

    swap(&a, &b);
    cout<<endl<<a<<" "<<b;

    return 0;
}

void print_array(int arr[], int start, int end){
    for(int i = start; i <= end; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge_sort(int arr[], int start, int end){

    if(start == end){
        return;
    }
    int mid = start + ((end-start)/2);

    merge_sort(arr,start, mid);
    //cout<<"left half ";
    //print_array(arr,start,mid);
   

    merge_sort(arr,mid+1,end);
    //cout<<"right half ";
    //print_array(arr, mid+1,end);

    //cout<<endl;
    merge(arr, start, mid, end);

}

void merge(int arr[], int start, int mid, int end){
   
    int indx1 = start;
    int indx2 = mid + 1;

    int size = end - start + 1;
    //cout<<"size: "<<size;

    int temp[size] ;
    int temp_indx = 0;

    //cout<< " start:"<<start<<" mid:"<<mid<<" end:"<<end;

    while(indx1<=mid && indx2<=end){
        if(arr[indx1] <= arr[indx2]){
            temp[temp_indx] = arr[indx1];
            indx1++;
            temp_indx++;
        }
        else{
            temp[temp_indx] = arr[indx2];
            indx2++;
            temp_indx++;
        }

    }
    while(indx1<=mid){
        temp[temp_indx] = arr[indx1];
        indx1++;
        temp_indx++;
    }
    while(indx2<=end){
        temp[temp_indx] = arr[indx2];
        indx2++;
        temp_indx++;
    }

    for ( int i = 0 ; i < size; i++){
        arr[i+start] = temp[i];
    }

    //cout<<" sorted_Array"<<" ";
    //print_array(arr,start,end);
    //cout<<endl;
}

void swap(int* a, int* b){
    int temp;
    
     temp = *a;
     *a = *b;
     *b = temp ;
    
}