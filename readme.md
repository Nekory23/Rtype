# RType

# Convention de commits:
[ADD] : Ajout d'un fichier ou feature

[DEL] : Delete d'un fichier ou feature

[FIX] : Fixation d'un bug

[UP] : Amélioration d'une implémentation

[DOC] : Documentation

# Protocol:
## Protocol TCP:

**Connexion au serveur**:

client -> serveur `<header: size 00 00, code 00>`

serveur -> client `<header: size 00 00, code 00>`

**Inscription**:

client -> serveur `<header: size 00 06, code 01> [6 -> name]`

server -> client `<header: size 00 00, code 01>`

**Création d'un salon de jeu**:

client -> serveur `<header: size 00 00, code 02>`

server -> client `<header: size 00 --, code 03> [8 -> id] [1 -> nb player] [nb * 6 -> player name]`

> server: ouverture d'un thread

**Rejoindre un salon**:

client -> client `<header: size 00 08, code 03> [8 -> id]`

*accès accepté*:

server -> client `<header: size 00 --, code 03> 1 [8 -> id] [1 -> nb player] [nb * 6 -> player name]`

*accès refusé*:

server -> client `<header: size 00 01, code 03> 0`

**Quitté le salon**:

client -> server  `<header: size 00 00, code 04>`

server -> client `<header: size 00 01, code 04> 1`

server -> other client `<header: size 00 08, code 05> [6 -> name]`

**Plus de joueur dans le salon**:

> server:  fermeture du thread

**lancé la partie**:

client -> server `<header: size 00 00, code 06>`

server -> all client `<header: size 00 02, code 06> [2 -> port UDP]`

> server: lance le jeu

## Protocol UDP:

**Ajout d'une entity**:

server -> all client    `<header: size 04 + x, code 01> [4 -> type] [x -> proprity]`

*proprity*:

    <drawable   [4 -> id du sprite]>
    <event      [4 -> taille de la map] <-*[4, 4 -> pair d'action]>
    <vie        [16 -> vie]>
    <ia         [4 -> stratégie] [4 -> drop]>
    <liste des armes [4 -> nombre d'arme] <-*[4 -> id entity]>
    <colision   [16 -> taille]>
    <velocité   [16 -> direction] [16 -> vitesse]>
    <position   [32 -> position]>
    <dégat      [16 -> dégat]>
    <arme       [4 -> type] [16 -> vitesse d'attaque]>
    <animation  [16 -> taille des tiles] [16 -> tile actuelle] [16 -> temps de recharge] [1 -> en cours]>
    <son        [4 -> id du son]>
    <bonus      [4 -> effet] [1 -> utilisé]

**destruction d'une entity**:

server -> all client `<header: size 00 04, code 02> [4 -> id entity]`

**event client**:

client -> server `<header: size 00 08, code 03> [4 -> id entity] [4 -> event type]`

> server: call [Ajout d'une entity] si necessaire

**event**:

*deplacement*:

server -> other client  `<header: size 00 24, code 04> [4 -> id entity] <velocité>`

*deconnexion*:

server -> other client  `<header: size 00 08, code 05> [8 -> name]`
