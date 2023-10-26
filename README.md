# 42_SoLong

lib : https://github.com/codam-coding-college/MLX42

walls : https://merchant-shade.itch.io/16x16-mixed-rpg-icons
collectibles : https://bdragon1727.itch.io/150-neon-icons-effect-pack-2 / https://greatdocbrown.itch.io/coins-gems-etc 
background : https://elv-games.itch.io/free-inventory-for-rpg-or-farming-games
enemy : https://rgsdev.itch.io/pixel-art-animated-knight-character-pack-rgsdev
player: https://elthen.itch.io/2d-pixel-art-imp-sprites / https://zneeke.itch.io/dark-fantasy-monster-pack-1

idea : lockpick imp / pickpocket imp

features :

chat bubble	: using draw pixel by pixel -> rectangle(x, y, len, wid, fill_colour, border_size, border_colour);
			: write text -> text(x, y, *str, colour);
			: chat bubble -> say(*str, who); *who has assigned colours and (x, y) traced. who : select, exit !check for displaying on borders
imp on exit -> text displays random printable signs, preferably UNICODE in Cursive (?) red, changes letter by letter into "COINS!" in yellow (without cursive ?)with last letter left old value in red. 
all coins collected -> glyph changes colour.
random number generator : generates a random number from 0 to max -> random(max);


Map checker	: returns a structure that contains size of map, map plan, number of elements 