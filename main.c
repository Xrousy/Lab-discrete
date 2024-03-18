#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // Структура для создание множества
{
    char* elements;
    int size;
}Sets;

Sets createSets() // Функция для создания множества
{
    Sets newSets;
    newSets.size = 0;
    newSets.elements = NULL;
    return newSets;
}
 
void addtoSets(Sets* set, char element)
{
    set->size++;
    set->elements = realloc(set->elements, set->size * sizeof(char));
    set->elements[set->size - 1] = element;
}

void duplicates(Sets* set) // Функция удаляет одинаковые эллементы
{
    if (set->size <=1)
    {
        return;
    }
    for(int i = 0; i < set->size - 1; i++)
    {
        for(int j = i + 1; j < set->size; j++)
        {
            if(set->elements[i] == set->elements[j])
            {
                for(int k = j; k < set->size - 1; k++)
                { 
                    set->elements[k] = set->elements[k+1];
                }
                set->size--;
                set->elements = realloc(set->elements, set->size * sizeof(char));
            }
        }
    }
}

void sortSets(Sets* set) // Сортирует множества;
{
    if(set->size <= 1)
    {
        return;
    }
    char temp;
    for(int i = 0; i < set->size - 1; i++)
    {
        for(int j = i + 1; j < set->size; j++)
        {
            if(set->elements[i] > set->elements[j])
            {
                temp = set->elements[i];
                set->elements[i] = set->elements[j];
                set->elements[j] = temp;
            }
        }
    }
}

int AentryB(Sets setA, Sets setB) // Проверка на вхождении одного множества в другое
{   
    int found = 0;
    for(int i = 0; i< setA.size; i++)
    {
        for(int j = 0; j < setB.size; j++)
        {
            if(setA.elements[i] == setB.elements[j])
            {
                found = 1;
                break;
            }
        }    
    }
    if(found == 0)
        {
            return 0;
        }
    return 1;
}
Sets unionSets(Sets setA, Sets setB) // объединение
{
    Sets result = createSets();
    for(int i = 0; i < setA.size; i++)
    {
        addtoSets(&result, setA.elements[i]);
    }
    for(int i = 0; i < setB.size; i++)
    {
        addtoSets(&result, setB.elements[i]);
    }
    duplicates(&result);
    sortSets(&result);
    return result;

}
Sets intersectionSets(Sets setA, Sets setB) // пересечение 
{
    Sets result = createSets();
    for(int i = 0; i < setA.size; i++)
    {
        for(int j = 0; j < setB.size; j++)
        {
            if(setA.elements[i] == setB.elements[j])
            {
                addtoSets(&result, setA.elements[i]);
                break;
            }
        }
    }
    duplicates(&result);
    sortSets(&result);
    return result;    
}

Sets difference(Sets setA, Sets setB) // разность множеств
{
    Sets result = createSets();
    for(int i = 0; i < setA.size; i++)
    {
        int found = 0;
        for(int j = 0; j < setB.size; j++)
        {
            if(setA.elements[i] == setB.elements[j])
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            addtoSets(&result, setA.elements[i]);
        }
    }
    duplicates(&result);
    sortSets(&result);
    return result;
}

int main()
{
    Sets setA = createSets();
    Sets setB = createSets();

    printf("Введите элементы множества A:\n");
    char inputA[100];
    fgets(inputA, sizeof(inputA), stdin);
    int lengthA = strlen(inputA);
    if(inputA[lengthA - 1] == '\n')
    {
        inputA[lengthA - 1] = '\0';
    }
    for(int i = 0; i < strlen(inputA); i++)
    {
        addtoSets(&setA, inputA[i]);
    }
    duplicates(&setA);
    sortSets(&setA);

    printf("Введите элементы множества B:\n");
    char inputB[100];
    fgets(inputB, sizeof(inputB), stdin);
    int lengthB = strlen(inputB);
    if(inputB[lengthB - 1] == '\n')
    {
        inputB[lengthB - 1] = '\0';
    }
    for(int i = 0; i < strlen(inputB); i++)
    {
        addtoSets(&setB, inputB[i]);
    }
    duplicates(&setB);
    sortSets(&setB);
    
    int choice = 0;
    while (choice != 5) 
    {
        printf("Выберите операцию:\n");
        printf("1. Проверить вхождение A в B\n");
        printf("2. Выполнить объединение A и B\n");
        printf("3. Выполнить пересечение A и B\n");
        printf("4. Выполнить разность A и B\n");
        printf("5. Выйти из программы\n");
        printf("Введите номер операции: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            int temp = AentryB(setA, setB);
            if(temp != 0)
            {
                printf("Множество A является подмножеством B\n");
                printf("Множество A: ");
                for(int i = 0; i < setA.size; i++)
                {
                    printf("%c ", setA.elements[i]);
                }
                printf("Множество B: ");
                for(int i = 0; i < setB.size; i++)
                {
                    printf("%c ", setB.elements[i]);
                }
            }
            else
            {
                printf("Множество A не является подмножеством B\n");
                printf("Множество A: ");
                for(int i = 0; i < setA.size; i++)
                {
                    printf("%c ", setA.elements[i]);
                }
                printf("Множество B: ");
                for(int i = 0; i < setB.size; i++)
                {
                    printf("%c ", setB.elements[i]);
                }
            }
            printf("\n");
            break;
        case 2:
            printf("Результат объединения множеств A и B: ");
            Sets unionResult = unionSets(setA, setB);
            for(int i = 0; i < unionResult.size; i++)
            {
                printf("%c ", unionResult.elements[i]);
            }
            printf("\n");
            printf("Множество A: ");
                for(int i = 0; i < setA.size; i++)
                {
                    printf("%c ", setA.elements[i]);
                }
                printf("Множество B: ");
                for(int i = 0; i < setB.size; i++)
                {
                    printf("%c ", setB.elements[i]);
                }
            printf("\n");
            break;
        case 3:
            printf("Результат пересечения множеств A и B: ");
            Sets intersectionResult = intersectionSets(setA, setB);
            for(int i = 0; i < intersectionResult.size; i++)
            {
                printf("%c ", intersectionResult.elements[i]);
            }
            printf("\n");
            printf("Множество A: ");
                for(int i = 0; i < setA.size; i++)
                {
                    printf("%c ", setA.elements[i]);
                }
                printf("Множество B: ");
                for(int i = 0; i < setB.size; i++)
                {
                    printf("%c ", setB.elements[i]);
                }
            printf("\n");
            break;
        case 4:
            printf("Результат разности множеств A и B: ");
            Sets differenceResult = difference(setA, setB);
            for (int i = 0; i < differenceResult.size; i++) 
            {
                printf("%c ", differenceResult.elements[i]);
            }
            printf("\n");
            printf("Множество A: ");
                for(int i = 0; i < setA.size; i++)
                {
                    printf("%c ", setA.elements[i]);
                }
                printf("Множество B: ");
                for(int i = 0; i < setB.size; i++)
                {
                    printf("%c ", setB.elements[i]);
                }
            printf("\n");
            break;
        case 5:
            printf("Выход из программы\n");
            break;
        default:
            printf("Неверный номер операции\n");
            break;
        }
    }
    
    free(setA.elements);
    free(setB.elements);
    
    return 0;
}