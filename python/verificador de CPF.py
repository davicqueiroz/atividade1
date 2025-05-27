#limita que a digitação tenho apenas 11 digitos
while True:
    cpf = input('Digite o CPF: ')
    if cpf.isdigit() and len(cpf) == 11:
        print(f'{cpf[:3]}.{cpf[3:6]}.{cpf[6:9]}-{cpf[9:]}')
        break
    else:
        print('Entrada inválida, digite os 11 dígitos')

# conferindo se d1 é válido
def conferir_d1():
    pesos1 = [10, 9, 8, 7, 6, 5, 4, 3, 2]
    soma = 0
    for i in range(9):
        digito = int(cpf[i])
        peso1 = pesos1[i]
        soma += peso1 * digito
    d1 = soma % 11
    if d1 < 3:
        d1 = 0
    else:
        d1 = 11 - d1
    return d1
d1 = conferir_d1()

#conferindo se d2 é válido
def conferir_d2():
    pesos2 = [11, 10, 9, 8, 7, 6, 5, 4, 3, 2]
    soma = 0
    for i in range(10):
        digito = int(cpf[i])
        peso2 = pesos2[i]
        soma += peso2 * digito
    d2 = soma % 11
    if d2 < 3:
        d2 = 0
    else:
        d2 = 11 - d2
    return d2
d2 = conferir_d2()
#print(f'{d1}{d2}')

def liberacao():
    if d1 == int(cpf[9]) and d2 == int(cpf[10]):
        print('CPF válido')
    else:
        print('CPF inválido')

liberacao()