/*
Alfonso Alfonso Peterssen
1 - 9 - 2007
USACO 2006 NOV Gold "Reparaci�n de Cerca"
*/
#include <fstream>
#include <set>
using namespace std;

#define problem "d"

typedef long long int64;

int N, i, j;
int64 sol;

multiset< int64 > heap;
multiset< int64 >::iterator it;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) {
    fin >> j;
    heap.insert( j );
  }

  for ( i = 0; i < N - 1; i++ ) {

    int64 sum = 0;
    it = heap.begin(); sum += *it; heap.erase( it );
    it = heap.begin(); sum += *it; heap.erase( it );

    heap.insert( sum );
    sol += sum;
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 1: Reparaci�n de Cerca [Richard Ho, 2006]

El Granjero Juan (GJ) quiere reparar una peque�a porci�n del cerco
alrededor de su campo de pasteo. El mide la cerca y encuentra que
necesita N (1 <= N <= 20,000) tablones de madera, cada uno teniendo
alguna longitud entera de Li (1 <= Li <= 50,000) unidades. El entonces
compr� un solo tablero con la longitud suficientemente grande como
para partirlo en N tablones (esto es, cuya longitud es la suma de las
longitudes Li). GJ est� ignorando el �desperdicio�, la longitud extra
p�rdida en aserr�n cuando se hace un corte; usted tambi�n debe
ignorarlo.

GJ se da cuenta tristemente que �l no posee una sierra con la cual
cortar la madera, por lo tanto �l va a la Granja del Granjero Don con
su tablero grande y le pide cort�smente si �l le puede prestar una
sierra.

El Granjero Don, un capitalista cerrado, no le presta su sierra a GJ.
En lugar de esto se ofrece a cobrarle al Granjero Juan por cada una de
los N-1 cortes en el tablero. El costo de cortar una pieza de madera
es exactamente igual a su longitud. Cortar una plancha de longitud 21
cuesta 21 centavos.

El Granjero Don le permite entonces al Granjero Juan decidir el orden
y las posiciones donde cortar la plancha. Ayude al Granjero Juan a
determinar la m�nima cantidad de dinero que puede gastar en crear los
N tablones. GJ sabe que �l puede cortar el tablero en varios ordenes
diferentes lo cual resultar� en diferentes costos desde que los
tableros intermedios son de longitudes diferentes.

NOMBRE DEL PROBLEMA: plank

FORMATO DE ENTRADA:

* L�nea 1: Un entero N, el n�mero de tablones.

* L�neas 2..N+1: Cada l�nea contiene un solo entero describiendo la
     longitud de un tabl�n necesitado.

ENTRADA EJEMPLO (archivo plank.in):

3
8
5
8

DETALLES DE LA ENTRADA:

El quiere cortar un tablero de longitud 21 en piezas de longitudes 8,
5, y 8.

FORMATO DE LA SALIDA:

* L�nea 1: Un entero: La m�nima cantidad de dinero que �l debe gastar
     para hacer los N-1 cortes.

SALIDA EJEMPLO (archivo plank.out):

34

DETALLES DE LA SALIDA:

El tablero original mide 8+5+8=21. El primer corte costar� 21, y
deber�a ser usado para cortar el tablero en piezas midiendo 13 y 8. El
segundo corte costar� 13, y deber�a ser usado para cortar el 13 en 8 y
5. Esto costar�a 21+13=34. Si en lugar de esto el 21 fuera cortado en
16 y 5, el segundo corte costar�a 16 para un total de 37 (lo cual es
m�s que 34).
*/
