Definición del Proyecto: Sistema de Monitoreo de Entrenamiento Indoor con ESP32-CAM

Este proyecto es para la creación de un sistema embebido con ESP32, que sirva para monitorear entrenamientos de bicicleta sobre rodillo en interiores.

El hardware principal es una placa ESP32-CAM genérica (similar a la Aithinker).

Características del sistema

    Debe medirse la velocidad de avance en km/h, con opción de conversión a millas por hora (mph).

    La velocidad requiere como parámetro el diámetro de la rueda para realizar la conversión de vueltas a distancia recorrida.

    La medición de la velocidad se realiza mediante sensores de efecto Hall.

    Debe mostrarse la cadencia de pedaleo (en RPM).

    Tanto la velocidad como la cadencia deben mostrar 0 si la bicicleta no está en movimiento.

    Los resultados se deben publicar en una página web servida por el propio ESP32, mediante un servidor HTTP embebido.

    Los datos deben actualizarse cada 1 segundo.

    El sistema debe entrar en modo deep sleep cuando no hay movimiento detectado por 5 minutos.

    Todos los datos se deben registrar en archivos almacenados en la tarjeta microSD conectada al ESP32.

    Los datos también podrán visualizarse mediante una pantalla TFT de dos colores (o al menos debe dejarse preparada la arquitectura para que esto sea posible a futuro).




Por hacer : 
Meter los valores a un array para que se muestren los cambios paulatinamente
La frecuencia de actualizacion puede estar basada en el valor minimo que se espera del sensor para cada uno, cadencia y velocidad. 
Se debe tener en consideracion que el diametro de la rueda es el parametro que debe recibir el sistema. 
Se debe implementar un wakeup y un ingreso al modo de deep-sleep para ahorrar bateria
Se debe implementar el guarddao automatico de los registros 
Se debe tener en consideracion el registro de las ubicaciones del gps 