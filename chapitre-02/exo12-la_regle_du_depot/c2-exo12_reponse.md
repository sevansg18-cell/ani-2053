# Charte Git du projet

**Groupe : 4 étudiants — Application : dès demain**

# Branches

La branche `main` contient uniquement une version stable du projet. Aucun étudiant ne travaille directement dessus.

Chaque tâche importante doit être réalisée sur une branche dédiée. Le nom doit respecter l'un des formats suivants :

```
feature/nom-fonctionnalite
fix/nom-du-bug
docs/nom-documentation
test/nom-du-test
```

Exemples :
```
feature/menu-principal
fix/calcul-score
docs/rapport
Règles
```

Une tâche importante = une branche.
Les noms doivent être courts, en minuscules et utiliser des tirets.
Avant de commencer, récupérer la dernière version de main.
Une branche doit être relue avant sa fusion.
Chaque commit doit correspondre à une modification cohérente.

Le message doit obligatoirement commencer par l'un des préfixes suivants :
```
feat:
fix:
docs:
test:
```

Exemples :

````
feat: ajout du menu principal
fix: correction du calcul du score
docs: mise à jour du rapport
test: ajout des tests utilisateur
````

Cette règle permet une vérification objective : le relecteur peut accepter ou refuser le commit simplement en regardant son préfixe et son contenu.

Avant chaque commit :
````
git status
git diff
Interdits
````

Il est interdit de :

travailler directement sur main ;
pousser sur main sans relecture ;
utiliser git push --force sur main ;
supprimer le travail d'un autre étudiant sans accord ;
commiter des mots de passe, clés ou fichiers confidentiels ;
mélanger plusieurs tâches sans rapport dans un même commit ;
utiliser des messages comme modif, test, aaa ou final ;
fusionner du code non testé.
Relecture

Toute modification destinée à main doit être relue par un autre étudiant.

Le relecteur vérifie au minimum :

que le projet compile ;
que les tests nécessaires passent ;
que la modification correspond à la tâche ;
que le commit respecte la convention de nommage ;
qu'aucun fichier inutile ou confidentiel n'est ajouté.

L'auteur ne valide pas seul sa propre modification.

# Branche principale cassée

Si un commit casse main, on ne réécrit pas l'historique et on ne fait pas de push --force.

Le commit fautif peut être annulé avec :

``git revert <commit>``

Cette commande crée un nouveau commit d'annulation : l'historique reste donc conservé et main peut retrouver son état précédent.

Après l'annulation, le problème doit être corrigé sur une branche dédiée :

fix/correction-main

La correction est ensuite testée et relue avant d'être fusionnée.

Travail en groupe : règles et risques

Chaque étudiant est responsable de ses modifications et doit prévenir le groupe lorsqu'un problème peut affecter le travail commun.

Il faut :

1. communiquer avant une modification importante ;
2. récupérer régulièrement les changements de main ;
3. tester avant toute fusion ;
4. respecter le travail des autres ;
5. conserver un historique Git compréhensible.

Les principales conséquences du non-respect de ces règles sont la perte de travail, les conflits, les régressions et le blocage de main.

