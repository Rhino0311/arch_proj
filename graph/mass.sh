g++ -I ./ *.cpp
x=1
while [ $x -le 500 ]
do
  ./a.out graph01.dat
  x=$(( $x + 1 ))
done

while [ $x -le 500 ]
do
  ./a.out graph02.dat
  x=$(( $x + 1 ))
done

while [ $x -le 500 ]
do
  ./a.out graph03.dat
  x=$(( $x + 1 ))
done

