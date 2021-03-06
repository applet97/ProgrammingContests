/*
Alfonso Alfonso Peterssen
3 - 8 - 2007
USACO 2005 DEC Bronze "Alineaci�n de los Planetas"
*/
#include <cstdio>

#define problem "d"
#define MAXN 770
#define MAXSOL 5000

int N, i, j, k, sol;
int X[MAXN], Y[MAXN];
int p1[MAXSOL], p2[MAXSOL], p3[MAXSOL];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d %d", &X[i], &Y[i] );

  for ( i = 0; i < N; i++ )
    for ( j = i + 1; j < N; j++ )
      for ( k = j + 1; k < N; k++ )
        if ( ( X[j] - X[i] ) * ( Y[k] - Y[i] ) ==
             ( X[k] - X[i] ) * ( Y[j] - Y[i] ) ) {
          p1[sol] = i;
          p2[sol] = j;
          p3[sol] = k;
          sol++;
        }

  printf( "%d\n", sol );
  for ( i = 0; i < sol; i++ )
    printf( "%d %d %d\n", p1[i] + 1, p2[i] + 1, p3[i] + 1 );

  return 0;
}

/*
Problema 12: Alineaci�n de los Planetas [Tradicional, 2005]

En realidad, este problema es acerca de alinear N (1 <= N <= 770) vacas
numeradas 1..N las cuales est�n pasteando en su campo el cual tiene cerca
de 15,000x15,000 unidades. Todas sus posiciones de pasteo caen en
coordenadas enteras en esquema tradicional x, y (las coordenadas est�n
en el rango 0..15,000).

Bessie mira el campo y se da cuenta que est� exactamente alineada con
Sara y Julie. Ella se pone a pensar en cu�ntos grupos de tres vacas
alineadas existen dentro del campo.

Dadas las ubicaciones de todas las vacas (ning�n par de vacas ocupan
la misma posici�n), encuentre todos los conjuntos de tres vacas que son
exactamente colineales. Lleve registro de los conjuntos, ordenando las
vacas en cada conjunto por su n�mero de identificaci�n, el m�s bajo
primero. Luego ordene los conjuntos por los tres n�meros de identificaci�n
(el m�s bajo primero), rompiendo empates con los n�meros de identificaci�n
segundo y tercero.

NOMBRE DEL PROBLEMA: align

FORMATO DE ENTRADA:

* L�neas 1: Un solo entero, N.

* L�neas 2..N+1: La l�nea i+1 describe la posici�n de la vaca i con dos
        enteros separados por espacio que son las coordenadas x y y.


ENTRADA EJEMPLO (archivo align.in):

8
0 0
0 4
1 2
2 4
4 3
4 5
5 1
6 5

DETALLES DE LA ENTRADA

Ocho vacas pasteando en un arreglo cuya esquina inferior izquierda se ve como esto:

. . . . * . *
* . * . . . .
. . . . * . .
. * . . . . .
. . . . . * .
* . . . . . .

FORMATO DE SALIDA:

* L�nea 1: Un solo entero que es el n�mero de conjuntos de tres vacas que son
        exactamente colineales. Un conjunto de cuatro vacas colineales podr�a,
        por supuesto, resultar en cuatro conjuntos de tres vacas colineales.

* L�neas 2..?: Cada l�nea contiene tres enteros separados por espacio que
        son los n�meros de identificaci�n de tres vacas colineales. Las
        l�neas deben estar ordenadas como se ha especificado antes. Esta
        secci�n es vac�a si no existen conjuntos colineales.

SALIDA EJEMPLO (archivo align.out):

1
1 3 4

DETALLES DE LA SALIDA:

Los d�gitos marcan los identificadores de vacas colineales:

. . . . * . *
* . 4 . . . .
. . . . * . .
. 3 . . . . .
. . . . . * .
1 . . . . . .
*/
