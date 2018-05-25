# Ordenação em multithread

Este exercício consiste em programar um algoritmo de ordenação que executa em
múltiplas threads simultâneas. A ordenação é um problema bem conhecido e as
soluções melhor paralelizáveis são, tipicamente, variantes do MergeSort ou do
QuickSort.

1. O vetor deve ser processado por diversas threads paralelas
1. O número máximo de threads paralelas fica a critério do programador, mas deve
   ser um número *finito*, *razoável* (ou seja: não é interessante usar 1024 threads
   paralelas) e *claro*.
1. O programa deve garantir que todas as threads encerram *antes* do fim do
   programa principal.

Soluções que não contemplem esses três requisitos não serão aceitas. Eles serão
verificados manualmente, caso a caso.

## Exemplos

Entrada | Saida
------- | -----
`5 4 3 2 1\n` | `1 2 3 4 5\n`
`3 2 4 1 5\n` | `1 2 3 4 5\n`

## Instruções adicionais

1. Vá diretamente ao conjunto de testes para verificar como tratar casos
   limítrofes ou mal-definidos.
1. Lembre-se de seguir as [instruções de submissão](doc/instrucoes.md).
1. Se desejar, proponha novos casos de teste.
