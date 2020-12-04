# P4_EnriqueTeran_IsaacVazquez

Para esta practica el funcionamiento deseado, es diseñar e implementar un sistema de tiempo real, el cual procese a traves de 3 filtros (pasa-bajas, pasa-bandas y pasa altas),
señales de audio mediante un Codec.

Se implementaron 3 filtros con las siguientes caracteristicas:
	1. Filtro pasa-bajas, con frecuencia de corte en 300Hz
	2. Filtro pasa-bandas, con frecuencia de corte en 300Hz y 5kHz
	3. Filtro pasa-altas, con frecuencia de corte en 5kHz

Se utilizo la UART esto para recibir y mandar comandos, para utilizarlo como una GUI reducida y poder controlar los filtros que se quiere utilizar.

Los filtros de diseñaron en Matlab con la funcion fir, para despues utilizar los valores dentro de unas constantes, esto para dar forma a los filtros deseados.
Se utilizo el protocolo I2C, para la configuracion del Codec.
