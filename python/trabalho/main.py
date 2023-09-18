def insereAlunos(alunos, quantidadeAlunos):
    for x in range(quantidadeAlunos):
        ra = int(input("Digite o RA do Aluno: "))
        nome = str(input("Digite o Nome do Aluno: "))
        nota = float(input("Digite a Media Final do Aluno: "))
        aluno = {
            "RA": ra,
            "nome": nome,
            "nota": nota,
        }
        alunos.append(aluno)

def editaAlunos(alunos):
    raEdicao = int(input("Digite o RA do aluno que deseja Editar: "))

    for aluno in alunos:
        if aluno["RA"] == raEdicao:
            novo_nome = str(input("Digite o Novo Nome do Aluno: "))
            nova_nota = float(input("Digite a Nova Media Final do Aluno: "))
            aluno["nome"] = novo_nome
            aluno["nota"] = nova_nota
            print("Os dados foram atualizados")
            return
    
    print("Aluno não encontrado")
    
def removeAlunos(alunos):
    raRemocao = int(input("Digite o RA do aluno que deseja Remover: "))

    for aluno in alunos:
        if aluno["RA"] == raRemocao:
            alunos.remove(aluno)
            print("Cadastro removido")
            return
        
    print("Aluno não encontrado")

def main():
    alunos = []
    while True:
        print("\nMenu")
        print("1 - Inserir Alunos")
        print("2 - Editar Aluno")
        print("3 - Remover Aluno")
        print("4 - Resumo Estatistico")
        print("5 - Sair")

        selecao = int(input("Escolha uma ação: "))

        if selecao == 1:
            quantidadeAlunos = int(input("Digite o numero de alunos a serem inseridos: "))
            insereAlunos(alunos, quantidadeAlunos)
        elif selecao == 2:
            editaAlunos(alunos)
        elif selecao == 3:
            removeAlunos(alunos)
        elif selecao == 5:
            break
        else:
            print("Opção Invalida")

if __name__ == "__main__":
    main()

