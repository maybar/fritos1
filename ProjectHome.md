# Introducción a los RTOS sobre distintas plataformas #

## Objetivo del proyecto ##

Introducción a los RTOS sobre distintas plataformas, para lo que se pretende implementar un mismo proyecto sobre varios RTOS distinos y sobre arquitecturas de 8, 16 y 32bits, a fin de comprobar los rendimientos y capacidades en los distintos entornos.

Es también objetivo del proyecto la realización del mismo mediante un metodología de desarrollo ordenada, documentación exportable con Doxygen e implementación cumpliendo las buenas praxis de codificación.

## RTOS seleccionados ##

Se decide empezar con un RTOS comercial MICRIUM uC-OS-2 y otro completamente GPL FREERTOS puesto que se dispone de documentación de referencia.

## Arquitecturas seleccionadas ##

Dada la disponibilidad actual de entornos de desarrollo se selecciona:
  * 8 bits: Atmel AVR Atmega 2560 (preferiblemente sobre STK500)
  * 16 bits: Microchip DSPIC33F (sobre placa de desarrollo XXXXXX)
  * 32 bits: Intel PXA240 (sobre placa de desarrollo TORADEX) ¿Comprobar que existen los ports)


## Proyectos de aplicación: TODO ##

Se pretende hacer un proyecto que permita analizar las capacidades de los RTOS y en el que se utilicen las herramientas de debugging/trazas/análisis de rendimiento.
Posibles proyectos:
  * Audio + Display + IOs
  * Radiocontrol