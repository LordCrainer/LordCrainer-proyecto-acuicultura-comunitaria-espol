# **PRIMEROS PASOS**

---

### **HERRAMIENTAS A USAR**

[IDE ARDUINO](https://www.arduino.cc/en/software)

[VISUAL CODE](https://code.visualstudio.com/)

### **CONFIGURACIÓN DEL VISUAL CODE**

- Instalar las siguientes extensiones dentro del Visual Code ([Tutorial](https://www.youtube.com/watch?v=BO-nhyqpm7A)👀)

    > Arduino

    > C/C++

- Ir a la ruta para configurar la extensión de arduino
- Barra de opciones (parte superior): Archivo => Preferencias => Settings (Configuración)
- En la barra de búsqueda escribir: Arduino
- En Arduino: Path (Scroll para abajo)
- Copiar la ruta por default del Arduino (C:\Program Files (x86)\Arduino)
- Presionar F1 dentro del Visual Code para mostrar en la parte superior un menú de opciones
- Escribir Arduino en el menú que aparece en la parte de arriba (> Arduino)
- Observar que estén los comandos del Arduino (Arduino: Upload, Arduino: Verify, Arduino: Examples)

**INSTALAR LAS LIBRERÍAS**

- **LIBRERÍA ESP8266 EN ARDUINO**
    - [Video Tutorial](https://www.youtube.com/watch?v=0g7sazWXfEI)
    - [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
    - [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)

**NOTA: Si falta alguna librería tanto el Visual Code como el IDE de Arduino les imprimirá por pantalla el error y tendrían que instalar desde el manejador del  Arduino IDE**

**AÑADIR EL ARCHIVO DE CONFIGURACIÓN DE LA EXTENSIÓN "ARDUINO"**

Se debe de generar el archivo de configuración de la extensión de Arduino en el Visual Code (c_cpp_properties.json).

- Aplastar F1 dentro del Visual Code
- Escribir "Arduino" en el menú que aparece en la parte de arriba (>)
- Seleccionar la opción que dice: "Arduino: Examples"
- Se les abrirá una nueva pestaña den
- Abrir la carpeta dedicado a NodeMCU o ESP8266
- Abrir cualquier ejemplo, y se les abrirá una nueva ventana.
- Copiar el archivo "c_cpp_properties.json" dentro del ./vscode del ejemplo, a la misma carpeta del proyecto.

NOTA: El archivo c_cpp_properties.json, tiene que tener una configuración parecida al siguiente formato.

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

**AGREGAR LAS VARIABLES DE ENTORNO**

La variables de entorno son aquellas que deberían ser ocultas para las demás personas, como ejemplo tenemos: La configuración de la red de un hogar para realizar pruebas

- Copiar el archivo llamado: *env.example.h*
- Renombrarlo a:  *.env*
- Editar las variables acorde a sus preferencias.
- [Ejemplos usando ESP8266](https://github.com/luisllamasbinaburo/ESP8266-Examples/tree/master/22_API_REST_Server)

#### Estructura del programa
* arduino.ino   //Archivo principal del proyecto
* env.h     //Variables de entorno
* ***config/***   //Todas las configuraciones
  * server
  * wifi-config
  * router //rutas del api para comunicarse con el cliente
  * utils //utilidades usadas en todo el proyecto)
  * api.utils.hpp //Funciones para manejar partes del api
  * json.utils.hpp
  * time.utils.hpp
* ***router/***
	* router.hpp  //Reglas o comandos que permite el API REST para comunicarse con el cliente
* ***api/***
	* ***components/***
		* ***device/*** //Activa el dispositivo para una acción específica
			* ***2.adapter/*** 
				* controller.hpp //Recibe las peticiones del cliente, las procesa y devuelve una respuesta
			* ***3.use-case/*** //Lógica de la aplicación, o las acciones que hace el componente
				* start.hpp //Inicia el proceso de censado y guardado de datos
		* ***LCD/***
		* ***measurement/***  //Todo lo relacionado con mediciones o censado (lectura, tratamiento de los datos, etc)
		* ***sd-card/***
			* ***2.adapter/***
				* controller.hpp
			* ***3.use-case/*** //Lógica de la aplicación, o las acciones que hace el componente
				* crudSD //Funciones que puede hacer una SD. (Leer, escribir, borrar, mostrar directorios y archivos, etc)
			* ***4.domain/*** //Es la lódigo del negocio, para tratar los datos u objetos que maneja el proyecto. 
				* dirModel.hpp
				* fileModel.hpp //Modela la estructura y lo convierte en json
				* filename.hpp //Establece el nombre final del archivo
		* ***sensor/*** //Acciones para ejecutar o tratar la información de los sensores.
		* ***share/*** //Area del código con alcance a todos los componentes
			* ***4.domain/***
				* ***interface/*** //Guarda todas las estructuras de todos los componentes
					* measurement.hpp //structura para la medición

# API REST 
---
**¿Qué es una API?**
API es el acrónimo de Application Programming Interfaces, en español sería Interfaz de programación de aplicaciones. Es la agrupación de diferentes funciones ,bibliotecas, procesos y subrutinas que pueden ser integrados en otro software.

**¿Para qué sirve?**

Permite que sus productos y servicios puedan comunicarse con otros de una manera sencilla. Las APIs permiten simplificar el diseño, brindan flexibilidad para ser usado en otros desarrollos, administración de los recursos y dan paso a que la innovación fluya al permitir usar alguna característica en particular. En este caso, la API nos ayuda en la comunicación entre los diferentes periféricos del dispositivo (NodeMCU) a otros dispositivo conectado en la red (celular).

**REST**

REST es un estilo de arquitectura basados en el protocolo HTTP que permite conectar vraios sistemas, como un servidor con un cliente. Para obtener o enviar los datos se puede usar cualquier formato, siendo los más usados XML, JSON.

**API REST**

Es cuando una API usa como arquitectura REST para comunicar entre el cliente y servidor. El cliente envía una petición hacia el servidor mediante algún verbo del http (get, post, put, patch, delete, etc), el servidor recoge esta peitición, realiza la acción correspondiente a la petición y luego devuelve una respuesta hacia el cliente, en algún tipo de formato, en este caso, JSON.

> El Api Rest funciona de manera asíncrona y por eventos. Eso significa que toda petición hecha por el cliente será continuamente escuchada por servidor y luego verificada si coincide con la ruta o acción que permite el servidor, caso contrario deberá de responder con un mensaje de error o que no ha sido encontrada la petición del cliente.

# **ESTRUCTURA DEL PROYECTO**

**ARQUITECTURA**

El proyecto presenta una arquitectura en capas de manera jerárquica, cada capa tiene un fin específico dentro del proyecto y un flujo el cual se debe de respetar, esto significa que las capas superiores únicamente pueden acceder a las inferiores o comunicarse de manera adyacentes a ellas. Por ningún motivo una capa inferior puede acceder a una capa de nivel superior. En otras palabras, cuando se incluye o se usa una función del sistema se debe de considerar en que capa se encuentra. Las capas generales son:

Normalmente las capas que se trabajan serían las siguientes:

> Infraestructura  👉🏿 Adaptadores de interfaz 👉🏿 Casos de uso 👉🏿 Dominio

La capa de infraestructura no se encuentra creada
Para ser usada se debería de separar el componente "sd-card" de componentes y colocarlo la carpeta infraestructura. Así que de momento está implícita pero se le dará un breve explicación.

- **Infraestructura: Servidor y configuraciones**

    La infraestructura es la capa más externa de la arquitectura compuesta por frameworks, herramientas y base de datos, etc (Detalles del sistema). Esta capa es la que se encuentra más cerca del cliente, en otras palabras, primero pasa por esta capa y luego por las demás.

    Ejemplo:

    - **Server**
        Es el que se encarga de levantar el servidor.
    - **Wifi-conf**
        Se encarga de cambiar el comportamiento del adaptador de wifi del equipo, para que trabaje como estación (Station) o punto de acceso (AP)
    - **IniciarSD**
    - **Iniciar LCD**
    Si comparamos en arduino, la infraestructura podría ser todos los procesos que se deben de ejecutar en primera instancia en el setup, antes que cualquier programa.

- **Adaptador de interfaz**

    Se encarga de adaptar los datos que le llegan del cliente hacia los casos de uso y viceversa. Esta capa es la que recibe las peticiones hechas por el cliente y se le devuelve una respuesta.

    * **Router**

        Define las reglas de como el usuario debe de interactuar con el api, se divide en:

        - Ruta: Es la dirección o rama que trabajará el api: /ruta1, /ruta1/subruta2
        - Método: Son los verbos del protocolo a usar, en este caso del Http. Estos pueden ser: get, post, patch, delete, entre otros.
        - Request: Es la petición o datos que el cliente ha enviado al servidor (API), que a su vez es traslada hacia una función de controlador
        - Manejador de funciones: Como último parámetro se puede pasar diferentes funciones que manejarán las peticiones del cliente de manera secuencial.

      Ejemplo:

      ```cpp
      Server.on(“/item”, HTTP_GET, getAllData)
      Server.on(“/item”, HTTP_PUT, *request, null, editConfiguration)
      Server.on(“/item”, HTTP_POST, *request, null, createPool)
      Server.on(“/item”, HTTP_POST, *request, validationPool, createPool)
      ```

      > En el último ejemplo se agrega una función que valida la información en el caso de que el cliente envíe una petición errada. Lo que ocurre que se detenga y devuelva una respuesta. 
      Caso contrario el programa fluiría hacia la siguiente función.

      > No está dentro de una carpeta, sino que se ha colocado de manera general

- **Controlador**

    Esta subcapa se encarga de recibir las peticiones y datos del cliente, devolviendo siempre una respuesta al mismo, en esta respuesta puede ser un mensaje con el estado 200 OK, o un error 404, además que también se puede incluir el dato que el cliente ha solicitado. Aquí no debería de haber nada de la lógica del negocio o extensas funciones, por el contrario, su responsabilidad tiene que ser única.

    Ejemplo de Responsabilidad única

    > Si la función dice: readingMeasurement
    Sólo leerá la información, y no hará otro proceso como borrar, crear o activar algo.

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

**FLUJO DE LA PETICIÓN**

Cliente (Celular) ⇒ Servidor (API REST) ⇒ Router ⇒ Controller ⇒ Casos de uso ⇒ Dominio

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