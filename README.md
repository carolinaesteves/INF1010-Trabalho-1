# INF1010-Trabalho-1
INF1010 - Trabalho 1 - Calculando expressões matemáticas

Testar programa com as seguintes expressões:
| Infix   |     Postfix      |  Resultado |
|----------|:-------------:|------:|
| 3+2*3  |  323*+ | 9 |
| 10*2-2*5 |    10 2 * 2 5 * - |   10 |
| 7+3/2 | 7 3 2 / + |    8 |  
| 2*6+3/8 | 26*38/+ |    12 |     
| 2+(3*(8-4)) | 2 3 8 4 - * + |    14 |     
| 18/2*5+6-4  | 18 2 / 5 * 6 + 4 - |    47 |     
| 3+(16-4*3)-6/2 | 3 16 4 3 * - + 6 2 / -  |    4 |     
| (2-3+1)/(2-2) | 2 3 - 1 + 2 2 - / |    denominador = 0 |     
| ((18+3*2)/8+5*3)/6 | 18 3 2 * + 8 / 5 3 * + 6 / |    3 |  
| 16/4*(4) | 16 4 / 4 * |    16 |  

#Tarefas
- [ ] (Anna Carolina) Traduzir expressão do formato infix para formato postfix
- [ ] (Anna Carolina) Calcular resultado com o algoritmo Shunting Yard
- [ ] (Ana Carolina) Receber uma expressão no formato postfix e criar uma árvore de expressão
- [ ] (Ana Carolina) Calcular resultado com a árvore de expressão
