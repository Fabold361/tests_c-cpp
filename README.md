# tests c/c++

Kurze Zusammenfassung: Sammlung alter Klausuren (SS 2026) für systemnahes Programmieren (C/C++) aus dem Elektrotechnik-Studium an der TU Wien.

Dieses Projekt ist mein persönliches Repository für C/C++-Übungen und alte Prüfungen. Ich sammle hier alle Laboraufgaben und Testdateien, damit ich später gezielt lernen und üben kann.

## Projektstruktur

- `lab1/` - Aufgaben und Testdateien aus Labor 1 (C++)
  - `Angabe/` - Angabe als PDF
  - `Code/testE.cpp` - Beispielaufgabe für Lab 1
- `lab2/` - Aufgaben und Testdateien aus Labor 2 (C++)
  - `Angabe/` - Angabe als PDF
  - `Code/testE.cpp` - Beispielaufgabe für Lab 2
- `lab3/` - Aufgaben und Testdateien aus Labor 3 (C++)
  - `Angabe/` - Angaben als Bilder/PDF
  - `Code/testA.cpp`
  - `Code/testB.cpp`
  - `Code/testC.cpp`
  - `Code/testD.cpp`
  - `Code/testE.cpp`
- `lab4/` - Aufgaben und Testdateien aus Labor 4 (C++)
  - `Angabe/` - Angabe als Bild
  - `Code/testB.cpp`
- `lab5/` - Aufgaben und Testdateien aus Labor 5 (C)
  - `Angabe/` - Angaben als Bilder/PDF
  - `Code/testE.c` - Abgabe Gruppe E: `concatenate`
  - `Code/testF.c` - Abgabe Gruppe F: `erase_all_of`
- `lab6/` - Aufgaben und Testdateien aus Labor 6 (C/C++)
  - `Angabe/` - Angaben als Bilder/PDF
  - `Code/testE.c`, `Code/testE.cpp` - Aufgabe E (C und C++)
  - `Code/testA.cpp` … `Code/testD.cpp` - Aufgaben A-D
- `output/` - Kompilierte Binaries (via `.gitignore` nicht im Repo)
- `.gitignore` - Ignoriert Build-Dateien und Output-Ordner
- `README.md` - Projektbeschreibung und Hinweise

## GitHub Repository

`github.com/Fabold361/tests_c-cpp`

## Nutzung

1. Repo klonen und im Root-Ordner (`tests_c-cpp/`) in VS Code öffnen.
2. In den jeweiligen `labX/Code/`-Ordner navigieren und die gewünschte Datei kompilieren.
3. Die Dateien sind so organisiert, dass jede Laboraufgabe ihren eigenen Ordner bekommt.

## Kompilieren

### C++ (lab1–lab4)

Vom Root-Ordner (`tests_c-cpp/`) aus:

```bash
mkdir -p output && g++ -fmax-errors=1 -std=c++20 labX/Code/testX.cpp -o output/testX && ./output/testX
```

Beispiel für Lab 4, Aufgabe B:

```bash
mkdir -p output && g++ -fmax-errors=1 -std=c++20 lab4/Code/testB.cpp -o output/testB && ./output/testB
```

### C (lab5+)

```bash
mkdir -p output && gcc -g -fsanitize=address -fmax-errors=1 -std=c11 labX/Code/testX.c -o output/testX -lm && ./output/testX
```

Beispiel für Lab 5, Aufgabe F:

```bash
mkdir -p output && gcc -g -fsanitize=address -fmax-errors=1 -std=c11 lab5/Code/testF.c -o output/testF -lm && ./output/testF
```

Lab 6 enthält sowohl C- als auch C++-Dateien (z. B. `testE.c` und `testE.cpp` für dieselbe Aufgabe) - je nach Datei mit `gcc` bzw. `g++` kompilieren.

## Hinweise

- Wenn neue Labore oder Prüfungsaufgaben hinzukommen, einfach einen neuen Ordner `labX/` mit `Angabe/` und `Code/` anlegen.
- Build-Dateien und der `output/`-Ordner werden via `.gitignore` nicht ins Repo gepusht.
