# AdventOfCode
Advent13
Este código nos pedia calcular el mínimo de tokens que debemos gastar para ganar todos los premios posibles. Cada máquina tienes dos botones A y B que mueven la garra en X e Y. Moverlo con A cuesta 3 fichas y con B cuesta 1. La tarea es calcular la cantidad mínima de fichas necesarias para que la garra se alinee con el premio en las coordenadas X y Y dadas para cada máquina. Lo máximo que puedes presionar los botones es 100 veces, por ello, debes maximizar la cantidad de premios ganados. El objetivo es obtener el mayor número de premios posibles y determinar cuántas fichas en total gastarías para obtener esos premios.

Hemos escogido resolverlo mediante programacion dinámica ya que nos permitía estructurar el problema en subproblemas que se resolvian de manera más óptima. Por ello, decidimos dar un estado a cada máquina y usar la programacion dinámica para calcular el coste mínimo acumulado mientras vamos maximizando la cantidad de premios obtenidos. 

Primero, hemos definido el estado de la máquina usando un array dp[] donde dp[i] representaba el número minimo de fichas necesarias para ganar i premios. Iniciámos el array dp[] con un valor muy alto como es INF de infinito para que sepa que no se puede ganar un número especifico de premios con un número dado de fichas. Luego establecemos dp[0]=0 ya que sin gastar fichas no se pueden ganar premios 

Seguidamente, buscamos cuantas veces debemos presionar los botones A y B para alcanzar la coordenada del premio y si es posible calculamos el coste mínimo de fichas.
Si con X número de fichas podemoste ganar un premio pues debemos actualizar dp para que vea que con más fichas podemos ganar más premios. Entonces, el máximo valor de dp nos va a dar los premios que podemos ganar y el coste mínimo de fichas para lograrlo.

De forma más resumida, buscamos el coste mínimo de fichas necesarios para ganar cada premio. Actualizamos el número máximo de premios que se pueden ganar utilizando programacion dinámica. Luego, buscamos el número máximo de premios posibles y el coste mínimo que se nos haya asociado a ese número.





