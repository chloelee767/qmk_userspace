# CLAUDE.md for qmk_userspace

This is a QMK userspace project for a split keyboard.

## General concepts

### Key order

This diagram shows the physical layout of the keyboard with the key order labelled.
```
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │           │ 6 │ 7 │ 8 │ 9 │10 │11 │
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│12 │13 │14 │15 │16 │17 │           │18 │19 │20 │21 │22 │23 │
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│24 │25 │26 │27 │28 │29 │           │30 │31 │32 │33 │34 │35 │
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│36 │37 │38 │39 │40 │41 ┌───┐  ┌───┐│44 │45 │46 │47 │48 │49 │
└───└───└───└─┌───┌───┐─│42 │  │43 │└─┌───┌───┐─└───└───└───┘
              │50 │51 ┌───┐─┘  └─┌───┐│54 │55 │
              └───└───│52 │      │53 │└───└───┘
                      └───┘      └───┘
```

The key order is used in:

1. QMK code: specifically, the `keymaps[][MATRIX_ROWS][MATRIX_COLS]` in `keymap.c`
example:
```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] =
  LAYOUT(
    /* Number Row */
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
// ...
```

based on this example, the keys on physical keyboard:
```
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │           │ 6 │ 7 │ 8 │ 9 │ 0 │ = │
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐

```

2. `caksoylar/keymap-drawer` YAML files
example (using the same layout as the QMK code above):
```yaml
layers:
  BASE:
  # Number Row
  - ['`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '=']
# ...
```

### Key matrix positions

This diagram shows the physical layout of the keyboard with the matrix positions labelled in `row,column` format.
```
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│0,0│0,1│0,2│0,3│0,4│0,5│           │5,5│5,4│5,3│5,2│5,1│5,0│
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│1,0│1,1│1,2│1,3│1,4│1,5│           │6,5│6,4│6,3│6,2│6,1│6,0│
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│2,0│2,1│2,2│2,3│2,4│2,5│           │7,5│7,4│7,3│7,2│7,1│7,0│
┌───┌───┌───┌───┌───┌───┐           ┌───┌───┌───┌───┌───┌───┐
│3,0│3,1│3,2│3,3│3,4│3,5┌───┐  ┌───┐│8,5│8,4│8,3│8,2│8,1│8,0│
└───└───└───└─┌───┌───┐─│4,5│  │9,5│└─┌───┌───┐─└───└───└───┘
              │4,2│4,3┌───┐─┘  └─┌───┐│9,3│9,2│
              └───└───│4,4│      │9,4│└───└───┘
                      └───┘      └───┘
```

The matrix positions are used in some QMK code, eg. per-key LEDs

## QMK firmware

How to build the firmware: `just build`

## Keymap diagrams

We have multiple SVG diagrams created using the `caksoylar/keymap-drawer` tool.
Updating the diagram:
- Update the relevant yaml file in `diagrams/*.yaml`
- Run `just diagrams` to regenerate the SVGs

### Conventions

- The "QWERTY" layer in the QMK code is named "BASE" in the diagram
- The "MULTIMEDIA" layer in the QMK code is named "MEDIA" in the diagram

### Syntax for keymap yaml:

Syntax for keys:
- `{t: ▽, type: trans}`: transparent key (ie. pass through to next layer in stack). `_______` in QMK
- `null`: empty key. `XXXXXXX` in QMK
- `{h: Shift, t: Enter}`: `h:` means hold, `t:` means tap. In this example, it means Shift on hold and Enter on tap.
- `'$$mdi:arrow-up$$'`: these are custom SVG glyphs to display on the keymap
> From Documentation:
> keymap-drawer can also use SVG glyphs for legends, in addition to plain or unicode text. The easiest way to do this is to use the $$source:id$$ notation certain sources, which will automatically fetch the SVGs from a given remote source, e.g. using $$mdi:volume-mute$$ will insert the mute icon from Material Design Icons. The following source values are currently supported:
> mdi: Pictogrammers Material Design Icons (use icon name as id)
> mdil: Pictogrammers Material Design Icons Light (use icon name as id)
> material: Google Material Symbols (use value in "Android" tab as id)
> tabler: Tabler Icons ("Outline" style, use icon name as id)
> phosphor: Phosphor Icons (use <weight>/<name> as id, e.g. $$phosphor:bold/lock$$)
> fa: Font Awesome (use <type>/<name> as id where type is solid, regular or brands, e.g. $$fa:brands/apple$$)

