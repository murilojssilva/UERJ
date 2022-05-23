vet=[0]*12
for i in range(0,12):
    vet[i]=input("Número:")
print vet
x=input("Posição x:")
y=input("Posição y:")
for i in range(0,12):
    if x==i:
        a=vet[i]
    if y==i:
        b=vet[i]
soma=a+b
print "Soma posição (x) + posição (y) =", soma
