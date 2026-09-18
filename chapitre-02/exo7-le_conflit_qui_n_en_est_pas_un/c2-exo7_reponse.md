# Modification du meme fichier

J'ai cree un autre depot test mais cette fois dans mon depot `ani-2053` avec mkdir depot-test
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> mkdir depot-test


    Répertoire: C:\Users\cloth\OneDrive\Bureau\CHAP2 
    M.Teuguia\ani-2053


Mode                 LastWriteTime         Length Name               
----                 -------------         ------ ----               
d-----        18/09/2026     05:00                depot-test         


PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053> cd depot-test
```
Ensuite j'ai initialise git avec `git init`
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git init
hint: Using 'master' as the name for the initial branch. This default branch name
hint: will change to "main" in Git 3.0. To configure the initial branch name
hint: to use in all of your new repositories, which will suppress this warning,
hint: call:
hint:
hint:   git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint:   git branch -m <name>
hint:
hint: Disable this message with "git config set advice.defaultBranchName false"
Initialized empty Git repository in C:/Users/cloth/OneDrive/Bureau/CHAP2 M.Teuguia/ani-2053/depot-test/.git/
```
J'ai modifie le contenu du fichcier avec:
```
Ligne 1 : Bonjour
Ligne 2 : Bienvenue
Ligne 3 : Texte original
Ligne 4 : Texte original
Ligne 5 : Texte original
Ligne 6 : Au revoir
```
J'ai fait un commit pour signaler ma modification.
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add fichier.txt
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Version initiale"
[master (root-commit) b3dc3f8] Version initiale
 1 file changed, 6 insertions(+)
 create mode 100644 fichier.txt
```


# Demonstration

J'ai cree une branche `personne2` et j'ai modifie le fichier:
```
Ligne 1 : Bonjour
Ligne 2 : Bienvenue
Ligne 3 : Texte original
Ligne 4 : Texte original
Ligne 5 : Texte modifié par personne 2
Ligne 6 : Au revoir
```
J'ai fait un commit pour signaler la modification.
## NB: Ce commit n'a pas fonctionne parce que mon depot utilisait `master`
J'ai refait la procedur en m'assurant d'aller sur main avant de switcher sur mater:
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git branch
  master
* personne2
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git switch master
Switched to branch 'master'
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> Get-Content fichier.txt
Ligne 1 : Bonjour à tous
Ligne 2 : Bienvenue dans le projet
Ligne 3 : Texte original
Ligne 4 : Texte original
Ligne 5 : Texte original
Ligne 6 : Au revoir
```
Ensuite j'ai fait un `git merge personne2` pour fusionner automatiquement.
```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git merge personne2
Auto-merging fichier.txt
Merge made by the 'ort' strategy.
 fichier.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```

# Conclusion

Deux personnes ont modifié le même fichier `fichier.txt`, mais à des endroits différents. La première personne a modifié les lignes 1 et 2, tandis que la deuxième personne a modifié la ligne 5.

Lors du retour sur la branche `master`, la commande `git merge personne2` a automatiquement fusionné les deux modifications :

`Auto-merging fichier.txt`
`Merge made by the 'ort' strategy.`

Aucun conflit n'a été signalé et Git n'a posé aucune question. Le fichier final contient donc les modifications des deux personnes.

Cela montre que Git peut fusionner automatiquement deux modifications effectuées dans des zones différentes d'un même fichier..

## NB: Un conflit apparaît seulement lorsque les modifications se chevauchent ou concernent des lignes que Git ne peut pas fusionner automatiquement.
