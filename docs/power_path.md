# Camino de Energía (v1) — arquitectura canónica y notas de seguridad

**Meta:** Una arquitectura de energía simple y conservadora para nodos relay off-grid. Esto es una referencia, no un diseño certificado.

---

## 1) Arquitectura canónica (v1)

**Topología recomendada (típica):**
- Panel solar → **fusible en serie** → módulo de carga/alimentación
- Módulo de carga/alimentación → pack de batería (1S) + riel(es) regulados
- Riel(es) regulados → MCU/radio/sensores

**Elementos de protección (alto impacto):**
- **Fusible (serie):** limita corriente de falla en PV o fallas de cableado de batería.
- **TVS (shunt):** sujeta picos/ESD en la entrada PV (especialmente con cables largos al panel).
- Opcional: protección de polaridad inversa en entrada de batería (trade-off: caída de tensión vs seguridad).

---

## 2) Requisitos de química de batería (no mezclar)

### Li-ion (1S, terminación 4.2V)
- Requiere un perfil de cargador Li-ion (CC/CV a 4.2V).
- Usar celdas 18650 protegidas cuando sea posible.
- Preferir corriente de carga conservadora e incluir consideraciones térmicas.

### LiFePO₄ (1S, terminación ~3.6–3.65V)
- Requiere terminación y protección compatibles con LiFePO₄.
- **No** usar un cargador solo-Li-ion configurado para 4.2V de terminación.

**Advertencia:** La química de carga incorrecta es un riesgo de seguridad y un modo de falla común en campo. El ensamblaje debe incluir un paso explícito de verificación de química.

---

## 3) Rieles y comportamiento ante brownout
- Si el MCU usa 3.3V, asegurar que el regulador sea estable cerca del fin de descarga.
- Evitar oscilación de brownout con:
  - UVLO + histéresis
  - backoff en firmware (dormir) bajo bajo-voltaje
  - potencia TX y duty cycle conservadores

---

## 4) Qué debe documentarse por build
- química de batería + modelo de celda
- módulo/perfil de cargador usado
- rating del fusible y ubicación
- corriente de sueño medida y comportamiento de bajo voltaje (ver docs/test_plan.md)
