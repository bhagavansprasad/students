#King - King, Queen - Queen, 
#Queen - Queen
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


maxrows = 8
maxcols = 8

def init_board():
	board.clear()
	coin_2_pos.clear()
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

def dump_board_only_filled():
	for i in range(1, maxrows+1):
		for j in range(1, maxcols+1):
			if (board[(i, j)]["coin"]):
				print(board[(i, j)])

def dum_coin_2_pos():
	print(coin_2_pos)

def add_pawn(coin, row, col):
	for i in range (1, maxcols+1):
		key = coin+str(i)

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
	#print ("coin :%s, row :%d, col :%d" % (coin, row, col))
	if (coin == "K" or coin == "Q" or coin == "k" or coin == "q"):
		board[(row, col)]["coin"] = coin
		coin_2_pos[coin] = (row, col)
	elif (coin == "P" or coin == "p"):
		add_pawn(coin, row, col)
	elif (coin == "P" or coin == "p"):
		add_others(coin, row, col)
	
def populate_board(board):
	spawn = "P1"

	for (i, line) in enumerate(board):
		for (j, coin) in enumerate(line[0]):
			if (coin != '#'):
				#print ("row :%d, col :%d, coin :%s, line :%s" % (maxrows-i, j+1, coin, line))
				add_element(coin, maxrows-i, j+1)
		#print ("")

	return

d1 = [ ["########"], ["#k#P####"], ["########"], ["########"], ["########"], ["########"], ["#K######"], ["########"] ]
d2 = [ ["########"], ["######P#"], ["####k###"], ["########"], ["########"], ["########"], ["####K###"], ["########"] ]

def is_promotion_possible(row, col):
	if(board[(row, col)]["coin"]):
		#print ("Can NOT be promoted")
		return False
	else:
		#print ("Can be promoted")
		return True
		
#Queen #Bishap-Camel, #kNight-Horse, #rook-Elephant, 
#pawn - Solder
def is_queen_possible(row, col):
	if("Q" in coin_2_pos):
		return False

	return True

def is_bishap_possible(row, col):
	#TODO: what if only "b2" exists
	if("B1" in coin_2_pos):
		if ("B2" in coin_2_pos["B2"]):
			return False
		elif(board[coin_2_pos["B1"]["color"]] == board[(row, col)]["color"]):
			return False
		else:
			return True
	else:
		return True

def is_knight_possible(row, col):
	#TODO: what if only "b2" exists
	if("N1" in coin_2_pos):
		if("N2" in coin_2_pos):
			return False
		else:
			return True
	else:
		return True
	
def is_rook_possible(row, col):
	#TODO: what if only "b2" exists
	if("R1" in coin_2_pos):
		if("R2" in coin_2_pos):
			return False
		else:
			return True
	else:
		return True
	
def is__possible(row, col):
	if(coin_2_pos["Q"]):
		return False

def get_promoted_coins_by_pawn(cell):
	nrow, ncol = cell["pos"]
	#print("row :%d, col :%d" % (nrow, ncol))
	if (is_promotion_possible(nrow+1, ncol) == False):
		print ("No promotion is possible")
		return False
	
	if(is_queen_possible(nrow, ncol)):
		yield "Q"

	if (is_bishap_possible(nrow, ncol)):
		yield "B"

	if (is_knight_possible(nrow, ncol)):
		yield "N"

	if (is_rook_possible(nrow, ncol)):
		yield "R"

#         top 
#    tl            tr
#
#left                 right
#
#    ld            rd
#         down
#top         row++ col
#top-right   row++ col++
#right       row   col++
#right-down  row-- col++
#down        row-- col
#left-down   row-- col--
#left        row   col--
#top-left    row++ col--

#top         row++ col
def get_top_positions(row, col):
	tlist = []
	while(1):
		if (row > maxrows):
			break

		tlist.append((row, col))
		row = row + 1

	return tlist

#top-right   row++ col++
def get_top_right_positions(row, col):
	tlist = []
	while(1):
		if (row > maxrows or col > maxcols):
			break

		tlist.append((row, col))
		row = row + 1
		col = col + 1

	return tlist

#right       row   col++
def get_right_positions(row, col):
	tlist = []
	while(1):
		if (col > maxcols):
			break

		tlist.append((row, col))
		col = col + 1

	return tlist

#right-down  row-- col++
def get_right_down_positions(row, col):
	tlist = []
	while(1):
		if (row < 1 or col > maxcols):
			break

		tlist.append((row, col))
		row = row - 1
		col = col + 1

	return tlist

#down        row-- col
def get_down_positions(row, col):
	tlist = []
	while(1):
		if (row < 1):
			break

		tlist.append((row, col))
		row = row - 1

	return tlist


#left-down   row-- col--
def get_left_down_positions(row, col):
	tlist = []
	while(1):
		if (row < 1 or col < 1):
			break

		tlist.append((row, col))
		row = row - 1
		col = col - 1

	return tlist


#left        row   col--
def get_left_positions(row, col):
	tlist = []
	while(1):
		if (col < 1):
			break

		tlist.append((row, col))
		col = col - 1

	return tlist


#top-left    row++ col--
def get_top_left_positions(row, col):
	tlist = []
	while(1):
		if (row > maxrows or col < 1):
			break

		tlist.append((row, col))
		row = row + 1
		col = col - 1

	return tlist

def get_queen_valid_moves(row, col):
	topl        = get_top_positions(row, col)
	top_rightl  = get_top_right_positions(row, col)
	rightl      = get_right_positions(row, col)
	right_downl = get_right_down_positions(row, col)
	downl       = get_down_positions(row, col)
	left_downl  = get_left_down_positions(row, col)
	leftl       = get_left_positions(row, col)
	top_leftl   = get_top_left_positions(row, col)
	return (topl + top_rightl + rightl + right_downl + downl + left_downl + leftl + top_leftl)

#camel
def get_bishap_valid_moves(row, col):
	top_rightl  = get_top_right_positions(row, col)
	right_downl = get_right_down_positions(row, col)
	left_downl  = get_left_down_positions(row, col)
	top_leftl   = get_top_left_positions(row, col)

	return (top_rightl + right_downl + left_downl + top_leftl)

def is_valid_rows_col(r, c):
	if (r >= 0 and r <= maxrows and c >= 0 and c <= maxcols):
		return True
	else:
		return False

#horse
def get_knight_valid_moves(r, c):
	if (is_valid_rows_col(r+2, c-1)): #tl
		yield ((r+2, c-1))

	if (is_valid_rows_col(r+2, c+1)): #tr
		yield((r+2, c+1))

	if (is_valid_rows_col(r+1, c+2)): #rt
		yield((r+1, c+2))

	if (is_valid_rows_col(r-1, c+2)): #rd
		yield((r-1, c+2))

	if (is_valid_rows_col(r-2, c+1)): #dr
		yield((r-2, c+1))

	if (is_valid_rows_col(r-2, c-1)): #dl
		yield((r-2, c-1))

	if (is_valid_rows_col(r-1, c-2)): #ld
		yield((r-1, c-2))

	if (is_valid_rows_col(r+1, c-2)): #lt
		yield((r+1, c-2))

def get_rook_valid_moves(row, col):
	topl        = get_top_positions(row, col)
	rightl      = get_right_positions(row, col)
	downl       = get_down_positions(row, col)
	leftl       = get_left_positions(row, col)
	return (topl + rightl + downl + leftl)

def get_possible_moves(coin, nrow, ncol):
	#print("row :%d, col :%d, coin :%s" % (nrow, ncol, coin))
	if (coin == "Q"):
		return get_queen_valid_moves(nrow, ncol)
	elif (coin == "B"):
		return list(get_bishap_valid_moves(nrow, ncol))
	elif (coin == "N"):
		return list(get_knight_valid_moves(nrow, ncol))
	elif (coin == "R"):
		return list(get_rook_valid_moves(nrow, ncol))

def get_checkmate_count(data):
	count = 0
	init_board()
	populate_board(data)
	#dump_board()	
	#dum_coin_2_pos()
	#dump_board_only_filled()	
	#print(coin_2_pos["K"])
	#print(board[coin_2_pos["K"]])
	#dum_coin_2_pos()
	#print("P1 :%s" % board[coin_2_pos["P1"]])
	#print("k  :%s" % board[coin_2_pos["k"]])
	promoted_coins = get_promoted_coins_by_pawn(board[coin_2_pos["P1"]])
	promoted_coins = list(promoted_coins)
	#print ("promoted_coins....", promoted_coins)
	nrow, ncol = board[coin_2_pos["P1"]]["pos"]
	#print("k  :%s" % board[coin_2_pos["k"]])
	print ("k position :", coin_2_pos["k"])
	for coin in promoted_coins:
		possible_moves = get_possible_moves(coin, nrow+1, ncol)
		count = count + possible_moves.count(coin_2_pos["k"])
		print ("cell (%d, %d) coin :%s, count :%d -->" % (nrow+1, ncol, coin, count), possible_moves)
	print ("")
	return (count)

def main():
	print (get_checkmate_count(d1))
	print (get_checkmate_count(d2))

if (__name__ == "__main__"):
	main()


