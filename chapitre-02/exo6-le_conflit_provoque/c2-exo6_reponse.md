# Clonage de mon depot ani-2053

Pour cloner mon depot j'ai utilise `git clone URL du depot`:

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
J'ai effectue deux clones pour faire l'exercice.

Ensuite j'ai utilise `Get-ChildItem .\clone1 -Recurse -File | Select-Object -First 20 FullName` pour verifier les dossiers et fichiers presents dans mes clones:
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

# Modifications

J'ai choisi le `README.md` pour faire les modifications.
J'ai fait les modifications directement avec mon terminal
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Get-Content .\clone1\README.md
# ani-2053
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Set-Content .\clone1\README.md "# ani-2053 - Modification clone1"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia> Get-Content .\clone1\README.md
# ani-2053 - Modification clone1
```
J'ai par la suite fait un `git add README.md` puis un `git commit -m"..."` et un `git push`:
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
J'ai reproduit exactement la meme chose clone 2. 
#### Sauf que lors du git push du clone 2 le push a ete rejete:
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

# Conflits

J'ai fait `git pull` pour recuperer le commit du premier clone
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
hint: You can do so by running one of the following commands sometime before
hint: your next pull:
hint:
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint:
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
fatal: Need to specify how to reconcile divergent branches.
```
J'ai relance `git pull` en mode merge pour faire une fusion:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> git pull --no-rebase
Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.

```
# Resolution

J'ai d'abord affiche le conflit:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Get-Content .\README.md
<<<<<<< HEAD
# ani-2053 - Modification clone2
=======
# ani-2053 - Modification clone1
>>>>>>> 3b8b0a2409f8cc15377f1f3ee6d376fd7d883c1a
```
Ensuite j'ai resolu le confilt et affiche `Conflit resolu`
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Set-Content .\README.md "# ani-2053 - Conflit resolu"
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\clone2> Get-Content .\README.md
# ani-2053 - Conflit resolu
```
J'ai verifier, ajoute et reverifier.
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

J'ai par la suite fait un commit `"Résolution du conflit dans README"` et un push.

### J'ai affiche tous messages. 
