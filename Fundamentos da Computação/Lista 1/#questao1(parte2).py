n=input("Digite um número:")
if n<=0:
    print "ERRO!"
elif n<=3:
    print "Número Primo"
else:
    primo=True
    i=2
    while i<=n//2 and primo:
        if n%i==0:
            primo=False
            print "Não Primo"
        i+=1
    if primo==True:
        print "Número Primo"
