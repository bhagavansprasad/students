#King - King, Queen - Queen, 
#Bishap - Camel, 
#kNight - Horse, 
#rook - Elephant, 
#pawn - Solder

import json
'''
pos2value
{
	(1, 1) : { "ccolor" : "w", "coin" : "K", "pos":(1, 1) }, #White King
	(1, 2) : { "ccolor" : "b", "coin" : "k", "pos":(1, 2) }, #Blacks King
}
value2pos
{
	"K" : (1, 1),
	"k" : (1, 2),
}
'''
#position to values
board = {}

#value2pos
coin_2_pos = {}

#white_coins = ["Q", "B1", "N1", "R1", "B2", "N2", "R2", "P1"]
#coins = ["K", "Q", "N", "R", "B", "P", "k", "q", "n", "r", "b", "p"]

#pos_n_coins = {}
coins_n_pos = {
	"K":(),  "Q":(),  "N1":(), "B1":(), "R1":(), "N2":(), "B2":(), "R2":(),
	"P1":(), "P2":(), "P3":(), "P4":(), "P5":(), "P6":(), "P7":(), "P8":(), 
	"k":(),  "q":(),  "n1":(), "b1":(), "r1":(), "n2":(), "b2":(), "r2":(),
	"p1":(), "p2":(), "p3":(), "p4":(), "p5":(), "p6":(), "p7":(), "p8":()
}
maxrows = 8
maxcols = 8

def init_board():
	cell_color = "b"

	for i in range(1, maxrows+1):
		for j in range(1, maxcols+1):
			if (cell_color == "b"):
				cell_color = "w"
			else:
				cell_color = "b"

			board.update({(i,j):{"color" : cell_color, "coin":"", "pos":(i, j)}})
			#print (i, j, cell_color)
		if (cell_color == "b"):
			cell_color = "w"
		else:
			cell_color = "b"
		#print ("")


def dump_board():
	for i in range(1, maxrows+1):
		for j in range(1, maxcols+1):
			print(board[(i, j)])
		print ("")

def dum_coin_2_pos():
	print(coin_2_pos)

def add_pawn(coin, row, col):
	for i in range (1, maxcols+1):
		key = coin+str(i)
		'''
		if (not coins_n_pos[key]):
			coins_n_pos[key] = (row, col)
			board[(row, col)]["coin"] = key
			break
		'''
		if ((key in coin_2_pos) == False):
			board[(row, col)]["coin"] = key
			coin_2_pos[key] = (row, col)
			break
			
def add_others(coin, row, col):
	coin = coin+str(1)

	if ((coin in coin_2_pos) == False):
		board[(row, col)]["coin"] = coin
	else:
		coin = coin+str(2)
		board[(row, col)]["coin"] = coin

	coin_2_pos[coin] = (row, col)
	
	
def add_element(coin, row, col):
	print ("coin :%s, row :%d, col :%d" % (coin, row, col))
	if (coin == "K" or coin == "Q" or coin == "k" or coin == "q"):
		#coins_n_pos[coin] = (row, col)
		board[(row, col)]["coin"] = coin
		coin_2_pos[coin] = (row, col)
	elif (coin == "P" or coin == "p"):
		add_pawn(coin, row, col)
	elif (coin == "P" or coin == "p"):
		add_others(coin, row, col)
	
	#"N", "R", "B", "P", "k", "q", "n", "r", "b", "p"]
	
'''
def get_possible_promotable_coins(pawn_name, ppos):
	white_coins = ["Q", "B1", "N1", "R1", "B2", "N2", "R2", "P1"]
	print("############White coins and positions")
	for element in white_coins:
		if (not coins_n_pos[element]):
			print(element, ":", coins_n_pos[element])

def dump_coins_n_pos():
	print("############coins and positions")
	for element in coins_n_pos.items():
		if (element[1]):
			print (element)
'''

'''
def dump_white_coins():
	print("############White coins and positions")
	for element in white_coins:
		if (coins_n_pos[element]):
			print(element, ":", coins_n_pos[element])
	print ("")

def dump_pos_n_coins():
	print("############positions and coins")
	for element in pos_n_coins.items():
		if (element[1]):
			print (element)

def init_pos_n_conins():
	for i in range(1, 9):
		for j in range(1, 9):
			pos_n_coins.update({(i,j):None})

def update_pos_n_coins():
	for element in coins_n_pos.items():
		if (element[1]):
			pos_n_coins[element[1]] = element[0]
'''


def get_count(board):
	spawn = "P1"

	for (i, line) in enumerate(board):
		for (j, coin) in enumerate(line[0]):
			if (coin != '#'):
				print ("row :%d, col :%d, coin :%s, line :%s" % (maxrows-i, j+1, coin, line))
				add_element(coin, maxrows-i, j+1)
		print ("")

	dump_board()	
	dum_coin_2_pos()
	return
	#dump_coins_n_pos()
	update_pos_n_coins()
	#dump_pos_n_coins()
	#dump_white_coins()
	#promoted_coins = get_possible_promotable_coins(spawn, coins_n_pos[spawn])

d1 = [
["########"],
["#k#P#P##"],
["###PP###"],
["########"],
["########"],
["########"],
["#K######"],
["########"]
]

d2 = [
["########"],
["######P#"],
["####k###"],
["########"],
["########"],
["########"],
["####K###"],
["########"]
]

def main():
	init_board()
	#dump_board()
	#init_pos_n_conins()
	get_count(d1)
	#get_count(d2)

if (__name__ == "__main__"):
	main()


