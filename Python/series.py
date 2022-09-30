x=int(input("Give value of X "));
n=int(input("Give value of N "));

sum = 1;

for i in range (0,n+1):
    sum=sum+pow(x,i);

print("Sum of the Series is >",sum);
