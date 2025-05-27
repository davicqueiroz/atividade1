def saudacao(nome):
    mensagem = f"Olá, {nome}! Seja bem-vindo(a) ao Python no VS Code."
    return mensagem

# Ponto de entrada
nome_usuario = input("Digite seu nome: ")
mensagem_final = saudacao(nome_usuario)
print(mensagem_final)