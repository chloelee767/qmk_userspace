This is a QMK userspace project for a split keyboard.

## QMK firmware

How to build the firmware: `just build`

## Keymap diagrams

We have a SVG diagram created using the `caksoylar/keymap-drawer` tool. 
Updating the diagram:
- Update `diagrams/iris_keymap.yaml`
- Run `just diagrams`

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

