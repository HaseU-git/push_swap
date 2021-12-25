from itertools import permutations
s = "123456"
st = set()
for it in permutations(s):
        st.add("".join(it))
test_list = sorted(st)

i = 0

while (i < len(test_list)):
    test_list[i] = list(test_list[i])
    i = i + 1

for i in test_list:
        print(" ".join(i))
