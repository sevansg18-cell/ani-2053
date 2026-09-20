# Ajout puis suppression d'un fichier de 10 Mo

Pour réaliser cette manipulation, je me suis placé dans mon dépôt d'essai avec le chemin suivant :

```
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test
```

L'objectif était de créer volontairement un fichier de **10 Mo**, de le commit, puis de le supprimer au commit suivant afin de mesurer l'évolution de la taille du dossier `.git`.

## Mesure de la taille avant l'ajout

Avant de commencer la nouvelle expérience, j'ai d'abord supprimé les anciens objets Git qui n'étaient plus utilisés avec les commandes :

```
git reflog expire --expire=now --all
git gc --prune=now
```

Le résultat de `git gc` a été :

```
Enumerating objects: 30, done.
Counting objects: 100% (30/30), done.
Delta compression using up to 12 threads
Compressing objects: 100% (20/20), done.
Writing objects: 100% (30/30), done.
Total 30 (delta 11), reused 0 (delta 0), pack-reused 0 (from 0)
```

J'ai ensuite mesuré la taille du dossier `.git` avec :

```
(Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
```

J'ai obtenu :

```
34555
```

Puis j'ai converti cette valeur en Mo avec :

```
"{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum / 1MB)
```

Résultat :

```
0,03 Mo
```

Cette valeur constitue donc mon état **avant l'ajout du fichier de 10 Mo**.

## Création du fichier de 10 Mo

Pour créer le fichier, j'ai utilisé PowerShell afin de générer des données aléatoires. J'ai utilisé les commandes suivantes :

```
$bytes = New-Object byte[] 10MB
$rng = [System.Security.Cryptography.RandomNumberGenerator]::Create()
$rng.GetBytes($bytes)
$rng.Dispose()
[System.IO.File]::WriteAllBytes("gros_fichier.bin", $bytes)
```

J'ai ensuite vérifié la taille du fichier avec :

```
Get-Item gros_fichier.bin | Select-Object Name,Length
```

J'ai obtenu :

```
Name               Length
----               ------
gros_fichier.bin 10485760
```

Le fichier fait donc exactement **10 485 760 octets**.

## Ajout du fichier dans le dépôt

J'ai ajouté le fichier à l'index avec :

```
git add gros_fichier.bin
```

Puis j'ai créé le premier commit avec :

```
git commit -m "Ajout volontaire d'un fichier de 10 Mo"
```

Le résultat obtenu est :

```
[branche-fille d3fe3c4] Ajout volontaire d'un fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 gros_fichier.bin
```

Après ce commit, j'ai mesuré à nouveau la taille de `.git` :

```
(Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
```

Résultat :

```
10524309
```

Puis :

```
"{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum / 1MB)
```

Résultat :

```
10,04 Mo
```

La taille de `.git` est donc passée de **0,03 Mo avant l'ajout** à **10,04 Mo après le commit**.

## Suppression du fichier

Après avoir ajouté le fichier dans un premier commit, j'ai supprimé le fichier du répertoire de travail avec :

```
Remove-Item gros_fichier.bin
```

J'ai ensuite vérifié l'état du dépôt avec :

```
git status
```

J'ai obtenu :

```
On branch branche-fille
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    gros_fichier.bin

no changes added to commit (use "git add" and/or "git commit -a")
```

Cela montre que Git a bien détecté la suppression du fichier, mais que cette modification n'était pas encore préparée pour le commit.

J'ai donc utilisé :

```
git add -u
```

Puis j'ai créé le deuxième commit avec :

```
git commit -m "Suppression du fichier de 10 Mo"
```

Le résultat obtenu est :

```
[branche-fille 1dec404] Suppression du fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 gros_fichier.bin
```

Le fichier a donc été supprimé de l'état actuel du projet.

## Mesure après la suppression

Après le commit de suppression, j'ai mesuré une dernière fois la taille de `.git` avec :

```
(Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
```

J'ai obtenu :

```
10524769
```

Puis :

```
"{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum / 1MB)
```

Résultat :

```
10,04 Mo
```

Avant l'expérience, `.git` occupait seulement **0,03 Mo**. Après l'ajout du fichier de 10 Mo, sa taille est passée à **10,04 Mo**.

Après la suppression du fichier et la création du deuxième commit, la taille est restée pratiquement identique : **10,04 Mo**.

La différence entre la mesure après l'ajout et celle après la suppression est seulement de :

```
10524769 - 10524309 = 460 octets
```

Cette faible différence ne correspond pas à la suppression des 10 Mo du fichier. Elle provient des informations supplémentaires enregistrées par Git pour le nouveau commit.

## Conclusion

Cette manipulation montre que supprimer un fichier ne supprime pas automatiquement son contenu de l'historique Git.

Le fichier `gros_fichier.bin` a d'abord été enregistré dans le commit `d3fe3c4`. Même après sa suppression dans le commit `1dec404`, les données du premier commit restent présentes dans l'historique du dépôt.

C'est pourquoi `.git` passe de **0,03 Mo avant l'expérience** à environ **10,04 Mo après l'ajout**, puis reste à environ **10,04 Mo après la suppression**.

La suppression permet donc de retirer le fichier de la version actuelle du projet, mais elle ne permet pas de récupérer immédiatement l'espace occupé par sa version précédente dans l'historique Git.
