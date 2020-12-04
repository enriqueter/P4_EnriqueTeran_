# P4_EnriqueTeran_IsaacVazquez

Para esta practica el funcionamiento deseado, es diseñar e implementar un sistema de tiempo real, el cual procese a traves de 3 filtros (pasa-bajas, pasa-bandas y pasa altas),
señales de audio mediante un Codec.

Se implementaron 3 filtros con las siguientes caracteristicas:
	1. Filtro pasa-bajas, con frecuencia de corte en 300Hz
	2. Filtro pasa-bandas, con frecuencia de corte en 300Hz y 5kHz
	3. Filtro pasa-altas, con frecuencia de corte en 5kHz
	
Los filtros primero se diseñaron en MATLAB  para la obtencion de sus coeficiones los cuales se declararon como arreglo para utilizar despues las funciones declaradas en la libreria CMSIS DSP para generar los 3 filtro con sus frecuencias de corte verificadas en sus graficas en el dominio de la frecuencia en MATLAB.

Se utilizo la UART esto para recibir y mandar comandos, para utilizarlo como una GUI reducida y poder controlar los filtros que se quiere utilizar.

Los filtros de diseñaron en Matlab con la funcion fir, para despues utilizar los valores dentro de unas constantes, esto para dar forma a los filtros deseados.
Se utilizo el protocolo I2C, para la configuracion del Codec.

Se obtuvo informacion del documento de I2S, despues de la inicializacion del Codec no en modo bypass, recibir y mandar audio. Aunque no se pudo establecer la comunicacion.
