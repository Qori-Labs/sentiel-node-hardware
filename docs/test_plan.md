# Plan de Pruebas (v1) — sentinel-node-hardware

**Propósito:** Proveer un plan de pruebas conservador y reproducible para el bring-up en banco y la validación temprana en campo.  
**Alcance:** Solo validación de hardware. La cobertura/afirmaciones operacionales a nivel de sistema están fuera del alcance de este repo.

**Principio:** Los objetivos son **objetivos de diseño** (no garantías). La validación está **pendiente** hasta que se reúnan artefactos de prueba.

---

## 1) Pruebas de bring-up en banco

### 1.1 Inspección visual + mecánica (pre-energización)
- Verificar marcas de polaridad y etiquetas de cableado (PV+, PV−, BAT+, BAT−).
- Confirmar alivio de tensión en todos los cables; sin aislante pellizcado.
- Confirmar asiento de la junta, compresión de prensaestopas y torque de la tapa (a mano + un cuarto de vuelta; evitar sobre-torque).

**Aceptación (conservadora):**
- Sin conductor expuesto; sin interferencias mecánicas obvias; la tapa cierra sin forzar.

---

### 1.2 Sanidad del camino de energía (sin solar)
- Insertar el pack de baterías; medir:
  - voltaje en bornes de batería
  - voltaje de riel(es) regulados (3.3V / 5V según aplique)
- Verificar que el MCU pueda bootear repetidamente sin bucles de brownout (observar logs seriales / LED de latido).

**Aceptación:**
- Rieles dentro de la tolerancia esperada para el regulador seleccionado.
- Sin bucle de reset repetido bajo voltaje nominal de batería.

---

### 1.3 Comportamiento del cargador (con solar)
- Conectar el panel solar bajo luz controlada (o fuente de banco emulando el panel).
- Observar el comportamiento del controlador de carga:
  - voltaje/corriente de entrada PV (si se puede medir)
  - corriente de carga a batería
  - comportamiento térmico del IC/módulo de carga
- Confirmar supuestos correctos de química:
  - **No usar un cargador Li-ion para LiFePO₄** (y viceversa).

**Aceptación:**
- Sin sobrecalentamiento bajo la corriente de carga esperada.
- El voltaje de la batería aumenta de acuerdo con el perfil del cargador para la química elegida.
- Sin corriente inversa hacia el panel en baja luz (si el diseño espera bloqueo).

---

### 1.4 Corriente en sueño y comportamiento de wake (bajo consumo)
- Flashear firmware de bring-up con un modo de sueño conocido.
- Medir corriente en:
  - modo activo (radio apagada)
  - modo sueño (objetivo: “tan baja como sea práctico”; registrar el valor medido)
- Probar fuentes de wake si se usan (timer, GPIO, etc.).

**Aceptación:**
- La corriente en sueño es estable (sin oscilación).
- El wake es repetible; sin cuelgues tras múltiples ciclos de sueño.

---

### 1.5 Brownout / comportamiento de subvoltaje
- Bajar lentamente el voltaje de batería (fuente de banco o descarga controlada).
- Observar:
  - umbrales de reset
  - si el nodo entra en un bucle de brownout
  - si el sistema registra/indica condición de bajo voltaje

**Aceptación:**
- Sin oscilación rápida de brownout que arriesgue corrupción de flash.
- La condición de bajo voltaje es detectable (por indicador de estado o log).

---

## 2) Pruebas ambientales (nivel checklist)

### 2.1 Chequeo de riesgo de condensación (banco)
- Colocar el nodo ensamblado en un ambiente frío, luego llevarlo a un ambiente cálido/húmedo.
- Abrir el enclosure tras un tiempo de permanencia definido (p. ej., 2–4 horas) e inspeccionar:
  - condensación visible
  - puntos de inicio de corrosión (conectores, tornillos, bordes del PCB)

**Aceptación:**
- Sin agua acumulada dentro del enclosure.
- Si aparece condensación, se documentan mitigaciones (tapón de ventilación, conformal coating, ubicación de desecante).

---

### 2.2 Checklist de ciclado térmico
- Ciclar el nodo a través de temperaturas realistas para el entorno objetivo (rango definido por el setup).
- Verificar:
  - boot a través de temperaturas
  - integridad del sello del enclosure
  - retención del prensaestopas tras el ciclado

**Aceptación:**
- Sin aflojamientos mecánicos que creen rutas de ingreso.
- El nodo sigue funcional en el rango probado (registrar explícitamente el rango probado).

---

## 3) Pruebas RF de sanidad (sin cobertura)

### 3.1 Reglas de seguridad de antena (obligatorias)
- **Nunca transmitir sin una antena** conectada.
- Confirmar tipo de conector y torque; usar alivio de tensión para que el conector no cargue esfuerzo mecánico.
- Mantener tramos coaxiales cortos; evitar curvas cerradas.

### 3.2 Prueba RF “¿está vivo?”
- Validar que la radio pueda transmitir un paquete corto de prueba y ser recibido por un receptor conocido-bueno a corta distancia.
- Registrar configuración usada:
  - plan de frecuencias (dependiente de región)
  - potencia de salida
  - spreading factor / ancho de banda
  - restricciones de duty-cycle

**Aceptación:**
- TX/RX básico confirmado a corta distancia con configuración documentada.
- No se hacen afirmaciones de cobertura en campo a partir de esta prueba.

---

## 4) Resumen conservador de criterios de aceptación (v1)
Un nodo es aceptable para **validación piloto limitada** si:
- El camino de energía es estable (sin bucles de brownout en condiciones nominales).
- El comportamiento del cargador coincide con la química de batería elegida.
- La corriente en sueño está medida y documentada.
- La prueba RF de sanidad TX/RX pasa a corta distancia con reglas de antena cumplidas.
- Se evalúan riesgos de condensación y se documentan mitigaciones.
