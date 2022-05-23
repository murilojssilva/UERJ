cont=0
vet=[0]*4
for i in range(0,4):
    vet[i]=input("Número:")
    if vet[i]%2==0:
        cont+=1
print vet
print cont, "elemento(s) par(es)"
