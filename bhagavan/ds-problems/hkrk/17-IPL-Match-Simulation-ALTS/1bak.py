import random

def get_possible_matches(teams):
    teamcount = len(teams)

    i = 0
    while(i < teamcount-1):
        j = i + 1
        while(j < teamcount):
            #print ("%d<-->%d" % (teams[i], teams[j]))
            yield ((teams[i], teams[j]))
            j = j + 1
        i = i + 1

def get_winner_by_match(match):
    #print (match)
    match_winner = random.randint(0, 1)
    return match[match_winner]


def get_winners_list_by_matches(match_list):
    #print (match_list)
    for match in match_list:
        mw = get_winner_by_match(match)
        print ("match ", match, "winner ", mw)
        yield mw

def get_top_four(teams, league_winners):
    tdict = {}
    for i in teams:
        wc = league_winners.count(i)
        tdict[i] = wc
    return (tdict)
    
def get_match_winner(team1, team2):
    match_winner = random.randint(0, 1)
    if (match_winner == 0):
        return team1, team2
    else:
        return team2, team1
    
def main():
    team_size = 8
    no_of_rounds = 2
    league_winners = []
    teams_in_sorted = []
    play_of_teams = []
    teams = list(range(1, team_size+1))
    #print (teams)
    match_list = list(get_possible_matches(teams))
    #print (match_list)

    for i in range(no_of_rounds):
        winners_list = list(get_winners_list_by_matches(match_list))
        #print ("winners list :",  winners_list)
        league_winners += winners_list

    print ("league_winners ", league_winners)
    print ("league match count ", len(league_winners))

    top4list = get_top_four(teams, league_winners)

    print (top4list)

    for key, value in sorted(top4list.iteritems(), key=lambda (k,v): (v,k)):
        #print "%s: %s" % (key, value)
        teams_in_sorted.append((key, value))

    print ("teams_in_sorted ", teams_in_sorted)

    for i in range(7, 3, -1):
        #print (i)
        play_of_teams.append(teams_in_sorted[i][0])


    print ("play_of_teams ", play_of_teams)

    '''
    for team in play_of_teams:
        print (team)
    '''

    pof_1_win, pof_1_los = get_match_winner(play_of_teams[0], play_of_teams[1])
    print ("pof_1_win :%d, pof_1_los :%d" % (pof_1_win, pof_1_los))

    (pof_2_win, pof_2_los)  = get_match_winner(play_of_teams[2], play_of_teams[3])
    print ("pof_2_win :%d, pof_2_los :%d" % (pof_2_win, pof_2_los))

    (pof_3_win, pof_3_los)  = get_match_winner(pof_1_los, pof_2_win)
    print ("pof_3_win :%d, pof_3_los :%d" % (pof_3_win, pof_3_los))

    (final_win, final_los)  = get_match_winner(pof_1_win, pof_3_win )
    print ("final_win :%d, final_los :%d" % (final_win, final_los))

    print ("winner ", final_win)
    print ("final  ", final_los)


    '''
    for key, value in sorted(mydict.iteritems(), key=lambda (k,v): (v,k)):
        print "%s: %s" % (key, value)
    '''

    #print ("top4list ", top4list)
    #sort_winners(top4list)
    #print (top4list.sort())


if (__name__ == "__main__"):
    main()
