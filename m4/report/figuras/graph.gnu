#Instruções para plotar
set grid
set style line 1 lc rgb '#000000' lt 1 lw 2 pt 7 pi -1 ps 1.5
set pointintervalbox 3
plot "in.dat" using 1:2:(sprintf("(%d, %.4f)", $1, $2)) with linespoints ls 1 notitle
set terminal png
set output 'graph.png'
replot
#Fim
