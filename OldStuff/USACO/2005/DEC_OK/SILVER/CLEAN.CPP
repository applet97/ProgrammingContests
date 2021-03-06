/*
Alfonso Alfonso Peterssen
6 - 8 - 2007
USACO 2005 DEC Silver "Turnos de Limpieza"
*/
#include <fstream>
#include <set>
using namespace std;

#define problem "d"
#define MAXN 25000
#define oo 1000000000

int N, start, end, i, j, k;
int best, sol;
int cost[MAXN];
multiset< int > heap;

struct event {

  int time, id;
  bool flag;

  event( int t = 0, int i = 0, bool f = false )
  : time( t ), id( i ), flag( f ) {}

  bool operator < ( const event &x ) const {
    if ( time != x.time ) return time < x.time;
    return flag;
  }

} ls[ 2 * MAXN ];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> start >> end;
  end++;

  for ( i = 0; i < N; i++ ) {
    fin >> j >> k >> cost[i];
    ls[i] = event( j, i, true );
    ls[N + i] = event( k + 1, i, false );
  }

  sort( ls, ls + 2 * N );

  sol = best = oo;
  for ( i = 0; i < 2 * N; i++ ) {

    if ( ls[i].time == start ) best = 0;
    else if ( !heap.empty() )  best = *heap.begin();
    else break;

    if ( ls[i].flag )
      heap.insert( cost[ ls[i].id ] += best );
    else {
      if ( ls[i].time == end )
        sol <?= best;
      heap.erase( heap.find( cost[ ls[i].id ] ) );
    }
  }

  if ( sol == oo )
       fout << -1 << endl;
  else fout << sol << endl;

  return 0;
}

/*
Problema 7: Turnos de Limpieza [Entrenadores, 2004]

Las vacas del granjero Juan, consentidas desde reci�n nacidas, han
llegado a nuevas alturas de meticulosidad. Ellas ahora requieren que
su establo est� inmaculado. El Granjero Juan, el granjero m�s
consentidor, no tiene otra alternativa m�s que contratar algunas de
las vacas para limpiar el establo.

El Granjero Juan tiene N (1 <= N <= 10,000) vacas que desean hacer
algo de limpieza. Debido a que la basura cae continuamente, las vacas
requieren que la granja sea continuamente limpiada durante todo el d�a
laborable, el cu�l corre desde el segundo n�mero M al segundo n�mero E
durante el d�a (0 <= M <= E <= 86,399). Note que el n�mero total de
segundos durante el cual la limpieza tiene lugar es M-E+1. Durante
cualquier segundo dado en M..E, al menos una vaca debe estar
limpiando.

Cada vaca ha enviado una solicitud de trabajo indicando su deseo de
trabajar cierto intervalo T1..T2 (donde M <= T1 <= T2 <= E) por cierto
salario S (donde 0 <= S <= 500,000). Note que una vaca que indic� el
intervalo 10..20 trabajar�a 11 segundos, no 10. El Granjero Juan debe
o aceptar o rechazar cada solicitud individual; NO puede pedirle a una
vaca que trabaje solo una fracci�n del tiempo que ella indic� y
recibir la fracci�n correspondiente de salario.

Encuentre un horario en el cual cada segundo del d�a de trabajo est�
cubierto por al menos una vaca y el cual minimice el salario total que
va a las vacas.

NOMBRE DEL PROBLEMA: clean

FORMATO DE ENTRADA:

* L�nea 1: Tres enteros separados por espacios: N, M y E.

* L�neas 2..N+1: La l�nea i+1 describe la solicitud de la vaca i con
        tres enteros separados por espacios: T1, T2 y S.


ENTRADA EJEMPLO (archivo clean.in):

3 0 4
0 2 3
3 4 2
0 0 1

DETALLES DE LA ENTRADA:

GJ tiene tres vacas, y el establo debe ser limpiado desde el segundo 0
hasta el segundo 4. La primera vaca quiere trabajar durante los
segundos 0, 1 y 2 por un salario total de 3, etc.

FORMATO DE SALIDA:

* L�nea 1: Un solo entero, que es o el salario total m�nimo para tener
        el establo limpio o en otro caso �1 si es imposible limpiar el
        establo.

SALIDA EJEMPLO (archivo clean.out):

5

DETALLES DE LA SALIDA:

El Granjero Juan puede contratar las dos primeras vacas.
*/
