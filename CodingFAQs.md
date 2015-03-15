# FAQs #

  * **¿por qué es mejor hacer una máquina de estados con SWITCH en lugar de evaluar las condiciones con IF?**
> Por mera velocidad de ejecución. Es relativo al numero de casos. Para 2 o incluso 3, el IF está bien. EN el resto SWITCH.


  * **¿hasta que punto usar los DEFINEs? ¿en que casos usar MACROS?**
Esto creo que va más relacionado con tus tendencias de pogramación.
En general Un DEFINE/MACRO se expande en tiempo de compilacion en la zona de código que lo llame. Así pues si una macro se llama muchas veces, sustitúllela por una función. A no ser que esa macro la hagas en ASM, para generar por ejemplo ciclos de RETARDO....

  * **¿cómo dejar los pines que no están conectados, sin configurar, alta impedancia, como salida?**
> Evidentemente, esto es propio de cada micro y si es medianamente decente aparecerá en el Datasheet. No obstante, si tienes el esquemático interno del micro en cuestión, lo pondrás según aplicación de tal manera que consigas leer un estado real y que este además sea el de mínimo consumo, por aquello de que los puertos de los micros tienen limitada la corriente máxima consumida/cedida y por lo tanto un pin que no usas no tiene que robarte corriente que podrías emplear en otro pin de ese mismo puerto.