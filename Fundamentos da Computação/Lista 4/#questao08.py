vet1=[0]*5
vet2=[0]*5
vet3=[0]*5
vet4=[0]*5

for i in range(0,5):
    vet1[i]=input("Número Vet1:")
print vet1, "\n "

for i in range(0,5):
    vet2[i]=input("Número Vet2:")
print vet2, "\n "

for i in range(0,5):
    soma=vet1[i]+vet2[i]
    vet3[i]=soma
    dif=vet1[i]-vet2[i]
    vet4[i]=dif
print "Soma dos elementos:", vet3
print "Diferença dos elementos:", vet4

