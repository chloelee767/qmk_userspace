# QMK Userspace

## Keebio Iris

![Keyboard layout](./iris_keymap.svg)

## Development

First time setup:
- Setup the QMK toolchain (see the docs), this is needed for the `qmk` CLI to work

Building the firmware: 
- Build the firmware: `qmk compile -kb keebio/iris_ce/rev1 -km chloelee767`

How to reflash the keyboard:
- Go to multimedia layer (top uncovered thumb keys) + press top left (left half) / top right key (right half)
- Ideally we should flash both halves of the keyboard. Some features will work fine after flashing both halves (which firmware we use depends on which half is plugged in as the main), some will not.

Regenerating the diagram:
- Update `iris_keymap.yaml`
- Run `keymap draw iris_keymap.yaml > iris_keymap.svg`
