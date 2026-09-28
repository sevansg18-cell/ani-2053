# Ouverture des 7 fenêtres

Pour cet exercice, j'ai commencé par identifier les droits disponibles dans `NkWindowConfig`.

Les sept droits testés sont :

1. **`resizable`** : droit de redimensionner la fenêtre.
2. **`movable`** : droit de déplacer la fenêtre.
3. **`closable`** : droit de fermer la fenêtre.
4. **`minimizable`** : droit de minimiser la fenêtre.
5. **`maximizable`** : droit de maximiser la fenêtre.
6. **`canFullscreen`** : droit de passer la fenêtre en plein écran.
7. **`frame`** : présence du cadre de la fenêtre.

Dans mon code, ces droits correspondent à :

```
cfg.resizable
cfg.movable
cfg.closable
cfg.minimizable
cfg.maximizable
cfg.canFullscreen
cfg.frame
```

Au départ, les sept droits sont activés :

```
cfg.resizable = true;
cfg.movable = true;
cfg.closable = true;
cfg.minimizable = true;
cfg.maximizable = true;
cfg.canFullscreen = true;
cfg.frame = true;
```

J'ai ensuite désactivé **un seul droit à la fois** afin d'observer précisément son effet.

# Désactivation des droits

## 1. `resizable`

Pour ce test, j'ai désactivé uniquement le droit de redimensionnement :

```
cfg.resizable = false;
```

Les autres droits sont restés activés.

La fenêtre s'est ouverte avec une taille de **1280 × 720**.

J'ai constaté que :

* la fenêtre pouvait toujours être déplacée ;
* elle pouvait toujours être minimisée ;
* elle pouvait toujours être maximisée ;
* mais je ne pouvais plus modifier sa largeur ou sa hauteur en utilisant les bords ou les coins de la fenêtre.

### Conclusion

Dans ce test, `resizable = false` empêche bien le redimensionnement de la fenêtre.


## 2. `movable`

Pour ce test, j'ai désactivé uniquement :

```
cfg.movable = false;
```

Les autres droits sont restés à `true`.

J'ai ensuite essayé de déplacer la fenêtre en faisant glisser sa barre de titre.

### Observation

Malgré :

```
cfg.movable = false;
```

j'ai toujours réussi à déplacer la fenêtre.

### Conclusion

Le droit `movable` est bien présent dans `NkWindowConfig`, mais sa désactivation n'empêche pas le déplacement dans l'implémentation Windows utilisée pour cet exercice.

Il s'agit donc d'une différence entre le comportement attendu par l'énoncé et le comportement réellement observé dans le moteur.


## 3. `closable`

J'ai ensuite désactivé uniquement le droit de fermeture :

```
cfg.closable = false;
```

La fenêtre s'est ouverte normalement et les autres fonctionnalités sont restées disponibles.

### Observation

Le bouton rouge de fermeture était toujours présent et actif.

J'ai donc pu fermer la fenêtre malgré :

```
cfg.closable = false;
```

### Conclusion

La propriété `closable` n'empêche pas la fermeture de la fenêtre dans l'implémentation Windows utilisée.


## 4. `minimizable`

Pour ce test, j'ai remis :

```
cfg.closable = true;
```

puis désactivé uniquement :

```
cfg.minimizable = false;
```

### Observation

Malgré la désactivation de `minimizable`, j'ai toujours réussi à minimiser la fenêtre.

### Conclusion

La propriété `minimizable` n'est pas effectivement appliquée par l'implémentation Windows utilisée.


## 5. `maximizable`

Pour ce test, j'ai désactivé uniquement :

```
cfg.maximizable = false;
```

### Observation

Le bouton permettant de maximiser la fenêtre n'était pas fonctionnel lors de l'ouverture normale.

Cependant, après avoir minimisé la fenêtre puis cliqué sur celle-ci depuis la barre des tâches, la fenêtre pouvait de nouveau s'agrandir.

### Conclusion

Le comportement observé ne correspond donc pas à une désactivation complète et uniforme de la maximisation. Cela montre que le comportement dépend également de la gestion native de la fenêtre par Windows.


## 6. `canFullscreen`

J'ai désactivé :

```
cfg.canFullscreen = false;
```

### Observation

Je n'ai pas réussi à faire passer la fenêtre en plein écran.

### Conclusion

Dans mon test, la désactivation de `canFullscreen` empêche le passage en plein écran.


## 7. `frame`

Pour le dernier test, j'ai désactivé le cadre de la fenêtre :

```
cfg.frame = false;
```

### Observation

La fenêtre est créée sans son cadre natif habituel.

Les éléments normalement fournis par le cadre de la fenêtre, comme la barre de titre et les boutons natifs, ne sont donc plus présentés de la même manière.

### Conclusion

Contrairement à plusieurs autres propriétés testées, le réglage du cadre est effectivement pris en compte par l'implémentation Windows.

# Remarque sur `modal`

J'avais initialement considéré `modal` comme le septième droit :

```
cfg.modal = true;
```

Cependant, après vérification, `modal` ne correspond pas au septième droit demandé dans cet exercice.

`modal` décrit le comportement modal de la fenêtre et ne doit donc pas être utilisé pour remplacer `frame` dans les sept tests.

Lors de mon test, j'ai également constaté que la modification de `modal` ne produisait pas le blocage des interactions que j'attendais.

Je ne retiens donc pas `modal` comme l'un des sept droits de cet exercice.

# conclusion generale

Cette expérience montre que les sept propriétés existent dans la configuration de `NkWindow`, mais qu'elles ne sont pas toutes appliquées de la même manière par l'implémentation Windows actuelle.

