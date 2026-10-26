import re, sys, html
S = sys.argv[1]
layers = [
 ("Dvorak", "base", "Capa base", "Siempre activa. Dvorak con Ñ y acento muerto en la mano derecha para alternar con las vocales.",
  ["´ + vocal = á é í ó ú", "Pulgar derecho externo: toque = Shift de un toque, mantener = Alt", "Doble toque en Shift izquierdo = Caps Word (CPSWD en la OLED)"]),
 ("QWERTY", "toggle", "Util → 2ª tecla", "QWERTY estándar para juegos. Sin tecla Gui, para que no te saque del juego.",
  ["Tab en el pulgar izquierdo externo", "Números y F1–F12 en Numpad", "Volver: Util → → Dvorak"]),
 ("Maple", "toggle", "Util → 3ª tecla", "MapleStory Classic World con los atajos por defecto del juego.",
  ["Ctrl = ataque, Alt = salto, ambos en los pulgares", "Ins/Home/PgUp/Del/End/PgDn: slots de skills y pociones", "Volver: mantener Util (pulgar derecho externo) → → Dvorak", "Las letras de ventanas son las de fábrica; revísalas en el juego"]),
 ("Numpad", "hold-num", "Mantener pulgar izq. del medio", "Números, F1–F12, flechas y atajos de edición.",
  ["Copiar / Pegar / Cortar / Captura en los pulgares (Cmd en Mac, Ctrl en Linux y Windows)", "Escr ←/→ cambia de escritorio virtual; Ventanas abre la vista general"]),
 ("Symbols", "hold-sym", "Mantener pulgar der. del medio", "Signos de programación, signos de español y controles multimedia.",
  ["Los paréntesis, llaves y corchetes abren a la izquierda y cierran a la derecha en espejo", "¿ y ¡ en la fila inferior"]),
 ("Util", "hold-util", "Numpad + Symbols a la vez", "Cambio de capas, RGB y mouse.",
  ["→ Dvorak apaga QWERTY y Maple a la vez", "Boot está en la esquina derecha, lejos de los toggles", "Mouse: flechas en la fila central derecha, rueda abajo, clics arriba"]),
]
def svg_for(name):
    s = open(f"{S}/layer_{name}.svg", encoding="utf-8").read()
    s = re.sub(r"<style>.*?</style>", "", s, flags=re.S)
    s = re.sub(r'<text x="[^"]*" y="[^"]*" class="label"[^>]*>.*?</text>', "", s, flags=re.S)
    s = re.sub(r'<svg width="(\d+)" height="(\d+)" viewBox="0 0 (\d+) (\d+)"', lambda m: f'<svg viewBox="0 48 {m.group(3)} {int(m.group(4))-92}" role="img" aria-label="Capa {name}"', s, count=1)
    return s
tags = {"base":"Base","toggle":"Toggle","hold-num":"Mantener","hold-sym":"Mantener","hold-util":"Mantener"}
sections = []
for name, kind, how, desc, notes in layers:
    lis = "".join(f"<li>{html.escape(n)}</li>" for n in notes)
    sections.append(f'''<section class="layer" id="{name.lower()}">
  <header class="layer-head">
    <div class="titles"><h2>{name}</h2><p class="desc">{html.escape(desc)}</p></div>
    <span class="how {kind}"><b>{tags[kind]}</b>{html.escape(how)}</span>
  </header>
  <div class="board">{svg_for(name)}</div>
  <ul class="notes">{lis}</ul>
</section>''')
nav = "".join(f'<a href="#{n.lower()}">{n}</a>' for n, *_ in layers)
tpl = open(sys.argv[2], encoding="utf-8").read()
out = tpl.replace("{{NAV}}", nav).replace("{{SECTIONS}}", "\n".join(sections))
open(sys.argv[3], "w", encoding="utf-8").write(out)
