#define max_digits 6

#define bossfivehealth 25 // hpx3
#define bossfourhealth 25 //hpx3
#define bossthreehealth 100
#define bosstwohealth 100
#define bossonehealth 100//hpx3

#define SCREENWAIT 10
#define offscreen -9000
#define locked 0
#define unlocked 1

#define titlesel 0
#define difficultysel 1
#define vesselsel 2
#define weaponssel 3
#define cutscene 4

#define RADARFIX 420

#define GRID_WIDTH    20
#define GRID_HEIGHT   23
#define POS_X         25
#define POS_Y         0

// This is the number of X tiles for our board
#define BOARD_WIDTH  15
// This is the number of the Y tiles for our board
#define BOARD_HEIGHT 17

// This is the width in pixels of each tile
#define TILE_WIDTH		32
// This is the height in pixels of each tile
#define TILE_HEIGHT		32
// This is how many frames of animation our players's sprite has
#define PLAYER_FRAMES	1

#define maxhealthL     6
#define maxhealthM     8
#define maxhealthH     10
#define maxlevel 10

#define load 0
#define easydif	    1
#define normaldif	2
#define harddif		3
#define crueldif	4

#define special_side	 1
#define special_diagonal 2
#define special_swivel   3
#define special_friendly 4

#define bossone       11
#define bosstwo       2
#define bossthree     3
#define bossfour      4
#define bossfive      5
#define bosssix       6
#define bossseven     7
#define bosseight     8
#define bossnine      9
#define escort        10

#define max_battery 1000

#define light         0
#define medium        1
#define heavy         2

#define hurt          7
#define dyingfive     6
#define dyingfour     5
#define dyingthree    4
#define dyingtwo      3
#define dyingone      2
#define alive         1
#define dead          0

#define weapon_laser  0
#define weapon_mgun   1
#define weapon_flame  2
#define weapon_pulse  3

#define weapon_diagonallaser  0
#define weapon_sidelaser   1
#define weapon_missile 2

#define maxnuke 3
#define addlaser         0
#define addmgun          1 
#define addflame         2
#define addpulse         3
#define addhealth        4
#define adddiagonallaser 5
#define addsidelaser     6
#define addmissile       7
#define addnuke          8
#define addcharge        9
#define addbattery       10

#define scriptpowerup     -1
#define scriptone        0
#define scripttwo        1
#define scriptthree      2
#define scriptfour       3
#define scriptfive       4
#define scriptsix        5
#define scriptseven      6
#define scripteight      7
#define scriptnine       8
#define scriptten        9
#define scriptbossone         12
#define scriptbosstwo         13
#define scriptbossthree       14
#define scriptbossfour        15
#define scriptbossfive        18
#define scripteleven          16
#define scripttwelve          17


#define nukegrey         0
#define nukewhite        1
#define nukegreytwo      2
#define nukenonuke       3

#define yes           34
#define no            0

#define startypos     19
#define startxpos     9

#define ENEMY 1

#define lasermax 25
#define level_max 10
#define max_level_tiles 25

////////////// TILE DEFINES ///////////////////

#define SPACE      0

////////////// TILE DEFINES ///////////////////


// Create a define for our window height
#define HEIGHT         (TILE_HEIGHT * BOARD_HEIGHT)											
// Create a define for our window width
#define WIDTH          (TILE_WIDTH * BOARD_WIDTH)											

// We want 30 frames per second for our animation speed
#define FRAME_RATE     60

#define RADARFIXx 430	
#define RADARFIXy 469	
#define maxally 4


//wide or close formation
#define maxcloseformation	 0
#define maxopenformation     128

//types of formation
#define wedgeformation    0
#define lineformation     1
#define columnformation   2
#define coverformation    3
#define breakformation    4

#define playerupspeed 16
#define playerLRspeed 12
#define playerdownspeed 4

#define allyspeed 12
#define levelspeed 20
#define enemyspeed 6
#define elaserspeed 18
#define laserspeed 18
#define mgunspeed 24
#define flamespeed 16
#define smokespeed 16
#define sparkspeed 2

#define laserdamage 4
#define mgundamage 2
#define flamedamage 1
#define pulsedamage 3
#define missiledamage 1
#define max_particles 25
#define max_explosions 3
#define gridalignment 30

#define left -1
#define none 0
#define right 1

#define attacking 0
#define defending 1
#define passive 2

#define fixmaxmovement 15

#define BOSSONEWINGL 13*8
#define BOSSONEPIT 13*8+1
#define BOSSONEWINGR 13*8+2
#define BOSSONEWINGLH 13*8+3
#define BOSSONEWINGRH 13*8+4
#define BOSSONEPITD1 13*8+5
#define BOSSONEPITD5 13*8+6
#define BOSSONEWINGLD1 13*8+7
#define BOSSONEWINGLD2 13*8+8
#define BOSSONEWINGRD1 13*8+9
#define BOSSONEWINGRD2 13*8+10

#define maxlaserupgrade 9
#define maxmgunupgrade 20
#define maxflameupgrade 20
#define maxpulseupgrade 10

#define powerupspeed 2

#define max_levels 10

#define spawning 6
#define spawned 16
#define unspawning 17
#define unspawned 26

#define talk1 27
#define talk2 28
#define talk3 29

#define idle1S 30
#define idle1E 33
