/*
koder -> A2P
26 - 5 - 1007
PSN 2007 #69 "Rangos de Ra�l"
*/
#include <cstdio>
using namespace std;

#define problem "d"
#define MAXN 1000
const oo = (1 << 29);

int A, B, N, i, j;
int X[MAXN], Y[MAXN],
    C[MAXN], last[MAXN];

  int memo(int i) {
    if ( C[i] != oo ) return C[i];
    int j, t;
    for ( j = 0; j < N; j++ )
      if ( Y[j] == X[i] - 1 ) {
        t = memo(j) + 1;
        if ( t < C[i] ) {
          C[i] = t;
          last[i] = j;
        }
      }
    if ( C[i] == oo ) C[i] = oo + 1;
    return C[i];
  }

  void print(int i) {
    if ( i == -1 ) return;
    print( last[i] );
    printf( "%d %d\n", X[i], Y[i]);
  }

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &A, &B );
  scanf( "%d", &N );

  for ( i = 0; i < N; i++ ) {
    scanf( "%d %d\n", &X[i], &Y[i]);
    C[i] = (X[i] <= A && Y[i] >= A) ? 1 : oo;
    last[i] = -1;
  }

  for ( i = 0; i < N; i++ ) memo( i );

  for ( i = 0, j = -1; i < N; i++ )
    if (Y[i] >= B && (j == -1 || C[i] < C[j]))
      j = i;

  if ( j == -1 || C[j] >= oo ) printf( "NO\n" );
  else {
    printf( "YES\n" );
    printf( "%d\n", C[j] );
    print(j);
  }

  return 0;
}

/*
69� Rangos de Ra�l.                                       Croacia 2007
----------------------------------------------------------------------

 Hace   mucho tiempo,   un muchacho   llamado Ra�l,   hab�a hecho   un
 programa    de computaci�n que consist�a en cubrir   una secuencia de
 objetos etiquetados  con un valor entero. El programa era considerado
 muy  eficiente y  de multiprop�sito.  Este programa  estaba dise�ado
 para que fuera usado  tanto por un usuario  como por otro programa.

 Un  buen d�a,  inesperadamente el   programa fue  contaminado por  un
 virus   llamado   Carvajal.    Despu�s    de    tanto    tiempo    de
 investigaci�n  pudimos  encontrar la informaci�n detallada de que era
 lo  que hacia  el virus.  El virus  le asignaba   a la  soluci�n del
 programa una informaci�n basura.

 Definiciones:

 range(x,y):     es     un    conjunto     cerrado     de    elementos
 enteros,    donde contienen  a todos  los enteros  entre "x"  y "y",
 incluy�ndolos a ambos.

 C:    es    un    conjunto   de    elementos    range(x',y')    C   =
 range(x1,y1)   U range(x2,y2)   U...U  range(xn,yn),   tal  que   los
 intervalos   [Xi,   yi]    sean  intervalos   disjuntos  |C|:   es la
 cardinalidad  de   C,  que   es la   cantidad   de  elementos  que el
 conjunto C contiene.

 C-Cubrimiento:  es  un   conjunto "C"  donde   se  cumple que    para
 todo  "a"  que pertenezca   a "range(x,y)   de la    entrada" implica
 que "a" pertenezca  al conjunto "C".

 Nosotros nos dimos cuenta  de la magnitud del  problema causado y les
 pedimos a  ustedes que hagan un programa  que dado un range(x,y)  que
 queremos   cubrir y  una  lista   de "range(x,y)"   que el   programa
 hecho   por  Raul   da   como   salida,  encontrar  un   conjunto  "C
 -Cubrimiento" tal que su cardinalidad sea m�nima.

 Tareas

 Tarea 1:  Escribir "Yes" or "No", si  podemos encontrar un  conjunto
 "C -Cubrimiento".

 Tarea 2: Escribir la cardinalidad de dicho conjunto (|C-Cubrimiento|)
 tal  que sea m�nima.

 Tarea 3: Escribir todos los  elementos de dicho conjunto.

 Entrada

 El fichero de entrada RANGE.IN contiene:
 L�nea 1: Contiene  un rango(x,y), 0<=x<=y<=10^9.
 L�nea 2: Contiene  un entero N, 0<N<=1000.
 Siguientes N L�neas: Dos enteros a,b, 0<=a,b<= 10^9.

 Salida

 El fichero de salida RANGE.OUT contiene:

 L�nea 1:  Contiene una  palabra, "YES"  o "NO"  en dependencia  a  la
 soluci�n. En caso de ser "YES".
 L�nea  2: Debe  escribirse  un  valor  S,  que  es  la  soluci�n  al
 problema.
 Pr�ximas S l�neas:   Deben  aparecen  los  rangos que dan  soluci�n a
 ese valor S, ordenados crecientemente.

 Ejemplo de Entrada y Salida

 +-----------+  +------------+
 �  RANGE.IN �  �  RANGE.OUT �
 +-----------�  +------------�
 � 2 10      �  � YES 	     �
 � 6         �  � 3   	     �
 � 2 2       �  � 2 2	       �
 � 2 5       �  � 3 8	       �
 � 3 8       �  � 9 10       �
 � 6 8       �  +------------+
 � 8 9       �
 � 9 10      �
 +-----------+
*/
