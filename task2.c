#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Insertion_Sort(int array[], int size) {
for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) 
    {
        array[j + 1] = array[j];
        --j;
    }
    array[j + 1] = key;
}
}

// function to find the partition position
int partition(int array[], int low, int high) {
int pivot = array[high];
int i = (low - 1);

for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
    i++;
    Swap(&array[i], &array[j]);
    }
}
Swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void Quick_Sort(int array[], int low, int high) {
if (low < high) {
    int pi = partition(array, low, high);
    Quick_Sort(array, low, pi - 1);
    Quick_Sort(array, pi + 1, high);
}
}
void printArray(int array[], int size) 
{
for (int i = 0; i < size; ++i) 
    printf("%d  ", array[i]);
printf("\n");
}

void main(){
        int arr[100000];
    int size= sizeof(arr)/sizeof(arr[1]);
    for(int i = 0;i<size;i++)
        arr[i]=rand()%100000;
    printf("Array of 100000 numbers is initialized");

    clock_t begin = clock();
    printf("\nInsertion Sort: ");
    Insertion_Sort(arr,size); 
    clock_t end = clock();
    double time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %lf seconds\n", time_spent2);

    begin = clock();
    printf("\nQuick Sort: ");
    Quick_Sort(arr, 0, size - 1);
    end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %lf seconds\n", time_spent);
}