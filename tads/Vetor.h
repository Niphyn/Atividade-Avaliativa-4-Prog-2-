#ifndef _VETOR_H_
#define _VETOR_H_

#include <stdio.h>
#include <stdlib.h>


typedef enum {
    FLOAT = 0,
    INT = 1,
    DOUBLE = 2,
}type;

/**
Tipo opaco que contem um ponteiro de void,
o tamanho do vetor e o tipo do vetor.
Faz parte da implementação do struct, a implementação das funções de acesso aos membros internos.
*/
typedef struct vetor Vetor;

/**
*Inicializa um vetor com tamanho tam do tipo tipo;
*/
/**
 * @brief Aloca um vetor  com TAM elementos. 
 * @param tam  quantidade de elementos
   @param tipo O tipo do vetor
 * @return Vetor com tam elementos alocados
   pós-condição: Sair do programa caso seja um tipo desconhecido
 */
Vetor *criar(int tam, int tipo);

/**
  @brief Preenche o vetor  'v' com elementos aleatórios
  A semente deve ser inicializada pelo programa cliente
  @param v  Vetor V 
  Pré-condição V já inicializado
 */
void preencher(Vetor *v);

/**
  @brief Imprime o vetor  'v' 
  @param v  Vetor V 
  Pré-condição V já inicializado
 */
void imprimir(Vetor *v);


/**
  @brief Retorna a média dos elementos em  'v' 
  
  @param v  Vetor V já inicializado
  @return A média dos elementos em V
 
 */
double media(Vetor *v);

/**
  @brief Retorna a variancia dos elementos em  'v' 
  
  @param v  Vetor V já inicializado
  @return A variancia dos elementos em V
 
 */
double variancia(Vetor *v);

/**
  @brief Retorna O desvio padrão dos elementos em  'v' 
  
  @param v  Vetor V já inicializado
  @return Desvio padrão dos elementos em V
 
 */
double desvioPadrao(Vetor *v);



/**
  @brief Retorna o calculo de acordo com a função passada pelo parametro char
  
  @param v  Vetor V já inicializado
  @return A  media (m) ou a variancia (v) ou o desvio padrão.
  Deve obrigatoriamente usar uma tabela de disperção.
 */
double calcular(Vetor *v, char c);




/**
  @brief Libera os elementos de V da memória
  @param v  Vetor V já inicializado
 
 */
void liberar(Vetor *v);


#endif
