# Graphe des commits d'un dépôt réel

Pour réaliser cet exercice, j'ai utilisé mon dépôt réel `ani-2053`.

## Chemin d'accès au dépôt



J'ai ensuite vérifié que le dossier était bien un dépôt Git avec la commande :

```
git status
```

J'ai obtenu le résultat suivant :

```
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        chapitre-02/demo1-le_graphe_au_tableau/
        chapitre-02/exo12-la_regle_du_depot/

nothing added to commit but untracked files present (use "git add" to track)
```

Ce résultat confirme que je suis bien dans le dépôt Git `ani-2053` et que je travaille actuellement sur la branche `main`.

Les deux dossiers affichés comme `Untracked files` correspondent aux exercices que j'ai créés. Ils n'ont pas été ajoutés à Git à ce moment-là.

## Commande utilisée pour afficher le graphe

Une fois dans le dépôt, j'ai utilisé la commande :

```
git log --oneline --graph --all
```

Cette commande permet d'afficher l'historique des commits sous forme de graphe. L'option `--oneline` permet d'afficher chaque commit sur une seule ligne, `--graph` permet de représenter graphiquement les différentes branches et les fusions, et `--all` permet d'afficher les différentes références disponibles dans le dépôt.

## Résultat obtenu

La commande a donné le résultat suivant dans mon dépôt :

```
* 7b54462 (HEAD -> main, origin/main, origin/HEAD) exo11
* 0c8acfb exo11
* 6376378 exo11
* b55ddb3 exo1
* 2cda76b exo10
* fc43caa exo2
* 8b89ab5 exo6
* f79c996 exo9
* 8624631 exo8
* af708d7 exo3
* a442fd7 exo4
* dae2e54 exo7
* b61bf94 exo 6
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
* b778ee1 exo5
* 170e687 exo4
* eba6675 exo3
* 9d291a8 exo4
* 29eee28 exo5
* ba51e55 exo3
* 472b0c5 exo2
* febe87b exo1
| * a9f66ac (origin/branche-mesure-2) Revert "Commit a annuler"
| * d3865f6 Commit a annuler
| * b652c9e Troisième commit de mesure
| * d0348ed Deuxième commit de mesure
| * 840dd48 Premier commit de mesure
| * 3f4d956 message
| * d491c05 Ajout d'une présentation de Git
| * a2f8d9c Ajout du fichier de réponse
| * a3de3bd Ajout de l'exercice 2
| * 34ce519 Modification du README
| * db88553 Ajout de l'exercice1
|/
* 2476454 Initial commit
```

## Partie du graphe utilisée pour l'exercice

Pour représenter clairement les branches, le point de divergence et la fusion, j'ai utilisé cette partie de l'historique :

```
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
* b778ee1 exo5
```

Cette partie est particulièrement adaptée à l'exercice car elle montre directement une divergence entre deux historiques, puis leur réunion.

## Graphe dessiné au tableau

À partir du résultat obtenu avec Git, le graphe peut être représenté au tableau de la manière suivante :

```
                         3b8b0a2
                    Modification depuis clone1
                         /       \
                        /         \
b778ee1 ---------------/           \--------------- f1a104f
exo5                                              Résolution du conflit
                        \         /
                         \       /
                          cd2f54b
                    Modification depuis clone2
```

Une représentation plus proche de celle affichée directement par Git est :

```
                         3b8b0a2
                        /        \
                       /          \
b778ee1 --------------              f1a104f
                       \          /
                        \        /
                         cd2f54b
```

## Correspondance ligne par ligne

La première ligne du graphe Git :

```
*   f1a104f Résolution du conflit dans README
```

correspond au commit de fusion `f1a104f`, qui réunit les deux historiques.

La deuxième ligne :

```
|\
```

correspond au point où Git montre graphiquement les deux lignes de développement qui sont liées au commit de fusion.

La troisième ligne :

```
| * 3b8b0a2 Modification depuis clone1
```

correspond à la branche contenant la modification réalisée depuis `clone1`.

La quatrième ligne :

```
* | cd2f54b Modification depuis clone2
```

correspond à l'autre ligne de développement, contenant la modification réalisée depuis `clone2`.

La cinquième ligne :

```
|/
```

correspond à la réunion des deux lignes de développement.

La sixième ligne :

```
* b778ee1 exo5
```

correspond au commit commun à partir duquel les deux historiques se sont séparés.

## Correspondance avec le dessin du tableau

Dans le dessin, le commit :

```
b778ee1
```

correspond à :

```
* b778ee1 exo5
```

dans le résultat de `git log`.

Dans le dessin, la première branche contenant :

```
3b8b0a2
Modification depuis clone1
```

correspond à :

```
| * 3b8b0a2 Modification depuis clone1
```

dans le résultat de Git.

Dans le dessin, la deuxième branche contenant :

```
cd2f54b
Modification depuis clone2
```

correspond à :

```
* | cd2f54b Modification depuis clone2
```

dans le résultat de Git.

Dans le dessin, la réunion des deux branches correspond aux caractères :

```
|/
```

dans le résultat de Git.

Enfin, le point où les deux branches sont réunies dans le dessin correspond au commit :

```
f1a104f
Résolution du conflit dans README
```

qui apparaît dans Git sous la forme :

```
*   f1a104f Résolution du conflit dans README
```

## Explication du point de divergence

Le commit `b778ee1` est le point commun visible avant la séparation des deux historiques.

À partir de ce commit, deux modifications différentes apparaissent.

La première modification est :

```
3b8b0a2 Modification depuis clone1
```

Elle correspond à la modification effectuée depuis le premier clone.

La deuxième modification est :

```
cd2f54b Modification depuis clone2
```

Elle correspond à la modification effectuée depuis le deuxième clone.

Les deux historiques ont donc évolué séparément à partir d'un même état du dépôt.

## Fusion des deux historiques

Après ces deux modifications, les historiques sont réunis dans :

```
f1a104f Résolution du conflit dans README
```

Le résultat de Git montre cette réunion avec :

```
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
```

Le commit `f1a104f` correspond donc à la fusion des deux évolutions.

Cette fusion est également liée à la résolution du conflit qui avait été rencontré dans le fichier `README`.

## Graphe complet du dépôt

Le graphe complet obtenu avec la commande :

```
git log --oneline --graph --all
```

montre également une autre branche distante appelée :

```
origin/branche-mesure-2
```

Cette branche apparaît dans la partie suivante :

```
| * a9f66ac (origin/branche-mesure-2) Revert "Commit a annuler"
| * d3865f6 Commit a annuler
| * b652c9e Troisième commit de mesure
| * d0348ed Deuxième commit de mesure
| * 840dd48 Premier commit de mesure
| * 3f4d956 message
| * d491c05 Ajout d'une présentation de Git
| * a2f8d9c Ajout du fichier de réponse
| * a3de3bd Ajout de l'exercice 2
| * 34ce519 Modification du README
| * db88553 Ajout de l'exercice1
|/
* 2476454 Initial commit
```

Cette partie montre qu'il existe également une autre ligne de développement qui part de l'`Initial commit`.

Cependant, pour l'exercice demandé, la partie utilisée pour illustrer clairement une divergence suivie d'une fusion est celle contenant :

```
b778ee1
    |
    +---- 3b8b0a2
    |
    +---- cd2f54b
             |
          f1a104f
```

## Conclusion

J'ai utilisé un dépôt réel, `ani-2053`, situé dans :

```
C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia\ani-2053
```

Après avoir vérifié avec :

```
git status
```

que le dossier était bien un dépôt Git, j'ai affiché son historique avec :

```
git log --oneline --graph --all
```

Le résultat obtenu montre plusieurs commits et plusieurs lignes de développement.

La partie :

```
*   f1a104f Résolution du conflit dans README
|\
| * 3b8b0a2 Modification depuis clone1
* | cd2f54b Modification depuis clone2
|/
* b778ee1 exo5
```

permet de répondre directement à l'exercice.

`b778ee1` représente le point commun avant la divergence, `3b8b0a2` et `cd2f54b` représentent les deux évolutions séparées, puis `f1a104f` représente leur réunion lors de la résolution du conflit.

Le graphe dessiné au tableau correspond donc directement au graphe produit par Git avec `git log --oneline --graph --all`.
