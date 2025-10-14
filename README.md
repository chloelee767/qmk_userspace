# QMK Userspace

## Keebio Iris

Notes: 
- for the layer switch keys, only 1 of the shaded key needs to be held. That is to say, most layers have multiple possible layer switch keys.
- dotted outline keys: rarely used keys, considering to remove

![Keyboard layout](./diagrams/iris_keymap.svg)

## Development

First time setup:
- Setup the QMK toolchain (see the docs), this is needed for the `qmk` CLI to work
- Install just

Building the firmware: 
- Build the firmware: `just build`

How to reflash the keyboard:
- Go to multimedia layer (top uncovered thumb keys) + press top left (left half) / top right key (right half)
- Ideally we should flash both halves of the keyboard. Some features will work fine after flashing just 1 half (which firmware we use depends on which half is plugged in as the main), some will not.

Updating the diagram:
- Update `diagrams/iris_keymap.yaml`
- Run `just diagrams`
