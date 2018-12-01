#include <time.h>
#include <string.h>
#include "casamentoCaracteres.h"


int main(int argc, char** argv) {
    int i, opcao = -1, carregadoSucesso = 0, modo = 1, mostrarPosicao = 0;
    char nomeArq[50];
    double Tempo;
    clock_t Ticks[2];//definindo variaveis para contagem de tempo
    char p[MAXTAMPADRAO];
    TipoTexto texto;
  
    while (opcao != 0) {
        printf("* * * * * * * * * * * M E N U * * * * * * * * * * * \n");
        printf("* 1- Carregar arquivo                             * \n");
        printf("* 2- Mostrar Texto                                * \n");
        printf("* 3- Pesquisar Padrao                             * \n");
        printf("* 4- Modo de Apresentacao                         * \n");
        printf("* 0- SAIR                                         * \n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        do {
            printf("   Escolha uma opcao:");
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 4);

        switch (opcao) {
            case 1: //carregar arquivo
                printf("\n Nome do arquivo a ser carregado: ");
                scanf("%s", &nomeArq);
                if (carregaArquivo(nomeArq, &texto)) {
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
                    printf("\nTexto carregado: \n%s\n", texto);

                } else {
                    printf("\n -- Primeiro carregue um arquivo");
                }
                break;

            case 3: //pesquisar padrao
                if (carregadoSucesso == 1) {
                    printf("\n Padrao a ser pesquisado: ");
                    scanf(" %[^\n]s",p);
                    
                    //transforma o padrão em maiúscula
//                    i = 0;
                    for (i=0; i < strlen(p); i++) {
                        p[i] = toupper(p[i]);
                    }


                    
                    printf(" Mostrar Posicoes encontradas? (0-Nao | 1-Sim) ");
                    scanf("%d", &mostrarPosicao);
                    
                    if (modo == 1) {
                        printf("\n\nModo NORMAL ativado!");
                    }else{
                        printf("\nModo DEBUG ativado!");
                    }

                    
                    printf("\n Tamanho do texto: %d",strlen(texto));
                    printf("\n Tamanho do padrao: %d",strlen(p));
                    
                    printf("\n\n*Forca Bruta:");
                    Ticks[0] = clock();
                    ForcaBruta(texto, strlen(texto), p, strlen(p),mostrarPosicao);
                    Ticks[1] = clock();
                    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;


                    if (modo == 2) {
                        printf("\n  Tempo gasto: %g ms.", Tempo);
                    }

                    printf("\n\n*BMH:");
                    Ticks[0] = clock();
                    BMH(texto, strlen(texto), p, strlen(p),mostrarPosicao);
                    Ticks[1] = clock();
                    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                    
                    if (modo == 2) {
                        printf("\n  Tempo gasto: %g ms.", Tempo);
                    }
                    

                } else {
                    printf("\n -- Primeiro carregue um arquivo");
                }
                break;

            case 4:
                printf(" Modo (1-Normal | 2-Debug):");
                scanf("%d", &modo);
                break;
                
            case 0:
                printf("\n\n");
                printf(" Programa encerrado!");
                return 0;
        }
        printf("\n");
    }

}

