# Trabalho 4º Semestre - Orientação a Objetos com Python 

O trabalho prático consiste em implementar um controle de turmas. O objetivo é
permitir o cadastro de alunos e suas notas em uma turma. Todas as operações devem ser
disponibilizadas em um menu.

## Deve conter as seguintes funções e dados:

### Cadastro de um novo aluno:
- RA (Registro Academico (Tipo: Inteiro))
- Nome (Tipo: String)
- Nota (Corresponde a media **final** do aluno **naquela turma** (Tipo: Flutuante))

### Edição dos dados de um aluno:
- A partir do RA, permite ao usuário alterar o nome e a nota de um aluno.

### Exclusão de um aluno:
- A partir do RA, permite ao usuário excluir um aluno da turma em questão.

### Resumo estatístico da turma:
~Apresentar os seguintes dados da turma em questão:~
- Quantidade de alunos
- Maior nota (nome do aluno e nota)
- Menor nota (nome do aluno e nota)
- Média das notas da turma

### Exportação de informações:
- A partir de um nome para o arquivo (string), exportar os dados de todos os alunos da turma, escrevendo em um arquivo texto.

### Importação de informações:
- A partir de um nome de arquivo (string), importar os dados de todos os alunos da turma, lendo um arquivo texto.
