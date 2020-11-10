### HERRAMIENTAS A USAR
- [IDE ARDUINO](https://www.arduino.cc/en/software)
- [VISUAL CODE](https://code.visualstudio.com/)

### INSTALAR LAS LIBRERÍAS
##### - LIBRERÍA ESP8266 EN ARDUINO
- [Video Tutorial](https://www.youtube.com/watch?v=0g7sazWXfEI)
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)

##### PASOS PARA USAR EL PROGRAMA
En la carpeta: 

CARPETA: .vscode
- ARCHIVO: c_cpp_properties.json
    Cambiar las propiedades a las rutas de su sistema
        => Aplastar f1
        => En el recuadro escribir: Arduino
        => Buscar el que dice: Arduino: Examples
        => Abrir cualquier Examples mostrado: blink.ino
        => Copiar el mismo archivo y pegar (c_cpp_properties.json)

- ARCHIVO: arduino.json
    Si no está el siguiente comando, colocarlo: "output": "./build"

CARPETA: Arduino
=> Crear el archivo env.h (variables de entorno)
=> Copiar exactamente el archivo env.example.h
=> Editar las variables de entorno acorde a su preferencia.


LIBRERÍAS

INSTALAR EL ESP8266 EN ARDUINO IDE
https://www.youtube.com/watch?v=0g7sazWXfEI

EJEMPLOS USANDO ESP8266
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
