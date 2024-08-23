#include <Arduino.h>

int numero = 10; //Variable Global, se puede usar en cualquier funcion del archivo

void duplicar(int * puntero); //Prototipo de la funcion duplicar
//Este es el punto de entrada del programa, donde arranca
//Sirve para inicializar las variables y configuraciones

void setup() { // 10KHZ es el maximo ancho de banda de una linea telefonica: 10000 bits por segundo
  Serial.begin(115200); // [9600 bps] potencias de 2, 1200 bps, 24000 bps baudios, bits por segundo Configurar la velocidad del puerto serial
}                     //depende del largo del cable

//Este es el loop principal del programa
//Se eecuta despues de que el setup termina
void loop() {
  //ln enter al final
  Serial.println("numero = "+String(numero)); // Imprime: numero = 10 se concatena ambos estrings al convertir el numero a string
  duplicar(&numero); // & Ampemsar numero significa que le paso la direccion de memoria de la variable numero 
                      //ubicacion de memoria de una variable sin necesidad de conocerla desde antes
                      //direccion de memoria donde hay un puntero 
  delay(1000); // 1 segundo de espera                    
  //Serial.println(numero); //Imprime numero = 10 
 
}
//El operador direccion de memoria $ se utiliza para obtener la direccion de memoria de una variable
//El operador  indireccion se utiliza para acceder al valor de la direccion de memoria que se le pasa

void duplicar(int * puntero){ // &numero se pone asi para construir la funcion
    * puntero = * puntero * 2; //se agsede al valor de  la direccion de memoria que pasaron
    Serial.println("[duplicar] numero = "+String(* puntero)); // Imprime: numero = 20
}


//extension .a es una biblioteca estatica