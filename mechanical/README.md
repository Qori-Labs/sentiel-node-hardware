# Guía Mecánica / Enclosure (v1.0)

Los despliegues en alta altitud fallan mecánicamente antes que electrónicamente. Este doc prioriza control de ingreso, durabilidad UV y mantenibilidad.

---

## Enfoque recomendado de enclosure (v1)
1. **Enclosure principal:** IP67 policarbonato (UV-estable preferido).
2. **Entrada de cables:** prensaestopas IP68 (UV-rated).
3. **Control de condensación:** tapón respirable + pack desecante.
4. **Alivio de tensión interno:** anclar cables dentro de la caja para evitar fatiga de conectores.

---

## Dimensionado de prensaestopas (guía práctica)
- Tamaños típicos: **M12/M16**, pero elige siempre por **diámetro exterior (OD)** del cable.
- Regla práctica: elige un prensaestopas cuyo rango de sujeción deje tu OD cerca del centro del rango.
- No sobre-aprietes: exceso de compresión puede dañar la chaqueta y crear una ruta de fuga después.

---

## Montaje de antena y alivio de tensión (ejemplo)
No dejes que el conector RF cargue esfuerzo mecánico.

Ejemplo:
- Montar la antena mecánicamente a un mástil/soporte.
- Usar un coax/pigtail corto hacia el enclosure de la radio.
- Añadir alivio de tensión (base para brida o clamp) cerca de la entrada del enclosure para que el conector no sea jalado.

---

## Guía de impresión 3D (si imprimes piezas del enclosure)
- Material: **ASA** (preferido) o PETG (aceptable). Evitar PLA por UV/calor.
- Espesor de pared: ≥ 2.0–2.5 mm; añadir nervaduras para rigidez.
- Usar inserts térmicos para tornillería servible.
- Validar sellado con un canal de junta + junta de silicona/O-ring.

---

## Checklist mínimo de servicio en campo
- Inspeccionar prensaestopas por aflojamiento; re-torque según procedimiento (sin sobre-torque).
- Inspeccionar junta: limpiar suciedad, revisar grietas/aplastamiento.
- Abrir enclosure y **secar** si hay humedad; reemplazar desecante.
- Inspeccionar terminales por corrosión; limpiar y proteger según se requiera.
- Inspeccionar montaje de antena/alivio de tensión; asegurar que el conector no esté estresado.
- Registrar cualquier evento de ingreso/condensación como incidente de mantenimiento.
