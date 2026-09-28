# Test de la taille minimale de la fenêtre

## Objectif

L’objectif de cet exercice est de vérifier le fonctionnement de la taille minimale d’une fenêtre.

L’énoncé demande de :

1. fixer une taille minimale ;
2. essayer de réduire la fenêtre en dessous de cette taille ;
3. constater que la fenêtre ne peut pas être réduite davantage ;
4. retirer la taille minimale ;
5. recommencer les manipulations ;
6. déterminer et noter la plus petite taille réellement acceptée.


## 1. Vérification de la configuration

Avant de modifier le programme, j’ai vérifié la définition de `NkWindowConfig` dans le fichier :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\include\NKWindow\Core\NkWindow.h
```

Cette vérification était nécessaire pour connaître les noms exacts des propriétés permettant de définir les dimensions minimales de la fenêtre.

J’ai constaté que `minSize` n’est pas un champ de `NkWindowConfig`.

Les deux dimensions minimales sont définies séparément dans la configuration. J’ai donc utilisé les deux champs réellement présents dans l’en-tête au lieu de créer une propriété qui n’existe pas.


## 2. Configuration de la fenêtre

La fenêtre utilisée pour les tests est configurée comme une fenêtre redimensionnable :

```
NkWindowConfig cfg;

cfg.title = "Ma fenetre";
cfg.width = 1280;
cfg.height = 720;

cfg.resizable = true;
cfg.movable = true;
cfg.closable = false;
cfg.minimizable = true;
cfg.maximizable = true;
cfg.canFullscreen = true;
cfg.modal = true;
```

La propriété :

```
cfg.resizable = true;
```

est importante car elle permet de modifier la largeur et la hauteur de la fenêtre avec la souris.


## 3. Première partie : fixer une taille minimale

Pour la première partie de l’exercice, j’ai fixé explicitement les deux dimensions minimales à :

```
largeur minimale : 800 pixels
hauteur minimale  : 600 pixels
```

Les deux propriétés utilisées correspondent aux champs réellement présents dans `NkWindowConfig`.

Le programme a ensuite été compilé et exécuté afin de vérifier que la configuration était valide.

J’ai essayé de réduire progressivement la fenêtre en dessous de `800 × 600`.

### Observation

Lorsque la fenêtre atteint les dimensions minimales configurées, il n’est plus possible de la réduire davantage.

La bordure de la fenêtre empêche donc de passer sous les deux valeurs définies dans la configuration.

Cette première manipulation permet de vérifier expérimentalement que les deux propriétés de taille minimale sont bien prises en compte par le moteur.


## 4. Mesure de la taille avec l’événement de redimensionnement

Pour éviter de déterminer les dimensions uniquement à l’œil, j’ai utilisé l’événement de redimensionnement de la fenêtre.

J’ai d’abord vérifié la définition de cet événement dans :

```
C:\Users\cloth\OneDrive\Documenten\workspace\FirstWindow\Mon workspace\include\NKEvent\NkWindowEvent.h
```

Le programme affiche ensuite les dimensions reçues lorsqu’un redimensionnement est effectué.

Cette méthode permet de mesurer la taille réellement communiquée au programme au lieu de simplement estimer la taille de la fenêtre visuellement.


## 5. Retrait de la taille minimale

Après le premier test, les deux propriétés de taille minimale ont été retirées du programme.

Le programme a été recompilé puis relancé.

L’objectif est maintenant de déterminer quelle taille minimale le moteur utilise lorsqu’aucune limite minimale n’est définie explicitement dans notre configuration.

Il est important de distinguer cette valeur de la taille minimale définie précédemment : dans cette deuxième partie, ce sont les valeurs par défaut du moteur qui sont observées.


## 6. Réduction progressive de la fenêtre

J’ai effectué plusieurs tests en réduisant progressivement la taille de la fenêtre.

Pour chaque tentative, la taille réellement obtenue est relevée grâce à l’événement de redimensionnement.

### Test 1 : 800 × 600

Taille demandée :

```
800 × 600
```

Taille réellement obtenue :

```
798 x 592
```

---

### Test 2 : 600 × 400

Taille demandée :

```
600 × 400
```

Taille réellement obtenue :

```
598 x 392
```


### Test 3 : 400 × 200

Taille demandée :

```
400 × 200
```

Taille réellement obtenue :

```
398 x 192
```

---

### Test 4 : 200 × 100

Taille demandée :

```
200 × 100
```

Taille réellement obtenue :

```
198 x 92
```

### Test 5 : 100 × 50

Taille demandée :

```
100 × 50
```

Taille réellement obtenue :

```
148 x 43
```



### Test 6 : 50 × 20

Taille demandée :

```
50 × 20
```

Taille réellement obtenue :

```
148 x 43
```

Ce dernier test permet de déterminer si le moteur accepte réellement une fenêtre aussi petite ou s’il applique sa propre limite minimale.



## 7. Comparaison des résultats

Les résultats doivent être comparés entre les deux configurations :

### Avec les deux bornes minimales

Les dimensions minimales sont celles que j’ai explicitement définies dans `NkWindowConfig`.

Lorsque j’essaie de réduire la fenêtre sous ces valeurs, le moteur empêche le redimensionnement d’aller plus loin.

### Sans les deux bornes minimales

Les limites définies par mon programme sont supprimées.

Les dimensions obtenues lors des tentatives de redimensionnement permettent alors d'observer les valeurs minimales utilisées par défaut par le moteur.

Cette comparaison permet de distinguer clairement :

* la limite que j’ai imposée dans mon programme ;
* la limite minimale appliquée par défaut par le moteur.


## 8. Plus petite taille observée

Après avoir retiré les deux limites minimales et effectué les différents tests, la plus petite taille réellement obtenue est :

```
148 x 43
```

Cette valeur doit être déterminée à partir de l’événement de redimensionnement et non simplement à partir d’une observation visuelle.

La tentative de réduire davantage la fenêtre permet ensuite de vérifier que cette valeur correspond bien à la limite minimale appliquée par le moteur.


## 9. Conclusion

Cet exercice m’a permis de vérifier expérimentalement le fonctionnement de la taille minimale d’une fenêtre.

La première partie consiste à définir explicitement deux limites minimales dans `NkWindowConfig`. Lorsque la fenêtre atteint ces dimensions, elle ne peut plus être réduite davantage.

Dans la deuxième partie, j’ai retiré ces deux limites afin d’observer le comportement par défaut du moteur.

J’ai également utilisé l’événement de redimensionnement pour obtenir les dimensions réellement reçues par le programme. Cette méthode est plus précise qu’une simple estimation visuelle.

La taille minimale finale doit donc être déterminée à partir des valeurs affichées par le programme lors des tests. Elle ne doit pas être déduite uniquement du fait que la fenêtre semble rester à une certaine dimension.

Cette vérification permet de distinguer clairement les limites configurées par le programme des limites imposées par défaut par le moteur.
