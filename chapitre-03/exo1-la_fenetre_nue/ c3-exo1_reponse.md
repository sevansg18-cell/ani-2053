# Fenetre nue

## 1. Création du kit

Pour faire cet exercice, j'ai d'abord généré le kit dans un dossier sur mon bureau appelé **Mon workspace**.

La commande utilisée pour générer le kit est :

```
jenga kit --target NKWindows --outpout "C:\Users\cloth\OneDrive\Bureau\Mon workspace" --platform windows --config Debug
```

Le dossier généré contient notamment :

```
Mon workspace
│
├── include
│   ├── NKContainer
│   ├── ...
│
├── lib
│   └── Debug-Windows
│
├── KIT.txt
└── Monworkspace.jenga
```

J'ai ensuite créé mon espace de travail dans :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow
```

Dans ce dossier, on trouve notamment :

```
FirstWindow
├── .jenga
├── .jenga-typings
├── Build
├── Mon workspace
├── Window
├── .gitignore
├── FirstWindow.jenga
└── pyrightconfig.json
```

# 2. Programme réalisé

Pour commencer l'exercice, j'ai écrit un programme permettant de créer une fenêtre avec une taille initiale de **1280 × 720**.

Le programme utilisé est le suivant :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKLogger/NkSink.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"

#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```

Le programme contient **25 lignes physiques**, en comptant les lignes vides.


# 3. Explication du programme ligne par ligne

## Ligne 1

```
#include "NKWindow/NKWindow.h"
```

Cette ligne inclut le fichier d'en-tête principal de `NKWindow`.

Il permet notamment d'utiliser les éléments nécessaires à la création et à la gestion de la fenêtre, comme `NkWindow` et `NkWindowConfig`.


## Ligne 2

```
#include "NKWindow/NKMain.h"
```

Cette ligne inclut les éléments nécessaires au point d'entrée de l'application NKEntseu, notamment la fonction `nkmain`.


## Ligne 3

```
#include "NKLogger/NkSink.h"
```

Cette ligne permet d'utiliser le système de journalisation.

Elle est nécessaire dans mon programme car j'utilise ensuite :

```
logger.Error("[app] creation fenetre echouee");
```

pour signaler une erreur lorsque la création de la fenêtre échoue.

Cette ligne n'est pas présente dans le code du chapitre fourni.


## Ligne 4

```
#include "NKTime/NkTime.h"
```

Cette ligne inclut les fonctionnalités liées au temps.

Elle n'est pas utilisée directement dans le programme actuel, mais elle faisait partie des inclusions utilisées dans mon environnement de travail.

Cette ligne n'est pas présente dans le code du chapitre.


## Ligne 5

```
#include "NKTime/NkChrono.h"
```

Cette ligne inclut les fonctionnalités de chronométrage liées au temps.

Elle n'est pas utilisée directement dans ce programme.

Elle n'est pas présente dans le code du chapitre.


## Ligne 6

Ligne vide.

Elle sert uniquement à séparer les différents groupes d'inclusions afin de rendre le code plus lisible.


## Ligne 7

```
#include "NKEvent/NkWindowEvent.h"
```

Cette ligne inclut les événements liés à la fenêtre.

Elle permet notamment de disposer des types nécessaires à la gestion des événements de fenêtre dans les développements suivants.

Elle n'est pas présente dans le code du chapitre.


## Ligne 8

```
#include "NKEvent/NkKeyboardEvent.h"
```

Cette ligne inclut les événements liés au clavier.

Elle n'est pas présente dans le code du chapitre.


## Ligne 10

```
using namespace nkentseu;
```

Cette instruction permet d'utiliser les éléments du namespace `nkentseu` sans devoir écrire `nkentseu::` devant chaque élément.

Elle est nécessaire pour pouvoir écrire directement :

```
NkWindow
NkWindowConfig
NkEntryState
```

## Ligne 12

```
int nkmain(const NkEntryState &state) {
```

Cette ligne définit le point d'entrée de l'application.

La fonction `nkmain` reçoit l'état d'entrée `state` et retourne un entier.


## Ligne 13

```
NkWindowConfig cfg;
```

Cette ligne crée une configuration de fenêtre appelée `cfg`.

Cette configuration va ensuite recevoir le titre, la largeur et la hauteur de la fenêtre.


## Ligne 14

```
cfg.title  = "Ma fenetre";
```

Cette ligne définit le titre de la fenêtre.

Le titre affiché est :

```
Ma fenetre
```


## Ligne 15

```
cfg.width  = 1280;
```

Cette ligne définit la largeur initiale de la fenêtre à **1280 pixels**.


## Ligne 16

```
cfg.height = 720;
```

Cette ligne définit la hauteur initiale de la fenêtre à **720 pixels**.

La taille initiale demandée est donc :

```
1280 × 720
```

## Ligne 18

```
NkWindow window(cfg);
```

Cette ligne crée l'objet `window` à partir de la configuration `cfg`.

La fenêtre est donc créée avec les paramètres définis précédemment.


## Ligne 19

```
if (!window.IsOpen()) {
```

Cette condition vérifie si la fenêtre a bien été ouverte.

Si `IsOpen()` retourne `false`, le `!` transforme cette valeur en `true` et le programme entre dans le bloc d'erreur.


## Ligne 20

```
logger.Error("[app] creation fenetre echouee");
```

Si la fenêtre n'a pas pu être créée, cette ligne écrit un message d'erreur dans le système de logs.

Le message est :

```
[app] creation fenetre echouee
```


## Ligne 21

```
return -1;
```

Cette ligne arrête le programme avec le code de retour `-1`.

Elle indique que le programme s'est terminé à cause d'une erreur.


## Ligne 22

```
}
```

Cette accolade ferme le bloc de la condition `if`.


## Ligne 23

```
while (window.IsOpen()) { /* les evenements arrivent ici */ }
```

Cette boucle continue tant que la fenêtre est ouverte.

Le commentaire indique que les événements doivent être traités à cet endroit.

Dans le chapitre, cette boucle est présentée sur plusieurs lignes :

```
while (window.IsOpen()) {
    // les evenements arrivent ici (chapitre 4)
}
```

La logique est donc la même, mais la présentation est différente.


## Ligne 24

```
return 0;
```

Cette ligne indique que le programme s'est terminé normalement.

Le code `0` correspond à une fin sans erreur.


## Ligne 25

```
}
```

Cette accolade ferme la fonction `nkmain`.


# 4. Résultat obtenu

Après avoir écrit le programme, j'ai utilisé Jenga pour compiler et exécuter le projet.

La compilation et l'exécution permettent d'obtenir une fenêtre.

La taille initiale demandée dans le programme est :

```
1280 × 720
```

Le programme vérifie également que la fenêtre a bien été créée avant d'entrer dans la boucle principale.


# 5. Comparaison avec le code du chapitre

Le code du chapitre fourni dans l'exercice est :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

NKENTSEU_DEFINE_APP_DATA([]() {
    NkAppData d{};
    d.appName = "MaFenetre";
    d.appVersion = "1.0.0";
    return d;
}());

int nkmain(const NkEntryState &state) {

    NkWindowConfig cfg;

    cfg.title = "Ma fenetre";
    cfg.width = 1280;
    cfg.height = 720;

    NkWindow window(cfg);

    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    while (window.IsOpen()) {
        // les evenements arrivent ici (chapitre 4)
    }

    return 0;
}
```

Le chapitre contient **27 lignes physiques** lorsqu'on conserve les lignes vides et le bloc de déclaration des données de l'application.

Mon programme et celui du chapitre ont donc une structure très proche, mais ils ne sont pas identiques.


# 6. Comparaison ligne par ligne

## Lignes 1 et 2

Mon programme :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
```

Chapitre :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
```

**Correspondance : identique.**

Ces deux lignes servent à inclure les éléments principaux de `NKWindow`.


## Lignes 3 à 5

Mon programme contient :

```
#include "NKLogger/NkSink.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"
```

Ces trois lignes ne sont pas présentes dans le code du chapitre.

Elles constituent donc une première différence entre les deux programmes.

La première est utilisée pour le logger, tandis que les deux autres concernent les fonctionnalités de temps.


## Lignes 7 et 8

Mon programme contient :

```
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
```

Ces deux inclusions ne sont pas présentes dans le code du chapitre fourni.

Elles constituent donc également des lignes supplémentaires dans mon programme.


## Bloc `NKENTSEU_DEFINE_APP_DATA`

Le chapitre contient :

```
NKENTSEU_DEFINE_APP_DATA([]() {
    NkAppData d{};
    d.appName = "MaFenetre";
    d.appVersion = "1.0.0";
    return d;
}());
```

Ce bloc est **complètement absent de mon programme**.

C'est une différence importante.

Le chapitre définit ici les données de l'application :

```
d.appName = "MaFenetre";
d.appVersion = "1.0.0";
```

Mon programme ne définit pas ces données d'application.

Je ne peux donc pas affirmer que seules trois lignes diffèrent entre les deux programmes.


## `using namespace`

Mon programme contient :

```
using namespace nkentseu;
```

Le chapitre contient également cette instruction.

**Correspondance : identique.**


## Fonction `nkmain`

Mon programme :

```
int nkmain(const NkEntryState &state) {
```

Le chapitre :

```
int nkmain(const NkEntryState &state) {
```

**Correspondance : identique.**



## Configuration

Les deux programmes contiennent :

```
NkWindowConfig cfg;
```

**Correspondance : identique.**


## Titre

Mon programme :

```
cfg.title  = "Ma fenetre";
```

Chapitre :

```
cfg.title = "Ma fenetre";
```

L'instruction est la même.

La seule différence est l'espacement supplémentaire avant le `=` dans mon programme.

**Correspondance : même instruction, présentation différente.**



## Largeur

Les deux programmes contiennent :

```
cfg.width = 1280;
```

**Correspondance : identique.**

La largeur de la fenêtre est fixée à 1280 pixels.


## Hauteur

Les deux programmes contiennent :

```
cfg.height = 720;
```

**Correspondance : identique.**

La hauteur de la fenêtre est fixée à 720 pixels.


## Création de la fenêtre

Les deux programmes utilisent :

```cpp
NkWindow window(cfg);
```

**Correspondance : identique.**

---

## Vérification de la fenêtre

Les deux programmes contiennent :

```cpp
if (!window.IsOpen()) {
```

**Correspondance : identique.**

---

## Message d'erreur

Les deux programmes contiennent :

```
logger.Error("[app] creation fenetre echouee");
```

**Correspondance : identique.**


## Retour en cas d'erreur

Les deux programmes contiennent :

```cpp
return -1;
```

**Correspondance : identique.**


## Boucle principale

Mon programme :

```
while (window.IsOpen()) { /* les evenements arrivent ici */ }
```

Chapitre :

```
while (window.IsOpen()) {
    // les evenements arrivent ici (chapitre 4)
}
```

Les deux programmes utilisent la même condition :

```
window.IsOpen()
```

La différence est uniquement dans la présentation du bloc.

Mon programme place le commentaire sur la même ligne que la boucle, tandis que le chapitre place le commentaire à l'intérieur du bloc sur une ligne séparée.

**Correspondance : même fonctionnement, présentation différente.**



## Retour final

Les deux programmes contiennent :

```
return 0;
```

**Correspondance : identique.**

Cette instruction indique que le programme se termine normalement.



# 7. Bilan de la comparaison

La comparaison ligne par ligne montre que mon programme reprend la structure principale du programme présenté dans le chapitre.

Les éléments communs sont notamment :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
using namespace nkentseu;
int nkmain(...)
NkWindowConfig cfg
cfg.title
cfg.width
cfg.height
NkWindow window(cfg)
if (!window.IsOpen())
logger.Error(...)
return -1
while (window.IsOpen())
return 0
```

Cependant, plusieurs différences existent.

### Lignes supplémentaires dans mon programme

Mon programme contient les inclusions supplémentaires suivantes :

```
#include "NKLogger/NkSink.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
```

### Bloc présent dans le chapitre mais absent de mon programme

Le chapitre contient :

```
NKENTSEU_DEFINE_APP_DATA([]() {
    NkAppData d{};
    d.appName = "MaFenetre";
    d.appVersion = "1.0.0";
    return d;
}());
```

Ce bloc n'est pas présent dans mon programme.

### Différence dans la boucle

Mon programme écrit la boucle sur une seule ligne :

```
while (window.IsOpen()) { /* les evenements arrivent ici */ }
```

alors que le chapitre l'écrit sur plusieurs lignes.

### Conclusion

Mon programme permet bien de réaliser la partie **fenêtre nue** de l'exercice et reprend la majorité de la structure du programme du chapitre.

La comparaison détaillée montre toutefois que les deux programmes ne sont pas identiques. Les différences concernent principalement les inclusions supplémentaires de mon programme, l'absence du bloc `NKENTSEU_DEFINE_APP_DATA` et la présentation différente de la boucle principale.

Cette comparaison permet de retrouver les éléments du programme du chapitre directement dans mon code et d'identifier les lignes qui ont été ajoutées, supprimées ou modifiées.
