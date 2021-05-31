make re

counter=0
while [ $counter -le 20 ]
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker_Mac $ARG
	./push_swap $ARG | wc -l
	((counter++))
done