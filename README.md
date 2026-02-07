# boot
Que hace: Inicializar el sistema y transferir el control al código en C.

los archivos dentro de la carpeta
- root.s
- linker.ld
Esta carpeta es la primera en ejecutarse cuando el programa inicia en QEMU. Se encarga de definir el punto de entrada del programa.

# os
Que hace: Proveer servicios básicos de entrada y salida directamente relacionados con el hardware.

los archivos dentro de la carpeta
- os.h
- os.c
Esta carpeta se centra en abstraer el acceso directo al uart . No interpreta datos ni maneja formatos; únicamente envía y recibe caracteres

# lib
Que hace: Proveer funciones de soporte y librerias de lenguaje independiente del hardware.

los archivos dentro de la carpeta
- string.h 
- string.c
- stdio.h 
- stdio.c

Esta carpeta implementa funcionalidades comunes como manejo de strings y funciones de print y read. No accede directamente al hardware, sino que utiliza la capa os para comunicarse.

# user
Que hace: Contener la lógica del programa

los archivos dentro de la carpeta
- main.c

Esta carpeta implementa la calculadora. Solo utiliza las funciones print y read proporcionadas por los archivos de lib.
Este es el punto de inicio del programa podemos ver que muestra mensajes al usuario usando print. Solicita valores numéricos usando read pueden ser enteros o flotantes


<img width="1716" height="911" alt="image" src="https://github.com/user-attachments/assets/9eb2d648-ddce-434b-a964-e5910f93201a" />
