Évaluation
~~~~~~~~~~

+-------------------------+----------------------------+-----------+-----------+
| Critère                 | Sous-critère               | Résultat  | Sur       |
+=========================+============================+===========+===========+
|                         | Chargement des pays        | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Chargement des villes      | 10        | 10        |
|                         +----------------------------+-----------+-----------+
| Fonctionnabilité        | Tri selon la population    | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Arguments de la fonction   | 5         | 10        |
|                         | ``main``                   |           |           |
|                         +----------------------------+-----------+-----------+
|                         | Qualité de l'affichage     | 8         | 10        |
|                         | (colonnes alignées)        |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Modularité fonctionnelle   | 10        | 10        |
|                         +----------------------------+-----------+-----------+
|                         | Style de programmation     | 4         | 5         |
| Qualité du code         +----------------------------+-----------+-----------+
|                         | Documentation (en-tête du  | 5         | 5         |
|                         | fichier et des fonctions)  |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Compilation et nettoyage   |           |           |
|                         | (``make`` et               | 10        | 10        |
|                         | ``make clean``)            |           |           |
| Makefile                +----------------------------+-----------+-----------+
|                         | Téléchargement des données | 5         | 5         |
|                         | (``make database``)        |           |           |
+-------------------------+----------------------------+-----------+-----------+
|                         | Commits significatifs      | 10        | 10        |
| Utilisation de Git      +----------------------------+-----------+-----------+
|                         | Qualité des messages de    | 4         | 5         |
|                         | commits                    |           |           |
+-------------------------+----------------------------+-----------+-----------+
| **Total**                                            | **91**    | **100**   |
+-------------------------+----------------------------+-----------+-----------+

Commentaires
------------

- Compilation correcte;
- Au niveau de l'exécution, erreur de segmentation si le paramètre n'est pas
  valide ou si les fichiers n'existent pas.
- Le formatage n'est pas très propre (trop d'espaces superflus).
- Bonne modularité.
- Style de programmation très bien. Peut-être s'assurer que l'espacement soit
  un peu plus uniforme. Le ``main`` est un peu long aussi.
- Le fichier README n'utilise pas Markdown à son plein potentiel. Pour les
  énumérations, utiliser les listes (à l'aide de tirets), pour les bouts de
  code, utiliser la syntaxe pour les délimiter (voir par exemple
  https://bitbucket.org/tutorials/markdowndemo/overview#markdown-header-code-and-syntax-highlighting).
- Makefile impeccable.
- Bonne utilisation de Git. Certains messages de commit (notamment les
  premiers), manquent de précision. Il est important de prendre la peine de
  bien rédiger un message de commit. Aussi, le fichier ``.gitignore`` devrait
  contenir les fichiers qui sont téléchargés.
