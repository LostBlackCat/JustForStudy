a=[1,2,3,4,5,6,7]
b=[2,3,4,5,6]
c=[a,b]
b=map(sum,c)
print(b)
for i in range(1,10):
    for j in range(1,i+1):
        print(j,'*',i,'=',i*j,'\t',end='')
    print('\n')

