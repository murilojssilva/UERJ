import json


class ManipuladorJson:

    def __init__(self, nomegrafo):
        self.nomegrafo = nomegrafo

    @property
    def getMassaGrafos(self):

        with open('massa.json') as json_file:
            data = json.load(json_file)

            for i in range(0, len(data['grafos'])):
                if data['grafos'][i]['nome'] in self.nomegrafo:
                    return data['grafos'][i]

    def getTamanho(self, getGrafos):

        return len(getGrafos['vertices'])
