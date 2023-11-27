# SO_LONG ROADMAP
This is the roadmap of so_long project. Here will some of the informations needed to do the project.

## Map
Maps needs to be .ber format.

A valid map is structured as followed :
- 1 player (P)
- at least 1 exit (E)
- at least 1 collectible (C)
- is rectangular
- has a solid outside border of walls (1)
- all the empty spaces are filled with 0
- not other characters than :
	- P
	- E
	- C
	- 0
	- 1

For example :

	1111111111111
	10010000000C1
	1000011111001
	1P0011E000011
	1111111111111

Which would look like this :

<img src="images/examplemap.png" width="400"/><br>
