# Intégration par fusion puis par rejeu

Pour réaliser cet exercice, j'ai utilisé mon dépôt d'essai situé dans le dossier :

```
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test
```

L'objectif était de réaliser deux fois la même intégration : une première fois avec une **fusion (`merge`)**, puis une deuxième fois avec un **rejeu (`rebase`)**, afin de comparer les deux graphes.

---

## 1. Vérification des branches existantes

Je me suis placé dans mon dépôt d'essai et j'ai d'abord essayé de me placer sur la branche `main` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git switch main
fatal: invalid reference: main
```

La branche `main` n'existant pas dans mon dépôt, j'ai vérifié les branches disponibles :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git branch
* branche-fille
  master
  personne2
```

J'ai ensuite affiché le graphe initial :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git log --oneline --graph --all --decorate
* 573860c (HEAD -> branche-fille) Modification sur la branche fille 2
* 1ddef9d Modification sur la branche fille 1
*   8422b45 (master) Merge branch 'personne2'
|\
| * b7727e3 (personne2) Modification de la fin du fichier
* | 7b2c424 Modification du début du fichier
|/
* b3dc3f8 Version initiale
```

À ce moment-là, `branche-fille` avait deux commits supplémentaires par rapport à `master`.

---

# 2. Création d'une divergence entre les branches

Je suis revenu sur la branche principale de mon dépôt, qui s'appelle `master` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git switch master
Switched to branch 'master'
```

J'ai vérifié que le dépôt était propre :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
nothing to commit, working tree clean
```

J'ai ensuite ouvert `fichier.txt` avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> notepad fichier.txt
```

Après avoir effectué ma modification, j'ai ajouté le fichier et créé un commit :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add fichier.txt

PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Modification sur master"
[master 474e730] Modification sur master
 1 file changed, 2 insertions(+), 1 deletion(-)
```

J'ai ensuite vérifié le graphe :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git log --oneline --graph --all --decorate
* 474e730 (HEAD -> master) Modification sur master
| * 573860c (branche-fille) Modification sur la branche fille 2
| * 1ddef9d Modification sur la branche fille 1
|/
*   8422b45 Merge branch 'personne2'
|\
| * b7727e3 (personne2) Modification de la fin du fichier
* | 7b2c424 Modification du début du fichier
|/
* b3dc3f8 Version initiale
```

Les branches `master` et `branche-fille` étaient alors divergentes.

---

# 3. Première intégration : fusion avec `merge`

J'ai effectué la fusion de `branche-fille` dans `master` avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git merge branche-fille
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
Automatic merge failed; fix conflicts and then commit the result.
```

Git a donc détecté un conflit dans `fichier.txt`.

J'ai vérifié l'état du dépôt :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch master
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
```

J'ai ouvert le fichier pour résoudre le conflit :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> notepad fichier.txt
```

Après avoir résolu le conflit dans le fichier, j'ai ajouté le fichier :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add fichier.txt
```

Puis j'ai terminé la fusion :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Fusion de branche-fille dans master"
[master 463fdf4] Fusion de branche-fille dans master
```

J'ai ensuite affiché le graphe :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git log --oneline --graph --all --decorate
*   463fdf4 (HEAD -> master) Fusion de branche-fille dans master
|\
| * 573860c (branche-fille) Modification sur la branche fille 2
| * 1ddef9d Modification sur la branche fille 1
* | 474e730 Modification sur master
|/
*   8422b45 Merge branch 'personne2'
|\
| * b7727e3 (personne2) Modification de la fin du fichier
* | 7b2c424 Modification du début du fichier
|/
* b3dc3f8 Version initiale
```

Le résultat de cette première intégration est donc un historique avec un **commit de fusion `463fdf4`**.

---

# 4. Conservation du résultat de la fusion

Afin de conserver le résultat obtenu avec `merge` avant de réaliser le `rebase`, j'ai créé une branche appelée `resultat-merge` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git branch resultat-merge
```

J'ai vérifié les branches :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git branch
  branche-fille
* master
  personne2
  resultat-merge
```

La branche `resultat-merge` permet ainsi de conserver le résultat de la première expérience.

---

# 5. Retour à l'état avant la fusion

Pour réaliser la deuxième expérience avec `rebase`, je suis revenu au commit de `master` qui existait juste avant la fusion :

```
474e730 Modification sur master
```

J'ai utilisé :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git reset --hard 474e730
```

Le résultat de la fusion restait conservé dans la branche `resultat-merge`.

---

# 6. Deuxième intégration : rejeu avec `rebase`

Je me suis placé sur la branche `branche-fille` et j'ai lancé le rejeu avec `master` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git rebase master
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
error: could not apply 1ddef9d... Modification sur la branche fille 1
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config set advice.mergeConflict false"
Could not apply 1ddef9d... # Modification sur la branche fille 1
```

Le premier commit de `branche-fille` provoquait donc un conflit.

J'ai résolu le conflit dans `fichier.txt`, puis j'ai poursuivi le rejeu avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git rebase --continue
[detached HEAD eca5ae7] Modification sur la branche fille 1
 1 file changed, 7 insertions(+), 1 deletion(-)
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
error: could not apply 573860c... Modification sur la branche fille 2
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config set advice.mergeConflict false"
Could not apply 573860c... # Modification sur la branche fille 2
```

Le premier commit avait donc été rejoué sous le nouvel identifiant :

```
1ddef9d → eca5ae7
```

Git a ensuite rencontré un deuxième conflit lors du rejeu du commit :

```
573860c Modification sur la branche fille 2
```

J'ai résolu ce deuxième conflit, ajouté le fichier, puis continué le rejeu avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git rebase --continue
[detached HEAD b5868ac] Modification sur la branche fille 2
 1 file changed, 5 insertions(+)
Successfully rebased and updated refs/heads/branche-fille.
```

Le deuxième commit avait alors lui aussi obtenu un nouvel identifiant :

```
573860c → b5868ac
```

---

# 7. Vérification de l'état du dépôt après le `rebase`

J'ai vérifié l'état du dépôt :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git status
On branch branche-fille
nothing to commit, working tree clean
```

Le rejeu était donc terminé et le dépôt était propre.

J'ai finalement affiché le graphe complet :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git log --oneline --graph --all --decorate
* b5868ac (HEAD -> branche-fille) Modification sur la branche fille 2
* eca5ae7 Modification sur la branche fille 1
| * 463fdf4 (resultat-merge) Fusion de branche-fille dans master
|/|
| * 573860c Modification sur la branche fille 2
| * 1ddef9d Modification sur la branche fille 1
* | 474e730 (master) Modification sur master
|/
*   8422b45 Merge branch 'personne2'
|\
| * b7727e3 (personne2) Modification de la fin du fichier
* | 7b2c424 Modification du début du fichier
|/
* b3dc3f8 Version initiale
```

---

# 8. Comparaison des deux graphes

Avec `merge`, le résultat conservé dans `resultat-merge` contient un commit de fusion :

```
*   463fdf4 Fusion de branche-fille dans master
|\
| * 573860c Modification sur la branche fille 2
| * 1ddef9d Modification sur la branche fille 1
* | 474e730 Modification sur master
|/
```

Avec `rebase`, les deux commits de `branche-fille` ont été rejoués après `master` :

```
* b5868ac Modification sur la branche fille 2
* eca5ae7 Modification sur la branche fille 1
* 474e730 Modification sur master
```

Le `rebase` a donc produit un historique plus linéaire. Les commits ont changé d'identifiant parce qu'ils ont été recréés lors du rejeu.

Je préfère lire le graphe obtenu avec le `rebase`, car il est plus linéaire et permet de suivre les commits dans un ordre plus simple. Le graphe obtenu avec `merge` montre davantage la divergence et la réunion des branches grâce au commit de fusion.
