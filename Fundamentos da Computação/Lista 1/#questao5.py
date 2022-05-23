soma=0
n=input("Quantidade de pares (x,y):")
for i in range(0,n):
    x=input("Valor de x=")
    y=input("Valor de y=")
    if x>y:
        for j in range(y,x+1):
            if j%2==1:
                soma+=j
                print "Soma dos ímpares entre x e y:",soma
    else:
        print "ERRO!"

