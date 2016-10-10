#Instruções para plotar
reset
set grid
set title "Coeficiente C em função da vazão A/A1"
set xlabel "Eixo X - A/A1"
set ylabel "Eixo Y - C"
# set xtics -10,1,10 axis
# set ytics -10,1,10 axis
plot "in.dat" using 1:2 title '' pt 5 ps 2, \
     "in2.dat" using 1:2 title '' pt 9 ps 2
set terminal png
set output 'coef.png'
replot
#Fim
