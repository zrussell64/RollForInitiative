# Saikoro
A simple dice roller for DnD-style tabletop games, inspired by [this](https://www.reddit.com/r/dailyprogrammer/comments/8s0cy1/20180618_challenge_364_easy_create_a_dice_roller/) programming challenge. Requires C++11 or later.

Dice rolls are specified in the format `NdM`, where `N` is the number of dice to roll, and `M` is the number of sides on the dice. `N` and `M` are integers bounded on the following intervals:
* `N` ϵ [1, 100]
* `M` ϵ [2, 100]

Rolls are input slightly differently than described in the problem. Multiple rolls are separated by a space instead of newlines. For example, `1d6 2d8` would specify 1 roll of a 6-sided dice and 2 rolls of an 8-sided dice (instead of putting each roll on a separate line).

Output is given in the form: `Sum: Roll1 Roll2 ... RollN`, and each roll is put on a new line.

Any rolls with invalid input are ignored. For example, `1d6 200d2 30.5d10 9D9` would result in only one roll of a 6-sided dice:
* `200d2` specifies a number of rolls > 100
* `30.5d10` specifies a decimal number of rolls
* `9D9` contains a valid number of rolls and sides, but isn't separated by the correct delimiter (`d`).

Finally, the program can be closed by simply entering "end".