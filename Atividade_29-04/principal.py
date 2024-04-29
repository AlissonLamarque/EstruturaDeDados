class Atleta:
    def __init__(self, fone, nome, apelido, dataNasc, pontAcumulada):
        self.fone = fone
        self.nome = nome
        self.apelido = apelido
        self.dataNasc = dataNasc
        self.pontAcumulada = pontAcumulada
    
    def __str__(self):
        return f"Atleta: {self.nome} ({self.apelido}) - Telefone: {self.fone}, Data de Nascimento: {self.dataNasc}, Pontuacao Acumulada: {self.pontAcumulada}"
    
    def __eq__(self, other):
        return self.fone == other.fone
    
    def __hash__(self):
        return hash(self.fone)

class SistemaAtletas:
    def __init__(self):
        self.atletas = []
    
    def listar_atletas(self, ordenar_por_pontuacao=False):
        if ordenar_por_pontuacao:
            atletas_ordenados = sorted(self.atletas, key=lambda x: x.pontAcumulada, reverse=True)
            for atleta in atletas_ordenados:
                print(atleta)
        else:
            for atleta in self.atletas:
                print(atleta)
    
    def cadastrar_atleta(self, atleta):
        if atleta not in self.atletas:
            self.atletas.append(atleta)
            print("Atleta cadastrado com sucesso!")
        else:
            print("Atleta ja cadastrado.")
    
    def procurar_atleta(self, termo):
        for atleta in self.atletas:
            if termo.lower() in atleta.nome.lower() or termo.lower() in atleta.apelido.lower():
                print(atleta)
                return
        print("Atleta nao encontrado.")
    
    def remover_atleta(self, termo):
        for atleta in self.atletas:
            if termo.lower() == atleta.nome.lower() or termo.lower() == atleta.apelido.lower():
                self.atletas.remove(atleta)
                print("Atleta removido com sucesso!")
                return
        print("Atleta nao encontrado.")

sistema = SistemaAtletas()
while True:

    print("Menu\n")
    print("1 - Listar atletas")
    print("2 - Cadastrar atleta")
    print("3 - Procurar por atleta")
    print("4 - Remover atleta")
    print("0 - Sair")
    print("Opcao:")
    opcao = input()

    if opcao == "1":
        ordenar_por_pontuacao = input("Deseja ordenar por pontuacao decrescente? (s/n): ").lower()
        if ordenar_por_pontuacao == "s":
            sistema.listar_atletas(ordenar_por_pontuacao=True)
        else:
            sistema.listar_atletas()
    elif opcao == "2":
        fone = input("Telefone do atleta: ")
        nome = input("Nome do atleta: ")
        apelido = input("Apelido do atleta: ")
        data_nascimento = input("Data de nascimento do atleta: ")
        pontuacao_acumulada = input("Pontuacao acumulada do atleta: ")
        atleta = Atleta(fone, nome, apelido, data_nascimento, pontuacao_acumulada)
        sistema.cadastrar_atleta(atleta)
    elif opcao == "3":
        termo = input("Digite o nome ou apelido do atleta: ")
        sistema.procurar_atleta(termo)
    elif opcao == "4":
        termo = input("Digite o nome ou apelido do atleta a ser removido: ")
        sistema.remover_atleta(termo)
    elif opcao == "0":
        print("Saindo do sistema...")
        break
    else:
        print("Opção invalida! Tente novamente.")
