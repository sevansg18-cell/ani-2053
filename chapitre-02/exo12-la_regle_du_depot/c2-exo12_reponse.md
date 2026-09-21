# Organisation des branches

La branche `main` contient la version stable et commune du projet. Aucun étudiant ne doit travailler directement dessus.

Chaque étudiant travaille sur une branche correspondant à une tâche précise.

Les noms des branches doivent respecter une convention :

```
feature/nom-fonctionnalite
fix/nom-du-bug
docs/nom-documentation
test/nom-du-test
```

Exemples :

```
feature/menu-principal
fix/correction-affichage
docs/rapport-git
test/test-connexion
```

Avant de commencer une tâche, l'étudiant doit récupérer les dernières modifications de `main` et créer sa branche à partir d'une version récente.

```
git switch main
git pull
git switch -c feature/menu-principal
```

## Ce qu'il faut faire

* Utiliser une branche par fonctionnalité ou correction importante.
* Donner aux branches des noms courts et explicites.
* Garder sa branche régulièrement à jour.
* Supprimer sa branche personnelle lorsqu'elle n'est plus nécessaire, après accord du groupe.

## Ce qu'il ne faut jamais faire

* Travailler directement sur `main`.
* Utiliser des noms de branches vagues comme `test`, `branche1` ou `truc`.
* Modifier ou supprimer la branche d'un autre étudiant sans accord.
* Garder une branche très longtemps sans la synchroniser avec le projet.

**Risque :** une mauvaise organisation des branches augmente les conflits et peut rendre difficile l'identification de l'origine d'une erreur.



# Contenu d'un commit

Un commit doit représenter une modification cohérente et identifiable.

Avant de faire un commit, l'étudiant doit vérifier les fichiers modifiés :

```
git status
git diff
```

Les messages de commit doivent être clairs.

Exemples :

```
Ajout du menu principal
Correction du calcul des scores
Ajout des tests utilisateur
Mise à jour de la documentation
```

Les messages suivants sont à éviter :

```
modif
test
aaa
changement
final
```

## Ce qu'il faut faire

* Faire des commits réguliers.
* Faire un commit pour une modification cohérente.
* Utiliser des messages précis.
* Vérifier les fichiers avant de valider.
* Ne mettre dans le commit que les fichiers nécessaires.

## Ce qu'il ne faut jamais faire

* Faire un commit sans vérifier son contenu.
* Mélanger plusieurs travaux sans rapport dans un même commit.
* Commiter des mots de passe, clés privées ou informations confidentielles.
* Ajouter volontairement des fichiers temporaires ou inutiles.
* Utiliser des messages de commit incompréhensibles.

Après le commit, on peut vérifier l'historique avec :

```
git log --oneline -n 5
```

**Risque :** de mauvais commits rendent l'historique difficile à comprendre et compliquent la recherche ou l'annulation d'une erreur.


# Relecture du travail

Une modification importante doit être relue par un autre étudiant avant d'être intégrée à `main`.

Le groupe de quatre étudiants fonctionne avec une rotation afin que chacun puisse relire le travail des autres.

Le relecteur vérifie notamment :

* que la fonctionnalité correspond à la demande ;
* que le code est compréhensible ;
* que le projet compile ;
* que les tests nécessaires fonctionnent ;
* qu'aucun fichier inutile n'a été ajouté ;
* que la modification ne casse pas une fonctionnalité existante.

## Ce qu'il faut faire

* Faire relire les modifications importantes.
* Tester avant la fusion.
* Signaler clairement les erreurs.
* Corriger les problèmes détectés avant la fusion.

## Ce qu'il ne faut pas faire

* Valider automatiquement le travail d'un camarade.
* Fusionner une branche sans vérifier les modifications.
* Considérer la relecture comme une simple formalité.
* Modifier silencieusement le travail d'un autre étudiant.

**Risque :** une mauvaise relecture peut introduire des bugs ou des régressions dans `main`.


# Ce qui est interdit

Certaines pratiques sont interdites car elles peuvent mettre en danger le travail du groupe.

## Interdictions concernant Git

Il est interdit de :

* travailler directement sur `main` ;
* pousser directement sur `main` sans relecture ;
* utiliser `git push --force` sur `main` ;
* supprimer l'historique partagé ;
* supprimer le travail d'un camarade sans son accord ;
* utiliser un `reset --hard` sur le travail d'un autre sans vérification ;
* résoudre un conflit en supprimant automatiquement la partie d'un autre étudiant ;
* fusionner du code non testé ;
* commiter des informations confidentielles.

## Interdictions concernant le travail de groupe

Il est également interdit de :

* s'approprier le travail d'un autre étudiant ;
* cacher volontairement une erreur ;
* modifier le travail d'un camarade sans l'en informer ;
* empêcher un membre d'accéder au projet ;
* faire passer le travail d'un étudiant pour son propre travail ;
* conserver volontairement une information importante pour soi.

## Règle importante

Une commande dont les conséquences ne sont pas comprises ne doit pas être exécutée sur le dépôt commun. Il faut d'abord demander l'avis d'un autre membre du groupe.



# Procédure en cas de problème sur `main`

Si une modification casse `main`, il ne faut pas immédiatement supprimer des commits ou réécrire l'historique.

## Étape 1 : arrêter les modifications

Les étudiants évitent de pousser de nouvelles modifications sur `main` tant que le problème n'est pas compris.

## Étape 2 : identifier le problème

On vérifie l'état du dépôt et l'historique :

```
git status
git log --oneline
```

On recherche ensuite la modification à l'origine du problème.

## Étape 3 : prévenir le groupe

La personne qui découvre le problème doit informer les autres étudiants et expliquer ce qui s'est passé.

## Étape 4 : créer une branche de correction

La correction se fait sur une branche dédiée :

```
fix/correction-main
```

On évite de corriger directement `main`.

## Étape 5 : tester et relire

La correction doit être testée puis relue par un autre étudiant avant d'être fusionnée.

## Ce qu'il ne faut jamais faire

* Supprimer immédiatement le commit suspect.
* Utiliser `git push --force` pour cacher l'erreur.
* Effacer l'historique.
* Supprimer le travail d'un camarade pour résoudre rapidement un conflit.
* Continuer à travailler normalement sur `main` sans prévenir le groupe.

**Règle :** une erreur doit être corrigée de manière traçable. Le but est de réparer le projet, pas de faire disparaître la trace de l'erreur.



# Règle générale du travail en groupe

Git est un outil de collaboration. Les quatre étudiants doivent donc respecter les mêmes règles.

## Avant de travailler

Chaque étudiant doit :

1. connaître la tâche qui lui est attribuée ;
2. récupérer la dernière version du projet ;
3. vérifier l'état du dépôt ;
4. travailler sur sa propre branche.

## Pendant le travail

L'étudiant doit :

* rester sur sa branche ;
* faire des commits réguliers ;
* utiliser des messages clairs ;
* éviter les modifications inutiles ;
* prévenir le groupe lorsqu'un problème apparaît ;
* communiquer lorsqu'une modification risque d'affecter un autre étudiant.

## Avant une fusion

L'étudiant doit vérifier : `git status`, `git diff`

Il doit ensuite tester son travail et expliquer au relecteur ce qui a été modifié.

## Après une fusion

Les autres membres doivent récupérer la nouvelle version avant de commencer un nouveau travail important.

L'objectif est que les quatre étudiants travaillent sur une version aussi proche que possible du projet commun.



# Contraintes et risques

Les principaux risques sont :

* perte de travail ;
* conflits Git ;
* régressions ;
* mauvaise résolution des conflits ;
* historique incompréhensible ;
* fichiers inutiles dans le dépôt ;
* blocage de la branche principale ;
* difficulté à identifier l'origine d'un problème.



# Règles essentielles à retenir

Les règles principales du groupe sont :

1. **Ne jamais travailler directement sur `main`.**
2. **Toujours utiliser une branche pour son travail.**
3. **Faire des commits clairs et cohérents.**
4. **Vérifier les fichiers avant chaque commit.**
5. **Faire relire les modifications importantes.**
6. **Tester avant de fusionner.**
7. **Ne jamais utiliser `git push --force` sur `main`.**
8. **Ne jamais supprimer le travail d'un camarade sans accord.**
9. **Signaler rapidement toute erreur.**
10. **Corriger les problèmes de manière traçable.**
11. **Respecter le travail des autres membres.**
12. **Maintenir `main` dans un état stable.**

## Conclusion

Le principe du groupe est que chaque étudiant est responsable de son travail, mais que les quatre étudiants sont collectivement responsables de l'état du projet.

Une bonne organisation Git repose donc sur trois éléments :

**branches séparées + commits propres + relecture avant fusion.**

En cas de problème, le groupe doit privilégier la communication, la sauvegarde du travail existant et une correction traçable plutôt qu'une modification précipitée ou destructive.
