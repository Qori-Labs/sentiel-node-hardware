<div align="center">
  <!-- Optional: add logo at docs/assets/qori-labs-mark.svg -->
  <!-- <img alt="Qori Labs" src="docs/assets/qori-labs-mark.svg" height="64" /> -->
  <h1>sentinel-node-hardware</h1>
  <p><strong>Reference hardware design for autonomous LoRa store-and-forward relay nodes</strong></p>

  ![Status: Prototype](https://img.shields.io/badge/Status-Prototype-orange)
  ![License: CERN-OHL-W](https://img.shields.io/badge/License-CERN--OHL--W-blue)
  ![Docs: v1.0](https://img.shields.io/badge/Docs-v1.0-informational)
</div>

---

## Overview

This repository defines the **physical layer** for Qori Sentinel relay nodes: power path, enclosure guidance, wiring logic, and a bring-up scaffold for high-altitude off-grid environments.

**Design goals (validation pending):**
- Cold-weather operating target: **-10°C to +25°C** *(design target; validation pending — see docs/test_plan.md)*
- Tolerance for high UV exposure *(materials selection + maintenance; validation pending)*
- Off-grid solar operation with **panel ≥5W** *(design target; site/season dependent; validation pending)*
- Store-and-forward operation with short LoRa packets *(system-level behavior depends on firmware; validation pending)*

This repository is an **engineering reference**. It is not a certified product design.

---

## System intent (what this node is / is not)

### Intended
- Solar-powered relay node for store-and-forward experiments with **short LoRa packets**.
- Conservative, testable design decisions for pilot validation.
- Field maintainability (serviceable enclosure, documented failure modes).

### Not intended
- Not a life-safety device and not a substitute for established rescue protocols.
- Does not guarantee coverage, delivery, uptime, or response time.

---

## Radio configuration (region-dependent)

This design is **region-dependent** and must be configured according to local regulatory constraints and site approval requirements (for example, frequency plan, output power, and duty cycle).

- Conceptually supported: LoRa hardware in the **433 / 868 / 915 MHz** classes (region-dependent).
- **Current reference configuration:** **915 MHz-class** components and antenna in the BOM (adjust for region).

Do not interpret any reference configuration as permission to operate. Confirm compliance and obtain site approval.

---

## No false assurance (prototype disclaimer)

**RESEARCH PROTOTYPE / ENGINEERING REFERENCE — NOT A CERTIFIED LIFE-SAFETY DEVICE.**  
Do not rely on this hardware for personal safety decisions. Always follow local protocols and trained authorities.

This repository intentionally documents limits and failure modes. Validation is pending and must be demonstrated with test artifacts (see docs/test_plan.md).

---

## What’s in this repo

- **BOM.md** — Bill of materials with preferred parts and safe alternates
- **docs/wiring_logic.mermaid** — wiring logic diagram (reference)
- **docs/power_path.md** — canonical v1 power architecture + chemistry warnings
- **docs/test_plan.md** — conservative bring-up + environmental + RF sanity tests
- **docs/failure_modes.md** — main high-altitude failure modes + mitigations/observability
- **mechanical/README.md** — enclosure/printing guidance + field service notes
- **firmware/** — minimal PlatformIO scaffold for bring-up (not production firmware)

---

## Bring-up quick start (minimum)

1. Read:
   - docs/power_path.md
   - docs/test_plan.md
2. Assemble conservatively (label chemistry, add fuse on PV input).
3. Flash the firmware scaffold and confirm:
   - serial output is alive
   - LED heartbeat
4. Run bench tests before any field exposure.

---

## Licensing

The hardware documentation and associated design files in this repository are licensed under **CERN-OHL-W**.  
See **/LICENSE** for the full text.

---

## Safety notes (non-exhaustive)

- Lithium cells can be hazardous. Use protected cells, the correct chemistry/charger profile, and consider fusing.
- Waterproof enclosures can trap moisture; condensation is a common failure mode at altitude.
- **Never transmit RF without an antenna connected.**
# sentinel-node-hardware
