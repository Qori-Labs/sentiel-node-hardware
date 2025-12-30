# Modos de Falla (v1) — nodo relay de alta altitud

**Propósito:** Enumerar modos de falla de alto impacto para despliegues en Andes/alta altitud y documentar mitigaciones y observabilidad.

**Nota:** Esto es un registro de riesgos de ingeniería, no una garantía de seguridad. Trátese como documentación viva.

---

## Principales modos de falla (8–12) y mitigaciones

### 1) Condensación dentro del enclosure
- **Síntoma:** resets intermitentes, corrosión en PCB/herrajes, deriva de sensores.
- **Causas raíz:** ciclado térmico; caja sellada que atrapa humedad.
- **Mitigaciones:** tapón respirable (vent plug), desecante, recubrimiento conformal en bordes/conectores, procedimiento de servicio-secado.
- **Qué mostrar/registrar:** bandera de servicio “Riesgo de humedad”; contador de resets; última razón de reboot.

### 2) Fragilización por UV (cables, juntas, plásticos impresos)
- **Síntoma:** chaquetas de cable agrietadas, prensaestopas con fuga, piezas impresas quebradizas.
- **Mitigaciones:** cable UV-rated, enclosure UV-estable (policarbonato/ASA), inspección/reemplazo programado de juntas.
- **Mostrar/registrar:** recordatorios de intervalos de mantenimiento; “inspección de prensaestopas/junta pendiente”.

### 3) Oscilación de brownout / bucles de reset
- **Síntoma:** ciclos de boot repetidos; logs corruptos; radio nunca estabiliza.
- **Causas raíz:** subvoltaje, inrush, inestabilidad del regulador, celdas agotadas.
- **Mitigaciones:** diseño UVLO, histéresis, backoff en firmware, mayor capacitancia de entrada, potencia TX conservadora.
- **Mostrar/registrar:** estado de bajo voltaje; contador de brownout; voltaje mínimo de batería.

### 4) Prensaestopas flojos / ruta de ingreso
- **Síntoma:** ingreso de agua; fallas intermitentes de energía por conectores húmedos.
- **Mitigaciones:** tamaño correcto de prensaestopas para OD del cable, alivio de tensión, procedimiento de torque, marca testigo.
- **Mostrar/registrar:** ítem en checklist de servicio; notas de inspección de ingreso.

### 5) Fatiga de conectores (conector de antena, pigtails)
- **Síntoma:** RSSI/SNR degradado, fallas RF intermitentes, holgura física.
- **Mitigaciones:** alivio de tensión para antena/coax, evitar cargas en voladizo, montar antena mecánicamente al mástil.
- **Mostrar/registrar:** indicador de salud RF (tasa de error de paquetes en pruebas); bandera “revisar antena”.

### 6) Hinchazón/venteo de celdas (Li-ion)
- **Síntoma:** abombamiento del enclosure, olor, calor, caída rápida de voltaje.
- **Mitigaciones:** celdas protegidas, perfil de carga correcto, carga consciente de temperatura, fusible, corriente de carga conservadora.
- **Mostrar/registrar:** lockout “falla de batería”; registro de evento de temperatura (si existe sensado).

### 7) Química de cargador incorrecta (Li-ion vs LiFePO₄)
- **Síntoma:** voltaje de terminación incorrecto; degradación acelerada; riesgo de seguridad.
- **Mitigaciones:** restricciones duras en BOM, etiquetado físico, conectores con llave cuando sea posible.
- **Mostrar/registrar:** checklist de build; paso “química confirmada” en log de ensamblaje.

### 8) Corrosión en terminales / herrajes
- **Síntoma:** resistencia incrementada, pérdida intermitente de energía, calentamiento bajo carga.
- **Mitigaciones:** herrajes inoxidables, grasa dieléctrica en terminales expuestos, terminales crimp sellados, recubrimiento conformal.
- **Mostrar/registrar:** checklist de inspección; mediciones de caída de voltaje bajo carga.

### 9) Daño del panel solar / delaminación / falla de cable
- **Síntoma:** menor corriente de carga; déficit energético diario; estados de bajo poder frecuentes.
- **Mitigaciones:** alivio de tensión, cable UV, montaje que evite flexión, plan de panel de repuesto.
- **Mostrar/registrar:** resumen diario de presupuesto energético (si se mide); estado “entrada solar baja”.

### 10) Cuelgue de firmware (watchdog ausente o mal configurado)
- **Síntoma:** el nodo parece “muerto” hasta un power cycle.
- **Mitigaciones:** watchdog, boot en modo seguro, latido periódico.
- **Mostrar/registrar:** razón de reset por watchdog; uptime desde el último reset.

---

## Expectativas mínimas de observabilidad
Incluso en un repo de hardware, planear ganchos mínimos de observabilidad:
- razón de reset + contador de reboots
- voltaje de batería (y temperatura opcional)
- estado “bajo poder / brownout”
- estado de sanidad RF (modo de prueba TX/RX básico)
