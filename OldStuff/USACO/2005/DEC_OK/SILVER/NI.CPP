/*
Alfonso Alfonso Peterssen
4 - 8 - 2007
USACO 2005 DEC Silver "Caballeros de Ni"
*/
#include <cstdio>
#include <cstdlib>

#define problem "d"
#define MAXF 1500

const int mov[4][2] =
  { {-1,0}, {0,-1}, {0,1}, {1,0} };

int F, C, i, j;
int front, rear;
int map[MAXF][MAXF], dist[MAXF][MAXF];
int qX[MAXF * MAXF], qY[MAXF * MAXF];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &C, &F );
  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ ) {
      scanf( "%d", &map[i][j] );
      if ( map[i][j] == 2 ) {
        qX[front] = i;
        qY[front] = j;
        front++;
      }
    }

  /* BFS */
  while ( front != rear ) {
    for ( i = 0; i < 4; i++ ) {

      int rx = qX[rear], x = rx + mov[i][0],
          ry = qY[rear], y = ry + mov[i][1];

      if ( ( x >= 0 && x < F ) && ( y >= 0 && y < C ) ) {

        if ( ( map[x][y] == 1 ) || ( map[x][y] == map[rx][ry] ) ||
             ( map[rx][ry] != 4 && map[x][y] == 3 ) ) continue;

        if ( map[x][y] == 3 ) {
          printf( "%d\n", dist[rx][ry] + 1 );
          exit( 0 );
        }

        if ( map[x][y] != 4 ) map[x][y] = map[rx][ry];

        dist[x][y] = dist[rx][ry] + 1;
        qX[front] = x; qY[front] = y;

        front++;
      }
    }
    rear++;
  }

  return 0;
}

/*
Problema 6: Caballeros de Ni [Carl Hultquist, Sudafrica, 2005]

Bessie est� en Camelot y se ha encontrado en una situaci�n inc�moda:
ella necesita pasar a trav�s del bosque que es vigilado por los
Caballeros de Ni. Para que ella pueda pasar con seguridad, los
Caballeros han demandado que ella les lleve una sola fresa. El tiempo
es esencial, y Bessie debe encontrar y llevarles una fresa tan pronto
como sea posible.

Bessie tiene un mapa del bosque, el cual est� particionado en un
arreglo cuadrado arreglado en la manera usual, con los ejes paralelos
a los ejes X y Y. El mapa tiene tama�o W x H unidades (1 <= W <= 1000;
1 <= H <= 1000).

El mapa muestra donde Bessie comienza su recorrido, el �nico cuadrado
en donde est�n los Caballeros de Ni, y la ubicaci�n de todas las
fresas en el territorio. Tambi�n muestra que �reas del mapa pueden ser
atravesadas (algunos bloques del arreglo son impasables debido a
pantanos, monta�as y conejos asesinos). Bessie no puede pasar a trav�s
del cuadrado de los Caballeros de Ni sin una fresa.

Para estar seguros que Bessie siga el mapa correctamente, Bessie puede
moverse �nicamente en cuatro direcciones: Norte, Este, Sur, U oeste
(esto es diagonalmente NO). Ella requiere un d�a para completar un
recorrido de un bloque del arreglo a un bloque vecino del arreglo.

Se garantiza que Bessie ser� capaz de conseguir una fresa y luego
llevarla a los Caballeros de Ni. Determine la manera m�s r�pida en que
ella pueda hacer eso.

NOMBRE DEL PROBLEMA: ni

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio W y H.

* L�neas 2..?: Estas l�neas describen el bosque, fila por fila. La
         primera l�nea describe la parte m�s al noroeste del bosque.
         La �ltima l�nea describe la parte m�s sudeste del bosque.
         Enteros sucesivos en la entrada describen columnas del bosque
         de oeste a este. Cada nueva fila de la descripci�n del bosque
         comienza en una nueva l�nea de entrada, y cada l�nea de la
         entrada contiene no m�s de 40 enteros separados por espacios.
         Si W <= 40, entonces cada l�nea de la entrada describe una
         fila completa del bosque. Si W > 40, entonces m�s de una
         l�nea es usada para describir una sola fila, 40 enteros en
         cada l�nea exceptuando potencialmente la �ltima. Ninguna
         l�nea de la entrada describir� elementos de m�s de una fila.

Los enteros que describen el bosque vienen de este conjunto:
0: Cuadrado a trav�s del cual Bessie puede desplazarse
1: Cuadrado impasable, a trav�s del Cual Bessie no puede desplazarse
2: Posici�n inicial de Bessie
3: Posici�n de los Caballeros de Ni
4: Posici�n de una fresa

ENTRADA EJEMPLO (archivo ni.in):

8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0

DETALLES DE LA ENTRADA:

Ancho=8, alto=4. Bessie comienza en la tercera fila, solo unos
cuadrados lejos de los Caballeros.


FORMATO DE LA SALIDA:

* L�nea 1: D, el m�nimo n�mero de d�as que le tomar� a Bessie llegar a
        una fresa y llev�rsela a los Caballeros de Ni.

SALIDA EJEMPLO (archivo ni.out):

11

DETALLES DE LA SALIDA:

Bessie puede moverse en este patr�n para llevar una frase a los
Caballeros: N, O, N, S, E, E, N, E, E, S, S. Ella consigue la fresa en
la esquina noroeste y luego rodea las barreras hacia el este y luego
al sur hacia los Caballeros.
*/
