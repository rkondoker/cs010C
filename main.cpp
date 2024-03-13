#include <iostream>
#include <time.h>

using namespace std;


const int NUMBERS_SIZE = 50000;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
    }
    void fillArrays(int arr1[], int arr2[],int arr3[]){
        for(int i = 0; i < NUMBERS_SIZE; ++i){
            arr1[i] = genRandInt(0,NUMBERS_SIZE);
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
    }

int Partition(int numbers[], int i, int k){
    int midPoint = i + (k - i)/2;
    int pivot = numbers[midPoint];

    bool complete = false;
    while(!complete){
        while (numbers[i] < pivot){
            i += 1;
        }

        while (pivot < numbers[k]){
            k -= 1;
        }

        if (i >= k) complete = true;
        else {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i += 1;
            k -= 1;
        }
    }
    return k;
}

void Quicksort_midPoint(int numbers[], int i, int k){
    if (i >= k) return;

    int lowEndIndex = Partition(numbers, i, k);
    Quicksort_midPoint(numbers, i, lowEndIndex);
    Quicksort_midPoint(numbers, lowEndIndex + 1, k);
}



int PartitonMedianOfThree(int numbers[], int i, int k){
    int midPoint;// = i + (k - i)/2;

    if (numbers[i] < numbers[k] && numbers[i] > numbers[(i+k)/2]){
        midPoint = i;
    }
    else if (numbers[k] < numbers[i] && numbers[k] > numbers[(i+k)/2]){
        midPoint = k;
    }
    else {
        midPoint = (i+k)/2;
    }
    int pivot = numbers[midPoint];

    bool complete = false;
    while(!complete){
        while (numbers[i] < pivot){
            i += 1;
        }

        while (pivot < numbers[k]){
            k -= 1;
        }

        if (i >= k) complete = true;
        else {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i += 1;
            k -= 1;
        }
    }
    return k;
}

void Quicksort_medianOfThree(int numbers[], int i, int k){
    if (i >= k) return;

    int lowEndIndex = PartitonMedianOfThree( numbers, i, k);
    Quicksort_medianOfThree(numbers, i, lowEndIndex);
    Quicksort_medianOfThree(numbers, lowEndIndex + 1, k);
}

void InsertionSort(int numbers[], int numbersSize){
    int i;
    int j;
    int temp;

    for (i = 1; i < numbersSize; ++i){
        j = i;
        while(j > 0 && numbers[j] < numbers[j - 1]){
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}


int main(){
    

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1,arr2,arr3);


    

    clock_t Start = clock();
    //call sort function here
    Quicksort_midPoint(arr1, 0, NUMBERS_SIZE);
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    InsertionSort(arr3, NUMBERS_SIZE);

    clock_t End = clock();

    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << elapsedTime << endl;

return 0;
}