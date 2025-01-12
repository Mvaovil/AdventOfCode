Advent5


En este problema, el código verifica si las actualizaciones de páginas de un manual siguen un orden específico según las reglas de precedencia. Si una actualización está en el orden correcto, calcula la página en el medio de la lista y suma esos valores de todas las actualizaciones válidas. El resultado final es la suma de los números de página medios de las actualizaciones correctas.

Hemos elegido este problema ya que le veíamos una dificultad extra (al menos para nosotros) ya que no teníamos ni idea de como realizar el código. Al leerlo y verlo pensamos que podría tratarse de un problema de tablas hash para almacenar y acceder rápidamente a las relaciones de precedencia entre las páginas, así como para optimizar el proceso de verificación del orden en las actualizaciones. Pero al leerlo detalladamente vimos que era inviable ya que el problema requeria mantenermelos el orden entre los elementos, y en este aspecto las tablas no son muy adecuadas. 

Tras esto, pensamos en arbol ya que es más útilizado para mantener el orden pero no veíamos el como implementarlo para la resolución de este problema.

Finalmente optamos por utilizar grafos ya que las relaciones de precedencia entre las páginas pueden ser representadas naturalmente como un grafo dirigido, donde cada página es un nodo y las reglas de precedencia son los arcos dirigidos. Eso sí, no teníamos mucha idea de llevarlo al código así que empezamos a probar de manera independiente.

El primer problema que nos encontramos es que no sabíamos como representar las relaciones de precedencia entre las páginas. Finalmente, encontramos la solución usando map para almacenar las relaciones entre páginas. Tras esto, necesitabamos saber cómo verificar si una actualización cumplía con las reglas de precedencia, después de pensar en cómo estructurar el grafo, se optó por recorrer las relaciones de cada página y comprobar si las páginas estaban en el orden correcto. También, no sabíamos si debía tomarse la página del índice (size / 2) o si había que hacer alguna modificación en el caso de una lista par, lo que nos llevó a probar varias opciones hasta encontrar la correcta.



