#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vetor.h"

struct vetor
{
    void *elementos;      //vetor de numeros
    int qtd_elementos;    //quantidade de numeros
    type tipo;            //tipo de numeros
};

typedef double funcao(Vetor *v);
funcao *p_funcao;

Vetor *criar(int tam, int tipo){
    Vetor *vetor =(Vetor*)calloc(1,sizeof(Vetor)) ;

    if(tipo == 0){
        vetor->elementos = calloc(tam,sizeof(float));
    }

    if(tipo == 1){
        vetor->elementos = calloc(tam,sizeof(int));
    }

    if(tipo == 2){
        vetor->elementos = calloc(tam,sizeof(double));
    }

    vetor->qtd_elementos = tam;
    vetor->tipo = tipo;

    return vetor;
}

void preencher(Vetor *v){
    int i = 0, MAX = 1000;

    if(v->tipo == FLOAT){
        for(i = 0; i< v->qtd_elementos; i++){
            ((float*)v->elementos)[i] = (float)rand( )/RAND_MAX*MAX;
        }
    }

    if(v->tipo == INT){
        for(i = 0; i< v->qtd_elementos; i++){
            ((int*)v->elementos)[i] = (int)rand( )%MAX;
        }
    }

    if(v->tipo == DOUBLE){
        for(i = 0; i< v->qtd_elementos; i++){
            ((double*)v->elementos)[i] = (double)rand( )/RAND_MAX*MAX;
        }
    }    
}

void imprimir(Vetor *v){
    int i = 0;

    if(v->tipo == FLOAT){
        float *elementos_float = (float*)v->elementos;
        for(i = 0; i< v->qtd_elementos; i++){
            printf("%.3f ",elementos_float[i]);
        }
    }

    if(v->tipo == INT){
        int *elementos_int = (int*)v->elementos;
        for(i = 0; i< v->qtd_elementos; i++){
            printf("%d ",elementos_int[i]);
        }
    }
    
    if(v->tipo == DOUBLE){
        double *elementos_double = (double*)v->elementos;
        for(i = 0; i< v->qtd_elementos; i++){
            printf("%.3f ",elementos_double[i]);
        }
    }
}


void liberar(Vetor *v){
    free(v->elementos);
    free(v);
}

double media_int(Vetor *v){
    int i = 0,soma = 0;
    int *elementos_int = (int*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + elementos_int[i];
    }
    return soma/(v->qtd_elementos);
}

double media_float(Vetor *v){
    int i = 0;
    float soma = 0;
    float *elementos_float = (float*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + elementos_float[i];
    }
    return soma/(v->qtd_elementos);
}

double media_double(Vetor *v){
    int i = 0;
    double soma = 0;
    double *elementos_double = (double*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + elementos_double[i];
    }
    return soma/(v->qtd_elementos);
}

double variancia_int(Vetor *v){
    double media = media_int(v);
    int i = 0,soma = 0;
    int *elementos_int = (int*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + (elementos_int[i] - media)*(elementos_int[i] - media);
    }

    return soma/(v->qtd_elementos - 1);
}

double variancia_float(Vetor *v){
    double media = media_float(v);
    int i = 0;
    float soma = 0;
    float *elementos_float = (float*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + (elementos_float[i] - media)*(elementos_float[i] - media);
    }

    return soma/(v->qtd_elementos - 1);  
}

double variancia_double(Vetor *v){
    double media = media_double(v);
    int i = 0;
    double soma = 0;
    double *elementos_double = (double*)v->elementos;
    for(i = 0; i < v->qtd_elementos; i++){
        soma = soma + (elementos_double[i] - media)*(elementos_double[i] - media);
    }

    return soma/(v->qtd_elementos - 1);  
}

double desvioPadrao_int(Vetor *v){
    double desvio = variancia_int(v);
    return sqrt(desvio);
}

double desvioPadrao_float(Vetor *v){
    double desvio = variancia_float(v);
    return sqrt(desvio);
}

double desvioPadrao_double(Vetor *v){
    double desvio = variancia_double(v);
    return sqrt(desvio);
}

double operacao(Vetor *v, funcao *f){
    return (*f)(v);
 }

double calcular(Vetor *v, char c){
    if(c == 'm'){
        if(v->tipo == DOUBLE){
            p_funcao = media_double;
        }

        if(v->tipo == FLOAT){
             p_funcao = media_float;
        }

        if(v->tipo == INT){
             p_funcao = media_int;
        }
    }

    if(c == 'v'){
         if(v->tipo == DOUBLE){
            p_funcao = variancia_double;
        }

        if(v->tipo == FLOAT){
             p_funcao = variancia_float;
        }

        if(v->tipo == INT){
             p_funcao = variancia_int;
        }
    }

    if(c == 'd'){
         if(v->tipo == DOUBLE){
             p_funcao = desvioPadrao_double;
        }

        if(v->tipo == FLOAT){
            p_funcao = desvioPadrao_float;
        }

        if(v->tipo == INT){
            p_funcao = desvioPadrao_int;
        }
    }

    return operacao(v,p_funcao);
}