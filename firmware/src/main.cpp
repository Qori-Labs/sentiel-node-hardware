// sentinel-node-hardware/firmware/src/main.cpp
//
// Sketch mínimo de bring-up (andamio “compila seguro”).
// Propósito: serial vivo + parpadeo de LED + placeholders para init de energía/RF.
// Este repo es hardware-first; el firmware de producción vive en otro lado.

#include <Arduino.h>

#ifndef LED_BUILTIN
// Fallback: muchos cores Arduino definen LED_BUILTIN.
// Si tu placa no lo hace, define el pin correcto en platformio.ini (build_flags).
#define LED_BUILTIN 13
#endif

static void blink_once(uint32_t on_ms, uint32_t off_ms) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(on_ms);
  digitalWrite(LED_BUILTIN, LOW);
  delay(off_ms);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
  delay(50);

  Serial.println();
  Serial.println("sentinel-node-hardware bring-up (v1)");
  Serial.println("NOTA: Prototipo de investigacion. Validacion pendiente. Sin falsa seguridad.");

  // TODO(power): leer voltaje de batería (ADC) si está cableado; reportar estado de subvoltaje.
  // TODO(radio): inicializar SX126x (RadioLib preferido) DESPUÉS de confirmar antena conectada.
  // TODO(lowpower): configurar sueño + fuentes de wake; medir corriente de sueño según docs/test_plan.md.
}

void loop() {
  // Patrón de latido: 2 parpadeos rápidos, pausa.
  blink_once(60, 60);
  blink_once(60, 300);
  delay(1000);

  // Placeholder: una máquina de estados futura viviría aquí.
}
