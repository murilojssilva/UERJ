vet=[0]*8
vet_aux=[0]*4
for i in range(0,8):
    vet[i]=input("Número:")
    for j in range(0,4):
        if i==j:
            vet_aux[j]=vet[i]
print "Vetor Original:", vet

inicio=0
meio=len(vet)//2
while meio<8:
    vet[inicio]=vet[meio]
    inicio+=1
    meio+=1
meio-=1
fim=len(vet_aux)-1
while meio>3:
    vet[meio]=vet_aux[fim]
    fim-=1
    meio-=1
print "Vetor  Trocado:", vet
