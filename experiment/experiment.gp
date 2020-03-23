reset
set term png enhanced font 'Verdana,10'
set ylabel 'time(ns)'
set key left top
set title 'fib algo comparison'
set output 'experiment.png'
plot [2:93][:] \
'experiment_data' using 1:2 with linespoints linewidth 2 title "easy fib",\
'' using 1:3 with linespoints linewidth 2 title "fast fib w/o clz",\
'' using 1:4 with linespoints linewidth 2 title "fast fib with clz",\