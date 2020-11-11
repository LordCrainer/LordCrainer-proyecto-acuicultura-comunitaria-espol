### HERRAMIENTAS A USAR
- [IDE ARDUINO](https://www.arduino.cc/en/software)
- [VISUAL CODE](https://code.visualstudio.com/)

### CONFIGURAR EL VISUAL CODE
- INSTALAR LAS SIGUIENTES EXTENSIONES
    * Arduino
    * C/C++
- CONFIGURAR LA RUTA DEL ARDUINO
    * Archivo => Preferencias => Settings (Configuración)
    * Escribir: Arduino
    * En Arduino:Path => Copiar la ruta por default del Arduino (C:\Program Files (x86)\Arduino)
   
- REALIZAR LAS PRUEBAS
    * Presionar F1 dentro del Visual Code
    * Escribir Arduino en el menú que aparece en la parte de arriba (>)
    * Observar que estén los comandos del Arduino (Verificar, subir, Serial port)

### INSTALAR LAS LIBRERÍAS
##### - LIBRERÍA ESP8266 EN ARDUINO
- [Video Tutorial](https://www.youtube.com/watch?v=0g7sazWXfEI)
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)

###### NOTA: Si falta algún otra librería el Visual Code o el IDE de Arduino les mostrará el error

#### PASOS PARA USAR EL PROGRAMA

- SE DEBE DE INSERTAR EL ARCHIVO DE CONFIGURACIÓN: c_cpp_properties.json. 
    * Aplastar F1 dentro del Visual Code
    * Escribir Arduino en el menú que aparece en la parte de arriba (>)
    * Seleccionar la opción que dice: "Arduino: Examples"
    * Elegir cualquier proyecto
    * Copiar el archivo "c_cpp_properties.json" de la carpeta ./vscode en la misma del proyecto

- CREANDO EL ARCHIVO QUE CONTIENE LAS VARIABLES DE ENTORNO
    * Copiar el archivo llamado: env.example.h
    * Renombrarlo a: .env
    * Editar las variables acorde a sus preferencias


- EJEMPLOS USANDO ESP8266
    https://github.com/luisllamasbinaburo/ESP8266-Examples/tree/master/22_API_REST_Server


# ESTRUCTURA DEL PROGRAMA

## ARQUITECTURA POR CAPAS

### ESTRUCTURA DEL PROYECTO
- arduino.ino
    - env.h
    - config (Todas las configuraciones)
        * server
        * wifi-config
    - api
        - componentes | api-rest (Todas las funciones externas)
            * device
            * LCD
            * measurement
            * sd-card
            * sensor
        - utils (utilidades generales de la aplicacion)
    - router (rutas del api)
    

## FUNCIONAMIENTO DEL API REST

#### ¿Qué es una API?
API es el acrónimo de Application Programming Interfaces, en español sería Interfaz de programación de aplicaciones. Es la agrupación de diferentes funciones ,bibliotecas, procesos y subrutinas que pueden ser utilizados por otro software. Para la comunicación hacia otros programas, este puede aplicar una variedad de protocolos a través de un conjunto de reglas específicas. 

#### Para que sirve
Permite usar algún tipo de servicio de una manera sencilla sin tener que volver a hacer todo el programa. En este caso, la API nos ayuda en la comunicación entre los diferentes periféricos del dispositivo (NodeMCU) a otros dispositivo conectado en la red (celular).

#### REST
REST es un estilo de arquitectura  basados en el protocolo HTTP que permite conectar vraios sistemas, como un servidor con un cliente. Para obtener o enviar los datos se puede usar cualquier formato, siendo los más usados XML, JSON. 

#### API REST
Es cuando una API usa como arquitectura REST para comunicar entre el cliente y servidor.  El cliente envía una petición hacia el servidor mediante algún verbo del http (get, post, put, patch, delete, etc), el servidor recoge esta peitición, realiza la acción correspondiente a la petición y luego devuelve una respuesta hacia el cliente, en el formato, en este caso, JSON.



El Api Rest funciona de manera asíncrona y por eventos. Eso significa que toda petición hecha por el cliente será continuamente escuchada por servidor y luego verificada si coincide con la ruta o acción que permite el servidor, caso contrario deberá de responder con un mensaje de error o que no ha sido encontrada la petición del cliente. 

### ARQUITECTURA
El proyecto presenta una arquitectura en capas de manera jerárquica, cada capa tiene un fin específico dentro del proyecto y un flujo el cual deben de respetar, como se indicó al ser jerárquico las capas superior únicamente pueden acceder a las inferiores o adyacentes a ellas, por ningún motivo se debería de comunicarse un capa inferior con una superior. En otras palabras, cuando se incluye o se usa una función del sistema se debe de considerar en que capa se encuentra.
Las capas generales son: 
- Infraestructura
- Controlador
- Dominio

- Infraestructura: Servidor y configuraciones
   La infraestructura es todo el proceso encargado de los programas que realizan una actividad general o global del sistema, en este caso, el Server.hpp o wifi-  config.hpp ejecutan el servidor, o activan el modo AP o Station del módulo de Wifi. 
   - Wifi
   - Server
   - Iniciar SD
   - Calibración
   - Inciar LCD

- Controlador: Router y Controlador
   El router es el que da las reglas de como el cliente debe de comunicarse al API.
   - /device/start  GET  startMeasurement
   - /measurement   GET  getALL
   - /measurement/1 GET getByID

   El controlador únicamente debería ser responsable de recibir la petición del cliente, realizar una única acción (Service) y enviar una respuesta al cliente. Para este proyecto no se ha dado el caso de esa manera, sino que el controlador realiza diferentes acciones para lograr su objetivo.

- Dominio: Service
   Se le denomina a todo el código que realiza la lógica del negocio o todas las actividades que el api va a realizar. 
   Se recomienda que los services añadan a otros services para lograr su cometido. 

   SD_CARD
   - Leerá la SD
   - Guardará datos en los ficheros
   - Borrará ficheros 
   - Creará un nuevo fichero

   Measurement
   - Recibe el Id de la piscina que se desea obtener
   - Busca en la SD Card los datos de la piscina deseada.
   - returna el valor

   DEVICE
   - start (opcional)
      * Muestra el temporizador del tiempo antes de comenzar a sensar en la LCD
      * Activa el sensado de todos los sensores
      * Guarda los datos en la SD (tener cuidado del tiempo de sensado y el grabado de los datos)
      * Envía una respuesta indicando que todo ha funcionado correctamente



##### FLUJO DE LA PETICIÓN
Cliente => Servidor (API REST) => Router => Controller => Service

##### DESCRIPCIÓN DE CADA CARPETA
En la carpeta principal: Arduino
- Estará todas carpetas y archivos principales
   - arduino.ino => Es el archivo principal donde se llamará a todo el programa y librerías.
   - env.example.h => Un ejemplo a seguir para usar las variables de entorno
   - .env => Es el archivo donde se encuentran las variables propias de todo el sistema y son de caracter confidencial

- Subcarpeta: API
   * En esta carpeta se encuentra el código responsable de toda la API, manejo de librerías y periféricos.
      * components: Está el código responsable de la actividad principal del proyecto: medición, sensado, sd card, lcd
      * utils: Es la carpeta de utilidades que ayuda de manera general a la carpeta de componentes.
- Subcarpeta: config
   * Código responsable de la configuración del Wifi y Servidor
- Subcarpeta: router
   * Todas las rutas del api rest se encuentran alojadas en esta carpeta, junto a la funciones(controlador) que debe de ejecutar)
