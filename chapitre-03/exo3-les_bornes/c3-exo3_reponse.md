# Test de la taille minimale de la fenêtre

## Objectif

L’objectif de cet exercice est de vérifier le fonctionnement de la taille minimale d’une fenêtre.

L’énoncé demande de :

1. fixer une taille minimale ;
2. essayer de réduire la fenêtre en dessous de cette taille ;
3. constater que la fenêtre ne peut pas être réduite davantage ;
4. retirer la taille minimale ;
5. recommencer les manipulations ;
6. déterminer et noter la plus petite taille que le système accepte.

---

## 1. Fenêtre utilisée pour les tests

La fenêtre utilisée dans le programme est configurée comme une fenêtre redimensionnable :

```
NkWindowConfig cfg;
cfg.title  = "Ma fenetre";
cfg.width  = 100;
cfg.height = 50;
cfg.resizable = true;
cfg.movable = true;
cfg.closable = false;
cfg.minimizable = true;
cfg.maximizable = true;
cfg.canFullscreen = true;
cfg.modal = true;
```

La ligne :

```
cfg.resizable = true;
```

est importante car elle permet de modifier la largeur et la hauteur de la fenêtre avec la souris.

---

## 2. Première partie : fixer une taille minimale

Pour réaliser la première partie de l’exercice, une taille minimale est fixée à :

```cpp
cfg.minSize = {800, 600};
```

La taille minimale imposée est donc de :

**800 × 600 pixels**

Le programme est ensuite lancé.

J’essaie de réduire la fenêtre progressivement en dessous de **800 × 600**.

### Observation

Lorsque la fenêtre atteint **800 × 600**, il n’est plus possible de la réduire davantage.

Même si j’essaie de déplacer la bordure de la fenêtre vers l’intérieur, elle conserve une taille minimale de **800 × 600**.

Cela permet de vérifier que la propriété `minSize` impose bien une limite minimale au redimensionnement de la fenêtre.

---

## 3. Retrait de la taille minimale

Après ce premier test, la contrainte :

```
cfg.minSize = {800, 600};
```

est retirée du programme.

Le programme est recompilé puis relancé.

L’objectif est maintenant de vérifier quelle est la plus petite taille que le système accepte lorsqu’aucune taille minimale n’est explicitement définie dans la configuration.

---

## 4. Réduction progressive de la fenêtre

J’ai effectué six tests en réduisant progressivement la taille de la fenêtre.

### Test 1 : 800 × 600

La fenêtre est réduite à :

**800 × 600 pixels**

Cette taille est acceptée.

---

### Test 2 : 600 × 400

La fenêtre est ensuite réduite à :

**600 × 400 pixels**

Cette taille est également acceptée.

---

### Test 3 : 400 × 200

La fenêtre est ensuite réduite à :

**400 × 200 pixels**

Cette taille est encore acceptée.

---

### Test 4 : 200 × 100

La fenêtre est ensuite réduite à :

**200 × 100 pixels**

Cette taille est également acceptée.

---

### Test 5 : 100 × 50

La fenêtre est ensuite réduite à :

**100 × 50 pixels**

Cette taille est acceptée.

La fenêtre atteint donc cette dimension minimale lors de mes essais.

---

### Test 6 : 50 × 20

Enfin, j’essaie de réduire la fenêtre à :

**50 × 20 pixels**

Cependant, la fenêtre ne devient pas plus petite.

Elle reste à :

**100 × 50 pixels**

La tentative de passer à **50 × 20** n'est donc pas prise en compte.

---

## 5. Résumé des six tests

Les tests réalisés sont les suivants :

```text
800 × 600  → accepté
600 × 400  → accepté
400 × 200  → accepté
200 × 100  → accepté
100 × 50   → accepté
50 × 20    → la fenêtre reste à 100 × 50
```

Le dernier test est important : même en essayant de réduire la fenêtre à **50 × 20**, sa taille reste de **100 × 50**.

---

## 6. Plus petite taille observée

La plus petite taille effectivement obtenue pendant les tests est :

```text
100 × 50 pixels
```

La tentative suivante, **50 × 20**, ne réduit pas davantage la fenêtre.

On peut donc noter :

**Plus petite taille acceptée : 100 × 50 pixels.**

---

## 7. Conclusion

La première partie de l’exercice montre qu’une taille minimale explicitement définie avec :

```
cfg.minSize = {800, 600};
```

empêche la fenêtre de devenir plus petite que **800 × 600 pixels**.

Après avoir retiré cette contrainte, j’ai réalisé six tests de réduction :

```
800 × 600
600 × 400
400 × 200
200 × 100
100 × 50
50 × 20
```

Les cinq premières tailles sont atteintes, tandis que la dernière tentative, **50 × 20**, laisse la fenêtre à **100 × 50**.

La plus petite taille obtenue avec cette configuration et ce système est donc :

**100 × 50 pixels.**

Cela montre qu'en l'absence de `minSize` explicite, le système de fenêtrage conserve tout de même une limite minimale de redimensionnement dans ce test.
