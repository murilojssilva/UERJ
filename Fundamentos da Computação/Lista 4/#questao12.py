vet1=[0]*10
vet2=[0]*10
vet3=[0]*20
vet4=[0]*10
for i in range(0,10):
    vet1[i]=input("Número:")
    vet3[i]=vet1[i]
    vet2[i]=input("Número:")
    vet3[i+10]=vet2[i]
    if vet1[i]==vet2[i]:
        vet4[i]=vet1[i]
print vet1
print vet2
print vet3
print vet4
               
