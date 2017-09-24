#include"ponto.h"
#include<math.h>
#include<iostream>

using namespace std;

/**@brief Construtor default
* @details Inicializa o ponto com (0,0).
*/
Ponto::Ponto(){
   x = 0;
   y = 0;
}

/**@brief Sobrecarga do construtor
* @details Inicializa o ponto com valor de x e y fornecido pelo usuário.
*/
Ponto::Ponto(float _x,float _y){
   x = _x;
   y = _y;
}

/**@brief Função para setar x
* @details Atribui ao x do ponto declarado, o valor fornecido pelo usuário.
*/
void Ponto::setX(float _x){
    x = _x;
}

/**@brief Função para setar y
* @details Atribui ao y do ponto declarado, o valor fornecido pelo usuário
*/
void Ponto::setY(float _y){
    y = _y;
}

/**@brief Função para setar x e y
*@details Atribui, simultaneamente, as coordenadas x e y do ponto declarado, com os valores fornecido pelo usuário.
*/
void Ponto::setXY(float _x, float _y){
    x = _x;
    y = _y;
}

/**@brief Função para acessar x:
* @details Retorna a coordenada x do ponto.
*/
float Ponto::getX(){
    return x;
}

/**@brief Função para acessar y:
* @details Retorna a coordenada y do ponto.
*/
float Ponto::getY(){
    return y;
}

/**@brief Sobrecarga do '+':
* @details Soma as coordenadas dos dois pontos se encontram ao lado do operador sobrecarregado
*/
Ponto Ponto::operator +(Ponto p1){
    Ponto ret;
    ret.x = x + p1.x;
    ret.y = y + p1.y;
    return ret;
}

/**@brief Sobrecarga do '-':
* @details Subtrai as coordenadas dos dois pontos que se encontram ao lado do operador sobrecarregado
*/
Ponto Ponto::operator -(Ponto p1){
    Ponto ret;
    ret.x = x - p1.x;
    ret.y = y - p1.y;
    return ret;
}

/**@brief Funcao Norma:
* @details Calcula a norma do ponto utilizando a função:
*
* @htmlonly
* <script type="text/javascript" async
* src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=TeX-MML-AM_CHTML">
* </script>
* <body>
*  $$Norma = \sqrt{x^2+y^2}$$
* </body>
* @endhtmlonly
*/
double Ponto::norma(){
    return (sqrt((x*x) + (y*y)));
}

/**@brief Funcao para transladar ponto:
* @details Translada as coordenadas dos pontos, somando os parâmetros 'a' e 'b' fornecidos pelo usuário
* aos valores das coordenadas já atribuidos ao ponto.
*/
void Ponto::translada(float a, float b){
    x = x + a;
    y = y + b;
}

/**@brief Funcao para imprimir ponto:
* @details Imprime o ponto na tela no formato
*
* @htmlonly
* <script type="text/javascript" async
* src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=TeX-MML-AM_CHTML">
* </script>
* <body>
*  $$(x, y)$$
* </body>
* @endhtmlonly
*/
void Ponto::imprime(){
    cout << "(" << x << ", " << y << ")";
}
