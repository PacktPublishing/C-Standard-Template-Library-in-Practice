set datafile separator ","
set autoscale
set title "Raw vs. Clamped values"
set xlabel "Index"
set ylabel "Value"

plot "output.csv" using 0:2 title "Raw value" with lines lw 3, "output.csv" using 0:3 title "Clampled signed 8-bit" with lines lw 3, "output.csv" using 0:4 title "Clamped unsigned 8-bit" with lines lw 3, "output.csv" using 0:5 title "Clamped -30, 30" with lines lw 3

pause -1
