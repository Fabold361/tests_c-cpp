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
- `lab5/` - Platzhalterordner für Labor 5 (C/C++)
- `lab6/` - Platzhalterordner für Labor 6 (C/C++)
- `.gitignore` - Ignoriert Build-Dateien
- `README.md` - Projektbeschreibung und Hinweise

## GitHub Repository

`github.com/Fabold361/tests_c-cpp`

## Nutzung

1. Repo klonen und im Root-Ordner (`tests_c-cpp/`) in VS Code öffnen.
2. In den jeweiligen `labX/Code/`-Ordner navigieren und die gewünschte Datei kompilieren.
3. Die Dateien sind so organisiert, dass jede Laboraufgabe ihren eigenen Ordner bekommt.

## Kompilieren

Vom Root-Ordner (`tests_c-cpp/`) aus:

```bash
g++ -fmax-errors=1 -std=c++20 labX/Code/testX.cpp -o labX/Code/testX && ./labX/Code/testX
```

Beispiel für Lab 4, Aufgabe B:

```bash
g++ -fmax-errors=1 -std=c++20 lab4/Code/testB.cpp -o lab4/Code/testB && ./lab4/Code/testB
```

## Hinweise

- Wenn neue Labore oder Prüfungsaufgaben hinzukommen, einfach einen neuen Ordner `labX/` mit `Angabe/` und `Code/` anlegen.
- Build-Dateien werden via `.gitignore` nicht ins Repo gepusht.
