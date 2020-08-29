PASOS PARA USAR EL PROGRAMA

Para probar el archivo, existen algunos pasos previos y librerías que se deben de instalar

PASO 1)
INSTALAR EL ESP8266 EN ARDUINO IDE
    https://www.youtube.com/watch?v=0g7sazWXfEI

PASO 2) 
INSTALAR LAS SIGUIENTES LIBRERÍAS EN EL ARDUINO IDE
    https://github.com/me-no-dev/ESPAsyncWebServer
    https://github.com/me-no-dev/ESPAsyncTCP


PASO 3)

En la carpeta: 

CARPETA: .vscode
- ARCHIVO: c_cpp_properties.json
    Cambiar las propiedades a las rutas de su sistema
        => Aplastar f1
        => En el recuadro escribir: Arduino
        => Buscar el que dice: Examples
        => Abrir cualquier Examples mostrado: blink.ino
        => Copiar el archivo y pegar    

- ARCHIVO: arduino.json
    Si no está el siguiente comando, colocarlo: "output": "./build"

CARPETA: Arduino
=> Crear el archivo env.h
=> Copiar exactamente el archivo env.example.h
=> Editar las información respectiva a la información que le piden


LIBRERÍAS

INSTALAR EL ESP8266 EN ARDUINO IDE
https://www.youtube.com/watch?v=0g7sazWXfEI

EJEMPLOS USANDO ESP8266
https://github.com/luisllamasbinaburo/ESP8266-Examples/tree/master/22_API_REST_Server