/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY 1000000


void intercala(long *v, int i, int k, int j);
void mergeSort(long *v, int i, int j);

int main() {
    long *entrada = calloc(MAX_ENTRY, sizeof(long));
    int tam = 0;

    while(scanf("%ld ", &(entrada[tam])) != EOF) tam++;

    mergeSort(entrada, 0, tam-1);

    for(int i = 0; i < tam-1; i++) printf("%ld ", entrada[i]);
    printf("%ld\n", entrada[tam-1]);
    free(entrada);
    return 0;
}


void intercala(long *v, int i, int m, int f) {
    //Vetor temporario
    long *aux = calloc(f-i+1, sizeof(long));
    //Variaveis de indice
    int j, k, t;

    j = i;
    k = m+1;
    //Insere os valores de [i,f] ordenados em aux[]
    for(t = 0; t < (f-i+1); t++)
    {
        int chave;
        if(j <= m && k <= f) {
            //No caso normal, inserimos o menor valor
            if(v[j] < v[k])
                chave = v[j++];
            else
                chave = v[k++];
        }
        else if(j <= m) {
            //Caso o trecho a esquerda tenha acabado
            chave = v[j++];
        }
        else {
            //Caso o trecho a direita tenha acabado
            chave = v[k++];
        }
        aux[t] = chave;
    }
    //Copia o trecho ordenado para o vetor base
    for(j = i; j <= f; j++)
        v[j] = aux[j - i];

    free(aux);
}

void mergeSort(long *v, int i, int j) {
    if(i >= j)
        return;
    int m = (i+j)/2;
    mergeSort(v, i, m);
    mergeSort(v, m+1, j);
    intercala(v, i, m, j);
}
