def BuscaNome(vet,elem):
    vet_aux=[0]*2
    inicio=0
    fim=len(vet)-1
    achou=False
    while inicio<=fim and not achou:
        meio=(inicio+fim)//2
        if vet[meio]==elem:
            pos=meio
            achou=True
        elif elem>vet[meio]:
            inicio=meio+1
        else:
            fim=meio-1
    if achou:
        vet_aux[0]=elem
        vet_aux[1]=pos+1
    return vet_aux


nome=[0]*5
for i in range (0,5):
    nome[i]=raw_input("Digite um nome:")
print nome
busca=raw_input("Nome procurado:")
pesquisa=[]
pesquisa=BuscaNome(nome,busca)
if pesquisa[0]!=0 and pesquisa[1]!=0:
    print "\nNome Encontrado:", pesquisa[0]
    print "Posição", pesquisa[1], "da lista"
else:
    print "Nome não consta na lista!"
