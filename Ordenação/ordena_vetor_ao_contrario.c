// Problema 7.5 - PDS1
// Insertion_sort Online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int tamanho = 0;
    int aux = 0;

    scanf("%d", &tamanho);

    int numeros[tamanho];

    for (int i = tamanho - 1; i >= 0; i--)
    {
        scanf("%d", &numeros[i]);
        if (!(i == tamanho - 1))
        {
            if (numeros[i] < numeros[i + 1])
            {
                for (int j = i; (numeros[j] < numeros[j + 1]) && (j < tamanho - 1); j++)
                {
                    aux = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = aux;
                }
            }
        }
    }

    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("%d\n", numeros[tamanho - 1]);

    return 0;
}