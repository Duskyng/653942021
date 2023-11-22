"""
Quais jogos foram realizados em determinado grupo ou fase (oitavas, quartas, semi e final)?

Quais jogos tiveram vitória do visitante?
Quais jogos terminaram empatados?
Quais jogos tiveram vitória do mandante?

Quais jogos foram realizados por determinada seleção?
Quais jogos foram realizados em determinado estádio e em determinada cidade?
Quantos gols foram feitos por determinado jogador?

"""

from dataclasses import dataclass
import requests

@dataclass
class Gol:
    """Classe representando um gol"""
    nome_jogador: str
    minuto: int

    def __repr__(self) -> str:
        return self.nome_jogador + " " + str(self.minuto)

@dataclass
class Partida:
    """Classe representando uma partida"""
    fase: str
    numero: int
    estadio: str
    cidade: str
    mandante: str
    visitante: str
    gols_mandante: int
    gols_visitante: int
    gols: list[Gol]

    def contem(self, codigo_time: str) -> bool:
        return codigo_time in (self.mandante, self.visitante)

    def __repr__(self) -> str:
        return (
            self.mandante + " " +  str(self.gols_mandante) + " X "
                + str(self.gols_visitante) + " " + self.visitante + " Jogado em "
                    + self.estadio + "\n")

LISTA_DE_PARTIDAS: list[Partida] = []
URL: str = "https://raw.githubusercontent.com/leandroflores/api-world-cup/main/results_2018"

def load_dados():
    """Função para carregar os dados da API"""
    response = requests.get(URL, timeout=10)
    dados = response.json()
    rodadas = dados["rounds"]
    for rodada in rodadas:
        fase = rodada["name"]
        partidas = rodada["matches"]
        for partida in partidas:
            numero = partida["num"]
            estadio = partida["stadium"]["name"]
            cidade = partida["city"]
            mandante = partida["team1"]["code"]
            visitante = partida["team2"]["code"]
            gols_mandante = partida["score1"]
            gols_visitante = partida["score2"]

            gols: list[Gol] = []
            todos_os_gols: list[dict] = partida["goals1"] + partida["goals2"]
            for gol in todos_os_gols:
                gols.append(
                    Gol(gol["name"], gol["minute"])
                        )

            partida: Partida = Partida(
                fase,
                numero,
                estadio,
                cidade,
                mandante,
                visitante,
                gols_mandante,
                gols_visitante,
                gols,
            )

            LISTA_DE_PARTIDAS.append(partida)

def get_partidas(codigo_time: str) -> list[Partida]:
    """Função para verificar qual time jogou e qual partida"""
    return list(
        filter(
            lambda partida: partida.contem(codigo_time),
            LISTA_DE_PARTIDAS
        )
    )

def get_gols_jogador(nome_jogador: str) -> list[Gol]:
    """Função para filtrar os gols"""
    gols_jogador: list[dict] = []
    for partida in LISTA_DE_PARTIDAS:
        for gol in partida.gols:
            if gol.nome_jogador == nome_jogador:
                gols_jogador.append(
                    {
                        "gol": gol,
                        "partida": partida,
                    }
                )
    return len(gols_jogador)

def get_local_partida(local: str) -> list[Partida]:
    """Função para filtrar o local da partida sendo cidade ou estadio"""
    return list(
        filter(
            lambda partida: partida.estadio == local or partida.cidade == local,
            LISTA_DE_PARTIDAS
        )
    )

def determinar_vencedor_mandante() -> list[Partida]:
    LISTA_DE_RESULTADOS = []
    for partida in LISTA_DE_PARTIDAS:
        if partida.gols_mandante > partida.gols_visitante:
            LISTA_DE_RESULTADOS.append(partida)
    return LISTA_DE_RESULTADOS

def determinar_vencedor_visitante() -> list[Partida]:
    LISTA_DE_RESULTADOS = []
    for partida in LISTA_DE_PARTIDAS:
        if partida.gols_mandante < partida.gols_visitante:
            LISTA_DE_RESULTADOS.append(partida)
    return LISTA_DE_RESULTADOS

def determinar_empate() -> list[Partida]:
    LISTA_DE_RESULTADOS = []
    for partida in LISTA_DE_PARTIDAS:
        if partida.gols_mandante == partida.gols_visitante:
            LISTA_DE_RESULTADOS.append(partida)
    return LISTA_DE_RESULTADOS

def determinar_fase() -> str:
    for partida in LISTA_DE_PARTIDAS:
        if "Matchday" in partida.fase:
            pass
        else:
            print("Partida numero: " + str(partida.numero) +
                  " ocorreu na etapa: " + str(partida.fase))

load_dados()

while True:
    # Exibe o menu
    print("\nMenu:")
    print("1. Obter informações sobre as partidas")
    print("2. Obter numero de gols de um jogador")
    print("3. Obter informações sobre o local da partida")
    print("4. Listar os jogos que resultaram em vitoria do Mandante")
    print("5. Listar os jogos que resultaram em vitoria do Visitante")
    print("6. Listar os jogos que resultaram em Empate")
    print("7. Listar jogos e suas fases")
    print("0. Sair")

    # Obtém a escolha do usuário
    escolha = input("Digite o número da opção desejada (ou 0 para sair): ")

    if escolha == "0":
        break
    elif escolha == "1":
        partida = input("Digite o codigo do time para filtrar suas partidas: ")
        partidas_do_time = get_partidas(partida)
        print(partidas_do_time)
    elif escolha == "2":
        jogador = input("Digite o nome do jogador para ver o total de gols: ")
        gols_jogador = get_gols_jogador(jogador)
        print(gols_jogador)
    elif escolha == "3":
        local = input("Digite a Cidade ou nome do Estadio para filtrar seus jogos: ")
        local_partida = get_local_partida(local)
        print(local_partida)
    elif escolha == "4":
        determinar_vencedor_mandante()
        vencedor_mandante = determinar_vencedor_mandante()
        print(vencedor_mandante)
    elif escolha == "5":
        determinar_vencedor_visitante()
        vencedor_visitante = determinar_vencedor_visitante()
        print(vencedor_visitante)
    elif escolha == "6":
        determinar_empate()
        empate = determinar_empate()
        print(empate)
    elif escolha == "7":
        determinar_fase()
    else:
        print("Opção inválida. Por favor, escolha um número de 0 a 7.")
