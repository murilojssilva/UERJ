maiorIdade=-1
soma=0
cont1=0
cont2=0
cont3=0
nome=raw_input("Nome:")
idade=input("Idade:")
salario=input("Salario:")
while salario>=0:
    cont1+=1
    soma+=salario
    media=float(soma)/cont1
    if idade<30 and salario>3000:
        cont3+=1
    if idade>maiorIdade:
        maiorIdade=idade
        maiorNome=nome
    nome=raw_input("Nome:")
    idade=input("Idade:")
    salario=input("Salario:")
print "Média salarial:", media
print "Pessoa mais velha:", maiorNome
print "Salário acima de 3000 com menos de 30 anos:", cont3, "pessoas"


    
