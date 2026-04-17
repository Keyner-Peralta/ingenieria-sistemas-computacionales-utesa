# ▶️ Cómo ejecutar los programas en C++

Este repositorio contiene múltiples programas desarrollados en C++.  
A continuación, se presentan dos formas de ejecutarlos: **en línea** y **de forma local** en tu computadora.

---

## 🌐 Opción 1: Ejecutar en línea (cpp.sh)

Puedes ejecutar los programas sin instalar nada utilizando el compilador en línea:

🔗 https://cpp.sh/

### Pasos:

1. Abre el enlace anterior.
2. Copia el código del archivo `.cpp` que deseas ejecutar.
3. Pégalo en el editor de la página.
4. Haz clic en el botón **Run**.
5. Observa la salida en la consola.

📌 Ventajas:
- No requiere instalación.
- Ideal para pruebas rápidas.

---

## 💻 Opción 2: Ejecutar en tu computadora (compilador local)

Para ejecutar los programas de forma local, necesitas un compilador de C++.

---

### 🟦 Método 1: Usando Visual Studio Code

#### Requisitos:
- Visual Studio Code  
- Extensión de C/C++  
- Compilador (MinGW o similar)

#### Pasos:

1. Instala Visual Studio Code.
2. Instala la extensión **C/C++**.
3. Instala un compilador como **MinGW**.
4. Abre la carpeta del proyecto en VS Code.
5. Abre el archivo `.cpp`.
6. Ejecuta el programa desde la terminal:

```bash
g++ archivo.cpp -o programa
./programa
