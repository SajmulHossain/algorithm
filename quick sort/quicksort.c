#include <stdio.h>

void dekhabo(int create[], int size);
void quickSort(int create[], int low, int high);
int partition(int create[], int low, int high);

int main() {
    int create[] = {14, 12, 21, 7};
    int csize = sizeof(create) / sizeof(create[0]);

    printf("Jei array deya Hoyesey:\n\n");
    dekhabo(create, csize);

    quickSort(create, 0, csize - 1);

    printf("\nArray jeta pelam:\n\n");
    dekhabo(create, csize);

    return 0;
}

void dekhabo(int create[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", create[i]);
    printf("\n");
}

void quickSort(int create[], int low, int high) {
    if (low < high) {
        int pi = partition(create, low, high);

        quickSort(create, low, pi - 1);
        quickSort(create, pi + 1, high);
    }
}

int partition(int create[], int low, int high) {
    int pivot = create[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (create[j] <= pivot) {
            i++;
            temp = create[i];
            create[i] = create[j];
            create[j] = temp;
        }
    }

    temp = create[i + 1];
    create[i + 1] = create[high];
    create[high] = temp;

    return i + 1;
}
