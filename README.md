### HERRAMIENTAS A USAR
- [IDE ARDUINO](https://www.arduino.cc/en/software)
- [VISUAL CODE](https://code.visualstudio.com/)

### CONFIGURAR EL VISUAL CODE
- INSTALAR LAS SIGUIENTES EXTENSIONES
    * Arduino
    * C/C++
- CONFIGURAR EL LA RUTA DEL ARDUINO
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



El Api Rest funciona de manera asíncrona y por eventos. Eso significa que toda petición hecha por el cliente será continuamente escuchada por servidor y luego verificada si coincide con la ruta y acción que permite el servidor, caso contrario deberá de responder con un mensaje de "No encontrado"

arduino.ino => Es el archivo principal donde ejecutará únicamente 
