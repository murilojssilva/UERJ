cont=0
soma=0
n=input("Digite um número:")
for i in range(1,n+1):
    for j in range(2,i):
        if i%j==0:
            cont+=1
    if cont==0:
        print i
        soma+=i
    cont=0
print "Soma dos Primos:", soma
