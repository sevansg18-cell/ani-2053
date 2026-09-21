# Détruire volontairement un travail avec `reset --hard` puis le retrouver avec `reflog`

Pour réaliser cet exercice, j'ai utilisé mon dépôt Git `ani-2053`, situé à l'emplacement suivant :

```
C:\Users\Administrator\OneDrive\Desktop\CHAP2 M.Teuguia\ani-2053
```

L'objectif de l'exercice est de créer un travail enregistré dans un commit, de le supprimer volontairement avec `git reset --hard`, de constater sa disparition de l'historique courant, puis de retrouver ce commit grâce à la commande `git reflog`.

## 1. Création et enregistrement du travail

J'ai choisi de travailler sur le fichier `README.md`.

J'ai d'abord ouvert le fichier avec la commande :

```
notepad README.md
```

J'ai effectué une modification dans le fichier, puis je l'ai enregistrée.

J'ai ensuite ajouté la modification à Git avec :

```
git add README.md
```

Puis j'ai créé un commit avec :

```
git commit -m "Test reset hard"
```

Le résultat obtenu est :

```
[main 0a1d7e4] Test reset hard
 1 file changed, 3 insertions(+), 1 deletion(-)
```

Le commit créé porte donc le hash `0a1d7e4` et le message `Test reset hard`.

Le message :

```
1 file changed, 3 insertions(+), 1 deletion(-)
```

indique que la modification concernait un fichier et que trois lignes ont été ajoutées tandis qu'une ligne a été supprimée.

## 2. Vérification du commit

J'ai vérifié que le commit venait bien d'être créé avec :

```
git log --oneline -3
```

Le résultat obtenu est :

```
0a1d7e4 (HEAD -> main) Test reset hard
79fbc6c Resolution du conflit README
ebf8a42 Modification conflit branche main
```

Le commit `0a1d7e4` est donc bien le dernier commit de la branche `main`.

La mention :

```
(HEAD -> main)
```

indique que `HEAD` et la branche `main` pointent actuellement sur ce commit.

À ce stade, le travail est bien enregistré dans l'historique Git.

## 3. Suppression volontaire avec `reset --hard`

Pour provoquer volontairement la perte du dernier commit, j'ai utilisé :

```
git reset --hard HEAD~1
```

Le résultat obtenu est :

```
HEAD is now at 79fbc6c Resolution du conflit README
```

La commande `HEAD~1` demande à Git de revenir au commit précédent.

L'option `--hard` demande également de remettre l'index et les fichiers de travail dans l'état correspondant au commit vers lequel `HEAD` est déplacé.

Le commit `0a1d7e4` n'est donc plus le commit courant de la branche `main`.

## 4. Constat de la perte

Après le `reset --hard`, j'ai vérifié l'historique avec :

```
git log --oneline -3
```

Le résultat obtenu est :

```
79fbc6c (HEAD -> main) Resolution du conflit README
ebf8a42 Modification conflit branche main
dda188b (conflit-demo) Modification conflit branche A
```

Le commit :

```
0a1d7e4 Test reset hard
```

n'apparaît plus dans cet historique.

La perte volontaire du commit est donc constatée : il ne fait plus partie de l'historique courant de `main`.

J'ai également vérifié l'état du dépôt avec :

```
git status
```

Le résultat obtenu est :

```
On branch main
Your branch is ahead of 'origin/main' by 7 commits.
  (use "git push" to publish your local commits)

Untracked files:
  chapitre-02/demo1-le_graphe_au_tableau/
  chapitre-02/demo2-le_conflit_resolu_en_direct/
  chapitre-02/exo12-la_regle_du_depot/

nothing added to commit but untracked files present
```

Les trois dossiers indiqués comme `Untracked files` sont indépendants de la manipulation effectuée sur le commit `Test reset hard`.

## 5. Recherche du commit perdu avec `reflog`

Même si le commit n'apparaît plus avec `git log`, j'ai utilisé la commande :

```
git reflog
```

pour rechercher les déplacements précédents de `HEAD`.

Une partie du résultat est :

```
79fbc6c (HEAD -> main) HEAD@{0}: reset: moving to HEAD~1
0a1d7e4 HEAD@{1}: commit: Test reset hard
79fbc6c (HEAD -> main) HEAD@{2}: commit (amend): Resolution du conflit README
b4d6138 HEAD@{3}: commit (amend): Resolution du conflit README
2e63919 HEAD@{4}: commit (merge): Resolution du conflit README
ebf8a42 HEAD@{5}: commit: Modification conflit branche main
825a2a3 HEAD@{6}: checkout: moving from conflit-demo to main
dda188b (conflit-demo) HEAD@{7}: commit: Modification conflit branche A
825a2a3 HEAD@{8}: checkout: moving from main to conflit-demo
825a2a3 HEAD@{9}: merge conflit-test: Merge made by the 'ort' strategy.
be9adb0 HEAD@{10}: commit: Deuxieme modification du README sur main
```

La ligne importante est :

```
0a1d7e4 HEAD@{1}: commit: Test reset hard
```

Elle permet de retrouver le hash du commit qui avait été supprimé de l'historique courant.

Le hash recherché est donc :

```
0a1d7e4
```

Le `reflog` permet ainsi de retrouver la référence d'un ancien état de `HEAD`, même après le `reset --hard`.

## 6. Tentative avec un mauvais hash

Lors de la récupération, j'ai d'abord utilisé :

```
git reset --hard abc1234
```

Git a retourné l'erreur :

```
fatal: ambiguous argument 'abc1234': unknown revision or path not in the working tree.
Use '--' to separate paths from revisions, like this:
'git <command> [<revision>...] -- [<file>...]'
```

Cette commande n'a pas fonctionné car `abc1234` n'était pas le hash réel du commit.

Grâce au `reflog`, j'avais identifié le véritable hash du commit :

```
0a1d7e4
```

J'ai donc utilisé cette référence pour effectuer correctement la récupération.

## 7. Récupération du travail

J'ai restauré le commit avec :

```
git reset --hard 0a1d7e4
```

Le résultat obtenu est :

```
HEAD is now at 0a1d7e4 Test reset hard
```

Git indique donc que `HEAD` est de nouveau positionné sur le commit `0a1d7e4`.

Le travail qui avait été retiré de l'historique courant est ainsi récupéré.

## 8. Vérification de la récupération

J'ai vérifié l'historique avec :

```
git log --oneline -3
```

Le résultat obtenu est :

```
0a1d7e4 (HEAD -> main) Test reset hard
79fbc6c Resolution du conflit README
ebf8a42 Modification conflit branche main
```

Le commit `0a1d7e4` est de nouveau présent dans l'historique de la branche `main`.

J'ai également exécuté :

```
git status
```

Le résultat obtenu est :

```
On branch main
Your branch is ahead of 'origin/main' by 8 commits.
  (use "git push" to publish your local commits)

Untracked files:
  chapitre-02/demo1-le_graphe_au_tableau/
  chapitre-02/demo2-le_conflit_resolu_en_direct/
  chapitre-02/exo12-la_regle_du_depot/

nothing added to commit but untracked files present
```

Le dépôt est donc de nouveau positionné sur le commit `Test reset hard`.

Le nombre de commits d'avance par rapport à `origin/main` est également revenu à 8, alors qu'il était de 7 après le `reset --hard HEAD~1`.

## Conclusion

Cette manipulation m'a permis de mettre volontairement en pratique la perte et la récupération d'un commit.

J'ai d'abord créé le commit :

```
0a1d7e4 Test reset hard
```

Puis je l'ai supprimé de l'historique courant avec :

```
git reset --hard HEAD~1
```

Après cette commande, le commit `0a1d7e4` n'apparaissait plus dans le résultat de `git log`.

J'ai ensuite utilisé :

```
git reflog
```

pour retrouver la trace du commit supprimé. Le `reflog` m'a permis d'identifier son hash :

```
0a1d7e4
```

Enfin, j'ai récupéré le travail avec :

```
git reset --hard 0a1d7e4
```

La commande `git log --oneline -3` a confirmé que le commit était de nouveau présent.

Cet exercice montre donc que `git reset --hard` peut retirer un commit de l'historique courant, mais que le `reflog` permet de retrouver un ancien état de `HEAD` et de restaurer le commit concerné.
