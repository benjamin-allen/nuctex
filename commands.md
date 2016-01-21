#Playing NuCTex
NuCTex uses a verb-noun command syntax, where verbs are the main commands known
by the game and nouns act as subcommands.

##Movement
The main movement command is `go`. `go` can be combined with the nouns `north`,
`south`, `east`, and `west` to take you in the direction you want to go. `n`,
`s`, `e`, and `w` also work as substitutes for the directions.

##Environment
`look` is the base command to view things. Currently, you can look `around` you
to see what is in the room, or, alternately, use `look room`. While looking at
yourself, called with `look me`, won't do much yet, it's something you can do.

##Inventory
To see the items that you have, use 'items' or 'inventory'. Both commands will
print your inventory as well as your equipment. To see the items in the room,
use 'look items'. The 'drop' and 'get' commands will drop items or pick them up,
respectively. Call them with the name of the item you wish to pick up.

##Fighting
You can fight a monster that is in the same location that you are in by typing
`kill <monster>`. If you don't know the name of a monster that you're trying to
kill, you can learn the names of the monsters in the available area with the
`look` command.

Once in combat, you can either attack the monster or try to flee. Both are
dependent on your stats. You can also rest, but the action does nothing at
present and exists for debugging purposes

##System
`quit` is the command issued to quit the game cleanly.
