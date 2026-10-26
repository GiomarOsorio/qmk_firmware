import json, sys
src, out, info = sys.argv[1], sys.argv[2], sys.argv[3]
d = json.load(open(src))
names = ["Dvorak", "QWERTY", "Maple", "Numpad", "Symbols", "Util"]
M = {
 "KC_ESC":"Esc","KC_BSPC":"⌫","KC_LCTL":"Ctrl","KC_LSFT":"Shift","KC_RSFT":"Shift","KC_TAB":"Tab",
 "KC_LGUI":"Gui","KC_SPC":"Space","KC_ENT":"Enter","KC_LALT":"Alt","KC_DEL":"Del","KC_INS":"Ins",
 "KC_HOME":"Home","KC_END":"End","KC_PGUP":"PgUp","KC_PGDN":"PgDn","KC_CAPS":"Caps",
 "KC_LEFT":"←","KC_RIGHT":"→","KC_RGHT":"→","KC_UP":"↑","KC_DOWN":"↓",
 "KC_VOLD":"Vol−","KC_VOLU":"Vol+","KC_MUTE":"Mute","KC_MPRV":"⏮","KC_MPLY":"⏯","KC_MNXT":"⏭",
 "ES_QUOT":"'","ES_COMM":",","ES_DOT":".","ES_NTIL":"Ñ","ES_ACUT":{"t":"´","h":"dead"},"ES_PIPE":"|",
 "ES_MINS":"-","ES_PLUS":"+","ES_ASTR":"*","ES_SLSH":"/","ES_DLR":"$","ES_LBRC":"[","ES_LCBR":"{",
 "ES_LPRN":"(","ES_AMPR":"&","ES_EQL":"=","ES_EXLM":"!","ES_QUES":"?","ES_RPRN":")","ES_RCBR":"}",
 "ES_RBRC":"]","ES_NOT":"¬","ES_GRV":"`","ES_AT":"@","ES_NUMB":"#","ES_DQUO":"\"","ES_PERC":"%",
 "ES_TILD":"~","ES_BSLS":"\\","ES_UNDS":"_","ES_MORD":"º","ES_LABK":"<","ES_IEXL":"¡","ES_IQUE":"¿",
 "ES_RABK":">","ES_CIRC":"^",
 "NUMPAD":{"t":"Numpad","type":"held-num"},"SYMBOLS":{"t":"Symbols","type":"held-sym"},
 "UTIL":{"t":"Util","type":"held-util"},
 "ALT_OSS":{"t":"⇧ / Alt","h":"tap / hold"},
 "MW_COPY":"Copiar","MW_PASTE":"Pegar","MW_CUT":"Cortar","MW_PSCR":"Captura",
 "MW_WDS":"Ventanas","MW_LEFT":"Escr ←","MW_RIGHT":"Escr →",
 "TO_BASE":{"t":"→ Dvorak","type":"toggle"},"TG_QWRT":{"t":"QWERTY","h":"toggle","type":"toggle"},
 "TG_MAPL":{"t":"Maple","h":"toggle","type":"toggle"},"QK_BOOT":{"t":"Boot","type":"danger"},
 "RM_TOGG":"RGB on","RM_NEXT":"RGB modo","RM_HUEU":"Hue+","RM_HUED":"Hue−","RM_SATU":"Sat+",
 "RM_SATD":"Sat−","RM_VALU":"Brillo+","RM_VALD":"Brillo−","RM_SPDU":"Vel+","RM_SPDD":"Vel−",
 "MS_BTN1":"Clic 1","MS_BTN2":"Clic 2","MS_BTN3":"Clic 3","MS_BTN4":"Clic 4",
 "MS_LEFT":"🖱←","MS_DOWN":"🖱↓","MS_UP":"🖱↑","MS_RGHT":"🖱→",
 "MS_WHLL":"Rueda←","MS_WHLD":"Rueda↓","MS_WHLU":"Rueda↑","MS_WHLR":"Rueda→",
 "XXXXXXX":"","KC_NO":"","KC_TRNS":{"t":"▽","type":"trans"},
}
MAPLE_HINTS = {"KC_LCTL":"ataque","KC_LALT":"salto","KC_I":"inventario","KC_E":"equipo","KC_S":"stats",
 "KC_K":"skills","KC_Q":"quests","KC_M":"minimapa","KC_W":"mapa","KC_ENT":"chat"}
def lab(kc, layer):
    v = M.get(kc)
    if v is None:
        for p in ("ES_","KC_"):
            if kc.startswith(p): v = kc[len(p):]; break
        else: v = kc
    if isinstance(v, str): v = {"t": v}
    v = dict(v)
    if layer == "Maple" and kc in MAPLE_HINTS: v["h"] = MAPLE_HINTS[kc]
    if layer in ("Numpad","Symbols") and kc in ("NUMPAD","SYMBOLS"): v = {"t":v["t"],"type":"held"}
    return v
def yv(v):
    if v == {"t": ""}: return '""'
    if list(v) == ["t"]: return json.dumps(v["t"], ensure_ascii=False)
    return "{" + ", ".join(f"{k}: {json.dumps(x, ensure_ascii=False)}" for k, x in v.items()) + "}"
lines = [f"layout: {{qmk_info_json: {info}, layout_name: LAYOUT_split_3x6_3}}", "layers:"]
for n, keys in zip(names, d["layers"]):
    lines.append(f"  {n}:")
    for r in range(4):
        row = keys[r*12:(r+1)*12] if r < 3 else keys[36:42]
        lines.append("    - [" + ", ".join(yv(lab(k, n)) for k in row) + "]")
open(out, "w").write("\n".join(lines) + "\n")
