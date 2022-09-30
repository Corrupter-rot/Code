str = input("Give a string: ");
count = {};

for i in str:
    if i in count:
        count[i]+=1;
    else:
        count[i]=1;
print(count);
