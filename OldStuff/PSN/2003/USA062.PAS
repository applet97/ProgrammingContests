{koder: A^2P}{2 - 5 - 2007}
{PSN 2003 #62 "T�nel"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  pos             : array[0..MaxN] of longint;
  list            : array[0..MaxN * 2] of string[8];

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to 2 * N do readln(fin,list[i]);

  {solve}
  for i:=1 to N do
  begin
    j := N + 1;
    while list[j] <> list[i] do inc(j);
    pos[i] := j;
  end;{for}

  for i:=1 to N do
    for j:=i - 1 downto 1 do
      if pos[i] < pos[j] then
      begin
        inc(sol);
        break;
      end;{then}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
62� T�nel.                                                    USA 2003
����������������������������������������������������������������������

Mirko est� posicionado  en la entrada y Slavko est� posicionado en la
salida de un t�nel. Ellos anotan el registro de matr�cula (las chapas)
de los autom�viles que pasan por ellos y proporcionan esa informaci�n
a la patrulla de policia que est� a unas millas de ellos en la
carretera.

Usando la informaci�n que Mirko y Slavko les dieron, la polic�a puede
determinar, sin cometer error, que algunos choferes se adelantaron
mientras manejaban a trav�s del t�nel y esto est� estrictamente
prohibido Escriba un programa que determine el n�mero de choferes para
los cuales la polic�a puede alegar que ellos se adelantaron. Nosotros
asumimos que el tr�fico a trav�s del t�nel no tiene ninguna parada.

Entrada

El archivo de la entrada TUNNEL.IN consiste en 2N+1 l�neas. En primera
l�nea hay un entero N, 1 <= N <= 1000, n�mero de autom�viles. En las
pr�ximas N l�neas hay registros de matr�cula de esos autom�viles, en
el orden en que ellos entraron en el t�nel. En las pr�ximas N l�neas
est�n los registros de matr�culas de esos autom�viles, en el orden en
que ellos salieron del t�nel. El registro de matr�cula de un autom�vil
consiste en por lo menos seis y a lo sumo ocho car�cteres y s�lo ser�n
permitidos los caracteres del alfabeto ingl�s (A-Z) y los d�gitos del
sistema decimal (0-9).

Salida

En la primera y �nica l�nea del fichero de salida TUNNEL.OUT aparecer�
el n�mero de choferes que polic�a puede castigar ciertamente por
adelantarse en el t�nel.

Ejemplos de Entrada y Salida:

  Ejemplo #1           Ejemplo # 2             Ejemplo #3

 �����������Ŀ        �����������Ŀ           ������������Ŀ
 � TUNNEL.IN �        � TUNNEL.IN �           � TUNNEL.IN  �
 �����������Ĵ        �����������Ĵ           ������������Ĵ
 � 4         �        � 5         �           � 5          �
 � ZG431SN   �        � ZG508OK   �           � ZG206A     �
 � ZG5080K   �        � PU305A    �           � PU234Q     �
 � ST123D    �        � RI604B    �           � OS945CK    �
 � ZG206A    �        � ZG206A    �           � ZG431SN    �
 � ZG206A    �        � ZG232ZF   �           � ZG5962J    �
 � ZG431SN   �        � PU305A    �           � ZG5962J    �
 � ZG5080K   �        � ZG232ZF   �           � OS945CK    �
 � ST123D    �        � ZG206A    �           � ZG206A     �
 �������������        � ZG508OK   �           � PU234Q     �
                      � RI604B    �           � ZG431SN    �
                      �������������           ��������������
 ������������Ŀ       ������������Ŀ          ������������Ŀ
 � TUNNEL.OUT �       � TUNNEL.OUT �          � TUNNEL.OUT �
 ������������Ĵ       ������������Ĵ          ������������Ĵ
 � 1          �       � 3          �          � 2          �
 ��������������       ��������������          ��������������
}
