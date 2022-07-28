echo "Enter Number of Terms to be Outputted: "
read n 
first=0
second=1 
echo $first 
echo $second
while [ $n -gt 2 ]
do 
    third=`expr $first + $second` 
    echo $third
    first=$second
    second=$third
    n=`expr $n - 1`
done
