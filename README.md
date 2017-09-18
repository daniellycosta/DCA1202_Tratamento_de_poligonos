# DCA1202_Tratamento_de_poligonos
Primeiro projeto da segunda unidade da disciplina de Programação Avançada (DCA1202)

Instruções: (disponível em: http://agostinhobritojr.github.io/cursos/progav/projetoscpp.html)

1. Projeto 1 - Tratamento de polígonos
Seu projeto deverá ser capaz de armazenar e realizar operações com polígonos formados por conjuntos de pontos em duas dimensões.

Deve ser previsto no projeto a criação de três classes:

Ponto

Poligono

Retangulo

1.1. Etapa 1 - Criação da classe Ponto
Crie uma classe denominada Point para representar pontos no espaço bidimensional. Na sua implementação, você deverá encapsular duas variáveis x e y do tipo float para guardar a posição do ponto. Apenas as funções da classe poderão ter acesso direto a essas variávies, de modo que os clientes da classe somente poderão modificá-las usando métodos específicos que você definir. Implemente, na sua classe, métodos que realizem as seguintes operações:

Função	Descrição
setX(float)
Define o valor da coordenada x do ponto.
setY(float)
Define o valor da coordenada y  do ponto.
setXY(float,float)
Define, em uma mesma função, os valores da coordenadas x e y do ponto.
float getX()
Recupera o valor da coordenada x do ponto.
float getY()
Recupera o valor da coordenada y do ponto.
add(Point p1)
Adiciona as coordenadas (x,y)(x,y) do ponto com as coordenadas de um ponto P1(x1,y1)P1(x1,y1) fornecido, armazenando o resultado (x+x1,y+y1)(x+x1,y+y1) nas coordenadas de um novo ponto, que deverá ser retornado para o cliente da classe.
sub(Point p1)
Subtrai as coordenadas (x,y)(x,y) do ponto com as coordenadas de um ponto P1(x1,y1)P1(x1,y1) fornecido, armazenando o resultado (x−x1,y−y1)(x-x1,y-y1) nas coordenadas de um novo ponto, que deverá ser retornado para o cliente da classe.
norma()
Calcula a distância do ponto para a origem do sistema de coordenadas.
translada(float a, float b)
Translada o ponto (x,y)(x,y) de (+a,+b)(+a,+b), de modo que, após a execução do método, as coordenadas do ponto serão (x+a,y+b)(x+a,y+b).
imprime()
Imprime o ponto na forma (xpos, ypos).
1.2. Etapa 2 - Criação da classe Poligono
Defina uma classe chamada Poligono para representar polígonos convexos. Assuma que o tamanho dos polígonos será limitado a 100 vértices. Utilize a classe Point que você definiu na etapa anterior para guardar informações com as posições dos NN vértices do polígono. Sua classe deverá prever as seguintes funcionalidades:

Inserir vértice no polígono. Assuma que os vértices deverão ser inseridos conforme a sequência (anti-horária) em que figuram ao redor do polígono. As arestas do polígono serão então compostas pelos segmentos (x0,y0)→(x1,y1)(x0,y0)→(x1,y1), (x1,y1)→(x2,y2)(x1,y1)→(x2,y2) etc., com exceção da última aresta, que será formada pelo segmento (xN−1,yN−1)→(x0,y0)(xN−1,yN−1)→(x0,y0).

Recuperar a quantidade de vértices que foram inseridos no polígono

Calcular a área do polígono. Procure na Internet a fundamentação matemática necessária para implementar essa funcionalidade.

Transladar o polígono para (+a,+b)(+a,+b) usando uma função translada(float a, float b).

Rotacionar o polígono de θθ graus no sentido anti-horário em torno de um ponto (x0,y0)(x0,y0) fornecido pelo usuário.

Imprimir o polígono armazenado da forma (x0,y0)→(x1,y1)→(x2,y2)→…​

1.3. Etapa 3 - Criação da classe Retangulo
Utilizando a implementação da classe Poligono desenvolvida na etapa anterior, crie uma subclasse Retangulo derivada da superclasse Poligono. O construtor da nova classe deverá ser da forma Retangulo(float x, float y, float largura, float altura), denotando a posição (x,y)(x,y) do retângulo no espaço (coordenadas do canto superior esquerdo) e suas dimensões - altura e largura. Realize com esta classe as seguintes tarefas:

Assegure-se de que o construtor da classe utiliza os métodos da superclasse para armazenar a estrutura interna do retângulo.

1.4. Etapa 4 - Teste das classes criadas
Crie um pequeno exemplo para testar sua implementação da classe Retangulo.

No exemplo, defina um novo retângulo na posição (x,y)=(0,0)(x,y)=(0,0), com altura e largura iguais a 3 e 4, respectivamente.

Imprima a estrutura poligonal gerada para o retângulo.

Calcule a sua área usando a função já implementada na classe Poligono e mostre o resultado.

Mude a posição do retângulo usando a função translada(float,float) para (x,y)=(−3,4)(x,y)=(-3,4) e recalcule a área do retângulo. Compare-a com a área calculada antes da transformação geométrica.

Rotacione o Retângulo de +30o+30o em relação ao seu centro de massa e recalcule a sua área. Compare-a com a área calculada antes da transformação geométrica.
