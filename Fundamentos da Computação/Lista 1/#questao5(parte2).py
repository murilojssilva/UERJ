cont=0
n=input("Digite um número:")
for i in range(1,n//2+1):
    if n%i==0:
        cont+=1
    print i,
print "\nQuantidade de divisores:",cont
