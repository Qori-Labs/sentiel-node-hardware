<div align="center">
  <!-- Opcional: añadir logo en docs/assets/qori-labs-mark.svg -->
  <!-- <img alt="Qori Labs" src="docs/assets/qori-labs-mark.svg" height="64" /> -->
  <h1>sentinel-node-hardware</h1>
  <p><strong>Diseño de hardware de referencia para nodos relay LoRa autónomos store-and-forward</strong></p>

  ![Status: Prototype](https://img.shields.io/badge/Status-Prototype-orange)
  ![License: CERN-OHL-W](https://img.shields.io/badge/License-CERN--OHL--W-blue)
  ![Docs: v1.0](https://img.shields.io/badge/Docs-v1.0-informational)
</div>

---

## Descripción general

Este repositorio define la **capa física** para nodos relay Qori Sentinel: camino de energía, guía de enclosure, lógica de cableado y un scaffold de bring-up para entornos de alta altitud off-grid.

**Objetivos de diseño (validación pendiente):**
- Objetivo de operación en frío: **-10°C a +25°C** *(objetivo de diseño; validación pendiente — ver docs/test_plan.md)*
- Tolerancia a alta exposición UV *(elección de materiales + mantenimiento; validación pendiente)*
- Operación solar off-grid con **panel ≥5W** *(objetivo de diseño; depende de sitio/estación; validación pendiente)*
- Operación store-and-forward con paquetes LoRa cortos *(el comportamiento a nivel sistema depende del firmware; validación pendiente)*

Este repositorio es una **referencia de ingeniería**. No es un diseño de producto certificado.

---

## Intención del sistema (qué es / qué no es este nodo)

### Intended (intencionado)
- Nodo relay alimentado por solar para experimentos store-and-forward con **paquetes LoRa cortos**.
- Decisiones de diseño conservadoras y testeables para validación piloto.
- Mantenibilidad en campo (enclosure servible, modos de falla documentados).

### Not intended (no intencionado)
- No es un dispositivo de “seguridad de vida” ni un sustituto de protocolos de rescate establecidos.
- No garantiza cobertura, entrega, uptime ni tiempo de respuesta.

---

## Configuración de radio (dependiente de región)

Este diseño es **dependiente de la región** y debe configurarse según restricciones regulatorias locales y aprobación del sitio (p. ej., plan de frecuencias, potencia de salida, duty cycle).

- Soportado conceptualmente: hardware LoRa clase **433 / 868 / 915 MHz** (dependiente de región).
- **Configuración de referencia actual:** componentes y antena clase **915 MHz** en BOM (ajustar por región).

No interpretes ninguna configuración de referencia como permiso para operar. Confirma cumplimiento y obtén aprobación del sitio.

---

## Sin falsa seguridad (descargo por prototipo)

**PROTOTIPO DE INVESTIGACIÓN / REFERENCIA DE INGENIERÍA — NO ES UN DISPOSITIVO CERTIFICADO DE SEGURIDAD DE VIDA.**  
No confíes en este hardware para decisiones de seguridad personal. Sigue siempre protocolos locales y autoridades entrenadas.

Este repo documenta intencionalmente límites y modos de falla. La validación está pendiente y debe demostrarse con artefactos de prueba (ver docs/test_plan.md).

---

## Qué hay en este repo

- **BOM.md** — Lista de materiales con partes preferidas y alternos seguros
- **docs/wiring_logic.mermaid** — diagrama de lógica de cableado (referencia)
- **docs/power_path.md** — arquitectura canónica v1 de energía + advertencias de química
- **docs/test_plan.md** — pruebas conservadoras de bring-up + ambiente + sanidad RF
- **docs/failure_modes.md** — principales modos de falla en altura + mitigaciones/observabilidad
- **mechanical/README.md** — guía de enclosure/impresión + servicio en campo
- **firmware/** — scaffold mínimo PlatformIO para bring-up (no firmware de producción)

---

## Bring-up quick start (mínimo)

1. Leer:
   - docs/power_path.md
   - docs/test_plan.md
2. Ensamblar de forma conservadora (etiquetar química, fusible en entrada PV).
3. Flashear el scaffold de firmware y confirmar:
   - serial vivo
   - latido LED
4. Ejecutar pruebas de banco antes de cualquier exposición en campo.

---

## Licenciamiento

La documentación de hardware y archivos de diseño asociados en este repositorio están licenciados bajo **CERN-OHL-W**.  
Ver **/LICENSE** para el texto completo.

---

## Notas de seguridad (no exhaustivas)

- Las celdas de litio pueden ser peligrosas. Usa celdas protegidas, química/perfil de cargador correctos y considera fusibles.
- Los enclosures impermeables pueden atrapar humedad; la condensación es un modo de falla común en altura.
- **Nunca transmitas RF sin una antena conectada.**
# sentiel-node-hardware
