#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10 
int arr[NUM], temp[NUM];

void insert_sort( int arr[], int cnt )
{
    int i, j;
    int temp;
    for ( i = 0; i < cnt; i++ )
    {
        temp = arr[i];
        //printf( "%d\n", temp );
        j = i-1;
        while ( j >= 0 && temp < arr[j] )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}

void merge_sort( int arr[], int left, int right, int temp[] )
{
    int i;
    if ( left < right )
    {
        int mid = (left+right)/2;
        merge_sort( arr, left, mid, temp );
        merge_sort( arr, mid+1, right, temp );
        for ( i = left; i <= right; i++ )
            temp[i] = arr[i];
        int pos = left;
        int left_index = left, right_index = mid+1;
        while ( left_index <= mid && right_index <= right )
        {
            if ( temp[left_index] < temp[right_index] )
                arr[pos++] = temp[left_index++];
            else
                arr[pos++] = temp[right_index++];
        }
        if ( left_index <= mid )
            for ( i = left_index; i <= mid; i++ )
                arr[pos++] = temp[i];
        if ( right_index <= right )
            for ( i = right_index; i <= right; i++ )
                arr[pos++] = temp[i];
    }
    return;
}

void quick_sort( int arr[], int left, int right )
{
    if ( left < right )
    {
        int key = arr[left];
        int i = left, j = right;
        while ( i < j )
        {
            for (; j>i; j-- )
                if ( arr[j] < key )
                {
                    arr[i++] = arr[j];
                    break;
                }
            for (; j>i; i++ )
                if ( arr[i] > key )
                {
                    arr[j--] = arr[i];
                    break;
                }
        }
        arr[i] = key;
        quick_sort( arr, left, i );
        quick_sort( arr, i+1, right );
    }
    return;
}

int main()
{
    int i;
    clock_t start, finish;
    srand( (unsigned int)time(NULL) );
    for ( i = 0; i < NUM; i++ )
        arr[i] = rand();
    for ( i = 0; i < NUM; i++ )
        printf( "%d\n", arr[i] );

    start = clock();

    //insert_sort( arr, NUM );
    merge_sort( arr, 0, NUM-1, temp );
    //quick_sort( arr, 0, NUM-1 );

    finish = clock();
    printf( "time: %f\n", (double)(finish-start)/CLOCKS_PER_SEC);

    for ( i = 0; i < NUM; i++ )
        printf( "%d\n", arr[i] );
    return 0;
}
