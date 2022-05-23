soma=0
n=input("Número de Termos da PA:")
a1=input("Primeiro Termo da PA:")
r=input("Razão da PA:")
an=a1+(n-1)*r
for i in range(a1,an+1,r):
    print i," ",
    soma+=i
print "\nSoma dos Termos = ", soma
