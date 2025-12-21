diagrams:
    keymap draw diagrams/iris_keymap.yaml > diagrams/iris_keymap.svg
    keymap draw diagrams/example_word_navigation.yaml > diagrams/example_word_navigation.svg
    keymap draw diagrams/example_word_navigation_multi.yaml > diagrams/example_word_navigation_multi.svg
    keymap draw diagrams/example_one_handed_arrows.yaml > diagrams/example_one_handed_arrows.svg

build:
    qmk compile -kb keebio/iris_ce/rev1 -km chloelee767

clean:
    qmk clean
