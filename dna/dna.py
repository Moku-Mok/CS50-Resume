import csv
import sys
import string

def main():

    # TODO: Check for command-line usage

    dbase = sys.argv[1]
    seq = sys.argv[2]

    # TODO: Read database file into a variable

    dbase = read_database(dbase)

    # TODO: Read DNA sequence file into a variable

    seq = read_sequence(seq)

    # TODO: Find longest match of each STR in DNA sequence

    if "small" in sys.argv[1]:

        suspect_sequence = {}

        suspect_sequence["AGATC"] = longest_match(seq, "AGATC")
        suspect_sequence["AATG"] = longest_match(seq, "AATG")
        suspect_sequence["TATC"] = longest_match(seq, "TATC")

    elif "large" in sys.argv[1]:

        suspect_sequence = {}

        suspect_sequence["AGATC"] = longest_match(seq, "AGATC")
        suspect_sequence["TTTTTTCT"] = longest_match(seq, "TTTTTTCT")
        suspect_sequence["AATG"] = longest_match(seq, "AATG")
        suspect_sequence["TCTAG"] = longest_match(seq, "TCTAG")
        suspect_sequence["GATA"] = longest_match(seq, "GATA")
        suspect_sequence["TATC"] = longest_match(seq, "TATC")
        suspect_sequence["GAAA"] = longest_match(seq, "GAAA")
        suspect_sequence["TCTG"] = longest_match(seq, "TCTG")

    # TODO: Check database for matching profiles

    culprit = database_match(dbase, suspect_sequence)

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

def read_database(db):

    rows = []
    with open(db) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    return rows

def read_sequence(seq):

    with open(seq) as file:
        sequence = file.read()

    return sequence

def database_match(database, target):


    if "small" in sys.argv[1]:

        for person in database:
            targetnum = 0

            for key in person:

                if key == "name":
                    continue

                if int(person.get(key)) == int(target.get(key)):
                    targetnum += 1

                if targetnum == 3:
                    print(person.get("name"))
                    return

        if targetnum != 3:
            print("No Match")

    elif "large" in sys.argv[1]:

        for person in database:
            targetnum = 0

            for key in person:

                if key == "name":
                    continue

                try:
                    if int(person.get(key)) == int(target.get(key)):
                        targetnum += 1
                except:
                    continue

                if targetnum == 8:
                    print(person.get("name"))
                    return

        if targetnum != 8:
            print("No Match")


main()
