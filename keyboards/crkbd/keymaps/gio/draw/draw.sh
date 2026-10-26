#!/usr/bin/env bash
# Regenera las imagenes del layout: draw/keymap.svg (todas las capas) y draw/keymap.html (pagina)
# Requiere: qmk CLI y keymap-drawer (uv tool install keymap-drawer)
set -euo pipefail

DIR="$(cd "$(dirname "$0")" && pwd)"
QMK_HOME="$(cd "$DIR/../../../../.." && pwd)"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

qmk c2json -kb crkbd/rev1 -km gio --no-cpp "$DIR/../keymap.c" -o "$TMP/gio.json" >/dev/null
python3 "$DIR/build_yaml.py" "$TMP/gio.json" "$TMP/gio.yaml" "$QMK_HOME/keyboards/crkbd/info.json"

keymap -c "$DIR/draw.yaml" draw "$TMP/gio.yaml" -o "$DIR/keymap.svg"
for layer in Dvorak QWERTY Maple Numpad Symbols Util; do
    keymap -c "$DIR/draw.yaml" draw "$TMP/gio.yaml" -s "$layer" -o "$TMP/layer_$layer.svg"
done
python3 "$DIR/build_html.py" "$TMP" "$DIR/page.tpl.html" "$DIR/keymap.html"

echo "Listo: $DIR/keymap.svg y $DIR/keymap.html"
