# Capture de la souris lors d'un glisser

## 1. Objectif de l'exercice

L'objectif est de réaliser un glisser qui commence dans la fenêtre et continue à l'extérieur, puis de comparer le comportement :

* sans capture de la souris ;
* avec capture de la souris.

La capture permet à la fenêtre de continuer à recevoir les événements de souris lorsque le curseur sort de sa zone.

## 2. Implémentation

Une variable permet de choisir si la capture est utilisée :

```
bool captureSouris = false;
```

Lors d'un clic gauche, la capture est activée lorsque cette variable vaut `true` :

```
if (auto *event = dynamic_cast<NkMouseButtonPressEvent *>(e))
{
    if (event->IsLeft())
    {
        if (captureSouris)
        {
            window.CaptureMouse(true);
            logger.Info("Capture souris activee");
        }
    }
}
```

Lors du relâchement du bouton gauche, la capture est désactivée :

```
if (auto *event = dynamic_cast<NkMouseButtonReleaseEvent *>(e))
{
    if (event->IsLeft())
    {
        if (captureSouris)
        {
            window.CaptureMouse(false);
            logger.Info("Capture souris liberee");
        }
    }
}
```

La compilation fonctionne avec cette implémentation.

## 3. Test sans capture

Pour le premier test, j'ai utilisé :

```
bool captureSouris = false;
```

J'ai effectué un glisser avec le bouton gauche en commençant dans la fenêtre, puis en déplaçant la souris vers l'extérieur.

### Observation

Lorsque le curseur sort de la fenêtre, il n'est plus capturé par celle-ci.

Le curseur **redevient normal** lorsqu'il quitte la fenêtre.

La fenêtre ne continue donc pas à recevoir les événements de déplacement de la souris une fois que celle-ci est sortie de sa zone.

## 4. Test avec capture

Pour le deuxième test, j'ai utilisé :

```
bool captureSouris = true;
```

J'ai effectué le même glisser : clic gauche dans la fenêtre, maintien du bouton puis déplacement vers l'extérieur.

### Observation

Cette fois, le curseur est bien capturé.

Même lorsque le curseur sort de la fenêtre, la fenêtre continue à recevoir les événements de souris.

Dans mon test, le curseur reste différent du curseur normal : il conserve le **curseur de redimensionnement vertical**.

## 5. Comparaison

### Sans capture

```
bool captureSouris = false;
```

* Le glisser commence dans la fenêtre.
* La souris sort de la fenêtre.
* La fenêtre ne capture pas la souris.
* Le curseur redevient normal à l'extérieur.

### Avec capture

```
bool captureSouris = true;
```

* Le glisser commence dans la fenêtre.
* La capture est activée au clic gauche.
* La souris peut sortir de la fenêtre.
* La fenêtre continue à recevoir les événements de souris.
* Le curseur conserve le comportement actif.
* Dans mon test, il reste sous la forme du **curseur de redimensionnement vertical**.

## 6. Conclusion

La différence principale concerne le comportement de la souris lorsque le curseur quitte la fenêtre.

**Sans capture**, le curseur redevient normal lorsqu'il sort de la fenêtre.

**Avec capture**, la fenêtre conserve la souris pendant le glisser et continue à recevoir les événements. Dans mon test, le curseur conserve alors le **curseur de redimensionnement vertical**.

La capture est donc utile pour les opérations qui doivent continuer lorsque la souris sort temporairement de la fenêtre, notamment le **glisser-déposer** et le **redimensionnement**.

