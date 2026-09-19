# Clonage de mon depot ani-2053

Pour cloner mon depot, j'ai utilise la commande `git clone URL du depot`.

J'ai effectue deux clones afin de simuler deux personnes travaillant sur le meme depot :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> git clone https://github.com/sevansg18-cell/ani-2053.git clone1
Cloning into 'clone1'...
remote: Enumerating objects: 43, done.
remote: Counting objects: 100% (43/43), done.
remote: Compressing objects: 100% (32/32), done.
remote: Total 43 (delta 7), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (43/43), 17.93 KiB | 73.00 KiB/s, done.
Resolving deltas: 100% (7/7), done.
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> git clone https://github.com/sevansg18-cell/ani-2053.git clone2
Cloning into 'clone2'...
remote: Enumerating objects: 43, done.
remote: Counting objects: 100% (43/43), done.
remote: Compressing objects: 100% (32/32), done.
remote: Total 43 (delta 7), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (43/43), 17.93 KiB | 86.00 KiB/s, done.
Resolving deltas: 100% (7/7), done.
```

Les deux clonages se sont donc correctement déroulés. Les dossiers `clone1` et `clone2` constituent deux copies de travail indépendantes du meme depot.

Ensuite, j'ai utilise `Get-ChildItem .\clone1 -Recurse -File | Select-Object -First 20 FullName` pour verifier les fichiers presents dans le clone :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Get-ChildItem .\clone1 -Recurse -File | Select-Object -First 20 FullName

FullName                                                             
--------                                                             
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\README.md      
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\chapitre-02\...
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\chapitre-02\...
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\chapitre-02\...
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\chapitre-02\...
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1\chapitre-02\...
```

Cette commande permet de vérifier que le clonage a bien créé les fichiers du depot dans `clone1`.

# Modifications

J'ai choisi le fichier `README.md` pour faire les modifications.

Pour provoquer un conflit, j'ai modifie la meme ligne de ce fichier dans les deux clones, mais avec un contenu different.

Dans `clone1`, j'ai d'abord verifie le contenu initial :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Get-Content .\clone1\README.md
# ani-2053
```

J'ai ensuite modifie le fichier directement avec le terminal :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Set-Content .\clone1\README.md "# ani-2053 - Modification clone1"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Get-Content .\clone1\README.md
# ani-2053 - Modification clone1
```

J'ai par la suite fait un `git add README.md`, puis un `git commit` et un `git push` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1> git add README.md
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1> git commit -m "Modification depuis clone1"
[main 3b8b0a2] Modification depuis clone1
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone1> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 330 bytes | 330.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/sevansg18-cell/ani-2053.git
   b778ee1..3b8b0a2  main -> main
```

Le premier clone a donc réussi à envoyer sa modification sur le depot distant.

J'ai reproduit la meme modification dans `clone2`, mais avec une valeur différente sur la meme ligne. J'ai ensuite effectué un `git add`, un `git commit` puis un `git push`.

#### Sauf que lors du `git push` du clone 2, le push a ete rejete :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git push
To https://github.com/sevansg18-cell/ani-2053.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/sevansg18-cell/ani-2053.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

Le `push` de `clone2` est refuse car le depot distant contient deja le commit provenant de `clone1`, alors que `clone2` ne possede pas encore ce commit. Git empeche donc cette mise a jour afin de ne pas ecraser le travail deja present sur le depot distant.

# Conflits

J'ai fait `git pull` dans `clone2` pour recuperer le commit du premier clone :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git pull
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 3 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 310 bytes | 14.00 KiB/s, done.
From https://github.com/sevansg18-cell/ani-2053
   b778ee1..3b8b0a2  main       -> origin/main
hint: You have divergent branches and need to specify how to reconcile them.
hint:
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint:
hint: You can replace "git config" with "git config --global" or pass
hint: --rebase, --no-rebase, or --ff-only on the command line to override
hint: the configured default per invocation.
fatal: Need to specify how to reconcile divergent branches.
```

Git a bien récupéré la nouvelle version distante, mais il a constaté que les deux historiques avaient diverge : `clone2` possédait son propre commit et `origin/main` possédait le commit provenant de `clone1`.

J'ai donc relance `git pull` en precisant que je voulais utiliser une fusion (`merge`) :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git pull --no-rebase
Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.
```

Git a détecté un conflit de contenu dans `README.md` parce que les deux clones avaient modifié la meme ligne.

# Resolution

J'ai d'abord affiche le conflit avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Get-Content .\README.md
<<<<<<< HEAD
# ani-2053 - Modification clone2
=======
# ani-2053 - Modification clone1
>>>>>>> 3b8b0a2409f8cc15377f1f3ee6d376fd7d883c1a
```

Git a donc placé les deux versions dans le fichier avec les marqueurs `<<<<<<<`, `=======` et `>>>>>>>`.

La version située **au-dessus de `=======`** est celle de `clone2`, c'est-à-dire la version correspondant à `HEAD` :

```
# ani-2053 - Modification clone2
```

La version située **en-dessous de `=======`** est celle provenant du commit récupéré depuis le depot distant, donc la modification envoyée précédemment par `clone1` :

```
# ani-2053 - Modification clone1
```

J'ai ensuite résolu le conflit en choisissant un nouveau contenu commun :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Set-Content .\README.md "# ani-2053 - Conflit resolu"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Get-Content .\README.md
# ani-2053 - Conflit resolu
```

J'ai vérifié le contenu du fichier, puis j'ai utilisé `git add README.md` pour indiquer à Git que le conflit était résolu.

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git status
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git add README.md
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git status
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   README.md
```

Le deuxième `git status` montre que le conflit est maintenant résolu : Git indique `All conflicts fixed but you are still merging`. La fusion n'est toutefois pas encore terminée ; il faut encore créer le commit de fusion.

J'ai par la suite fait un commit :

```
git commit -m "Résolution du conflit dans README"
```

Ce commit permet d'enregistrer la résolution du conflit et de terminer la fusion entre les deux historiques.

Enfin, j'ai effectué un `push` afin d'envoyer le résultat de la fusion sur le depot distant :

```
git push
```

Ainsi, les deux modifications réalisées séparément dans `clone1` et `clone2` ont été intégrées dans une meme histoire Git après la résolution manuelle du conflit.
