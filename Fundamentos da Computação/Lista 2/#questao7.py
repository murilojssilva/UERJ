def LerVetor(vet):
    for i in range(0,5):
        vet[i]=int(input("Número:"))
    return vet

def NovoVetor(vet):
    for i in range(0,5):
        if i%2==1:
            vet[i]=vet[i]*3
        if vet[i]%2==0:
            vet[i]=vet[i]*2
    return vet

A=[0]*5
A=LerVetor(A)
vetor=NovoVetor(A)
print "\nVetor Original:", A
print "\nNovo Vetor:", vetor
