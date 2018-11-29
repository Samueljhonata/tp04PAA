#include <time.h>
#include <string.h>
#include "casamentoCaracteres.h"

int main(int argc, char** argv) {
    int opcao = -1, carregadoSucesso = 0;
    char nomeArq[50];
    double Tempo;
    clock_t Ticks[2];//definindo variaveis para contagem de tempo
    TipoPadrao p;
    TipoTexto t;


    while (opcao != 0) {
        printf("* * * * * * * * * * * M E N U * * * * * * * * * * * \n");
        printf("* 1- Carregar arquivo                             * \n");
        printf("* 2- Mostrar Texto                                * \n");
        printf("* 3- Pesquisar Padrao                             * \n");
        printf("* 0- SAIR                                         * \n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        do {
            printf("   Escolha uma opcao:");
            fflush(stdout);
            scanf("%d", &opcao);
            fflush(stdout);
        } while (opcao < 0 || opcao > 3);

        switch (opcao) {
            case 1: //carregar arquivo
                printf("\n Nome do arquivo a ser carregado: ");
                fflush(stdout);
                scanf("%s", &nomeArq);
                fflush(stdout);
                if (carregaArquivo(nomeArq, &t)) {
                    printf("\n Arquivo carregado com sucesso!");
                    carregadoSucesso = 1;
                } else {
                    printf("\n Arquivo nao foi carregado!");
                    carregadoSucesso = 0;
                }
                printf("\n\n");
                break;

            case 2: //mostrar texto
                if (carregadoSucesso == 1) {
                    printf("\nTexto carregado: \n\"%s\"\n", t);

                } else {
                    printf("\n -- Primeiro carregue um arquivo");
                }
                break;

            case 3: //pesquisar padrao
                if (carregadoSucesso == 1) {
                    printf("\n Padrao a ser pesquisado: ");
                    fflush(stdout);
                    scanf("%s", &p);
                    fflush(stdout);

                    printf("\nForca Bruta:\n");
                    Ticks[0] = clock();
                    ForcaBruta(t, strlen(t), p, strlen(p));
                    Ticks[1] = clock();
                    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                    printf("Tempo gasto: %g ms.", Tempo);


                    printf("\nBMH:");
                    Ticks[0] = clock();
                    BMH(t, strlen(t), p, strlen(p));
                    Ticks[1] = clock();
                    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                    printf("Tempo gasto: %g ms.", Tempo);

                } else {
                    printf("\n -- Primeiro carregue um arquivo");
                }
                break;

            case 0:
                printf("\n\n");
                printf(" Programa encerrado!");
                return 0;
        }
        printf("\n");
    }

}

