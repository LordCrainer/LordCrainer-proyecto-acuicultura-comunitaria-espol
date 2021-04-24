## Tabla de Contenidos
1. [Primeros pasos](#1-primeros-pasos)
<br/>
    <br/>1.1 [Herramientas a usar](#11-herramientas-a-usar)
    <br/>1.2 [Configuraciones generales del proyecto](#12-configuraciones-generales-del-proyecto)
2. [Estructura del proyecto](#2-estructura-del-proyecto)
3. [API REST](#3-api-rest)

---
# `1. Primeros pasos`
------------------------
#### 1.1 Herramientas a usar

* [IDE ARDUINO](https://www.arduino.cc/en/software)
* [VISUAL CODE](https://code.visualstudio.com/)

#### 1.2 Configuraciones generales del proyecto

- **Arduino**
    - **Instalar Las Librerías De esp8266 en arduino**
        - [Video Tutorial](https://www.youtube.com/watch?v=0g7sazWXfEI)
        - [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
        - [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)
        <br/>

        > 📄 **NOTA: 
        Si falta alguna librería tanto el Visual Code como el IDE de Arduino les imprimirá por pantalla el error y tendrían que instalar desde el manejador del  Arduino IDE**

- **Visual Code**
    - **Instalar Y Configurar Las Extensiones**
        - Instalar las siguientes extensiones dentro del Visual Code (👀[Tutorial](https://www.youtube.com/watch?v=BO-nhyqpm7A))
            * Arduino
            * C/C++
        - Ir a la ruta para configurar la extensión de arduino
        - Barra de opciones (parte superior): Archivo => Preferencias => Settings (Configuración)
        - En la barra de búsqueda escribir: Arduino
        - En Arduino: Path (Scroll para abajo)
        - Copiar la ruta por default del Arduino (C:\Program Files (x86)\Arduino)
        - Presionar F1 dentro del Visual Code para mostrar en la parte superior un menú de opciones
        - Escribir Arduino en el menú que aparece en la parte de arriba (> Arduino)
        - Observar que estén los comandos del Arduino (Arduino: Upload, Arduino: Verify, Arduino: Examples)
        <br/>

    - **Configuración De La Extensión "ARduino"**
        Se debe de generar el archivo de configuración de la extensión de Arduino en el Visual Code (c_cpp_properties.json).
        - Aplastar F1 dentro del Visual Code
        - Escribir "Arduino" en el menú que aparece en la parte de arriba (>)
        - Seleccionar la opción que dice: "Arduino: Examples"
        - Se les abrirá una nueva pestaña den
        - Abrir la carpeta dedicado a NodeMCU o ESP8266
        - Abrir cualquier ejemplo, y se les abrirá una nueva ventana.
        - Copiar el archivo "c_cpp_properties.json" dentro del ./vscode del ejemplo, a la misma carpeta del proyecto.

        > 📄 **NOTA:
         El archivo c_cpp_properties.json, debe de tener una configuración parecida al siguiente formato.**

        ```json
        {
            "configurations": [
                {
                    "name": "Win32",
                    "defines": [
                        "ARDUINO=10800"
                    ],
                    "includePath": [
                        "${workspaceRoot}",
                        "C:\\Users\\camog\\AppData\\Local\\Arduino15\\packages\\esp8266\\hardware\\esp8266\\2.7.4\\**",
                        "C:\\Users\\camog\\AppData\\Local\\Arduino15\\packages\\esp8266\\tools\\**",
                        "C:\\Program Files (x86)\\Arduino\\hardware\\tools\\**",
                        "C:\\Program Files (x86)\\Arduino\\libraries\\**",
                        "C:\\Documents\\Arduino\\hardware\\tools\\**",
                        "C:\\Documents\\Arduino\\libraries\\**"
                    ],
                    "forcedInclude": [],
                    "intelliSenseMode": "clang-x64",
                    "cStandard": "c11",
                    "cppStandard": "c++17",
                    "compilerPath": "/usr/bin/gcc"
                }
            ],
            "version": 4
        }
        ```

    - **Agregar Las Variables De Entorno**
        La variables de entorno son aquellas que deberían ser ocultas para las demás personas, como ejemplo tenemos: La configuración de la red de un hogar para realizar pruebas

        - Copiar el archivo llamado: *env.example.h*
        - Renombrarlo a:  *.env*
        - Editar las variables acorde a sus preferencias.
        - [Ejemplos usando ESP8266](https://github.com/luisllamasbinaburo/ESP8266-Examples/tree/master/22_API_REST_Server)

---
# `2. Estructura del Proyecto`
----

#### 2.1 Arquitectura del programa
El proyecto presenta una arquitectura por capas de manera jerárquica para la parte del API REST (api/). Cada capa tiene un fin específico dentro del proyecto y un flujo el cual se debe de respetar, esto significa que las capas superiores únicamente pueden acceder a las inferiores o comunicarse de manera adyacentes a ellas. Por ningún motivo una capa inferior puede acceder a una capa de nivel superior. 
En otras palabras, cuando se incluye o se usa una función del sistema se debe de considerar en que capa se encuentra.

Normalmente las capas que se trabajan serían las siguientes:

> ☁ Infraestructura  ➡ 🔗 Adaptadores de interfaz ➡ 🛒 Casos de uso ➡ 📦 Dominio

Pero en esta ocasión la capa de infraestructura está omitida: 
>🔗 Adaptadores de interfaz ➡ 🛒 Casos de uso ➡ 📦 Dominio

<br/>

- **Infraestructura: Servidor y configuraciones**

    La infraestructura es la capa más externa de la arquitectura compuesta por frameworks, herramientas y base de datos, etc (Detalles del sistema). Esta capa es la que se encuentra más cerca del cliente, en otras palabras, primero pasa por esta capa y luego por las demás.
    Ejemplos: 
    * `Server.hpp`        ➡ Activa el servidor
    * `sd-card.hpp`       ➡ Funciones para manejar la base de datos
    <br/>
    > No se encuentran en su capa correspondiente

<br/>

- **Adaptador de interfaz**

    Se encarga de adaptar los datos que le llegan del cliente hacia los casos de uso y viceversa. Esta capa es la que recibe las peticiones hechas por el cliente y se le devuelve una respuesta.

    * **Router**

        Define las reglas de como el usuario debe de interactuar con el api, se divide en:

        - `Ruta`
        Es la dirección o rama que trabajará el api: /ruta1, /ruta1/subruta2
        - `Método`: 
        Son los verbos del protocolo a usar, en este caso del Http. Estos pueden ser: get, post, patch, delete, entre otros.
        - `Request`
        Es la petición o datos que el cliente ha enviado al servidor (API), que a su vez es traslada hacia una función de controlador
        - `Manejador de funciones`
         Son las funciones que se ejecutan para realizar la acción solicitada por el cliente.
         
        Ejemplo:

        ```cpp
        Server.on(“/item”, HTTP_GET, getAllData)
        Server.on(“/item”, HTTP_PUT, *request, null, editConfiguration)
        Server.on(“/item”, HTTP_POST, *request, null, createPool)
        Server.on(“/item”, HTTP_POST, *request, validationPool, createPool)
        ```

        > **En el último ejemplo se agrega una función que valida la información en el caso de que el cliente envíe una petición errada. Lo que ocurre que se detenga y devuelva una respuesta. 
        Caso contrario el programa fluiría hacia la siguiente función.**

    - **Controlador**

        Esta subcapa se encarga de recibir las peticiones y datos del cliente, devolviendo siempre una respuesta al mismo, en esta respuesta puede ser un mensaje con el estado 200 OK, o un error 404, además que también se puede incluir el dato que el cliente ha solicitado. Aquí no debería de haber nada de la lógica del negocio o extensas funciones, por el contrario, su responsabilidad tiene que ser única.

        Ejemplo de Responsabilidad única

        > <br/>**Si la función dice:** 
        ***readingMeasurement***
        **Sólo leerá la información, y no hará otro proceso como borrar, crear o activar algo.**
        <br/>

<br/>

- **Casos de uso**

    Esta capa es donde están todas las reglas del negocio o las funciones generales de lo que hace el proyecto. Su responsabilidad es la de ensamblar las diferentes funciones y servicios para resolver una solución en concreto. Hay que saber que sólo recibe datos, ejecuta varias funciones y devuelve más datos.

    Ejemplo:

    Si queremos que el API permita iniciar el proceso de medición de los parámetros de entrada (temperatura, ph, oxígeno) necesitamos ejecutar ciertas funciones de manera ordenada para satisfacer la solución, y estas pueden ser:

    - Recibir el id de la piscina a censar.
    - Verificar si existe el archivo para guardar los datos, caso contrario crearlo
    - Obtener los valores de configuración
    - Iniciar el conteo regresivo para su medición
    - Iniciar con el censado
    - Guardar en la SD
    - Chequear si el tiempo o la cantidad de muestras llegó al valor máximo
    - Devolver una respuesta al cliente

    Como podemos notar, la aplicación deberá de ejecutar una serie de procesos o funciones para solucionar un caso en particular, cada una de estas funciones, por lo general, pertenecen a la misma capa.

#### 2.2 Estructura del programa
```markdown 
📄 arduino.ino                          ℹ Archivo principal del proyecto
📄 env.h                                ℹ Variables de entorno
📂 config/                              ℹ Todas las configuraciones
|- 📄 Server.hpp                        ℹ Servidor Web
|- 📄 lcd-config.hpp
|- 📄 wifi-config

📂 router/
|- 📄 router.hpp                        ℹ Reglas o comandos que permite el API REST para comunicarse con el cliente

📂 api/
|- 📂 utils                             ℹ utilidades usadas en todo el proyecto)
    |- 📄 api.utils.hpp                 ℹ Funciones para manejar partes del api
    |- 📄 json.utils.hpp
    |- 📄 time.utils.hpp

|- 📂 components/
    |- 📂 device/                       ℹ Activa el dispositivo para una acción específica
        |- 📂 2.adapter/ 
            |- 📄 controller.hpp        ℹ Recibe las peticiones del cliente, las procesa y devuelve una respuesta
        |- 📂 3.use-case/               ℹ Lógica de la aplicación, o las acciones que hace el componente
            |- 📄 start.hpp             ℹ Inicia el proceso de censado y guardado de datos
    |- 📁 LCD/
    |- 📁 measurement/                  ℹ Todo lo relacionado con mediciones o censado (lectura, tratamiento de los datos, etc)
    |- 📂 sd-card/
        |- 📂 2.adapter/
            |- 📄 controller.hpp
        |- 📂 3.use-case/               ℹ Lógica de la aplicación, o las acciones que hace el componente
            |- 📄 crudSD                ℹ Funciones que puede hacer una SD. (Leer, escribir, borrar, mostrar directorios y archivos, etc)
        |- 📂 4.domain/                 ℹ Es la lódigo del negocio, para tratar los datos u objetos que maneja el proyecto. 
            |- 📄 dirModel.hpp
            |- 📄 fileModel.hpp         ℹ Modela la estructura y lo convierte en json
            |- 📄 filename.hpp          ℹ Establece el nombre final del archivo
    |- 📁 sensor/                       ℹ Acciones para ejecutar o tratar la información de los sensores.
    |- 📂 share/                        ℹ Area del código con alcance a todos los componentes
        |- 📂 4.domain/
            |- 📂 interface/            ℹ Guarda todas las estructuras de todos los componentes
                |- 📄 measurement.hpp   ℹ structura para la medición
```

#### 2.3 Flujo del programa

> <br/> Cliente (Celular) ➡ Servidor (API REST) ➡ Router ➡ Controller ➡ Casos de uso ➡ Dominio
<br/>

* **Cliente**
    * Envía la petición desde un equipo hacia el servidor
    * La petición es la siguiente: 
        * **Type:**  GET
        * **URL:** http://IP_NODEMCU/directory_sd`
<br/>

* **Servidor (API REST)**
    * El servidor escucha la petición y buscará en **``router.hpp``** la que coincide
<br/>

* **Router**
    * De la ruta se dirije al **``controller``** que ejecutará sóla una función (**`use-case`**)
        *  **Ruta:** Arduino/router/router.hpp
        * **``server.on("/directory_sd", HTTP_GET, directorySD)``**
<br/>

* **Controller**
    * Dentro del controller se redirije hacia la función **`directorySD`**, el cual sólo debería de ejecutar un proceso (**`printDirectory`**) y devolver una respuesta al cliente.
        *  **Ruta:** Arduino/api/sd-card/4.adapter/controller.hpp
        <br/>
    > *La función devuelve una seria de objetos anidados ("{},{}") por una ",". Por eso se debe de encerrar en corchetes*

<br/>

* **Casos de Uso**
    * La función **`printDirectory`** entrará en un ciclo continuo hasta que no encuentre más datos, dentro del bucle preguntará si es un directorio o es un archivo. Para cada caso irá al dominio a modelarlos para devolver un archivo en formato "JSON" y luego concatenarlo.
        * Ruta: **`/Arduino/api/sd-card/3.use-case/crudSD.hpp`**
    <br/>
    > *La función tiene la responsabilidad única de buscar directorio y archivos para ser devueltos, no cumple otra función externa o ajena a su responsabilidad.*

<br/>

* **Dominio**
    * En este caso el Caso de uso, solo necesita modelar los datos para dos modelos. Por eso que se dirije a `dir.model.hpp` para los directorios y a `file.model.hpp` para los archivos. 
         * Ruta: `/Arduino/api/sd-card/4.domain/dir.model.hpp` 
         * Ruta: `/Arduino/api/sd-card/4.domain/file.model.hpp` 


---
# 3. API REST 
---
#### 3.1 ¿Qué es una API?
API es el acrónimo de Application Programming Interfaces, en español sería Interfaz de programación de aplicaciones. Es la agrupación de diferentes funciones ,bibliotecas, procesos y subrutinas que pueden ser integrados en otro software.

#### 3.2 ¿Para qué sirve?
Permite que sus productos y servicios puedan comunicarse con otros de una manera sencilla. Las APIs permiten simplificar el diseño, brindan flexibilidad para ser usado en otros desarrollos, administración de los recursos y dan paso a que la innovación fluya al permitir usar alguna característica en particular. En este caso, las APIs nos ayuda en la comunicación entre los diferentes periféricos del dispositivo (NodeMCU) a otros dispositivo conectado en la red (celular).

3.3 REST
REST es un estilo de arquitectura basados en el protocolo HTTP que permite conectar vraios sistemas, como un servidor con un cliente. Para obtener o enviar los datos se puede usar cualquier formato, siendo los más usados XML, JSON.

#### 3.4 API REST
Es cuando una API usa como arquitectura REST para comunicar entre el cliente y servidor. El cliente envía una petición hacia el servidor mediante algún verbo del http (get, post, put, patch, delete, etc), el servidor recoge esta peitición, realiza la acción correspondiente a la petición y luego devuelve una respuesta hacia el cliente, en algún tipo de formato, en este caso, JSON.

#### 3.5 Principios de operación
El servidor web trabaja de manera asíncrona, el cual se mantiene escuchando a la espera de alguna petición por parte del cliente. Tiene la capacidad de manejar varias conexiones al mismo tiempo. 

> <br/>En perspectiva es como las interrucciones en un microcontrolador, que se mantienen a la espera de una acción. Y puede salir de un código secuencial en cualquier momento, incluso de un delay. 
<br/>

Es importante aclarar que el servidor no se ejecuta dentro del void loop(), dado que estaría trabajando de manera "paralela" por es importante evitar el uso de funciones dentro del servidor, que puedad provocar que el equipo se quede en stand by, como: delay, yield, entre otros parecidos.

Pasos que realiza el servidor
* Escucha las conexiones
* Envuelve la petición del cliente en REQUEST
* Realiza un seguimiento de los clientes y limpia la memoria
* Gestiona los `Rewrites` y las aplica en la URL de la solicitud (tipo, url, parametros, versión http, etc)
* Administra los `Handler (Controladores)` y los adjunta en la solicitud

#### 3.6 DOCUMENTACIÓN DEL API REST

`TYPE: `GET
`URL: ` http://IP_NODEMCU/directory_sd
`OUTPUT: `
```JSON
{
    "name": ""
}
```
## **BIBLIOGRAFÍA**

[http://aitorrm.github.io/t%C3%A9cnicas%20y%20metodolog%C3%ADas/arquitectura_software_limpia/](http://aitorrm.github.io/t%C3%A9cnicas%20y%20metodolog%C3%ADas/arquitectura_software_limpia/)

[http://aitorrm.github.io/t%C3%A9cnicas%20y%20metodolog%C3%ADas/arquitectura_software_limpia/](http://aitorrm.github.io/t%C3%A9cnicas%20y%20metodolog%C3%ADas/arquitectura_software_limpia/)

[https://medium.com/@BryanSBarrios/arquitectura-limpia-para-el-resto-de-nosotros-440a4fba4d92](https://medium.com/@BryanSBarrios/arquitectura-limpia-para-el-resto-de-nosotros-440a4fba4d92)

[https://github.com/jbuget/nodejs-clean-architecture-app](https://github.com/jbuget/nodejs-clean-architecture-app)

[https://github.com/royib/clean-architecture-node/blob/master/src/frameworks/persistance/InMemory/InMemoryStudentRepository.js](https://github.com/royib/clean-architecture-node/blob/master/src/frameworks/persistance/InMemory/InMemoryStudentRepository.js)

# **ARDUINO JSON**

Es una librería que permite codificar y decodificar los datos en formato JSON.

**Página Oficial:** [https://arduinojson.org/](https://arduinojson.org/)

**Asistente:** [https://arduinojson.org/v6/assistant/](https://arduinojson.org/v6/assistant/)

### **Serielize**

Es el proceso que genera documentos en formato JSON.

```jsx
String output;
int sizeDoc // Usar el asistente de ArduinoJson para saber el tamaño
DynamicJsonDocument doc(sizeDoc);
doc["name"] = "COMUNITARIAS";
doc["id"] = 10;
serielizeJson(doc, output);
// output => {"name": "COMUNITARIAS", "id": 10}
```

### **Deserielize**

Extrae la información desde un documento de JSON.

```jsx
String input = "{\"name\": \"COMUNITARIAS\", \"id\": 10}"; // \" => "
int sizeDoc = input.length();
DynamicJsonDocument doc(sizeDoc)
DeserializationError err = deserilezejson(doc, input);
// Manejo de errores
if (err) {
Serial.print(F("deserializeJson() failed with code "));
Serial.println(err.c_str());
}

String name = "COMUNITARIAS";
byte id = 10;
```