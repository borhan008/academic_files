echo "Enter a number"
read n
i=`expr $n - 1`
p=1
while [ $i -ge 1 ]
do
	n=`expr $n \* $i`
	i=`expr $i - 1`
done
echo "The factorial of the given number is $n"