#include <string.h>

#include "casamentoCaracteres.h"

//https://www.cprogressivo.net/2013/11/Como-ler-arquivos-em-C-As-funcoes-fgetc-fscanf-fgets.html
int carregaArquivo(char *nomeArq, char* texto) {
    FILE *arq;
    char temp[MAXTAMTEXTO];
    
    arq = fopen(nomeArq, "r");

    if (arq == NULL) { //erro ao carregar arquivo
        printf("ERRO AO LER ARQUIVO");
        return 0;
    } else {
        strcpy(texto,"");
        while( (fgets(temp, sizeof(temp), arq))!=NULL ) { //enquanto o arquivo não termina
            strcat(texto,temp);
        }
        //printf("%s",texto);
    }

    fclose(arq);
    return 1;
}


long ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m) {
    long i, j, k, tempo = 0;
    printf(" Casamento na(s) posicao(oes): ");
    for (i = 1; i <= (n - m + 1); i++) {
        tempo++;
        k = i;
        j = 1;
        while (T[k - 1] == P[ j - 1] && j <= m) {
            tempo++;
            j++;
            k++;
        }
        if (j > m) {
            printf("%3ld, ", i);
        }
    }
    printf("\n Tempo: %ld", tempo);
    return tempo;
}

long BMH(TipoTexto T, long n, TipoPadrao P, long m) {
    long i, j, k, d[MAXCHAR + 1], tempo = 0;
    for (j = 0; j <= MAXCHAR; j++) d[ j ] = m;
    for (j = 1; j < m; j++) d[P[ j - 1]] = m - j;
    i = m;
    printf(" Casamento na(s) posicao(oes): ");
    while (i <= n) /*--Pesquisa--*/ {
        tempo++;
        k = i;
        j = m;
        while (T[k - 1] == P[ j - 1] && j > 0) {
            tempo++;
            k--;
            j--;
        }
        if (j == 0)
            printf("%3ld, ", k + 1);
        i += d[T[i - 1]];
    }
    printf("\n Tempo: %ld", tempo);
    return tempo;
}