make re

counter=0
while [ $counter -le 10 ]
do
	ARG=`ruby -e "puts (1..15).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker_Mac $ARG
	./push_swap $ARG | wc -l
	((counter++))
done