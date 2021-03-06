{koder: A^2P}
{PSN 2005 #69 "GUS"}
program gus;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,M          : byte;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,N,M);

     {dprint}
     if M < N then write(fout,2 * M - 1)
     else write(fout,2 * N - 2);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
69� Gus.                                                  Polonia 2005
����������������������������������������������������������������������

Un gusano  comer� chocolate en un  rect�ngulo con  M filas  y N
columnas. El comienza comiendo en la esquina superior izquierda y  se
come la fila entera hasta el final. El entonces gira en sentido de las
manecillas del reloj y contin�a  comiendo la columna entera. El
proceso  es repitido, es  decir, el gusano gira en sentido  de las
manecillas  del reloj y  come la fila  entera o sea hasta el �ltimo
todav�a no comido. Repitiendo este  proceso de  comer el chocolate, el
gusano se comer� el chocolate entero.

Tarea

Escriba un programa que calcule el n�mero de giros que el guzano  hizo
hasta que el se comio el chocolate entero.

Entrada

La primera y �nica l�nea del fichero de entrada GUS.IN dos enteros M y
N, 2 <= M,N <= 100, separados por un caracter espacio. M es el  n�mero
de filas y N es el n�mero de columnas.

Salida

La primera  y �nica  l�nea del  fichero de  salida GUS.OUT contiene el
n�mero  de  giros  que  un  gusano  necesita  hacer  hasta  comerse el
chocolate entero.

Ejemplos de Entrada y Salida

Ejemplo # 1        Ejemplo # 2           Ejemplo # 3

���������Ŀ        ���������Ŀ          ���������Ŀ
� GUS.IN  �        � GUS.IN  �          � GUS.IN  �
���������Ĵ        ���������Ĵ          ���������Ĵ
� 2 3     �        � 5 3     �          � 4 10    �
�����������        �����������          �����������
���������Ŀ        ���������Ŀ          ���������Ŀ
� GUS.OUT �        � GUS.OUT �          � GUS.OUT �
���������Ĵ        ���������Ĵ          ���������Ĵ
� 2       �        � 5       �          � 6       �
�����������        �����������          �����������
}

