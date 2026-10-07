#include <Arduino.h>
#include <math.h>
#include <esp_now.h>
#include <WiFi.h>


struct Vec3 {
  float x;
  float y;
  float z;
};

Vec3 addiere(Vec3 a, Vec3 b){
  Vec3 c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}

Vec3 subtrahiere(Vec3 a, Vec3 b){
  Vec3 c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  return c;
}

Vec3 mal(Vec3 a, float s){
  Vec3 c;
  c.x = a.x * s;
  c.y = a.y * s;
  c.z = a.z * s;
  return c;
}

Vec3 teile(Vec3 a, float s){
 if(s==0){
    return a;
  }else{  
    return mal(a, 1.0f/s);
  }
}

float laenge(Vec3 a){
  return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

Vec3 setLaenge(Vec3 a, float m){
  float l = laenge(a);
  if(l == 0) return a;
  return mal(a, m/l);
}

Vec3 begrenze(Vec3 a, float b){
  if(laenge(a)>b) return setLaenge(a,b);
  return a; 
}

float abstand(Vec3 a, Vec3 b){
return laenge(subtrahiere(a,b));
}

//einheit in m

#define MAX_DROHNEN      8
#define MEINE_ID         1        // pro Drohne aendern!

#define SICHT            3.0f
#define MIN_ABSTAND      1.0f
#define MAX_SPEED        2.0f
#define MIN_SPEED        0.3f
#define MAX_FORCE        0.5f

#define GEW_SEPARATION   1.5f
#define GEW_ALIGNMENT    1.0f
#define GEW_COHESION     0.8f

#define SENDE_INTERVALL  50       // ms -> 20 Hz
#define BOIDS_INTERVALL  33       // ms -> 30 Hz
#define TIMEOUT          500      // ms ohne Paket = Nachbar weg

struct Nachbar{
  Vec3 pos;
  Vec3 vel;
  uint32_t letzteMeldung;
  bool     belegt;
};

Vec3 meineVel;
Vec3 meinePos;
Vec3 meineAcc;

Nachbar nachbar [MAX_DROHNEN];

bool istAktiv(uint8_t i) {
  if (!nachbar[i].belegt) return false;
  if (i == MEINE_ID) return false;
  return (millis() - nachbar[i].letzteMeldung) < TIMEOUT;
}

Vec3 separation(){
  
}



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
