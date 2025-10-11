diagrams:
    keymap draw diagrams/iris_keymap.yaml > diagrams/iris_keymap.svg

build:
    qmk compile -kb keebio/iris_ce/rev1 -km chloelee767

clean:
    qmk clean