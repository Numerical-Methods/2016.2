#Instruções para plotar sen(x)
reset
set grid
set title "Equação de Kepler"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set xtics -10,2,10 axis
set ytics -10,2,10 axis
set size 1,1
E = 0.2
M = 0.5
plot -E * sin(x) + x - M
set terminal png
set output 'kepler.png'
replot
#Fim
