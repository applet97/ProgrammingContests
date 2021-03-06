/*
Alfonso Alfonso Peterssen
3 - 8 - 2007
USACO 2005 DEC Bronze "Bolos bovinos"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 350

int N, i, j;
int dp[MAXN][MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    for ( j = 0; j <= i; j++ )
      fin >> dp[i][j];

  for ( i = N - 1; i >= 0; i-- )
    for ( j = 0; j <= i; j++ )
      dp[i][j] += max( dp[i + 1][j], dp[i + 1][j + 1] );

  fout << dp[0][0] << endl;

  return 0;
}

/*
Problema 14: Bolos bovinos [IOI, 1994]

Las vacas no usan las bolas usuales de bolos cuando van a jugar bolos. A
pesar de eso, cada una toma un n�mero (en el rango 1..99), y se alinean en
un tri�ngulo est�ndar de bolos como esto:

          7

        3   8

      8   1   0

    2   7   4   4

  4   5   2   6   5


Entonces las otras vacas recorren el tri�ngulo comenzando desde su parte
superior y se mueven "abajo" hacia una de las dos vacas adyacentes en
diagonal hasta que se llega a la fila "de abajo". Las vacas obtienen
como puntaje la suma de los n�meros de las vacas visitadas en el camino.
La vaca con el m�s alto puntaje gana esa l�nea.

Dado un tri�ngulo con N (1 <= N <= 350) filas, determine la suma m�s
grande que se pueda obtener.

NOMBRE DEL PROBLEMA: bowl

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, N

* L�neas 2..N+1: La l�nea i+1 contiene i enteros separados por espacios
        que representan la fila i del tri�ngulo.

ENTRADA EJEMPLO (archivo bowl.in):

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

FORMATO DE SALIDA:

* L�nea 1: La suma m�s grande que se puede obtener usando las reglas de
        recorrido.

SALIDA EJEMPLO (archivo bowl.out):

30

DETALLES DE LA SALIDA:

          7
         *
        3   8
       *
      8   1   0
       *
    2   7   4   4
       *
  4   5   2   6   5

La suma m�s grande se puede obtener recorriendo las vacas como se muestra
antes.
*/
