For load
We need to use that dictionary string to use fopen and verify if it exists

for the length of that dictionary array we need to now put it in the char word variable.
Create *n and malloc it, as we strcpy n->word into it
Afterwards we will use the hash function at its current state and create a int
Then lets start a brand new function
And this will create our hash table


For Hash
In this we will create a hash function
We will take the length of the string
and we will add up each int of the
char and put it inside a variable
We will utilize a for foop and that
will make every word have their own respective value
Also we will use a if statement that will make our first character
uppercase and that will show according to the ASCII table
After the loop we will return the value back to the hash table.

For Size
All we need to do is to give back the number of words written in tbe
dictionary load function
We wil create a global variable that will track that
and afterwards it will return us the number of words for the dictionary
We will have a if statement that if its 0 then return 0


For Check
We take the value of hash from the word
Then we check if that value in the tabel exists or else its false


For unload
We will run a for loop that will loop if that value in
our hash table exists
Then we run a while loop that will free
each node that exists within that particular value
In the while loop our cursor will be in charge of getting the first value and the next while the temp free that value, until that temp is null.



