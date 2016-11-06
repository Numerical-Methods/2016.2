#Instruções para plotar
set grid
plot "in.dat" using 1:2 with linespoints pt 5 ps 1 lw 2 title 'Valores tabelados'
set terminal png
set output 'graph.png'
replot
#Fim
