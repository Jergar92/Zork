# Zork
First project: Zork Game "S.O.S"
This is a University project:

Zork S.O.S_1.0 release

Implemented commands:

 - Movement.
 - Open/Close.
 - Look.
 - Take/Drop.
 - Equip/Unequip.
 - Put/Get "ITEM" Into/From.
 - Atack "CREATURE".
 - Special Atack "CREATURE".
 - Speak "CREATURE".
 - Buy "CREATURE".
 - Buy "ITEM" from "CREATURE".
 - Sell "ITEM" from "CREATURE".
 - Eat/Drink "ITEM"
 - Mount Beacon
 - Push.
 - Help.
 - Quit.

Utils
 
 - You can write two words and the program separates into two.
 - You can write freely (no key sensitive).
 - You can open/close the door of the Home base.
 - You can take/drop items.
 - You can equip/unequip objects and improve yours stats.
 - You can push especific objects (only Rock)<--special feature.
 - You can put/get items into/from trunk(only one trunk)
 - You can look the path of any direction.
 - You can eat/drink items
 - You can buy/sell items
 - You can speak whits specific NPC
 - You can attack monsters
 - You can use Special attack
 - You can mount the beacon
 - You can move around the map.
 - You can type for help you get a basic guide for the game commands(same as "How to play?" section).
 - You can quit the game.

How to play?

 - You can move using the comand Go North G North, North or N.
 - You can look using the command Look North, Look N or L N.
 - You can open/close using the command Open/Close North, Open/Close N or O/C N.
 - You can take/drop items using the command Take/Drop, T/D.
 - You can equip/unequip items using the command Equip/Unequip.
 - You can put/get items into/from trunk using the command Put/Get Into/From.
 - You can push items using the command Push.
 - You can quit the program using the command Quit or Q.
 - You can eat/drink items using the command eat/drink <ITEM>.
 - You can can talk to the seller using the command speak <NPC>(Only seller).
 - You can look seller invetory using the command buy <NPC>(Only seller).
 - You can buy items using the command buy <ITEM>(only potion) from <NPC>(Only seller).
 - You can sell items using the command sell <ITEM>(only meat) to <NPC>(Only seller).
 - You can atack monsters using the command Atack <NPC>.
 - From time to time You can do one special atack on monsters using the command Special Atack <NPC>.
 - If you have the necessary objects you can finish the game using de tho command ->Mount Beacon<-
 - You can quit the program using the command Quit.
	
Example complex commands

 - Look here == Look
 - Look hero, Look hero stats
 - Look "name_item", Look "name_item" stats
 - Look inside trunk
 - Put "item" into trunk
 - Get "item" from trunk
 - Equip "item"
 - Unequip "item"
 - Push rock to north/east/west/south
 - Speak Seller
 - Sell "item" to Seller
 - Buy "item from Seller
 - But Seller
 - Eat/drink "item"
 - Attack "creature"
 - Special Attack "creature"
 - Mount Beacon

ITEMS
 - Armor-> attack: 0 defense: 20
 - Laser Gun-> attack: 20 defense: 0
 - Jump Boots-> attack: 5 defense: 5
 - Rock-> If You push rock to north you kill bear, but you lose the option to take the robot, while if you throw it to the east you can take the robot.
	  You can throw in other directions but only bring negative things
 - Core-> The bear has that object
 - Transmitter-> The Hawk has that object
 - Antenna->The Eel has that object
 - Robot-> With this object does not need energy to create the beacon
 - Fuel-> No functionality implemented
NPC

 - Monkeys-> life:25 attack: 15 defense: 5 info: monkeys can steal objects and equip, beware (if one monkey take the armor + laser gun and take one quest item sorry for you.)
 - Bear->life:100 attack: 30 defense: 20 info: the most powerful monster, a lot of life force and defense, You need an armor and gun to kill
 - Hawk->life:50 attack: 15defense: 15 info: It is a balanced beast, it would be the first that you should defeat
 - Eel->life:40 attack: 40 defense: 5  Info: is weak but very strong Equip armor if you do not want to die
 - Seller-> If you give food transforms it into potions to recover your life, but do not use all your meat because you need it to recover energy

Win Condition

-  You need the core, the transmitter and the antenna for win but also need at least 20 more energy or the robot of the waterfall

Lose Condition

- If the monster kill you or If You try to mount the beacon without energy and without the robot

