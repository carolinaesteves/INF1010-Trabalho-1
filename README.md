# INF1010-Trabalho-1
INF1010 - Trabalho 1 - Calculando expressões matemáticas

Testar programa com as seguintes expressões:
| Infix   |     Postfix      |  Resultado |
|----------|:-------------:|------:|
| 3+2x3  |  32x3+ | 9 |
| 10x2-2x5 |    ??? |   10 |
| 7+3/2 | 7 3 2 / + |    8 |  
| 2x6+3/8 | 26x38/+ |    12 |     
| 2+(3x(8-4)) | 2384-x+ |    14 |     
| 18/2x5+6-4  | ??? |    47 |     
| 3+(16-4x3)-6/2 | ????  |    4 |     
| (2-3+1)/(2-2) | 23-1+22- / |    denominador = 0 |     
| ((18+3x2)/8+5x3)/6 | ??? |    3 |  
| 16/4x(4) | ??? |    16 |  

#Tarefas
- [ ] (Anna Carolina) Traduzir expressão do formato infix para formato postfix
- [ ] (Anna Carolina) Calcular resultado com o algoritmo Shunting Yard
- [ ] (Ana Carolina) Receber uma expressão no formato postfix e criar uma árvore de expressão
- [ ] (Ana Carolina) Calcular resultado com a árvore de expressão
