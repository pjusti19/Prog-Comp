#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void calcula_soma_dos_cubos(unsigned long long *soma_dos_cubos, unsigned long long limite)
{
    int pos = 0;
    for (unsigned long long i = 1; i <= limite; i++)
    {
        unsigned long long cubo_de_i = (i * i * i);
        for (unsigned long long j = i; j <= limite; j++)
        {
            soma_dos_cubos[pos] = cubo_de_i + (j * j * j);
            pos++;
        }
    }
}

int soma_eh_igual(const void *a, const void *b)
{
    return (*(unsigned long long *)a) - (*(unsigned long long *)b);
}

int main()
{

    unsigned long long limite = 0;

    scanf("%llu", &limite);

    int tamanho_vetor = limite * (limite + 1) / 2; // P. A até n (n = limite)

    unsigned long long *soma_dos_cubos = malloc(tamanho_vetor * sizeof(unsigned long long));

    if (soma_dos_cubos == NULL)
    {
        printf("Erro na alocação dinâmica\n");
        return 1;
    }

    calcula_soma_dos_cubos(soma_dos_cubos, limite);

    qsort(soma_dos_cubos, tamanho_vetor, sizeof(unsigned long long), soma_eh_igual);

    // Saída
    bool achou_duplicatas = false;

    printf("Considerando %llu como o limite de inteiros para calculo:\n", limite);

    for (int i = 1; i < tamanho_vetor; i++)
    {
        if (soma_dos_cubos[i] == soma_dos_cubos[i - 1])
        {
            printf("%llu pode ser escrito com a soma do cubo de 2 numeros diferentes\n", soma_dos_cubos[i]);
            achou_duplicatas = true;
            while (i < tamanho_vetor && soma_dos_cubos[i] == soma_dos_cubos[i - 1]) // Pula as somas iguais
                i++;
        }
    }

    if (achou_duplicatas == false)
        printf("Nenhum numero pode ser escrito em funcao da soma do cubos de dois inteiros diferentes\n");

    free(soma_dos_cubos);

    return 0;
}