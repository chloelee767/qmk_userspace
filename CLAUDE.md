# About the keymap diagram

## How to redraw the keymap diagram:
``` sh
keymap draw iris_keymap.yaml > iris_keymap.svg
```

## Conventionsd 

- The "QWERTY" layer in the QMK code is named "BASE" in the diagram 

## Syntax for keymap yaml:

Syntx for keys:
- `{t: ▽, type: trans}`: transparent key (ie. pass through to next layer in stack). `_______` in QMK 
- `null`: empty key. `XXXXXXX` in QMK
- `{h: Shift, t: Enter}`: `h:` means hold, `t:` means tap. In this example, it means Shift on hold and Enter on tap. 


