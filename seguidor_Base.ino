//*********PARAMTROS A CALIBRAR *************************************************************************************************
#include<Servo.h>

Servo fan;
int velocidad =205; // Velocidad crucero de robot max 255

float Kp = 2; // calibracion proporciona0.7
float Kd = 9.97;  //  calibracion derivativo9.65

int frente =  200;   // Velocidad a la que ira el motor hacia adelante cuando pierda la linea max 255
int reversa = 178;  // Velocidad a la que ira el motor hacia atras cuando pierda la linea    max 255

int color = 1;      // 1 linea negra 2 linea blanca
//********CONEXION DE PUERTOS****************************************************************************************************
int OP = A4;   // A0 conectdado a OP    SALIDA DEL MULTIPLEXOR
int S0 = A0;   // A4 conectado a S0     S0 DEL MULTIPLEXOR
int S1 = A1;   // A3 conectado a S1     S1 DEL MULTIPLEXOR
int S2 = A2;   // A1 conectado a S2     S2 DEL MULTIPLEXOR
int S3 = A3;   // A2 conectado a S3     S3 DEL MULTIPLEXOR
int led = 13;  // Led default de Arduino

int pini = 10;
int pwmi = 11;
int pind = 9;
int pwmd = 3;

int go = 8;   // Puerto donde se conecta el arrancador ( si el modulo no esta conectado, debe ponerse una resistencia pull-down)
int rdy = 12;
int boton_izq = 4; // boton izquierdo
//int boton_der = 7; // boton derecho
//int lon = 11;
//*******VARIABLES A UTILIZAR****************************************************************************************************



int mins1 = 255, mins2 = 255, mins3 = 255, mins4 = 255, mins5 = 255, mins6 = 255, mins7 = 255, mins8 = 255, mins9 = 255, mins10 = 255, mins11 = 255, mins12 = 255, mins13 = 255, mins14 = 255, mins15 = 255, mins16 = 255;

int maxs1 = 0, maxs2 = 0, maxs3 = 0, maxs4 = 0, maxs5 = 0, maxs6 = 0, maxs7 = 0, maxs8 = 0, maxs9 = 0, maxs10 = 0, maxs11 = 0, maxs12 = 0, maxs13 = 0, maxs14 = 0, maxs15 = 0, maxs16 = 0;

int valor_sensor1 = 0, valor_sensor2 = 0, valor_sensor3 = 0, valor_sensor4 = 0, valor_sensor5 = 0, valor_sensor6 = 0, valor_sensor7 = 0, valor_sensor8 = 0;

int valor_sensor9 = 0, valor_sensor10 = 0, valor_sensor11 = 0, valor_sensor12 = 0, valor_sensor13 = 0, valor_sensor14 = 0, valor_sensor15 = 0, valor_sensor16 = 0;

int valor_bd = 0, state_go = 0, state_rdy = 0, allow_off = 0, valor_bi = 0, memory_deg = 0, posicion = 0, MUESTREO = 1, sensibilidad = 100, c = 0, espera = 0, modo = LOW, value_x = 0;
int vel = 0;
unsigned long presente = 0;
long antes = 0;
long pausa = 70;
unsigned long pasado = 0;
unsigned long ahora;
double ERROR_POSICION = 0;
double ERROR_ULTIMO = 0;
double CX = 0;







void setup()
{
fan.attach(6);
fan.writeMicroseconds(0);
  pinMode ( led, OUTPUT);
 // pinMode(lon, OUTPUT);
  pinMode ( S0, OUTPUT);
  pinMode ( S1, OUTPUT);
  pinMode ( S2, OUTPUT);
  pinMode ( S3, OUTPUT);
  pinMode ( OP, INPUT);
  pinMode ( go, INPUT);
  pinMode ( boton_izq, INPUT);
//  pinMode ( boton_der, INPUT);
  pinMode(rdy, INPUT);

  pinMode(pini, OUTPUT);
  pinMode(pwmi, OUTPUT);
  pinMode(pind, OUTPUT);
  pinMode(pwmd, OUTPUT);
  //digitalWrite(lon, HIGH);

rutina1:
  
  delay(1000);
  digitalWrite ( led, HIGH);

rutina2:
  lectura();
  if ( valor_bi == LOW ) {
    value_x = 1;
  }
  if ( valor_bi == HIGH && value_x == 1 ) {
    delay (50);
    goto rutina3;
  }
  goto rutina2;


  //****************************************************************************************************************************************************************************


rutina3:   // Calibracion de sensores

  while ( espera < 4000) {
    lectura();
    if ( valor_bi == LOW ) {
      espera = 5000;
    }
    presente = millis();
    if (presente - antes > pausa) {
      antes = presente;
      if (modo == LOW) {
        modo = HIGH;
      }
      else {
        modo = LOW;
      }
      digitalWrite(led, modo);
    }




    if (valor_sensor1 <  mins1) {
      mins1 = valor_sensor1;
    }
    if (valor_sensor2 <  mins2) {
      mins2 = valor_sensor2;
    }
    if (valor_sensor3 <  mins3) {
      mins3 = valor_sensor3;
    }
    if (valor_sensor4 <  mins4) {
      mins4 = valor_sensor4;
    }
    if (valor_sensor5 <  mins5) {
      mins5 = valor_sensor5;
    }
    if (valor_sensor6 <  mins6) {
      mins6 = valor_sensor6;
    }
    if (valor_sensor7 <  mins7) {
      mins7 = valor_sensor7;
    }
    if (valor_sensor8 <  mins8) {
      mins8 = valor_sensor8;
    }
    if (valor_sensor9 <  mins9) {
      mins9 = valor_sensor9;
    }
    if (valor_sensor10 <  mins10) {
      mins10 = valor_sensor10;
    }
    if (valor_sensor11 <  mins11) {
      mins11 = valor_sensor11;
    }
    if (valor_sensor12 <  mins12) {
      mins12 = valor_sensor12;
    }
    if (valor_sensor13 <  mins13) {
      mins13 = valor_sensor13;
    }
    if (valor_sensor14 <  mins14) {
      mins14 = valor_sensor14;
    }
    if (valor_sensor15 <  mins15) {
      mins15 = valor_sensor15;
    }
    if (valor_sensor16 <  mins16) {
      mins16 = valor_sensor16;
    }

    if (valor_sensor1 >  maxs1) {
      maxs1 = valor_sensor1;
    }
    if (valor_sensor2 >  maxs2) {
      maxs2 = valor_sensor2;
    }
    if (valor_sensor3 >  maxs3) {
      maxs3 = valor_sensor3;
    }
    if (valor_sensor4 >  maxs4) {
      maxs4 = valor_sensor4;
    }
    if (valor_sensor5 >  maxs5) {
      maxs5 = valor_sensor5;
    }
    if (valor_sensor6 >  maxs6) {
      maxs6 = valor_sensor6;
    }
    if (valor_sensor7 >  maxs7) {
      maxs7 = valor_sensor7;
    }
    if (valor_sensor8 >  maxs8) {
      maxs8 = valor_sensor8;
    }
    if (valor_sensor9 >  maxs9) {
      maxs9 = valor_sensor9;
    }
    if (valor_sensor10 >  maxs10) {
      maxs10 = valor_sensor10;
    }
    if (valor_sensor11 >  maxs11) {
      maxs11 = valor_sensor11;
    }
    if (valor_sensor12 >  maxs12) {
      maxs12 = valor_sensor12;
    }
    if (valor_sensor13 >  maxs13) {
      maxs13 = valor_sensor13;
    }
    if (valor_sensor14 >  maxs14) {
      maxs14 = valor_sensor14;
    }
    if (valor_sensor15 >  maxs15) {
      maxs15 = valor_sensor15;
    }
    if (valor_sensor16 >  maxs16) {
      maxs16 = valor_sensor16;
    }

  }  // Termina calibracion de sensores


  digitalWrite ( led, LOW);
  delay (500);



rutina4:

  digitalWrite ( led, HIGH);
  lectura();
  if ( state_go == HIGH) {
    allow_off = 1;
    goto PD;
  }
  if ( valor_bi == LOW) {
    c = 1;
  }
  if ( valor_bi == HIGH && c == 1 ) {
    delay ( 50);
    digitalWrite ( led, LOW);
   
   
    goto PD;
  }
  goto rutina4;



off:
  lectura();
  if ( state_go == HIGH ) {
    goto PD;
  }
  analogWrite ( pwmi , 0); analogWrite ( pwmd, 0);
  goto off;





  //*****************************************************************> PROGRAMA PRINCIPAL DE PD <**************************************************************************************

PD:

  if ( state_go == 0 && allow_off == 1 ) {
    goto off;
  }
  
  ahora = millis();
  int ACTUAL = ahora - pasado;
  if (ACTUAL >= MUESTREO)
  {

    lectura();
   
    ERROR_POSICION = valor_sensor1 * (-1) + valor_sensor2 * (-1) + valor_sensor3 * (-1) + valor_sensor4 * (-.8) + valor_sensor5 * (-.6) + valor_sensor6 * (-.4) + valor_sensor7 * (-.2) + valor_sensor8 * (-.1) + valor_sensor9 * (.1) + valor_sensor10 * (.2) + valor_sensor11 * (.4) + valor_sensor12 * (.6) + valor_sensor13 * (.8) + valor_sensor14 * (1) + valor_sensor15 * (1) + valor_sensor16 * (1);


    double ERROR_D = (ERROR_POSICION - ERROR_ULTIMO);
    float P = Kp * ERROR_POSICION;

    float D = Kd * ERROR_D;

    CX = P + D;

    pasado = ahora;
    ERROR_ULTIMO = ERROR_POSICION;

    if ( CX >=  255 ) {
      CX =  255;
    }
    if ( CX <= -255 ) {
      CX = -255;
    }




    int pwm1 = velocidad + (CX);
    int pwm2 = velocidad - (CX);

    if ( pwm1 >= 255 ) {
      pwm1 = 255;
    }
    if ( pwm2 >= 255 ) {
      pwm2 = 255;
    }


    if ( valor_sensor3 > sensibilidad ) {
      posicion = 0;
    }
    if ( valor_sensor1 > sensibilidad && valor_sensor8 < sensibilidad && valor_sensor9 < sensibilidad  ) {
      posicion = 1;
    }

    if ( valor_sensor14 > sensibilidad ) {
      posicion = 0;
    }
    if ( valor_sensor16 > sensibilidad  && valor_sensor8 < sensibilidad && valor_sensor9 < sensibilidad  ) {
      posicion = 16;
    }

    float r1 = abs(pwm1);
    float r2 = abs (pwm2);

    if ( r1 >= 255 ) {
      r1 = 255;
    }
    if ( r2 >= 255 ) {
      r2 = 255;
    }
//Si te sales
    if ( posicion == 16 )
    { analogWrite ( pwmd, reversa); digitalWrite ( pind, HIGH);
      analogWrite ( pwmi, frente); digitalWrite ( pini, HIGH); ;
    }

    if ( posicion == 1 )
    { analogWrite ( pwmd, frente); digitalWrite ( pind, LOW);
      analogWrite ( pwmi, reversa); digitalWrite (pini, LOW); ;
    }
//control de motores 
    if ( posicion != 16 && posicion != 1 ) {
      if ( pwm1 < 0 ) {
        analogWrite ( pwmd, r1);
        digitalWrite ( pind, LOW);//Derecho atras
          digitalWrite ( 13, HIGH);
            
              ;
           
      }
      if ( pwm2 < 0 ) {
        analogWrite ( pwmi, r2);
        digitalWrite ( pini, HIGH);
   ;
      }

      if ( pwm1 == 0 ) {
        analogWrite ( pwmd, 0);
        digitalWrite ( pind, LOW);  
          digitalWrite ( 13, LOW);
       ;
      }
      if ( pwm2 == 0 ) {
        analogWrite ( pwmi, 0);
        digitalWrite ( pini, LOW);  
          digitalWrite ( 13, LOW);
         ;
      }

      if ( pwm1 > 0 ) {
        analogWrite ( pwmd, pwm1);
        digitalWrite ( pind, HIGH);
      ;
      }
      if ( pwm2 > 0 ) {
        analogWrite ( pwmi, pwm2);
        digitalWrite ( pini, LOW) ; 
         ;
      }
    }
  }
  goto PD;
}




void loop() {}

void lectura() {

  valor_bi = digitalRead ( boton_izq);
  //valor_bd = digitalRead ( boton_der);
  state_go = digitalRead ( go);
  state_rdy = digitalRead(rdy);


  digitalWrite ( S0, LOW); digitalWrite ( S1, LOW); digitalWrite ( S2, LOW); digitalWrite ( S3, LOW);       valor_sensor1 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH);                                                                                 valor_sensor2 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, HIGH);                                                        valor_sensor3 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH);                                                                                 valor_sensor4 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, LOW); digitalWrite ( S2, HIGH);                               valor_sensor5 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH);                                                                                 valor_sensor6 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, HIGH); digitalWrite ( S2, HIGH);                              valor_sensor7 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH); digitalWrite ( S1, HIGH); digitalWrite ( S2, HIGH);                             valor_sensor8 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, LOW); digitalWrite ( S2, LOW); digitalWrite ( S3, HIGH);      valor_sensor9 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH); digitalWrite ( S1, LOW); digitalWrite ( S2, LOW);                               valor_sensor10 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, HIGH); digitalWrite ( S2, LOW);                               valor_sensor11 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH); digitalWrite ( S1, HIGH); digitalWrite ( S2, LOW);                              valor_sensor12 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite ( S1, LOW); digitalWrite ( S2, HIGH);                               valor_sensor13 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH); digitalWrite ( S1, LOW);                                                        valor_sensor14 = analogRead ( OP) / 4;
  digitalWrite ( S0, LOW); digitalWrite (  S1, HIGH);                                                       valor_sensor15 = analogRead ( OP) / 4;
  digitalWrite ( S0, HIGH);                                                                                 valor_sensor16 = analogRead ( OP) / 4;


  if ( color == 2 )
  {

    valor_sensor1 = map(valor_sensor1, 0 , 255 , 255, 0);
    valor_sensor2 = map(valor_sensor2, 0 , 255 , 255, 0);
    valor_sensor3 = map(valor_sensor3, 0 , 255 , 255, 0);
    valor_sensor4 = map(valor_sensor4, 0 , 255 , 255, 0);
    valor_sensor5 = map(valor_sensor5, 0 , 255 , 255, 0);
    valor_sensor6 = map(valor_sensor6, 0 , 255 , 255, 0);
    valor_sensor7 = map(valor_sensor7, 0 , 255 , 255, 0);
    valor_sensor8 = map(valor_sensor8, 0 , 255 , 255, 0);
    valor_sensor9 = map(valor_sensor9, 0 , 255 , 255, 0);
    valor_sensor10 = map(valor_sensor10, 0 , 255 , 255, 0);
    valor_sensor11 = map(valor_sensor11, 0 , 255 , 255, 0);
    valor_sensor12 = map(valor_sensor12, 0 , 255 , 255, 0);
    valor_sensor13 = map(valor_sensor13, 0 , 255 , 255, 0);
    valor_sensor14 = map(valor_sensor14, 0 , 255 , 255, 0);
    valor_sensor15 = map(valor_sensor15, 0 , 255 , 255, 0);
    valor_sensor16 = map(valor_sensor16, 0 , 255 , 255, 0);
  }



  valor_sensor1 = map(valor_sensor1, mins1 , maxs1 , 0, 255);
  valor_sensor2 = map(valor_sensor2, mins2 , maxs2 , 0, 255);
  valor_sensor3 = map(valor_sensor3, mins3 , maxs3 , 0, 255);
  valor_sensor4 = map(valor_sensor4, mins4 , maxs4 , 0, 255);
  valor_sensor5 = map(valor_sensor5, mins5 , maxs5 , 0, 255);
  valor_sensor6 = map(valor_sensor6, mins6 , maxs6 , 0, 255);
  valor_sensor7 = map(valor_sensor7, mins7 , maxs7 , 0, 255);
  valor_sensor8 = map(valor_sensor8, mins8 , maxs8 , 0, 255);
  valor_sensor9 = map(valor_sensor9, mins9 , maxs9 , 0, 255);
  valor_sensor10 = map(valor_sensor10, mins10 , maxs10 , 0, 255);
  valor_sensor11 = map(valor_sensor11, mins11 , maxs11 , 0, 255);
  valor_sensor12 = map(valor_sensor12, mins12 , maxs12 , 0, 255);
  valor_sensor13 = map(valor_sensor13, mins13 , maxs13 , 0, 255);
  valor_sensor14 = map(valor_sensor14, mins14 , maxs14 , 0, 255);
  valor_sensor15 = map(valor_sensor15, mins15 , maxs15 , 0, 255);
  valor_sensor16 = map(valor_sensor16, mins16 , maxs16 , 0, 255);

}
