# Modulo Puente H L298 

> Controlador de giro para motores.

---

## Tabla de contenido 
- [Especificaciones ](#Especificaciones )
- [Pines ](#Pines )
- [Dimensiones](#Dimensiones)
- [Características ](#Características)
- [Licencia](#Licencia)

---
## Especificaciones

### Chip: L298N

> Canales: 2 (soporta 2 motores DC o 1 motor PAP)

> Voltaje lógico: 5V

> Voltaje de potencia (V motor): 5V - 35V DC

> Consumo de corriente (lógico): 0 a 36mA

> Capacidad de corriente: 2A (picos de hasta 3A)

> Potencia máxima: 25W


[![](https://github.com/Robotois/robotois-robert/blob/master/specs/images/renders/driver.png)]()

## Pines

- +5 Volts DC 
- GND (0 Volts)
- +12 Volts DC
- Habilitar motor A
- Entrada analógica 1 
- Entrada analógica 2
- Entrada analógica 3
- Entrada analógica 4
- Habilitar motor B


## Dimensiones

> Peso: 30g

> Longitud del motor: 43.5mm

> Ancho del motor: 43.5mm

> Alto del motor: 26mm
 

[![](https://github.com/Robotois/robotois-robert/blob/master/specs/images/measures/L298N%20Motor%20Driver.PNG)]()



## Características

- Voltaje de alimentación, mínimo de 5V. Posee dos entradas, una de 5V para controlar la parte lógica y otra para alimentar las 
salidas al motor, que pueden ser de 5V o más.
- Posee un regulador de voltaje de 5V 78M05, para alimentar la etapa lógica del L298N, sin embargo, cuando la alimentación supera los 12V, 
se recomienda, utilizar una fuente de 5V externa como fuente de alimentación.
- El módulo permite controlar el sentido y velocidad de giro de motores. 
- Admite entradas de señal PWM para el control de velocidad.
- Posee 8 diodos de protección contra corriente inversas.

## Licencia

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2019 © <a href="http://fvcproductions.com" target="_blank">ROBOTOIS</a>.
