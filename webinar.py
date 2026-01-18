# Fun "Pythonista Party" demo using the same ideas: list, indexing/slicing, list comprehension,
# a generator (yield), and a function that adds ages.

crew = ["Ethan", "Minh", "Dang"]          # list of names
secret = "abcdxyz"                        # string to slice/index

# Make all ordered pairs of different player indexes (like a mini round-robin)
matchups = [(i, j) for i in range(len(crew))
                  for j in range(len(crew)) if i != j]

# Generator for rounds
def rounds(n):
    for r in range(n):
        yield r + 1

# Function to add ages
def total_age(e, m, d):
    return e + m + d

ages_sum = total_age(16, 16, 17)

# Use generator
for r in rounds(3):
    print("\n" + ("=" * 12) + f" ROUND {r} " + ("=" * 12))

    # each person gets a fun message
    for name in crew:
        # slicing + negative indexing + upper for style
        code_piece = secret[1:3]          # slice (like your example)
        last_char = secret[-1]            # negative index from end
        print("Hey " + name + "! Your mini-code is:", (code_piece + last_char).upper())

    # show the matchups each round
    print("Matchups this round:")
    for i, j in matchups:
        print(f"  {crew[i]} vs {crew[j]}")

print("\nTheir total age is", ages_sum)
