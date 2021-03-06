{koder: A^2P}
{PSN 2002 #52 "Prado"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxF = 2000;
var
  fin,fout        : text;
  F,B,i,j,k       : word;
  piv,tmp         : real;
  d               : array[0..MaxF] of real;
  x,y             : array[0..MaxF] of integer;
  mark            : array[1..MaxF] of boolean;

    function cost(i,j: word): real;
    begin
      cost := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
    end;{cost}

    procedure qsort(desde,hasta: word);
    var i,j : word;
    begin
      i := desde; j := hasta; piv := d[(desde + hasta) div 2];
      repeat
        while d[i] > piv do inc(i);
        while d[j] < piv do dec(j);
        if i <= j then
        begin
          tmp := d[i]; d[i] := d[j]; d[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < hasta then qsort(i,hasta);
      if j > desde then qsort(desde,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,F,B);
  for i:=1 to F do readln(fin,x[i],y[i]);

  {solve}{prim}
  mark[1] := true;
  d[0] := MaxLongint;
  for i:=1 to F do
    d[i] := cost(1,i);
  for i:=1 to F-1 do
  begin
    k := 0;
    for j:=1 to F do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    for j:=1 to F do
      if (not mark[j]) and (cost(k,j) < d[j])
        then d[j] := cost(k,j);
  end;{for}
  qsort(1,F);

  {dprint}
  write(fout,d[B]:0:2);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
52� Prado                                                     USA 2003
����������������������������������������������������������������������

Como   usted  probablemente  ha  supuesto,  nosotros  estamos hablando
acerca    de  un  prado  ordinario con  muchas  flores esparcidas  por
todas  partes.  Volando  entre  ellas, aterrizando sobre ellas y luego
irse  de  ellas  est�n numerosas abejas trabajadoras, recolectando  la
materia prima conocida como polen  que  usan para  producir la miel en
sus  colmenas.  Dado  que   la  vida  y prosperidad de la comunidad de
abejas  dependen  de    ello,    cada flor  necesita ser visitada para
recolectar la mayor cantidad de polen posible.

Maya      es    la    abeja    que  tiene  que  hacer  una  lista   de
planificaci�n    seg�n la cual las abejas visitar�n  todas  las flores
en  el prado. Una lista de planificaci�n consiste  en varios conjuntos
de    flores (sus posiciones,  realmente). Cada abeja es asignada a un
conjunto  y  esta  tiene  que  visitar todas las flores  de  �l  en un
orden  arbitrario.  Cada  flor    puede  ser visitada  arbitrariamente
muchas  veces.    El    peso    de    una secuencia  de  flores  es la
distancia m�s grande  entre  dos flores consecutivas en la secuencia.
El  peso  de  un  conjunto  de flores  es  el peso m�nimo de todas las
secuencias de flores del  conjunto.  Una  abeja  con el conjunto  dado
de    flores siempre  planear� su vuelo  seg�n la secuencia  de  todas
las  flores  del  conjunto con el peso m�nimo. El peso en la  lista de
planificaci�n  es el peso m�ximo de todos los conjuntos en la lista de
planificaci�n.

Tarea

Escriba    un    programa  que  ayude a Maya a encontrar  una lista de
planificaci�n con el peso m�s bajo.

Entrada

La  primera  l�nea  del fichero de entrada MEADOW.IN consiste  en  dos
n�meros  naturales  F y B; 1<= F<= 2000, 1 <= B <= F, F  es  el n�mero
de  flores  en el prado y B es el  n�mero  de  abejas disponibles para
recolectar  el  polen. Cada  una  de  las  pr�ximas F l�neas  contiene
dos    n�meros  naturales X y Y, 1<=X,Y<=10000, las coordenadas de una
flor.

Salida

La    primera  y  �nica  l�nea  del  fichero de salida MEADOW.OUT debe
contener el posible peso m�nimo de una lista de planificaci�n para los
datos  dados  en  el  fichero  de  entrada descritos anteriormente. El
resultado  debe redondearse a dos lugares  decimales.  El resultado no
puede diferir de la soluci�n correcta por m�s de 0.01.

Ejemplos de Entrada y Salida

      Ejemplo # 1         Ejemplo # 2            Ejemplo # 3
���������Ŀ����������Ŀ ���������Ŀ����������Ŀ ���������Ŀ����������Ŀ
�MEADOW.IN��MEADOW.OUT� �MEADOW.IN��MEADOW.OUT� �MEADOW.IN��MEADOW.OUT�
���������Ĵ����������Ĵ ���������Ĵ����������Ĵ ���������Ĵ����������Ĵ
� 3 2     �� 1.41     � � 5 3     �� 3.00     � � 7 4     �� 3.00     �
� 1 1     ������������� � 1 1     ������������� � 1 1     �������������
� 2 3     �             � 1 4     �             � 3 9     �
� 3 2     �             � 1 5     �             � 9 4     �
�����������             � 5 1     �             � 2 2     �
                        � 5 5     �             � 6 4     �
                        �����������             � 5 5     �
                                                � 6 9     �
                                                �����������
}
