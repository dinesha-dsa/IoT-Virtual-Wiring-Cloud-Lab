# IoT Virtual Wiring & Cloud Lab — Version 2.1

Prepared by **Prof. Dinesh S. Auti, Department of EXCP, KJSSE**.

An educational, browser-based laboratory for ESP32 wiring, sensor–actuator logic, MQTT telemetry, cloud visualization, code generation and experiment-report preparation.

## Capabilities

- Choose two sensors and one actuator.
- Connect component and ESP32 pins interactively.
- Auto-wire a reference circuit or build one manually.
- Validate power, ground, signal, ADC and 3.3 V compatibility.
- Animate sensor, control and current signals.
- Configure AND/OR threshold logic.
- Connect to a secure MQTT WebSocket broker at runtime.
- Display simulated or MQTT telemetry on the cloud dashboard.
- Generate and download an ESP32 Arduino sketch.
- Download an editable HTML experiment report or print it to PDF.

## GitHub Pages

Upload `index.html`, `styles.css`, `app.js`, `README.md` and the `firmware` folder to the repository root. In **Settings → Pages**, choose **Deploy from a branch**, `main`, and `/(root)`.

## MQTT requirement

GitHub Pages uses HTTPS, so the browser broker endpoint must use secure WebSockets (`wss://`). Credentials are entered only at runtime and are not saved by this project.

## Educational scope

This is a logic-level teaching simulator. It validates common ESP32 interfacing rules, but it is not a SPICE electrical simulator and must not replace datasheet review or hardware safety checks.

## Safety

ESP32 GPIO is 3.3 V logic. Do not apply 5 V directly to an input. Motors and pumps require an appropriate relay/MOSFET driver, separate supply and protective components.
