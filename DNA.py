import csv
import sys

# نتأكد من عدد البراميترز
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# نقرأ قاعدة البيانات
with open(sys.argv[1]) as database_file:
    reader = csv.DictReader(database_file)
    database = list(reader)

# نقرأ تسلسل الـ DNA
with open(sys.argv[2]) as sequence_file:
    sequence = sequence_file.read()

# نجيب لستة الـ STRs (من أول عمود غير الاسم)
strs = list(database[0].keys())[1:]

# نحسب أطول تكرار متتالي لكل STR
def longest_match(sequence, subsequence):
    longest = 0
    length = len(subsequence)

    for i in range(len(sequence)):
        count = 0
        while sequence[i + count*length : i + (count+1)*length] == subsequence:
            count += 1
        longest = max(longest, count)

    return longest

# نحط النتائج في dict
results = {}
for s in strs:
    results[s] = longest_match(sequence, s)

# نقارن مع كل شخص في الداتا
for person in database:
    match = True
    for s in strs:
        if int(person[s]) != results[s]:
            match = False
            break
    if match:
        print(person["name"])
        sys.exit(0)

print("No match")