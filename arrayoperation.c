#include <stdio.h>

//array tracersal
void arrayTraversal(int arr[], int size){
    printf("elem of array are : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//reverse traversal
void reverseTraversal(int arr[], int size){
    printf("elem of array in reverse order are: \n");
    for (int i = size-1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//element insertion
int elemInsert(int arr[], int size, int capacity, int elem, int index){
    if (capacity == size)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = elem;
    return 1;  
}
//element deletion
int elemDelete(int arr[], int size, int index, int capacity){
    if (capacity == 0)
    {
        return -1;
    }
    
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
}
//search operation
//linear search
int linearSearch(int arr[], int size, int item){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            return i;
        } 
    }
    return -1;
}
//binary search
int binarySearch(int arr[], int size, int item){
    int low = 0, high = size-1, mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if (arr[mid] == item)
        {
            return mid;
        }else if (arr[mid] > item)
        {
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int size, capacity = 100, elem, index;
    printf("enter the size of the array\n");
    scanf("%d", &size);
    int arr[size];

    printf("enter the elements of the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // array traversal
    printf("array traversal\n");
    arrayTraversal(arr,size);
    printf("reverse array traversal\n");
    reverseTraversal(arr,size);

    //array insertion
    printf("insertion operation\n");
    printf("enter the index where you want to insert element: \n");
    scanf("%d", &index);
    printf("enter the element you want to insert\n");
    scanf("%d", &elem);
    int i_res = elemInsert(arr,size,capacity,elem,index);
    if (i_res == -1)
    {
        printf("element not inserted!!!\n");
    }else{
        printf("element inserted!!!!\n");
        size++;
    }
    arrayTraversal(arr,size);

    //deletion operation
    printf("delete operation\n");
    int d_index;
    printf("enter the index of item to be deleted\n");
    scanf("%d", &d_index);
    int d_res = elemDelete(arr,size,d_index,capacity);
    if (d_res == -1)
    {
        printf("item not deleted\n");
    }else{
        printf("item deleted!!!\n");
        size--;
    }
    arrayTraversal(arr,size);

    //search operation
    //linear search
    printf("linear search\n");
    int item;
    printf("enter the item you want to search\n");
    scanf("%d", &item);
    int linear_res = linearSearch(arr,size,item);
    if (linear_res == -1)
    {
        printf("item not found in linear search\n");
    }else{
        printf("item found at %d index position in linear search\n", linear_res);
    }

    //binary search
    printf("binary search\n");
    int key;
    printf("enter the element you want to search in binary search\n");
    scanf("%d", &key);
    int b_res = binarySearch(arr,size,key);
    if (b_res == -1)
    {
        printf("item not found in binary search\n");
    }else{
        printf("item found at %d index in binary search\n", b_res);
    }
    
    
    return 0;
}