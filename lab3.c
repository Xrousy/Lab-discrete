#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char* elements;
    int size;
} Sets;

void duplicates(Sets* set) 
{
    if (set->size < 1) 
    {
        return;
    }
    for (int i = 0; i < set->size - 1; i++) 
    {
        for (int j = i + 1; j < set->size; j++) 
        {
            if (set->elements[i] == set->elements[j]) 
            {
                for (int k = j; k < set->size - 1; k++) 
                { 
                    set->elements[k] = set->elements[k+1];
                }
                set->size--;
                set->elements = realloc(set->elements, set->size * sizeof(char));
                j--;
            }
        }
    }
}

void addtoSets(Sets* set, char element) 
{
    set->size++;
    set->elements = realloc(set->elements, set->size * sizeof(char));
    set->elements[set->size - 1] = element;
}

void printArray(Sets* A) 
{
    for (int i = 0; i < A->size; i++) 
    {
        printf("%c ", A->elements[i]);
    }
    printf("\n");
}

void swap(char *a, char *b) 
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *arr, int start, int end) 
{
    while (start < end) 
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void generatePermutations(Sets* A, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (A->elements[j] > A->elements[j+1]) 
            {
                swap(&A->elements[j], &A->elements[j+1]);
            }
        }
    }

    printArray(A);

    while (1) 
    {
        int k = -1;
        for (int i = n-2; i >= 0; i--) 
        {
            if (A->elements[i] < A->elements[i+1]) 
            {
                k = i;
                break;
            }
        }

        if (k == -1) 
        {
            break;
        }

        int l = -1;
        for (int i = n-1; i > k; i--) 
        {
            if (A->elements[i] > A->elements[k]) 
            {
                l = i;
                break;
            }
        }

        swap(&A->elements[k], &A->elements[l]);

        reverse(A->elements, k+1, n-1);

        printArray(A);
    }
}

int main() 
{
    Sets A;
    A.size = 0;
    A.elements = NULL;

    printf("Введите элементы множества A:\n");
    char inputA[100];
    fgets(inputA, sizeof(inputA), stdin);
    int lengthA = strlen(inputA);
    if (inputA[lengthA - 1] == '\n') 
    {
        inputA[lengthA - 1] = '\0';
    }  
    
    for (int i = 0; i < strlen(inputA); i++) 
    {
        addtoSets(&A, inputA[i]);
    }
    duplicates(&A);
    generatePermutations(&A, A.size);

    return 0;
}

