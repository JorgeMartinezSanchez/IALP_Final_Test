# Éxamen final de Introducción a la Programación: Agenda de eventos

## Problema
Crear una base de datos cuyo propósito sea guardar eventos en una fecha correspondiente en un programa de C++

## Explicación y comparación
Esta base de datos es se podría decir una versión menos avanzada de las ya existentes, ya que tiene el proposito solo de preparar a los estudiantes de ingeniera de software para que puedan realizar proyectos más grandes y ambiciosos a futuro.

## Estructura del repositorio
Este repositorio se divide unicamente de dos partes.
- Una carpeta llamada _Testers_ en el que está contenida varios ejecutables y archivos .cpp que fueron usados y creados para probar funciones y lógicas para implementarlas al programa principal en el que se presentará el exámen
- La raíz del repositorio se compone unicamente de la ya mencionada carpeta, el coidgo, el header con el que el código se ejecutará y el ejecutable con el que se correrá el código (es recomendable correrlo en cmd con el comando _.\x_

## Descripcion de las funciones y estructuras
### Funciones del header dateset
Este header se divide en 5 funciones del tipo _string_

- **Date.-** Esta función es la que se utiliza en el código principal para devolver la fecha, ejecutando la siguiente funcion **_monthSet_** agregando tres variables enteras que el usuario puede darle valor llamadas **_d (day)_, _m (month)_ & _y (year)_**. Tambien dentro de la función son declaradas la variable **_max_day_** que se utiliza como límite del rango de días que puede tener cada mes del año, la variable **_leap_** que es una contraparte de la varibale **_max_day_** exclusivamente para el mes de febrero cuyo valor depende si el año que introdujo el usuario es un año bisiesto o no. La función **_Date_** de por si sola se encarga de asegurarse si el año es bisiesto o no y también para asegurarse de que el año introducido no sea un numero negativo para luego, ejecutar las siguientes 4 funciones que iré mencionando.

- **monthSet.-** Esta función se encarga de establecer el limite del rango de días (max_day) para luego ejecutar y devolver la función **_daySet_** dependiendo del numero del mes que haya agregado el usuario en el programa, si el usuario llegase a agregar un numero que no corresponda a los numeros del mes (1 a 12), la función devolvera el numero que esté más próximo al introducido por el usuario (generalmente el mes 12), si por alguna extraña razón el usuario llega a introducir un número negativo, se ejecutará una función exclusiva para esta llamada **_ifMonthNegative_** que hace casi exactamente lo mismo que la función **_monthSet_** solo que este convierte los numeros negativos introducidos por el usuario en positivos, devolviendo así la versión positiva del numero introducido.

- **daySet.-** Está función se encarga de devolver el numero del día que haya introducido el usuario dentro del rango **_max_day_** ya establecido por la anteriormente mencionado **_monthSet_**, al igual que esta, si el usuario llega a poner un numero que no corresponda al rango del numero de días impuesto por **_max_day** se devolverá el nuemro más próximo al introducido dentro del rango de días, y si el usuario ingresa un numero negativo se ejecutará la función **_ifDayNegative_** que se encargará de deolver la versión positiva del numero introducido por el usuario ejecutando la misma lógica que tiene **_daySet_**

### Funciones del código principal
El código en si no cuenta con tantas funciones como en el header pero si cuenta como un menú principal conformados por ciclos **_do-while_** en que puedes realizar las funciones de agregar, eliminar, buscar y mostrar eventos

- **Agregar eventos.-** Lo que hace lo que me gustaría llamar pseudo-función es crear los eventos a partir de introducir el día, mes y año mediante la funcion **_Date_** de la fecha para luego introducir el evento y se guardaran en un map llamada **_list_** mediante la función **.push_back()** para que se guarde como elemento de un vector que el valor del map, en el que la fecha es la clave y los eventos son los valores de esta.

- **Eliminar eventos.-** Existen 3 tipos de opcciones para elimnar eventos:
  - **Borrar un evento de una fecha.-** Elige una fecha de un evento y la elimina, se puede repetir hasta que se el map se vacie.
  - **Borrar todos los eventos de una fecha en especifico.-** Elige la fecha del evento por su índice para que se eliminen todos los eventos de la fecha seleccionada.
  - **Limpiar la lista.-** Borra toda la lista... es todo JAJAJAJA

- **Imprimir la lista.-** Imprime todas las fechas y eventos que se guardo el map, si no hay nada, mostrará que no hay nada.

- **Buscar eventos de una fecha en especifico.-** Sirve para mostrar todos los evento de una fecha en especifco, buscando la fecha por medio de su índice.

## Pseudocódigo
### Código principal
![Procedimiento Principal_pages-to-jpg-0001](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/94b5ed7a-4a96-4f7b-906b-cdb14b1537b5)
![Procedimiento Principal_pages-to-jpg-0002](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/fc770aed-d4c0-46b0-90f4-34107098442e)
![Procedimiento Principal_pages-to-jpg-0007](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/35514f04-e323-457d-9bfe-8f19d0d86826)
![Procedimiento Principal_pages-to-jpg-0006](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/667bfbb6-c0bb-4b55-a5d4-2cdf93e70991)
![Procedimiento Principal_pages-to-jpg-0005](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/be29fd77-7581-4394-bf38-a9052d2b1eb4)
![Procedimiento Principal_pages-to-jpg-0004](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/2c33a922-37bf-4937-8be4-8f9bfd25a896)
![Procedimiento Principal_pages-to-jpg-0003](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/230a1ce4-7ccc-406e-ab49-e626a4918a29)

### Header Dateset
![Header_page-0003](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/728056c5-ada9-420c-8a00-791dc133484f)
![Header_page-0002](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/45d1a644-d5b6-45c4-9fa0-c2c79a4bce95)
![Header_page-0001](https://github.com/JorgeMartinezSanchez/IALP_Final_Test/assets/159574519/476a65f3-c3dd-4a4e-baf5-d5d6c6b9a096)

## Creditos
Jorge Martínez Sánchez

## Herramientas utilizadas
Visual Studio, un tutorial de maps en yt, y un poco de ChapGPT para probar lógicas de código e implementarlas al código base
