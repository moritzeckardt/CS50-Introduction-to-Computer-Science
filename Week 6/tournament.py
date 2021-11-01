# Simulate a sports tournament

import csv
import sys
import random

# Task: https://cs50.harvard.edu/x/2021/labs/6/

# Number of simultations to run
N = 1000

def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Read data into memory
    teams = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(row)

    # Simulate N tournaments and keep track of win counts
    counts = {}
    for i in range(N):
        team_won = simulate_tournament(teams)

        if team_won in counts:
            counts[team_won] += 1
        else:
            counts[team_won] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


# Simulate a game. Return True if team1 wins, False otherwise.
def simulate_game(team1, team2):
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


# Simulate a round. Return a list of winning teams.
def simulate_round(teams):
    # Simulate games for all pairs of teams
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


# Simulate a tournament. Return name of winning team.
def simulate_tournament(teams):

    while len(teams) > 1:
        teams = simulate_round(teams)

    return teams[0]["team"]

if __name__ == "__main__":
    main()
