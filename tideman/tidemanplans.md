FOR ADD_PAIRS

if we need to compare other peoples score
we will just reverse the numbers according to the loop
so if alice is in 2 and bob is in 0
we will get 2 0 first then we will just move backwards 0 2

for number in candidates count

    for othernumber in candidate count

        chosennumber1 = preference[number][othernumber];
        chosennumber2 = preference[othernumber][number];

        if chosennumber1 != 0
            if chosennumber1 > chosennumber2
            pairs[number].winner = chosennumber1;
            paris[other.number].loser = chosennumber2;


FOR SORT_PAIRS

we will set our intital score to 0

strength = 0

for i = 0, i < pair_count; i++
    preferences[pairs[i].winner][pairs[j].loser] - preferences[pairs[j].winner][pairs[i].loser]
    intital_winner = pairs[0].winner;
    initial_loser = pairs[0].loser;

    if that value is more than strength
        pairs[0].winner = pairs[i].winner];
        pairs[0].loser = pairs[i].loser;
        pairs[i].winner = intial_winner;
        pairs[i].loser = initial_loser;


FOR lock_pairs

For each winner we will put them in the boolean true
But heres a catch everyone cannot beat each other so Charlie beats Alice, Alice beats Bob, and Bob beats Charlie.
Whoever is in the last of the descending order is who we want to beat.
We need a mechanism to determine who has the lowest score so that they can be deleted.
For that I would loop through each winner and see if
The amount of winners is equal to the pair count 





