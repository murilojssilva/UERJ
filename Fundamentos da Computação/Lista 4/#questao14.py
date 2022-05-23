pal=raw_input("Palavra:")
pal=pal.upper()
inicio=0
fim=len(pal)-1
palindromo=True
while inicio<=fim and palindromo:
    if pal[inicio]!=pal[fim]:
        palindromo=False
    else:
        inicio+=1
        fim-=1
if palindromo==True:
    print "Palíndromo"
else:
    print "Não Palíndromo"




