import csv
import sys


def main():

    try:
        sys.argv[1]
        sys.argv[2]
    except IndexError:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    # TODO: Check for command-line usage
    filename = sys.argv[1]
    text = sys.argv[2]

    # Verifies if there is a output that equals to someone
    verify = False
    # TODO: Read database file into a variable
    with open(filename,'r') as data:
        data_reader = csv.DictReader(data)
        list_data = list(data_reader)
    # TODO: Read DNA sequence file into a variable
    with open(text, 'r') as seq:
        sequence = seq.read()

    # New Dictionary to add STR items
    findings = {}

    # Creates a list of STR Keys
    str = list(list_data[0].keys())
    str.pop(0)

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(len(str)):
        findings[str[i]] = longest_match(sequence, str[i])

    # We will create a list of values to compare
    true_values = list(findings.values())

    # TODO: Check database for matching profiles
    for x in range(len(list_data)):
        comp_values = list(list_data[x].values())
        comp_values.pop(0)
        comp_values = list(map(int, comp_values))
        if set(comp_values) == set(true_values):
            print(list(list_data[x].values()).pop(0))
            verify = True

    if verify == False:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
