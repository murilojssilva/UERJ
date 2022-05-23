def buscaPosicao(vet,palavra):
    for i in range(0,len(vet)):
        if(vet[i]==palavra):
            return i
    return -1
def contarPalavra(palavra,vet1,vet2):
    posicao=buscaPosicao(vet1,palavra)
    if(posicao==-1):
        vet1.append(palavra)
        vet2.append(1)
    else:
        vet2[posicao]+=1
def separarPalavras(frase,vet1,vet2):
    palavra=''
    for i in range(0,len(frase)):
        if(frase[i]!=' '):
            palavra+=frase[i]
        else:
            if(palavra!=''):
                contarPalavra(palavra,vet1,vet2)
                palavra=''
    if(palavra!=''):
        contarPalavra(palavra,vet1,vet2)
frase=raw_input("Entre com frase: ")
vetPalavras=[]
vetCont=[]
separarPalavras(frase,vetPalavras,vetCont)
f=open("PalavraQuantidade.txt","w")
f.write("Frase: "+frase+"\n")
for i in range(0,len(vetPalavras)):
    f.write("\""+vetPalavras[i]+"\""+" aparece "+str(vetCont[i])+" vezes\n")
f.close()
