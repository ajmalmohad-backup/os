echo "Enter a number to find it's Factorial: "
read num 
fact=1
while [ $num -gt 0 ]
do 
    fact=`expr $fact \* $num`
    num=`expr $num - 1` 
done 
echo "Factorial is $fact"