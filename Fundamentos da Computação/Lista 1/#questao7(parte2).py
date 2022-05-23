n=input("Digite um número:")
if n<=0:
    print "ERRO!"
elif n<=3:
    print "Número Perfeito"
else:
    soma=0
    for i in range(1,n//2+1):
        if n%i==0:
            soma+=i
    if soma==n:
        print n,"Número Perfeito"
    else:
        print "Não Perfeito"
