# So Long

**So Long** es un juego 2D sencillo desarrollado con miniLibX. El objetivo del jugador es recolectar todos los objetos del mapa y llegar a la salida, utilizando la ruta más eficiente posible. 

---

## 🎮 Funcionamiento del juego

- **Objetivo:** El jugador debe recoger todos los objetos (`C`) y alcanzar la salida (`E`), mientras sigue las reglas del mapa.
- **Controles:**
  - **W, A, S, D** o teclas de dirección: Mover al personaje en las 4 direcciones.
  - **ESC:** Cierra la ventana y termina el programa.
- **Restricciones de movimiento:**
  - El personaje no puede atravesar paredes (`1`).
  - Cada movimiento se registra y se muestra en la terminal.
- **Mapas:**
  - Construidos con los caracteres: `0` (espacio vacío), `1` (pared), `C` (coleccionable), `E` (salida), `P` (posición inicial del jugador).
  - Ejemplo de mapa válido:
    ```
    1111111111111
    10010000000C1
    1000011111001
    1P0011E000001
    1111111111111
    ```
  - Validaciones del mapa:
    - Debe estar cerrado (rodeado de muros).
    - Debe contener al menos un coleccionable, una salida y una posición inicial.
    - Debe ser rectangular.
    - Debe existir un camino válido desde el inicio hasta la salida.

---

## 📦 Recursos utilizados

El juego utiliza recursos descargados de *Itch.io*

- [Dungeon Tiles](https://cardinalzebra.itch.io/dungeon-tiles-1)
- [Undead Loot Pixel Art Icons](https://free-game-assets.itch.io/free-undead-loot-pixel-art-icons)
- [Hooded Protagonist](https://penzilla.itch.io/hooded-protagonist)

---

## 🖼️ Capturas de pantalla

<img width="416" alt="Captura 1" src="https://github.com/ezy0/so-long-42/assets/113242188/614b6325-b84c-4c8f-9dd0-8c48846b4a85">

<img width="898" alt="Captura 2" src="https://github.com/ezy0/so-long-42/assets/113242188/d4cecd12-4aa4-4950-a2ca-61a29964d8e0">

