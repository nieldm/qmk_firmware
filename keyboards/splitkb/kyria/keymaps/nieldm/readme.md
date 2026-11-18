# Kyria rev1 — keymap nieldm

Keymap personal para un splitkb Kyria rev1.4 con Elite-C (izquierda) y Pro Micro (derecha).

## Hardware y features

- OLED SSD1306 en ambas mitades (rotación 180°)
  - Master: logo QMK, `Kyria nieldm`, capa activa y estado Num/Caps/Scroll Lock
  - Esclava: logo Kyria
- Encoders: izquierdo = volumen, derecho = Page Up/Down
- RGB underglow (brillo máximo limitado a 150)
- `EE_HANDS`: cada mitad sabe su lado, se puede conectar el USB a cualquiera
- VIA con las 6 capas editables en vivo desde [Remappr](https://remappr.com) o VIA
- Animaciones RGB: breathing, rainbow mood, rainbow swirl, snake, knight y static gradient. Las demás se quitaron para que el firmware entre en el ATmega32u4 (se usa ~95% de la flash)

## Capas

| # | Capa | Cómo se activa | Contenido |
|---|------|----------------|-----------|
| 0 | QWERTY | Base por defecto | QWERTY con home row mods |
| 1 | GAMING | Base (Adjust + D) | QWERTY sin home row mods |
| 2 | NAV | Mantener pulgar izq. interior | Flechas, Home/End, PgUp/PgDn, media, numpad izq., Repeat |
| 3 | SYM | Mantener pulgar der. interior | Números y símbolos |
| 4 | FUNCTION | Mantener `F-keys` | F1–F12 a la izquierda, numpad a la derecha |
| 5 | ADJUST | Mantener pulgar izq. exterior | Cambio de capa base (E = QWERTY, D = GAMING) y control RGB |

Los diagramas de cada capa están en los comentarios de `keymap.c`.

### Home row mods (QWERTY)

| A | S | D | F | G | H | J | K | L | ; |
|---|---|---|---|---|---|---|---|---|---|
| Ctrl | Alt | GUI | Shift | Hyper | Hyper | Shift | GUI | Alt | Ctrl |

Otras teclas dual: Esc/Ctrl, `'`/Ctrl derecho, Enter/Alt.

### Tap-hold

- `TAPPING_TERM` 200 ms
- Quick tap term 0 (sin auto-repeat con doble tap) y permissive hold, solo en las home row mods

### Repeat

La tecla `REPEAT` (NAV, posición de la G) es el Repeat Key nativo de QMK (`QK_REP`): repite la última tecla con sus modificadores. Con mod-taps repite la letra.

## Compilar y flashear

```sh
# Mitad izquierda (Elite-C)
qmk flash -kb splitkb/kyria/rev1 -km nieldm -bl dfu-split-left
# Mitad derecha (Pro Micro)
qmk flash -kb splitkb/kyria/rev1 -km nieldm -bl avrdude-split-right
```

Una vez flasheado, cualquier cambio hecho desde Remappr/VIA queda en la EEPROM. Para volver al keymap de este archivo hay que borrar la EEPROM (`QK_CLEAR_EEPROM` o reflashear con EEPROM limpia), y después volver a flashear cada mitad para regrabar el lado.

Hay que flashear cada mitad una vez con su bootloader para que quede grabado el lado en la EEPROM.
