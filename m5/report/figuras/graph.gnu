#Instruções para plotar
set grid
set xtics 0,1,10
plot "in.dat" using 1:2 with linespoints ps 1 lw 1 title 'Gráfico com 100 valores'
set terminal png
set output 'graph.png'
replot
#Fim
