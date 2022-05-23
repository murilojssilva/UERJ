cont1=0
cont2=0
cont3=0
soma1=0
soma2=0
soma3=0
nome=raw_input("Nome da Mercadoria:")
nome=nome.lower()
while nome!="fim":
    preco_compra=input("Preço de compra da mercadoria:")
    preco_venda=input("Preço de venda da mercadoria:")
    lucro=preco_venda - preco_compra
    if lucro<0.1:
        cont1+=1
    elif lucro==0.1 or lucro<=0.2:
        cont2+=1
    else:
        cont3+=1
    soma1+=preco_compra
    soma2+=preco_venda
    soma3+=lucro
    nome=raw_input("Nome da Mercadoria:")
print "PREÇO TOTAL DE COMPRAS R$",soma1
print "PREÇO TOTAL DE VENDAS R$",soma2
print "LUCRO TOTAL R$",soma3
print "Lucro menor que 10% R$",cont1
print "Lucro entre 10% e 20% R$",cont2
print "Lucro maior que 20% R$",cont3
