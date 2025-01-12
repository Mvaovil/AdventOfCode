Advent7


Este día nos ha costado mucho ya que creíamos que era un buen ejercicio para implementar lo aprendido a clase y utilizar un árbol binario pero al final hemos sido incapaces de hacerlo. Lo hemos resuelto utilizando recursividad y generando un arbol implícito de decisiones.

Hemos elegido este día ya que lo veíamos un buen ejercicio para ser resuelto por arbol debido a que en el problema teníamos dos pasos posibles en cada calibración, sumar o multiplicar. Debido a esto, cada elección se ramificaba en 2 opciones, uno por cada operador posible lo cual encajaba a la perfección con un problema para ser resuelto con árbol. Hemos intentado solucionar el fallo de todas las formas posibles pero finalmente hems hecho un arbol implícito por así decirlo forzando la situación y ya está. 

En todo momento supimos que este problema era para ser realizado usando árbol y por ello no le dimos más vueltas a otras soluciones.

Este código lee una serie de objetivos y de listas de números desde un archivo y, para cada objetivo, comprueba si es posible formarlo **colocando operadores + o *** entre los elementos de la lista correspondiente. Para entender su lógica como un árbol, basta con ver que la función verificarConArbol usa recursividad: en cada paso (nodo), elige entre sumar o multiplicar el siguiente número (ramificaciones), generando así un “árbol de decisiones” implícito. Cada camino por ese árbol representa una combinación distinta de operaciones, y cuando se agotan los números se verifica si el resultado coincide con el objetivo. Si al menos un camino produce el objetivo, se considera alcanzable y se suma al resultado total.

Hemos encontrado tantos fallos realizándolo que al final simplemente hemos sido incapaces de realizarlo. Siempre nos salía el mismo número y no sabíamos porqué, al forzar la recursividad y el árbol, hemos conseguido que nos diese un número diferente que sí que aceptaba el AdventOfCode, pero del otro modo era imposible. Habíamos intentado implementar la estrctura de árbol en memoria y crear cada nodo con un puntero a left y right para asignar dinámicamente objetos TREENODE.

Tras este día, hemos aprendido a buscar soluciones alternativas cuando las cosas no salen como uno espera, hemos sabido implementar el árbol aunque no de una manera correcta pero al menos se ven restos de la antigua implementación.

Para compilar este código, input7.txt debe estar en la misma carpeta que Advent7.cpp y se debe usar g++ -o Advent7 Advent7.cpp y luego ./Advent7
