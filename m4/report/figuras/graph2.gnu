#Instruções para plotar
set grid
p1(x) = 0.9998 * ((x**2 - 25*x + 150)/50) + 0.9997 * ((x**2 - 20*x +75)/-25) + 0.9991 * ((x**2 - 15*x + 50)/50)
p2(x) = 0.9991 * ((x**3 - 75*x**2 + 1850*x - 15000)/-750) + 0.9982 * ((x**3 - 70*x**2 + 1575*x - 11250)/250) + 0.9971 * ((x**3 - 65*x**2 + 1350*x - 9000)/-250) + 0.9957 * ((x**3 - 60*x**2 + 1175*x - 7500)/750)
set style line 1 lc rgb '#000000' lt 1 lw 2 pt 7 pi -1 ps 1.5
set pointintervalbox 3
plot "in.dat" using 1:2 pt 5 title 'Valores tabelados', \
     p1(x) title 'Eq: 2 grau' , \
     p2(x) title 'Eq: 3 grau'
set terminal png
set output 'graph2.png'
replot
#Fim
