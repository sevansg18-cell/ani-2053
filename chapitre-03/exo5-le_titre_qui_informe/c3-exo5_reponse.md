# Exercice — Sept zones et changement de curseur

## 1. Vérification de l'API

Avant de modifier le programme, j'ai d'abord vérifié dans les fichiers du projet les éléments nécessaires pour gérer le curseur et les mouvements de la souris.

La recherche a été effectuée depuis le projet :

```
PS C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow>
```

Commande utilisée :

```
Get-ChildItem -Recurse -File | Select-String -Pattern "Cursor|Mouse|NkMouse" | Select-Object Path, LineNumber, Line
```

Cette vérification m'a permis d'identifier notamment :

* `NkCursorType` dans `NkWindow.h`
* les différents types de curseurs :

  * `Arrow`
  * `TextInput`
  * `Hand`
  * `ResizeNS`
  * `ResizeWE`
  * `ResizeNWSE`
  * `ResizeNESW`
* la méthode `SetCursor()`
* l'événement `NkMouseMoveEvent`
* les méthodes `GetX()` et `GetY()` permettant de récupérer la position de la souris.

Les fichiers vérifiés se trouvent notamment dans :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\include\NKWindow\Core\NkWindow.h
```

et :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\include\NKEvent\NkMouseEvent.h
```

## 2. Découpage de la fenêtre en sept zones

La fenêtre utilisée est de taille initiale :

```
1280 x 720
```

J'ai ensuite divisé la fenêtre en sept zones à partir des coordonnées `X` et `Y` de la souris.

La répartition utilisée est :

```
Zone 1 : y < 120
Zone 2 : y >= 120 et y < 320, x < 426
Zone 3 : y >= 120 et y < 320, 426 <= x < 853
Zone 4 : y >= 120 et y < 320, x >= 853
Zone 5 : y >= 320, x < 426
Zone 6 : y >= 320, 426 <= x < 853
Zone 7 : y >= 320, x >= 853
```

Chaque zone possède un curseur différent :

```
Zone 1 → Arrow
Zone 2 → TextInput
Zone 3 → Hand
Zone 4 → ResizeNS
Zone 5 → ResizeWE
Zone 6 → ResizeNWSE
Zone 7 → ResizeNESW
```

## 3. Résultat du test

J'ai déplacé la souris dans les différentes parties de la fenêtre afin de vérifier les sept zones.

Les sept formes de curseur sont bien obtenues et changent lorsque la souris passe d'une zone à une autre.

La première partie de l'exercice est donc fonctionnelle.

## 4. Curseur défini une seule fois au démarrage

J'ai ensuite effectué le deuxième test en appelant `SetCursor()` une seule fois au démarrage de la fenêtre, sans modifier le curseur lors des déplacements de la souris.

Dans ce cas, le programme ne recalcule plus la zone survolée et ne demande plus de changement de curseur pendant le déplacement de la souris.

Ce test montre que le changement automatique entre les sept curseurs dépend du traitement de `NkMouseMoveEvent` et de l'appel correspondant à `SetCursor()`.

## 5. Conclusion

J'ai d'abord vérifié l'API disponible dans les fichiers du projet avant de réaliser l'exercice.

Les sept types de curseurs disponibles ont été identifiés dans `NkWindow.h`, puis les coordonnées de la souris ont été récupérées avec `NkMouseMoveEvent`, `GetX()` et `GetY()`.

Le découpage de la fenêtre en sept zones permet ensuite d'associer un curseur différent à chaque zone.

Les sept curseurs ont été testés avec succès.
