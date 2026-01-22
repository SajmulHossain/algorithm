#include <stdio.h>

void dekhabo(int create[], int size);
void merge(int create[], int left, int mid, int right);
void mergeSort(int create[], int left, int right);

int main() {
    int create[]= {14,12,21,7};
    int csize= sizeof(create)/sizeof(create[0]);
    printf("Jei array deya Hoyesey:\n\n");
    dekhabo(create,csize);
    mergeSort(create,0,csize-1);
    printf("\nArray jeta pelam:\n\n");
    dekhabo(create,csize);
    return 0;
}

void dekhabo(int create[], int size) {
    int i;
    for (i =0;i<size;i++)
        printf("%d ", create[i]);
    printf("\n");
}

void merge(int create[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right- mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = create[left + i];
    for (j = 0; j < n2; j++)
        R[j] = create[mid+ 1 + j];
    i = 0;
    j = 0;
    k = left;

    while (i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            create[k]=L[i];
            i++;
        }
        else {
            create[k] = R[j];
            j++;
        }
        k++;
    }

    while(i< n1) {
        create[k]=L[i];
        i++;
        k++;
    }

    while (j<n2) {
        create[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int create[], int left, int right) {
    if (left<right){
        int mid = left+(right -left)/2;
        mergeSort(create, left, mid);
        mergeSort(create, mid +1, right);
        merge(create, left, mid, right);
    }
}