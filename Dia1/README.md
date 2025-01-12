Advent1


Este problema consiste en calcular la distancia total entre dos listas de números, de tal forma que, para cada elemento de una lista, se determine la diferencia entre los elementos correspondientes en la otra lista. En el problema se observa que las listas pueden seguir cualquier orden, por ello, primero debemos ordenarlas.

Al ser el primer dia teniamos ganas por ver como funcionaba ya que era nuestra primera vez, por ello escogimos este problema ya que entendimos el enunciado y nos atrajo la idea de poder implementar lo trabajado en clase. Nos gustó ya que lo veíamos con una dificultad asequible y vimos una solucion bastante rápida aunque nos costó un poco saber empezar...

La primera idea fue utilizar divide y vencerás, en el cual la lista se divide en dos mitades y se calcula la distancia de cada mitad recursivamente.  Sinceramente se plantearon otras opciones pero fueron descartadas rapidamente ya que no tenían mucho sentido. Ademas, cuando nos pusimos a utilizar esta técnica vimos que nuestra idea original tenía sentido y no le dimos muchas más vueltas.

El algoritmo utiliza divide y vencerás para dividir las listas de manera recursiva y calcular la distancia total entre ellas. Después de ordenar ambas listas, la función calcularDistancia evalúa la distancia de cada sublista.

Finalmente, la función principal imprime la distancia total entre las dos listas.

Realizando el código nos encontramos con dificultades como que pusimos inicio>fin en el primer if en vez de igual y esto provocó que nuestra codición base no fuese la correcta. Ademas, al principio, pensamos que la función debería devolver una diferencia acumulada de distancias en lugar de una suma de distancias, y restamos la distanciaIzquierda con la distanciaDerecha, por eso nos daba un resultado erroneo el código.

Coincidimos en que tras haber realizado este problema hemos entendido como aplicar bien el divideyvencerás y su tan útilizado uso para problemas de este caso. Ademas, ya sabemos identificar bien como se hace un caso base, cosa que en su día nos costó verlo con claridad.

Para compilar este código debes tener el input1.txt en la misma carpeta que el Advent1.cpp y ejecutar g++ -o Advent1 Advent1.cpp y luego ./Advent1
