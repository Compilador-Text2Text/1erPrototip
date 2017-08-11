Funcionament
============

python3 explorer.py *nomFitxerDefinidor* *nomFitxerCodiFont*
- *nomFitxerDefinidor* és el descriptor de com voldrà compilar.
- *nomFitxerCodiFont* és el codi font.

Si retorna:
-----------

- 0, tot va bé.
- 1, el nom del fitxer no existeix.
- 2, no s'ha intruduït cap paràmetre.
- 3, diem que entrem en mode Error Lèxic.

Explicació
==========

Aquest document està fet amb *python3* per la simplificació que dona al programar **REGEX** en relació *C*.
També permet treballar amb el sistema operatiu, ja que ens permet comunicar entre diferents llenguatges de programació.

Fins a on ens limitem
=====================

Suposem que el fitxer és petit.
Llavors ens podem permetre el luxe de cargar tot el document a memòria.

Millores possibles
------------------
- Podria anar llegint el fitxer caràcter per caràcter.
- Compilar amb diferents ordinadors. Ja que ens comuniquem a *pipes* i la diferència llavors és mínima.
- Hulman ???!!!
- Podria tenir paràmetres, per tal de canviar les prestacions d'aquest programa.

Micelanius
==========

vars() de python3 és on hi ha totes les variables.
En funcions tindrà................................

debug
-----
- `-m pdf`
```
import pdb
pdb.run('algo')
```

Errors
======

- No accepta accents.
