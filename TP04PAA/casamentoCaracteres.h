#ifndef CASAMENTOCARACTERES_H
#define CASAMENTOCARACTERES_H

#include <stdio.h>
#include <stdlib.h>

#define MAXTAMTEXTO 1000000
#define MAXTAMPADRAO 100
#define MAXCHAR 256

typedef char TipoTexto[MAXTAMTEXTO] ;
typedef char TipoPadrao[MAXTAMPADRAO] ;

int carregaArquivo(char *nomeArq, char* texto);
void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m, int mostrarPosicao);
void BMH(TipoTexto T, long n, TipoPadrao P, long m, int mostrarPosicao);

#endif /* CASAMENTOCARACTERES_H */


