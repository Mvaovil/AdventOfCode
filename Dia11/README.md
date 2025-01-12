Advent11


Imagina una hilera de piedras, cada una con un número grabado, y observa lo que ocurre cada vez que parpadeas. Al parpadear, todas las piedras cambian simultáneamente según tres reglas: si ves un 0, se convierte en 1; si el número tiene un número par de dígitos, se parte en dos mitades; y si no se cumple nada de lo anterior, se multiplica por 2024. La hilera siempre conserva su orden, solo que puede alargarse si aparecen nuevas piedras al dividir un número. Para abordar el problema,debemos anotar los números iniciales, luego, definir la función que, por cada piedra, compruebe la regla aplicable y transforme ese número (o números) acorde al caso. Eso hay que hacerlo con cada parpadeo.

El principal motivo de la elección de este problema fue que era entendible y parecía de un nivel asequible. Además, debido a que este problema con fuerza bruta podría llevar a gastar excesivos recursos, consideramos que sería buena opicón aplicar una técnica de las aprendidas en clase.

Primeramente, se valoraron diferentes escenarios para su realización. El primero descartado fue el de fuerza bruta ya que eran demasiados recursos. También se valoró el uso de tablas hash pero no eran tan efectivas como usar recursividad y memorización, es decir, programación dinámica. 

Cada combinación de (valor, blinksRestantes) se trata como un subproblema. Antes de resolverlo, el programa revisa en la caché si ya existe el resultado. Si está, se recupera de inmediato, si no, se calcula y se guarda en un unordered_map. De este modo, se evitan repeticiones en los cálculos y se optimiza la ejecución. 

Durante la realización del código nos tamos con problemas como que el programa leía mal los numeros debido a que no pusimos los : en el string_clave, esto generó un auténtico quebradero de cabezas que nos tocó solucionar consultando internet. 

Al finalizar, nos quedó mucho más claro como funciona la programación dinámica y aprendimos a traducir mejor la información desde un input para que nuestro código fuese capaz de interprtarlo.

Para compilar este código input11.txt debe estar en la misma carpeta que Advent11.cpp y se debe usar g++ -o Advent11 Advent11.cpp y luego ./Advent11

