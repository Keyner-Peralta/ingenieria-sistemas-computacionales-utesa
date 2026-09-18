# ▶️ Cómo ejecutar los programas en Java

Este directorio contiene múltiples programas desarrollados en **Java** como parte de la asignatura **Programación 2**.

A continuación, se presentan dos formas de ejecutarlos: **en línea** y **de forma local** en tu computadora.

---

## 🌐 Opción 1: Ejecutar en línea (OnlineGDB)

Puedes ejecutar los programas sin instalar nada utilizando un compilador de Java en línea:

🔗 https://www.onlinegdb.com/online_java_compiler

### Pasos:

1. Abre el enlace anterior.
2. Copia el código del archivo `.java` que deseas ejecutar.
3. Pégalo en el editor.
4. Haz clic en **Run**.
5. Observa la salida en la consola.

📌 **Ventajas:**

* No requiere instalación.
* Ideal para probar programas rápidamente.
* Permite ejecutar código Java desde el navegador.

---

## 💻 Opción 2: Ejecutar en tu computadora

Para ejecutar los programas de forma local necesitas tener instalado el **JDK (Java Development Kit)**.

### Requisitos:

* Java JDK
* Un editor de código, como Visual Studio Code, IntelliJ IDEA o cualquier otro.
* Terminal o consola.

Puedes comprobar si Java está instalado ejecutando:

```bash
java --version
```

Y para comprobar que el compilador está disponible:

```bash
javac --version
```

---

### 🟦 Método 1: Usando Visual Studio Code

#### Requisitos:

* Visual Studio Code
* Extensión **Extension Pack for Java**
* Java JDK

#### Pasos:

1. Instala Visual Studio Code.
2. Instala **Extension Pack for Java**.
3. Instala un JDK si todavía no lo tienes.
4. Abre la carpeta `Programacion 2` en VS Code.
5. Abre el archivo `.java` que deseas ejecutar.
6. Ejecuta el programa utilizando el botón **Run** que aparece sobre el método `main`.

También puedes ejecutarlo desde la terminal.

---

### 🟩 Método 2: Usando la terminal

Primero, entra en la carpeta donde se encuentra el archivo:

```bash
cd "Programacion 2"
```

Después, compila el archivo:

```bash
javac Main.java
```

Finalmente, ejecuta el programa:

```bash
java Main
```

> **Nota:** Cambia `Main.java` por el nombre del archivo que quieras ejecutar. Si el archivo contiene una clase pública, el nombre de la clase y el archivo deben coincidir.

---

## 📚 Contenido

Los programas de este directorio incluyen ejercicios relacionados con temas de **Programación 2**, como:

* Variables y tipos de datos.
* Entrada de datos.
* Métodos.
* Arrays.
* Estructuras de control.
* Programación Orientada a Objetos.

También se incluye el **proyecto final** de la asignatura.
