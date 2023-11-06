#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
int total_votes;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    argc = 3;
    argv[0] = "Bob";
    argv[1] = "Alice";
    argv[2] = "Charlie";
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %d: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            if(strcmp(name, "Bob") == 0)
            {
                switch(rank)
                {
                    case 0 ... 2:
                    preferences[voter][rank] = 0;
                    break;
                }
                return true;
            }
            else if(strcmp(name, "Alice") == 0)
            {
                switch(rank)
                {
                    case 0 ... 2:
                    preferences[voter][rank] = 1;
                    break;
                }
                return true;
            }
            else if(strcmp(name, "Charlie") == 0)
            {
                switch(rank)
                {
                    case 0 ... 2:
                    preferences[voter][rank] = 2;
                    break;
                }
                return true;
            }
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
     for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if(candidates[j].eliminated == false)
            {
                int numb = preferences[i][j];
                switch(numb)
                {
                    case 0:
                    candidates[0].votes ++;
                    total_votes += 1;
                    break;
                    case 1:
                    candidates[1].votes ++;
                    total_votes += 1;
                    break;
                    case 2:
                    candidates[2].votes ++;
                    total_votes += 1;
                    break;
                }
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int winning_score = total_votes / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > winning_score)
        {
            printf("%s", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min;
    for (int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].eliminated == false)
        {
            if(min >= candidates[i].votes)
            {
                min = candidates[i].votes;
            }
        }
        else
        {
            continue;
        }
    }
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
     int i = 0;
    while(i < candidate_count)
    {
        if (candidates[i].votes > min)
        {
            return false;
            break;
        }
        else
        {
            continue;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].eliminated == false)
        {
            if(min == candidates[i].votes)
            {
                candidates[i].eliminated = true;
            }
        }
        else
        {
            continue;
        }
    }
    return;
}