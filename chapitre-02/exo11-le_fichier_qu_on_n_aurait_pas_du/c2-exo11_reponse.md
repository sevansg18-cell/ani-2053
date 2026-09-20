# Commit d'un fichier de 10 Mo

Pour réaliser cet exercice, j'ai encore utilisé le dépôt d'essai situé dans :

```
C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test
```

## Création du fichier de 10 Mo

J'ai d'abord créé un fichier de 10 Mo avec la commande suivante :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> fsutil file createnew gros_fichier.bin 10485760
Le fichier C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test\gros_fichier.bin est créé
```

J'ai vérifié sa taille avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> Get-Item gros_fichier.bin | Select-Object Name,Length

Name               Length
----               ------
gros_fichier.bin 10485760
```

Le fichier faisait donc bien `10 485 760` octets.

## Premier essai de commit

J'ai ajouté le fichier puis effectué le premier commit :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add gros_fichier.bin
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Ajout volontaire d'un fichier de 10 Mo"
[branche-fille 6ad3897] Ajout volontaire d'un fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 gros_fichier.bin
```

J'ai ensuite tenté d'enregistrer la suppression du fichier avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add -u
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Suppression du fichier de 10 Mo"
On branch branche-fille
nothing to commit, working tree clean
```

Cette commande n'a pas créé de commit car le fichier n'avait pas encore été supprimé du répertoire de travail.

J'ai ensuite mesuré la taille de `.git` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> (Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
85554
```

Puis en Mo :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> "{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum / 1MB)
0,08 Mo
```

Le fichier faisait pourtant 10 Mo, mais `.git` ne faisait que `0,08 Mo`. Le fichier créé avec `fsutil` était principalement composé de zéros, ce qui permettait à Git de le compresser fortement.

## Reprise de l'expérience avec des données aléatoires

J'ai donc repris l'expérience afin que le fichier contienne des données aléatoires et soit beaucoup moins compressible.

J'ai d'abord annulé les deux commits précédents :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git reset --hard HEAD~2
HEAD is now at b5868ac Modification sur la branche fille 2
```

J'ai ensuite essayé de générer les données aléatoires avec :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> $bytes = New-Object byte[] 10MB
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> [System.Security.Cryptography.RandomNumberGenerator]::Fill($bytes)
```

Cette commande a produit l'erreur suivante :

```
Échec lors de l’appel de la méthode, car
[System.Security.Cryptography.RandomNumberGenerator] ne contient pas de méthode nommée «
Fill».
```

J'ai donc utilisé une autre méthode compatible avec mon environnement PowerShell :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> $bytes = New-Object byte[] 10MB
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> $rng = [System.Security.Cryptography.RandomNumberGenerator]::Create()
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> $rng.GetBytes($bytes)
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> $rng.Dispose()
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> [System.IO.File]::WriteAllBytes("gros_fichier.bin", $bytes)
```

J'ai vérifié la taille du nouveau fichier :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> Get-Item gros_fichier.bin | Select-Object Name,Length

Name               Length
----               ------
gros_fichier.bin 10485760
```

Le fichier faisait toujours exactement `10 485 760` octets, mais il contenait maintenant des données aléatoires.

## Commit du fichier

J'ai ajouté le fichier puis effectué le commit :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add gros_fichier.bin
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Ajout volontaire d'un fichier de 10 Mo"
[branche-fille 4db1a0f] Ajout volontaire d'un fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 gros_fichier.bin
```

## Suppression du fichier et deuxième commit

J'ai ensuite supprimé le fichier :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> Remove-Item gros_fichier.bin
```

J'ai enregistré cette suppression dans le deuxième commit :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git add -u
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> git commit -m "Suppression du fichier de 10 Mo"
[branche-fille fae062f] Suppression du fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 gros_fichier.bin
```

## Mesure de la taille de `.git`

Après les deux commits, j'ai mesuré la taille du dossier `.git` :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> (Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
10577539
```

J'ai ensuite converti cette taille en mégaoctets :

```
PS C:\Users\cloth\OneDrive\Bureau\CHAP2 M.Teuguia\ani-2053\depot-test> "{0:N2} Mo" -f ((Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum / 1MB)
10,09 Mo
```
