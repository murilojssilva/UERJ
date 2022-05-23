def OrdemAlfabetica(vet):
    tam=len(vet)
    for i in range (0,tam-1):
        menor=i
        for j in range(i+1,tam):
            if vet[i]>vet[j]:
                menor=j
        aux=vet[i]
        vet[i]=vet[menor]
        vet[menor]=aux
    return vet

vet=[0]*10
for i in range(0,10):
    vet[i]=raw_input("Nome:")
print "\n Nomes:"
print vet
vet_ord=[]
vet_ord=OrdemAlfabetica(vet)
print "\n Nomes Ordenados:"
print vet_ord
