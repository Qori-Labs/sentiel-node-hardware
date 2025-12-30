# BOM (v1) — sentinel-node-hardware

**Propósito:** Lista de materiales de referencia con partes preferidas y alternos conservadores. No es una orden de compra. Ajustar por región, disponibilidad y normativa.

**Regla crítica:** La química de batería y el cargador **deben coincidir**. Elige **un solo track** (Li-ion o LiFePO₄) para cada build.

---

## Track de química (elige 1)

### Opción A — Li-ion (1S, terminación 4.2V)
- Pack 1S (2x18650 en paralelo), preferentemente con protección/BMS.
- Módulo de carga solar compatible con Li-ion (CC/CV a 4.2V) y power-path si es necesario.

### Opción B — LiFePO₄ (1S, terminación ~3.6–3.65V)
- Pack 1S LiFePO₄ (p. ej., 2x26650 en paralelo) con protección compatible.
- Módulo de carga solar compatible con LiFePO₄ (terminación 3.6–3.65V).

---

## Lista de materiales (referencia)

| Ítem | Especificación preferida | Ejemplos / notas |
| --- | --- | --- |
| Panel solar | 6V nominal, ≥5W (típico 6W) | Ajustar por sitio/estación; cable UV-rated. |
| Fusible PV | 1–2A en serie, portafusible inline | Dimensionar por Isc del panel + margen. |
| TVS PV | Diodo TVS shunt, Vstandoff > Voc del panel | Protege contra picos/ESD en cables largos. |
| Módulo de carga | Solar + química correcta (Li-ion o LiFePO₄) | Evitar mezclar químicas; revisar perfil CC/CV. |
| Pack de batería | 1S, 2x celdas en paralelo con protección | Preferir celdas protegidas y de marca. |
| Regulador 3.3V | Bajo IQ, estable a bajo voltaje de batería | Buck-boost recomendado si 3.3V estable es crítico. |
| MCU | Módulo nRF52840 (p. ej., RAK4631 o equivalente) | Referencia de firmware usa entorno rak4631. |
| Radio LoRa | SX126x (p. ej., SX1262) | Seleccionar banda por región (433/868/915). |
| Antena | Banda regional (915MHz referencia) | Conector SMA/N según enclosure. |
| Coax/pigtail | Corta longitud, baja pérdida | Agregar alivio de tensión para RF. |
| Enclosure | IP67 policarbonato, UV-estable | Vent plug + desecante recomendados. |
| Prensaestopas | IP68 UV-rated, tamaño por OD de cable | M12/M16 típicos. |
| Tornillería | Acero inoxidable | Evitar corrosión en altura. |
| Cables | UV-rated, 18–22 AWG potencia | Ajustar sección por corriente y longitud. |
| Etiquetas | Etiquetas de química, polaridad, servicio | Minimiza errores de ensamblaje/mantenimiento. |
| Conformal coating | Opcional, tipo acrílico o silicona | Útil en bordes y conectores expuestos. |

---

## Notas de integración
- Mantener el camino PV protegido (fusible + TVS).
- Verificar torque y alivio de tensión en prensaestopas.
- Documentar: química, perfil de cargador, rieles, corriente de sueño y pruebas (ver docs/test_plan.md).
