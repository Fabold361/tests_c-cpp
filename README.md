# tests c/c++

Kurze Zusammenfassung: Sammlung alter Klausuren (SS 2026) für systemnahes Programmieren (C/C++) aus dem Elektrotechnik-Studium an der TU Wien.

Dieses Projekt ist mein persönliches Repository für C/C++-Übungen und alte Prüfungen. Ich sammle hier alle Laboraufgaben und Testdateien, damit ich später gezielt lernen und üben kann.

## Projektstruktur

- `lab1/` - Aufgaben und Testdateien aus Labor 1 (C++)
  - `testE.cpp` - Beispielaufgabe für Lab 1
- `lab2/` - Aufgaben und Testdateien aus Labor 2 (C++)
  - `testE.cpp` - Beispielaufgabe für Lab 2
- `lab3/` - Aufgaben und Testdateien aus Labor 3 (C++)
  - `testA.cpp`
  - `testB.cpp`
  - `testC.cpp`
  - `testD.cpp`
- `lab4/` - Platzhalterordner für Labor 4 (C/C++)
- `lab5/` - Platzhalterordner für Labor 5 (C/C++)
- `lab6/` - Platzhalterordner für Labor 6 (C/C++)
- `.clangd` - Konfiguration für `clangd`, damit C++20 verwendet wird
- `README.md` - Projektbeschreibung und Hinweise

## GitHub Repository

Wenn du das Repo auf GitHub erstellst, steht oben `owner / repository-name`.
Hier kannst du für den Repository-Namen beispielsweise `test` nehmen, weil das der Basisordner ist, der alles enthält.

Beispiel: `github.com/dein-benutzername/test`

## Nutzung

1. Code in den jeweiligen `labX/`-Ordner kopieren oder hinzufügen.
2. Mit `g++` oder einem passenden Buildsystem kompilieren.
3. Die Dateien sind so organisiert, dass jede Laboraufgabe ihren eigenen Ordner bekommt.

## Hinweise

- Wenn neue Labore oder Prüfungsaufgaben hinzukommen, einfach einen neuen Ordner `lab4/`, `lab5/` usw. anlegen.
- Ich kann hier auch Kommentare oder Zusammenfassungen zu jeder Aufgabe einfügen.
- Das Repository soll als Lernordner für alte Prüfungen dienen.

## Kompilieren

Beispiel:

```bash
g++ lab2/testE.cpp -std=c++20 -o lab2/testE
```

Bei Bedarf kann später ein `Makefile` oder `CMakeLists.txt` hinzugefügt werden.
