import random

crew = ["Ethan", "Andy", "Dang"] #declare variables
letters = "abcdxyz"  # indexes 0-6

# all matchups (ordered pairs) where i != j
matchups = [(i, j) for i in range(len(crew))
                  for j in range(len(crew)) if i != j]

# generator for rounds
def rounds(n):
    for r in range(n):
        yield r + 1

# function to add ages
def total_age(e, a, d):
    return e + a + d

ages_sum = total_age(16, 17, 17)

for r in rounds(3):
    print(f"\n=== ROUND {r} ===")

    for name in crew:
        # pick 3 different random indexes from 0..6
        index1, index2, index3 = random.sample(range(len(letters)), 3)

        # build the secret code using those indexes
        code = letters[index1] + letters[index2] + letters[index3]

        print(f"Hey {name}! Your secret code is: {code}")

    print("Matchups:", matchups)

print("Their total age is", ages_sum)
