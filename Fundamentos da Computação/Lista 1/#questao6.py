cont1=0
cont2=0
soma1=0
soma2=0
n=input("Quantidade de pares (x,y):")
for i in range(0,n):
    x=input("Valor de x=")
    y=input("Valor de y=")
    if x>y:
        for j in range(y,x+1):
            if j%2==0:
                cont1+=1
                soma1+=j
                media1= float(soma1)/cont1
                print "Média aritimética dos pares entre x e y:",media1
    else:
        for k in range (x,y+1):
            if k%2==1:
                cont2+=1
                soma2+=k
                media2= float(soma2)/cont2
                print "Média artitimética dos ímpares entre x e y:",media2

