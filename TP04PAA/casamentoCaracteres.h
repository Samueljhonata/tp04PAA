#ifndef CASAMENTOCARACTERES_H
#define CASAMENTOCARACTERES_H

#include <stdio.h>
#include <stdlib.h>

#define MAXTAMTEXTO 1000
#define MAXTAMPADRAO 10
#define MAXCHAR 256
#define NUMMAXERROS 10
typedef char TipoTexto[MAXTAMTEXTO] ;
typedef char TipoPadrao[MAXTAMPADRAO] ;

int carregaArquivo(char *nomeArq, char* texto);
void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m);
void BMH(TipoTexto T, long n, TipoPadrao P, long m);

#endif /* CASAMENTOCARACTERES_H */


