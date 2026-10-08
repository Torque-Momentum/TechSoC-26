I have completed Level 1 and Level 2 but could not complete the Status_Effect part in Level 3.
I have declared 6 characters in Level 1 and Level 2 , and 12 Characters in Level 3
# Level 1
This has manual input. You have to manually choose your attacker and defender. I could also make a randomised one but then it wouldnt require any input which I think is not a good idea.

# Classes:
## Bender Class:
I defined the objects such as name, element, hp etc. which are required.
I defined the constructor, also defined a empty constructor so that I can take variables as Objects in the Class and use them for operations (h and g strings which are used to take input from User).

I wanted to have a better grasp with working with vectors, so I created vectors and not arrays for moves, also, they are more dynamic than arrays as well.

### Display_Stats
This function is used to display the stats of the benders chosen.
### Attacker
This function is used to attack the defender, taking the defender object and the move no. as input , as in:

attackingbender.attacker(defendingbender, move no.)

Taking them as input, it calculates the damage and updates hp accordingly 
(note that HP is the initial hp of the Bender)

### is_fainted
This function checks if the bender is fainted or not, it can be called by
x.is_fainted()

### showAttacks
This function is used to display the choice of attacks the user can select.

# Level 2
I have created both randomised and manual versions of this level. So that, it can generate both user controlled outputs, and a quick output for reference.


#### Manual Input 
Asks for user's choice of characters and begins the duel  and gives choice of moves at each Turn. Two persons can actually play this as a game.

#### Randomised Input 
Asks for user's choice of characters and begins the duel and makes choice of random moves until a player is eliminited


I created a Duel class for this:
It takes two benders as input from user and processes them using the methods inside the class.

# Duel Class
# start_duel
The duel(x,y) object takes input from the user to process the benders in the Duel Class.
This is the main function which makes the duel happen.
There are two pointer objects "first" and "second" which are assigned to the Benders b1 and b2 (input from user) based on conditions from Line 164 to Line 184. Then in case of Manual Input, it asks for the Player Input for moves.
## Rand_Move
This is a random num generator from (0,3) which gives the index for the moves (for the Randomised input part).


# Level 3

I had to create two more classes for this Level. I could not create a generalised system for the numbers of players but i created one with the options 2,4 and 8.
I could also create a 16 player tournament option as well but it was getting very complex so i dropped the idea.

**Global Variables**

total_crits, total_sefs, total_turns and turn_i are declared outside all the classes. They count critical hits, super effective hits and turns across the whole program. Every Duel adds its numbers to these, which is how the Tournament statistics are calculated.

**Bender Class**

This is the base class. It holds everything a character needs.

Important variables:

- name, element, attack, defense, speed: the basic stats.
- hp is the current HP, which changes during the fight. HP (capital) is the initial/max HP, used for display and healing.
- moves is a vector of tuples. Each tuple has (move name, move power, effect).
- type_counter and critical_counter count the super effective and critical hits of that Bender.
- type_multiplier and critical_multiplier are used in the damage calculation.
- healing_move and strongest_move store the names of those moves. The AI uses them.

I made two constructors. One takes all the stats and moves. The other is empty, so I can declare empty Bender objects first and assign them later (like AI_Player and User_Player in main).

Functions:

display_stats  
Prints the stats and moves of the Bender.

attacker  
The main combat function, called like attackingbender.attacker(defendingbender, move_index).

1. Calculates base damage = attack × move power / defender’s defense.
2. Checks the elements for the type multiplier (2.0 super effective, 0.5 not very effective, 1.0 otherwise).
3. If the move power is 0, it is a healing move and restores 30% of the total HP, capped at max HP.
4. Rolls 1 to 100. If it is 10 or below, it is a critical hit (10% chance) and damage is doubled.
5. Subtracts the final damage from the defender’s hp, and sets it to 0 if it goes negative.

has_healing_move  
Checks whether the Bender’s healing move (index 2) has power 0.

is_fainted  
Checks if hp is 0 or below and prints true or false.

showAttacks  
Prints the list of moves for the user to choose from.

**Duel Class**

It takes two Benders (b1, b2) and runs a full fight between them.

start_duel  
This is the main function that makes the duel happen.

- Two pointers, first and second, are assigned to b1 and b2 by speed. The faster one goes first, and on equal speed it is random.
- In a do-while loop, first attacks, then second strikes back, until one hp reaches 0.
- At the end it prints the Duel Summary (winner, turns, critical hits, super effective hits) and adds these to the global counters.
- It stores the Winner and Loser pointers, which the Tournament class uses.

Rand_Move  
Random number generator from (0,3) which gives the index of the move, for randomised moves.

**Tournament Class**

This class manages everything related to the tournament (2, 4 or 8 players). I could not make a general version for any number of players, so I made it for 2, 4 and 8.

Vectors (this is the confusing part, so here is what each one holds):

- Players: the Benders chosen by the user, in the order chosen.
- Sort: the same Benders in randomised order. It is filled randomly, with a check so the same Bender isn’t added twice. The first-round matches are made from this.
- winnersof2: the winners of the first round. In a 4-player tournament these are the semifinal winners (2 of them). In an 8-player tournament these are the quarterfinal winners (4 of them), and they are shuffled again before the semifinals.
- winnersof2in4: holds the winner of the final in the 4-player tournament, so winnersof2in4.at(0) is the champion there. The name means “winner of the last 2-player duel in the 4-player tournament”.
- winnersof2in8: used only in the 8-player tournament. It holds the semifinal winners (2 of them). The name means “winners of the 2-player duels in the 8-player tournament”.
- winnerfinalein8: used only in the 8-player tournament. It holds the winner of the final, so winnerfinalein8.at(0) is the champion there.

Functions:

- roundof_2(x, y): creates a Duel between Sort[x] and Sort[y], runs it, and stores the winner in winnersof2. It is used for the first round in every tournament size.
- roundof_2in4(): runs the final between winnersof2[0] and winnersof2[1] and stores the winner in winnersof2in4. It is used for the final of the 4-player tournament.
- roundof_2in8(x, y): creates a Duel between winnersof2[x] and winnersof2[y], runs it, and stores the winner in winnersof2in8. It is used for the semifinals of the 8-player tournament.
- roundfinalein8(): runs the final between winnersof2in8[0] and winnersof2in8[1] and stores the winner in winnerfinalein8. It is used for the final of the 8-player tournament.
- roundof_4: prints the brackets, runs 2 semifinals (roundof_2), then the final (roundof_2in4), and prints the statistics (3 battles).
- roundof_8: runs 4 quarterfinals (roundof_2), shuffles the 4 winners randomly for the semifinals, runs 2 semifinals (roundof_2in8), then the final (roundfinalein8), and prints the statistics (7 battles).
- start_tournament: prints the participants, shuffles them into Sort, and calls roundof_2, roundof_4 or roundof_8 depending on the number of players.

**AI Class**

This is for the AI Duel mode, where the user plays against the computer.

Important variables:

- UP is the User Player and AP is the AI Player.
- difficulty is Easy, Medium or Hard.
- pehla and dusra (“first” and “second” in Hindi) are pointers that work like first and second in the Duel class, assigned by speed.

AI_duel  
Works like start_duel, but on the user’s turn it shows the moves and takes input with cin. On the AI’s turn, the move depends on the difficulty:

- Easy: Random moves. Every move comes from Rand_Move().
- Medium: 50% chance of a random move, otherwise the calculated move from AI_Atk().
- Hard: 100% chance of the calculated move from AI_Atk().

AI_Atk  
This is the “calculated” move logic. It looks at the AI and the user, and returns the name of the move to use:

- If the AI’s HP is below 30% and it has a healing move, it heals.
- If the user’s HP is below 25%, it uses its strongest move to finish them.
- Otherwise, it picks a random move.

AI_duel then matches this name against the AI’s moves to find the index to attack with.

**main**

First I create all 12 Benders and put them in the AllPlayers vector. Then I make separate vectors for each element (FireType, WaterType, etc.).

Then it asks for the gamemode:

1. Player vs Player tournament: asks the number of players (2, 4, 8), takes the characters, and starts the Tournament.
2. AI Duel: the user picks a character, and the AI picks an opponent whose element is strong against the user’s (Fire → Water, Water → Earth, Earth → Air, Air → Fire). Then the user picks a difficulty and AI_duel starts.

