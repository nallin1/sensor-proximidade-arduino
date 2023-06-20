/*
 * Guilherme Garcia Nallin
 * Vitor Baltazar Bergamini
 * 3 TDSMD 
 */

#include <Ultrasonic.h>

#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 9
#define TRIGGER 11
#define ECHO 12
#define BUZZER 3
 
const float limite1 = 30.0; // Limites de distância em cm
const float limite2 = 20.0;
const float limite3 = 10.0;
const float limite4 = 5.0;

Ultrasonic ultrassom(11,12);

void setup() {
 
// Inicie a comunicação Serial a 9600bps
Serial.begin(9600);
 
// Modo de entrada / saída do pino
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(ECHO, INPUT);
pinMode(TRIGGER, OUTPUT);
pinMode(BUZZER, OUTPUT);
 
// Função que desliga os LEDs
desligarLEDs();
 
}
 
void loop() {
 
// Inicializa o sensor ultrassônico
inicializarTrigger();
 
// Obtenha a distância
float distancia = calcularDistancia();
 
// Desligar os LEDs
desligarLEDs();
 
// Alerta se estiver dentro da zona de perigo
if (distancia < limite1){
// Dispara os alertas
alertas(distancia);
}
 
}
 
// Função de desligar os LEDs
void desligarLEDs()
{
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
}
 
// Verifique se algum alerta visual ou sonoro é necessário
void alertas (float distancia){
 
//entre o limite1 e o limite2
if (distancia < limite1 && distancia >= limite2){
 
// Ligue o LED 1
digitalWrite(LED1, HIGH);
tone(BUZZER, 500, 50);
}
 
//entre o limite2 e o limite3
else if (distancia < limite2 && distancia >= limite3){

// Ligue o LED 2
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
tone(BUZZER, 1000, 100);
}
 
// Se a distância estiver entre o limite3 e o limite4
else if (distancia < limite3 && distancia >= limite4){
 
// Ligue o LED 3
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
tone(BUZZER, 1200, 150);
}
 
// menor que o limite4
else if (distancia < limite4){
 
// Ligue o LED 4
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
digitalWrite(LED4, HIGH);
tone(BUZZER, 1500, 200);
}
}
 
// Função usada para calcular a distância
float calcularDistancia(){
float distancia = ultrassom.Ranging(CM);
Serial.print(distancia);
Serial.print(" cm");
Serial.println("");
return distancia;
}

void inicializarTrigger(){
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);
}
