soma=0
cont=0
n=input("Digite um Número:")
if n>=13:
    for i in range(13,n+1):
        soma+=i
        cont+=1
    media=float(soma)/cont
    print "Média Aritmética= ",media
else:
    print "ERRO!"
        
