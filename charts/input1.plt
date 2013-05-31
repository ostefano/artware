set terminal png
set output "output.png"
set yrange [-1:256]
set ytics 16
set key off
set grid xtics ytics
set title "Scatterplot of binary values across offsets"
set xlabel "Offset (decimal)"
set ylabel "Value (decimal)"
plot "input.dat" using 1:2

