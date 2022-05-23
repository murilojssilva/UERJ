cont_vog=0
frase=raw_input("Digite uma frase:")
frase=frase.lower()
for i in range(0,len(frase)):
    if frase[i]=='a'or frase[i]=='e'or frase[i]=='o'or frase[i]=='u':
        cont_vog+=1
print "Quantidade de vogais:",cont_vog
tam=len(frase)
meio=tam//2
fim=tam-1
if tam%2==0:
    if (frase[0]=='a' or frase[0]=='e' or frase[0]=='i' or frase[0]=='o' or frase[0]=='u') and\
        (frase[meio]=='a' or frase[meio-1]=='a' or frase[meio]=='e' or frase[meio-1]=='e' or\
        frase[meio]=='i' or frase[meio-1]=='i' or frase[meio]=='o' or frase[meio-1]=='o' or\
         frase[meio]=='u' or frase[meio-1]=='u') and (frase[fim]=='a' or frase[fim]=='e' or\
                                                      frase[fim]=='i' or frase[fim]=='o' or frase[fim]=='u'):
        print "OK!"
    else:
        print "PROBLEMA!"
elif tam%2==1:
    if (frase[0]=='a' or frase[0]=='e' or frase[0]=='i' or frase[0]=='o' or frase[0]=='u') and\
        (frase[meio]=='a'or frase[meio]=='e' or frase[meio]=='i' or frase[meio]=='o' or frase[meio]=='u') and\
         (frase[fim]=='a' or frase[fim]=='e' or frase[fim]=='i' or frase[fim]=='o' or frase[fim]=='u'):
        print "OK!"
    else:
        print "PROBLEMA!"
        
        
        
