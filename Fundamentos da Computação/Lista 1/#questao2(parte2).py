maior=-10000
menor=10000
soma=0
cont=0
n=input("Digite um número:")
while n!=9999:
    if n<menor:
        menor=n
    elif n>maior:
        maior=n
    soma+=n
    cont+=1
    n=input("Digite um número:")
media=float(soma)/cont
print "Maior Valor:",maior
print "Menor Valor:",menor
print "Média Aritimética dos Valore:", media
