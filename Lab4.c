#include <stdio.h>
#include <math.h>

// Функция для определения элемента для добавления или удаления
int Q(int i) {
    int count = 0;
    while (i > 0) {
        if (i % 2 == 0) {
            count++;
            i /= 2;
        } else {
            break;
        }
    }
    return count + 1;
}

// Функция для генерации подмножеств
void generateSubsets(int n) {
    int i, p;
    int B[32] = {0}; // Массив B для хранения битовой шкалы
    
    // Инициализация массива B и его вывод на печать
    for (i = 0; i < n; i++) {
        printf("%d", B[i]);
    }
    printf("\n");
    int s = pow(2, n);
    // Цикл для генерации подмножеств
    for (i = 1; i < s; i++) {
        // Определение элемента для добавления или удаления
        p = Q(i);
        
        // Добавление или удаление элемента
        B[p-1] = 1 - B[p-1];
        
        // Вывод очередного подмножества
        for (int j = 0; j < n; j++) {
            printf("%d", B[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    printf("Введите мощность множества: ");
    scanf("%d", &n);
    
    // Генерация подмножеств
    generateSubsets(n);
    
    return 0;
}