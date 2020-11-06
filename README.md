PASOS PARA USAR EL PROGRAMA

NOTA: Para probar el proyecto, existen algunos pasos previos y librerías que se deben de instalar

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


