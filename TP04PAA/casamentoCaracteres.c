#include <string.h>
#include "casamentoCaracteres.h"

//https://www.cprogressivo.net/2013/11/Como-ler-arquivos-em-C-As-funcoes-fgetc-fscanf-fgets.html

int carregaArquivo(char *nomeArq, char* texto) {
    FILE *arq;
    char temp;
    int i = 0;

    arq = fopen(nomeArq, "r");

    if (arq == NULL) { //erro ao carregar arquivo
        printf("ERRO AO LER ARQUIVO");
        return 0;
    } else {
        rewind(arq);
        strcpy(texto, "");
        while ((temp = fgetc(arq)) != EOF) { //enquanto o arquivo nao termina
            /*if (temp == '\n') {
                temp = ' ';
            }*/
            texto[i] = toupper(temp);
            i++;
        }
        texto[i] = '\0';
    }

    fclose(arq);
    return 1;
}

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m, int mostrarPosicao) {
    long i, j, k, qtd = 0;

    if (mostrarPosicao == 1) {
        printf("\n Casamento na(s) posicao(oes): ");
    }
    for (i = 1; i <= (n - m + 1); i++) {
        k = i;
        j = 1;
        while (T[k - 1] == P[ j - 1] && j <= m) {
            j++;
            k++;
        }
        if (j > m) {
            if (mostrarPosicao == 1) {
                printf("%3ld, ", k + 1);
            }
            qtd++;
        }
    }
    printf("\n\n Quantidade encontrada: %ld", qtd);
}

void BMH(TipoTexto T, long n, TipoPadrao P, long m, int mostrarPosicao) {
    long i, j, k, d[MAXCHAR + 1], qtd = 0;
    for (j = 0; j <= MAXCHAR; j++) {
        d[ j ] = m;
    }
    for (j = 1; j < m; j++) {
        d[P[ j - 1]] = m - j;
    }
    i = m;

    /*--Pesquisa--*/
    if (mostrarPosicao == 1) {
        printf("\n Casamento na(s) posicao(oes): ");
    }
    while (i <= n) {
        k = i;
        j = m;
        while (T[k - 1] == P[ j - 1] && j > 0) {
            k--;
            j--;
        }
        if (j == 0) {
            qtd++;
            if (mostrarPosicao == 1) {
                printf("%3ld, ", k + 1);
            }
        }
        i += d[T[i - 1]];
    }
    printf("\n\n Quantidade encontrada: %ld", qtd);
}
