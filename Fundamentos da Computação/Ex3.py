arquivo=open('arq.txt','w') #criando arquivo
for i in range(0,3):
    nome=raw_input('Nome: ')
    idade=input('Idade: ')
    arquivo.write(nome+' ')
    arquivo.write(str(idade)+'\n')
arquivo.close()

arquivo=open('arq.txt','r') #lendo arquivo
soma=0
for i in range(0,3):
    a=arquivo.readline()
    [nome,idade]=a.split()
    soma=soma+int(idade)
media=soma/3.0
arquivo.close()

arquivo2=open('arq_media.txt','w') #calculando e escrevendo a media
arquivo2.write('Media: '+str(media)+'\n')
arquivo2.close()

arquivo=open('arq.txt','r') #escrevendo nome com media menor
for i in range(0,3):
    a=arquivo.readline()
    [nome,idade]=a.split()
    if int(idade)<media:
        arquivo2=open('arq_media.txt','a')
        arquivo2.write('Aluno: '+nome+'\n')
        arquivo2.close()
arquivo.close()
