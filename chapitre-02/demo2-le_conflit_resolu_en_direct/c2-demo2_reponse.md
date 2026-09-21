# Provoquer et résoudre un conflit Git
## 1. Création de deux modifications différentes

J'ai d'abord créé une branche appelée `conflit-demo` :

```
git switch -c conflit-demo
```

Résultat :

```
Switched to a new branch 'conflit-demo'
```

Sur cette branche, j'ai modifié une ligne de `README.md` en :

```
VERSION BRANCHE A
```

Puis j'ai enregistré la modification :

```
git add README.md
git commit -m "Modification conflit branche A"
```

Résultat :

```
[conflit-demo dda188b] Modification conflit branche A
1 file changed, 1 insertion(+), 1 deletion(-)
```

Je suis ensuite revenu sur la branche principale :

```
git switch main
```

Puis j'ai modifié **la même ligne** du même fichier, mais avec un autre contenu :

```
VERSION MAIN
```

J'ai enregistré cette deuxième modification :

```
git add README.md
git commit -m "Modification conflit branche main"
```

Résultat :

```
[main ebf8a42] Modification conflit branche main
1 file changed, 1 insertion(+), 1 deletion(-)
```

Les deux branches contenaient donc maintenant deux versions différentes de la même ligne.


## 2. Déclenchement du conflit

Depuis la branche `main`, j'ai essayé de fusionner la branche `conflit-demo` :

```
git merge conflit-demo
```

Git a détecté que les deux branches avaient modifié la même partie du fichier :

```
Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.
```

J'ai ensuite vérifié l'état du dépôt avec :

```
git status
```

Résultat :

```
On branch main
Your branch is ahead of 'origin/main' by 5 commits.

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   README.md

no changes added to commit (use "git commit" to commit)
```

Git indique donc que `README.md` a été modifié sur les deux branches et qu'il faut résoudre le conflit.


## 3. Lecture des marqueurs du conflit

J'ai affiché le contenu du fichier avec :

```
Get-Content README.md
```

J'ai obtenu :

```
# ani-2053 - Conflit resolu

<<<<<<< HEAD
VERSION MAIN
=======
VERSION BRANCHE A
>>>>>>> conflit-demo

Modification faite sur la branche conflit-test
```

Les marqueurs indiquent les deux versions du fichier :

* `<<<<<<< HEAD` indique le début de la version actuellement présente sur `main`.
* `VERSION MAIN` correspond à la modification faite sur `main`.
* `=======` sépare les deux versions.
* `VERSION BRANCHE A` correspond à la modification provenant de `conflit-demo`.
* `>>>>>>> conflit-demo` indique la fin de la version de la branche fusionnée.

Le conflit est donc clairement visible entre :

```
VERSION MAIN
```

et :

```
VERSION BRANCHE A
```


## 4. Décision et reconstruction du fichier

J'ai choisi de conserver les deux informations au lieu de supprimer l'une des deux versions.

J'ai donc supprimé les marqueurs Git :

```
<<<<<<< HEAD
=======
>>>>>>> conflit-demo
```

et reconstruit manuellement le contenu du fichier comme ceci :

```
# ani-2053 - Conflit resolu

VERSION MAIN + VERSION BRANCHE A

Modification faite sur la branche conflit-test
```

Le fichier `README.md` ne contient donc plus les marqueurs de conflit.

J'ai vérifié le résultat avec :

```
Get-Content README.md
```

Résultat :

```
# ani-2053 - Conflit resolu

VERSION MAIN + VERSION BRANCHE A

Modification faite sur la branche conflit-test
```


## 5. Validation de la résolution

Une fois le fichier corrigé, j'ai indiqué à Git que le conflit était résolu avec :

```
git add README.md
```

Puis j'ai validé la résolution du conflit :

```
git commit --amend --no-edit
```

Résultat final obtenu :

```
[main 79fbc6c] Resolution du conflit README
Date: Mon Sep 21 20:00:40 2026 +0200
```

Le commit de résolution est donc :

```
79fbc6c Resolution du conflit README
```


## 6. Vérification finale

J'ai ensuite vérifié l'état du dépôt avec :

```
git status
```

Résultat :

```
On branch main
Your branch is ahead of 'origin/main' by 7 commits.

Untracked files:
        chapitre-02/demo1-le_graphe_au_tableau/
        chapitre-02/demo2-le_conflit_resolu_en_direct/
        chapitre-02/exo12-la_regle_du_depot/

nothing added to commit but untracked files present
```

Les trois dossiers indiqués comme `untracked` correspondent à d'autres exercices. Ils ne concernent pas la résolution du conflit et je ne les ai donc pas ajoutés au commit.

Le conflit de `README.md` est bien résolu et le fichier est maintenant dans l'état voulu.

## 7. Graphe obtenu

L'historique montre les deux modifications qui ont provoqué le conflit, puis leur fusion :

```
*   79fbc6c (HEAD -> main) Resolution du conflit README
|\
| * dda188b (conflit-demo) Modification conflit branche A
* | ebf8a42 Modification conflit branche main
|/
*   825a2a3 Merge branch 'conflit-test'
|\
| * ee9e8db (conflit-test) Modification du README sur conflit-test
* | be9adb0 Deuxieme modification du README sur main
|/
* 1f461e3 Modification du README sur main
* 7b54462 (origin/main, origin/HEAD) exo11
```

Ce graphe permet de voir que les deux branches ont suivi des chemins différents avant de rejoindre la branche `main` lors de la résolution du conflit.

## Conclusion

Cet exercice m'a permis de provoquer volontairement un conflit Git sur le fichier :

```
C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia\ani-2053\README.md
```

J'ai ensuite suivi les étapes demandées : **lecture des marqueurs, décision, reconstruction du fichier et validation**.

La résolution a été faite sans supprimer l'historique et sans annuler la fusion. Le résultat final a été validé par le commit :

```
79fbc6c Resolution du conflit README
```
