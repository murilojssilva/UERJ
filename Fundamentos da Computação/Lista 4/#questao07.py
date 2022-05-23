vet1=[0]*5
vet2=[0]*5
vet3=[0]*10
tam=5
for i in range(0,5):
    vet1[i]=input("Número Vet1:")
    vet3[i]=vet1[i]
for i in range(0,5):
    vet2[i]=input("Número Vet2:")
    vet3[i+tam]=vet2[i]
print vet1
print vet2
print vet3
    
    
