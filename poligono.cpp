#include "poligono.h"
#include<cmath>
#include<iostream>

#define PI 3.14159265

using namespace std;
/**@brief Construtor default:
**@details Inicializa todos os 100 vértices do polígono com (0,0)
* e o número de vértices com 0.
**/
Poligono::Poligono(){
    nVertices = 0;
    for(int i=0; i<100; i++){
        vertices[i].setXY(0.0,0.0);
    }
}

/**@brief Sobrecarga do operador '+':
*@details Acrescenta vértice ao polígono se este possuir menos de 100 (tamanho máximo). Antes do acréscimo, porém
*  o método confere se o polígono já possui o ponto que se quer adicionar, uma vez que, um polígono válido, não possui
* vértices repetidos. Após o acrescimo do vértice, a variável número de vértice é atualizada.
* OBS.: Os vértices são adicionados no sentido anti-horário.
**/
void Poligono::operator+(Ponto _vertice){

    int tamAntigo = nVertices;

    if(tamAntigo == 100){
        cout << "[POL] Erro! Poligono com tamanho max\n";
        return;
    }
    else{
        for(int i=0;i<tamAntigo;i++){
            if(vertices[i].getX() == _vertice.getX() && vertices[i].getY() == _vertice.getY()){
                cout << "[POL] Erro! Poligono jah possui esse ponto\n";
                return;
            }
        }
        vertices[tamAntigo].setXY(_vertice.getX(),_vertice.getY());
        nVertices++;
    }
}

/**@brief Função de adicionar vertice:
*@details Faz a mesma coisa que a sobrecarga acima. Essa alternativa precisou ser criada para a implementação
* do construtor do retângulo.
**/
void Poligono::addVert(Ponto _vertice){
    int tamAntigo = nVertices;

    if(tamAntigo == 100){
        cout << "[POL] Erro! Poligono com tamanho max\n";
        return;
    }
    else{
        for(int i=0;i<tamAntigo;i++){
            if(vertices[i].getX() == _vertice.getX() && vertices[i].getY() == _vertice.getY()){
                cout << "[POL] Erro! Poligono jah possui esse ponto\n";
                return;
            }
        }
        vertices[tamAntigo].setXY(_vertice.getX(),_vertice.getY());
        nVertices++;
    }
}



/**@brief Funcao que retorna o numero de vertices
*/

int Poligono::numVertices(){

    return nVertices;

}

/**@brief Calcula a área do polígono usando as coordenadas de seus vértices:
*
* @details O algoritmo do cálculo da área funciona como se as coordenadas dos vértices, pegos no sentido anti-horário, tivessem sido organizados em uma matriz
* repetindo-se as primeiras coordenadas na última linha. Assim, o método multiplica e soma todas as diagonais principais e secundárias da suposta matriz e
* ,em seguida, subtrai a soma das diagonais principais pela soma das diagonais secundárias e divide-se o resultado por 2 (ou multiplica-se por 0.5).
* Por fim, o algoritmo retorna o valor absoluto da solução da operação anterior que é igual a área do polígono.
*
* @htmlonly
* <script type="text/javascript" async
* src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=TeX-MML-AM_CHTML">
* </script>
* <body>
Matriz contendo coordenadas dos vértices do polígono:
$$
 \begin{vmatrix}
x_{0} & y_{0} \\
x_{1} & y_{1} \\
x_{2} & y_{2}\\
 ... & ...\\
x_{n} & y_{n}\\
x_{0} & y_{0}
\end{vmatrix}
\\
\\
 $$
Cálculo da área:$$
Area = 0.5[(x_{0}*y_{1} + x_{1}*y_{2} + ... + x_{n}*y_{0}) - (y_{0}*x_{1} + y_{1}*x_{2} + ... + y_{n}*x_{0})]$$
</body>
* @endhtmlonly
* */

double Poligono::area(){
    double area;
    double diagPrinc=0;
    double diagSec=0;

    for(int i=0; i<(nVertices-1); i++){
        diagPrinc += (vertices[i].getX()*vertices[i+1].getY());
        diagSec += (vertices[i].getY()*vertices[i+1].getX());
    }
    diagPrinc += (vertices[nVertices-1].getX()*vertices[0].getY());
    diagSec += (vertices[nVertices-1].getY()*vertices[0].getX());

    area = 0.5*(diagPrinc-diagSec);

    return abs(area);
}

/**@brief Funcao para transladar os vértices do polígono:
 * @details
*/
void Poligono::translada(float a, float b){
    for(int i=0; i<nVertices; i++){
        vertices[i].translada(a,b);
    }
}

//EM TORNO DA ORIGEM. TRANSLADA PARA O P0 FICAR NA ORIGEM, ROTACIONA E TRANSLADA
void Poligono::rotaciona(float theta, Ponto p0){
    float angRad = theta * 180.0 / PI;
    float novoX,novoY;

    for(int i=0;i<nVertices;i++){
        vertices[i].translada(-p0.getX(),-p0.getY());

        novoX = vertices[i].getX()*cos(angRad) - vertices[i].getY()*sin(angRad);
        novoY = vertices[i].getX()*sin(angRad) + vertices[i].getY()*cos(angRad);

        vertices[i].setXY(novoX,novoY);

        vertices[i].translada(p0.getX(),p0.getY());
    }
}

void Poligono::imprime(){
    if(nVertices<3){
        cout<<"[POL] Erro! Poligono com numero de vertices invalido\n";
        return;
    }

    for(int i=0; i<nVertices; i++){
        vertices[i].imprime();
        if(i<nVertices){
            cout << " -> ";
        }
    }
    vertices[0].imprime();
    cout<<endl;
}


