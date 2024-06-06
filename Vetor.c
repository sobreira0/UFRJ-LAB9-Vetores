#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dimensao;
    float *entradas;
} Vetor; 

float prodInterno(Vetor, Vetor);
Vetor intercalaVetor(Vetor, Vetor);
void printVetor(Vetor);
void sortVetorBubble(Vetor*);


int main(void) 
{
    int dimensao1, dimensao2;
    Vetor a, b;
    printf("Digite a dimensao do vetor 1: \n");
    scanf("%d", &dimensao1);
    a.dimensao = dimensao1;

    printf("Digite a dimensao do vetor 2: \n");
    scanf("%d", &dimensao2);
    b.dimensao = dimensao2;

    a.entradas = (float *) malloc(sizeof(float) * dimensao1);
    printf("Crie o vetor 1: \n");
    for (int i = 0; i < dimensao1; i++) 
    {
        scanf("%f", &a.entradas[i]);
    }

    b.entradas = (float *) malloc(sizeof(float) * dimensao2);
    printf("Crie o vetor 2: \n");
    for (int i = 0; i < dimensao2; i++) 
    {
        scanf("%f", &b.entradas[i]);
    }

    printf("%f", prodInterno(a, b));

    sortVetorBubble(&a);

    Vetor c = intercalaVetor(a, b);
    
    printVetor(a);
    printVetor(c);

    free(a.entradas);
    free(b.entradas);
    free(c.entradas);

    return 0;
}

// Realiza o produto interno de dois vetores retornando um escalar
float prodInterno(Vetor a, Vetor b)
{
    if (a.dimensao != b.dimensao) 
    {
        puts("Esperado vetores de dimensoes iguais");
        return -1;
    }

    float result = 0;

    for (int i = 0; i < a.dimensao; i++)
    {
        result += a.entradas[i] * b.entradas[i];
    }

    return result;
}

// Intercala dois vetores, presumindo que os dois já estejam ordenados
// retornando um vetor com suas entradas ordenadas em ordem crescene 
Vetor intercalaVetor(Vetor a, Vetor b)
{
    Vetor c;
    c.dimensao = a.dimensao + b.dimensao;
    c.entradas = (float *) malloc(sizeof(float) * (a.dimensao + b.dimensao));

    int i = 0;
    int j = 0;

    for(int k = 0; k < c.dimensao; k++)
    {
        if (i > a.dimensao && j < b.dimensao)
        {
            c.entradas[k] = b.entradas[j];
            break;
        } else if (j > b.dimensao && i < a.dimensao) {
            c.entradas[k] = a.entradas[i];
            break;
        }
        if (a.entradas[i] <= b.entradas[j])
        {
            c.entradas[k] = a.entradas[i];
            i++;
        } else {
            c.entradas[k] = b.entradas[j];
            j++;
        }
    }
    return c;
}

// Ordena as entradas do vetor usando o algorítmo de BubbleSort 
void sortVetorBubble(Vetor *a)
{
    for(int i = 0; i < a->dimensao - 1; i++)
        for(int j = 0; j < a->dimensao - i - 1; j++)
            if(a->entradas[j] > a->entradas[j+1]) 
            {
                int k = a->entradas[j];
                a->entradas[j] = a->entradas[j+1];
                a->entradas[j+1] = k;
            }
}

// Feito para facilitar o print das entradas do vetor
void printVetor(Vetor a)
{
    for(int i = 0; i < a.dimensao; i++)
        printf("%.2f ", a.entradas[i]);
    printf("\n");
}
