# QMK Keymaps

![ferris-sweep](./assets/img/keyboards/ferris-sweep.jpg)

## Features
* **Autocorrect**
* **Case Modes**
* **Combos**
* **Home Row Mods**
* **Leader Key**
* **Repeat / Magic Keys**

## My Keymap
![ferris-keymap](./assets/img/keymaps/ferris-sajenim.svg)

See [**magic sturdy**](https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md) for usage of the magic key.

## Installation
Follow the [getting started](https://docs.qmk.fm/#/newbs_getting_started) docs to install [QMK Firmware](https://docs.qmk.fm/#/)

```sh
# Clone the keymaps
git clone https://git.sajenim.dev/jasmine/qmk_userspace.git
    
# Setup external userspace
qmk config user.overlay_dir="$(realpath qmk_userspace)"

# Compile the firmware
qmk compile -kb <keyboard> -km <keymap>
```

## References
* [Precondition](https://precondition.github.io/home-row-mods)
* [Pascal Getreuer](https://getreuer.info/posts/keyboards/index.html)
* [Ikcelaks](https://github.com/Ikcelaks/keyboard_layouts/tree/main)
* [Andrew Rae](https://github.com/andrewjrae/kyria-keymap)
* [Jonas Hietala](https://www.jonashietala.se/series/t-34/)
