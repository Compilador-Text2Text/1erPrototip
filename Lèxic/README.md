Funcionament
============

python3 explorer.py *nomFitxerDefinidor* *nomFitxerCodiFont*
- *nomFitxerDefinidor* �s el descriptor de com voldr� compilar.
- *nomFitxerCodiFont* �s el codi font.

Si retorna:
-----------

- 0, tot va b�.
- 1, el nom del fitxer no existeix.
- 2, no s'ha intrudu�t cap par�metre.
- 3, diem que entrem en mode Error L�xic.

Explicaci�
==========

Aquest document est� fet amb *python3* per la simplificaci� que dona al programar **REGEX** en relaci� *C*.
Tamb� permet treballar amb el sistema operatiu, ja que ens permet comunicar entre diferents llenguatges de programaci�.

Fins a on ens limitem
=====================

Suposem que el fitxer �s petit.
Llavors ens podem permetre el luxe de cargar tot el document a mem�ria.

Millores possibles
------------------
- Podria anar llegint el fitxer car�cter per car�cter.
- Compilar amb diferents ordinadors. Ja que ens comuniquem a *pipes* i la difer�ncia llavors �s m�nima.
- Hulman ???!!!
- Podria tenir par�metres, per tal de canviar les prestacions d'aquest programa.

Micelanius
==========

vars() de python3 �s on hi ha totes les variables.
En funcions tindr�................................

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
